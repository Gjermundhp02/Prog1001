/**
 * Program som leser tall og sjekker om de er mellom et interval og
 * leser en adresse og postnummer og sjekker om det er gyldig
 * Har en brukerinterface med karakter komandoer
 * 
 * @file Oblig.c
 * @author Gjermund H. Pedersen
 */
#include <stdbool.h> // bool
#include <stdio.h> // scanf, printf, getChar, gets
#include <ctype.h> // idalpha, isdigit
#include <string.h> // strlen

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
 * Kopiert fra oppgaven
 * 
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
            printf("\nAntall i arrayen i intervallet 0-2000: %i\n\n",
                   antallIArray(tallene, ANTINT, 0, 2000));
            break;
        case 'L':
            lesTekst("Postnummer og -sted", teksten);
            break;
        case 'S':
            printf("\nTeksten er%s et gyldig postnr og -sted.\n\n",
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
 * 
 * @return Antall elementer i arrayet som er mellom de to gitte verdiene
 */
int antallIArray(int tall[], const int n, const int min, const int max)
{
    int antallIArray = 0; // Antall tall som er i intervalet
    for (int i = 0; i < n; i++) // Går gjennom alle tallene
    {
        if (min <= tall[i] && tall[i] < max) // Sjekker om det er innenfor
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
    for (int i = 0; i < n; i++) // Leser et input for hver index i arrayet
    {
        // 3000 for at antallIArray skal kunne filtrere ut noe
        tall[i] = lesTall("Neste tall: ", 0, 3000); 
    }
};

/**
 *  Leser og returnerer ett (upcaset) tegn.
 *  Kopiert fra oppgaven
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
 *  Kopiert fra oppgaven
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
 *  Kopiert fra oppgaven
 *
 *  @param   ledetekst  - Ledetekst som utskrift til brukeren om hva lese inn
 *  @param   tekst      - char-array som fylles med innlest tekst
 */
void lesTekst(const char ledetekst[], char tekst[])
{
    printf("%s:  ", ledetekst);
    gets(tekst); //  Oppdaterer ORIGINALEN/aktuell parameter.
}

/**
 * Sjekker om teksten som blir sendt inn er gyldig postkode og adresse
 * 
 * @param tekst - Teksten som skal sjekkes 
 * 
 * @return Om teksten er gyldig postkode 
 */
bool sjekkTekst(const char tekst[])
{
    const int tekstLengde = strlen(tekst);
    if (tekstLengde<5)return false; // Sjekker om teksten er under 5 karakterer. 
                                    // Den er alltid ugyldig da
    
    int indexSisteTall = 4; // Lagrer indexen til det siste tallet i postkoden
    for (int i = 0; i < tekstLengde; i++) // Lopper lengden av teksten
    {
        if (isdigit(tekst[i]))
        {
            if (i>1) // Hvis den er på det tredje eller fjerde tallet
            {
                if (tekst[i+1]==' ') // Hvis neste karakter er ' ' er slutten av
                {                    // postkoden funnet
                    indexSisteTall=i;
                }
            }
        }
        else if (i>indexSisteTall)
        {
            if (!isalpha(tekst[i]) && // Hvis karakteren ikke er a-z, '.', 
                !tekst[i] == ' ' &&   // ' ' eller '-' er ikke teksten gyldig
                !tekst[i] == '.' && 
                !tekst[i] == '-')
            {
                return false;
            }
        }
        else{ // Hvis karakteren ikke er et tall eller løkken er forbi der
              // slutten av postkoden burde vært er teksten ikke gyldig
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
