#include "PDA.h"
#include <string.h>

int compareString(void *ip,void *ip2){
	return strcmp((char*)ip, (char*)ip2);
}

automatic* PDA_create(){
	automatic* a = malloc(sizeof(automatic));
	a->s = stack_empty();
	//a->end_states = dlist_empty();
	a->t = table_create(compareString);
	a->freeFunc = NULL;
	return a;
}

void PDA_setmemHandler(automatic* a, memFreeFunc* f){
	a->freeFunc = f;
	//table_setKeyMemHandler(a->t, free); TROR INTE DENNA SKALL BEHÖVAS
	table_setValueMemHandler(a->t, free);
	stack_setMemHandler(a->s, f);
}

void PDA_setState(automatic* a, char* c){
	state* tmp = malloc(sizeof(state));
	tmp->transitions = dlist_empty();
	tmp->accepted_state = false;
	dlist_setMemHandler(tmp->transitions, free);
	table_insert(a->t, c, tmp);
}

void PDA_setStartState(automatic* a, char* q0){
	strncpy(a->start, q0, strlen(q0)+1);
}

void PDA_setAcceptState(automatic* a, char* q){
	state* tmp = table_lookup(a->t, q);
	tmp->accepted_state = true;
	//dlist_insert(a->end_states, dlist_first(a->end_states), qend);
}

void PDA_addTransFunc(automatic* a, char* qfrom, char* qto, trans_control* tc){
	transition* tmp = malloc(sizeof(transition));
	
	state* tmp2 = table_lookup(a->t, qfrom);
	strncpy(tmp->to, qto, strlen(qto)+1);
	tmp->func = tc;
	dlist_insert(tmp2->transitions, dlist_first(tmp2->transitions), tmp);
}

void PDA_makeTrans(automatic* a){
	state* tmp = table_lookup(a->t, a->current_state);
	dlist_position tmp2 = dlist_first(tmp->transitions);
	int trans_made = 0;
	/*do{
		
		transition* tmp3;
		if(!dlist_isEmpty(tmp->transitions)){
			tmp3 = dlist_inspect(tmp->transitions, tmp2);
			if(tmp3->func(a->input)){
				strncpy(a->current_state, tmp3->to, strlen(tmp3->to)+1);
				trans_made = 1;
			}
			tmp2 = dlist_next(tmp->transitions, tmp2);
		}
		else{
			trans_made = 1;
		}
		
		
	} while(!dlist_isEnd(tmp->transitions, tmp2) && trans_made == 0);
	*/
	while(!dlist_isEnd(tmp->transitions, tmp2) && trans_made == 0){
		transition* tmp3;
		if(!dlist_isEmpty(tmp->transitions)){
			tmp3 = dlist_inspect(tmp->transitions, tmp2);
			if(tmp3->func(a->input)){
				strncpy(a->current_state, tmp3->to, strlen(tmp3->to)+1);
				trans_made = 1;
			}
			tmp2 = dlist_next(tmp->transitions, tmp2);
		}
		else{
			trans_made = 1;
		}
	}
}

void PDA_run(automatic* a, char* input, int inputsize){
	int i;
	strncpy(a->current_state, a->start, strlen(a->start)+1);
	for(i = 0; i < inputsize; i++){
		a->input = input[i];
		PDA_makeTrans(a);
	}
	state* tmp = table_lookup(a->t, a->current_state);
	if(tmp->accepted_state == true){
		printf("JADET ÄR DET\n");
	}
	else{
		printf("NEJ DET ÄR DET INTE\n");
	}
}

void PDA_free(automatic* a){
	stack_free(a->s);
	table_free(a->t);
	free(a);
}