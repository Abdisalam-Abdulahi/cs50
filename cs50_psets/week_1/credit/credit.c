#include <cs50.h>
#include <stdio.h>

int checkIfValid(long n);
int get_len(long n);
void get_campany(long n);
int main(void)
{
    long n = get_long("Number: ");

    if (checkIfValid(n) % 10 == 0)
    {
        get_campany(n);
    }
    else
    {
        printf("INVALID\n");
    }
}

int checkIfValid(long n)
{
    long copy = n;
    int check = 0;
    int sum = 0;
    int len = get_len(copy);
    int i = 0;
    while (i < len)
    {
        int last = n % 10;
        if (check == 1)
        {
            if (last > 4)
            {
                int temp = last * 2;
                sum += (temp % 10);
                temp = temp / 10;
                sum += temp;
                check = 0;
            }
            else
            {
                sum += last * 2;
                check = 0;
            }
        }
        else if (check == 0)
        {
            check = 1;
        }

        n = n / 10;
        i++;
    }

    int chck = 0;
    int k = 0;
    while (k < len)
    {
        int last = copy % 10;
        if (chck == 0)
        {
            sum += last;
            chck = 1;
        }
        else if (chck == 1)
        {
            chck = 0;
        }
        copy = copy / 10;
        k++;
    }
    return sum;
}

int get_len(long n)
{

    int len = 0;
    while (n > 0)
    {
        n = n / 10;
        len++;
    }
    return len;
}

void get_campany(long n)
{
    int i = 0;
    int len = get_len(n) - 2;
    long first_2 = n;
    while (i < len)
    {
        first_2 = first_2 / 10;
        i++;
    }
    if ((first_2 == 34 || first_2 == 37) && get_len(n) == 15)
    {
        printf("AMEX\n");
    }
    else if ((first_2 == 51 || first_2 == 52 || first_2 == 53 || first_2 == 54 || first_2 == 55) &&
             get_len(n) == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (((first_2 / 10) == 4) & (get_len(n) == 13 || get_len(n) == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
