#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Struktura reprezentująca krawędź
struct Krawedz {
    int zrodlo, cel, waga;
};

// Struktura reprezentująca graf
struct Graf {
    int V, E; //V- wierzchołek, E-krawędź
    struct Krawedz* krawedzie;
};

// Funkcja do inicjalizacji grafu
struct Graf* stworzGraf(int V, int E) {
    struct Graf* graf = (struct Graf*) malloc(sizeof(struct Graf));
    graf->V = V;
    graf->E = E;
    graf->krawedzie = (struct Krawedz*) malloc(graf->E * sizeof(struct Krawedz));
    return graf;
}

// Funkcja do wyświetlania rezultatów
void wypiszWyniki(int dystans[], int n) {
    printf("Wierzcholek   Odleglosc od zrodla\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dystans[i]);
    }
}

// Implementacja algorytmu Bellmana-Forda
void BellmanFord(struct Graf* graf, int zrodlo) {
    int V = graf->V;
    int E = graf->E;
    int dystans[V];
    
    // Inicjalizacja dystansów od źródła do wszystkich wierzchołków jako "nieskończoność"
    for (int i = 0; i < V; i++) {
        dystans[i] = INT_MAX;
    }
    dystans[zrodlo] = 0; // Dystans od źródła do źródła wynosi 0

    // Relaksacja wszystkich krawędzi |V| - 1 razy
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graf->krawedzie[j].zrodlo;
            int v = graf->krawedzie[j].cel;
            int waga = graf->krawedzie[j].waga;
            if (dystans[u] != INT_MAX && dystans[u] + waga < dystans[v]) {
                dystans[v] = dystans[u] + waga;
            }
        }
    }

    // Wykrycie ujemnego cyklu
    for (int i = 0; i < E; i++) {
        int u = graf->krawedzie[i].zrodlo;
        int v = graf->krawedzie[i].cel;
        int waga = graf->krawedzie[i].waga;
        if (dystans[u] != INT_MAX && dystans[u] + waga < dystans[v]) {
            printf("Graf zawiera ujemny cykl\n");
            return;
        }
    }

    // Wyświetlenie wyników
    wypiszWyniki(dystans, V);
}

int main() {
    int V = 5;  // Liczba wierzchołków
    int E = 8;  // Liczba krawędzi

    struct Graf* graf = stworzGraf(V, E);

    // Dodawanie krawędzi
    graf->krawedzie[0].zrodlo = 0;
    graf->krawedzie[0].cel = 1;
    graf->krawedzie[0].waga = -1;

    graf->krawedzie[1].zrodlo = 0;
    graf->krawedzie[1].cel = 2;
    graf->krawedzie[1].waga = 4;

    graf->krawedzie[2].zrodlo = 1;
    graf->krawedzie[2].cel = 2;
    graf->krawedzie[2].waga = 3;

    graf->krawedzie[3].zrodlo = 1;
    graf->krawedzie[3].cel = 3;
    graf->krawedzie[3].waga = 2;

    graf->krawedzie[4].zrodlo = 1;
    graf->krawedzie[4].cel = 4;
    graf->krawedzie[4].waga = 2;

    graf->krawedzie[5].zrodlo = 3;
    graf->krawedzie[5].cel = 2;
    graf->krawedzie[5].waga = 5;

    graf->krawedzie[6].zrodlo = 3;
    graf->krawedzie[6].cel = 1;
    graf->krawedzie[6].waga = 1;

    graf->krawedzie[7].zrodlo = 4;
    graf->krawedzie[7].cel = 3;
    graf->krawedzie[7].waga = -3;

    int zrodlo = 0;  // Wierzchołek źródłowy

    BellmanFord(graf, zrodlo);

    return 0;
}
