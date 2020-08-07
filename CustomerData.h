//Customer Data header file
#pragma once
#ifndef CustomerData_H
#define CustomerData_H

#include<iostream>
#include <string>
using namespace std;

//Customer Account structure
struct CustomerAccountInfo
{
	//Customers information
	string name, address, city, state, date, telephoneNum, zipCode;
	double accountBalance;

};

//function prototypes
CustomerAccountInfo ProcessInfo(CustomerAccountInfo&);
void DisplayDetails(CustomerAccountInfo[], int);
int getCustNum(CustomerAccountInfo[], int, string);

#endif // !Customer_H
