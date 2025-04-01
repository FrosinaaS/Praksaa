#include <stdio.h>
#include <stdlib.h>

int f_checksum(char *embg){
    int suma= 0;
    for(int i=0, j=7; i<6; i++, j--){
        suma= suma + j*(embg[i]-'0');
        suma= suma + j*(embg[i+6]-'0');
    }
    int m= 11 - (suma%11);

    if(m==10 || m==11)
     return 0;
     return m;
}//m = 11 − (( 7×(a + g) + 6×(b + h) + 5×(c + i) + 4×(d + j) + 3×(e + k) + 2×(f + l) ) mod 11) kade shto  DDMMYYYRRBBBK = abcdefghijklm

char *compose_embg(char *date_of_birth, char *region_code, char *sex, char *sequence){
    static char embg[13];

    snprintf(embg, 13, "%s%s%s%s", date_of_birth, region_code, sex, sequence);
    int checksum= f_checksum(embg);
    embg[12]= checksum+'0';
    embg[13]= '\0';

    return embg;
}

int validate_embg(char *embg){
    int DD= (embg[0]-'0')*10 + (embg[1]-'0');
    int MM= (embg[2]-'0')*10 + (embg[3]-'0');
    int RR= (embg[7]-'0')*10 + (embg[8]-'0');

    return (DD<=0 || DD>31 || MM<=0 || MM>12 || RR<0 || RR>96);
}

int main(){
    char date_of_birth[8], region_code[3], sex[2], sequence[4];

    printf("Внеси датум на раѓање (DDMMYYY): ");
    scanf("%7s", date_of_birth);
    printf("Внеси регионален код (RR): ");
    scanf("%2s", region_code);
    printf("Внеси пол и реден број (BBB): ");
    scanf("%1s%2s", sex, sequence);

    char *embg = compose_embg(date_of_birth, region_code, sex, sequence);
    printf("EMBG: %s\n", embg);

    if(validate_embg(embg)==0)
        printf("EMBG е валиден.\n");
    else
        printf("EMBG не е валиден.\n");

    return 0;
}
