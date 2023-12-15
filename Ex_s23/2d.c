void kundeLagFaktura(const struct Kunde* kunde){
    printf("Navn: %s\n", kunde->navn)
    printf("Adresse: %s\n", kunde->adresse)
    printf("Tlf: %i\n", kunde->tlf)
    printf("Prisklasse: %i\n", Pris[kunde->prisNr])
    printf("Brøyter: "); broytStroSkrivNavn(gBroytereStroere[kunde->BSNr]); printf("\n");
    printf("Antall brøytinger: %i\n", kunde->antBroyt)
    printf("Antall strøinger: %i\n", kunde->antStro)
    printf("Sum: %i\n", kundeHentKostnad(kunde))
}

void lagFakturaer(){
    if(gAntallKunder){
        for(int i = 0; i<gAntallKunder; i++){
            kundeSkrivData(gAntallKunder[i]);
        }
    }
    else{
        printf("Ingen kunder registrert")
    }
}