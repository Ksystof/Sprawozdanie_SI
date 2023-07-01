//Biblioteka:
#include <stdio.h>
#include <stdbool.h>

//Definicja:
#define MAKS_WIERZCHOLKI 20

//Deklaracja:
bool odwiedzony[MAKS_WIERZCHOLKI]; // Tablica odwiedzonych wierzchołków
int graf[MAKS_WIERZCHOLKI][MAKS_WIERZCHOLKI]; // Graf reprezentowany jako macierz sąsiedztwa
//----

void przeszukiwanieWglab(int wierzcholek, int cel) { //Funckja do wyświetlenia
    odwiedzony[wierzcholek] = true;
    printf("Przetwarzanie wierzchołka: %d (Trwa proces) \n", wierzcholek);

    if (wierzcholek == cel) {
        printf("Znaleziono wierzchołek docelowy: %d (Proces zatrzymany) \n", wierzcholek);
        return;
    }

    for (int i = 0; i < MAKS_WIERZCHOLKI; i++) {
        if (graf[wierzcholek][i] == 1 && !odwiedzony[i]) {
            przeszukiwanieWglab(i, cel);
        }
    }
}

int main() {
    // Deklaracja grafu:
    graf[0][1] = 1;
    graf[0][2] = 1;
    graf[1][3] = 1;
    graf[1][4] = 1;
    graf[2][5] = 1;
    graf[2][6] = 1;

    int wierzcholekStartowy = 0;
    int wierzcholekDocelowy = 4;

    // Inicjalizacja tablicy odwiedzone
    for (int i = 0; i < MAKS_WIERZCHOLKI; i++) {
        odwiedzony[i] = false;
    }

    printf("Rozpoczyna proces przeszukiwania w głąb ...\n");
    przeszukiwanieWglab(wierzcholekStartowy, wierzcholekDocelowy);

    return 0;
}
