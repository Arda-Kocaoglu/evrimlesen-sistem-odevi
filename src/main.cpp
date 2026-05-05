#include <iostream>
using namespace std;

class IndirimStrategy {
public:
    virtual double indirimUygula(double toplamTutar) = 0;
    virtual ~IndirimStrategy() {}
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

class Kupon50Indirimi : public IndirimStrategy {
public:
    double indirimUygula(double toplamTutar) override {
        return toplamTutar - 50;
    }
};

class IndirimFactory {
public:
    static IndirimStrategy* indirimOlustur(string indirimTipi) {
        if (indirimTipi == "ogrenci") {
            return new OgrenciIndirimi();
        }
        else if (indirimTipi == "yuzde20") {
            return new Yuzde20Indirimi();
        }
        else if (indirimTipi == "kupon50") {
            return new Kupon50Indirimi();
        }
        else {
            return nullptr;
        }
    }
};

class Sepet {
private:
    double toplamTutar;
    IndirimStrategy* indirimStrategy;

public:
    Sepet(double tutar, IndirimStrategy* strategy) {
        toplamTutar = tutar;
        indirimStrategy = strategy;
    }

    double indirimliTutarHesapla() {
        return indirimStrategy->indirimUygula(toplamTutar);
    }
};

int main() {
    IndirimStrategy* indirim = IndirimFactory::indirimOlustur("ogrenci");

    if (indirim != nullptr) {
        Sepet sepet(500, indirim);

        cout << "Indirimli Tutar: "
             << sepet.indirimliTutarHesapla() << endl;

        delete indirim;
    }

    return 0;
}
