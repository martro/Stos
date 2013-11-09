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



    do
    {
        dzialaj=menu_glowne(param,dtab);
    }
    while (dzialaj);

    return 0;
}




