#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>


#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define BYEL "\e[1;33m"
#define URED "\e[4;31m"
#define UCYN "\e[4;36m"
#define CRESET "\e[0m"
#define WHT "\e[0;37m"

void CreateMatrix(int arr[][4]);
void ShowMatrix(int arr[][4]);

void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
int readEnteredKey()
{
   char c;
   c=getch();
  
  return c;
}
// shift up function
int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 3) // shifting not possible
        return 0;

    // Successfully swapped two numbers !
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; // Success
}

int shiftDown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 0) // shifting not possible
        return 0;
    swap(&arr[i][j], &arr[i - 1][j]); // swap numbers

    return 1; // shift up success
}

int shiftRight(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);

    return 1; // shift up success
}

int shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }

    if (j == 3) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // shift up success
}

int winning(int arr[][4])
{
  int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
            if (arr[i][j] != k)
                break;

        if(j<4)        
          break;
    }

    if (j < 4)
        return 0;
    return 1;
}

void GameRule(int arr[][4])
{
    int i,j;
    printf(MAG"\t\t  MATRIX PUZZLE\n"WHT);
    printf("\n");
    printf(BLU "                 RULE OF THIS GAME                 \n" WHT);
    printf(URED "\n1.You can move only 1 step at a time by arrow key \n" WHT);
    printf(BYEL"\n\tMove Up   : by Up arrow key "WHT);
    printf(BYEL"\n\tMove Down : by Down arrow key"WHT);
    printf(BYEL"\n\tMove Left : by Left arrow key"WHT);
    printf(BYEL"\n\tMove Right: by Right arrow key"WHT);

    printf(MAG "\n\n2.You can move number at empty position only"  WHT);
    printf(URED "\n3. For each valid move : your total number of move will decreased by 1 \n"  WHT);
    printf(MAG "4. Wining situation : " WHT);
    printf(URED " Number in a 4*4 matrix should be in order from 1 to 15 " WHT);
    printf(MAG"\n\n            winning situation:         \n"WHT);

    printf(BLU "--------------------\n"  WHT);
    
    for(i=0;i<4;i++)
    {   printf(BLU"|");
        for(j=0;j<4;j++)
       {
         if(i<3 || j<3)
           printf(BLU "%2d | ",4*i+(j*1+1));
         else
           printf(BLU"   |"WHT);
       }

       printf("\n")  ;
    }
    printf(BLU "--------------------\n" WHT);
    printf(URED"\n5.You can exit the game at any time by pressing 'E' or 'e' "WHT);

    printf(MAG"\nSo Try to win in minimum no of move \n"WHT);

    printf(BYEL"\nEnter any key to start.....   \n"WHT);

    

}
int main()
{
    int arr[4][4] ;//matrix
    int MaxMoves=4; 
    char name[20];

    for(int i=0;i<2;i++)
      printf("\n");
    
    printf("Player Name:-");
    scanf("%s",name);

    system ("cls");
   
    while(1)
    {
    CreateMatrix(arr);
    GameRule(arr);
    while(!winning(arr))
    {
       if(!MaxMoves)
        break;

       printf("\n\n  Player Name:  %s ,  Move remaining : %d\n\n", name, MaxMoves); 

        ShowMatrix(arr);

        int key=readEnteredKey();

        switch (key) // maping
            {
            case 101: // ascii of E

            case 69: // ascii of e
                printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                printf("\nHit 'Enter' to exit the game \n");
                key = readEnteredKey();
                return 0;

            case 72: // arrow up
                if (shiftUp(arr))
                    MaxMoves--;
                break;
            case 80: // arrow down
                if (shiftDown(arr))
                    MaxMoves--;
                break;
            case 77: // arrow  right
                if (shiftRight(arr))
                    MaxMoves--;
                break;
            case 75: // arrow left
                if (shiftLeft(arr))
                    MaxMoves--;
                break;
            default:

                printf("\n\n      \a\a Not Allowed \a");
            }

        }
         if (!MaxMoves)
            printf(URED "\n\a          YOU LOSE !          \a\a\n" WHT);
        else
            printf(URED "\n\a!!!!!!!!!!!!!Congratulations  %s for winning this game !!!!!!!!!!!!!\n\a" WHT, name);

        fflush(stdin); // Will clear the buffer
        char check;
        printf(BYEL "\nWant to play again ? \n"WHT);
        printf("enter 'y' to play again:  ");
        scanf("%c", &check);

        // Leave the game here itself !
        if ((check != 'y') && (check != 'Y'))
            break;

       MaxMoves= 4;
    }
    return 0;
}

void CreateMatrix(int arr[][4])
{
    int n=15; 
    int num[n],i, j;

    for(i=0;i<15;i++)
     num[i]=i+1;  

    srand(time(NULL));

    int lastIndex = n-1, index;

     for(i=0;i<4;i++)
      for(j=0;j<4;j++)
        if(lastIndex>=0)
        {
          index=rand()%(lastIndex+1);
          arr[i][j]=num[index];
          num[index]=num[lastIndex--];
        }

      arr[i-1][j-1]=0;

}

void ShowMatrix(int arr[][4])
{
    printf("\n\n--------------------\n");
    for(int i=0;i<4;i++)
    { 
        printf("|");

          for(int j=0;j<4;j++)
            if(arr[i][j]!=0)
              printf("%2d | ",arr[i][j]);
            else
              printf("   |");

          printf("\n");
    }
    printf("--------------------\n");

}

