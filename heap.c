#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){

  if(pq == NULL || pq->size == 0) return NULL;
  
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

  if(pq->size == pq->capac) {
    pq->heapArray = (heapElem *)realloc(pq->heapArray, (pq->capac *2 + 1) * sizeof(heapElem));
  }

  pq->heapArray[pq->size+1].data = data;
  pq->heapArray[pq->size+1].priority = priority;
  

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){

  Heap* nuevoHeap = (Heap *) malloc(sizeof(Heap));
  nuevoHeap->heapArray = (heapElem *) malloc(sizeof(heapElem) * 3);
  nuevoHeap->capac = 3;
  nuevoHeap->size = 0;

  return nuevoHeap;
}
