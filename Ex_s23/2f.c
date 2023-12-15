void broyterStroerMedMestInntjening(){
    int broyterHoyest = 0;
    int broyterSum = 0;
    int sammeSum = 0;
    for(int i=0; i<gAntallBroytStro; i++){
        int sum = broyterSum(i)
        if(sum>broyterSum){
            broyterHoyest = i;
            broyterSum = sum;
        }
        else if (sum=broyterHoyest){
            sammeSum++;
        }
    }
    printf("%s har høyest utestående beløp\n", broytStroSkrivNavn(broyterHoyest))
    printf("Utestående beløp: %i\n", broyterSum)
    if(sammeSum)printf("Det var %i som hadde samme beløp\n", sammeSum)
}

int broyterSum(const int BSNr){
    int sum = 0;
    for(int i = 0; i<gAntallKunder; i++){
        if(gKunder[i]->BSNr==BSNr){
            sum += kundeHentKostnad(gKunder[i])
        }
    }
}