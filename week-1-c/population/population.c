#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int x;
    do
    {
        x = get_int("starting size: ");
    }
    while (x < 9);
    
    // Prompt for end size
    int y;
    do
    {
        y = get_int("ending size? ");
    }
    while (y < x);

    // Set a variable for number of years
    int z = 0;

    // Increase years until we reach the ending population
    while (x < y)
    {
        x = x + (x / 3) - (x / 4);
        z++;
    }
    printf("Years: %i\n", z);
}