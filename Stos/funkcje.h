/**
*Laboratorium Programowanie w C
*Program generujacy sygnaly
*Marcin Trojan 205608 MTR W-10
    */

#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED


void podkreslenie(void);
int menu(void);


int menu(void)
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
#endif // FUNKCJE_H_INCLUDED
