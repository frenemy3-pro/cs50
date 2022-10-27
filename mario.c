#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // n - висота піраміди
    int n;
    do
    {
        // Запитуємо у користувача висоту піраміди
        n = get_int("Height: ");
    } while (n < 1 || n > 8);

    // i - рядок; виведення лівої піраміди
    for (int i = 0; i < n; i++)
    {
        // цикл для пробілів, j - пробіли
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // цикл для колонок, k - стовпець
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("  ");
        // виведення правої піраміди,
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
