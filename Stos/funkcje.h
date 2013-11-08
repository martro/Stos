/**
*Laboratorium Programowanie w C
*Program generujacy sygnaly
*Marcin Trojan 205608 MTR W-10
    */

#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED

typedef struct  //tutaj przechowywane sa parametry sygnalu
{
    double amplituda;
    double fs; //cz�stotliwo�� sygna�u
    double fp; //cz�stotliwo�� pr�bkowania
    double fi; //przesuni�cie fazowe
} parametry;


typedef struct
{
    double *tab; //tablica przechowywania danych
    double czas;
    int rozmiar_tablicy;

} dane_tablicy;

void podkreslenie(void);
int menu_glowne(void);


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
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczb�
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
#endif // FUNKCJE_H_INCLUDED
