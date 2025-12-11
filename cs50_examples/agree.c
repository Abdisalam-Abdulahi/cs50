#include <cs50.h>
#include <stdio.h>

int main()
{
	char c = get_char("Do you agree ");
	if (c == 'n' || c == 'N')
	{
		printf("not agreed\n");
	}
	else if (c == 'y' || c == 'Y')
	{
		printf("agreed\n");
	}
}
