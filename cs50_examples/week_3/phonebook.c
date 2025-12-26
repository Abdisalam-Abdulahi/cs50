#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"David", "John", "Yulia"};
    string numbers[] = {"+1-697-495-1000", "+1-949-468-2750", "+1-697-495-1000"};

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if(strcmp(names[i], name) == 0)
        {
            printf("found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}