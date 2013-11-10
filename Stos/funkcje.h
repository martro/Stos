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
#include <time.h>

#define ROZMIAR_POCZ 100
#define NAZWA_PLIKU 30

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

double at(dane_tablicy *dtab,int pozycja);
void funkcja_menu_01();
void funkcja_menu_02();
void funkcja_menu_03();
void funkcja_menu_04();
void funkcja_menu_05();
void funkcja_menu_06();
void funkcja_menu_07();
void funkcja_menu_08();
void funkcja_menu_09();
void generuj_sygnal(parametry *param,dane_tablicy *dtab);
void inicjalizuj_zegar(void);
int menu_glowne(parametry *param,dane_tablicy *dtab);
void odszum(parametry *param, dane_tablicy *dtab);
void podkreslenie(void);
double push(dane_tablicy *dtab, double wartosc);
void pushat(dane_tablicy *dtab, double wartosc, int pozycja);
void rysuj_wykres(parametry *param, dane_tablicy *dtab);
void ustaw_parametry_sygnalu(parametry *param, dane_tablicy *dtab);
void usun_tab(dane_tablicy *dtab);
void wczytaj_z_pliku(parametry *param, dane_tablicy *dtab);
void wyswietlanie(parametry *param,dane_tablicy *dtab);
void zapisz_bufor(parametry *param, dane_tablicy *dtab);
void zaszum(parametry *param, dane_tablicy *dtab);
void zatwierdz(void);

double at(dane_tablicy *dtab,int pozycja)
{
    return dtab->tab[pozycja];
}

void funkcja_menu_01(parametry *param,dane_tablicy *dtab)
{
    wyswietlanie(param,dtab);
}

void funkcja_menu_02(parametry *param,dane_tablicy *dtab)
{
    wczytaj_z_pliku(param,dtab);
}

void funkcja_menu_03(parametry *param,dane_tablicy *dtab)
{
    zapisz_bufor(param,dtab);
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

void funkcja_menu_07(parametry *param,dane_tablicy *dtab)
{
    zaszum(param,dtab);
}

void funkcja_menu_08(parametry *param,dane_tablicy *dtab)
{
    odszum(param,dtab);
}

void funkcja_menu_09(parametry *param,dane_tablicy *dtab)
{
    rysuj_wykres(param,dtab);
}

void generuj_sygnal(parametry *param, dane_tablicy *dtab)
{
    int i, dl_sygnalu;

    dl_sygnalu = dtab->czas * param->fp;

    for (i=0; i<dl_sygnalu; i++)
        push(dtab, param->amplituda * sin((M_PI *2* param->fs / param->fp) * i + param->fi));

    dtab->czy_wygenerowany=1;
}

void inicjalizuj_zegar(void)
{
    srand (time(NULL));
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
               "6 - USUN SYGNAL Z BUFORA\n"
               "\n"
               "7 - ZASZUM SYGNAL\n"
               "8 - ODSZUM SYGNAL\n\n"
               "9 - GENERUJ WYKRES  [Google Charts]\n"
               "WYBOR: ");
        if(scanf("%d",&wybor))   //jezeli odczytane jest liczba
        {
            if ((wybor>=0)&&(wybor<=10))
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
    case 2:
    {
        funkcja_menu_02(param,dtab);
        break;
    }
    case 3:
    {
        zapisz_bufor(param,dtab);
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
    case 7:
    {
        funkcja_menu_07(param,dtab);
        break;
    }
    case 8:
    {
        funkcja_menu_08(param,dtab);
        break;
    }
    case 9:
    {
        funkcja_menu_09(param,dtab);
        break;
    }
    default:
    {
        break;
    }
    }



    return wybor;
}

void odszum(parametry *param, dane_tablicy *dtab)
{
    int i,j,suma,n;

    n=param->fp*dtab->czas;

    pushat(dtab,(at(dtab,0)+at(dtab,1))/2.,0);
    pushat(dtab,(at(dtab,0)+at(dtab,1)+at(dtab,2)/3.),1);

    for (i=2;i<=(n-3);i++)
    {
        suma=0;
        for(j=(i-2);j<=(i+2);j++)
            {
                suma+=at(dtab,j);
            }
        pushat(dtab,suma/5.,i);
    }
    pushat(dtab,(at(dtab,n-3)+at(dtab,n-2)+at(dtab,n-1)/3.),n-2);
    pushat(dtab,(at(dtab,n-2)+at(dtab,n-1))/2.,n-1);
}

void podkreslenie(void)
{
    printf("\n-------------------\n");
}

double push(dane_tablicy *dtab, double wartosc)
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
    return wartosc;

}

void pushat(dane_tablicy *dtab, double wartosc, int pozycja)
{
    dtab->tab[pozycja]=wartosc;
}

void rysuj_wykres(parametry *param, dane_tablicy *dtab)
{
    int i,dl_sygnalu;
    char nazwa[NAZWA_PLIKU];
    FILE *pFile;

    dl_sygnalu = dtab->czas * param->fp;

    if (dtab->czy_wygenerowany)
    {
        printf("\nPODAJ NAZWE PLIKU: ");
        scanf("%s",nazwa);
        printf("%s",nazwa);
        pFile = fopen (nazwa,"w");

        if (pFile!=NULL)
        {
            fprintf(pFile,"<html>"
                    "  <head>"
                    "    <script type=\"text/javascript\" src=\"https://www.google.com/jsapi\"></script>"
                    "    <script type=\"text/javascript\">"
                    "      google.load(\"visualization\", \"1\", {packages:[\"corechart\"]});"
                    "      google.setOnLoadCallback(drawChart);"
                    "      function drawChart() {"
                    "        var data = google.visualization.arrayToDataTable(["
                    "          ['Napiece', 'Nr probki'],");


            for (i=0; i<dl_sygnalu; i++)
            {
                fprintf(pFile,"[%d,",i+1);
                fprintf(pFile," %f],\n",dtab->tab[i]);
            }

            /*
            "          [ 3,10],"
            "          [ 8,12],"
            "          [ 4,5.5],"
            "          [ 11,14],"
            "          [ 4,5],"
            "          [ 3,3.5],"
            "          [ 6.5,7]"*/
            fprintf(pFile,"        ]);"
                    "        var options = {"
                    "          title: 'Wykres napiecia od czasu',");
            fprintf(pFile,"          hAxis: {title: 'Nr probki', minValue: 0, maxValue: %lf},",dtab->czas*param->fp);
            fprintf(pFile,"          vAxis: {title: 'Napiecie', minValue: %lf, maxValue: %lf},",-param->amplituda,param->amplituda);
            fprintf(pFile,"          legend: 'none',"
                    "       pointSize: 1"
                    "        };"
                    "        var chart = new google.visualization.ScatterChart(document.getElementById('chart_div'));"
                    "        chart.draw(data, options);"
                    "      }"
                    "    </script>"
                    "  </head>"
                    "  <body>"
                    "    <div id=\"chart_div\" style=\"width: 900px; height: 500px;\"></div>"
                    "  </body>"
                    "</html>");

            fclose (pFile);
        }
    }
    else
        printf("\nsygnal nie wygenerowany\n");

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
    }
    else
        printf("\nW BUFORZE NIE MA SYGNALU");
}

void wczytaj_z_pliku(parametry *param, dane_tablicy *dtab)
{
    char nazwa[NAZWA_PLIKU],znak;
    int licznik=0,nr_probki,inttym;
    double odczyt, liczbatym;
    dtab->pozycja=0;
    FILE * pFile;
    if ((dtab->czy_wygenerowany)==0)
    {
        printf("\nPODAJ NAZWE PLIKU: ");
        scanf("%s",nazwa);
        printf("%s",nazwa);
        pFile = fopen (nazwa,"r");


        if (pFile!=NULL)
        {
            printf("\nOTWORZONO PLIK\n");
            do
            {
                znak=fgetc(pFile);

                fseek(pFile,-1,SEEK_CUR);

                if (znak=='*')
                {
                    while (fgetc(pFile)!='\n');
                    printf("koment\n");
                }
                if (znak=='@')
                {   licznik++;
                    while (fgetc(pFile)!=':');
                    fscanf(pFile,"%lf\n",&liczbatym);
                    printf("paremetry: %lf ",liczbatym);
                    if (licznik==1){printf("amplituda\n");  param->amplituda=liczbatym;}
                    if (licznik==2) {printf("fs\n");        param->fs=liczbatym;}
                    if (licznik==3) {printf("fi\n");        param->fi=liczbatym;}
                    if (licznik==4) {printf("fp\n");        param->fp=liczbatym;}
                    if (licznik==5) {printf("czas\n");      dtab->czas=liczbatym;}

                }
                if (znak==':')
                {
                    while(fgetc(pFile) != ':');
                    fscanf(pFile,"%d",&inttym);
                    while(fgetc(pFile) != ':');
                    fscanf(pFile,"%lf\n",&liczbatym);
                    printf("\ndane: %d.%lf",inttym,liczbatym);
                    push(dtab,liczbatym);
                }



           }
            while (znak!=EOF);

            printf("amplituda:                \t%lf\n",param->amplituda);
            printf("czestotliwosc sygnalu:    \t%lf\n",param->fs);
            printf("przesuniecie fazowe:      \t%lf\n",param->fi);
            printf("czestotliwosc probkowania:\t%lf\n",param->fp);
            printf("czas sygnalu:             \t%lf\n",dtab->czas);
            fclose (pFile);
            printf("dtab: %d, %d",dtab->pozycja,dtab->rozmiar);
            dtab->czy_wygenerowany=1;
            dtab->czy_parametry=1;
        }
    }

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

void zapisz_bufor(parametry *param, dane_tablicy *dtab)
{
    int i,dl_sygnalu;
    char nazwa[NAZWA_PLIKU];
    FILE * pFile;

    dl_sygnalu = dtab->czas * param->fp;

    if (dtab->czy_wygenerowany)
    {
        printf("\nPODAJ NAZWE PLIKU: ");
        scanf("%s",nazwa);
        printf("%s",nazwa);
        pFile = fopen (nazwa,"w");

        if (pFile!=NULL)
        {
            fprintf(pFile,"*WYGENEROWANY SYGNAL\n"
                    "*PARAMETRY\n");

            fprintf(pFile,"@amplituda:\t%lf\n",param->amplituda);
            fprintf(pFile,"@czestotliwosc sygnalu:\t%lf\n",param->fs);
            fprintf(pFile,"@przesuniecie fazowe:\t%lf\n",param->fi);
            fprintf(pFile,"@czestotliwosc probkowania:\t%lf\n",param->fp);
            fprintf(pFile,"@czas sygnalu:\t%lf\n",dtab->czas);

            for (i=0; i<dl_sygnalu; i++)
            {
                fprintf(pFile,":%d\t",i+1);
                if (dtab->tab[i]>=0)
                    fprintf(pFile," :%f\n",dtab->tab[i]);
                else
                    fprintf(pFile,":%lf\n",dtab->tab[i]);
            }
            fclose (pFile);
        }


    }
    else
        printf("\nsygnal nie wygenerowany\n");

}

void zaszum(parametry *param, dane_tablicy *dtab)
{
    int i,popr;
    double amplituda_szumu,szum;

        if (dtab->czy_wygenerowany)
    {
    printf("\nDODAWANIE SZUMU\n\n"
           "Ustaw parametry\n");
           do
           {
           popr=0;
           fflush(stdin);
           printf("Podaj amplitude szumu jako procent amplitudy sygnalu: ");
           popr=scanf("%lf",&amplituda_szumu);

           } while((amplituda_szumu<0) || (popr==0));


          for (i=0;i<(param->fp*dtab->czas);i++)
          {
            szum=rand()%1000;
            szum=param->amplituda*(szum/500-1)*amplituda_szumu/100;
            pushat(dtab,at(dtab,i)+szum,i);
            printf("%lf\n",at(dtab,i));
          }
    } else
    printf("\nSygnal nie zostal jeszcze wygenerowany. Nie mozna zaszumic.\n");

}

void zatwierdz(void)
{
    printf("\nNacisnij enter.\n");
    fflush(stdin);
    getchar();
}
#endif // FUNKCJE_H_INCLUDED
