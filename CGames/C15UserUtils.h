#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Used to Store Name and His MovesCount , It will be later be used to generate High Scores Table
*/
typedef struct User{
	char *name;
	int movesCount;
}User;

/*
Create the user from Heap , Assign name to user->name , Make movesCount as 0.
Return the user .
*/
User * createUser(char *name){
	
	int i = 0;
	User* newUser = (User*)malloc(sizeof(User));
	
	newUser->movesCount = 0;
	newUser->name = (char*)malloc(35*sizeof(char));
	
	while(name[i]!='\0'){
		
		(newUser->name)[i]=name[i];
		i++;
	}
	(newUser->name)[i]='\0';
	
	return newUser;
}


/*
Increase moveCount of user by 1 ,if processInputOutCome is 1 ,Otherwise Leave it .
*/
void modifyMoveCountBasedOnProccessInput(User *user, int processInputOutCome){
	
	if(processInputOutCome==1)
		user->movesCount = (user->movesCount) + 1;
		
	
}

/*
Print the Following String from User Information .Replace accordingly .Dont ask what to Replace .
"Hey Abhijith , You have played 43 Moves "
*/
void printUser(User *user){
	
	printf("Hey %s , You have played %d Moves",user->name,user->movesCount);
}
