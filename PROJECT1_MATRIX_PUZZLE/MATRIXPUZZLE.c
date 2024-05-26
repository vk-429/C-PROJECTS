#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include <unistd.h>
#define TEXT_COLOR_DECLARATION HANDLE  hConsole;hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum borderlines{rowline=196,columnline=179,no_ofrowline=10,no_ofcolumnline=5};
enum keys{UpArrowKey=72,DownArrowKey=80,LeftArrowKey=75,RightArrowKey=77};

//Start Reading from Main Function to Undestand Code Better

//Print Target Matrix
void TargetMatrix()
{
    int i,j,k=1;
    for(j=1;j<=9;j++)
    {
        if(j%2==1)
        {
            printf("                  ");
            for(i=1;i<=no_ofrowline;i++)
                printf("%c ",rowline);
        }
        else
        {
            printf("                 ");
            for(i=1;i<=no_ofcolumnline;i++)
            {
                printf("%c ",columnline);
                if(i<5)
                {
                    if(k==16)
                    {
                        printf("   ");
                        continue;
                    }
                    if(k<=9)
                        printf("%2d ",k);
                    else
                        printf("%d ",k);
                    k++;
                }
            }
        } 
        printf("\n"); 
    }
}

//Rules of The Game
void Rules()
{
    TEXT_COLOR_DECLARATION;
    SetConsoleTextAttribute(hConsole, 9);// 9 - Blue
    printf("                     MATRIX PUZZLE\n\n");

    SetConsoleTextAttribute(hConsole, 12); // 12 - Red
    printf("                   RULES OF THIS GAME\n\n");
    printf("1.You can move empty box only 1 step at a time by arrow keys only.\n");

    SetConsoleTextAttribute(hConsole, 15); // 15 - white
    printf("       Move Up    : By Up arrow key\n");
    printf("       Move Down  : By Down arrow key\n");
    printf("       Move Left  : By Left arrow key\n");
    printf("       Move Right : By Right arrow key\n");

    SetConsoleTextAttribute(hConsole, 12); 
    printf("2.You can move number at empty position only.\n");
    printf("3.For each valid move, your total number of moves will decreased by 1,\n");
    printf("  So try to win in minimum nuber of moves.\n");
    printf("4.WinNing situation :- Numbers in a 4x4 matrix should be in order from 1 to 15.\n\n");

    SetConsoleTextAttribute(hConsole, 2); // 2 - Green
    printf("                   WINNING SITUATION\n\n");

    printf("%c You have to make the matrix looks like this :-\n",254);

    //Target Matix function to print the winning matrix (including border lines of matrix)
    TargetMatrix();

    SetConsoleTextAttribute(hConsole, 12);
    printf("5.You can EXIT the game at any time by pressing the key 'E' or 'e'.\n\n");
}


//Print Current Matrix After a Valid Move
void CurrentMatrix(char *name,int move,char (*num)[4])
{
    TEXT_COLOR_DECLARATION;
    SetConsoleTextAttribute(hConsole, 9);
    printf("                     GAME SCREEN\n\n");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Player Name : ");
    SetConsoleTextAttribute(hConsole, 2);
    printf("%s\n",name);
    SetConsoleTextAttribute(hConsole, 15);
    printf("Moves Remaining : "); 
    SetConsoleTextAttribute(hConsole, 12);
    printf("%d\n\n",move);
    SetConsoleTextAttribute(hConsole, 6);

    int index=0;
    int i,j;
    for(j=1;j<=9;j++)
    {
        if(j%2==1)
        {
            printf("                  ");
            for(i=1;i<=no_ofrowline;i++) // no_rowline=10, rowline='-'
                printf("%c ",rowline); 
        }
        else
        {
            printf("                 ");
            for(i=1;i<=no_ofcolumnline;i++)// no_columnline=5, columnline='|'
            {
                printf("%c ",columnline);
                if(i!=5)// 4 numbers in one row
                {                  
                    printf("%s",num[index]);
                    index++;
                }
            }
        } 
        printf("\n"); 
    }
}


//shuffle the Array using the Fisher-Yates algorithm
void shuffle(int *array, int n) {
    if (n > 1) {
        for (int i = n - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }
}

//Generate Random Numbers
void RandomNumberGeneration(int *a)
{
    int lower=1,upper=15;
    
    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with numbers from lower to upper
    for (int i = 0; i < 15; i++) {
        a[i] = lower + i;
    }

    // Shuffle the array for randomisation
    shuffle(a, 15);
}

//Play Game Here
int Gamescreen(char*name,int n)
{
    TEXT_COLOR_DECLARATION;
    
    int a[15];
    //Generate Random Numbers Every Time
    RandomNumberGeneration(a);

    // Converting random numbers in strings with 4 character
    // to print them easily in appropriate formate
    int i;
    char num[16][4];
    for (i = 0; i < 16; i++) {
        if (i == 15) {
            strcpy(num[i], "   ");
        } else {
            sprintf(num[i], "%2d ", a[i]);
        }
    }

    //Creating a Teporary Answer String Array to match with the
    //Current String Array whether the Winning Situation has Arrived  
    char temps[16][4];
    for (i = 0; i < 16; i++) 
    {
        if (i == 15)
            strcpy(temps[i], "   ");
        else
            sprintf(temps[i], "%2d ", (i+1));
    }

    int move;
    int p=15;
    for(move=n;move>=0;move--)
    {
        //Checking if the Current Matrix matches the Winning Situation
        int r,count=0;
        for(i=0;i<15;i++)
        {
            r=strcmp(temps[i],num[i]);
            if(r==0)
                count++;
        }
        if(count==15)
            return 1;
        else if(move==0)
            return 0;
            
        //Printing Current Matrix via function Current Matrix for Better Memroy Utilisation
        CurrentMatrix(name,move,num);

        char temp[4];
        int ch1, ch2;
        ch1 = getch();
        ch2 = 0;

        // Check if the key press is an arrow key (extended key)
        if (ch1==0 || ch1 == 0xE0) 
        { 
            ch2 = getch(); 
            switch(ch2)
            {
                case UpArrowKey:// Move Space Up
                    if((p>=0&&p<16)&&((p-4)>=0&&(p-4)<16))
                    {
                        strcpy(temp,num[p-4]);
                        strcpy(num[p-4],num[p]);
                        strcpy(num[p],temp);
                        p=p-4; 
                        printf("\nUp arrow key pressed");
                    }
                    else
                    {
                        move++;
                        printf("\nInvalid Move");
                    }
                    break;
                case DownArrowKey:// Move Space Down
                    if((p>=0&&p<16)&&((p+4)>=0&&(p+4)<16))
                    {
                        strcpy(temp,num[p+4]);
                        strcpy(num[p+4],num[p]);
                        strcpy(num[p],temp);
                        p=p+4;
                        printf("\nDown arrow key pressed");
                    }
                    else
                    {
                        move++;
                        printf("\nInvalid Move");
                    }
                    break;
                case LeftArrowKey:// Move Space Left
                    if((p>=0&&p<16)&&((p-1)>=0&&(p-1)<16)&&(p%4)!=0)
                    {
                        strcpy(temp,num[p-1]);
                        strcpy(num[p-1],num[p]);
                        strcpy(num[p],temp);
                        p=p-1; 
                        printf("\nLeft arrow key pressed"); 
                    }
                    else
                    {
                        move++;
                        printf("\nInvalid Move");
                    }
                    break;
                case RightArrowKey:// Move Space Right
                    if((p>=0&&p<16)&&((p+1)>=0&&(p+1)<16)&&(p+1)%4!=0)
                    {
                        strcpy(temp,num[p+1]);
                        strcpy(num[p+1],num[p]);
                        strcpy(num[p],temp);
                        p=p+1; 
                        printf("\nRight arrow key pressed"); 
                    }
                    else
                    {
                        move++;
                        printf("\nInvalid Move");
                    }
                    break;
                default:
                    {
                        printf("SOME OTHER SCROLL KEY PRESSED: %d %d\n", ch1, ch2);
                        move++;
                    } 
                    break;
            }
        }
        else
        {
            if(ch1=='e'||ch1=='E')//Exit Condition
            {
                TEXT_COLOR_DECLARATION;
                SetConsoleTextAttribute(hConsole, 15);
                system("cls");
                exit(0);
            }
            move++;
            printf("\nkey pressed: %d %c\n", ch1, ch2);
        }
        system("cls");
    }
}


int main()
{
    TEXT_COLOR_DECLARATION;//  To change the text color
    // Read the definition from MACRO defined above

    //input the name of the player
    char name[100];
    inputname:printf("Enter the Player Name : ");
    fflush(stdin);// using fflush() to empty the standard input stream
    fgets(name,100,stdin);
    name[strlen(name)-1]='\0';
    if(strlen(name)==0)//Check if user presses 'Enter Key' without entering any name
    {
        SetConsoleTextAttribute(hConsole, 12);
        printf("Please Enter Some Name!");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(1);
        system("cls");
        goto inputname;
    }
    system("cls");// to clear the screen

    //Make user understand rules of the game with the help pf Rules() function
    Rules();

    SetConsoleTextAttribute(hConsole, 2);// 2 - text color Green
    printf("                      GOOD LUCK !\n\n");
    SetConsoleTextAttribute(hConsole, 15);// 15 - white
    printf("Press any key to start.....");
    getch();// empty getch() to transfer the control immediately to next line
    system("cls");
    int n=-1,result;

    // input for maximum no. of moves in which user expect that he can win the game
    moves:printf("Enter maximum no. of moves(>0) : ");
    fflush(stdin);
    scanf("%d",&n);

    //handle the case when user enters 0 or a negative number as no. of moves
    if(n<=0)
    {
        SetConsoleTextAttribute(hConsole, 12);// 12 - Red
        printf("Please Enter a Valid No. of Moves");
        SetConsoleTextAttribute(hConsole, 15);
        sleep(1);
        system("cls");
        goto moves;
    }
    system("cls");

    // Gamescreen() function which provides interface to play the game
    // and returns the result of the game
    result=Gamescreen(name,n);
    SetConsoleTextAttribute(hConsole, 2);

    // Printing greetings according to result
    if(result==1)
    {
        printf("                   CONGRATULATIONS !\n");
        printf("                       YOU WON !\n\n");
    }
    SetConsoleTextAttribute(hConsole, 12);
    if(result==0)
    {
        printf("                      SORRY !\n");
        printf("                    YOU LOST !\n\n");
    }

    char ch;
    SetConsoleTextAttribute(hConsole, 2);
    printf("Want to play agan?\n");//Confirming before exit whether user want to play again or not
    SetConsoleTextAttribute(hConsole, 15);
    printf("Press 'y' or 'Y' for Yes and any other key for No : ");
    ch=getch();
    if(ch=='y'||ch=='Y')
    {
        printf("%c",ch);
        printf("\n\n");
        main();
    }
    else
    {
        system("cls");
        exit(0);
    }
    return 0;
}