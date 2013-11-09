/**
*Laboratorium Programowanie w C
*Program generujacy sygnaly
*Marcin Trojan 205608 MTR W-10
    */

#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED

#define ROZMIAR_POCZ 100

typedef struct  //parametry sygnalu
{
    double amplituda;
    double fs;  //czestotliwosc sygnalu
    double fp;  //czestottliwosc probkowania
    double fi;  //przesuniecie fazowe
} parametry;


typedef struct
{
    double *tab; //danych
    double czas;
    int rozmiar;
    int pozycja;
} dane_tablicy;


int menu_glowne(void);
void podkreslenie(void);
void push(dane_tablicy *dtab, int wartosc);


int menu_glowne(void)
{
    int wybor;
    char blad_odczytu;

    do
    {
        blad_odczytu=1;
        fflush(stdin);
        podkreslenie();
        printf("WYBOR AKCJI PROGRAMU\n"
               "1 - GENERUJ SYGNAL\n"
               "2 - ZASZUM SYGNAL\n\n"
               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczb¹
        {
            if ((wybor>0)&&(wybor<10))
            {
                printf("Poprawnie odczytano. Twoj wybor to: %d\n",wybor);
                blad_odczytu=0;
                podkreslenie();
            }
            else
            {
                printf("Blad wyboru akcji. Wybierz ponownie.");
                blad_odczytu=1;
            }

        }
        else
        {
            printf("Blad wyboru akcji. Wybierz ponownie.");
            blad_odczytu=1;
        }
    }
    while (blad_odczytu==1);



    return wybor;
}

void podkreslenie(void)
{
    printf("\n-------------------\n");
}

void push(dane_tablicy *dtab, int wartosc)
{
    if (dtab->rozmiar==0)
    {
        dtab->tab = ((double *)malloc(sizeof(double) * ROZMIAR_POCZ));
        dtab->rozmiar=ROZMIAR_POCZ;
    }
    if (dtab->pozycja >= dtab->rozmiar)
    {
        dtab->tab=realloc(dtab->tab,dtab->rozmiar*2*sizeof(double));
        dtab->rozmiar=dtab->rozmiar*2;
    }
    dtab->tab[dtab->pozycja ++]=wartosc;

}
#endif // FUNKCJE_H_INCLUDED
