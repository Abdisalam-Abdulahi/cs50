#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int get_score(string player, string letters, int values[]);
int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score1 = 0;
    int score2 = 0;

    // get the score
    score1 = get_score(player1, letters, values);
    score2 = get_score(player2, letters, values);
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int get_score(string player, string letters, int values[])
{
    int score = 0;
    for (int i = 0; player[i] != '\0'; i++)
    {
        player[i] = toupper(player[i]);
        for (int k = 0; letters[k] != '\0'; k++)
        {
            if (player[i] == letters[k])
            {
                score += values[k];
            }
        }
    }
    return score;
}
