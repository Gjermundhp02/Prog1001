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

    skrivMeny();
    kommando = lesKommando();

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N': nyOppgave();                 break;
          case 'S': skrivOppgaver();             break;
          case 'L': ledigeOppgaver();            break;  
          case 'P': personerTilknyttesOppgave(); break;  
          case 'F': fjernOppgave();              break;
          default:    break;    
        }
        kommando = lesKommando();
    }

    printf("\n\n");
    return 0;
}