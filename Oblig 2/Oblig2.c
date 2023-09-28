/**
 * Kalkulator
 *
 * Programmet er en ekel kalkulator
 *
 * @file Oblig2.c
 * @author Gjermund H. Pedersen
 */
#include <stdbool.h>
#include <stdio.h>

/**
 * Hovedprogrammet
*/
int main()
{
    // Deklaret variabler
    float akkumulator = 0.0;
    char operasjonsHistorie[255];
    float tallHistorie[255];


    printf("Enkel kalkulator starter:\n\n");
    // Index for å vite hvilken operasjon vi er på
    int operasjonsIndex = 0;
    while (true)
    {
        printf("= %.3f\n\n", akkumulator);
        // Lagre operasjonen i historien på den indeksen vi er
        scanf("%c", &operasjonsHistorie[operasjonsIndex]);
        if (operasjonsHistorie[operasjonsIndex] == 's' && getchar() == '\n')
        {
            // Avslutt programmet med å gå ut av while loopen
            break;
        }
        switch (operasjonsHistorie[operasjonsIndex])
        {
        case '+':
            scanf("%f", &tallHistorie[operasjonsIndex]);
            getchar(); // Fjerner \n fra bufferen
            akkumulator += tallHistorie[operasjonsIndex];
            break;
        case '-':
            scanf("%f", &tallHistorie[operasjonsIndex]);
            getchar(); // Fjerner \n fra bufferen
            akkumulator -= tallHistorie[operasjonsIndex];
            break;
        case '*':
            scanf("%f", &tallHistorie[operasjonsIndex]);
            getchar(); // Fjerner \n fra bufferen
            akkumulator *= tallHistorie[operasjonsIndex];
            break;
        case '/':
            scanf("%f", &tallHistorie[operasjonsIndex]);
            getchar(); // Fjerner \n fra bufferen
            if (tallHistorie[operasjonsIndex] == 0)
            {
                /** 
                 * Stopper brukeren fra å dele på 0 ved å 
                 * gå ut av switchen tidlig
                 * 
                 * Trekk fra en fra operasjonsIndex så vi skriver
                 * over den ugyldige komandoen
                 */
                operasjonsIndex--; 
               printf("Feil! Dele på null er tull\n");
                break;
            }
            akkumulator /= tallHistorie[operasjonsIndex];
            break;
        case 't':
            scanf("%f", &tallHistorie[operasjonsIndex]);
            getchar(); // Fjerner \n fra bufferen
            // Setter akkumulatoren til den spesifiserte verdien
            akkumulator = tallHistorie[operasjonsIndex];
            break;
        case 'c':
            // Reseter akkumulatoren
            akkumulator = 0;
            break;
        default:
            /**
             * Trekk fra en fra operasjonsIndex så vi skriver
             * over den ugyldige komandoen
             */
            operasjonsIndex--; 
            printf("Feil! Ukjent kommando gitt\n");
            while (getchar() != '\n'){} // Tøm bufferen
            break;
        }
        operasjonsIndex++;
    }
    printf("Enkel kalkulator stopper\n\nOperasjonene og tallene involvert:\n");
    // Skriver ut operasjonsHistorien og tallHistorien
    for (int i = 0; i < operasjonsIndex; i++)
    {
        printf("%c og tallet: %7.3f\n", operasjonsHistorie[i], tallHistorie[i]);
    }
    return 0;
}
