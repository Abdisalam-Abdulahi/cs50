#include<stdio.h>
#include <cs50.h>

int get_positive(void);
void meow(int n);
int main()
{
	int times = get_positive();
	meow(times);
	
}

int get_positive(void)
{
	int n;
	do
	{
		n = get_int("give me number: ");
	}	
	while(n < 1);
	
	return n;
}

void meow(int n)
{

	for (int i = n; i > 0; i--)
	{
		printf("meow\n");
	}
}
