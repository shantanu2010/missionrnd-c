#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "FunctionHeaders.h"

/*
Welcome to Mission RnD.
This is the First Project which you people have to submit .
Use MainTest File for testing any other function in other Cpp files .
DO NOT write main function in any other File or else your Build Fails.
Points to Follow for the whole C course :
->Read All Note points in all the files .
->Do practice other similar questions ,related to the Topic till you are confident .
->Do not only depend on the questions given by us in the Project Tracker Tool .
->Try to resolve your bugs by only using debugger.
-> Post in forums if you have any doubt.
-> Click on Test-> Run All tests to run all tests , then you can right click on specific test case and run only that.
-> You can click on debug and then Run with/without debugging.
*/




int main(){
	int num1 = 123;
	printf("Reverse of %d is %d\n", num1, reverseNumber(num1));


	int num2 = -1230;
	printf("Reverse of %d is %d\n", num2, reverseNumber(num2));
	char str1[10] = "123";
	char str2[10] = "235";
	//printf("Sum of %s and %s is %s\n", str1, str2, addNumberStrings(str1, str2));
	//To stop cmd from exiting, on some systems it is not needed.
	getchar();
	return 0;
}