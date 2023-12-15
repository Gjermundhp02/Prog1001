void kundeEndreBroyterStroer(struct Kunde* kunde){
    printf("Brøyter nr: %i", kunde->BSNr+1)
    printf("Brøyters navn:"); broytStroSkrivNavn(kunde); printf("\n")
    int broyter = lesInt("Skriv inn ny broyter nr, 0 for å ikke endre", 0, gAntallBroytStro)
    if(broyter){
        print("Broyter ikke endret")
    }
    else{
        kunde->BSNr = broyter-1
    }
}

void endreBroyterStroer(){
    if(gAntallKunder){
        int kundeNr = lesInt("Hvilken kunde (nr)", 1, gAntallKunder)-1
        if(kundeHentKostnad(gKunder[kundeNr])){
            printf("Kunden har hatt brøytinger/strøinger")
        }
        else{
            kundeEndreBroyterStroer(gKunder[kundeNr])
        }
    }
    else{
        printf("Ingen kunder registrert")
    }
}