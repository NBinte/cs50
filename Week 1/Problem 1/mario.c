#include <cs50.h>
#include <stdio.h>

int get_positive_height(void);
void print_spaces(int height, int i);
void print_hashes(int height, int i);

int main(void)
{

    // Get the positive height
    int height = get_positive_height();

    // Print the pyramid of the given height
    for (int i = 0; i < height; i++)
    {

        // Print spaces
        print_spaces(height, i);

        // Print hashes
        print_hashes(height, i);

        printf("\n");
    }
}

// Function to get the positive height
int get_positive_height(void)
{
    // Ask the user the height of the pyramid
    int height;
    do
    {
        height = get_int("Enter the height of the pyramid: \n");
    }
    while (height <= 0);

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
