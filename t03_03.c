#include <stdio.h>    
#include <stdlib.h>  
#include <string.h>  
#include <float.h>   

#define MAX_INPUT_LENGTH 1024 
#define MAX_NUMBERS 256       

int main() {
    char input_buffer[MAX_INPUT_LENGTH];
    char *token;
    double numbers[MAX_NUMBERS]; 
    int count = 0;
    double highest_average = -DBL_MAX; 

    printf("Masukkan serangkaian angka, dipisahkan oleh spasi (maks %d angka):\n", MAX_NUMBERS);
    
   
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
        fprintf(stderr, "Error membaca input.\n");
        return 1; 
    }

    input_buffer[strcspn(input_buffer, "\n")] = 0;

    token = strtok(input_buffer, " ");
    while (token != NULL && count < MAX_NUMBERS) {
        char *endptr;
        numbers[count] = strtod(token, &endptr);
        
        
        if (*endptr != '\0') {
            printf("Input tidak valid: '%s' bukan angka. Pastikan hanya memasukkan angka yang dipisahkan spasi.\n", token);
            return 1; 
        }
        
        count++;
        
        token = strtok(NULL, " ");
    }

    
    if (count < 2) {
        printf("Tidak cukup angka untuk membentuk pasangan. Mohon masukkan setidaknya dua angka.\n");
        return 0; 
    }


    for (int i = 0; i < count - 1; i++) {
        double num1 = numbers[i];
        double num2 = numbers[i+1];
       
        double current_average = (num1 + num2) / 2.0; 

    
        if (current_average > highest_average) {
            highest_average = current_average;
        }
    }

    printf("Rata-rata tertinggi adalah: %.2lf\n", highest_average);

    return 0; 
}