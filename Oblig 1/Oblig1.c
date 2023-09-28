/**
 *   Utregning av poeng og maal etter en fortballkamp
 *
 *   @file     Oblig1.c
 *   @author   Gjermund H Pedersen, NTNU
 */

#include <stdio.h> // Importeres for bruker input/output
#include <string.h> // Importeres for string manipulasjon

const int STRLEN = 20;  // Definer hvor lang string brukeren kan inputte


/**
 * Hovedprogrammet:
*/
int main()
{
    // Definer arrayet som navnene til lagene lagres i
    char navnA[STRLEN], navnB[STRLEN]; 
    // Definer variablene for maal
    int maalA, maalB;
    // Definer variabler for poeng
    int poengA, poengB;
    // Definer spilte kamper, maal og poeng i starten
    int tallA[] = {10, 22, 10, 23},
        tallB[] = {10, 18, 12, 19};
    
    // Spoerr brukeren om lagenes nav og lagre de
    printf("1. Lagets navn: ");
    fgets(navnA, STRLEN, stdin);
    printf("2. Lagets navn: ");
    fgets(navnB, STRLEN, stdin);

    // Fjerne linjeskift fra slutten av lag navnene
    navnA[strlen(navnA)-1]='\0';
    navnB[strlen(navnB)-1]='\0';

    // Skriv ut tabellen med spilte kamper, maal og poeng
    printf("\n%s\t%i\t%i-%i\t%i\n", navnA, 
    tallA[0], tallA[1], tallA[2], tallA[3]);
    printf("%s\t%i\t%i-%i\t%i\n", navnB, 
    tallB[0], tallB[1], tallB[2], tallB[3]);

    // Spoer brukeren om scorte maal og lagre de
    printf("\nMaal for %s:\t", navnA);
    scanf("%i", &maalA);
    printf("Maal for %s:\t", navnB);
    scanf("%i", &maalB);

    // Spoer brukeren om poeng og lagre de
    printf("\nPoeng for %s:\t", navnA);
    scanf("%i", &poengA);
    printf("Poeng for %s:\t", navnB);
    scanf("%i", &poengB);

    // Legg til en paa antall kamper
    tallA[0]++;
    tallB[0]++;

    // Regn ut hvor mange maal hvert lag scoret til sammen
    tallA[1] += maalA;
    tallB[1] += maalB;

    // Regn ut hvor mange maal hvert lag slapp inn til sammen
    tallA[2] += maalB;
    tallB[2] += maalA;

    // Regn ut hvor mange poeng hvert lag har til sammen
    tallA[3] += poengA;
    tallB[3] += poengB;

    // 
    printf("\n%s\t%i\t%i-%i\t%i\n", navnA, 
    tallA[0], tallA[1], tallA[2], tallA[3]);
    printf("%s\t%i\t%i-%i\t%i\n", navnB, 
    tallB[0], tallB[1], tallB[2], tallB[3]);

    // Returner 0 for at funksjonen har fullfoert uten feil
    return 0;
}
