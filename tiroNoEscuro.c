#include <stdio.h>
#include "util.h"

// Alunos
// João Pedro Boaretto - 16876293
// Lorena Borges - 16883652

static inline void swap_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void shellsort_knuth(int *arr, int N) {
    if (N < 2) {
        return;
    }

    // Gap usando a sequência de Knuth
    int gap = 1;
    while (gap < N / 3) {
        gap = 3 * gap + 1;
    }

    for (gap; gap > 0; gap = (gap - 1) / 3) {
        for (int i = gap; i < N; ++i) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

int partition_hoare(int *arr, int low, int high) {
    int pivot = arr[low + (high - low) / 2];

    int i = low - 1;
    int j = high + 1;
    
    while (1) {
        do {
            ++i;
        } while (arr[i] < pivot);
        do {
            --j;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        
        swap_int(&arr[i], &arr[j]);
    }
}

void quicksort_hoare_rec(int *arr, int low, int high) {
    while (low < high) {
        int pivot_index = partition_hoare(arr, low, high);

        if (pivot_index - low < high - pivot_index) {
            quicksort_hoare_rec(arr, low, pivot_index);
            low = pivot_index + 1;
        } else {
            quicksort_hoare_rec(arr, pivot_index + 1, high);
            high = pivot_index;
        }
    }
}

void quicksort_hoare(int *arr, int N) {
    if (N < 2) {
        return;
    }
    quicksort_hoare_rec(arr, 0, N - 1);
}

void insertion_sort(int *arr, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void quicksort_median3_rec(int *arr, int low, int high) {
    while (low < high) {
        // Otimização para subarrays pequenos
        if (high - low + 1 <= 16) {
            insertion_sort(arr, low, high);
            return;
        }

        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[low]) 
            swap_int(&arr[mid], &arr[low]);
        if (arr[high] < arr[low]) 
            swap_int(&arr[high], &arr[low]);
        if (arr[high] < arr[mid]) 
            swap_int(&arr[high], &arr[mid]);

        swap_int(&arr[mid], &arr[high - 1]);
        int pivot = arr[high - 1];

        int i = low;
        int j = high - 1;
        for (;;) {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);
            if (i >= j)
                break;
            swap_int(&arr[i], &arr[j]);
        }

        swap_int(&arr[i], &arr[high - 1]);
        if (i - 1 - low < high - (i + 1)) {
            quicksort_median3_rec(arr, low, i - 1);
            low = i + 1;
        } else {
            quicksort_median3_rec(arr, i + 1, high);
            high = i - 1;
        }
    }
}

void quicksort_median3(int *arr, int n) {
    if (n < 2) {
        return;
    }

    quicksort_median3_rec(arr, 0, (int)n - 1);
}

void preencherArray(int *arr, int N, char *ordem){
    if(strcmp(ordem, "sorted") == 0){
        for(int i = 0; i < N; i++){
            arr[i] = i + 1;
        }
    } else if(strcmp(ordem, "reverse") == 0){
        for(int i = 0; i < N; i++){
            arr[i] = N - i;
        }
    } else if(strcmp(ordem, "random") == 0){
        int seed = 12345;
        for(int i = 0; i < N; i++){
            arr[i] = get_random(&seed, N);
        }
    }   
}

int main() {
    init_crc32();

    int N;
    char ordem[16];
    int alg;

    scanf("%d", &N);
    scanf("%15s", ordem);
    scanf("%d", &alg);

    int *array = (int *)malloc(N * sizeof(int));
    preencherArray(array, N, ordem);

    switch (alg) {
        case 1:
            shellsort_knuth(array, N);
            break;
        case 2:
            quicksort_hoare(array, N);
            break;
        case 3:
            quicksort_median3(array, N);
            break;
        default:
            shellsort_knuth(array, N);
            break;
    }

    uint32_t saida = crc32(0, array, N * sizeof(int));
    printf("%08X", saida);

    free(array);

    return 0;
}