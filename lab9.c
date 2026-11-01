#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void f3(char sign, int side_a);

int main(void)
{
    setlocale(LC_ALL, ".UTF-8");

    printf("--- Задание 1 ---\n\n");

    int row, col;
    for (row = 1; row <= 5; ++row)
    {
        for (col = 1; col <= row; ++col)
        {
            printf("%5d", row * 5);
        }
        printf("\n");
    }
    printf("\n");

    printf("--- Задание 2 ---\n\n");

    char repeat;
    do
    {
        long long number, temp;
        int last_digit, current_digit;
        int sum_even_except_last = 0;

        printf("Введите длинное число: ");
        scanf("%lld", &number);

        temp = number;
        if (temp < 0) {
            temp = -temp;
        }

        last_digit = temp % 10;
        temp = temp / 10;

        while (temp > 0)
        {
            current_digit = temp % 10;

            sum_even_except_last += current_digit * (1 - (current_digit % 2));

            temp = temp / 10;
        }

        printf("Сумма четных цифр (исключая последнюю цифру %d): %d\n", last_digit, sum_even_except_last);

        while (getchar() != '\n');

        printf("Продолжить? (y/n): ");
        scanf("%c", &repeat);
        printf("\n");

    } while (repeat == 'y' || repeat == 'Y');

    printf("--- Задание 3 ---\n\n");

    char sign;
    int side_a;

    printf("Введите символ для построения фигуры: ");
    while (getchar() != '\n');
    scanf("%c", &sign);

    printf("Введите размер стороны 'a': ");
    scanf("%d", &side_a);

    printf("Контур фигуры (перевернутый прямоугольный треугольник):\n\n");
    f3(sign, side_a);

    system("pause");
    return 0;
}

void f3(char sign, int side_a)
{
    int i, j;

    int line_width = side_a * 2 - 1;
    for (j = 0; j < line_width; j++)
    {
        printf("%c", sign);
    }
    printf("\n");

    for (i = 1; i < side_a - 1; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf(" ");
        }

        printf("%c", sign);

        int spaces = (side_a - i - 1) * 2 - 1;
        for (j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        printf("%c\n", sign);
    }

    for (j = 0; j < side_a - 1; j++)
    {
        printf(" ");
    }
    printf("%c\n", sign);
}
