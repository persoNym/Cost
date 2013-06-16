/* 
@title				me.c
@description			Cost estimate emulation to fulfil section A && B of homework
@author				Victoria C
@version 			1.done	
@ last revised 			01/26/13
*/


#include <stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdbool.h>


typedef char* string;

int main(void)
{
	string name[5] = {"Oil filter","Spark plug","Engine","Gas light","Done"}; 
	float price[5] = {20.00, 50.00,150.00,35.00,0.0}; 
	bool userDone = false; //to ensure that the cases loop until input is done
	float tax = .06; 
	float taxOutput; //for the calculation of the final tax
	int choice, quantity,i;
	int selectedQuantity[4] = {0,0,0,0}; //array to store the quantity and is set to zero to prevent garbage
		
	while (!userDone) 
	{
	printf( "\n ~~~~~~~~~~ Auto Parts Menu ~~~~~~~~~~\n" ); //menu statement selection
	puts( "-------------------------------------------------" ); 
		for(i=0;i<5;++i)
		{
		printf("   %i. %s:$%.2f\n", i+1, name[i], price[i]);
		}
	
	
	printf("Please select 1, 2, 3, 4 and enter the quantity. Select 5 twice to end.\n"); //to be able to select from menu
	scanf("%d %d",&choice,&quantity);

		while(choice < 1 || choice > 5 || quantity < 1 ) //for validation to ensure it is in good range
		{
			printf("Invalid Option!\n");
			scanf("%d %d",&choice,&quantity);
		}
	
	
				switch(choice) 
				{
					case 1:
						selectedQuantity[0] += quantity; //to set the quantity in the empty array in order to be 							referred to again after
						break;
					case 2:
						selectedQuantity[1] += quantity;
						break;
					case 3:
						selectedQuantity[2] += quantity;
						break;
					case 4:
						selectedQuantity[3] += quantity;
						break;
					case 5:
						userDone = true; //done statement
						puts("fulfiling 'Finish and Pay' request...\n");
						break;
				}
		}

		puts("You have:");
		printf("%d %s(s)\n", selectedQuantity[0],name[0]); //outputs the quantity ammount by pulling it from the user inputed array
		printf("%d %s(s)\n", selectedQuantity[1],name[1]);
		printf("%d %s(s)\n", selectedQuantity[2],name[2]);
		printf("%d %s(s)\n", selectedQuantity[3],name[3]);
		printf("sales tax percentage is: %f\n", tax);
		taxOutput = tax * (price[0] * selectedQuantity[0]) + (price[1] * selectedQuantity[1]) + (price[2] * selectedQuantity[2])
				+ (price[3] * selectedQuantity[3]); //formula to compute the tax
		printf("Your total price is: $%.2f", taxOutput + (price[0] * selectedQuantity[0]) + (price[1] * selectedQuantity[1]) 
		+ (price[2] * selectedQuantity[2])+ (price[3] * selectedQuantity[3])); //formula to add tax and items for final price
		printf("\nPlease proceed to checkout\n");

		
return 0;
}

