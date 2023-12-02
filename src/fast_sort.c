#include <stdio.h>
#define ARRAY_SIZE 10

void swap(int *a, int *b) {
    int temp = *(a);
    *(a) = *(b);
    *(b) = temp;
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
void quick_sort(int *arr, int *begin, int *end) {
    int left_pointer = *begin;
    int right_pointer = *end;
    int pivot = (*begin + *end) / 2;

    while (left_pointer <= right_pointer) {
        while (*(arr + left_pointer) < *(arr + pivot)) {
            left_pointer++;
        }

        while (*(arr + right_pointer) > *(arr + pivot)) {
            right_pointer--;
        }

        if (left_pointer <= right_pointer) {
            int temp = *(arr + left_pointer);
            *(arr + left_pointer) = *(arr + right_pointer);
            *(arr + right_pointer) = temp;
            left_pointer++;
            right_pointer--;
        }
    }
    if (*begin < right_pointer) {
        quick_sort(arr, begin, &right_pointer);
    }
    if (left_pointer < *end) {
        quick_sort(arr, &left_pointer, end);
    }
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l<n &&*(arr + l)> * (arr + largest)) {
        largest = l;
    }

    if (r<n &&*(arr + r)> * (arr + largest)) {
        largest = r;
    }

    if (largest != i) {
        swap((arr + i), (arr + largest));
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    for (int j = n / 2 - 1; j >= 0; --j) {
        heapify(arr, n, j);
    }

    for (int j = n - 1; j >= 0; --j) {
        swap(arr, (arr + j));

        heapify(arr, j, 0);
    }
}

void input() {
    int const size = 10;
    int arr_1[10];
    int arr_2[10];
    int begin_q_s = 0;
    int end_q_s = 9;
    for (int i = 0; i < size; ++i) {
        int arr_var = 0;
        int sucs = scanf("%d", &arr_var);
        int last_char = getchar();
        if (sucs == 1 && (last_char == '\n' || last_char == ' ')) {
            *(arr_1 + i) = arr_var;
            *(arr_2 + i) = arr_var;
        } else {
            printf("n/a");
            return;
        }
    }

    quick_sort(arr_1, &begin_q_s, &end_q_s);
    heap_sort(arr_2, size);
    output(arr_1, &size);
    printf("\n");
    output(arr_2, &size);
}

int main() {
    input();
    return 0;
}