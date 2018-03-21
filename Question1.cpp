/*THE QUESTION IS THAT

The phone numbers of the companies are stored in the phones.txt. The area codes are missing in some of the phone
numbers. (A phone number including area code is 10 characters). You will write a program to format phone numbers
and add area code if necessary. At the end all the phone numbers will look like the following; (312) 4250204.
Write the following functions;

• readFromFile that reads all the phone numbers from the file phones.txt into a string array. The function should
return the number of phones.

• updateDirectory that takes the string array which keeps the phone numbers and the number of phones in the
array as parameters, and updates the phone numbers adding the parentesis and area code (312) where necessary
(i.e (312) 4250204).

• printDirectory that takes the string array which keeps the phone numbers and the number of phones in the
array as parameters, and displays the number of phones and the phone list on the screen.

*/
#include <stdio.h>
#include <string.h>

void readFromFile(FILE *fp, char pho[][15],int *nmb) // this function using for get values which are the numbers in phones.txt
{
	int i =0;
	for(i;fscanf(fp,"%s",pho+i)!=EOF;i++); //get value with string line by line and set to array
	*nmb = i; //total number of information in phones.txt
}
void updateDirectory(char pho[][15],int size) // this function using for update
{	
	char tmp[15] = "(312) "; //this is temporary char array	
	for(int i = 0;i<size;i++)
	{	
		if(strlen(*(pho+i)) < 8) // if value in the array has not area code 
		{
		strcat(tmp,*(pho+i)); //tmp include (312) and *(pho+i) (this mean pho[i]) include numbers, so new tmp is like (312) xxxxxxx
		strcpy(*(pho+i),tmp); //copy tmp to pho[i]
		strcpy(tmp,"(312) "); //clear the temporary char array
		}
		else //if the number has area code like 312xxxxxxx 
		{
		strcat(tmp,*(pho+i)+3);
		strcpy(*(pho+i),tmp);
		strcpy(tmp,"(312) ");
		}
	}
}

void printDirectory(char ar[][15],int size) //this function using for the print values in the array
{
	printf("There are %d phone numbers in the directory.\n",size);
	for(int i = 0;i<size;i++)
	printf("%s\n",*(ar+i));
	
}
int main()
{
	int number; //set the number of size in documentary
	char pho[15][15]; //this is main array
	FILE *fp = fopen("phones.txt","r");
	readFromFile(fp,pho,&number);
	updateDirectory(pho,number);
	printDirectory(pho,number);
	
	return 0;
}
