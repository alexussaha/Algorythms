#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

//Усов Александр
/*
1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу.*/

#define XY 6
#define M 8
#define N 8
#define STEPS 63
int steps = 0;
int PossibleSteps[8][2] = {{-1, -2}, {1, -2}, {-1, 2}, {1, 2}, {-2, -1}, {2, -1}, {-2, 1}, {2, 1}};
int board[M][N];
void print(int map[XY][XY]){
	int i, j;
	for(i = 0; i < XY; i++){
		
		for(j = 0; j < XY; j++){
			if(i==0&& j==0) map[i][j]=1;
			else if(i == 0 && map[i][j-1] == 0) map[i][j]=0;
			else if(j == 0 && map[i-1][j] == 0) map[i][j] = 0;
			else if(map[i][j] == 1 && (map[i-1][j]!=0||map[i][j-1]!=0) && i>0 && j>0  ) map[i][j]=map[i][j-1]+map[i-1][j];
			printf("%5d", map[i][j]);
		}
		printf("\n");
	}
}
void print1(int map[3][3]){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%2d", map[i][j]);
		}
		printf("\n");
	}
}
int routes(int x, int y, int map[3][3], int A[XY][XY]) {
  if ((x == 0 || y == 0) && map[x][y] == 0 ) return 0;
  else if(x==0 &&y == 0) return 1;
  else if(map[x][y] == 0) return 0;
  else if(x == 0 && A[x][y - 1] == 0)return 0;
  else if(y == 0 && A[x-1][y] == 0)return 0;
  else if(A[x-1][y]==0 && A[x][y - 1]==0) return 0;
  else return 1;
  //else return routes(x - 1, y, map) + routes(x, y - 1, map);
}





void annull(int A[XY][XY]) {
  int i;
  int j;
  for (i = 0; i < XY; i++) {
	for (j = 0; j < XY; j++) {
	  A[i][j] = -1;
	}
  }
}

void annullForHourse(int A[M][N]) {
  int i;
  int j;
  for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	  A[i][j] = 0;
	}
  }
}


int checkboard (int x, int y)
{
	if (steps == STEPS) return 1;
    int i;
    for (i = 0; i < 8; i++)          
    {
        int x1 = x + PossibleSteps[i][0];
        int y1 = y + PossibleSteps[i][1];

        if((x1 >= 0 && y1 >= 0) && (x1 < M && y1 < N))   
        {
            if(board[x1][y1] == 0)                                          
            {
                x = x1;                                                     
                y = y1;
                steps++;
                board[x][y] = steps;                                            
                if(checkboard(x, y)) return 1;                                  
                board[x1][y1] = 0;                                          
                steps--;
            }
        }
    }
     return 0;
}



int main(int argc, const char** argv) {
  int i;
  int j;
  int map[3][3];
  int steps[XY][XY];
  srand(time(NULL));
    annull(steps);
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            map[i][j] = rand()%2;
    map[0][0] = 1;
    printf("Obstacle map:\n");
    print1(map);
    printf("\n");
  for (i = 0; i < XY; i++) {
	for (j = 0; j < XY; j++) {
	  steps[i][j] = routes(i, j, map, steps);
	}
  }
  printf("\n");
  print(steps);
  printf("\n");
  annullForHourse(board);
  board[0][0] = -1;
  checkboard(0,0);
  int x, y;
  for (x=0; x<M; x++)
    {
        for (y=0; y<N; y++)
        {
            printf("%5d", board[x][y]);
        }
    printf("\n");
    } 
  
  return 0;
}