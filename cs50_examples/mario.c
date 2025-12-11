#include<stdio.h>
#include <cs50.h>

int main()
{
	for (int raw = 0; raw < 3; raw++)
	{
		for (int col = 0; col < 3; col++)
		{
			printf("#");
		}
		printf("\n");
	}
}
