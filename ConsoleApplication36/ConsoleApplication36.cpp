#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Produs {
    string nume;
    double pret;
};

struct Comanda {
    string numeClient;
    vector<Produs> produseComandate;
    double total;
};

int main() {
    vector<Produs> meniu;
    vector<Comanda> comenzi;

    meniu.push_back({ "Ulei", 25.0 });
    meniu.push_back({ "Ceapa", 12.0 });
    meniu.push_back({ "Coca Cola", 15.0 });
    meniu.push_back({ "Pizza", 15.0 });

    int numarulProdus;
    Comanda comanda{};

    while (true) {
        cout << "Bine ati venit la restaurantul nostru!" << endl;
        cout << "Meniu disponibil\n";

        for (const auto& produs : meniu) {
            cout << produs.nume << "-" << produs.pret << " Lei ";
        }

        cout << "\nAlege un numar din meniu (0 pentru a finaliza comanda)\n";
        cin >> numarulProdus;

        if (numarulProdus < 0 || numarulProdus > meniu.size()) {
            cout << "Comanda invalida, va rog sa incercati din nou\n";
            continue;
        }

        if (numarulProdus == 0) {
            break;
        }

        comanda.produseComandate.push_back(meniu[numarulProdus - 1]);
        comanda.total += meniu[numarulProdus - 1].pret;
        cout << "Ati adaugat " << meniu[numarulProdus - 1].nume << " la comanda. Total " << comanda.total << " Lei\n";
    }

    comenzi.push_back(comanda);
    cin.ignore();
    cout << "Comanda inregistrata cu succes" << endl;
    cout << "Produse comandate\n";

    for (const Comanda& com : comenzi) {
        cout << "Client " << com.numeClient << endl;
        cout << "Produse Comandate" << endl;

        for (const Produs& produs : com.produseComandate) {
            cout << "--" << produs.nume << "--" << produs.pret << " Lei ";
        }

        cout << "\nTotal Comanda: " << com.total << " Lei\n";
        cout << "-------------\n";
    }

    return 0;
}
