#include <stdio.h>
#include <stdbool.h>

//Deklaracja:
#define NIESKONCZONOSC  9999
#define WIERZCHOLKI 6 // Liczba wierzchołków w grafie

//Funkcje:
void wyswietlWynik(int dystans[], int n)
{
    printf("Wierzcholek \t Odleglosc od zrodla\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dystans[i]);
}

int znajdzNajmniejszaOdleglosc(int dystans[], bool odwiedzony[])
{
    int minOdleglosc = NIESKONCZONOSC, minIndeks;

    for (int v = 0; v < WIERZCHOLKI; v++)
    {
        if (odwiedzony[v] == false && dystans[v] <= minOdleglosc)
        {
            minOdleglosc = dystans[v];
            minIndeks = v;
        }
    }

    return minIndeks;
}

void dijkstra(int graf[WIERZCHOLKI][WIERZCHOLKI], int zrodlo)
{
    int dystans[WIERZCHOLKI];
    bool odwiedzony[WIERZCHOLKI];

    for (int i = 0; i < WIERZCHOLKI; i++)
    {
        dystans[i] = NIESKONCZONOSC;
        odwiedzony[i] = false;
    }

    dystans[zrodlo] = 0;

    for (int count = 0; count < WIERZCHOLKI - 1; count++)
    {
        int u = znajdzNajmniejszaOdleglosc(dystans, odwiedzony);

        odwiedzony[u] = true;

        for (int v = 0; v < WIERZCHOLKI; v++)
        {
            if (!odwiedzony[v] && graf[u][v] && dystans[u] != NIESKONCZONOSC && dystans[u] + graf[u][v] < dystans[v])
            {
                dystans[v] = dystans[u] + graf[u][v];
            }
        }
    }

    wyswietlWynik(dystans, WIERZCHOLKI);
}

int main()
{
    //Deklaracja zmiennych:
    int graf[WIERZCHOLKI][WIERZCHOLKI] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int zrodlo = 0;

    //Wywołanie funkcji:
    dijkstra(graf, zrodlo);

    return 0;
}
