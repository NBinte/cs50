#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int get_number_of_coins(int cents, int value);

#define QUARTER_VALUE 25
#define DIME_VALUE 10
#define NICKEL_VALUE 5
#define PENNY_VALUE 1

int main(void)
{

    // Get the cents
    int cents = get_cents();

    // Calculate how many quarters needed
    int quarters = get_number_of_coins(cents, QUARTER_VALUE);

    // Get cents after calculating quarters
    cents = cents - (quarters * QUARTER_VALUE);

    // Calculate how many dimes needed
    int dimes = get_number_of_coins(cents, DIME_VALUE);

    // Get cents after calculating dimes
    cents = cents - (dimes * DIME_VALUE);

    // Calculate how many nickels needed
    int nickels = get_number_of_coins(cents, NICKEL_VALUE);

    // Get cents after calculating nickels
    cents = cents - (nickels * NICKEL_VALUE);

    // Calculate how many pennies needed
    int pennies = get_number_of_coins(cents, PENNY_VALUE);

    // Get cents after calculating pennies
    cents = cents - (pennies * PENNY_VALUE);

    printf("Total coins: %i\n", quarters + dimes + nickels + pennies);
}

// Function to get the cents
int get_cents(void)
{
    // Ask the user for change owed
    int cents;
    do
    {
        cents = get_int("Enter the total cents: \n");
    }
    while (cents < 0);

    return cents;
}

// Function to get number of coins
int get_number_of_coins(int cents, int coin_value)
{
    int number_of_coins = 0;

    while (cents >= coin_value)
    {
        number_of_coins++;
        cents = cents - coin_value;
    }

    return number_of_coins;
}
