#include "priority_queue.h"

// 1. ADIM: SWAP (Yer Deðiþtirme)
void swap(Request *a, Request *b) {
    Request temp = *a;
    *a = *b;
    *b = temp;
}

// 2. ADIM: HEAPIFY UP (Yeni eleman eklenince yukarý týrmandýrma)
void heapifyUp(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && pq->heap[index].urgency < pq->heap[parent].urgency) {
        swap(&pq->heap[index], &pq->heap[parent]);
        heapifyUp(pq, parent);
    }
}

// 3. ADIM: HEAPIFY DOWN (Eleman silinince aþaðý indirme - 2i+1 kuralý)
void heapifyDown(PriorityQueue *pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;  // Sol çocuk
    int right = 2 * index + 2; // Sað çocuk

    if (left < pq->size && pq->heap[left].urgency < pq->heap[smallest].urgency)
        smallest = left;
    if (right < pq->size && pq->heap[right].urgency < pq->heap[smallest].urgency)
        smallest = right;

    if (smallest != index) {
        swap(&pq->heap[index], &pq->heap[smallest]);
        heapifyDown(pq, smallest);
    }
}

// ELEMAN EKLEME (realloc ile dinamik bellek yönetimi)
void insert(PriorityQueue *pq, Request req) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->heap = (Request*)realloc(pq->heap, pq->capacity * sizeof(Request));
    }
    pq->heap[pq->size] = req;
    heapifyUp(pq, pq->size);
    pq->size++;
}

// ELEMAN SÝLME (Kökü çýkarma ve yeniden kümelendirme)
Request extractMin(PriorityQueue *pq) {
    Request root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1]; // Son elemaný baþa al
    pq->size--;
    heapifyDown(pq, 0); // Yeniden düzenle
    return root;
}

// BELLEK TAHSÝSÝ (malloc)
PriorityQueue* createQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->heap = (Request*)malloc(capacity * sizeof(Request));
    return pq;
}

// BELLEK TEMÝZLEME (free)
void freeQueue(PriorityQueue *pq) {
    free(pq->heap);
    free(pq);
}
