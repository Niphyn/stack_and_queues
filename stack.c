#include "stack.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    Vector *v;
} Stack;

Stack *stack_construct(){
    Stack *s = (Stack *)calloc(1,sizeof(Stack));
    s->v = vector_construct();
    return s;
}
//(Stack *)

void stack_push(Stack *s, data_type val){
    vector_push_back(s->v,val);
}

data_type stack_pop(Stack *s){
    data_type retorno = vector_pop_back(s->v);
    return retorno;
}

int stack_empty(Stack *s){
    if(s->v->size > 0){
        return 0;
    }else{
        return 1;
    }
}

void stack_destroy(Stack *s){
    vector_destroy(s->v);
    free(s);
}