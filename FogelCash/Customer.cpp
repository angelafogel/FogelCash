//Angela Fogel
//CS625 Cryptography
//Digital Cash Protocol #4
//Customer.cpp

//Implemenets the Customer class functions and provides class constructors

//Class to extract money order information from user and initialize 
//money order object through class constructor



#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include "Customer.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "cryptopp\osrng.h" // PRNG
using namespace CryptoPP;
using namespace std;

Customer::Customer()  //Default Constructor
{
	CustomerID="0";
	CustomerMOamt=0;
	numOrders = 5;
	customerMO.resize(numOrders);

}


Customer::Customer(string CustomerID_par, int CustomerMOAmount_par, int numOrders_par) //overloaded constructor
{
	CustomerID = CustomerID_par;
	CustomerMOamt = CustomerMOAmount_par;
	numOrders = numOrders_par;
	customerMO.resize(numOrders);
}


void Customer::GetCustomerInfo(Customer NewCustomer_Par, int numOrders_par)
{
	
	Customer NewCustomer_Par;
	cout << "Enter New Customer ID" << endl;
	cin >> NewCustomer_Par.CustomerID;
	cout << "Enter Money Order Amount" << endl;
	cin >> NewCustomer_Par.CustomerMOamt;
	NewCustomer_Par.numOrders = numOrders_par;

}
static string GenerateUString()
{
	
	string Ustring;
	const unsigned int BLOCKSIZE = 10;
	byte CustRN[BLOCKSIZE];

	// Random Block
	AutoSeededRandomPool rng;  //Setup Crypto++ Random Number Generator
	rng.GenerateBlock(CustRN, BLOCKSIZE); //stores generated blocks in CustRN array

	// Output
	string UString_par;
	ostringstream ss;                  //Create output string stream object
	ss << setbase(16) << setfill('0'); //Inputs in hex and prepends 0 to a 1
	//char hex value (i.e. '5' == '05')
	for (unsigned int i = 0; i < BLOCKSIZE; i++)
	{
		ss << setw(2) << static_cast<unsigned int>(CustRN[i]);
	}
	Ustring = ss.str();  //Set Ustring to resulting string

	return Ustring;


}

//Secret Splitting Method
static string BitXOR(string x, string y)  //x is CustID;  Y is XOR key
{
	stringstream ss;            //create output stream object
	
	for (int i = 0; i < x.length(); i++)
	{

		ss << (x.at(i) ^ y.at(i));  //XOR the two variables and input into output stream variable
	}


	return ss.str(); // ss is left side of Identity string pair, key(ie. y) is right

}


void BlindSignature(string& CustSig_par)
{

}

void CreateCustomerMO(Customer NewCustomer_par, int numOrders_par)
	{

		string Ustring;
		string IDleft="123456789";
		string IDright = NewCustomer_par.CustomerID;
		string CustSig;

		for (int i = 0; i < numOrders_par; i++)
		{
			NewCustomer_par.customerMO[i].Ustring = GenerateUString();
			NewCustomer_par.customerMO[i].IDright = IDright;
			NewCustomer_par.customerMO[i].IDleft = BitXOR(IDleft, IDright);
		}

	}


}
