# Evrimleşen Sistem Ödevi

## Seçilen Konu: D - E-Ticaret Sepeti

Bu konuyu seçmemin sebebi, indirim sistemlerinin gerçek hayatta sık kullanılması ve farklı indirim türlerinin sisteme kolay eklenebilir olmasının önemli olmasıdır. Mevcut yapı if-else bloklarına dayandığı için genişletilebilir değildir.

## Projenin Amacı

Bu proje, e-ticaret sepeti üzerinde farklı tasarım örüntülerini uygulayarak sistemin zamanla nasıl daha esnek ve genişletilebilir hale getirilebileceğini göstermektedir.

## Kullanılan Tasarım Örüntüleri

- Factory Method: İndirim nesnelerinin oluşturulmasını merkezi hale getirmek için kullanıldı.
- Strategy Pattern: İndirim hesaplama davranışlarını ayrı sınıflara ayırmak için kullanıldı.
- Decorator Pattern: Sepete kargo ve vergi gibi ek özellikler eklemek için kullanıldı.
- Facade Pattern: Sistemin dışarıdan daha kolay kullanılmasını sağlamak için kullanıldı.
- Command Pattern: Sepet işlemlerini komut sınıfları haline getirmek için kullanıldı.
- Observer Pattern: Sepette işlem gerçekleştiğinde bildirim göndermek için kullanıldı.

## Nasıl Çalıştırılır?

Projeyi derlemek için:

```bash
g++ src/main.cpp -o main
```

Çalıştırmak için:

```bash
./main
```

Windows üzerinde:

```bash
main.exe
```

## Mimari Diyagram

```mermaid
classDiagram

    class Sepet {
        -double toplamTutar
        +kargoEkle()
        +vergiEkle()
        +getToplamTutar()
    }

    class IndirimStrategy {
        <<interface>>
        +indirimUygula(double)
    }

    class OgrenciIndirimi
    class Yuzde20Indirimi
    class Kupon50Indirimi

    class SepetDecorator
    class KargoDecorator
    class VergiDecorator

    class Komut {
        <<interface>>
        +calistir()
    }

    class KargoEkleKomutu
    class VergiEkleKomutu

    class Observer {
        <<interface>>
        +bildirimGonder(string)
    }

    class EmailObserver

    IndirimStrategy <|-- OgrenciIndirimi
    IndirimStrategy <|-- Yuzde20Indirimi
    IndirimStrategy <|-- Kupon50Indirimi

    Sepet <|-- SepetDecorator
    SepetDecorator <|-- KargoDecorator
    SepetDecorator <|-- VergiDecorator

    Komut <|-- KargoEkleKomutu
    Komut <|-- VergiEkleKomutu

    Observer <|-- EmailObserver
    Sepet --> Observer
```

## Proje Yapısı

```text
evrimlesen-sistem-odevi/
├── README.md
├── PATTERNS.md
├── PROBLEMS.md
├── src/
│   └── main.cpp
├── docs/
│   └── ai-log/
│       ├── phase1.md
│       ├── phase2.md
│       └── phase3.md
└── .github/
    └── workflows/
        └── ci.yml
```
