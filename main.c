#include <stdio.h>
#include <string.h>
#include "PDA.h"

bool isDigit(char c);
bool isOperator(char c);
bool isSpace(char c);

int main(int argc, char **argv)
{
	printf("HHEHEHEHEHEHE\n");
	int inputsize = 0;
	char* input = argv[1];
	while(input[inputsize] != '\0'){
		inputsize++;
	}
	automatic* test = PDA_create();
	char lek[3] = "q0";
	char lek2[3] = "q1";
	char lek3[3] = "aa";
	
	//strncpy(lek, lek2, strlen(lek2));
	//printf("%s\n", lek);
	//printf("%d\n", (int)strlen(lek2));
	//printf("%d\n", strlen(lek));
	//printf("%d\n", strlen(lek3));
	
	PDA_setState(test, lek);
	PDA_setState(test, lek2);
	PDA_setState(test, lek3);
	//PDA_setAcceptState(test, lek);
	PDA_setAcceptState(test, lek2);
	PDA_setStartState(test, lek);
	trans_control* lekis = &isDigit;
	
	PDA_addTransFunc(test, lek, lek2, lekis);
	//PDA_addTransFunc(test, lek, lek2, &isSpace);
	PDA_addTransFunc(test, lek, lek2, &isOperator);
	
	state* lekis2 = table_lookup(test->t, lek2);
	
	transition* lekis3;
	
	//lekis3 = dlist_inspect(lekis2->transitions, dlist_first(lekis2->transitions));
	
	//printf("%s\n", lekis3->to);
	PDA_run(test, lek3, inputsize);
	
	printf("%s\n", test->current_state);
	printf("hello world\n");
	//PDA_free(test); MÅSTE TESTAS
	char c = '/';
	if(isDigit(c)){
		printf("TESTING1\n");
	}
	if(isOperator(c)){
		printf("TESTING2\n");
	}
	if(isSpace(c)){
		printf("TESTING3\n");
	}
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
	if(c == 42||c==43||c==45||c==47){
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