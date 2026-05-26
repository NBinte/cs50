#include <cs50.h>
#include <stdio.h>

#define GAP_WIDTH 2

int get_positive_height(void);
void print_spaces(int height, int i);
void print_hashes(int height, int i);
void print_gaps(int height);

int main(void)
{

    // Get the positive and inclusive height
    int height = get_positive_height();

    // Print the pyramid of the given height
    for (int i = 0; i < height; i++)
    {

        // Print spaces
        print_spaces(height, i);

        // Print hashes
        print_hashes(height, i);

        // Print gaps
        print_gaps(height);

        // Print hashes after gap
        print_hashes(height, i);

        printf("\n");
    }
}

// Function to get the positive and inclusive height
int get_positive_height(void)
{
    // Ask the user the height of the pyramid
    int height;
    do
    {
        height = get_int("Enter the height of the pyramid: \n");
    }
    while (height < 1 || height > 8);

    return height;
}

// Function to Print spaces
void print_spaces(int height, int i)
{
    for (int j = 0; j < height - i - 1; j++)
    {
        printf(" ");
    }
}

// Function to Print hashes
void print_hashes(int height, int i)
{
    for (int k = height; k >= height - i; k--)
    {
        printf("#");
    }
}

// Function to Print gaps
void print_gaps(int height)
{
    for (int k = 0; k < GAP_WIDTH; k++)
    {
        printf(" ");
    }
}
