#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);
int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        int nargv = atoi(argv[1]);
        string plainText = get_string("plaintext:  ");
        printf("ciphertext: ");
        int i = 0;
        while (plainText[i] != '\0')
        {
            printf("%c", rotate(plainText[i], nargv));
            i++;
        }
        printf("\n");
        // printf("%c\n", rotate(plainText[0], nargv));
        return 0;
    }
}
bool only_digits(string key)
{
    int len = strlen(key);
    int i = 0;
    while (i < len)
    {
        /*
        if (i == 0 && strlen(key) > 2 && !isdigit(key[i + 1]))
        {
            return false;
        }
            */
        if (isdigit(key[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
        i++;
    }
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (islower(c))
        {
            int indx = c - 'a';
            int result = (indx + n) % 26;
            return result + 'a';
        }
        else
        {
            int indx = c - 'A';
            int result = (indx + n) % 26;
            return result + 'A';
        }
    }
    else
    {
        return c;
    }
}