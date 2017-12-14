/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void lowerCase(char* str){

	int i = 0;

	while (str[i] != '\0'){

		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;

		i++;
	}
}



bool checkEmailCase1(char* email){


	int c1 = 0;
	int c2 = 0;
	int i = 0;
	int p1 = -1;
	int p2 = -1;
	bool check1 = false;
	bool check2 = false;

	while (email[i] != '\0'){


		if (email[i] == '_'){


			i++;
			continue;
		}

		if (email[i] == '-'){

			i++;
			continue;
		}
		if (email[i] == ' '){

			i++;
			continue;
		}

		if (email[i] == 64){

			printf("\n1");
			if (c1 == 0){
				c1++;
				p1 = i;
				check1 = true;
				i++;
			}
			else{

				return false;

			}
		}
		else if (email[i] == '.'){
			printf("\n2");

			if (c2 == 0){
				check2 = true;
				p2 = i;
				i++;
			}

			else if (c1 == 1 && i>p1 + 1){
				check2 = true;
				i++;

			}
			else
				return false;
		}
		else{
			
			if ((email[i] >= 'a' && email[i] <= 'z')){

				i++;
			
			}
			else if (email[i] >= 'A' && email[i] <= 'Z')
				i++;

			else if (email[i] >= '0' && email[i] <= '9')
				i++;
			else{

			
				return false;
			}

		}

	}

	

	if (p2 == i)
		return false;

	if (p2 < p1 || (p2 - p1) == 1)
		return false;

	if (check1 == false || check2 == false)
		return false;

	else

		return true;




}

int findAt(char* email){

	int i = 0;

	while (email[i] != '\0'){

		if (email[i] == '@')
			return i;

		i++;
	}

	return -1;

}



int isValidEmail(char *email){

	
	//variable email is in form of "name something@domain.server"
	int check = false;



	if (checkEmailCase1(email)){
		
		check = true;
	}
	else
		return 0;

	int i = 0;
	int j = 0;
	char* name = (char*)calloc(100, sizeof(char));
	char* id = (char*)calloc(300, sizeof(char));
	int nameLen;
	int idLen = 0;
	int loc;
	bool flag = false;

	while (email[i] != ' '){

		name[i] = email[i];
		i++;
	}

	name[i] = '\0';
	nameLen = i;


	i++;

	while (email[i] != '\0'){

		id[j++] = email[i];
		i++;

	}

	id[j] = '\0';
	idLen = j;

	if (idLen > 254)
		return 0;

	lowerCase(name);
	lowerCase(id);

	if (id[0] == '_' || id[0] == '-' || id[0] == '.')
		return 0;
	
	loc = findAt(id);

	i = 0;

	

	while (i<nameLen){

		

		if (id[i] == name[i]){

			if (id[i] == ' ')
				return 0;

			if (i == nameLen - 1){
				flag = true;
			}
		}

		else
			break;

		i++;

	}


	if (flag == false){

		
		i = loc - 1;
		j = nameLen - 1;

		while (true){

			if (id[i--] == name[j--]){

				if (id[i] == ' ')
					return 0;

				if (j == 0)
					flag = true;

			}
			else
				break;

		}


	}


	if (flag == true && check == true)
		return 2;

	return 1;

}

