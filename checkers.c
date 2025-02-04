#include<stdio.h>
#include<stdlib.h>
//#include<string>
#include<stdlib.h>

void print_board(int board [9][8])
{
	system("cls");//clearing screen
	int x, y;
	char z=1;
	for(x=1;x<9;x++)
	{
		printf("%d",z);
		z++;
		for(y=1;y<9;y++)
		{
			printf("|");
			switch(board [x][y])
			{
			case 0:
				printf(" ");
				break;
			case 1: 
				printf("x");
				break;
			case 2: 
				printf("o");
				break;
			case 3: 
				printf("x");
				break;
			case 4: 
				printf("o");
				break;
			}
		}
	printf("\n");
	}
	printf("  1 2 3 4 5 6 7 8 \n");
}
void set_defaults (int board[9][8])// making board
{
	board[1][2]=1;board[1][4]=1;board[1][6]=1;board[1][8]=1;
	board[2][1]=1;board[2][3]=1;board[2][5]=1;board[2][7]=1;
	board[3][2]=1;board[3][4]=1;board[3][6]=1;board[3][8]=1;
	board[6][1]=2;board[6][3]=2;board[6][5]=2;board[6][7]=2;
	board[7][2]=2;board[7][4]=2;board[7][6]=2;board[7][8]=2;
	board[8][1]=2;board[8][3]=2;board[8][5]=2;board[8][7]=2;
}
int Enemy(int you)
{
	if(you==1||you==3)
		return 2;
	if(you==2||you==4)
		return 1;
}
void Check_if_became_queen(int x,int y,int board[9][8],int turn)
{
	if(turn==1)
		if(x==8)
			board[x][y]==3;
			
	if(turn==2)
		if(turn==1)
			board[x][y]==4;
}
int NextChainValid(int board [9][8],int x[4])
{
	if(board[x[3]+1][x[4]+1]==Enemy(board[x[3]][x[4]]) || board[x[3]+1][x[4]+1]==Enemy(board[x[3]][x[4]]+2))
		return 1;
		
	else if(board[x[3]+1][x[4]-1]==Enemy(board[x[3]][x[4]]) || board[x[3]+1][x[4]-1]==Enemy(board[x[3]][x[4]]+2))
		return 1;
		
	else if(board[x[3]-1][x[4]+1]==Enemy(board[x[3]][x[4]]) || board[x[3]-1][x[4]+1]==Enemy(board[x[3]][x[4]]+2))
		return 1;
		
	else if(board[x[3]-1][x[4]-1]==Enemy(board[x[3]][x[4]]) || board[x[3]-1][x[4]-1]==Enemy(board[x[3]][x[4]]+2))
		return 1;
		
	else
		return 0;
}

void get_co(int board [9][8], int turn,int peshka[2])
{
	int x[4];//from here
	getxyaz:
	if(turn==1)
		printf("x's turn \n");
	else
		printf("o's turn \n");

	printf("Write xyaz:\n");
	scanf("%d %d %d %d",&x[1],&x[2],&x[3],&x[4]);
	if(board[x[1]][x[2]]==turn || board[x[1]][x[2]]==turn+2)//checking move is valid or not if valid then make it
	{
		if(turn==1)
		{
			if(x[3]==x[1]+1 && x[4]==x[2]+1 || x[4]==x[2]-1)// checking if new co of peksha is valid
			{
				board[x[1]][x[2]]=0;//making them
				board[x[3]][x[4]]=turn;
				Check_if_became_queen(x[3],x[4],board,turn);	
			}
			else if(x[3]==x[1]+2 && x[4]==x[2]+2 || x[4]==x[2]-2)
			{
				board[x[1]][x[2]]=0;
				board[x[3]][x[4]]=turn;
				int x2, y2;
				
				if(x[1]>x[3])
					x2=x[1]-1;
				else
					x2=x[3]-1;
					
				if(x[2]>x[4])
					y2=x[2]-1;
				else
					y2=x[4]-1;
					
				board[x2][y2]=0;
				peshka[turn+1]--;//lowering amt of peshka thsat enemy has
				Check_if_became_queen(x[3],x[4],board,turn);
				if(NextChainValid(board,x))
					get_co(board,turn,peshka);
			}
			else
			{
				printf("Invalid move!\n Try Again!");
				goto getxyaz;
			}
		}
		else if(turn==2)
		{
			if(x[3]==x[1]-1 && x[4]==x[2]+1 || x[4]==x[2]-1)// checking if new co of peksha is valid
			{
				board[x[1]][x[2]]=0;//making them
				board[x[3]][x[4]]=turn;
				Check_if_became_queen(x[3],x[4],board,turn);	
			}
			else if(x[3]==x[1]-2 && x[4]==x[2]+2 || x[4]==x[2]-2)
			{
				board[x[1]][x[2]]=0;
				board[x[3]][x[4]]=turn;
				int x2, y2;
				
				if(x[1]>x[3])
					x2=x[1]-1;
				else
					x2=x[3]-1;
					
				if(x[2]>x[4])
					y2=x[2]-1;
				else
					y2=x[4]-1;
					
				board[x2][y2]=0;
				peshka[turn-1]--;//lowering amt of peshka thsat enemy has
				Check_if_became_queen(x[3],x[4],board,turn);
				if(NextChainValid(board,x))
					get_co(board,turn,peshka);
			}
			else
			{
				printf("Invalid move!\n Try Again!");
				goto getxyaz;
			}
			
		}
		else if(turn==3)//Queen X.
		{
			if(x[3]==x[1]-1 || x[3]==x[1]+1 && x[4]==x[2]+1 || x[4]==x[2]-1)// checking if new co of peksha is valid
			{
				board[x[1]][x[2]]=0;//making them
				board[x[3]][x[4]]=turn;
				Check_if_became_queen(x[3],x[4],board,turn);	
			}
			else if(x[3]==x[1]+2 || x[3]==x[1]-2 && x[4]==x[2]+2 || x[4]==x[2]-2)
			{
				board[x[1]][x[2]]=0;
				board[x[3]][x[4]]=turn;
				int x2, y2;
				
				if(x[1]>x[3])
					x2=x[1]-1;
				else
					x2=x[3]-1;
					
				if(x[2]>x[4])
					y2=x[2]-1;
				else
					y2=x[4]-1;
					
				board[x2][y2]=0;
				peshka[turn-1]--;//lowering amt of peshka thsat enemy has
				Check_if_became_queen(x[3],x[4],board,turn);
				if(NextChainValid(board,x))
					get_co(board,turn,peshka);
			}
			else
			{
				printf("Invalid move!\n Try Again!");
				goto getxyaz;
			}	
		}
		else if(turn==4)
		{
				if(x[3]==x[1]-1 && x[4]==x[2]+1 || x[4]==x[2]-1)// checking if new co of peksha is valid
			{
				board[x[1]][x[2]]=0;//making them
				board[x[3]][x[4]]=turn;
				Check_if_became_queen(x[3],x[4],board,turn);	
			}
			else if(x[3]==x[1]+2 && x[4]==x[2]+2 || x[4]==x[2]-2)
			{
				board[x[1]][x[2]]=0;
				board[x[3]][x[4]]=turn;
				int x2, y2;
				
				if(x[1]>x[3])
					x2=x[1]-1;
				else
					x2=x[3]-1;
					
				if(x[2]>x[4])
					y2=x[2]-1;
				else
					y2=x[4]-1;
					
				board[x2][y2]=0;
				peshka[turn-3]--;//lowering amt of peshka thsat enemy has
				Check_if_became_queen(x[3],x[4],board,turn);
				if(NextChainValid(board,x))
					get_co(board,turn,peshka);
			}
			else
			{
				printf("Invalid move!\n Try Again!");
				goto getxyaz;
			}
			
		}
				 } 			
	
}

int Winner(int x, int o)
{
	if(x==0)
	{
		printf("O won!");
		return 1;
	}
	else if(o==0)
	{
		printf("X won!");
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int board [9][8]={0}, turn=2, peshka[2]={12};
	set_defaults(board);
	while (Winner (peshka[1],peshka[2]))
	{
		print_board(board);
		get_co(board,turn,peshka);
		
		if(turn==2)
			turn=1;
		else
			turn=2;
	}
	scanf("a&d");
}
