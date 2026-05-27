#include <cs50.h>
#include <stdio.h>
#include <string.h>

void calculate_checksum(long card_number);

int main(void)
{

    long position_counter = 0;
    long card_number = get_long("Enter the card number: \n");

    calculate_checksum(card_number);
}

// Function to calculate checksum
void calculate_checksum(long card_number)
{
    long digit = 0, position_counter = 0, sum_after_multiply = 0, sum_without_multiply = 0,
         product = 1;
    long main_card = 0, first_digit = 0;

    main_card = card_number;

    while (card_number > 0)
    {
        // Get last digit
        digit = card_number % 10;
        card_number = card_number / 10;

        // Check the position of the digit
        if ((position_counter) % 2 == 1)
        {

            product = (digit * 2);

            // If the product is > 9, get sum of individual digits
            if (product > 9)
            {
                sum_after_multiply += (product % 10) + (product / 10);
            }
            // If product is single digit, keep adding
            else
            {
                sum_after_multiply += product;
            }
        }
        else
        {
            sum_without_multiply += digit;
        }

        position_counter++;
    }

    // Check last digit of final sum
    if ((sum_after_multiply + sum_without_multiply) % 10 == 0)
    {

        // Get first 2 digits of the card number
        while (main_card >= 100)
        {
            main_card = main_card / 10;
        }

        // Get first digit of the card number
        first_digit = main_card / 10;

        if (position_counter == 15 && (main_card == 34 || main_card == 37))
        {
            printf("AMEX\n");
        }
        else if (position_counter == 16 && (main_card == 51 || main_card == 52 || main_card == 53 ||
                                            main_card == 54 || main_card == 55))
        {

            printf("MASTERCARD\n");
        }
        else if (position_counter == 16 && (first_digit == 4))
        {
            printf("VISA\n");
        }
        else if (position_counter == 13 && (first_digit == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
