#include <stdio.h> //Biblioteki
#include <stdbool.h>

//Definicja
#define MAKS_WIERZCHOLEK 15

//Deklaracja:
bool odwiedzony[MAKS_WIERZCHOLEK]; // Tablica odwiedzonych wierzchołków
int graf[MAKS_WIERZCHOLEK][MAKS_WIERZCHOLEK]; // Graf reprezentowany jako macierz sąsiedztwa


void przeszukiwanieWszerz(int startowy) {
    int kolejka[MAKS_WIERZCHOLEK]; // Kolejka FIFO - First-In, First-Out
    int poczatek = 0; // Indeks początku kolejki
    int koniec = 0; // Indeks końca kolejki

    kolejka[koniec++] = startowy; // Dodajemy wierzchołek startowy do kolejki
    odwiedzony[startowy] = true; // Oznaczamy go jako odwiedzony

    printf("Rozpoczym przeszukiwania wszerz ... \n");

    while (poczatek < koniec) { // Dopóki kolejka nie jest pusta
        int aktualny = kolejka[poczatek++]; // Pobierz wierzchołek z początku kolejki
        printf("Przetwarzanie wierzchołka: %d \n", aktualny);

        // Przetwarzaj sąsiadów wierzchołka aktualnego
        for (int i = 0; i < MAKS_WIERZCHOLEK; i++) {
            if (graf[aktualny][i] == 1 && !odwiedzony[i]) {
                kolejka[koniec++] = i; // Dodaj sąsiada do kolejki
                odwiedzony[i] = true; // Oznacz sąsiada jako odwiedzonego
            }
        }
    }
}

int main() {
    //Deklarujemy graf:
    graf[0][1] = 1;
    graf[0][2] = 1;
    graf[1][3] = 1;
    graf[1][4] = 1;
    graf[2][5] = 1;
    graf[2][6] = 1;

    //Deklaracja danych:
    int wierzcholekStartowy = 0;

    //Inicjalizacja tablicy odwiedzonej na false
    for (int i = 0; i < MAKS_WIERZCHOLEK; i++) {
        odwiedzony[i] = false;
    }
  
    //Program zaczyna działać:
    printf("Rozpoczynanie przeszukiwania wszerz (BFS)...\n");
    przeszukiwanieWszerz(wierzcholekStartowy);

    return 0;
}
