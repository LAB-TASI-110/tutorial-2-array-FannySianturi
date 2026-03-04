#include <stdio.h> 
#include <limits.h> 

void findMinMax(int n, int *min_val, int *max_val) {
    int current_num;
   
    *min_val = INT_MAX; 
    *max_val = INT_MIN; 

    printf("Masukkan %d bilangan bulat (misal: 8, -3, 16, 77, -3, 10, 33, -7):\n", n);

    for (int i = 0; i < n; i++) {
        printf("Bilangan ke-%d: ", i + 1);
        
        if (scanf("%d", &current_num) != 1) {
            printf("Input tidak valid. Harap masukkan bilangan bulat. Coba lagi untuk bilangan ke-%d.\n", i + 1);
            
            while (getchar() != '\n');
            i--;
            continue; 

        if (current_num < *min_val) {
            *min_val = current_num;
        }

       
        if (current_num > *max_val) {
            *max_val = current_num;
        }
    }
}


int main() {
    int n; 
    int min_result, max_result; 

    printf("Masukkan jumlah bilangan bulat (n): ");
    
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input tidak valid. N harus bilangan bulat positif.\n");
        while (getchar() != '\n');
        return 1; 
    }

    findMinMax(n, &min_result, &max_result);

    printf("\n--- Hasil ---\n");
    printf("Nilai terkecil: %d\n", min_result);
    printf("Nilai terbesar: %d\n", max_result);

    return 0; 
}