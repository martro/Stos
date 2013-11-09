#include "funkcje.h"


int main(void)

{
    parametry *param;
    dane_tablicy *dtab;
    param = (parametry *)malloc(sizeof(parametry));
    dtab = (dane_tablicy *)malloc(sizeof(dane_tablicy));

    dtab->pozycja=0;
    dtab->rozmiar=0;
    /*
    dtab->czas=2;
    param->amplituda=5;
    param->fi=0;
    param->fp=100;
    param->fs=1;*/


    menu_glowne();

    ustaw_parametry_sygnalu(param,dtab);

    generuj_sygnal(param,dtab);
    wyswietlanie(param,dtab);
return 0;
}




