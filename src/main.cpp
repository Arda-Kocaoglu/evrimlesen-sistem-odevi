#include <iostream>
using namespace std;

// Strategy Pattern
class IndirimStrategy {
public:
    virtual double indirimUygula(double toplamTutar) = 0;
};

class OgrenciIndirimi : public IndirimStrategy {
public:
    double indirimUygula(double toplamTutar) override {
        return toplamTutar * 0.90;
    }
};

class Yuzde20Indirimi : public IndirimStrategy {
public:
    double indirimUygula(double toplamTutar) override {
        return toplamTutar * 0.80;
    }
};

// Sepet sınıfı
class Sepet {
protected:
    double toplamTutar;
    IndirimStrategy* strategy;

public:
    Sepet(double tutar, IndirimStrategy* s) {
        toplamTutar = tutar;
        strategy = s;
    }

    virtual double toplamHesapla() {
        return strategy->indirimUygula(toplamTutar);
    }
};

// Decorator Base
class SepetDecorator : public Sepet {
protected:
    Sepet* sepet;

public:
    SepetDecorator(Sepet* s) : Sepet(0, nullptr) {
        sepet = s;
    }

    virtual double toplamHesapla() {
        return sepet->toplamHesapla();
    }
};

// Kargo Decorator
class KargoDecorator : public SepetDecorator {
public:
    KargoDecorator(Sepet* s) : SepetDecorator(s) {}

    double toplamHesapla() override {
        return sepet->toplamHesapla() + 30;
    }
};

// Vergi Decorator
class VergiDecorator : public SepetDecorator {
public:
    VergiDecorator(Sepet* s) : SepetDecorator(s) {}

    double toplamHesapla() override {
        return sepet->toplamHesapla() * 1.18;
    }
};

int main() {
    SepetFacade facade;

    cout << "Toplam Tutar: "
         << facade.hesapla(500, "ogrenci") << endl;

    return 0;
}

class SepetFacade {
public:
    double hesapla(double tutar, string indirimTipi) {
        IndirimStrategy* strategy;

        if (indirimTipi == "ogrenci") {
            strategy = new OgrenciIndirimi();
        } else {
            strategy = new Yuzde20Indirimi();
        }

        Sepet* sepet = new Sepet(tutar, strategy);

        sepet = new KargoDecorator(sepet);
        sepet = new VergiDecorator(sepet);

        return sepet->toplamHesapla();
    }
};

