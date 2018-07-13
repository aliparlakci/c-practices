#include <cs50.h>
#include <stdio.h>

void mario(int line);

int main(void)
{
    int height = 0;
    do
    {
        printf ("Height: ");
        height = get_int();
        
    }while(height < 0 || height > 23);
    
    mario(height);
    
}

void mario(int line)
{
    for(int i = 0; i < line; i++)
    {
        for(int x = line - 1; x > i; x--)
        {
            printf(" ");
        }
        
        for(int y = 0; y <= i; y++)
        {
            printf("#");
        }
        
        printf("  ");
        
        for(int y = 0; y <= i; y++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}
