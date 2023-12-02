#include <stdio.h>

void sort(int *arr, int const *n) {
    for (int j = 0; j < *n; ++j) {
        for (int i = 0; i < *n - 1; ++i) {
            if ((*(arr + i)) > (*(arr + i + 1))) {
                *(arr + i) = *(arr + i) ^ *(arr + i + 1);
                *(arr + i + 1) = *(arr + i) ^ *(arr + i + 1);
                *(arr + i) = *(arr + i) ^ *(arr + i + 1);
            }
        }
    }
}

void output(int *arr, int const *n) {
    for (int i = 0; i < *n; ++i) {
        if (i != *n - 1) {
            printf("%d ", *(arr + i));
        } else {
            printf("%d", *(arr + i));
        }
    }
}

int input() {
    int const n = 10;
    int array[10];
    for (int i = 0; i < n; ++i) {
        int succes_read_var = scanf("%d", (array + i));
        if (succes_read_var != 1 && getchar() != '\n') {
            printf("n/a");
            return 1;
        }
    }

    sort(array, &n);
    output(array, &n);
    return 0;
}

int main() {
    input();
    return 0;
}