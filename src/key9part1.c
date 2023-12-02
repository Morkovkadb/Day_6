/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define MAX_SIZE 10

void input(int *buffer, int const *length);
void print(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);
void run();
int count(int *arr, int n);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    run();
    return 0;
}

void run() {
    int n;
    scanf("%d", &n);
    if (n > MAX_SIZE || n <= 0) {
        printf("n/a");
        return;
    }
    int array[n];
    input(array, &n);
    int sum = sum_numbers(array, n);
    int counter = count(array, n);
    int arr_res[counter];
    find_numbers(array, n, sum, arr_res);
}

int count(int *arr, int n) {
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) % 2 == 0) {
            counter++;
        }
    }
    return counter;
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % 2 == 0) {
            sum += *(buffer + i);
        }
    }

    return sum;
}

void print(int *buffer, int length) {
    for (int i = 0; i < length; ++i) {
        if (i != length - 1) {
            printf("%d ", *(buffer + i));
        } else {
            printf("%d", *(buffer + i));
        }
    }
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int *temp_ptr = numbers;
    for (int i = 0; i < length; ++i) {
        if (*(buffer + i) != 0 && number % *(buffer + i) == 0) {
            *temp_ptr = *(buffer + i);
            temp_ptr++;
        }
    }
    printf("%d\n", number);
    print(numbers, count(buffer, length));
    return 0;
}

void input(int *buffer, int const *length) {
    for (int i = 0; i < *length; ++i) {
        scanf("%d", buffer + i);
    }
}
