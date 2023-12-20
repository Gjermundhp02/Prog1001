void tingLesData(struct Ting* ting){
    ting->navn = lagoglestekst("Navn")
    ting->antall = lesInt("antall", 0, 1000)
    ting->pris = lesInt("pris", 0, 10000)
    ting->enhet = enumFraChar(leschar("enhet"))
    gAntallTing++
}

void nyTing(){
    if(gAntallTing!=MAXTING){
        printf("Ting nr %i\n", gAntallTing+1)
        gTing[gAntallTing]= malloc(sizeof(struct Ting*))
        tingLesData(gTing[gAntallTing])
    }
    else melding
}