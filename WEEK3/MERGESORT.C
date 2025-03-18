#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int b[n1], c[n2];
    
    for (int i = 0; i < n1; i++)
        b[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        c[j] = arr[mid + 1 + j];
    
    mergeSort(b, 0, n1 - 1);
    mergeSort(c, 0, n2 - 1);
    
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (b[i] <= c[j]) {
            arr[k] = b[i];
            i++;
        } else {
            arr[k] = c[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = b[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = c[j];
        j++;
        k++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    printf("Choose an option:\n");
    printf("1. Small length (User input)\n");
    printf("2. Big length (Random numbers)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int arr[n];

        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        printf("Sorted array:\n");
        printArray(arr, n);
        printf("Time taken: %f Milli-seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

    } else if (choice == 2) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int *arr = (int *)malloc(n * sizeof(int));  

        srand(time(0)); 
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;  
        }

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        printf("Sorting completed.\n");
        printf("Time taken: %f Milli-seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

        free(arr);  

    } else if (choice == 3) {
        printf("Exiting...\n");
        return 0;
    } else {
        printf("Invalid choice! Exiting...\n");
    }

    return 0;
}

