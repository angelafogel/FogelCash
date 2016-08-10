//Angela Fogel
//CS625 Cryptography
//Digital Cash Protocol #4

//This Main function drives all Customer, Merchant and Bank functions


#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Customer.h"
#include "cryptopp\osrng.h" // PRNG
using namespace CryptoPP;
using namespace std;

string customerID = "0";
string MOamount = "0";
int NumberOfOrders = 5;
Customer Alice;

int main(int argc, char* argv[]) 
{
	// CUSTOMER PROCESS:

	Alice.GetCustomerInfo(Alice, NumberOfOrders);
	Alice.CreateCustomerMO(Alice, Alice.CustomerMOamt);

	

	return 0;
}