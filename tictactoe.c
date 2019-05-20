#include<stdio.h>
#include<stdlib.h>
//#include<windows.h>

char mat[3][3];      //global declaration of matrix

void init_mat(void);
void display(void);                               //various functions used
void get_user_input(void);
void get_computer_input(void);
char check(void);

/*void GotoXY(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}*/

//main function
int main()
{
  char ch=' ';
  init_mat();
  display();
  do{
    get_computer_input();
    display();
    ch=check();
    if(ch!=' ')
    {
      display();
      break;
    }
    get_user_input();
    ch=check();
    if(ch!=' ')
    {
      display();
      break;
    }
    display();
  }while(ch==' ');

  if(ch=='X')
    printf("\n\nYou Won!! Enjoy! \n\n");
  else
    printf("\n\nI Won!! Better luck next time loser! \n\n");
  return 0;
}
//main end

//initializing the matrix to blank
void init_mat(void)
{
  int i,j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      mat[i][j]=' ';
}

//display the matrix
void display(void)
{
  int i;
//GotoXY(0,0);
  system("cls");
  printf("\n\nThis is a classic tic tac toe game. You are 'X' and I am 'O'. Let's play this exciting game!\n\n");
  printf("\nThe current view of the game is: \n\n");
  for(i=0;i<3;i++)
  {
    printf(" %c | %c | %c\n",mat[i][0],mat[i][1],mat[i][2]);
    if(i!=2)
      printf("---|---|---\n");
  }
  printf("\n\n");
}

//to get user's input
void get_user_input(void)
{
  int x,y;
  printf("Enter coordinates of position to be selected: ");
  scanf("%d%*c%d",&x,&y);

  x--; y--;

  if(mat[x][y]!=' ')
  {
    printf("Invalid Entry. Try again!");
    get_user_input();
  }
  else
    mat[x][y]='X';
}

//to check if someone won
char check(void)
{
  int i;
  for(i=0;i<3;i++)                                           //Checking each row
    if(mat[i][0]==mat[i][1] && mat[i][0]==mat[i][2])
      return mat[i][0];

  for(i=0;i<3;i++)                                          //Checking each column
    if(mat[0][i]==mat[1][i] && mat[0][i]==mat[2][i])
      return mat[0][i];

  if(mat[0][0]==mat[1][1] && mat[0][0]==mat[2][2])          //Checking diagonal 1
    return mat[0][0];

  if(mat[0][2]==mat[1][1] && mat[0][2]==mat[2][0])         //Checking diagonal 2
      return mat[0][2];

  return ' ';
}

//to get input from computer
void get_computer_input(void)
{
  int i,j,count;

  for(i=0;i<3;i++)
  {
    count=0;
    for(j=0;j<3;j++)
      if(mat[j][i]=='O')                 //checking columns for about-to-win situation for computer
        count++;
    if(count==2)
    {
      for(j=0;j<3;j++)
        if(mat[j][i]==' ')
        {
          mat[j][i]='O';
          return;
        }
    }
  }

  for(i=0;i<3;i++)
  {
    count=0;
    for(j=0;j<3;j++)
      if(mat[i][j]=='O')                 //checking rows for about-to-win situation for computer
        count++;
    if(count==2)
    {
      for(j=0;j<3;j++)
        if(mat[i][j]==' ')
        {
          mat[i][j]='O';
          return;
        }
    }
  }

  count=0;
  for(i=0;i<3;i++)
    if(mat[i][i]=='O')                 //checking diagonal 1 for about-to-win situation for computer
      count++;
  if(count==2)
    for(i=0;i<3;i++)
      if(mat[i][i]==' ')
      {
        mat[i][i]='O';
        return;
      }

  count=0;
  for(i=0;i<3;i++)
    if(mat[i][2-i]=='O')                 //checking diagonal 2 for about-to-win situation for computer
      count++;
  if(count==2)
    for(i=0;i<3;i++)
      if(mat[i][2-i]==' ')
      {
        mat[i][2-i]='O';
        return;
      }                                        //end of move to win for computer

  for(i=0;i<3;i++)
  {
    count=0;
    for(j=0;j<3;j++)
      if(mat[j][i]=='X')                 //checking columns for about-to-win situation for user
        count++;
    if(count==2)
    {
      for(j=0;j<3;j++)
        if(mat[j][i]==' ')
        {
          mat[j][i]='O';
          return;
        }
    }
  }

  for(i=0;i<3;i++)
  {
    count=0;
    for(j=0;j<3;j++)
      if(mat[i][j]=='X')                 //checking rows for about-to-win situation for user
        count++;
    if(count==2)
    {
      for(j=0;j<3;j++)
        if(mat[i][j]==' ')
        {
          mat[i][j]='O';
          return;
        }
    }
  }

  count=0;
  for(i=0;i<3;i++)
    if(mat[i][i]=='X')                 //checking diagonal 1 for about-to-win situation for user
      count++;
  if(count==2)
    for(i=0;i<3;i++)
      if(mat[i][i]==' ')
      {
        mat[i][i]='O';
        return;
      }

  count=0;
  for(i=0;i<3;i++)
    if(mat[i][2-i]=='X')                 //checking diagonal 2 for about-to-win situation for user
      count++;
  if(count==2)
    for(i=0;i<3;i++)
      if(mat[i][2-i]==' ')
      {
        mat[i][2-i]='O';
        return;
      }

  if(mat[1][1]==' ')                    //center move
  {
    mat[1][1]='O';
    return;
  }

  else if(mat[0][0]==' ')
  {

      mat[0][0]='O';
      return;
  }

  else if(mat[0][2]==' ')
  {
      mat[0][2]='O';
      return;
  }

  else if(mat[2][0]==' ')
  {
      mat[2][0]='O';
      return;
  }

  else if(mat[2][2]==' ')
  {
      mat[2][2]='O';
      return;
  }

  else if(mat[0][1]==' ')
  {
      mat[0][1]='O';
      return;
  }

  else if(mat[1][0]==' ')
  {
      mat[1][0]='O';
      return;
  }

  else if(mat[1][2]==' ')
  {
      mat[1][2]='O';
      return;
  }

  else if(mat[2][1]==' ')
  {
      mat[2][1]='O';
      return;
  }

  else
  {
    display();
    printf("\n\nDraw! You were quite a match!\n\n");
    exit(0);
  }
}
