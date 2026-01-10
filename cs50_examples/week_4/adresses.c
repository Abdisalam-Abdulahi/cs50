#include <stdio.h>

int main(void)
{
    char *s = "hi!";
    //printf("%s\n", s);
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}