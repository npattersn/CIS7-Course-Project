#include <iostream>
#include <string>

using namespace std;

string message;
string mappedKey;

void messageAndKey() {
	string msg;
	cout << "Enter your message: ";
	getline(cin, msg);
	cin.ignore();

for (int i = 0; i < msg.length(); i++) {
		msg[i] = toupper(msg[i]);
	}

	string key;
	cout << "Please enter your key: ";
	getline(cin, key);
	cin.ignore();

for (int i = 0; i < key.length(); i++) {
		key[i] = toupper(key[i]);
	}

string keyMap = "";
	for (int i = 0, j = 0; i < msg.length(); i++) {
		if (msg[i] == 32) {
			keyMap += 32;
		}
		else {
			if (j < key.length()) {
				keyMap += key[j];
				j++;
			}
			else {
				j = 0;
				keyMap += key[j];
				j++;
			}
		} 
	} 

message = msg;
	mappedKey = keyMap;
}

int vTable[26][26];
void visibleTable() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			int temp;
			if ((i + 65) + j > 90) {
				temp = ((i + 65) + j) - 26;
				vTable[i][j] = temp;
			}
			else {
				temp = (i + 65) + j;
				vTable[i][j] = temp;
			}
		}
	}


	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			cout << (char)vTable[i][j] << " ";
		}
		cout << endl;
	}
}

int tableArr[26][26];
void createVigenereTable() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			int temp;
			if ((i + 65) + j > 90) {
				temp = ((i + 65) + j) - 26;
				tableArr[i][j] = temp;
			}
			else {
				temp = (i + 65) + j;
				tableArr[i][j] = temp;
			}
		}
	}
}

void cipherEncryption(string message, string mappedKey) {
	createVigenereTable();
	string encryptedText = "";
	for (int i = 0; i < message.length(); i++) {
		if (message[i] == 32 && mappedKey[i] == 32) {
			encryptedText += " ";
		}
		else {
			int x = (int)message[i] - 65;
			int y = (int)mappedKey[i] - 65;
			encryptedText += (char)tableArr[x][y];
		}
	}

	cout << "Encrypted Text: " << encryptedText;
	cout << "\nRestart the program for more encryption or decryption.";
}

int itrCount(int key, int msg) {
	int counter = 0;
	string result = "";

	for (int i = 0; i < 26; i++) {
		if (key + i > 90) {
			result += (char)(key + (i - 26));
		}
		else {
			result += (char)(key + i);
		}
	} 

	for (int i = 0; i < result.length(); i++) {
		if (result[i] == msg) {
			break;
		}
		else {
			counter++;
		}
	}
	return counter;
}


void cipherDecryption(string message, string mappedKey) {
	string decryptedText = "";
	for (int i = 0; i < message.length(); i++) {
		if (message[i] == 32 && mappedKey[i] == 32) {
			decryptedText += " ";
		}
		else {
			int temp = itrCount((int)mappedKey[i], (int)message[i]);
			decryptedText += (char)(65 + temp);
		}
	}

	cout << "Decrypted Text: " << decryptedText;
	cout << "Please restart the program for more encryption or decryption.";
}


int main()
{
	int choice;
	cout << "*****************************************************************************\n ";
	cout << "Hello this program allows you to encrypts or decrypts messages. \n Press 1 to encrypt, 2 to decrypt or 3 to see the table. \n When inputs are entered, press ENTER two times to proceed.";
	cout << "*****************************************************************************\n";
	cin >> choice;
	cin.ignore();

	if (choice == 1)
	{
		cout << "You have chosen encryption. \n" << endl;
		messageAndKey();
		cipherEncryption(message, mappedKey);

	}
	else if (choice == 2)
	{
		cout << "You have chosen decryption. \n" << endl;
		messageAndKey();
		cipherDecryption(message, mappedKey);
	}
	else if (choice == 3)
	{
		cout << "The table has been chosen. \n Please press 3 to confirm.";

		cin >> choice;

		if (choice == 3)
		{
			visibleTable();
		}
	}
	else {
		cout << "Sorry this option is not available. \n Please restart the program" << endl;
	}

	return 0;
  }