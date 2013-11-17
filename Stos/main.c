#include "funkcje.h"


int main(void)

{
    inicjalizuj_zegar();
    int dzialaj;
    parametry *param;
    dane_tablicy *dtab;
    param = (parametry *)malloc(sizeof(parametry));
    dtab = (dane_tablicy *)malloc(sizeof(dane_tablicy));

    dtab->pozycja=0;
    dtab->rozmiar=0;
    dtab->czy_wygenerowany=0;
    dtab->czy_parametry=0;

    printf("Laboratorium Programowanie w C\n"
           "Program generujacy sygnaly\n"
           "Prowadzacy: mgr inz. Mariusz Ostrowski\n"
           "Marcin Trojan 205608 MTR W-10\n");


    do
    {

        dzialaj=menu_glowne(param,dtab);
        zatwierdz();
    }
    while (dzialaj);


    free(dtab);
    free(param);
    return 0;
}




