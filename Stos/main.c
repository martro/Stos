#include "funkcje.h"


int main(void)

{
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
           "Marcin Trojan 205608 MTR W-10\n");


    do
    {
        zatwierdz();
        dzialaj=menu_glowne(param,dtab);
    }
    while (dzialaj);


free(dtab);
free(param);
    return 0;
}




