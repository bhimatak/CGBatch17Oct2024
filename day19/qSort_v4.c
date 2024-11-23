#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int partition(int *, int, int);
int part(int *, int, int);
int qSort(int *, int, int);
int swap(int *, int *);
int display(int *, int);
int disp(int *, int, int);

int display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

int disp(int a[], int low, int high) {
    for (int i = low; i <= high; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

int swap(int *v1, int *v2) {
    int t = *v1;
    *v1 = *v2;
    *v2 = t;
    return 0;
}

int partition(int a[], int low, int high) {
    int i = low - 1;
    int pivot = a[high];
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

int part(int a[], int low, int high) {
    int rptr = high - 1;
    int pivot = a[high];
    int lptr = low;

    while (1) {
        // Move lptr to the right while it points to elements less than or equal to the pivot
        while (a[lptr] <= pivot && lptr < high) {
            lptr++;
        }
        // Move rptr to the left while it points to elements greater than or equal to the pivot
        while (a[rptr] >= pivot && rptr > low) {
            rptr--;
        }
        // If pointers meet or cross, break the loop
        if (lptr >= rptr) {
            break;
        }
        // Swap elements at lptr and rptr
        swap(&a[lptr], &a[rptr]);
    }
    // Swap the pivot element with the element at lptr to place the pivot correctly
    swap(&a[lptr], &a[high]);
    return lptr;
}


int qSort(int a[], int low, int high) {
    if (low < high) {
        int pi = part(a, low, high); // Use part or partition as needed
        qSort(a, low, pi - 1);
        qSort(a, pi + 1, high);
    }
    return 0;
}

int main() {
    int a[] = {70, 10, 80, 30, 90, 40, 60, 20, 50};
    int size = sizeof(a) / sizeof(a[0]);
    int low = 0, high = size - 1;

    printf("Before Sort:\n");
    display(a, size);

    qSort(a, low, high);

    printf("After Sort:\n");
    display(a, size);

    return 0;
}
