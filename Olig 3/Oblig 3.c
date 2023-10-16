/**
 * @file Oblig.c
 * @author Gjermund H. Pedersen
 */
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int STRLEN = 80; ///< Max.tekstlengde.
const int ANTINT = 20; ///< Lengden på int-array.
int antallIArray(int tall[], const int n, const int min, const int max);
void fyllArray(int tall[], const int n);
char lesKommando();
int lesTall(const char tekst[], const int min, const int max);
void lesTekst(const char ledetekst[], char tekst[]);
bool sjekkTekst(const char tekst[]);
void skrivMeny();

/**
 * Hovedprogrammet:
 */
int main()
{
    char kommando;
    int tallene[ANTINT];
    char teksten[STRLEN];
    skrivMeny();
    kommando = lesKommando();
    while (kommando != 'Q')
    {
        switch (kommando)
        {
        case 'F':
            fyllArray(tallene, ANTINT);
            break;
        case 'A':
            printf("\nAntall i arrayen i intervallet 0-2000: %i\n",
                   antallIArray(tallene, ANTINT, 0, 2000));
            break;
        case 'L':
            lesTekst("Postnummer og -sted", teksten);
            break;
        case 'S':
            printf("\nTeksten er%s et gyldig postnr og -sted.\n",
                   ((!sjekkTekst(teksten)) ? " IKKE" : ""));
            break;
        default:
            skrivMeny();
            break;
        }
        kommando = lesKommando();
    }
    return 0;
}

/**
 * Teller antall tall i arrayen som er i det gitte intervallet
 *
 * @param tall - Tallene som skal sjekkes
 * @param n    - Lengden av tall
 * @param min  - Minste verdi som skal telles (Inklusiv)
 * @param max  - Største verdi som skal telles (Eksklusiv)
 */
int antallIArray(int tall[], const int n, const int min, const int max)
{
    int antallIArray = 0;
    for (int i = 0; i < n; i++)
    {
        if (min <= tall[i] && tall[i] < max)
        {
            antallIArray++;
        }
    }
    return antallIArray;
};

/**
 *  Fyller den medsendte arrayen med n tallverdier i et aktuelt interval
 *
 * @param tall - Array som tallene skal fylles inn i
 * @param n    - Antall verdier som skal bli lest,der n < lengden av tall
 */
void fyllArray(int tall[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Neste tall: ");
        scanf("%i", &tall[i]);
    }
};

/**
 *  Leser og returnerer ett (upcaset) tegn.
 *
 *  @return  Ett (upcaset) tegn.
 */
char lesKommando()
{
    char tegn;
    printf("Skriv kommando:  ");
    scanf(" %c", &tegn);
    getchar();
    return (toupper(tegn));
}

/**
 *  Leser og returnerer et tall mellom to gitte grenser.
 *
 *  @param   tekst  - Ledetekst til brukeren når ber om input/et tall
 *  @param   min    - Minimum for innlest og godtatt tallverdi
 *  @param   max    - Maksimum for innlest og godtatt tallverdi
 *
 *  @return  Godtatt verdi i intervallet 'min' - 'max'
 */
int lesTall(const char tekst[], const int min, const int max)
{
    int tall;
    do
    {
        printf("\t%s (%i-%i):  ", tekst, min, max);
        scanf("%i", &tall);
        getchar();
    } while (tall < min || tall > max);
    return tall;
}

/**
 *  Leser tekst inn i medsendt char-array/tekst/string.
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[])
{
    printf("%s:  ", ledetekst);
    gets(tekst); //  Oppdaterer ORIGINALEN/aktuell parameter.
}

bool sjekkTekst(const char tekst[])
{
    const int tekstLengde = strlen(tekst);
    if (tekstLengde<5)return false;
    
    int numTall = 4;
    for (int i = 0; i < tekstLengde; i++)
    {
        printf("%c", tekst[i]);
        if (isdigit(tekst[i]))
        {
            if (i>1)
            {
                if (tekst[i+1]==' ')
                {
                    numTall=i;
                }
            }
        }
        else if (i>numTall)
        {
            if (!isalpha(tekst[i]) && !tekst[i] == ' ' && !tekst[i] == '.' && !tekst[i] == '-')
            {
                return false;
            }
        }
        else{
            return false;
        }
    }
    return true;
};

/**
 * Skriver ut start menyen
*/
void skrivMeny(){
    printf("\nKommandoer:\n");
    printf("F - Fyll inn tall i et array\n");
    printf("A - Tell antall tall i arrayet som er mellom 0 og 2000\n");
    printf("L - Fyll inn tekst med postnummer og sted.\n");
    printf("    Må først være 3-4 tall etterfulgt av en blank.\n");
    printf("    Resten må kun bestå av bokstaver, blanke, bindestreker eller punktum\n");
    printf("S - Sjekk om teksten er et gyldig postnummer og sted\n");
    printf("Q - Avslutt programmet\n\n");
};
