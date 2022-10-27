#include <cs50.h>
#include <stdio.h>

int main()
{
    // Записуємо змінну n, яка буде нашою карткою
    long n;
    do
    {
        n = get_long("Card number: ");
    }
    while (n < 0);

    // Рахуємо довжину картки
    int i = 0;
    long cc = n;
    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }
    // Перевіряємо чи довжина правдива
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    // Обраховуємо checksum
    int sum1 = 0, sum2 = 0, total = 0;
    long x = n;
    int firstdigit, seconddigit, d1, d2;

    do
    {
        //Видаляємо останню цифру і додаємо до суми
        firstdigit = x % 10;
        x = x / 10;
        // Видаляємо другу цифру
        sum1 = sum1 + firstdigit;
        seconddigit = x % 10;
        // Подвоюєм другу останню цифру та додаємо цифри до суми2
        x = x / 10;
        seconddigit = seconddigit * 2;
        d1 = seconddigit % 10;
        d2 = seconddigit / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;

    // Перевіряємо алгоритм Luhn`s
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Отримуємо початакові цифри
    long start = n;
    do
    {
        start = start / 10;

    }
    while (start > 100);

    // Перевіряжмо цифри на тип картки
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
