#include <cs50.h>
#include <stdio.h>

int main()
{
	const int n = 3;
	int score[n];
	for (int i = 0; i < n; i++)
	{
		score[i] = get_int("what is the score ");
	}
	printf("average is %.2f\n", (score[0] + score[1] + score[2]) / (float) n);
	printf("%c\n", 0);
}
