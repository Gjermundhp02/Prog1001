/**
 *   Programeksempel nr 27 - Større programeksempel.
 *
 *   Programmet holder oversikt over et arrangement med ulke oppgaver.
 *   Man kan legge til og fjerne oppgaver, legge personer til i oppgaver og
 *   sette et maks antall per oppgave.
 *
 *   @file     Oblig 4.c
 *   @author   Gjermund H. Pedersen
 */
#include <stdbool.h> // bool
#include "LesData.h" // lesInt, lesChar, lagOgLesText

#define MAXPERS 6  ///< Maks personer som kan være per oppgave
#define MAXOPPG 20 ///< Maks oppgaver man kan legge inn

// Datamedlemene til en oppgave
struct Oppgave {
char* navn;        // Navnet på oppgaven
int antallTotalt,  // Hvor mange som totalt kan være på oppgaven
    antallNaa;     // Hvor mange som er på oppgaven nå
int hvem[MAXPERS]; // IDen til de som er på oppgaven
};

struct Oppgave* gOppgavene[MAXOPPG]; ///< Arrayet som holder pekerne til oppgavene
int gSisteOppgave = 0;               ///< Hvor mange oppgaver som er lagt til

void nyOppgave();
void oppgaveLesData(struct Oppgave* oppgave);
void skrivOppgaver();
void oppgaveSkrivData(const struct Oppgave* oppgave);
void ledigeOppgaver();
bool oppgaveLedigPlass(const struct Oppgave* oppgave);
void personerTilknyttesOppgave();
void oppgaveTilknyttPersoner(struct Oppgave* oppgave);
void fjernOppgave();
void oppgaveSlettData(struct Oppgave* oppgave);
void skrivMeny(); 
void lesData();
void skrivData();


/**
 *  Hovedprogrammet:
 * 
 *  Leser en komando og kjører den korresponderende funksjonen 
 *  @see nyOppgave
 *  @see skrivOppgaver
 *  @see ledigeOppgaver
 *  @see personerTilknyttetOppgave
 *  @see fjernOppgavene
 *  @see skrivMeny
 */
int main ()  {
    char kommando;

    lesData();

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q')  {
        switch (kommando)  {
          case 'N': nyOppgave();                 break;
          case 'S': skrivOppgaver();             break;
          case 'L': ledigeOppgaver();            break;  
          case 'P': personerTilknyttesOppgave(); break;  
          case 'F': fjernOppgave();              break;
          default:  skrivMeny();  break;    
        }
        kommando = lesChar("\nKommando");
    }

    skrivData();

    printf("\n");
    return 0;
}

/**
 * @brief Lager en ny oppgave
 * 
 * @see oppgaveLesData
*/
void nyOppgave(){
    // Legger ikke til oppgave hvis det ikke er plass
    if (gSisteOppgave>MAXOPPG){ 
        printf("Det er ikke plass til flere oppgaver");
    }
    else{
        gOppgavene[gSisteOppgave] = (struct Oppgave*) malloc(sizeof(
            struct Oppgave)); // Akkokerer minne til oppgaven
        oppgaveLesData(gOppgavene[gSisteOppgave]);
        gSisteOppgave++; // Oppdaterer hvor mange oppgaver som er lagt til
    }
};

/**
 * @brief Leser data inn i en oppgave
 * 
 * @param oppgave - oppgaven som skal fylles ut
*/
void oppgaveLesData(struct Oppgave* oppgave){
    oppgave->navn = lagOgLesText("Skriv inn et navn");
    oppgave->antallTotalt = lesInt("Hvor mange kan jobbe på denne oppgaven", 
        0, MAXPERS);
    oppgave->antallNaa = 0;
};

/**
 * @brief Skriver ut alle oppgavene og infoen
 * 
 * @see oppgaveSkrivData
*/
void skrivOppgaver(){
    if (!gOppgavene[0]){
        printf("Det finnes ingen oppgaver.\n");
    }
    else{
        for (int i = 0; i < gSisteOppgave; i++){
            oppgaveSkrivData(gOppgavene[i]);
        }
    }
};

/**
 * @brief Skriver ut dataen i en oppgave
 * 
 * @param oppgave - oppgaven som skal bli skrevet ut.
*/
void oppgaveSkrivData(const struct Oppgave* oppgave){
    printf("\tNavn: %s\n", oppgave->navn);
    printf("\tMax antall på oppgvaen: %i\n", oppgave->antallTotalt);
    printf("\tAntall på oppgvaen: %i\n", oppgave->antallNaa);
    printf("\tPerson id-er på oppgven: ");
    // Looper gjennom alle oppgavene som er satt.
    // Sjekker om større enn 0 fordi compileren på windows satte variablene 
    // negative i stedet for 0.
    for (int i = 0; oppgave->hvem[i]>0; i++){ 
        
        printf("%i, ", oppgave->hvem[i]);
    }
    printf("\n");
};

/**
 * @brief Går gjennom alle oppgavene og skriver ut de som ikke er fulle
 * 
 * @see oppgaveLedigPlass
*/
void ledigeOppgaver(){
    if (!gOppgavene[0]){
        printf("Det finnes ingen oppgaver.\n");
    }
    else{
        for (int i = 0; i < gSisteOppgave; i++){
            if (oppgaveLedigPlass(gOppgavene[i])){
                oppgaveSkrivData(gOppgavene[i]);
            }  
        }
    }
};

/**
 * @brief Finner ut om en oppgave har ledig plass
 * 
 * @return Om det er ledig plass i oppgaven
*/
bool oppgaveLedigPlass(const struct Oppgave* oppgave){
    return oppgave->antallNaa < oppgave->antallTotalt;
};

/**
 * @brief Legger til en eller flere personer til en oppgave
 * 
 * @see oppgaveTilknyttPersoner
*/
void personerTilknyttesOppgave(){
    if (!gOppgavene[0]){
        printf("Det finnes ingen oppgaver.\n");
    }
    else{
        int oppgaveId = lesInt("Hvilken oppgeve", 0, MAXOPPG+1);
        if(oppgaveId==0){ // Sjekker om brukeren angrer
            printf("Angrer. Ingenting endret\n");
            return;
        }
        else{
            oppgaveTilknyttPersoner(gOppgavene[oppgaveId-1]);
        }
                                   
    }
};

/**
 * @brief Legger til en person i en spesifisert oppgave
 * 
 * @see oppgaveSkrivData
 * @see oppgaveLedigPlass
*/
void oppgaveTilknyttPersoner(struct Oppgave* oppgave){
    oppgaveSkrivData(oppgave);
    if(!oppgaveLedigPlass(oppgave)){
        printf("Oppgaven er full.");
        return;
    }
    else{
        // Spørr brukeren hvor mange som skal legges til.
        // Må være mellom oppgavens maksantall og nåværende
        int antallNye = lesInt("Hvor mange nye skal legges til", 0, 
                               oppgave->antallTotalt - oppgave->antallNaa);
        for (int i = 0; i < antallNye; i++){
            // Legger inn IDen og øker med 1 etter
            oppgave->hvem[oppgave->antallNaa++] = lesInt(
                "Id på personen som legges til", 0, 1000);
        }
        oppgaveSkrivData(oppgave);
    }
};

/**
 * @brief Fjerner den oppgaven brukeren spesifiserer
 * 
 * @see oppgaveSlettData
*/
void fjernOppgave(){
    if (!gOppgavene[0]){
        printf("Det finnes ingen oppgaver.\n");
        return;
    }
    else{
        int oppgaveId = lesInt("Hvilken oppgave vil du fjerne", 0, MAXOPPG+1);
        if(oppgaveId==0){
            printf("Ingenting ble fjernet.\n");
            return;
        }
        else{
            char bekreftelse = lesChar(
                "Er du sikker på at du vil fjerne den siste oppgaven: (J/N)");
            if (bekreftelse=='J'){
                if(oppgaveId==gSisteOppgave){
                    printf("Den siste oppgaven ble fjernert.\n");
                    oppgaveSlettData(gOppgavene[gSisteOppgave-1]);
                    free(gOppgavene[gSisteOppgave-1]);
                    gOppgavene[gSisteOppgave-1] = NULL;
                    gSisteOppgave--;
                }
                else{
                    printf("Oppgaven ble fjernet\n");
                    oppgaveSlettData(gOppgavene[oppgaveId-1]);
                    free(gOppgavene[oppgaveId-1]);
                    gOppgavene[oppgaveId-1] = gOppgavene[gSisteOppgave-1];
                    gOppgavene[gSisteOppgave-1] = NULL;
                    gSisteOppgave--;
                }
            }
            else{
                printf("Avbryter! Ingenting ble endret.\n");
            }
        }
    }
};

/**
 * @brief Frigjør allokert minne til den spesifiserte oppgaven
*/
void oppgaveSlettData(struct Oppgave* oppgave){
    free(oppgave->navn);
};

/**
 * @brief Skriver ut en meny som forklarer komandoene
 */
void skrivMeny(){
    printf("Kommandoer:\n");
    printf("\tN: Legg til en ny oppgave i arrangent oversikten.\n");
    printf("\tS: Skriv ut alle arangementene og dataene deres.\n");
    printf("\tL: Skriv ut arrangementer med ledig plass\n");
    printf("\tP: Legg til en eller flere personer på et arrengment.\n");
    printf("\t   - Skriv 0 for å kanselere, og ingenting blir endret.\n");
    printf("\tF: Fjern et arrengement.\n");
    printf("\t   - Skriv 0 for å kanselere, og ingenting blir endret.\n");
    printf("\t   - Skriv \"siste\" for å fjerne den siste oppgaven.\n");
    printf("\tQ: Avslutt programmet.\n");
};

void lesData(){
    FILE* fil = fopen("oppgaver.dat", "r");

    if (fil){
        while(!feof(fil)){
            char buffer[200];
            gOppgavene[gSisteOppgave] = malloc(sizeof(struct Oppgave*));

            
            fgets(buffer, 200, fil);
            buffer[strlen(buffer)-1] = '\0';
            gOppgavene[gSisteOppgave]->navn = (char *) malloc(sizeof(char)*(strlen(buffer)+1));
            strcpy(gOppgavene[gSisteOppgave]->navn, buffer);

            fscanf(fil, "%i %i", &gOppgavene[gSisteOppgave]->antallTotalt, &gOppgavene[gSisteOppgave]->antallNaa);
            fgetc(fil);
            
            for (int i = 0; i < gOppgavene[gSisteOppgave]->antallNaa+1; i++){
                fscanf(fil, "%i", &gOppgavene[gSisteOppgave]->hvem[i]);
            }

            gSisteOppgave++;
        }
    }
    else{
        printf("Fant ikke filen");
    }
    
};

void skrivData(){
    FILE* fil = fopen("oppgaver2.dat", "w");

    if(fil){
        for (int i = 0; i < gSisteOppgave; i++){
            fprintf(fil, "%s\n%i %i\n", gOppgavene[i]->navn, 
                gOppgavene[i]->antallTotalt, gOppgavene[i]->antallNaa);
            for (int j = 0; j < gOppgavene[i]->antallNaa; j++){
                fprintf(fil, "%i ", gOppgavene[i]->hvem[j]);
            }
            fprintf(fil, "\n");
        }
        
    }
    else{
        printf("Fant ikke filen");
    }
};