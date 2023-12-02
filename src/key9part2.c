#include <stdio.h>

#define MAX_SIZE 100

void sum(int const *buff1, int len1, int const *buff2, int len2, int *result, int *result_length);
void sub(int const *buff1, int len1, int const *buff2, int len2, int *result, int *result_length);
void print(int *buffer, int length);
void all_output(int *buffer, int length);
int input(int *arr, int *len);
void my_cicle_shift(int *array, int shift_count, int n);
int second_element_less_then_first_element(int const *buff1, int const *buff2);

int main() {
    int first_array[MAX_SIZE];

    int first_length;
    int second_length;

    int result_array_length;

    if (input(first_array, &first_length)) {
        int second_array[MAX_SIZE];
        if (input(second_array, &second_length)) {
            int res[MAX_SIZE];
            my_cicle_shift(first_array, first_length - MAX_SIZE, MAX_SIZE);
            my_cicle_shift(second_array, second_length - MAX_SIZE, MAX_SIZE);
            all_output(first_array, MAX_SIZE);
            printf("\n");
            all_output(second_array, MAX_SIZE);
            printf("\n");
            sum(first_array, first_length, second_array, second_length, res, &result_array_length);
            print(res, MAX_SIZE);
            printf("\n");
            sub(first_array, first_length, second_array, second_length, res, &result_array_length);
            if (result_array_length) {
                print(res, MAX_SIZE);
            } else
                printf("n/a");
        } else
            printf("n/a");
    } else
        printf("n/a");
}

void print(int *buffer, int length) {
    int flag = 0;
    for (int i = 0; i < length; ++i) {
        if (buffer[i] != 0) flag = 1;
        if (flag) {
            if (i == length - 1)
                printf("%d", buffer[i]);
            else
                printf("%d ", buffer[i]);
        }
    }
    if (flag == 0) printf("0");
}

void all_output(int *buffer, int length) {
    for (int i = 0; i < length; ++i) {
        if (i == length - 1)
            printf("%d", *(buffer + i));
        else
            printf("%d ", *(buffer + i));
    }
}

int input(int *arr, int *len) {
    *len = 0;
    int i;
    for (i = 0; i < MAX_SIZE; ++i) {
        int num = getchar() - '0';
        int sep = getchar();
        if (num < 0 || num > 9) return 0;
        arr[i] = num;
        ++(*len);
        if (sep == '\n')
            break;
        else if (sep != ' ')
            return 0;
    }

    while (++i < MAX_SIZE) {
        arr[i] = 0;
    }
    return 1;
}

void sum(int const *buff1, int len1, int const *buff2, int len2, int *result, int *result_length) {
    int overflow = 0;
    *result_length = 0;

    for (int i = MAX_SIZE - 1; i >= 0; --i) {
        if (i < len1 || i < len2) ++(*result_length);
        int my_sum = buff1[i] + buff2[i] + overflow;
        if (my_sum >= 10) {
            overflow = 1;
            my_sum -= 10;
        } else
            overflow = 0;

        result[i] = my_sum;
    }
}

int second_element_less_then_first_element(int const *buff1, int const *buff2) {
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (buff1[i] == 0 && buff2[i] == 0) continue;
        if (buff1[i] < buff2[i])
            return 0;
        else
            return 1;
    }
    return 1;
}

void sub(int const *buff1, int len1, int const *buff2, int len2, int *result, int *result_length) {
    int debt = 0;
    *result_length = 0;

    if (len2 > len1 || !second_element_less_then_first_element(buff1, buff2)) {
        *result_length = 0;
        return;
    }

    for (int i = MAX_SIZE - 1; i >= 0; --i) {
        if (i < len1 || i < len2) ++(*result_length);
        int diff = buff1[i] - buff2[i] - debt;
        if (diff < 0) {
            diff += 10;
            debt = 1;
        } else
            debt = 0;

        result[i] = diff;
    }
}

void my_cicle_shift(int *array, int shift_count, int n) {
    int direction = (shift_count >= 0) ? 1 : 0;
    shift_count = (shift_count > 0) ? shift_count : -shift_count;
    if (direction) {
        for (int i = 0; i < shift_count; ++i) {
            int tmp = array[0];
            for (int j = 0; j < n - 1; ++j) {
                array[j] = array[j + 1];
            }
            array[n - 1] = tmp;
        }

    } else {
        for (int i = 0; i < shift_count; ++i) {
            int tmp =

                array[n - 1];
            for (int j = n - 1; j > 0; --j) {
                array[j] = array[j - 1];
            }
            array[0] = tmp;
        }
    }
}
