#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int winner();
int main();
void fillval();
void title();
void display();
void play();
char arr[9];
char tmp[9];
char ch,pos1;
void title()
{
    printf("\n\n\n\t\t\t TIC TAC TOE GAME\n");
    display();
    printf("\n ---------------------------- Rules for the game ----------------------------");
    printf("\n 1.One person can enter one symbol at a time");
    printf("\n 2.If  player 1 has entered the symbol  then player 2 will have to entered the next symbol");
    printf("\n 3.If player one has entered the number at one position then he/ she can't entered the symbol again on that position (similarly for player two)");
}
void fillval()
{
    arr[0] = '1';
    arr[1] = '2';
    arr[2] = '3';
    arr[3] = '4';
    arr[4] = '5';
    arr[5] = '6';
    arr[6] = '7';
    arr[7] = '8';
    arr[8] = '9';

    tmp[0] = '1';
    tmp[1] = '1';
    tmp[2] = '1';
    tmp[3] = '1';
    tmp[4] = '1';
    tmp[5] = '1';
    tmp[6] = '1';
    tmp[7] = '1';
    tmp[8] = '1';
    pos1='1';
}
void display()
{
    system("cls");
    printf("\n\t\t\t_____________");
    printf("\n\t\t\t|_%c_|_%c_|_%c_|", arr[0], arr[1], arr[2]);
    printf("\n\t\t\t|_%c_|_%c_|_%c_|", arr[3], arr[4], arr[5]);
    printf("\n\t\t\t|_%c_|_%c_|_%c_|", arr[6], arr[7], arr[8]);
}

void play()
{
    int pos, count = 0, k;
    char symbol;
    while (count < 9)
    {
        // system("cls");
        printf("\n\nPlayer 1 has :X: and Player 2 has :0:\n");
        printf("Enter the position number where you want to insert");
        scanf("%d", &pos);
        fflush(stdin);
        printf("\nEnter the symbol ");
         scanf("%c", &symbol);
        if ((pos > 9 || pos == 0))
        {
            printf("\nInvalid position");
            
        }
        else if(pos1==symbol){
              system("cls");
            printf("\nNow its turn for different player because you have entered %c",symbol);
            printf("\n Press enter and enter different symbol");
            getch();
            display();
           

        }
        else
        {
           
            if (tmp[pos - 1] == '1')
            {
                arr[pos - 1] = symbol;
                tmp[pos - 1] = symbol;
                count++;
                pos1=symbol;
            }
            else
            {
                printf("\nThe position is already filled.Plse press enter and enter different position");
                getch();
            }
              system("cls");
            display();
            k = winner();
            if (k == 100)
            {
                printf("\nPlayer one wins");
                break;
            }
            else if (k == 200)
            {
                printf("\nPlayer two wins");
                break;
            }
        }
    }
    if (count == 9)
    {
        printf("\nMatch draw\n");
    }
    printf("\nDo you want to play again? if Yes then press y or Y or else press n or N\n");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        main();
    }
    else
    {
        printf("Have a good day");
    }
}
int winner()
{
    if ((arr[0] == 'x' && arr[4] == 'x' && arr[8] == 'x') || (arr[0] == 'x' && arr[3] == 'x' && arr[6] == 'x') || (arr[0] == 'x' && arr[1] == 'x' && arr[2] == 'x') || (arr[2] == 'x' && arr[5] == 'x' && arr[8] == 'x') || (arr[2] == 'x' && arr[4] == 'x' && arr[6] == 'x') || (arr[1] == 'x' && arr[4] == 'x' && arr[7] == 'x') || (arr[3] == 'x' && arr[4] == 'x' && arr[5] == 'x')||(arr[6]=='x'&&arr[7]=='x'&&arr[8]=='x'))
    {

        return 100;
    }
    if ((arr[0] == '0' && arr[4] == '0' && arr[8] == '0') || (arr[0] == '0' && arr[3] == '0' && arr[6] == '0') || (arr[0] == '0' && arr[1] == '0' && arr[2] == '0') || (arr[2] == '0' && arr[5] == '0' && arr[8] == '0') || (arr[2] == '0' && arr[4] == '0' && arr[6] == '0') || (arr[1] == '0' && arr[4] == '0' && arr[7] == '0') || (arr[3] == '0' && arr[4] == '0' && arr[5] == '0')||(arr[6]=='x'&&arr[7]=='x'&&arr[8]=='x'))
    {
        return 200;
    }
}
int main()
{
    system("cls");
    fillval();
    title();

    play();
    return 0;
}
