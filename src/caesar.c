#include <cs50.h>
#include <stdio.h>
#include <string.h>

void cypher(void);

int key = 0;

int main (int argc, string argv[])
{
    if (argc != 2){
        printf("missing arguments!");
        return 1;
    }
    else
    {
        key = ((int) strtol(argv[1], NULL, 10) % 26);
        cypher();
    }
}

void cypher(void)
{
    string plainText = NULL;
    do
    {
    printf("plaintext: ");
    plainText = get_string();
    }while(plainText == NULL);
    
    int plainLenght = strlen(plainText);
    char cypheredText[plainLenght];
    
    for(int i = 0; i < plainLenght; i++)
    {
        if(plainText[i] <= 122 && plainText[i] >= 97)
        {
            if(plainText[i] + key > 122)
            {
                int newKey = key - (122 - plainText[i]);
                //printf("new key: %i", key);
                cypheredText[i] = (char) (96 + newKey);
            }
            else
            {
                cypheredText[i] = (int) (plainText[i] + key);
            }
        }
        else if(plainText[i] <= 90 && plainText[i] >= 65)
        {
            if(plainText[i] + key > 90)
            {
                int newKey = key - (90 - plainText[i]);
                cypheredText[i] = (char) (64 + newKey);
            }
            else
            {
                cypheredText[i] = (int) plainText[i] + key;
            }
        }
        else
        {
            cypheredText[i] = (int) plainText[i];
        }
    }
    
    printf("ciphertext: ");
    
    for(int i = 0; i < plainLenght; i++)
    {
        printf("%c", cypheredText[i]);
    }
    
    printf("\n");
    
}
