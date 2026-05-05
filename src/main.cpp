#include <iostream>
using namespace std;

class Sepet {
public:
    double toplamTutar;

    Sepet(double tutar) {
        toplamTutar = tutar;
    }

    double indirimUygula(string indirimTipi) {
        double indirimliTutar = toplamTutar;

        if (indirimTipi == "ogrenci") {
            indirimliTutar = toplamTutar * 0.90;
        }
        else if (indirimTipi == "yuzde20") {
            indirimliTutar = toplamTutar * 0.80;
        }
        else if (indirimTipi == "kupon50") {
            indirimliTutar = toplamTutar - 50;
        }
        else {
            cout << "Indirim yok" << endl;
        }

        return indirimliTutar;
    }
};

int main() {
    Sepet sepet(500);

    cout << "Indirimli Tutar: "
         << sepet.indirimUygula("ogrenci") << endl;

    return 0;
}
