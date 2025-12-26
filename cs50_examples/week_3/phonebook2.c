#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} person;

int main(void)
{
    person people[3];
    
    people[0].name = "David";
    people[0].number = "+1-697-495-1000";

    people[0].name = "John";
    people[0].number = "+1-949-468-2750";

    people[0].name = "Yulia";
    people[0].number = "+1-697-495-1000";

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, nmae) == 0)
        {
            printf("found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}