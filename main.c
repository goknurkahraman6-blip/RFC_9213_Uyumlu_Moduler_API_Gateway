#include "priority_queue.h"

// Dýþarýdaki fonksiyonlarý tanýt
int parseUrgency(const char *header);
void processRequests(PriorityQueue *pq);

int main() {
    // 1. Kuyruðu baþlangýç kapasitesiyle oluþtur (malloc testi)
    PriorityQueue *pq = createQueue(2);

    // 2. Senaryo oluþtur (Farklý önceliklerde veriler)
    Request r1 = {10, parseUrgency("u=5"), "Resim istegi"};
    Request r2 = {20, parseUrgency("u=0"), "Kritik Guvenlik uyarisi"};
    Request r3 = {30, parseUrgency("u=2"), "Kullanici girisi"};
    Request r4 = {40, parseUrgency("u=1"), "Odeme islemi"};

    // 3. Verileri ekle (realloc burada devreye girecek)
    insert(pq, r1);
    insert(pq, r2);
    insert(pq, r3);
    insert(pq, r4);

    // 4. Oncelik sirasina gore isle ve ekrana bas
    processRequests(pq);

    // 5. Bellegi temizle (free testi)
    freeQueue(pq);

    return 0;
}
