/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

struct Point {
	
	int x;
	int y;

};


struct result {
	
	Point* selected;
	bool *visited;
	int size;

};


void select(char *pixels, int m, int n, struct Point pivot, result* res, struct Point current,int* i) {
	

	struct Point temp;

	if (res->visited[((current.x)*(n + 1)) + current.y] == true)
		return;
	


	if (pixels[((current.x)*(n + 1)) + current.y] == pixels[((pivot.x)*(n + 1)) + pivot.y]){

		res->selected[*i].x = current.x;
		res->selected[*i].y = current.y;
		res->visited[((current.x)*(n + 1)) + current.y] = true;
		res->size = (res->size) + 1;
		*i = *i + 1;
		
	}

	else{

		res->visited[((current.x)*(n + 1)) + current.y] = false;
		return;
	}
	
	if (current.y - 1 >= 0 && current.x <= m){


		temp.x = current.x;
		temp.y = current.y-1;

		select(pixels, m, n, pivot, res, temp, i);

	}

	if (current.y + 1 <= n && current.x <= m){


		temp.x = current.x;
		temp.y = current.y+1;

		select(pixels, m, n, pivot, res, temp, i);

	}

	if (current.y <= n && current.x-1 >= 0){


		temp.x = current.x -1;
		temp.y = current.y;

		select(pixels, m, n, pivot, res, temp, i);

	}

	if (current.y <= n && current.x + 1 <= m){


		temp.x = current.x + 1;
		temp.y = current.y;

		select(pixels, m, n, pivot, res, temp, i);

	}

	else{

		return;
	}
	
}

struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	
	result res;

	if (pivot.x > m || pivot.y > n || pixels == NULL || m < 0 || n < 0 || pivot.x < 0 || pivot.y<0){
		
		res.selected = NULL;
		res.size = 0;
		res.visited = NULL;

		return res;

	}

	res.selected = (Point *)malloc(((m+1)*(n+1))*sizeof(Point));
	res.visited = (bool*)calloc(((m + 1)*(n + 1)),sizeof(bool));
	res.size = 0;

	struct Point current;
	
	int i = 0;
	int j = 0;

	current.x = pivot.x;
	current.y = pivot.y;

	select(pixels, m, n, pivot, &res, current,&i);

	return res;

}
