#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hasilkanAngkaAcak(int array[], int size);
void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void simpanKeFile(const char *filename, int array[], int size);
double waktuPengurutan(void (*sortFunction)(int *, int), int array[], int size);
void copyArray(int *source, int *tujuan, int size);

int main()
{
    const int MAX_SIZE = 1000000; 
    int *numbers = (int *)malloc(MAX_SIZE * sizeof(int));
    int *numbersCopy = (int *)malloc(MAX_SIZE * sizeof(int));

    if (numbers == NULL || numbersCopy == NULL)
    {
        printf("Gagal Mengalokasikan Memori\n");
        return 1;
    }

    printf("\n");
    printf("|--------------------------------------------------------------|\n");
    printf("| %-16s | %-17s | %-21s |\n", "Jenis Algoritma", "Jumlah Bilangan", "Waktu Eksekusi (ms)");
    printf("|------------------|-------------------|-----------------------|\n");

    for (int size = 100000; size <= MAX_SIZE; size += 100000)
    {
        hasilkanAngkaAcak(numbers, size);
        char filename[256];

        // Menyimpan array acak ke file
        sprintf(filename, "angkaBelumTerurutkan_%d.txt", size);
        simpanKeFile(filename, numbers, size);

        // Bubble Sort
        copyArray(numbers, numbersCopy, size);
        double waktuUntuk_Bubble = waktuPengurutan(bubbleSort, numbersCopy, size);
        printf("| %-16s | %-17d | %-21f |\n", "Bubble Sort", size, waktuUntuk_Bubble);
        sprintf(filename, "angka_bubble_sort_%d.txt", size);
        simpanKeFile(filename, numbersCopy, size);

        // Selection Sort
        copyArray(numbers, numbersCopy, size);
        double waktuUntuk_Selection = waktuPengurutan(selectionSort, numbersCopy, size);
        printf("| %-16s | %-17d | %-21f |\n", "Selection Sort", size, waktuUntuk_Selection);
        sprintf(filename, "angka_selection_sorted_%d.txt", size);
        simpanKeFile(filename, numbersCopy, size);

        // Insertion Sort
        copyArray(numbers, numbersCopy, size);
        double waktuUntuk_Insertion = waktuPengurutan(insertionSort, numbersCopy, size);
        printf("| %-16s | %-17d | %-21f |\n", "Insertion Sort", size, waktuUntuk_Insertion);
        sprintf(filename, "angka_insertion_sorted_%d.txt", size);
        simpanKeFile(filename, numbersCopy, size);
    }

    free(numbers);
    free(numbersCopy);
    return 0;
}

void hasilkanAngkaAcak(int array[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}

void bubbleSort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {

                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size)
{
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (array[j] < array[min_idx])
                min_idx = j;

        temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void insertionSort(int array[], int size)
{
    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void simpanKeFile(const char *filename, int array[], int size)
{
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%d\n", array[i]);
    }
    fclose(file);
}

double waktuPengurutan(void (*sortFunction)(int *, int), int array[], int size)
{
    clock_t start, end;
    start = clock();
    sortFunction(array, size);
    end = clock();
    return (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;
}

void copyArray(int *source, int *tujuan, int size)
{
    for (int i = 0; i < size; i++)
    {
        tujuan[i] = source[i];
    }
}