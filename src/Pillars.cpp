/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of 
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height 

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their 
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump. 
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>
int * jumps_util(int *blocks, int x, int y, int N, int M, int *jumps, int *path){
	int x_next, y_next;
	int m = 0;
	int xMoves[] = { 0,0,1,-1};
	int yMoves[] = {1,-1,0,0};
	for (int i = 0; i < 4; i++){
		x_next = x + xMoves[i];
		y_next = y + yMoves[i];
		if (isGreaterPillar(blocks, x_next, y_next, N, M)){
			*jumps = *jumps + 1;
			path[m++] = *((blocks + x_next*N) + y_next);
			if (jumps_util(blocks, x_next, y_next, N, M, jumps, path)){

			}
		}
	}
}
int isGreaterPillar(int *blocks, int i, int j, int N, int M){
	if (*((blocks + i*N) + j + 1) > *((blocks + i*N) + j) || *((blocks + i*N) + j - 1) > *((blocks + i*N) + j + 1) || *((blocks + (i + 1)*N) + j) > *((blocks + i*N) + j) || *((blocks + (i - 1)*N) + j) > *((blocks + i*N) + j)){
		return 0;
	}
	else{
		return 1;
	}
}
int isLooserPillar(int *blocks,int i,int j, int N, int M){
	if (*((blocks + i*N) + j + 1) < *((blocks + i*N) + j) || *((blocks + i*N) + j - 1) < *((blocks + i*N) + j + 1) || *((blocks + (i + 1)*N) + j) < *((blocks + i*N) + j) || *((blocks + (i - 1)*N) + j) < *((blocks + i*N) + j)){
		return 0;
	}
	else{
		return 1;
	}
}
int* pillars_max_jumps_util(int *blocks, int N, int M, int *jumps,int *path){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (isLooserPillar(blocks,i,j, N, M) == 1){
				return  jumps_util(blocks, i, j, N, M, jumps, path);
			}
		}
	}


}

int * pillars_max_jumps(int *blocks, int n, int m,int *jumps_count){
	if (blocks == NULL || n <= 0 || m <= 0){
		return NULL;
	}
	int *max_path = (int*)malloc(sizeof(int)*n*m);

	return pillars_max_jumps_util(blocks, n, m, jumps_count,max_path);
}