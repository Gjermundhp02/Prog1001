void kundeLesData(struct Kunde* kunde){
    kunde->navn = lagOgLesTekst("Skriv inn et navn")
    kunde->adresse = lagOgLesTekst("Skriv inn en adresse")
    kunde->tlf = lesInt("Skriv inn et tlf nr", 0, 99999999)
    kunde->prisNr = lesInt("Hvilken prisgruppe", 1, 3)-1
    kunde->BSNr = lesInt("Hvilken brøyter/strøer", 1, gAntallBroytStro)-1
    kunde->antBroyt = 0
    kunde->antStro = 0
}

void nyKunde(){
    if(gAntallKunder<MAXKUNDER){
        printf("Kunde nr: %i", gAntallKunder+1)
        gKunder[gAntallKunder] = malloc(sizeof(Kunde))
        kundeLesdata(gKunder[gAntallKunder])
        gAntallKunder++
    }
    else{
        printf("Fult")
    }
}