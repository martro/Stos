#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"


int main(void)

{
    parametry *param;
    dane_tablicy *dtab;
    param = (parametry *)malloc(sizeof(parametry));
    dtab = (dane_tablicy *)malloc(sizeof(dane_tablicy));

    dtab->pozycja=0;
    dtab->rozmiar=0;

    menu_glowne();

return 0;
}
