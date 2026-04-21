# API Gateway Priority Request Scheduler (RFC 9213)

Bu proje, **RFC 9213 (Extensible HTTP Priorities)** standartlarına uygun olarak tasarlanmış, modüler bir API Gateway istek zamanlayıcısıdır. Projenin temel amacı, gelen HTTP isteklerini öncelik değerlerine göre sıralamak ve en acil olanı ilk sırada işleme almaktır.

## 🚀 Özellikler
* **Veri Yapısı:** Öncelik kuyruğu yönetimi için verimli **Min-Heap** algoritması kullanılmıştır.
* **Standart Uyumu:** İstek öncelikleri RFC 9213 (`u=0` ile `u=7` arası) formatında parse edilmektedir.
* **Modüler Mimari:** Kod; veri yapısı, parser ve gateway mantığı olarak ayrı katmanlarda (.h ve .c) inşa edilmiştir.
* **Dinamik Bellek:** `malloc`, `realloc` ve `free` fonksiyonları ile güvenli bellek yönetimi sağlanmıştır.

## 🛠️ Proje Mimarisi
* `priority_queue.h/c`: Min-Heap algoritması ve kuyruk operasyonları.
* `rfc_parser.c`: HTTP öncelik başlıklarını çözümleyen katman.
* `gateway.c`: İsteklerin işlendiği ana gateway mantığı.
* `main.c`: Test senaryoları ve sistemin giriş noktası.

## 💻 Kurulum ve Çalıştırma
Projeyi yerel makinenizde çalıştırmak için:
1. Depoyu klonlayın.
2. C derleyiciniz (GCC vb.) ile tüm dosyaları derleyin:
   ```bash
   gcc main.c priority_queue.c rfc_parser.c gateway.c -o api_gateway
   Oluşan dosyayı çalıştırın:
./api_gateway

📊 Algoritma Analizi
Sıradan bir dizi (Array) yerine Min-Heap kullanılmasının sebebi:

Ekleme (Insert): O(log n)

En Öncelikliyi Çıkarma (Extract-Min): O(log n)

Erişim: O(1)
Bu karmaşıklık değerleri, yüksek trafikli API sistemlerinde performans avantajı sağlar.
