/*
            ======================================================
            + Name        : mastermind.c                         +
            + Author      : Christos Z, 			             +
            + Description : Mastermind game                      +
            ======================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int digitCount(int number);								/*Declare functions */
char conversion(int number);
int repeatedDigits(int number);									
int commonDigits(char [],char [],int digitsnumber);
int spotDigits(char [],char [],int digitsnumber);
void showResults(int commonnumbers,int commonnumberscommonplaces,int digitsnumber);

int main()
{	
	srand(time(NULL));
	int i,duplicate_variable,number_of_tries,common_numbers,common_numbers_common_places;											/*Declare variable*/
	char appear_number_answer,duplicateanswer,A[10],B[10];			
	int digits_number,HiddenNumber,playersguess,count_number,players_number;
	int Secret;
	
	printf("Welcome to the secret number game!\n\n");
	do																			/* Give number in range 3 to 5 digits*/	
	{
		printf("How many digits do you want to use (3-5)? ");
		scanf("%d", &digits_number);
	}
	while(!(digits_number>=3 && digits_number<=5));
	
	if(digits_number==3)									/*rand is activated, returns a value depending on the value given by the user for the digits of the secret number*/
	{	
		do
		{												/*Check values in range 100-999 for 3 digits*/
			HiddenNumber=rand()%1000;
		}
		while(HiddenNumber<100);
	}
	else if(digits_number==4)							/*Check values in range 1000-9999 for 4 digits*/
	{
		do
		{											
			HiddenNumber=rand()%10000;					
		}
		while(HiddenNumber<1000);
	}
	else if(digits_number==5)
	{		
		do
		{													/*Check values in range 10090-99999 for 5 digits*/
			HiddenNumber=rand()%100000;
		}
		while(HiddenNumber<10000);
	}	
	printf("Do you want duplicate digits(y/n)? ");				/*Check for number with duplicate digits*/
	scanf(" %c", &duplicateanswer);
	
	if(duplicateanswer=='N'||duplicateanswer=='n')						/*For negative answer, check number for duplicates*/
	{
		duplicate_variable=repeatedDigits(HiddenNumber);							/*Find new secret number till secret number has no duplicate digits*/	
		if(digits_number==3)															
		{		
				while(duplicate_variable==1)
				{
					do
					{
						HiddenNumber=rand()%1000;
					}while(HiddenNumber<100);										/*Find new secret with no duplicate for 3digit number*/
					duplicate_variable=repeatedDigits(HiddenNumber);
						
				}
		}
		else if(digits_number==4)											/*Find new secret with no duplicate for 4digit number*/
		{
			while(duplicate_variable==1)
			{
				do
				{
					HiddenNumber=rand()%10000;
				}while(HiddenNumber<1000);
				duplicate_variable=repeatedDigits(HiddenNumber);
			}
		}
		else if(digits_number==5)										/* Find new secret with no duplicate for 5digit number*/
		{
				while(duplicate_variable==1)
				{	
					do
					{
						HiddenNumber=rand()%100000;
					}while(HiddenNumber<10000);
					duplicate_variable=repeatedDigits(HiddenNumber);	
				}
		}																			/*Answer yes, secret number may have or may have not duplicates*/
	}
	
	printf("Do you want to see the secret number(y/n)? ");					/*See the secret number (hihi)*/
	scanf(" %c", &appear_number_answer);
	if(appear_number_answer=='Y' ||appear_number_answer=='y' )				
		printf("The secret number is %d\n\n", HiddenNumber);
		
	Secret=HiddenNumber;
	number_of_tries=0;													/* Assign the value of the hidden number to another variable so that when the hidden number is assigned as an alphanumeric in the table it is not lost*/
	for(i=0;i<10;++i)
		A[i]=0;													/*Resetting a table  (random length)*/
	
	for(i=0; i<10; ++i)
	{
		A[i]=conversion(HiddenNumber);						/*ekxoroume stin proti thesi tou pinaka to teleutaio psifiou tou arithmou*/
		HiddenNumber/=10;											/*Divide the hidden number each time so that in the next iteration we get the next digit from the end*/
 	}

	
	
	
	do
	{
		
		do
		{	
			
			printf("Give your guess(negative to quit) ");						/*The player plays. Obeys what he has stated, otherwise he gets a message*/
			scanf("%d", &playersguess);
			count_number=digitCount(playersguess);											
			duplicate_variable=repeatedDigits(playersguess);
			if(playersguess<0)
			{
                printf("The players has quited after %d tries",number_of_tries);              
				printf("\nThe secret number was %d\n", Secret);							/*Negative answer, terminates the program with no_of tries*/
				
				Sleep(3000);
				return 0;
			}
			if((duplicateanswer=='N'||duplicateanswer=='n') && duplicate_variable==1)
			{
				do
				{
					printf("Give your guess(negative to quit) ");				/*repeatedDigits*/
					scanf("%d", &playersguess);
					count_number=digitCount(playersguess);
					duplicate_variable=repeatedDigits(playersguess);			/*User guess the secret number. The count of digits for the secret number and the guess number must be equal*/
				}while(duplicate_variable==1);
			}													/* Wrong guess. Asks user to give next guess*/			
		}while(count_number!=digits_number );
		players_number=playersguess;												
																	/*Assign the value of the player to another variable so that its value is not lost after the successive divisions required to assign it as an alphanumeric to the table*/ 
				
		for(i=0;i<10;++i)											/*fill a second table (random length)*/
			B[i]=0;		
		
		
 		for(i=0; i<10; ++i)
		{
			B[i]=conversion(playersguess);							/* enter the last digit of the number as an alphanumeric using the conversion function in the first cell of the table*/
			playersguess/=10;										/*successive cells too*/
 		}	
															/*auxiliary variable to keep the user's answer*/
		



		common_numbers_common_places=spotDigits(A,B,digits_number);						/*Func spotDigits finds digits in same position*/
		common_numbers=commonDigits(A,B,digits_number);								/*Func commonDigits finds equal digits*/
		
		showResults(common_numbers,common_numbers_common_places,digits_number);			/*Func showResults shows notification of how close the player's answer is to the secret number*/	
	
	
		number_of_tries+=1;																/*  no_of tries counter*/
		
	}while(Secret!=players_number);
																				/*Secret=players_number means player wins . Right guess*/
	if(Secret=players_number)
	{
        printf("You found the secret number after %d guesses",number_of_tries);                     
		printf("\nSecret Number was found: %d\n", Secret);									/*Print info*/
        Sleep(3000);					
	}
	return 0;
}
	


/*
Function repeatedDigits checks if a number has duplicate digits or not
*/

int repeatedDigits(int number)
{
    int digit_seen[10]={0};
    int digit,c;
    													/*h sinartisi repeatedDigits elegxei an enas arithmos exei dipla psifia h oxi*/
    													/*a number can be used or not depending on the player's answer*/
    while (number>0) 
	{
          digit = number%10;
          if (digit_seen[digit])
             break;
          digit_seen[digit] = 1;
          number/=10;
    }
    if (number>0)
    {
       		c=1;										/*We keep at a value the result of the function*/
   	}
    else
	{														/*c=1 has duplicates*/
    	   c=0;
    }														/*c=0 no duplicates*/
  	 return c;
}

/*
Function conversion ôakes a number as argument and converts it to an alphanumeric
*/
char conversion(int number)
{
	int digit;									
	digit=number%10;
	digit=digit +'0';
	return digit;
}

/*
Function showResults displays an appropriate indication according to the results of the guesswork
*/
void showResults(int commonnumbers,int commonnumberscommonplaces,int digitsnumber)
{
	if(commonnumbers<=digitsnumber/2)
		printf("Not so good guess...\n");															
	else if(commonnumbers>digitsnumber/2 && commonnumberscommonplaces<=digitsnumber/2)						
		printf("Good guess!\n");
	else if(commonnumberscommonplaces==digitsnumber)
		printf("Excellent! You found it!\n");
	else if(commonnumberscommonplaces>digitsnumber/2)
		printf("You are in the right path!\n");
	
	printf("Total number of digits found: %d\n", commonnumbers);
	printf("Digits found in correct position: %d\n\n", commonnumberscommonplaces);
}
	



/*
Function digitCount Calculates the number of digits in a number
*/
	
int digitCount(int number)				{
	int count=0;
	while(number!=0)					/*As long as the number is different from zero, it is undersampled so I take the last digit*/
	{
   		number/=10;          
   		++count;					/*Counter increases till number gets zero value*/
	}
  	return count;
}
	
	
/*
Function commonDigits calculates how many digits the numbers have in common
*/
int commonDigits(char A[],char B[],int digitsnumber)
{
	int i,j,commonnumbers,found;				
	commonnumbers=0;

	for(j=0;j<digitsnumber ;j++)
	{
		found=0;
		for (i=0,found=0; (!found) && (i<digitsnumber); i++)
		{																	/*Serial search variant*/
			if (A[j]==B[i])
			{
																		/*Assign another value to the cell of table B that is the same as that of table A so that if table A has 2 or more times the same digit you do not check twice*/ 
				found=1;
				commonnumbers+=1;
				B[i]=B[5+i]+10;											/*We change the value of cell B so that after finding once that it is common with a cell of table A */
																		/*if there is another time it will not find the first common but will look for a second digit (we add a random value)*/
			}
			
		}
	}
	return commonnumbers;
}
	
/*
Function spotDigits calculates which digits two numbers have in the same positions
*/
int spotDigits(char A[],char B[],int digitsnumber)
{																			
	int i,j,commonnumberscommonplaces,found;
	commonnumberscommonplaces=0;												/*Serial search variant*/
	{
		
		for(i=0, j=0; (i<digitsnumber); i++, j++ )
		{
			if(j==i)
			{												
				if(A[j]==B[i])													
					commonnumberscommonplaces+=1;
			}
		}
	}	
	return commonnumberscommonplaces;	
}
	
	
