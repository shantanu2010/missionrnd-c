/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include <stdio.h>
#include <string.h>


int getCube(int power){


	int temp = 1;

	while (power != 0){

		temp *= 3;
		power--;
	}
	return temp;
}


char identifyKid_Recu(int N,char kid, int K){


	if (N == 1)
		return kid;

	int temp = K;

	if (K % 3 == 0)
		temp /= 3;
		

	else{
		
		temp /= 3;
		temp += 1;
	}
	
	kid = identifyKid_Recu(N - 1, kid, temp);


	if (kid == 'A'){
		
		if (K % 3 == 0)
			return 'C';
		if (K % 3 == 1)
			return 'A';
		if (K % 3==2)
			return 'B';
	}

	else if (kid == 'B'){

		if (K % 3 == 0)
			return 'A';
		if (K % 3 == 1)
			return 'B';
		if (K%3==2)
			return 'C';

	}
	
	else{

		if (K % 3 == 0)
			return 'B';
		if (K % 3 == 1)
			return 'C';
		if (K % 3 ==2)
			return 'A';
	}

}




char identifyKid(int N, int K) {
	

	int maxElementsPossible = getCube(N);

	if (N<1)
		return '\0';

	if (maxElementsPossible<=K && maxElementsPossible > 0)
		return '\0';

	char answer = 'A';

	return identifyKid_Recu(N, answer,K);


}