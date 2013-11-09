/**
*Laboratorium Programowanie w C
*Program generujacy sygnaly
*Marcin Trojan 205608 MTR W-10
    */

#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int czy_wygenerowany;
    int czy_parametry;
} dane_tablicy;

void funkcja_menu_01();
void funkcja_menu_04();
void funkcja_menu_05();
void funkcja_menu_06();
void generuj_sygnal(parametry *param,dane_tablicy *dtab);
int menu_glowne(parametry *param,dane_tablicy *dtab);
void podkreslenie(void);
void push(dane_tablicy *dtab, double wartosc);
void ustaw_parametry_sygnalu(parametry *param, dane_tablicy *dtab);
void usun_tab(dane_tablicy *dtab);
void wyswietlanie(parametry *param,dane_tablicy *dtab);
void zatwierdz(void);

void funkcja_menu_01(parametry *param,dane_tablicy *dtab)
{
    wyswietlanie(param,dtab);
}

void funkcja_menu_04(parametry *param,dane_tablicy *dtab)
{
    int blad=0;

    printf("GENEROWANIE SYGNALU\n\n");

    if (dtab->czy_wygenerowany) //jesli juz wygenerowano
    {
        printf("\nSygnal jest juz wygenerowany.\n"
               "Musisz usunac poprzedni przed generowaniem nowego.\n");
        blad=1;
    }

    if (dtab->czy_parametry == 0)   //jesli nie ustawiono paramerow
    {
        printf("\nNie ustawiono parametrow\n"
               "Musisz ustawic parametry przed wygenerowaniem sygnalu.\n");
        blad=1;
    }

    if (blad==0)
    {
        generuj_sygnal(param,dtab);
        printf("\nSygnal wygenerowany pomyslnie.\n"
               "Parametry wygenerowanego sygnalu:\n\n");

        podkreslenie();
        printf("amplituda:                \t%lf\n",param->amplituda);
        printf("czestotliwosc sygnalu:    \t%lf\n",param->fs);
        printf("przesuniecie fazowe:      \t%lf\n",param->fi);
        printf("czestotliwosc probkowania:\t%lf\n",param->fp);
        printf("czas sygnalu:             \t%lf\n",dtab->czas);
    }

}

void funkcja_menu_05(parametry *param,dane_tablicy *dtab)
{
    ustaw_parametry_sygnalu(param,dtab);
}

void funkcja_menu_06(dane_tablicy *dtab)
{
    usun_tab(dtab);
}

void generuj_sygnal(parametry *param, dane_tablicy *dtab)
{
    int i, dl_sygnalu;

    dl_sygnalu = dtab->czas * param->fp;

    for (i=0; i<dl_sygnalu; i++)
        push(dtab, param->amplituda * sin((M_PI * param->fs / param->fp) * i + param->fi));

    dtab->czy_wygenerowany=1;
}

int menu_glowne(parametry *param,dane_tablicy *dtab)
{
    int wybor;
    char blad_odczytu;

    do
    {
        blad_odczytu=1;
        fflush(stdin);
        podkreslenie();
        printf("WYBOR AKCJI PROGRAMU\n"
               "1 - WYSWIETL SYGNAL ZNAJDUJACY SIE W BUFORZE\n"
               "2 - ZALADUJ ZAPISANY SYGNAL DO BUFORA\n"
               "3 - ZAPISZ SYGNAL ZNAJDUJACY SIE W BUFORZE\n"
               "\n"
               "4 - GENERUJ SYGNAL\n"
               "5 - USTAW PARAMETRY SYGNALU\n"
               "6 - USUN POPRZEDNIO WYGENEROWANY SYGNAL\n"
               "\n"
               "7 - ZASZUM SYGNAL\n"    //jeszcze nie dziala
               "8 - USTAW PARAMETRY SZUMU\n\n"  //jeszcze nie dziala
               "9 - ODSZUM SYGNAL\n"


               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor>=0)&&(wybor<10))
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

    switch (wybor)
    {
    case 0:
    {
        break;
    }
    case 1:
    {
        funkcja_menu_01(param,dtab);
        break;
    }
    case 4:
    {
        funkcja_menu_04(param,dtab);
        break;
    }
    case 5:
    {
        funkcja_menu_05(param,dtab);
        break;
    }
    case 6:
    {
        funkcja_menu_06(dtab);
        break;
    }
    default:
    {
        break;
    }
    }



    return wybor;
}

void podkreslenie(void)
{
    printf("\n-------------------\n");
}

void push(dane_tablicy *dtab, double wartosc)
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

void ustaw_parametry_sygnalu(parametry *param, dane_tablicy *dtab)
{
    podkreslenie();
    printf("PODAJ PARAMETRY SYGNALU\n");
    printf("amplituda: ");
    scanf("%lf",&param->amplituda);
    printf("czestotliwosc sygnalu: ");
    scanf("%lf",&param->fs);
    printf("przesuniecie fazowe: ");
    scanf("%lf",&param->fi);
    printf("czestotliwosc probkowania: ");
    scanf("%lf",&param->fp);
    printf("czas sygnalu: ");
    scanf("%lf",&dtab->czas);

    dtab->czy_parametry=1;

    /*
    dtab->czas=2;
    param->amplituda=5;
    param->fi=0;
    param->fp=100;
    param->fs=1;*/

}

void usun_tab(dane_tablicy *dtab)
{
    if (dtab->czy_wygenerowany)
    {
    free(dtab->tab);
    dtab->czy_wygenerowany=0;
    dtab->pozycja=0;
    dtab->rozmiar=0;
    printf("\nWYGENEROWANY SYGNAL ZOSTAL USUNIETY\n");
    } else
    printf("\nW BUFORZE NIE MA SYGNALU");
}

void wyswietlanie(parametry *param,dane_tablicy *dtab)
{
    int i,dl_sygnalu;
    dl_sygnalu = dtab->czas * param->fp;

    if (dtab->czy_wygenerowany)
    {
        for (i=0; i<dl_sygnalu; i++)
        {
            printf("%d\t",i+1);
            if (dtab->tab[i]>=0)
                printf(" %f\n",dtab->tab[i]);
            else
                printf("%lf\n",dtab->tab[i]);
        }
    }
    else
        printf("\nsygnal nie wygenerowany\n");
}

void zatwierdz(void)
{
    printf("\nNacisnij enter.\n");
    fflush(stdin);
    getchar();
}
#endif // FUNKCJE_H_INCLUDED
