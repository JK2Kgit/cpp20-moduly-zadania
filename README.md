# Moduły C++20 — zadania

Pięć [zadań na zajęcia](zadania.md): dwa najprostsze, jedno konkretne i dwa praktyczne. Repozytorium zawiera polecenia i pliki startowe, bez rozwiązań.

- [Zadanie 1](szablony/zadanie1): konfiguracja CMake; dopisz `main.cpp` i `pliki.cppm`.
- [Zadanie 4](szablony/zadanie4): kompletny projekt z implementacją wektorową, plikami testowymi i CMake. Zmieniasz tylko `statystyki.cpp`.

Wymagane są C++20 z obsługą modułów i CMake ≥ 3.28 (obsługa `FILE_SET CXX_MODULES`). Generator: Ninja ≥ 1.11 albo Visual Studio 2022 z MSVC ≥ 14.34. Zobacz [wymagania CMake](https://cmake.org/cmake/help/v3.28/manual/cmake-cxxmodules.7.html).

Przykład z Ninja, w katalogu wybranego zadania:

```sh
cmake -S . -B build -G Ninja
cmake --build build
```

Alternatywnie na Windowsie z Visual Studio 2022 i MSVC:

```sh
cmake -S . -B build-vs -G "Visual Studio 17 2022"
cmake --build build-vs --config Debug
```

Dla zadań 2, 3 i 5 dostosuj listę źródeł według dołączonych przykładów CMake i materiałów do zajęć.
