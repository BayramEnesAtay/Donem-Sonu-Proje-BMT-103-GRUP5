//Abdülselam İsmail 23181616010
//Bu test amaçlı kaba-taslak bir fonksiyon

#include <stdio.h>
#include <stdlib.h>
void gecmis();

int main() {
    char *islem[10];
    scanf("%s", &islem);
    gecmis(islem);
    return 0;
}

void gecmis(char *islem[20]) {
    FILE *gecmis;
    gecmis = fopen("Donem-Sonu-Proje-BMT-103-GRUP5//Bankacılık-Sistemi//gecmis.txt","w");
    fprintf(gecmis, "\n%s", islem);
    fclose(gecmis);

}
