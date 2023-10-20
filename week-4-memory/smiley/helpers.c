#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // Iterate through the rows
    for (int row = 0; row < height; row++)
    {

        // Iterate through the columns
        for (int col = 0; col < width; col++)
        {

            // Check for a black pixel
            if (image[row][col].rgbtRed == 0x00 && image[row][col].rgbtGreen == 0x00 && image[row][col].rgbtBlue == 0x00)
            {

                // Make the black pixel red
                image[row][col].rgbtRed = 0xFF;
            }
        }
    }
}
