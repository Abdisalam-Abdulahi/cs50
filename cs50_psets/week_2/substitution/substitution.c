#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_char(string key);
void cipher(string plainText, string key);
int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!only_char(argv[1]))
    {
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    string plainText = get_string("plaintext:  ");
    printf("ciphertext: ");
    cipher(plainText, argv[1]);
}

bool only_char(string key)
{
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("keys must alphapetical chracters\n");
            return false;
        }

        for (int k = i + 1; k < len; k++)
        {
            key[k] = toupper(key[k]);
            if (key[i] == key[k])
            {
                printf("chracters must contain only one\n");
                return false;
            }
        }
    }
    return true;
}

void cipher(string plainText, string key)
{
    int index;
    for (int i = 0; plainText[i] != '\0'; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (islower(plainText[i]))
            {
                index = plainText[i] - 'a';
                printf("%c", tolower(key[index]));
            }
            else
            {
                index = plainText[i] - 'A';
                printf("%c", key[index]);
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}