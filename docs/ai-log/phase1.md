# Phase 1 AI Log

## Sorduğum Prompt

Bu projede indirim hesaplama işlemi Sepet sınıfı içinde if-else blokları ile yapılıyor. Bu yapıda hangi tasarım sorunları vardır ve hangi tasarım örüntüsü daha uygun olur?

## AI Yanıtının Özeti

AI, bu yapıdaki en büyük problemin indirim hesaplama sorumluluğunun Sepet sınıfına bağlı olması olduğunu belirtti. Yeni indirim türleri eklendikçe if-else bloklarının artacağını ve bunun Açık/Kapalı Prensibine aykırı olduğunu söyledi. Çözüm olarak Strategy Pattern kullanılabileceğini önerdi.

## Benim Uyguladığım Çözüm

Sepet sınıfındaki if-else bloklarını kaldırdım. Her indirim türünü ayrı bir sınıfa taşıdım. OgrenciIndirimi, Yuzde20Indirimi ve Kupon50Indirimi sınıfları IndirimStrategy arayüzünden türetildi.

Bu sayede yeni bir indirim türü eklemek için Sepet sınıfını değiştirmeye gerek kalmadı.
