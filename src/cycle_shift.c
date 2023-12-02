#include <stdio.h>
#define MAX_SIZE 10

void cycle_shift(int *array, int quantity, int n) {
    if (quantity > 0) {
        for (int i = 0; i < quantity; ++i) {
            int first = *array;
            // int last = *(array + (n - 1));
            for (int j = 0; j < n - 1; ++j) {
                array[j] = array[j + 1];
            }
            array[n - 1] = first;
        }
    } else {
        quantity *= -1;
        for (int i = 0; i < quantity; ++i) {
            int last = array[n - 1];
            for (int j = n - 1; j > 0; --j) {
                array[j] = array[j - 1];
            }
            array[0] = last;
        }
    }
}

int input(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        int last_char = getchar();
        if ((scanf("%d", (array + i)) == 1 && (last_char == '\n' || last_char == ' ')) == 0) {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}

int output(int *array, int n) {
    for (int i = 0; i < n; ++i) {
        if (i != n - 1) {
            printf("%d ", *(array + i));
        } else {
            printf("%d", *(array + i));
        }
    }
    return 0;
}

void run() {
    int n;
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("n/a");
        return;
    }

    int array[n];
    if (input(array, n) == 1) {
        return;
    }

    int quantity;
    int succes = scanf("%d", &quantity);
    int last_char = getchar();
    if (succes == 1 && (last_char == '\n' || last_char == ' ')) {
    } else {
        printf("n/a");
        return;
    }

    cycle_shift(array, quantity, n);
    output(array, n);
}
int main() {
    run();
    return 0;
}