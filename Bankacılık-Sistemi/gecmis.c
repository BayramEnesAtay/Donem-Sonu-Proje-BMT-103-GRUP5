//Abdülselam İsmail 23181616010
//Bu test amaçlı kaba-taslak bir fonksiyon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gecmis();

int main() {
    char *islem[10];
    scanf("%s", &islem);
    gecmis(islem);
    return 0;
}

void gecmis(char *islem[20]) {
    time_t zaman = time(NULL);
    char *string_zaman = ctime(&zaman);
    FILE *gecmis;
    gecmis = fopen("C:\\Users\\rist0\\CLionProjects\\ders\\proje\\logs\\gecmis.txt","w");
    fprintf(gecmis, "\n%s: %s", islem, string_zaman);
    fclose(gecmis);

}
