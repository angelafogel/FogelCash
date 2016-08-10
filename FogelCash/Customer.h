//Angela Fogel
//CS625 Cryptography
//Digital Cash Protocol #4

//CUSTOMER FUNCTIONS HEADER FILE

//Class to extract money order information from user and initialize 
//money order object through class constructor

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Customer
{

public:
	Customer();  //Default Constructor

	Customer(string CustomerID_par, int CustomerMOamt_par, int numOrders_par); //overloaded constructor takes
	                                                // customer entered ss# as ID and the
	                                                // amount of the money order.
	
	//member variables
	string CustomerID;
	int CustomerMOamt;
	int numOrders;



class CustomerMoneyOrder
{
public:
	int MOamount;
	string Ustring;
	string IDleft;
	string IDright;
	string CustSig;
};

vector<CustomerMoneyOrder> customerMO;
void CreateCustomerMO(Customer NewCustomer_par, int amt_par);
void GetCustomerInfo(Customer NewCustomer_Par, int numOrders_par);
string GenerateUString();
string BitXOR(string x, string y);
void BlindSignature(string& CustSig_par);



};
#endif