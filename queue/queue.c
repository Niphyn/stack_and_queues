#include "queue.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    Vector *v;
} Queue;

Queue *queue_construct(){
    Queue *q = (Queue *)calloc(1,sizeof(Queue));
    q->v = vector_construct();
    return q;
}

void queue_enqueue(Queue *queue, data_type value){
    vector_push_back(queue->v,value);
}

data_type queue_dequeue(Queue *queue){
    return vector_pop_front(queue->v);
}

int queue_empty(Queue *queue){
    if(vector_size(queue->v)>0){
        return 0;
    }else{
        return 1;
    }
}

void queue_destroy(Queue *queue){
    vector_destroy(queue->v);
    free(queue);
}