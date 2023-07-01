#include <stdio.h>
#include <stdlib.h>

#define MAKS_WIERZCHOLKOW 100

void drukujMacierz(int macierz[MAKS_WIERZCHOLKOW][MAKS_WIERZCHOLKOW], int wierzcholki)
{
    int i, j;
    printf("   ");
    for (i = 0; i < wierzcholki; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < wierzcholki; i++) {
        printf("%d ", i);
        for (j = 0; j < wierzcholki; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void drukujIncydencji(int macierz[MAKS_WIERZCHOLKOW][MAKS_WIERZCHOLKOW], int wierzcholki, int krawedzie)
{
    int i, j;
    
    
    for (i = 0; i < wierzcholki; i++) {
        for (j = 0; j < krawedzie; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void drukujListeSasiedztwa(int macierz[MAKS_WIERZCHOLKOW][MAKS_WIERZCHOLKOW], int wierzcholki)
{
    int i, j;
    for (i = 0; i < wierzcholki; i++) {
        printf("%d: ", i);
        for (j = 0; j < wierzcholki; j++) {
            if (macierz[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    //Dane:
    int wierzcholki; //wierzchołków
    int krawedzie;
    int i, j; //proste zmienne
    //----
    
    //Definicja:
    int MacierzSasiedztwa[MAKS_WIERZCHOLKOW][MAKS_WIERZCHOLKOW] = {0};
    int MacierzIncydencji[MAKS_WIERZCHOLKOW][MAKS_WIERZCHOLKOW] = {0};
    //------
    
    //Program Wita się, z użytkownikiem:
    printf("\n\t\t Witaj, wprowadź dane: \n");
    
    //Program prosi u użytkownika o podanie wartości:
    printf("Podaj liczbę wierzchołków grafu: ");
    scanf("%d", &wierzcholki);

    printf("Podaj liczbę krawędzi grafu: ");
    scanf("%d", &krawedzie);

    printf("Podaj definicję grafu (pary wierzchołków oddzielone spacją):\n");
    for (i = 0; i < krawedzie; i++) {
        //Nowe dane:
        int u, v;
        //----
        
        scanf("%d %d", &u, &v); //Pobiera dane
        
        //----
        MacierzSasiedztwa[u][v] = 1;
        MacierzIncydencji[u][i] = 1;
        MacierzIncydencji[v][i] = -1;
    }
    
    //Wyświetla wszystkie pobrane dane na ekran (podaje wynik) 
    printf("\nMacierz sąsiedztwa:\n");
    drukujMacierz(MacierzSasiedztwa, wierzcholki);

    printf("Macierz incydencji:\n");
    drukujIncydencji(MacierzSasiedztwa, wierzcholki, krawedzie);

    printf("Lista sąsiedztwa:\n");
    drukujListeSasiedztwa(MacierzSasiedztwa, wierzcholki);

    return 0;
}
