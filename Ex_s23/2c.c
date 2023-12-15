void kundeBroytetStrodd(struct Kunde* kunde){
    char BEllerS = lesChar("Skriv B eller S")
    while(BEllerS=!'B'&&BEllerS!='S'){
        BEllerS = lesChar("Skriv B eller S")
    }
    switch (BEllerS)
    {
    case 'B';
        kunde->antBroyt++
        break;
    case 'S':
        kunde->antStro++
        break;
    }
}

void broytetStroddHosKunder(){
    int kunde = lesInt("Skriv inn kunde nr, 0 for å avbryte", 0, gAntallKunder);
    while(kunde != 0){
        kundeBroytetStrodd(gKunder[kunde-1])
        kunde = lesInt("Skriv inn kunde nr, 0 for å avbryte", 0, gAntallKunder);
    }
}