#include<stdio.h>
#include <cs50.h>

int main()
{
	int x = get_int("give me number: ");
	int y = get_int("give me number: ");
	if (x < y)
	{
		printf("x is less than y");
	}
	else if (x > y)
	{
		printf("x is greater than y");
	}
	else
	{
		printf("x is equal to y");
	}
}




