#include <cs50.h>
#include <stdio.h>

unsigned int company = 0;
unsigned long long card_number = 0;
// 1 --> American Express
// 2 --> MasterCard
// 3 --> Visa
int digits[16] = {};

void digits_func(long long all_digits, int lenght);
int lenght_finder(long long numbers);
void identifier(int lenght);
void calc();
void amex();
void visa();
void mastercard();

int main(void)
{
    printf("Please enter the credit card number\n>");
    
    card_number = get_long_long();
    
    if(lenght_finder(card_number) > 16){printf("INVALID");}
    digits_func(card_number , lenght_finder(card_number));
    identifier(lenght_finder(card_number));
    //for(int i = 0;lenght_finder(card_number) > i; i++){printf("%i => %i\n",i , digits[i]);}
}

void identifier(int lenght)
{
    switch(lenght)
    {
        case 13:
        case 16:
            if(digits[0] == 4)
            {
                visa();
            }
            else if(digits[0] == 5)
            {
                if(digits[1] == 1 || digits[1] == 2 || digits[1] == 3 || digits[1] == 4 || digits[1] == 5)
                {
                    mastercard();
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
            break;
        case 15:
            if(digits[0] == 3 && (digits[1] == 4 || digits[1] == 7))
            {
                amex();
            }
            else
            {
                printf("INVALID\n");
            }
        break;
        default:
            printf("INVALID\n");
    }
}

void digits_func(long long all_digits, int lenght)
{
    int digits_place = 1;
    
    while(all_digits)
    {
    digits[lenght-digits_place] = all_digits % 10;
    all_digits /= 10;
    digits_place++;
    }
}

int lenght_finder(long long numbers)
{
    int lenght = 1;
    for(; numbers > 9;lenght++)
    {
        numbers /= 10;
    }
    return lenght;
}

void calc()
{
    int sum = 0;
    
    for(int i = 2; lenght_finder(card_number) >= i; i+=2)
    {
        if((digits[lenght_finder(card_number) - i] * 2) > 9)
        {
            sum += ((digits[lenght_finder(card_number) - i] * 2) / 10) + ((digits[lenght_finder(card_number) - i] * 2) % 10);
            //printf("#%i element, %i added, sum: %i\n", (lenght_finder(card_number) - i), ((digits[lenght_finder(card_number) - i] * 2) / 10) + ((digits[lenght_finder(card_number) - i] * 2) % 10), sum);
        }
        else
        {
            sum += (digits[lenght_finder(card_number) - i] * 2);
            //printf("#%i element, %i added, sum: %i\n", (lenght_finder(card_number) - i), (digits[lenght_finder(card_number) - i] * 2), sum);
        }
    }
        
        //printf("\n");
        
    for(int i = 1; lenght_finder(card_number) >= i; i+=2)
    {
        sum += (digits[lenght_finder(card_number) - i]);
        //printf("#%i element, %i added, sum: %i\n", (lenght_finder(card_number) - i), (digits[lenght_finder(card_number) - i]), sum);
    }
    
    
    if((sum % 10) == 0)
    {
        switch(company)
        {
            case 1:
                printf("AMEX\n");
                break;
            
            case 2:
                printf("MASTERCARD\n");
                break;
            
            case 3:
                printf("VISA\n");
                break;
            
            default:
                printf("INVALID\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

void amex()
{
    company = 1;
    calc();
}

void mastercard()
{
    company = 2;
    calc();
}

void visa()
{
    company = 3;
    calc();
}