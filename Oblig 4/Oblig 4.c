/**
 *   Programeksempel nr 27 - Større programeksempel.
 *
 *   Programmet:
 *     - 
 *
 *   @file     Oblig 4.c
 *   @author   Gjermund H. Pedersen
 */
#include <stdbool.h>
#include <string.h>
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
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
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
          case 'L': ledigeOppgaver();            break;  
          case 'P': personerTilknyttesOppgave(); break;  
          case 'F': fjernOppgave();              break;
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
    oppgave->navn = lagOgLesText("Skriv inn et navn");
    oppgave->antallTotalt = lesInt("Hvor mange kan jobbe på denne oppgaven", 0, 6);
    oppgave->antallNaa = 0;
};

/**
 * @brief Skriver ut alle oppgavene og infoen
*/
void skrivOppgaver(){
    if (!gOppgavene[0]){
        printf("Det finnes ingen oppgaver.\n\n");
    }
    else{
        struct Oppgave** oppgaver = gOppgavene;
        // Anntar at det er en oppgave
        printf("Oppgaver:\n");
        do
        {
            oppgaveSkrivData((*oppgaver));
        }while ((*++oppgaver));
    }
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

/**
 * @brief Går gjennom alle oppgavene og skriver ut de som ikke er fulle
*/
void ledigeOppgaver(){
    if (!gOppgavene[0]){
        printf("Det finnes ingen oppgaver.\n\n");
    }
    else{
        struct Oppgave** oppgaver = gOppgavene;
        // Anntar at det er en ledig oppgave
        if(!oppgaveLedigPlass((*oppgaver))){
            printf("Det finnes ingen ledige oppgaver.\n\n");
        }
        else{
            printf("Ledige oppgaver:\n");
            oppgaveSkrivData(*oppgaver);
            while(*++oppgaver){
                if (oppgaveLedigPlass((*oppgaver))){
                    oppgaveSkrivData((*oppgaver));
                }
                
            };
        }
    }
};

/**
 * @brief Finner ut om en oppgave har ledig plass
*/
bool oppgaveLedigPlass(const struct Oppgave* oppgave){
    return oppgave->antallNaa<oppgave->antallTotalt;
};

/**
 * @brief 
*/
void personerTilknyttesOppgave(){
    if (!gOppgavene[0]){
        printf("Det finnes ingen oppgaver.\n\n");
    }
    else{
        char* oppgaveNavn = lagOgLesText("Hvilken oppgeve, (0 = angre)");
        if(strcmp("0", oppgaveNavn)==0){
            return;
        }
        else{
            struct Oppgave** oppgaver = gOppgavene;
            while(!(strcmp(oppgaveNavn, (*oppgaver)->navn)==0)){
                oppgaver++;
            }
            oppgaveTilknyttPersoner((*oppgaver));
        }
    }
};

/**
 * @brief
*/
void oppgaveTilknyttPersoner(struct Oppgave* oppgave){
    oppgaveSkrivData(oppgave);
    if(!oppgaveLedigPlass(oppgave)){
        printf("Oppgaven er full.");
        return;
    }
    else{
        int antallNye = lesInt("Hvor mange nye skal legges til", 0, 
                               oppgave->antallTotalt-oppgave->antallNaa);
        for (int i = 0; i < antallNye; i++)
        {
            oppgave->hvem[oppgave->antallNaa++] = lesInt(
                "Id på personen som legges til", 0, 1000);
        }
        oppgaveSkrivData(oppgave);
    }
};

/**
 * @brief
*/
void fjernOppgave(){
    if (!gOppgavene[0])
    {
        printf("Det finnes ingen oppgaver.\n\n");
        return;
    }
    else{
        char* oppgaveNavn = lagOgLesText("Hvilken oppgave vil du fjerne");
        if(strcmp("0", oppgaveNavn)==0){
            printf("Ingenting ble fjernet.\n");
            return;
        }

        struct Oppgave** oppgaver = gOppgavene;

        int sisteOppgave = 1;
        while(gOppgavene[sisteOppgave]){sisteOppgave++;}
        --sisteOppgave;

        if (strcmp("siste", oppgaveNavn)==0){
            oppgaveSlettData(gOppgavene[sisteOppgave]);
            gOppgavene[sisteOppgave] = NULL;
            gSisteOppgave--;
            return;
        }
        else{
            while(*oppgaver){
                if (strcmp(oppgaveNavn, (*oppgaver)->navn)==0){
                    oppgaveSlettData(*oppgaver);
                    (*oppgaver) = gOppgavene[sisteOppgave];
                    gOppgavene[sisteOppgave] = NULL;
                    gSisteOppgave--;
                    return;
                }
                oppgaver++;
            }
            printf("Fant ikke oppgaven.");
        }
    }
};

/**
 * @brief
*/
void oppgaveSlettData(struct Oppgave* oppgave){
    free(oppgave->navn);
    free(oppgave);
};