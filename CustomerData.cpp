//Customer Data Program .cpp file
#include <iostream>
#include <string>
#include "CustomerData.h"
using namespace std;

//Amount of customers array
const int SIZE = 20;

//Create an object from the Customer structure
CustomerAccountInfo customers[SIZE];
CustomerAccountInfo customer;

int main()
{
	int option;        //choice variable
	int count = 0;         //counter variable
	int customerCount = 0;     //counter for the customer
	string theFullName;    //full name of the customer
	int change;           //so that the information can be changed

	//Greeting
	do 
	{
		cout << "********************************************************************\n";
		cout << "--------Welcome to the Customer Program Main Menu.--------\n";
		cout << "********************************************************************\n";
		cout << endl;
		cout << "**********************************************\n";
		cout << "1. Enter New Account information             *\n";
		cout << "2. Change Account Information                *\n";
		cout << "3. Display all Account Information           *\n";
		cout << "4. Exit the program                          *\n";
		cout << "**********************************************\n";
		cout << "Please enter your choice: ";
		cin >> option;

		//input validation
		while (option < 1 || option > 4)
		{
			cout << "Error! This is an invalid option. Please select a value between 1 & 4\n";
			cout << "Please enter your choice: ";
			cin >> option;
		}

		switch (option)
		{
		case 1:
			customers[count] = ProcessInfo(customer);
			cout << "You have successfully entered information for Customer #" << count << endl;
			count++;
			customerCount = count;
			break;
		case 2:
			cout << "Please enter a customer #: ";
			cin >> count;
			
			//Display the information for this customer
			cout << "Customer's name: " << customers[count].name << endl;
			cout << "Customer's address: " << customers[count].address << endl;
			cout << "City: " << customers[count].city << endl;
			cout << "State : " << customers[count].state << endl;
			cout << "Zip Code: " << customers[count].zipCode << endl;
			cout << "Customer's Telephone Number: " << customers[count].telephoneNum << endl;
			cout << "Customer's date of last payment: " << customers[count].date << endl;
			cout << "Customer's Account Balance: " << customers[count].accountBalance << endl;

			//Change the information
			cout << endl << "Please enter the full name of the customer to be modified: ";
			cin.ignore();
			getline(cin,theFullName);
			cin.ignore();

			change = getCustNum(customers, count, theFullName);

			//input validation
			if (change == -1)
				cout << "This is the wrong name to change\n";
			else
				customers[change] = ProcessInfo(customer);
			break;
		case 3:
			DisplayDetails(customers, customerCount);
			break;
		case 4:
			cout << "You have chosen to exit the program. Have a nice day!\n";
			exit(0);
			break;
		}
	} while (option != 4 && count < SIZE);

	system("pause");
	return 0;
}

//Function for entering and processing the data
CustomerAccountInfo ProcessInfo(CustomerAccountInfo &obj)
{
	    //Name
	    cin.ignore();
		cout << "Enter the Customer's name: ";
		getline(cin, obj.name);
		cin.ignore();

		//Address
		cin.ignore();
		cout << "Enter the Customer's address: ";
		getline(cin, obj.address);
		cin.ignore();

		//City
		cin.ignore();
		cout << "Enter the Customer's city: ";
		getline(cin, obj.city);
		cin.ignore();

		//State
		cin.ignore();
		cout << "Enter the Customer's state: ";
		getline(cin, obj.state); 
		cin.ignore();

		//Zip Code
		cin.ignore();
		cout << "Enter the Customer's Zip Code: ";
		getline(cin, obj.zipCode);
		cin.ignore();

		//Telephone Number
		cin.ignore();
		cout << "Enter the Customer's Telephone number: ";
		getline(cin, obj.telephoneNum);
		cin.ignore();

		//Date of the Last Payment
		cin.ignore();
		cout << "Enter the Customer's Date of Last Payment: ";
		getline(cin, obj.date);
		cin.ignore();

		cin.ignore(256, '\n');

		//Remaining account balance
		cout << "Enter the Customer's remaining account balance: ";
		cin >> obj.accountBalance;

		cin.ignore(256, '\n');

		//input validation
		if (obj.accountBalance < 0)
		{
			cout << "Error! A negative balance is invalid.\n";
			cout << "Please enter a positive value: ";
			cin >> obj.accountBalance;
		}

		return obj;
}

//Function which returns the customer number
int getCustNum(CustomerAccountInfo cust[], int size, string name)
{
	int custNum = -1;
	for (int index = 0; index <= size; index++)
	{
		if (cust[index].name == name)
		{
			custNum = index;
			break;
		}
	}
	return custNum;
}

//Function which displays the customer information
void DisplayDetails(CustomerAccountInfo obj[], int size)
{
	//This is if there are no customers added
	if (size == 0)
	{
		cout << "No customers in the array to display.\n";
	}
	else 
	{
		//Uses a for loop to display each customer's information
		for (int index = 0; index < size; index++)
		{
			cout << "Customer's name: " << obj[index].name << endl;
			cout << "Customer's address: " << obj[index].address << endl;
			cout << "City: " << obj[index].city << endl;
			cout << "State : " << obj[index].state << endl;
			cout << "Zip Code: " << obj[index].zipCode << endl;
			cout << "Customer's Telephone Number: " << obj[index].telephoneNum << endl;
			cout << "Customer's date of last payment: " << obj[index].date << endl;
			cout << "Customer's Account Balance: " << obj[index].accountBalance << endl;
		}
	}
}