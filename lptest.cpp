#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

const int HTSIZE = 13;
int hashFunction(string , int );
int main() {
	
	string hashTable[HTSIZE];
	string line;
	fstream dataIn;
	int sub = 0;
	int index = 0;
	bool found;
	int collision = 0;
	
	dataIn.open("lab6.dat");
	cout << "HASH METHOD: modulo-division" << endl
		 << "COLLISION RESOLUTION: linear probe" << endl
		 << "HASHED LIST" << endl << endl
		 << "SUB" << setw(5) << "KEY" << endl;
		 
	while(dataIn)
	{
		getline(dataIn, line);
		index = hashFunction(line, line.length());
		hashTable[index] = line;
	}
	for(index = 0; index < HTSIZE; index++)
	{
		if(hashTable[index] == "")
		{
			hashTable[index] = "-1";
		}
		cout << left << setw(5) << index << hashTable[index] << endl;
	}
	dataIn.close();
	
	dataIn.open("lab6srch.dat");
	while(dataIn)
	{
		getline(dataIn, line);
		sub = hashFunction(line, line.length());
		found = false;
		
		while(hashTable[sub] != "-1" && !found)
		{
			
			if(hashTable[sub] == line)
			{
				found = true;
			}
			else
				sub = (sub + 1) % HTSIZE;
		}
		if(found)
		{
			cout <<"Yes" << endl;
		}
		else
		{
			hashTable[sub] = line;
		}
	}
		
	dataIn.close();
	for( index = 0; index < HTSIZE; index++)
	{
		cout << setw(5) << hashTable[index] << endl;
	}

	return 0;
}

int hashFunction(string insertKey, int keyLength)
{
	int sum = 0;
	
	for (int index = 0; index < keyLength; index++)
		sum = sum + static_cast<int>(insertKey[index]);
	return (sum % HTSIZE);
}
