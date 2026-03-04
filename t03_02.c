#include <stdio.h> 
#include <stdlib.h> 

double get_positive_double_input(const char* prompt) {
    double value;
    int input_status;
    char buffer[100]; 

    do {
        printf("%s", prompt);
        input_status = scanf("%lf", &value);

        if (input_status == 1) {
            if (value > 0) {
                while (getchar() != '\n');
                return value;
            } else {
                printf("Kesalahan: Nilai harus lebih besar dari nol. Silakan coba lagi.\n");
            }
        } else {
            printf("Kesalahan: Input tidak valid. Masukkan angka.\n");
            scanf("%s", buffer);
            while (getchar() != '\n'); 
        }
    } while (1); 
}

int main() {
    double alas;
    double tinggi;
    double luas;

    printf("--- Program Penghitung Luas Segitiga (Bahasa C) ---\n");


    alas = get_positive_double_input("Masukkan panjang alas segitiga (nilai positif): ");

    tinggi = get_positive_double_input("Masukkan tinggi segitiga (nilai positif): ");

    luas = (alas * tinggi) / 2.0; 
    
    printf("\n-------------------------------------\n");
    printf("Alas Segitiga  : %.2f\n", alas);
    printf("Tinggi Segitiga: %.2f\n", tinggi);
    printf("Luas Segitiga  : %.2f\n", luas);
    printf("-------------------------------------\n");

    return 0; 
}