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
    pq->capac = pq->capac *2 +1;
    pq->heapArray = (heapElem *) realloc(pq->heapArray, (pq->capac) * sizeof(heapElem));
  }

  int pos = pq->size;

  while(pos > 0) {
    int padre = (pos - 1)/2;
    if (pq->heapArray[padre].priority > priority) break;

    pq->heapArray[pos] = pq->heapArray[padre];
    pos = padre;
  }

  pq->heapArray[pos].priority = priority;
  pq->heapArray[pos].data = data;
  pq->size++;
  
}


void heap_pop(Heap* pq){
  if (pq->size == 0) return;

  int pos = 0;
  int hijo = 1;
  
  pq->size--;

  while(hijo < pq->size) {

    if(hijo + 1 < pq->size && pq->heapArray[hijo + 1].priority > pq->heapArray[hijo].priority) hijo++;
    
  

    if(pq->heapArray[pos].priority > pq->heapArray[hijo].priority) break;

    heapElem aux = pq->heapArray[pos];

    pos = hijo;
    
    
  }


   
  
}

Heap* createHeap(){

  Heap* nuevoHeap = (Heap *) malloc(sizeof(Heap));
  nuevoHeap->heapArray = (heapElem *) malloc(sizeof(heapElem) * 3);
  nuevoHeap->capac = 3;
  nuevoHeap->size = 0;

  return nuevoHeap;
}
