# Phase 3 AI Log

## Pair Programming Süreci

Bu fazda AI ile sepet sistemine davranışsal tasarım örüntüleri ekleme üzerine çalıştım. Sistemde yeni davranışların mevcut kodu fazla değiştirmeden eklenebilmesi amaçlandı.

## Tartışılan Konular

- Command Pattern ile işlemlerin komut sınıflarına ayrılması
- Observer Pattern ile işlem sonrası bildirim gönderilmesi
- Açık/Kapalı Prensibine daha uygun bir yapı kurulması
- Yeni davranışların mevcut sınıfları bozmadan eklenmesi

## AI Yanıtının Özeti

AI, sepet işlemlerinin Command Pattern ile ayrı sınıflara taşınabileceğini belirtti. Ayrıca sepette bir işlem gerçekleştiğinde bildirim sistemi çalışacaksa Observer Pattern kullanılabileceğini söyledi.

## Benim Uyguladığım Çözüm

Kargo ekleme ve vergi ekleme işlemleri için ayrı komut sınıfları oluşturdum. SepetIslemYoneticisi sınıfı bu komutları sırayla çalıştırmaktadır.

Ayrıca Sepet sınıfına observer listesi eklendi. EmailObserver sınıfı ile işlem gerçekleştiğinde kullanıcıya bildirim verilmesi sağlandı.

## AI Olmadan Bu Faz Ne Kadar Sürerdi?

AI olmadan bu fazın yaklaşık 4-5 saat sürebileceğini düşünüyorum. Çünkü hangi davranışsal örüntünün bu yapıya daha uygun olduğunu seçmek daha uzun sürebilirdi.

## AI Nerede Yanıltabilir?

AI bazen örüntüleri gereğinden fazla karmaşık hale getirebilir. Bu yüzden önerilen yapıyı direkt kopyalamak yerine, projenin seviyesine uygun daha sade bir yapı oluşturdum.