/**
 * @file march_13.c
 * @brief Banking USSD Simulator Program
 *
 * This program simulates a banking USSD service with the following features:
 * - Account Balance Checking
 * - Money Transfers
 * - Data Bundle Purchase
 * - Airtime Purchase
 * - Account Balance Top-up
 *
 * The program uses a simple command-line interface and validates all user inputs
 * to ensure proper operation.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief Clears the input buffer
 */
void clear_input_buffer(void)
{
    while (getchar() != '\n')
        ;
}

/**
 * @brief Prints a currency value with 2 decimal places
 *
 * @param currency The floating-point value to be formatted as currency
 * @details Formats and prints the given float value with exactly 2 decimal places,
 *          suitable for displaying monetary amounts
 */
void print_formatted_currency(float currency)
{
    printf("N %.2f", currency);
}

/**
 * @brief Validates and processes the entered USSD code
 *
 * @param ussd_code Pointer to store the validated USSD code
 * @details Continuously prompts user until the correct code (*69#) is entered
 */
void take_ussd_code(char *ussd_code)
{
    char temp_ussd_code[5];

    printf("Enter your USSD CODE: '*69#': ");
    do
    {
        scanf("%4s", temp_ussd_code);

        if (strcmp(temp_ussd_code, "*69#") != 0)
        {
            clear_input_buffer();
            printf("\nEnter the code '*69#': ");
        }

    } while (strcmp(temp_ussd_code, "*69#") != 0);

    clear_input_buffer();
    strcpy(ussd_code, temp_ussd_code);
}

/**
 * @brief Validates user menu input choices
 *
 * @param input Integer representing user's menu selection
 * @return int Returns 1 if input is valid (0-5), 0 otherwise
 * @details Validates that the input is within the acceptable range of menu options (0-5)
 */
int validate_input(int input)
{
    return input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 0;
}

/**
 * @brief Handles user menu selection and input validation
 *
 * @param user_option Pointer to store the user's menu choice
 * @param account_balance Pointer to current account balance
 * @details Validates input and ensures sufficient funds for selected operations
 */
void get_user_choice(int *user_option, float *account_balance)
{
    while (scanf("%d", user_option) != 1 || !validate_input(*user_option) || (*account_balance < 1 && (*user_option == 2 || *user_option == 3 || *user_option == 4)))
    {
        if (*account_balance < 1 && (*user_option == 2 || *user_option == 3 || *user_option == 4))
        {
            printf("You do not have enough funds in your account. Please press 5 to add funds: \n");
            clear_input_buffer();
        }
        else if (!validate_input(*user_option))
        {
            printf("Enter a number from 1 to 5 both inclusive.  ");
            clear_input_buffer();
        }
        else
        {
            printf("Enter a valid integer: ");
            clear_input_buffer();
        }
    }
}

/**
 * @brief Processes money transfer transactions
 *
 * @param account_balance Pointer to current account balance
 * @details Handles transfer amount validation and balance deduction
 */
void handle_transfer(float *account_balance)
{
    float amount = 0;
    printf("Enter the amount you want transfer: ");
    do
    {
        scanf("%f", &amount);
        if (amount < 1 || amount > *account_balance)
        {
            printf("Enter a number between 1 and %f:\n", *account_balance);
            clear_input_buffer();
        }

    } while (amount < 1 || amount > *account_balance);
    *account_balance -= amount;
    printf("Deducted %f for transfer from your account.\n", amount);
}

/**
 * @brief Handles data bundle purchase transactions
 *
 * @param account_balance Pointer to current account balance
 * @details Validates purchase amount and updates balance
 */
void buy_data(float *account_balance)
{
    float amount = 0;
    printf("How much data would you like to buy? ");
    do
    {
        scanf("%f", &amount);
        if (amount < 1 || amount > *account_balance)
        {
            printf("Enter an amount between 1 and %f\n", *account_balance);
            clear_input_buffer();
        }

    } while (amount < 1 || amount > *account_balance);
    *account_balance -= amount;
    printf("Deducted %f for data from your account.\n", amount);
}

/**
 * @brief Processes airtime purchase transactions
 *
 * @param account_balance Pointer to current account balance
 * @details Validates purchase amount and updates balance
 */
void buy_airtime(float *account_balance)
{
    float amount = 0;
    printf("How much airtime would you want to buy? ");

    do
    {
        scanf("%f", &amount);

        if (amount < 1 || amount > *account_balance)
        {
            printf("Enter an amount between 1 and %f\n", *account_balance);
            clear_input_buffer();
        }
    } while (amount < 1 || amount > *account_balance);

    *account_balance -= amount;
    printf("Deducted %f for airtime from your account", amount);
}

/**
 * @brief Handles account balance top-up
 *
 * @param account_balance Pointer to current account balance
 * @details Validates and processes balance addition
 */
void top_up_balance(float *account_balance)
{
    float amount = 0;

    printf("How much would you like to add to your account? ");

    do
    {
        scanf("%f", &amount);
        if (amount < 1)
        {
            printf("Enter an amount greater than 1\n");
            clear_input_buffer();
        }
    } while (amount < 1);
    *account_balance += amount;
    printf("Added %f to your account", amount);
}

/**
 * @brief Main program entry point
 *
 * @return int Returns 0 on successful execution
 * @details Initializes the banking system, manages the main menu loop,
 *          and coordinates all banking operations
 */
int main(void)
{
    char ussd_code[5];
    float account_balance = 4000000;
    int user_option = 0, should_run = 1;
    char options[5][100] = {
        "Check Balance", "Transfer", "Buy Data", "Buy Airtime", "Top Up Balance"};

    printf("\n\n-----WELCOME TO ME-BANK69-----\n\n");

    take_ussd_code(ussd_code);

    printf("\n           -----OPTIONS-----\n");

    while (should_run)
    {
        printf("\n\n");
        for (int i = 0; i < 5; i++)
        {
            if (account_balance < 1 && (i != 0 && i != 4))
            {
                continue;
            }
            else
            {
                printf("\nTo %s, press %d", options[i], i + 1);
            }
        }
        printf("\nOr press 0 to cancel");

        printf("\n\n");

        get_user_choice(&user_option, &account_balance);

        switch (user_option)
        {
        case 1:
            printf("Your current balance is: ");
            print_formatted_currency(account_balance);
            break;
        case 2:
            printf("Your picked option is %d which is %s.\n\n", user_option, options[user_option - 1]);
            handle_transfer(&account_balance);
            break;
        case 3:
            printf("Your picked option is %d which is %s.\n\n", user_option, options[user_option - 1]);
            buy_data(&account_balance);
            break;
        case 4:
            printf("Your picked option is %d which is %s.\n\n", user_option, options[user_option - 1]);
            buy_airtime(&account_balance);
            break;
        case 5:
            printf("Your picked option is %d which is %s.\n\n", user_option, options[user_option - 1]);
            top_up_balance(&account_balance);
            break;
        case 0:
            should_run = 0;
            printf("Goodbye");
            break;
        default:
            break;
        }
    }
    return 0;
}