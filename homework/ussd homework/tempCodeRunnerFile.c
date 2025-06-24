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