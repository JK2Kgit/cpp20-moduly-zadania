export module statystyki;

export struct Statystyki {
    int liczba;
    double minimum;
    double maksimum;
    double srednia;
};

export void dodajPomiar(double wartosc);
export Statystyki pobierzStatystyki();
export void wyczysc();
