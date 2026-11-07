#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#define ROW 9
#define COL 9
#define N_1 5
#define SIDE_B 22
#define SIDE_C 6
int task1();
int task2();
int task3();


int main()
{
    SetConsoleOutputCP(65001);
    task1();
    task2();
    //task3();
    return 0;
}

int task1()
{
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
            printf("%5d", col * row);
        printf("\n");
    }
    return 0;
}


int task2()
{
    printf("\n");
    long long number;
    int digit, sum;
    char answer;
    do
    {
        sum = 0;
        printf("Введите число: ");
        scanf("%lld", &number);
        do
        {
            digit = number % 10;
            if (digit < 0)
                digit = -digit;
            if (digit % 2 != 0)
                sum += digit;
            number /= 10;
        } while (number != 0);
        printf("Сумма нечетных цифр = %d\n", sum);
        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');
    return 0;
}

int task3(){
char symbol;
double alpha_deg, beta_deg;
int choice;

do {
    printf("Введите символ из которого будет строиться фигура:\n");
    scanf(" %c", &symbol);

    printf("Введите угол a:\n");
    scanf("%lf", &alpha_deg);

    printf("Введите угол b:\n");
    scanf("%lf", &beta_deg);

    if (alpha_deg <= 15.0 || alpha_deg >= 89.0 || beta_deg <= 91.0 || beta_deg >= 175.0) {
        printf("Ошибка: введите угол a в диапазоне [15..89] и угол b в диапазоне [91..175].\n\n");
    }
    else {
        double alpha_rad = alpha_deg * M_PI / 180.0;
        double beta_rad = (beta_deg - 90.0) * M_PI / 180.0;

        double tan_alpha = tan(alpha_rad);
        double tan_beta = tan(beta_rad);
        int max_y = (int)((SIDE_B + SIDE_C / tan_beta) / (1.0 / tan_alpha + 1.0 / tan_beta));

        if (max_y <= SIDE_C) {
            printf("При заданных углах стороны пересекаются слишком высоко. Увеличьте угол a или b.\n\n");
        }
        else {
            printf("Построенная фигура:\n\n");

            for (int y = 0; y <= max_y; y++) {
                int x_left = (int)round(y / tan_alpha);
                int x_right;
                if (y <= SIDE_C) {
                    x_right = SIDE_B;
                }
                else {
                    x_right = (int)round(SIDE_B - (y - SIDE_C) / tan_beta);
                }

                if (x_left > x_right) {
                    break;
                }
                for (int x = 0; x <= x_right; x++) {
                    if (y == 0 || y == max_y || x == x_left || x == x_right) {
                        printf("%c", symbol);
                    }
                    else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    printf("Продолжить ? (Да - введите любое число, Нет - введите 0)\n");
    scanf("%d", &choice);

} while (choice != 0);

return 0;
}
