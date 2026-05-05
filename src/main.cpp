#include <iostream>
#include <vector>
using namespace std;

// Observer Pattern
class Observer {
public:
    virtual void bildirimGonder(string mesaj) = 0;
};

class EmailObserver : public Observer {
public:
    void bildirimGonder(string mesaj) override {
        cout << "Email bildirimi: " << mesaj << endl;
    }
};

// Sepet sınıfı
class Sepet {
private:
    double toplamTutar;
    vector<Observer*> observers;

public:
    Sepet(double tutar) {
        toplamTutar = tutar;
    }

    void observerEkle(Observer* observer) {
        observers.push_back(observer);
    }

    void bildirimleriGonder(string mesaj) {
        for (Observer* observer : observers) {
            observer->bildirimGonder(mesaj);
        }
    }

    void kargoEkle() {
        toplamTutar += 30;
        bildirimleriGonder("Kargo ucreti eklendi.");
    }

    void vergiEkle() {
        toplamTutar *= 1.18;
        bildirimleriGonder("Vergi uygulandi.");
    }

    double getToplamTutar() {
        return toplamTutar;
    }
};

// Command Pattern
class Komut {
public:
    virtual void calistir() = 0;
};

class KargoEkleKomutu : public Komut {
private:
    Sepet* sepet;

public:
    KargoEkleKomutu(Sepet* s) {
        sepet = s;
    }

    void calistir() override {
        sepet->kargoEkle();
    }
};

class VergiEkleKomutu : public Komut {
private:
    Sepet* sepet;

public:
    VergiEkleKomutu(Sepet* s) {
        sepet = s;
    }

    void calistir() override {
        sepet->vergiEkle();
    }
};

class SepetIslemYoneticisi {
private:
    vector<Komut*> komutlar;

public:
    void komutEkle(Komut* komut) {
        komutlar.push_back(komut);
    }

    void komutlariCalistir() {
        for (Komut* komut : komutlar) {
            komut->calistir();
        }
    }
};

int main() {
    Sepet sepet(500);

    EmailObserver emailObserver;
    sepet.observerEkle(&emailObserver);

    KargoEkleKomutu kargoKomutu(&sepet);
    VergiEkleKomutu vergiKomutu(&sepet);

    SepetIslemYoneticisi yonetici;
    yonetici.komutEkle(&kargoKomutu);
    yonetici.komutEkle(&vergiKomutu);

    yonetici.komutlariCalistir();

    cout << "Son toplam tutar: "
         << sepet.getToplamTutar() << endl;

    return 0;
}
