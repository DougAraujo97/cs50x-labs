#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string

    // Initializing the point total to 0
    int points_total = 0;

    // Iterating through the input word
    for (int i = 0; i < strlen(word); i++)
    {

        // setting every character to lowercase
        char letter = tolower(word[i]);

        // Using a switch statement to assign points to specific letters
        switch (letter)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'l':
        case 'n':
        case 'o':
        case 'r':
        case 's':
        case 't':
        case 'u':

            // All these letters ar worth 1 point, which is assigned to POINTS[0]
            points_total += POINTS[0];
            break;

        case 'd':
        case 'g':
            points_total += POINTS[3];
            break;

        case 'b':
        case 'c':
        case 'm':
        case 'p':
            points_total += POINTS[1];
            break;

        case 'f':
        case 'h':
        case 'v':
        case 'w':
        case 'y':
            points_total += POINTS[5];
            break;

        case 'k':
            points_total += POINTS[10];
            break;

        case 'j':
        case 'x':
            points_total += POINTS[9];
            break;

        case 'q':
        case 'z':
            points_total += POINTS[25];
        }

        // I couldn't get ispunct to work in the switch statement so I made an if statement and assign 0 points to any punctuation
        if (ispunct(letter))
        {
            points_total += 0;
        }
    }

    return points_total;
}
