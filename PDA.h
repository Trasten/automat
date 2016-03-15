#include "stack_1cell.h"
#include "table.h"
#include "dlist.h"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef __DATA
#define __DATA
	typedef void *data;
#endif

#ifndef __MEMFREEDATAFUNC
#define __MEMFREEDATAFUNC
typedef void memFreeFunc(data);
#endif


 //FUNDERAR PÅ DENNA
//typedef bool (*trans_control)(char);

typedef struct{
	//char name;
	dlist* transitions;
	bool accepted_state;
} state;

typedef struct{
	char start[10];
	char input;
	Table* t;
	stack* s;
	char current_state[10];
	memFreeFunc* freeFunc;
} automatic;

typedef void stack_control(automatic* a);
typedef bool trans_control(char);

typedef struct{
	char to[10];
	trans_control* func;
	stack_control* stackFunc;
} transition;

automatic* PDA_create();
void PDA_setmemHandler(automatic* a, memFreeFunc* f);
void PDA_setState(automatic* a, char* c);
void PDA_setStartState(automatic* a, char* q0);
void PDA_setAcceptState(automatic* a, char* q);
void PDA_addTransFunc(automatic* a, char* qfrom, char* qto, trans_control* tc, stack_control* sc);
void PDA_makeTrans(automatic* a);
void PDA_run(automatic* a, char* input, int inputsize);
void PDA_freeTransiotionLists(automatic* a, dlist* l);
void PDA_free(automatic* a);