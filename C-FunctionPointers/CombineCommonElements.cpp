/*
In this question you will know how to assign,handle function pointers inside structures.

Given 2 arrays of ObjectNode's (which will have a value and function pointer).
You need to return the common values present in both the arrays. You also need to copy
final result array length into commonElementsLength

ObjectNode is a struct which holds a value of any type and also a equals function.

Sample float object Node.
float number = 7.45;
struct ObjectNode * floatObjectNode = (struct ObjectNode *)malloc(sizeof(struct ObjectNode));
floatObjectNode->value = (void *)&number;
floatObjectNode->equals = <Any Address of function which checks the equality of 2 void * who will point
to 2 float values)

Example :
Arr1 : [1,2,3,4,5]
Arr2 : [3,4,5,9,10]

So if each value in these 2 arrays are converted into objectNodes to create 2 more arrays
and sent to combine_common_elements sample output should be
[3,4,5]

You need to return an array of ObjectNode *, where each ObjectNode * points to one of the
common value. The return type of array would be struct ObjectNode **.

If 2 object nodes -> values are equal, you need to copy the first array's ObjectNode into final answer.
ie
Lets say inital int arrays are a=[1,3,4] and b=[2,5,3].
When converted to object node * array, now these are
[1000,1002,1004] and [1006,1008,1010] .

Here 1000 is address of a ObjectNode whose value will point to &a[0] ie 3's address.
1002-->value points to &a[1] like that 1010->value points to &b[2] ie 3's address.

The final returned array should be [1002]. (Even though both 1002 and 1010 point to 3, we will copy
only first object node arrays value)

Note 2 : (Final array shouldnt have any duplicates, If found Precedence needs to be given to first array
than second array,and in same array lesser index will get higher precedence)
If initial arrays are are a=[2,4,5,4] and b=[4,4,5,4,23,2]

Lets assume objectNodes1=[2000,2002,2004,2006] and objectNodes2=[2008,2010,2012,2014,2016,2018,2020]
(Here as in prev exampple 2004 points to 5, 2016 points to 4 etc.)
Return array should be [2000,2002]

*/

/*
Difficulties faced in this lesson :
->
->
*/
#include <stdio.h>
#include <stdlib.h>

/**
ObjectNode holds a value of any type and
also a equals function which will take 2 void * of the same datatype of value, and
this equals function should return 1 if both values are equal,0 otherwise.
*/
struct ObjectNode {
	void * value;
	int(*equals)(void *, void *);
};

/*
Sample equals Function for integers.
You will use this function while creating a Object node whose value holds address of an int.
*/
int equalsInt1(void * a, void *b) {
	//As a and b are void *, you need to first convert them to int * and extract the value.
	
	if (*(int *)a == *(int *)b)
		return 1;

	return 0;
}

/*
Sample function to print INT.
*/
void printInt(void * value) {
	printf("%d\n", *(int *)value);
}

/*
Sample function to create a int Object Node from a int pointer and equals function passed.
*/
struct ObjectNode * createIntObjectNode(int *number, int(*equals)(void *, void *)) {
	//Malloc for struct ObjectNode and copy value and equals method appropirately.

	struct ObjectNode* newNode = (struct ObjectNode *)malloc(sizeof(struct ObjectNode));

	void * temp = (void *)&number;

	newNode->value = temp;
	newNode->equals = equals;

	return newNode;
}



// sorting i.e implementing own quickSort

void quickSort(struct ObjectNode ** objectNodes1, int left, int right) {

	struct ObjectNode * temp;

	if (right <= left)
		return;

	if (objectNodes1[right]->value < objectNodes1[left]->value) {

		temp = objectNodes1[right];
		objectNodes1[right] = objectNodes1[left];
		objectNodes1[left] = temp;
	}

	int pLow = left + 1;
	int pHigh = right - 1;
	int i = left + 1;

	while (i <= pHigh) {

		if (objectNodes1[i]->value < objectNodes1[left]->value) {

			temp = objectNodes1[i];
			objectNodes1[i++] = objectNodes1[pLow];
			objectNodes1[pLow++] = temp;
		}
		else if (objectNodes1[right]->value < objectNodes1[i]->value) {
			temp = objectNodes1[i];
			objectNodes1[i] = objectNodes1[pHigh];
			objectNodes1[pHigh--] = temp;
		}
		else i++;
	}

	temp = objectNodes1[left];
	objectNodes1[left] = objectNodes1[--pLow];
	objectNodes1[pLow] = temp;

	temp = objectNodes1[right];
	objectNodes1[right] = objectNodes1[++pHigh];
	objectNodes1[pHigh] = temp;

	quickSort(objectNodes1, left, pLow - 1);

	if (objectNodes1[pLow]->value < objectNodes1[pHigh]->value)
		quickSort(objectNodes1, pLow + 1, pHigh - 1);

	quickSort(objectNodes1, pHigh + 1, right);
}





/*
@objectNodes1 -> Array1 of ObjectNodes pointing to values of same datatype.
@objectNodes2 -> Array1 of ObjectNodes pointing to values of same datatype.
@len1 -> length of objectNodes1
@len2 -> length of objectNodes2
@commonElementsLength -> final result array length which needs to be copied, it is already initialied, just copy the value.
*/
struct ObjectNode ** combine_common_elements(struct ObjectNode ** objectNodes1, struct ObjectNode ** objectNodes2, int len1, int len2, int *commonElementsLength) {


	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;

	bool flag = true;

	struct ObjectNode ** result = (struct ObjectNode **)malloc(sizeof(struct ObjectNode *) * 100);
	/*
	quickSort(objectNodes1, 0, len1 - 1);
	quickSort(objectNodes2, 0, len2 - 1);

	while (i < len1 && j<len2){

	if (objectNodes1[i]->value < objectNodes2[j]->value)
	i++;

	else if (objectNodes2[j]->value < objectNodes1[i]->value)
	j++;

	else{
	result[k++] = objectNodes1[i];
	i++;
	}

	if (objectNodes1[i] == objectNodes1[i + 1] && i < len1)
	i++;

	}
	(*commonElementsLength) = k;
	return result;
	}
	*/

	for (i = 0; i < len1; i++){

		flag = true;

		for (j = 0; j < len2; j++){

			if (equalsInt1((void *)objectNodes1[i]->value, (void *)objectNodes2[j]->value)){

				for (k = 0; k < l; k++){

					if (equalsInt1((void *)result[k]->value, (void *)objectNodes2[j]->value)){

						flag = false;
						break;


					}
				}
				if (flag){

					result[l++] = objectNodes1[i];
					
				}

			}
		


		}
	}
	(*commonElementsLength) = l;
	return result;
}

void test_combine_common_elements() {
	/*
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 6, 7, 8, 9, 10, 0, 0, 1, 2, 3 };
	int len1 = 10;
	int len2 = 10;
	struct ObjectNode ** intvalues1 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len1);
	struct ObjectNode ** intvalues2 = (struct ObjectNode **) malloc(sizeof(struct ObjectNode *)*len2);
	//Copy &arr[0] into intValues1 &arr[2] into intValues[2], same for intvalues2 too
	//Get Combined array of ObjectNodes
	//Print the values, using printInt method.
	*/

}
