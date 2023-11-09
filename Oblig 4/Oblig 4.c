/**
 *   Programeksempel nr 27 - Større programeksempel.
 *
 *   Programmet:
 *     - 
 *
 *   @file     Oblig 4.c
 *   @author   Gjermund H. Pedersen
 */

#include "LesData.h"

#define MAXPERS 6
#define MAXOPPG 20

struct Oppgave {
char* navn;
int antallTotalt,
    antallNaa;
int hvem[MAXPERS];
};

struct Oppgave* gOppgavene[MAXOPPG];
int gSisteOppgave = 0;

void nyOppgave(); // Legger til en ny oppgave
void oppgaveLesData(struct Oppgave* oppgave);
void skrivOppgaver();
void oppgaveSkrivData(const struct Oppgave* oppgave);
void ledigeOppgaver();
void personerTilknyttesOppgave();
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void fjernOppgave();
void oppgaveSlettData(struct Oppgave* oppgave);
void skrivMeny(); // Skriver ut menyen med komandoene


/**
 *  Hovedprogrammet:
 */
int main ()  {
    char kommando;

    // skrivMeny();
    kommando = lesChar("Kommando");

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N': nyOppgave();                 break;
          case 'S': skrivOppgaver();             break;
        //   case 'L': ledigeOppgaver();            break;  
        //   case 'P': personerTilknyttesOppgave(); break;  
        //   case 'F': fjernOppgave();              break;
          default:    break;    
        }
        kommando = lesChar("Kommando");
    }

    printf("\n\n");
    return 0;
}

/**
 * @brief Lager en ny oppgave
*/
void nyOppgave(){
    if (gSisteOppgave>MAXOPPG){
        printf("Det er ikke plass til flere oppgaver");
    }
    else{
        gOppgavene[gSisteOppgave] = (struct Oppgave*) malloc(sizeof(struct Oppgave));
        oppgaveLesData(gOppgavene[gSisteOppgave]);
        gSisteOppgave++;
    }
};

/**
 * @brief Leser data inn i en oppgave
*/
void oppgaveLesData(struct Oppgave* oppgave){
    oppgave->navn = lagOgLesText("Skriv inn et navn: ");
    oppgave->antallTotalt = lesInt("Hvor mange kan jobbe på denne oppgaven (0-6): ", 0, 6);
    oppgave->antallNaa = 0;
};

/**
 * @brief Skriver ut alle oppgavene og infoen
*/
void skrivOppgaver(){
    struct Oppgave** oppgaver = gOppgavene;
    printf("Oppgaver:\n");
    do
    {
        oppgaveSkrivData((*oppgaver));
    }while ((*++oppgaver));
};

/**
 * @brief Skriver ut dataen i en oppgave
*/
void oppgaveSkrivData(const struct Oppgave* oppgave){
    printf("\tNavn: %s\n", oppgave->navn);
    printf("\tMax antall på oppgvaen: %i\n", oppgave->antallTotalt);
    printf("\tAntall på oppgvaen: %i\n", oppgave->antallNaa);
    if (*oppgave->hvem){
        printf("\tPerson id-er på oppgven: ");
        for (int i = 0; oppgave->hvem[i]; i++)
        {
            printf("%i, ", oppgave->hvem[i]);
        }
        printf("\n");
    }
    printf("\n");
};