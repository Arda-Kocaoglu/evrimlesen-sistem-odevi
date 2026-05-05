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

## Phase 1 Fix - Factory Method

### Nerede Kullanıldı?

İndirim nesnelerinin oluşturulması IndirimFactory sınıfı ile merkezi hale getirildi.

### Neden Kullanıldı?

Nesne oluşturma işlemini Sepet sınıfından ayırmak ve daha esnek bir yapı oluşturmak için kullanıldı.

### Ne Kazandırdı?

- Nesne oluşturma sorumluluğu ayrıldı.
- Kod daha modüler hale geldi.
- Yeni indirim türleri eklemek kolaylaştı.

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

## Phase 3 - Command Pattern

### Nerede Kullanıldı?

Sepet üzerinde yapılacak işlemler komut sınıfları haline getirildi. Kargo ekleme ve vergi ekleme işlemleri ayrı komutlar olarak tanımlandı.

### Neden Kullanıldı?

Sepet işlemlerini doğrudan çağırmak yerine yönetilebilir komutlar haline getirmek istendi. Bu sayede yeni işlemler sisteme daha düzenli şekilde eklenebilir.

### Ne Kazandırdı?

- İşlemler ayrı sınıflara ayrıldı.
- Yeni komut eklemek kolaylaştı.
- Kod daha düzenli ve genişletilebilir hale geldi.


## Phase 3 - Observer Pattern

### Nerede Kullanıldı?

Sepette bir işlem gerçekleştiğinde bildirim göndermek için kullanıldı.

### Neden Kullanıldı?

Sepet sınıfı, bildirim gönderme detaylarına doğrudan bağımlı olmadan farklı gözlemcilere haber verebilmelidir.

### Ne Kazandırdı?

- Bildirim sistemi esnek hale geldi.
- Yeni bildirim türleri kolayca eklenebilir.
- Sepet ile bildirim sistemi arasındaki bağımlılık azaldı.


