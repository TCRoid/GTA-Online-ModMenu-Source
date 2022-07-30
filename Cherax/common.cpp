#include "common.h"

std::string encryptDecrypt(std::string toEncrypt) {

	std::string output = toEncrypt;
	for (int i = 0; i < toEncrypt.size(); i++)
	{
		char nextKey;

		switch (toEncrypt[i])
		{
		case ' ':
			nextKey = ' ';
			break;

		case '?':
			nextKey = '?';
			break;

		case 'A':
			nextKey = 'B';
			break;

		case 'B':
			nextKey = 'A';
			break;

		case 'C':
			nextKey = 'D';
			break;

		case 'D':
			nextKey = 'C';
			break;

		case 'E':
			nextKey = 'F';
			break;

		case 'F':
			nextKey = 'E';
			break;

		case '0':
			nextKey = '1';
			break;

		case '1':
			nextKey = '0';
			break;

		case '2':
			nextKey = '3';
			break;

		case '3':
			nextKey = '2';
			break;

		case '4':
			nextKey = '5';
			break;

		case '5':
			nextKey = '4';
			break;

		case '6':
			nextKey = '7';
			break;

		case '7':
			nextKey = '6';
			break;

		case '8':
			nextKey = '9';
			break;

		case '9':
			nextKey = '8';
			break;
		}


		output[i] = nextKey;
	}

	return output;
}
