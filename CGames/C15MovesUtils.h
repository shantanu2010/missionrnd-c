int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
void swap(Board *board, int x1, int y1, int x2, int y2);
int isValidInput(char letter);



/*
Take Only Valid Input W,A,S,D,w,a,s,d . If Invalid input is entered ,Take input again . Keep Taking input until its valid
Hint : Use While Loop and isValidInput function
*/
char takeInput()
{
	
	
	char input;
	int flag = 0;
	
	do{
		
		scanf_s(" %c",&input);
		flag = isValidInput(input);
		
	}while(flag != 1);
	
	/*
	Take input and return it ,Use fflush if scanf is being used .
	Does this function need fflush ? Whats fflush ? Post your observations in the forum ,if fflush is present/not present.
	*/
	return input;
}
/*
Return 1 for Valid Input ie if w,a,s,d,W,A,S,D are entered .
Return 0 for all other inputs
*/
int isValidInput(char letter){

	if(letter == 'a' || letter == 's' || letter == 'd' || letter == 'w')
		return 1;
		
	else if(letter == 'A' || letter == 'S' || letter == 'D' || letter =='W')
		return 1;
		
	return 0;		
	
	
}
/*
Process the Given Input .Ie Decide whether to move Left , Right , Up ,or Down based on W,A,S,D,w,a,s,d.
Call goLeft Function if A or a are entered.,similarly do for all valid inputs .
Output :
Returns 1 : If Input is Valid and Move is also Valid .
Returns 0 : If Input if Valid and Move is Invalid .
Returns 0: If Input is invalid ,like other letters are entered or sent through takeInput.
*/
int processInput(Board* board,char inputChar){
	
	int res = 0;
	
	if(inputChar == 'w' || inputChar == 'W'){
		
		res = goUp(board);
		
		if (res)
			return 1;
		
		return 0;	
		
	}
	
	else if(inputChar == 'a' || inputChar == 'A'){
		
		res = goLeft(board);
		
		if (res)
			return 1;
		
		return 0;	
	}
	
	else if(inputChar == 's' || inputChar == 'S'){
		
		res = goDown(board);
		
		if (res)
			return 1;
		
		return 0;	
		
	}
	
	else if(inputChar == 'd' || inputChar == 'D'){
		
		res = goRight(board);
		
		if (res)
			return 1;
		
		return 0;	
		
	}
	
	else
		return 0;
		

	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/
	
}

/*
This Method is invoked when a character is taken as input ie User has played his ValidMove ,and you need to proccess that Move .
Steps to be Done :
1)Call ProcessInput
2)Call modifyMoveCountBasedOnProccessInput and also pass Step 1s output
3)Call clearAndRedrawScreen
4)Call printUser
*/
void playMove(Board *board, User *user, char choice){
	//printf("Play move not implemented yet , Remove this printf btw ");
	
	int result = processInput(board,choice);
		
	modifyMoveCountBasedOnProccessInput(user, result);
	
	clearAndRedrawScreen(board);
	
	printUser(user);
		

}

/*
Move the 0 Tile one position to the left .
Return 1 if the move is possible, 0 other wise .
*/
int goLeft(Board *board)
{
	
	if (board->emptyTileCol == ((board->cols) - 1))
		return 0;
	
	swap(board,board->emptyTileRow,board->emptyTileCol,board->emptyTileRow,(board->emptyTileCol)+1);
	
	board->emptyTileCol = (board->emptyTileCol)+1;	
	return 1;	
}

/*
Move the 0 Tile one position to the Right.
Return 1 if the move is possible, 0 other wise .
*/
int goRight(Board *board)
{
	if(board->emptyTileCol == 0)
		return 0;
	
	swap(board,board->emptyTileRow,board->emptyTileCol,board->emptyTileRow,(board->emptyTileCol)-1);
	
	board->emptyTileCol = (board->emptyTileCol)-1;	
	return 1;	
}

/*
Move the 0 Tile one position to the UP .
Return 1 if the move is possible, 0 other wise .
*/
int goUp(Board *board){
	
	if(board->emptyTileRow == ((board->rows)-1))
		return 0;
		
	swap(board,board->emptyTileRow,board->emptyTileCol,(board->emptyTileRow)+1,board->emptyTileCol);
	
	board->emptyTileRow = (board->emptyTileRow)+1;		
		
	return 1;	
	
}

/*
Move the 0 Tile one position to the Down .
Return 1 if the move is possible, 0 other wise .
*/
int goDown(Board *board){
	
	if(board->emptyTileRow == 0)
		return 0;
	
	swap(board,board->emptyTileRow,board->emptyTileCol,(board->emptyTileRow)-1,board->emptyTileCol);
	
	board->emptyTileRow = (board->emptyTileRow)-1;			
	return 1;	
}


/*
You can use this Helper SWAP Function which can remove lots of extra Code from above functions .
*/
void swap(Board *board, int x1, int y1, int x2, int y2)
{
	int temp;
	
	temp = (board->table)[x1][y1];
	(board->table)[x1][y1] = (board->table)[x2][y2];
	(board->table)[x2][y2] = temp;
	
}
