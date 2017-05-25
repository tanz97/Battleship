#include <stdio.h>
#include <math.h>

typedef struct Game
{
    char name[80];
    int score;

}g;

void BATTLE(){
int i,j;

        printf("\t");
        for(i=1;i<=1;i++)
            for(j=1;j<=14;j++)
                printf("!");
        printf("\n");

        printf("\t!!BATTLESHIP!!\n");
        printf("\t");
        for(i=1;i<=1;i++)
            for(j=1;j<=14;j++)
                printf("!");
        printf("\n");

}


void startBoard(int board[][5])
{
    int line, column;
        for(line=0 ; line < 5 ; line++ )
            for(column=0 ; column < 5 ; column++ )
                board[line][column]=-1;
}
void showBoard(int board[][5])
{

    int line, column;

        printf("\t0 \t1 \t2 \t3 \t4");
        printf("\n");

        for(line=0 ; line < 5 ; line++ ){
            printf("%d",line);
            for(column=0 ; column < 5 ; column++ ){
                if(board[line][column]==-1){
                    printf("\t~");
                }else if(board[line][column]==0){
                    printf("\t*");
                }else if(board[line][column]==1){
                    printf("\tX");
                }

            }
            printf("\n");
        }

    }
    int main()
    {

        g game;

        FILE *fp,*tp;
         int points=0;
        int m; int n;int x; int y;
        srand(time(NULL));
        m=rand()%4;
        n=rand()%4;
        /*x=rand()%4;
        y=rand()%4;*/
        fp = fopen("C://CSE-115//score.txt","a");
        int board[5][5];
        //int ships[3][2];
        int enemy[m][n];
        int line, column;
        int hit=0;
        printf("Please enter your name: ");
        gets(game.name);
        system("cls");
        BATTLE();
        printf("\n\n");
        startBoard(board);
        showBoard(board);
        printf("m = %d\n",m);
        printf("n = %d\n",n);

        do{
        printf("Line: ");
        scanf(" %d",&line);
        printf("Column: ");
        scanf(" %d",&column);
        printf("\n");
        system("cls");

         if(m==line && column==n)
         {

            board[m][n]=1;
            hit=hit+1;
            printf("Success!\n");
            srand(time(NULL));
            m=rand()%4;
            n=rand()%4;
         }
        else if((m==line || n==column) || (m!=line && n!=column))
         {

         board[line][column]=0;
            printf("You missed !\n");


            if(m==line)
            {
                printf("There is an enemy ship in the line %d.\n",m);
            }
            else if(n==column)
            {
                printf("There is an enemy ship in the column %d.\n",n);
            }

            points++;
         }

         showBoard(board);
        }while(hit!=3);
        game.score=points;
        printf(" %s\n",game.name);
        printf(" Missed attempts %d\n",game.score);
        fputs(game.name,fp);
        fprintf(fp," %d",game.score);
        fclose(fp);

    }

