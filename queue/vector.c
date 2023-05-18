#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

Vector *vector_construct(){
    Vector *v = (Vector *)calloc(1,sizeof(Vector));
    v->size = 0;
    v->allocated = 20;
    v->data = (data_type *)calloc(v->allocated,sizeof(data_type));
    return v;
}

void vector_destroy(Vector *v){
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val){
    if(v->size == v->allocated){
        v->allocated *= 2;
        v->data = (data_type*)realloc(v->data, v->allocated*sizeof(data_type));
    }

    v->data[v->size] = val;
    v->size++;
}

data_type vector_get(Vector *v, int i){
	if((i<=-1)&&(i>v->size)){
	printf("Indice inválido\n");
	exit(1);}
    return v->data[i];
}
void vector_set(Vector *v, int i, data_type val){
    if((i<=-1)&&(i>v->size)){
	    printf("Indice inválido\n");
	    exit(1);
    }
    v->data[i] = val;
}

int vector_size(Vector *v){
    return v->size;
}

int vector_find(Vector *v, data_type val){
    int indice = -1;
    for(int i = 0; i < v->size; i++){
        if(v->data[i] == val){
            indice = i;
        }
    }
    return indice;
}

// Remove o i-ésimo elemento do vetor.
data_type vector_remove(Vector *v, int i){
    if((i<0)&&(i>v->size)){
	    printf("Indice inválido\n");
	    exit(1);
    }
    data_type retorno = v->data[i];
    for(int x = i + 1; x < v->size; x++){
        v->data[x-1] = v->data[x];
    }

    v->size = v->size - 1;

    return retorno;
}

// Remove o primeiro elemento
data_type vector_pop_front(Vector *v){
    data_type retorno = vector_remove(v,0);
    return retorno;
}

// Remove o ultimo elemento
data_type vector_pop_back(Vector *v){
    data_type retorno = vector_remove(v,v->size-1);
    return retorno;
}

void vector_insert(Vector *v, int i, data_type val){
    if((i<0)&&(i>v->size)){
	    printf("Indice inválido\n");
	    exit(1);
    }
    data_type aux_1 = v->data[i],aux_2;
    v->data[i] = val;
    for(int x = i + 1; x<v->size; x++){
        aux_2 = v->data[x];
        v->data[x] = aux_1;
        aux_1 = aux_2;
    }
    if(v->size == i){
        vector_push_back(v,val);
    }else{
        vector_push_back(v,aux_1);
    }
}

void vector_swap(Vector *v, int i, int j){
    data_type aux_1;
    aux_1 = v->data[i];
    v->data[i] = v->data[j];
    v->data[j] = aux_1;
}

void vector_sort(Vector *v){
    int trocas = 1, i, j;
    for(i = 0; trocas != 0; i++){
        trocas = 0;
        for(j = 0; j < (v->size-1-i); j++){
            if(v->data[j]>v->data[j+1]){
                vector_swap(v,j,j+1);
                trocas++;
            }
        }
    }
}

int vector_binary_search(Vector *v, data_type val){
    int indice = -1,indice_max = v->size-1, indice_min = 0,indice_half;
    vector_sort(v);
    while((indice == -1)&&(indice_min<=indice_max)){
        indice_half = (indice_max + indice_min)/2;
        if(v->data[indice_half]>val){
            indice_max = indice_half - 1;
        }else if(v->data[indice_half]<val){
            indice_min = indice_half + 1;
        }else{
            indice = indice_half;
        }
    }
    return indice;
}

void vector_reverse(Vector *v){
    vector_sort(v);
    int trocas = 1, i, j;
    for(i = 0; trocas != 0; i++){
        trocas = 0;
        for(j = 0; j < (v->size-1-i); j++){
            if(v->data[j]<v->data[j+1]){
                vector_swap(v,j,j+1);
                trocas++;
            }
        }
    }
}