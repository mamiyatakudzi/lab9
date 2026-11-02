#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char f3(char sign, int side_a, int i, int j);

int main(void)
{
    setlocale(LC_ALL, ".UTF-8");

    printf("--- Задание 1 ---\n\n");

    for (int row = 1; row <= 9; ++row)
    {
        for (int col = 1; col <= 9; ++col)
        {
            printf("%4d", row * col);
        }
        printf("\n");
    }
    printf("\n");

    int row, col;
    for (row = 1; row <= 5; ++row)
    {
        {
            for (col = 1; col <= row; ++col)
            {
                printf("%5d", row * 5);
            }
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

    do
    {
        char sign;
        int side_a;

        printf("Введите символ для построения фигуры: ");
        while (getchar() != '\n');
        scanf("%c", &sign);

        do {
            printf("Введите размер стороны 'a': ");
            if (scanf("%d", &side_a) != 1 || side_a <= 0) {
                printf("Ошибка! Введите положительное число.\n");
                while (getchar() != '\n');
            }
            else {
                break;
            }
        } while (1);

        printf("Контур фигуры (перевернутый прямоугольный треугольник):\n\n");

        int line_width = side_a * 2 - 1;
        for (int i = 0; i < side_a; i++)
        {
            for (int j = 0; j < line_width; j++)
            {
                printf("%c", f3(sign, side_a, i, j));
            }
            printf("\n");
        }

        while (getchar() != '\n');

        printf("\nПовторить рисунок? (y/n): ");
        scanf("%c", &repeat);
        printf("\n");

    } while (repeat == 'y' || repeat == 'Y');

    system("pause");
    return 0;
}

char f3(char sign, int side_a, int i, int j)
{
    int line_width = side_a * 2 - 1;

    return (i == 0 || (i == side_a - 1 && j == side_a - 1) || j == i || j == (line_width - 1 - i)) ? sign : ' ';
}
