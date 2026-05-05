# Kullanılan Tasarım Örüntüleri

## Phase 1 - Strategy Pattern

### Nerede Kullanıldı?

İndirim hesaplama işlemlerinde kullanıldı. Önceden Sepet sınıfı içinde if-else blokları vardı.

### Neden Kullanıldı?

İndirim türleri değişebilir ve zamanla yeni indirimler eklenebilir. Bu yüzden indirim hesaplama davranışını Sepet sınıfından ayırmak daha doğru oldu.

### Ne Kazandırdı?

- If-else blokları azaldı.
- Kod daha okunabilir hale geldi.
- Yeni indirim türü eklemek kolaylaştı.
- Açık/Kapalı Prensibine daha uygun bir yapı oluştu.
