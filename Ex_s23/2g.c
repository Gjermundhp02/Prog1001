void kundeLesFraFil(FILE* inn, struct Kunde* kunde){
    char buffer[256]
    fgets(inn, 200, buffer)
    buffer[strlen(buffer)-1]='\0'
    kunde->navn= (char*) malloc(sizeof(char)*strlen(buffer))
    strcpy(kunde->navn, buffer)
    fgets(inn, 200, buffer)
    buffer[strlen(buffer)-1]='\0'
    kunde->adresse= (char*) malloc(sizeof(char)*strlen(buffer))
    strcpy(kunde->adresse, buffer)

    fscanf("%i", &kunde->tlf)
    fgetc()
    fscanf("%i %i %i", &kunde->prisNr, &kunde->BSNr, &kunde->antBroyt, &kunde->antStro)
}

void lesFraFil(){
    FilE* fil = fopen("KUNDER.DTA")
    if(fil){
        fscanf("%i", &gAntallKunder)
        for(int i = 0; i<gAntallKunder; i++){
            gKunder[i] = (struct Kunde*) malloc(sizeof(Kunde))
            kundeLesFraFil(gKunder[i])
        }
    }
    else{
        melding
    }
}