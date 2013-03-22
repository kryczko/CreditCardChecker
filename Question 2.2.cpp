/*This program prompts the user to enter an 8 digit credit card 
number and then tell the user whether or not the credit card is valid
*/

#include <iostream>
#include <string>

using namespace std; 

int main()
{
	//define the variable to determine whether the user wants to quit
	//or check another card.
	string restart;

	//Do-While loop so the user has an option to quit or to enter
	//another card number.
	do
	{
	int credit_card_number, first_digit, second_digit, third_digit, fourth_digit, 
		fifth_digit, sixth_digit, seventh_digit, eighth_digit;

	//prompt the user to enter the 8 digit credit card number
	cout << "Please enter your 8 digit credit card number:";
	cin >> credit_card_number;

	//Seperating the 8 digit credit card number into individual digits
	eighth_digit = (credit_card_number) % 10;
	seventh_digit = (credit_card_number / 10) % 10;
	sixth_digit = (credit_card_number / 100) % 10;
	fifth_digit = (credit_card_number / 1000) % 10;
	fourth_digit = (credit_card_number / 10000) % 10;
	third_digit = (credit_card_number / 100000) % 10;
	second_digit = (credit_card_number / 1000000) % 10;
	first_digit = (credit_card_number / 10000000) % 10;

	//Defining the first sum of numbers for the check
	int first_sum;
	first_sum = eighth_digit + sixth_digit + fourth_digit + second_digit;

	//If statements to for the second sum
	if (first_digit >= 5)
	{
		first_digit = 1 + first_digit * 2 - 10;
	}
	else
	{
		first_digit = first_digit * 2;
	}
	if (third_digit >= 5)
	{
		third_digit = 1 + third_digit * 2 - 10;
	}
	else
	{
		third_digit = third_digit * 2;
	}
	if (fifth_digit >= 5)
	{
		fifth_digit = 1 + fifth_digit * 2 - 10;
	}
	else
	{
		fifth_digit = fifth_digit * 2;
	}
	if (seventh_digit >= 5)
	{
		seventh_digit = 1 + seventh_digit * 2 - 10;
	}
	else
	{
		seventh_digit = seventh_digit * 2;
	}

	//defining the second sum
	int second_sum;
	second_sum = first_digit + third_digit + fifth_digit + seventh_digit;
	
	//defining the final sum
	int final_sum;
	final_sum = first_sum + second_sum;
	
	//defining the check of the credit card
	int decision = final_sum % 10;

	string validity;

	// The check to see if the credit card is valid or not
	if (decision == 0)
	{
	  validity = "valid.";
	}
	else
	{
		validity = "invalid.";
	}

	//tells the user whether or not the credit card is valid and asks if they want to check another number or quit
	cout << "\nThe credit card number you entered is " << validity 
		<< "\n\nIf you would like to check another credit card number press C. If you would like to quit press Q.\n\n";
	
	cin >> restart;
	cout << "\n\n";
	}
	while(restart == "C");
	
	//terminates the program
	if (restart == "Q")
	{
	return 0;
	}
}