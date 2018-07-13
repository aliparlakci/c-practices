#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string name;
int initialsLenght = 0;
int aware = 0;
int initialsPlace = 0;
int space = 1;

void run(void);
void input(void);
void getInitialsLenght(void);
void declareInitials(void);

int main(void)
{
    run();
}

void run(void)
{
    input();
    getInitialsLenght();
    declareInitials();
}

void input(void)
{
    do
    {
        name = get_string();
    }while(name == NULL);
    
    if(name[0] != ' '){
        initialsLenght++;
        space = 0;
    }
}

void getInitialsLenght(void)
{
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if(name[i] == ' '){
            aware = 1;
            if(aware && i != n - 1 && name[i+1] != ' ')
            {
                initialsLenght++;
                aware = 0;
            }
        }
    }
    aware = 0;
}

void declareInitials(void)
{
    char initials[initialsLenght];
    if(space == 0){
        initials[0] = name[0];
    }
    
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        if(name[i] == ' '){
            aware = 1;
            if(aware && i != n - 1 && name[i+1] != ' ')
            {
                if(space == 0){
                    initials[initialsPlace+1] = name[(i+1)];
                }
                else
                {
                    initials[initialsPlace] = name[(i+1)];
                }
                aware = 0;
                initialsPlace++;
            }
        }
    }
    
    for(int i = 0; i < initialsLenght; i++){
        printf("%c", toupper(initials[i]));
    }
    
    printf("\n");
}