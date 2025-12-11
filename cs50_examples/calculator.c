#include<stdio.h>
#include <cs50.h>

int main()
{
	int dollar = 1;
	while (true)
	{
		char c = get_char("here is $%i amount of money we have now double it and give it to the next person? ", dollar);
		if (c == 'y')
		{
			dollar *= 2;
		}
		else
		{
			break;
		}
	}
}
