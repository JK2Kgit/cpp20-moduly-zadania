# Moduły C++20 — zadania

## 1. Rozpoznawanie plików graficznych

**Najprostsze.** Napisz moduł `pliki` z eksportowaną funkcją `bool czyObraz(const char* nazwa)`, rozpoznającą nazwy zakończone `.png`, `.jpg` lub `.bmp`. Rozróżniaj wielkość liter; argument to poprawny napis z samą nazwą pliku, bez ścieżki.

Zdefiniuj funkcję w `pliki.cppm`. W `main.cpp` zaimportuj moduł i sprawdź:

- `zdjecie.png`, `wakacje.jpg`, `ikona.bmp` → `true`;
- `notatki.txt`, `obraz.png.txt`, `FOTO.PNG`, `bez_rozszerzenia`, pusty napis → `false`.

Możesz użyć `std::string_view::ends_with`. Gotowy [CMakeLists.txt](szablony/zadanie1/CMakeLists.txt) umieść obok swoich plików.

## 2. Organizer korzystający z innego modułu

**Najprostsze.** Dodaj moduł `organizator` z eksportowaną funkcją `const char* katalogDocelowy(const char* nazwa)`. Zaimportuj w nim niezmieniony moduł `pliki` z zadania 1 i wykorzystaj `czyObraz`: dla obrazów zwracaj `obrazy`, dla pozostałych nazw — `pozostale`. Nie twórz katalogów ani nie przenoś plików.

W `main.cpp` importuj wyłącznie `organizator`. Sprawdź `zdjecie.png`, `obraz.png.txt` i `FOTO.PNG` — oczekiwane wyniki to `obrazy`, `pozostale`, `pozostale`.

Spróbuj też wywołać bezpośrednio `czyObraz` w `main.cpp`. Wyjaśnij w komentarzu, dlaczego zwykły import zależności nie udostępnia tej funkcji użytkownikowi organizera. Zakomentuj niedozwolone wywołanie przed oddaniem. Przy budowaniu uwzględnij oba moduły.

## 3. Walidacja daty i następny dzień

**Konkretne.** Napisz moduł `kalendarz` eksportujący strukturę `Data` z polami `int dzien`, `int miesiac`, `int rok` oraz funkcje:

```cpp
bool czyPoprawnaData(Data data);
bool przesunODzien(Data& data);
```

Deklaracje umieść w `kalendarz.cppm`, definicje w `kalendarz.cpp`. Pierwsza funkcja sprawdza poprawność daty dla lat `1–9999`. Druga przesuwa poprawną datę o dzień i zwraca `true`; dla błędnej daty i `31.12.9999` zwraca `false`, nie zmieniając argumentu. Funkcje pomocnicze pozostaw wewnątrz implementacji.

Rok jest przestępny, jeśli dzieli się przez `400` albo przez `4`, ale nie przez `100`. Sprawdź:

- `28.02.2024 → 29.02.2024 → 01.03.2024`;
- `28.02.1900 → 01.03.1900`, `28.02.2000 → 29.02.2000`;
- `30.04.2026 → 01.05.2026`, `31.12.2026 → 01.01.2027`;
- odrzucenie `31.04.2026`, `29.02.2025`, dnia `0`, miesiąca `13`, roku `0` i przesunięcia `31.12.9999` — argument pozostaje bez zmian.

## 4. Statystyki bez przechowywania pomiarów

**Praktyczne.** [Gotowy projekt](szablony/zadanie4) zawiera `main.cpp`, interfejs `statystyki.cppm`, implementację `statystyki.cpp` z wektorem i konfigurację CMake. Zastąp przechowywanie wszystkich pomiarów obliczaniem statystyk na bieżąco.

**Modyfikujesz wyłącznie `statystyki.cpp`. Nie wolno zmieniać `main.cpp` ani `statystyki.cppm`.**

Przechowuj tylko licznik, sumę, minimum i maksimum. Dodawanie, odczyt statystyk oraz zużycie pamięci mają być O(1). Dla pustego zbioru i po `wyczysc()` wszystkie pola wyniku są zerowe. Pierwszy pomiar, również ujemny, ma poprawnie ustawić ekstrema. Załóż skończone wartości oraz liczbę i sumę pomiarów mieszczące się w użytych typach.

Program przyjmuje polecenia `dodaj liczba`, `pokaz`, `wyczysc`, `koniec`. Uruchom wersję przed zmianą i po niej z [wejściem testowym](szablony/zadanie4/wejscie.txt). Obie powinny zwrócić [oczekiwany wynik](szablony/zadanie4/wynik.txt).

Oddaj zmienioną implementację i wynik testu. Krótko wyjaśnij, dlaczego program główny pozostał bez zmian i dlaczego zużycie pamięci nie rośnie z liczbą pomiarów.

## 5. Eksport raportu do CSV

**Praktyczne.** Dodaj moduł `raport` z eksportowaną funkcją `bool zapiszRaport(const char* sciezka)`. Interfejs i implementację umieść w osobnych plikach. Implementacja ma importować `statystyki` z zadania 4 i korzystać z `pobierzStatystyki()`, bez powielania obliczeń.

Zapisz nagłówek i jeden wiersz danych, rozdzielając kolumny średnikiem, a część dziesiętną kropką. Dla pomiarów `10`, `20`, `-6`:

```text
liczba;minimum;maksimum;srednia
3;-6;20;8
```

Zwracaj `true` po poprawnym zapisaniu i zamknięciu pliku, a `false` dla pustego zbioru lub błędu otwarcia/zapisu. Pusty zbiór nie może tworzyć ani nadpisywać pliku. Udany zapis zastępuje wcześniejszą zawartość. Możesz użyć `std::ofstream`.

Napisz osobny `main.cpp` importujący oba moduły i sprawdź:

- pusty zbiór — brak nowego pliku;
- zapis powyższych pomiarów — poprawna zawartość;
- dodanie `8` i ponowny zapis — jeden nagłówek i wiersz `4;-6;20;8`;
- nieistniejący katalog — `false`;
- reset i próba nadpisania raportu — `false`, wcześniejszy plik bez zmian.

Nie zmieniaj interfejsu statystyk. Zakaz zmiany dostarczonego `main.cpp` dotyczy zadania 4. Przy budowaniu uwzględnij oba interfejsy modułów oraz ich implementacje.
