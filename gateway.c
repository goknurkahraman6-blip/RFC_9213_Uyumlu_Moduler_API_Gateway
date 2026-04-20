#include "priority_queue.h"
#include <stdio.h>

void processRequests(PriorityQueue *pq) {
    printf("--- API Gateway Oncelikli Istek Listesi ---\n");
    while (pq->size > 0) {
        Request r = extractMin(pq);
        printf("[ISLEM] ID: %-3d | Oncelik: u=%-2d | Veri: %s\n", r.id, r.urgency, r.data);
    }
}
