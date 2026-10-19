#include <iostream>
#include <string>

import statystyki;

// Plik dostarczony do zadania. Nie wolno go zmieniac.
int main() {
    std::string polecenie;
    while (std::cin >> polecenie) {
        if (polecenie == "dodaj") {
            double wartosc;
            if (!(std::cin >> wartosc)) {
                std::cout << "Niepoprawny pomiar.\n";
                return 1;
            }
            dodajPomiar(wartosc);
        } else if (polecenie == "pokaz") {
            const Statystyki wynik = pobierzStatystyki();
            std::cout << wynik.liczba << ' ' << wynik.minimum << ' '
                      << wynik.maksimum << ' ' << wynik.srednia << '\n';
        } else if (polecenie == "wyczysc") {
            wyczysc();
        } else if (polecenie == "koniec") {
            break;
        } else {
            std::cout << "Nieznane polecenie.\n";
        }
    }
}
