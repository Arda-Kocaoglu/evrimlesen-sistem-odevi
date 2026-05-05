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
    OgrenciIndirimi ogrenciIndirimi;
    Sepet sepet(500, &ogrenciIndirimi);

    cout << "Indirimli Tutar: "
         << sepet.indirimliTutarHesapla() << endl;

    return 0;
}
