// FogelCash.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

// Link errors can be fixed by pasting path for the cryptlib.lib file in the Croptopp\Win32\Output\Debug file
// 
#include <cstdio>

#include <cstdlib>

#include "cryptopp\osrng.h"
#include "cryptopp\cryptlib.h"
#include "cryptopp\hex.h"
#include "cryptopp\filters.h"
#include "cryptopp\des.h"
#include "cryptopp\modes.h"
#include "cryptopp\secblock.h"
#include "cryptopp\modes.h"
#include "cryptopp\aes.h"
#include "cryptopp\filters.h"

#include <iostream>
#include <string>

using namespace std;
using namespace CryptoPP;




//int main(int argc, char* argv[]) {

	//HMODULE DLL = LoadLibrary(_T("cryptopp.dll"));
	//
	// Initialize the Key and IV (IV is the initialization vector or starting variable)
	//AES encryption uses a secret key of a variable length (128-bit, 196-bit or 256-
	//bit). This key is secretly exchanged between two parties before communication
	//begins. DEFAULT_KEYLENGTH= 16 bytes
	string key = "0123456789abcdef";
	string iv = "aaaaaaaaaaaaaaaa";
	string plain = "CBC Mode Test";
	string cipher, encoded, recovered;


	string plaintext = "name macmilan age 24 ciy bonn country germany";
	string ciphertext;
	string decryptedtext;

	cout << "Plain Text (" << plaintext.size() << " bytes)" << std::endl;
	cout << plaintext;
	cout << std::endl << std::endl;

	//create object for encrypting
	AES::Encryption aesEncryption((byte *)key.c_str(), AES::DEFAULT_KEYLENGTH);

	//Use Cipher Block Chaining Mode to turn the block cipher into a stream cipher
	// The specific FN below creates a mode object that holds a reference 
	// to a block cipher object rather than an instance of it
	CBC_Mode_ExternalCipher::Encryption cbcEncryption(aesEncryption, (byte *)iv.c_str());
	
	//CBC mode requires data processed in multiples of the block size so we use StreamTransformationFilter
	//to wrap the mode object and use it as a Filter object. The StringSink function then performs "pipelining"
	//or data flow from source to sink placing the ciphertext .  It also handles padding. 
	StreamTransformationFilter stfEncryptor(cbcEncryption, new StringSink(ciphertext));
	
	stfEncryptor.Put(reinterpret_cast<const unsigned char*>(plaintext.c_str()), plaintext.length() + 1);
	stfEncryptor.MessageEnd();
	cout << "cipher text plain: " << ciphertext << endl;
	std::cout << "Cipher Text (" << ciphertext.size() << " bytes)" << std::endl;
	cout << endl;
	cout << endl;
	cout << "cipher text In HEX FORM:: ";
	for (int i = 0; i < ciphertext.size(); i++) {

		cout << "0x" << hex << (0xFF & static_cast<byte>(ciphertext[i])) << " ";
	}
	cout << endl;
	cout << endl;
	/*********************************\
	\*********************************/

	// Pretty print
	encoded.clear();
	StringSource(ciphertext, true,
		new HexEncoder(
		new StringSink(encoded)
		) // HexEncoder
		); // StringSource
	cout << "cipher text In HEX FORM (Modified):: " << encoded << endl;
	cout << endl;
	cout << endl;
	char *name2;
	name2 = (char*)malloc(encoded.length() + 1); // don't forget to free!!!!
	//s2 = Database_row_count; // I forget if the string class can implicitly be converted to char*
	//s2[0] = '1';
	strcpy(name2, encoded.c_str());

	const char* hex_str = name2;

	string result_string;
	unsigned int ch;
	for (; sscanf(hex_str, "%2x", &ch) == 1; hex_str += 2)
		result_string += ch;
	cout << "HEX FORM to cipher text :: ";
	cout << result_string << '\n';
	cout << endl;
	cout << endl;
	/*********************************\
	\*********************************/


	AES::Decryption aesDecryption((byte *)key.c_str(), CryptoPP::AES::DEFAULT_KEYLENGTH);
	CBC_Mode_ExternalCipher::Decryption cbcDecryption(aesDecryption, (byte *)iv.c_str());

	StreamTransformationFilter stfDecryptor(cbcDecryption, new CryptoPP::StringSink(decryptedtext));
	stfDecryptor.Put(reinterpret_cast<const unsigned char*>(result_string.c_str()), result_string.size());
	stfDecryptor.MessageEnd();
	cout << "Decrypted Text: " << std::endl;
	cout << decryptedtext;
	cout << std::endl << std::endl;

	system("pause");

	return 0;

	/ sample.cpp : Defines the entry point for the console application.
		//

#include "stdafx.h"

		// Runtime Library Includes
#include <string>
#include <iostream>
#include <iomanip>

		// Crypto++ Include
#include "cryptopp\osrng.h" // PRNG
		using namespace CryptoPP;

	int main(int argc, char* argv[])
	{
		// Scratch Area
		const unsigned int BLOCKSIZE = 16 * 8;
		byte pcbScratch[BLOCKSIZE];

		// Random Block
		CryptoPP::AutoSeededRandomPool rng;
		rng.GenerateBlock(pcbScratch, BLOCKSIZE);

		// Output
		std::cout << "The generated random block is:" << std::endl;
		for (unsigned int i = 0; i < BLOCKSIZE; i++)
		{
			std::cout << "0x" << std::setbase(16) << std::setw(2) << std::setfill('0');
			std::cout << static_cast<unsigned int>(pcbScratch[i]) << " ";
		}
		std::cout << std::endl;

		return 0;
	}

}

