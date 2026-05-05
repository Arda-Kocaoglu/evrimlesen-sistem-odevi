# PROBLEMS.md

## Tespit Edilen Tasarım Sorunları

1. God Class Problemi  
Sepet sınıfı hem veri tutuyor hem de indirim hesaplıyor. Bu sorumluluklar ayrılmamış.

2. If-Else Bağımlılığı  
İndirim türleri if-else blokları ile kontrol ediliyor. Yeni indirim eklemek için mevcut kodu değiştirmek gerekiyor.

3. Açık/Kapalı Prensibi (OCP) İhlali  
Sisteme yeni bir indirim türü eklemek mevcut fonksiyonu değiştirmeyi gerektiriyor.

4. Genişletilebilirlik Sorunu  
Yeni indirim türleri eklendikçe kod karmaşıklaşacak ve okunabilirliği azalacak.

5. Tekrar Eden Mantık  
Her indirim türü aynı fonksiyon içinde hesaplanıyor, bu da kodun modüler olmasını engelliyor.

---

## AI Analizi ile Karşılaştırma

AI analizine göre bu kodda Strategy Pattern veya Factory Pattern kullanılabilir. Benim tespit ettiğim sorunlar ile AI’ın tespitleri büyük ölçüde örtüşmektedir.

Ancak AI daha çok tasarım örüntüsü önerisine odaklanırken, ben kodun genişletilebilirlik ve okunabilirlik problemlerine daha fazla dikkat ettim.
