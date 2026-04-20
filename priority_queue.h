#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Ödevde istenen Request yapýsý
typedef struct {
    int id;
    int urgency; // RFC 9213: u=0 en öncelikli, u=7 en az öncelikli
    char data[256];
} Request;

// Dinamik dizi tabanlý Min-Heap yapýsý
typedef struct {
    Request *heap;
    int size;
    int capacity;
} PriorityQueue;

// Fonksiyon prototipleri
PriorityQueue* createQueue(int capacity);
void insert(PriorityQueue *pq, Request req);
Request extractMin(PriorityQueue *pq);
void heapifyUp(PriorityQueue *pq, int index);
void heapifyDown(PriorityQueue *pq, int index);
void freeQueue(PriorityQueue *pq);

#endif
