module;

#include <vector>

module statystyki;

namespace {
std::vector<double> pomiary;
}

void dodajPomiar(double wartosc) {
    pomiary.push_back(wartosc);
}

Statystyki pobierzStatystyki() {
    if (pomiary.empty()) return {0, 0, 0, 0};
    double minimum = pomiary.front();
    double maksimum = pomiary.front();
    double suma = 0;
    for (double wartosc : pomiary) {
        if (wartosc < minimum) minimum = wartosc;
        if (wartosc > maksimum) maksimum = wartosc;
        suma += wartosc;
    }
    return {static_cast<int>(pomiary.size()), minimum, maksimum, suma / pomiary.size()};
}

void wyczysc() {
    pomiary.clear();
}
