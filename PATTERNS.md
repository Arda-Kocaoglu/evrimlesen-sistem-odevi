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

## Phase 2 - Decorator Pattern

### Nerede Kullanıldı?

Sepet sınıfına kargo ve vergi gibi ek özellikler eklemek için kullanıldı.

### Neden Kullanıldı?

Mevcut yapıyı değiştirmeden yeni özellikler eklemek istendi. Bu sayede Sepet sınıfı genişletilebilir hale geldi.

### Ne Kazandırdı?

- Esnek yapı sağlandı
- Kod tekrarının önüne geçildi
- Mevcut kod değiştirilmeden yeni özellik eklendi


## Phase 2 - Facade Pattern

### Nerede Kullanıldı?

SepetFacade sınıfı ile sistemin dışarıdan kullanımını basitleştirmek için kullanıldı.

### Neden Kullanıldı?

Kullanıcının indirim, kargo ve vergi işlemlerini tek tek yönetmesi yerine tek bir sınıf üzerinden işlem yapması sağlandı.

### Ne Kazandırdı?

- Kullanımı kolaylaştırdı
- Karmaşıklığı gizledi
- Daha okunabilir bir yapı oluşturdu

