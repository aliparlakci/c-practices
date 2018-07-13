#include <stdio.h>
#include <cs50.h>

int greedy(float change);

int main(void)
{
    float owed;
    
    do
    {
        
    printf("O hai! How much change is owed?\n>");
    owed = get_float();
    
    }while(owed < 0);
    
    printf("%i\n", greedy(owed));
}

int greedy(float change)
{
    int change_left = (int) ((change * 100) + 0.5);
    int coin_amount = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels  = 0;
    int pennies = 0;
    
    //printf("%i\n", change_left);
    
    while(change_left >= 25)
    {
        coin_amount += change_left / 25;
        quarters = change_left / 25;
        change_left = change_left % 25;
    }
    
    //printf("%i\n", change_left);
    //printf("%i quarters\n", quarters);
    
    while(change_left >= 10)
    {
        coin_amount += change_left / 10;
        dimes = change_left / 10;
        change_left = change_left % 10;
    }
    
    //printf("%i\n", change_left);
    //printf("%i dimes\n", dimes);
    
    while(change_left >= 5)
    {
        coin_amount += change_left / 5;
        nickels = change_left / 5;
        change_left = change_left % 5;
    }
    
    //printf("%i\n", change_left);
    //printf("%i nickels\n", nickels);
    
    while(change_left >= 1)
    {
        coin_amount += change_left / 1;
        pennies = change_left / 1;
        change_left = change_left % 1;
    }
    
    //printf("%i\n", change_left);
    //printf("%i pennies\n", pennies);
    
    return coin_amount;
}