#include <cs50.h>
#include <stdio.h>


int main()
{
	string name = get_string("what is your name? ");
	
	int i = 0;
	while(name[i] != '\0')
	{
		i++;
	}
	printf("%i\n", i);
}
