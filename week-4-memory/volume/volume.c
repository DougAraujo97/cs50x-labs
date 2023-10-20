// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    // creating an array to hold the header file's data
    uint8_t header_buffer[HEADER_SIZE];

    // reading the input file into the array
    fread(header_buffer, sizeof(uint8_t), HEADER_SIZE, input);

    // writing the header data from the array into the output file
    fwrite(header_buffer, sizeof(uint8_t), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file

    // creating a buffer capable of holding the 16-bit integers
    int16_t audio_buffer;

    // reading the file will return "true" until the file is done
    while (fread(&audio_buffer, sizeof(int16_t), 1, input))
    {
        // multiply the data by the factor to change volume
        audio_buffer *= factor;

        // write updated data to the output file
        fwrite(&audio_buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
