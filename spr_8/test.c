#include <stdio.h>
#include <stdlib.h>

//Definicja
#define WSPOLCZYNNIK_UCZENIA 0.01
#define MAX_ITERACJI 1000

//Funkcje:
void regresjaLiniowa(double X[], double Y[], int n, double* wspolczynnikNachylenia, double* przeciecie) {
    double sumaX = 0, sumaY = 0, sumaXY = 0, sumaXX = 0;
    for (int i = 0; i < n; i++) {
        sumaX += X[i];
        sumaY += Y[i];
        sumaXY += X[i] * Y[i];
        sumaXX += X[i] * X[i];
    }
    
    double sredniaX = sumaX / n;
    double sredniaY = sumaY / n;
    
    *wspolczynnikNachylenia = (sumaXY - n * sredniaX * sredniaY) / (sumaXX - n * sredniaX * sredniaX);
    *przeciecie = sredniaY - (*wspolczynnikNachylenia) * sredniaX;
}

int main() {
    //Deklaracja danych:
    double X[] = {1, 2, 3, 4, 5};
    double Y[] = {2, 4, 5, 4, 5};
    int n = sizeof(X) / sizeof(X[0]);
    
    double wspolczynnikNachylenia, przeciecie;

    //Wywołanie funkcji:
    regresjaLiniowa(X, Y, n, &wspolczynnikNachylenia, &przeciecie);
    
    //Wyświetla wynik:
    printf("Równanie prostej: Y = %.2fX + %.2f\n", wspolczynnikNachylenia, przeciecie);
    
    return 0;
}
