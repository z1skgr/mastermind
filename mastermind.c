/* Χρήστος Ζήσκας 2014030191*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countdigits(int number);								/*Diloseis sinartiseon pou xrisimopoiountai sto programma*/
char conversion(int number);
int functionduplicate(int number);									/*Prototipa sinartiseon*/
int comparison1(char [],char [],int digitsnumber);
int comparison2(char [],char [],int digitsnumber);
void resultcomparison(int commonnumbers,int commonnumberscommonplaces,int digitsnumber);

int main()
{	
	srand(time(NULL));
	int i,duplicate_variable,number_of_tries,common_numbers,common_numbers_common_places;											/*orismos ton metavliton*/
	char appear_number_answer,duplicateanswer,A[10],B[10];			
	int digits_number,HiddenNumber,playersguess,count_number,players_number;
	int Secret;
	
	printf("Welcome to the secret number game!\n\n");
	do																			/* epanaprosdiorismos tou arithmou ton psifion efoson den dothei o zitoumenos arithmos apo 3 mexri 5*/	
	{
		printf("How many digits do you want to use (3-5)? ");
		scanf("%d", &digits_number);
	}
	while(!(digits_number>=3 && digits_number<=5));
	
	if(digits_number==3)									/*energopoihte h rand kai epistrefei timi analoga me thn timi pou exei dosei o xristis gia ta psifia tou mystikou arithmou*/
	{	
		do
		{												/*elegxos gia tis times oste na epistrefonte times apo 100-999*/
			HiddenNumber=rand()%1000;
		}
		while(HiddenNumber<100);
	}
	else if(digits_number==4)							/*elegxos gia tis times oste na epistrefonte times apo 1000-9999*/
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
		{													/*elegxos gia tis times oste na epistrefonte 5psifies times*/
			HiddenNumber=rand()%100000;
		}
		while(HiddenNumber<10000);
	}	
	printf("Do you want duplicate digits(y/n)? ");				/*erotate o xristis an epithimei na diathetei dipla psifia o krifos arithmos*/
	scanf(" %c", &duplicateanswer);
	
	if(duplicateanswer=='N'||duplicateanswer=='n')						/*gia arnitiki apantisi elegxontai ta psifia tou mistikou arithmou*/
	{
		duplicate_variable=functionduplicate(HiddenNumber);							/*An o mistikos arithmos diathetei epanalamvanomena psifia tote o mistikos arithmos alazei mexri na dwthei o katallilos arithmos*/	
		if(digits_number==3)															/*xoris psifia pou epanalamvanontai*/
		{		
				while(duplicate_variable==1)
				{
					do
					{
						HiddenNumber=rand()%1000;
					}while(HiddenNumber<100);										/*allagi tou 3psifiou mystikou arithmou an an o xristis dn epithimei dipla psifia se auton*/
					duplicate_variable=functionduplicate(HiddenNumber);
						
				}
		}
		else if(digits_number==4)											/*allagi tou 4psifiou mystikou arithmou an o xristis dn epithimei dipla psifia se auton*/
		{
			while(duplicate_variable==1)
			{
				do
				{
					HiddenNumber=rand()%10000;
				}while(HiddenNumber<1000);
				duplicate_variable=functionduplicate(HiddenNumber);
			}
		}
		else if(digits_number==5)										/* allagi tou 5psifiou mystikou arithmou an o xristis dn epithimei dipla psifia se auton*/
		{
				while(duplicate_variable==1)
				{	
					do
					{
						HiddenNumber=rand()%100000;
					}while(HiddenNumber<10000);
					duplicate_variable=functionduplicate(HiddenNumber);	
				}
		}																			/*Gia thetiki apantisi o krifos arithmos den einai aparaithto na exei dipla psifia kata anagki*/
	}
	
	printf("Do you want to see the secret number(y/n)? ");					/*epithimia tou pexti an thelei na dei ton mystiko arithmo(gia epalitheusi)*/
	scanf(" %c", &appear_number_answer);
	if(appear_number_answer=='Y' ||appear_number_answer=='y' )				/* gia thetiki apantisi emfanizete o mystikos arithmos*/
		printf("The secret number is %d\n\n", HiddenNumber);
		
	Secret=HiddenNumber;
	number_of_tries=0;													/* ekxoroume thn timh tou krifou arithmou se mia alli metavliti etsi oste na otan ekxorithei o krifos os alfarithmitiko ston pinaka na min xathei*/
	for(i=0;i<10;++i)
			A[i]=0;													/*midenizoume ena  pinaka A 8theseon( to megethos tou pinaka einai tixaio)*/
	
	for(i=0; i<10; ++i)
		{
			A[i]=conversion(HiddenNumber);						/*ekxoroume stin proti thesi tou pinaka to teleutaio psifiou tou arithmou*/
			HiddenNumber/=10;											/*dieroume kathe fora to krifo arithmo oste stin epomeni epanalipsi na paroume to epomeno psifio apo to telos*/
 		}

	
	
	
	do
	{
		
		do
		{	
			
			printf("Give your guess(negative to quit) ");						/*o pextis ekxorei thn apantisi tou pou prepei na ipakouei stis apantiseis pou exei dwsei parapanw*/
			scanf("%d", &playersguess);
			count_number=countdigits(playersguess);											
			duplicate_variable=functionduplicate(playersguess);
			if(playersguess<0)
			{
				printf("The secret number was %d\n", Secret);							/*h ekxorisi arnitikou arithmou prokalei termatismo tou paixnidiou akolouthoumeno apo tis prospathies tou pexti*/
				printf("The players has quited after %d tries",number_of_tries);
				return 0;
			}
			if((duplicateanswer=='N'||duplicateanswer=='n') && duplicate_variable==1)
			{
				do
				{
					printf("Give your guess(negative to quit) ");				/*h arnitiki apantisei sta dipla psifia elegxei ton arithmo anigontas tin sinartisi functionduplicate*/
					scanf("%d", &playersguess);
					count_number=countdigits(playersguess);
					duplicate_variable=functionduplicate(playersguess);							/*h apantisi tou xristi tha prepei na exei idio arithmo psifion me ton krifo arithmo.Gia to skopo auto xrisimopoieite h sinartisi countdigits*/
				}while(duplicate_variable==1);
			}													/* an ta psifia tou krifou arithmou kai tis apantisis tou pexti diaferoun o pextis dinei xana arithmo*/			
		}while(count_number!=digits_number );
		players_number=playersguess;												
																	/*ekxoreite h timi tou paixti se mia alli metavliti oste na min xanete h timi tis meta tis diadoxikes diereseis pou apaitounte gia na ekxoreithi os alfarithmitiko ston pinaka*/ 
				
		for(i=0;i<10;++i)											/*gemizoume ena deutero pinaka B 8theseon me 0 (to megethos tou pinaka tixaio)*/
			B[i]=0;		
		
		
 		for(i=0; i<10; ++i)
		{
			B[i]=conversion(playersguess);							/*to teleutaio psifio tou arithmou eisagete os alfarithmitiko me thn voithia tis sinartisis convension sto prwto keli tou pinaka*/
			playersguess/=10;										/*diadoxika gemisoun me ton idio tropo ta epomena kelia*/
 		}	
															/*voithitiki metavliti gia na diatirisoume tin apantisi pou edwse o xristis*/
		



		common_numbers_common_places=comparison2(A,B,digits_number);						/*energopoieite h sinartisi comparison2 pou vriskei pia psifia vriskontai sthn idia thesi*/
		common_numbers=comparison1(A,B,digits_number);								/*energopoieite h sinartisi comparison1 pou vriskei pia psifia ton 2 arithmon einai idia*/
		
		resultcomparison(common_numbers,common_numbers_common_places,digits_number);			/*h sinartisi resultcomparison emfanizei ta minina gia to poso konta apexei h apantisi tou pexti apo ton mistiko arithmo*/	
	
	
		number_of_tries+=1;																/* auxanontai h prospathies tou pexti*/
		
	}while(Secret!=players_number);
																				/*Secret=players_number simenei oti telika o xristis vrike ton krimeno arithmo*/
	if(Secret=players_number)
	{
		printf("Secret Number was found: %d\n", Secret);									/*epalitheusi oti o mistikos arithmos einai idios me thn apantisi pou edwse o pextis teleutaia*/
		printf("You found the secret number after %d guesses",number_of_tries);					/*h anafora euresis tou mistikou arithmou akolouthite apo ton arithmo prospathion tou pexti mexri na ton vrei*/
	}
	return 0;
}
	




int functionduplicate(int number)
{
    int digit_seen[10]={0};
    int digit,c;
    													/*h sinartisi functionduplicate elegxei an enas arithmos exei dipla psifia h oxi*/
    													/*gia na xeroume an enas arithmos exei dipla psifia h oxi xrisimopoioume mia topiki metavliti*/
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
       		c=1;										/*diatiroume se mia timi to apotelesma tis sinartisis*/
   	}
    else
	{														/*c=1 o arithmos diathetei epanalamvanomena psifia*/
    	   c=0;
    }														/*c=0 o arithmos dn diathetei epanalamvanomena psifia*/
  	 return c;
}

	char conversion(int number)
	{
		int digit;									/*h sinartisi conversion pernei ta  psifia tou arithmou kai ta metatrepei se alfarithmitika*/
		digit=number%10;
		digit=digit +'0';
		return digit;
	}

	
	void resultcomparison(int commonnumbers,int commonnumberscommonplaces,int digitsnumber)
	{
		if(commonnumbers<=digitsnumber/2)
			printf("Not so good guess...\n");															/*h sinartisis resultcomparison analoga me ton arithmo ton psifion pou einai idia kai ton */
		else if(commonnumbers>digitsnumber/2 && commonnumberscommonplaces<=digitsnumber/2)						/* arithmo ton psifion pou einai idia se koines thesis emfanizei analoga minimata*/
			printf("Good guess!\n");
		else if(commonnumberscommonplaces==digitsnumber)
			printf("Excellent! You found it!\n");
		else if(commonnumberscommonplaces>digitsnumber/2)
			printf("You are in the right path!\n");
	
	printf("Total number of digits found: %d\n", commonnumbers);
	printf("Digits found in correct position: %d\n\n", commonnumberscommonplaces);
	}
	



	
	int countdigits(int number)				/*Sinartisi pou ipologizei to plithos ton psifion enos arithmou*/
	{
		int count=0;
  		while(number!=0)					/*Oso o arithmos einai diaforos tou midenos ton ipodekaplasiazo ara pernw to teleutaio tou psifio*/
  		{
      		number/=10;          
      		++count;					/*Auxanete o metritis mexri o arithmos na ginei 0.Otan ginei o arithmos ginei 0 o metritis count exei os timi ton arithmo ton psifion tou arithmou*/
  		}
  		return count;
	}
	
	
	
	int comparison1(char A[],char B[],int digitsnumber)
	{
		int i,j,commonnumbers,found;				/*h sinartisi comparison1 ipologizei posa psifia exoun oi arithmoi koinous*/
		commonnumbers=0;
		;
		for(j=0;j<digitsnumber ;j++)
		{
			found=0;
			for (i=0,found=0; (!found) && (i<digitsnumber); i++)
			{																	/*paralagi tis seiriakis anazitisis*/
				if (A[j]==B[i])
				{
																			/*ekxoroume alli timi sto  keli tou pinaka B pou einai idio me auto tou pinaka A oste an o pinaka A exei 2 h perissoteres fores to idio psifio na min elegxete 2 fores*/ 
					found=1;
					commonnumbers+=1;
					B[i]=B[5+i]+10;											/*alazoume tin timi tou keliou B oste afou vrikame mia fora oti einai koino me kapio keli tou pinaka A */
																			/*an iparxei alli fora na min sinantisei to prwto idio koino alla na anazitisei an iparxei deutero psifio(prosthetoume tixaia to 10 gia na alaxoume to periexomeno tou keliou*/
				}
				
			}
		}
		return commonnumbers;
	}
	
	int comparison2(char A[],char B[],int digitsnumber)
	{																			/*h comparison2 ipologizei poia psifia tous exoun koina stis idies thesis*/
		int i,j,commonnumberscommonplaces,found;
		commonnumberscommonplaces=0;												/*paralagi tis seiriakhs anazitisis*/
		for(j=0;j<digitsnumber;j++)
		{
			found=0;
			for(i=0,found=0; (!found) && (i<digitsnumber); i++ )
			{
				if(j==i)
				{
					found=1;												/*elegxos an ta koina tous stoixeia einai stin idia thesi*/
					if(A[j]==B[i])													
						commonnumberscommonplaces+=1;
				}
			}
		}	
	return commonnumberscommonplaces;
	
	}
	
	
