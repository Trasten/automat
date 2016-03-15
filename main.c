#include <stdio.h>
#include <string.h>
#include "PDA.h"
#include <math.h>
#include "dlist.h"

bool isDigit(char c);
bool isOperator(char c);
bool isSpace(char c);
bool isIncorrect(char c);
void pushToStack(automatic* a);
void addDigitToExistingDigit(automatic* a);
void removeTwoValuesFromStack(automatic* a);

int main(int argc, char **argv)
{
	if(argc <= 1){
		printf("To few arguments.\n");
		return 0;
	}
	int inputsize = 0;
	char* input = argv[1];
	while(input[inputsize] != '\0'){
		inputsize++;
	}
	
	automatic* calculator = PDA_create();
	char q0[10] = "q0";
	char opera[10] = "q1";
	char digit[10] = "q2";
	char space[10] = "q3";
	char fail[10] = "q4";
	
	dlist* states = dlist_empty();
	dlist_insert(states, dlist_first(states), q0);
	dlist_insert(states, dlist_first(states), opera);
	dlist_insert(states, dlist_first(states), digit);
	dlist_insert(states, dlist_first(states), space);
	dlist_insert(states, dlist_first(states), fail);
	
	PDA_setState(calculator, q0);
	PDA_setState(calculator, opera);
	PDA_setState(calculator, digit);
	PDA_setState(calculator, space);
	PDA_setState(calculator, fail);
	
	PDA_setStartState(calculator, q0);
	
	PDA_setAcceptState(calculator, digit);
	PDA_setAcceptState(calculator, opera);
	PDA_setAcceptState(calculator, space);
	
	PDA_addTransFunc(calculator, q0, fail, &isOperator, &removeTwoValuesFromStack);
	PDA_addTransFunc(calculator, q0, digit, &isDigit, &pushToStack);
	PDA_addTransFunc(calculator, q0, space, &isSpace, NULL);
	PDA_addTransFunc(calculator, q0, fail, &isIncorrect, NULL);
	
	PDA_addTransFunc(calculator, digit, digit, &isDigit, &addDigitToExistingDigit);
	PDA_addTransFunc(calculator, digit, opera, &isOperator, &removeTwoValuesFromStack);
	PDA_addTransFunc(calculator, digit, space, &isSpace, NULL);
	PDA_addTransFunc(calculator, digit, fail, &isIncorrect, NULL);
	
	PDA_addTransFunc(calculator, opera, digit, &isDigit, &pushToStack);
	PDA_addTransFunc(calculator, opera, space, &isSpace, NULL);
	PDA_addTransFunc(calculator, opera, opera, &isOperator, &removeTwoValuesFromStack);
	PDA_addTransFunc(calculator, opera, fail, &isIncorrect, NULL);
	
	PDA_addTransFunc(calculator, space, digit, &isDigit, &pushToStack);
	PDA_addTransFunc(calculator, space, space, &isSpace, NULL);
	PDA_addTransFunc(calculator, space, opera, &isOperator, &removeTwoValuesFromStack);
	PDA_addTransFunc(calculator, space, fail, &isIncorrect, NULL);
	
	PDA_run(calculator, input, inputsize);
	
	PDA_freeTransiotionLists(calculator, states);//MÅSTE VALGRIND TESTAS
	PDA_free(calculator); // MÅSTE VALGRIND TESTAS
	return 0;
}

bool isDigit(char c){
	if(c >= 48 && c <= 57){
		return true;
	}
	else{
		return false;
	}
}

bool isOperator(char c){
	if(c == 42||c==43||c==45||c==47||c==215||c==247){
		return true;
	}
	else{
		return false;
	}
}

bool isSpace(char c){
	if(c==32){
		return true;
	}
	else{
		return false;
	}
}

bool isIncorrect(char c){
	if(!isDigit(c)&&!isOperator(c)&&!isSpace(c)){
		return true;
	}
	else{
		return false;
	}
}

void pushToStack(automatic* a){
	char* tmp = calloc(sizeof(char), 2);
	tmp[0] = a->input;
	tmp[1] = '\0';
	stack_push(a->s, tmp);
}

void addDigitToExistingDigit(automatic* a){
	char* tmp = stack_top(a->s);
	char* tmp2 = calloc(sizeof(char), strlen(tmp)+2);
	strncpy(tmp2, tmp, strlen(tmp));
	tmp2[strlen(tmp)] = a->input;
	tmp2[strlen(tmp)+1] = '\0';
	stack_pop(a->s);
	stack_push(a->s, tmp2);
}

void removeTwoValuesFromStack(automatic* a){
	char* tmp = calloc(sizeof(char), 30);
	char* tmp2 = calloc(sizeof(char), 30);
	int result = -1;
	if(!stack_isEmpty(a->s)){
		strncpy(tmp, stack_top(a->s), strlen(stack_top(a->s))+1);
		stack_pop(a->s);
		if(!stack_isEmpty(a->s)){
			strncpy(tmp2, stack_top(a->s), strlen(stack_top(a->s))+1);
			stack_pop(a->s);
			//long int tmp3 = strtol(tmp, &tmp[strlen(tmp)], 10);
			//printf("LONG INT1 = %ld\n", tmp3);
			//long int tmp4 = strtol(tmp2, &tmp2[strlen(tmp2)], 10);
			//printf("LONG INT2 = %ld\n", tmp4);
			int tmp3 = atoi(tmp); // BYTTE TILL DESSA
			int tmp4 = atoi(tmp2); //
			//NÅN JÄVLA SKIT MED ASCII SOM VANLIGT........
			if(a->input == '*' || a->input == 215){
				result = tmp4 * tmp3;
			}
			else if(a->input == '/'|| a->input == 247){
				if(tmp3 == 0){
					printf("ERROR: Divided by zero\n");
					result = -1;
				}
				else{
				result = tmp4 / tmp3;
				}
			}
			else if(a->input == '-'){
				result = tmp4 - tmp3;
			}
			else{
				result = tmp4 + tmp3;
			}
		}
	}
	if(result == -1){
		free(tmp);
		free(tmp2);
		a->input = 'a'; // EN LÖSNIUNG MEN INTE NÖJD ÄNNU
		PDA_makeTrans(a);
		return NULL;
	}
	else{
		int nrOfDigits;
		if(result == 0){
			nrOfDigits = 1;
		}
		else{
			nrOfDigits = floor (log10 (abs (result))) + 1;
		}
		sprintf(tmp, "%d", result);
		tmp[nrOfDigits+1] = '\0';
		stack_push(a->s, tmp);
		free(tmp2);
	}
}