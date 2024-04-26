// File: CS112_A2_T2_s(15,16)_ 20230433_20230140_20230134.cpp 
// 
// Purpose: a program made of three ciphers that encrypts/decrypts any message with the desired cipher 
//
// Author 1: Rawan Rushdy Fathy s(15,16):
// Rawan did Aphine cipher (0).
// 
// Author 2: Dima Khaled Allam s(15,16):
// Dima did baconian cipher (4).
// 
// 
// Author 3: Mo'men Mamdouh Mahmoud s(15,16):
// Mo'men did vignere cipher (3). 
// 
// 
// Emails:
// rawanrushdy551@gmail.com
// dkh3462@gmail.com
// momenmamdouh122@gmail.com
// 
// ID1: 20230140 – did affine cipher.
// ID2: 20230134 – did baconian cipher.
// ID3: 20230433 – did vignere cipher.










#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <cmath>
#include <limits>
using namespace std;

// Function to check if input is an integer
bool isInteger(const string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
    char* p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}

// Function to encrypt text
void Affine_encryption() {
    string message;
    int a, b;
    cout << "Please enter the message you want to encrypt:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, message);
    string encrypted_message = "";
    char new_char;

    while (true) {  // Get the fisrt key for the shift
        cout << "Enter the value of 'a': ";
        cin >> a;
        if (a > 0) { // Valid input
            break;
        }
        else { // Handeling invalid inputs
            cout << "Invalid input. Please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (true) { // Get the second key for the shift
        cout << "Enter the value of 'b': ";
        cin >> b;
        if (b > 0) { // Valid input
            break;
        }
        else { // Handeling invalid inputs
            cout << "Invalid input. Please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Encryption
    for (int i = 0; i < message.length(); i++) {
        if (isalpha(message[i])) {
            char ch = isupper(message[i]) ? 'A' : 'a';
            new_char = (char)(((a * (message[i] - ch) + b) % 26) + ch);
            new_char = toupper(new_char);
            encrypted_message += new_char;
        }
        else if (isspace(message[i])) {
            encrypted_message += message[i];
        }
        else {
            continue;
        }
    }
    cout << "The encrypted message of " << message << " is " << encrypted_message << "\n";
}



// Function to find multiplicative inverse
int Inverse(int a, int m) {
    for (int x = 0; x < m; x++) {
        if ((a * x) % m == 1)
            return a;
    }
    return -1;
}

// Function to decrypt text
void Affine_decryption() {
    string message;
    int a, b;
    cout << "Please enter the message you want to decrypt:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, message);
    string decrypted_message = "";

    while (true) { // Get the first key for the shift
        cout << "Enter the value of 'a': ";
        cin >> a;
        if (a > 0) { // Valid input
            break;
        }
        else if (a < 0) { // Handeling invalid inputs
            cout << "Invalid input. Please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else { // Handeling invalid inputs
            cout << "Invalid input. Please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    while (true) { // Get the second key for the shift
        cout << "Enter the value of 'b': ";
        cin >> b;
        if (b > 0) {
            break;
        }
        else if (b < 0) { // Handeling invalid inputs
            cout << "Invalid input. Please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else { // Handeling invalid inputs
            cout << "Invalid input. Please try again\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    int a_inverse = Inverse(a, 26);

    // Decryption
    for (char character : message) {
        if (isalpha(character)) {
            character = toupper(character);
            int new_char = ((a_inverse * ((character - 'A') - b + 26)) % 26);
            character = 'A' + new_char;
            decrypted_message += character;
        }
        else if (isspace(character)) {
            decrypted_message += character;
        }
        else {
            continue;
        }
    }

    cout << "The encrypted message of " << message << " is " << decrypted_message << "\n";
}

// Function for bocanian cipher to cipher the message
void bocanianCipher() {
    cout << "Please enter the message you want to encrypt\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string msg;
    getline(cin, msg);
    string encr_message;     //declare a string variable to put the encrypted message in it
    //create a map for each key character in the alphabet and its corresponding code
    map<char, string> AlphabetCodeMap = { {'A', "aaaaa"},{'B', "aaaab"},{'C', "aaaba"},
                                          {'D', "aaabb"},{'E', "aabaa"},{'F', "aabab"},
                                          {'G', "aabba"},{'H', "aabbb"},{'I', "abaaa"},
                                          {'J', "abaab"},{'K', "ababa"},{'L', "ababb"},
                                          {'M', "abbaa"},{'N', "abbab"},{'O', "abbba"},
                                          {'P', "abbbb"},{'Q', "baaaa"},{'R', "baaab"},
                                          {'S', "baaba"},{'T', "baabb"},{'U', "babaa"},
                                          {'V', "babab"},{'W', "babba"},{'X', "babbb"},
                                          {'Y', "bbaaa"},{'Z', "bbaab"} };
    //loop the input message
    for (char i : msg) {
        //check if each character in the msg is alphabet if not ignore it
        if (isalpha(i)) {
            //after checking that it is an alphabet uppercase it using the toupper() function and put it in the uppercase_char variable
            char uppercase_char = toupper(i);
            //after that use the at() function to get the value of this alphabet character from the above map
            encr_message += AlphabetCodeMap.at(uppercase_char) + " ";
        }//repeat all this steps for all alphabet character in the input message
    }
    //print the encrypted version of the message
    cout << "The encrypted message of " << msg << " is " << encr_message << "\n";

}

// Function for bocanian cipher to decipher the message
void bocanianDecipher() {
    cout << "Please enter the message you want to decrypt\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string msg;
    getline(cin, msg);
    string temp_msg, encr_message;         //declare two string variables to use them down
    //create a map for each code of a and b and its corresponding character in alphabet
    map<string, char>decipherMap = { {"aaaaa",'A'},{"aaaab",'B'},{"aaaba",'C'},{"aaabb",'D'},
                                     {"aabaa",'E'},{"aabab",'F'},{"aabba",'G'},{"aabbb",'H'},
                                     {"abaaa",'I'},{"abaab",'J'},{"ababa",'K'},{"ababb",'L'},
                                     {"abbaa",'M'},{"abbab",'N'},{"abbba",'O'},{"abbbb",'P'},
                                     {"baaaa",'Q'},{"baaab",'R'},{"baaba",'S'},{"baabb",'T'},
                                     {"babaa",'U'},{"babab",'V'},{"babba",'W'},{"babbb",'X'},
                                     {"bbaaa",'Y'},{"bbaab",'Z'} };
    //loop the input message
    for (char i : msg) {
        //check if each character is a or b if not ignore it
        if (i == 'a' || i == 'b') {
            //then put the character in the temp_msg variable
            temp_msg += i;
            //repeat that until the temp_msg variable string has 5 characters in it
            if (temp_msg.size() == 5) {
                //then check if these 5 characters of a and b correspond to any key in the above map
                if (decipherMap.count(temp_msg)) {
                    //after checking that the 5 characters correspond to a key in the above map use the at() function to get the value of these 5 characters from the above map
                    encr_message += decipherMap.at(temp_msg);
                }
                //after finishing the steps for each 5 characters in the temp_msg variable clear the whole variable to check on the next 5 characters
                temp_msg = "";
            }
        }
    }
    //print the decrypted version of the message
    cout << "The decryption message of " << msg << " is " << encr_message << "\n";
}




//global variables 

string message;
string keyword;
// function to to map the keyword so it would be the same length as the entered message with all its characters.
static void vignerekeyMapping() {


    for (int i = 0; i < message.length(); i++)
    {
        if (keyword.length() == message.length()) break; //assures the repetition of the keyword fits exactly the lenth of the message
        keyword.push_back(keyword[i]);
    }
}

//checks the keyword condition to make sure it's suitable to the cipher
static bool vignerevalidateKeyword(string kword) {
    if (kword.length() > 8) { // checks the keyword length to see if it passes 8
        cout << "the length of the entered keyword passed the limit (8) ,please enter a shorter keyword. " << endl;
        return false;
    }

    for (int i = 0; i < kword.length(); i++)
    {
        if (!isalpha(kword[i])) { //assures that the entered keyword is only letters
            cout << "please enter only alphabetic characters" << endl;
            return false;
        }
    }
    return true;
}


string readString() {
    string input;


    // Ignore leading whitespaces
    cin >> ws;

    // Read the entire line (including whitespaces) until Enter is pressed
    getline(cin, input);

    return input;
}

//getting the inputs from the user
void vigneregetInputs() {


    // getting input message
    cout << "Enter Message: " << endl;
    message = readString();


    // assuring the message is not more than 80 characters.
    while (message.length() > 80)
    {
        cout << "the length of the entered message passed the limit (80) ,please enter a shorter message. ";
        message = readString();


    }
    // makes the message Uppercase
    for (int i = 0; i < message.length(); i++) {
        message[i] = toupper(message[i]);
    }

    // getting input key
    do
    {
        cout << "Enter Key: " << endl;

        keyword = readString();
    } while (!vignerevalidateKeyword(keyword)); //recalls the boolean function above which checks the keyword desired conditions



    // makes the keyword uppercase
    for (int i = 0; i < keyword.length(); i++) {
        keyword[i] = toupper(keyword[i]);
    }
    vignerekeyMapping(); // after making sure the message and true maps the keyword to the message by repeating the keyword to fit the message's length
}

// fucntion that encrypts the message
static void vignereEncrypt() {
    string encryptedText;

    for (int i = 0; i < message.length(); i++) //makes sure to loop over the whole message to do the encryption in the following steps
    {

        if (message[i] >= 'A' && message[i] <= 'Z') { // a condition to make sure that the encryption happens to alphabetic characters only.

            char temp = ((message[i] + keyword[i]) % 26) + 'A'; //the formula of encryption
            encryptedText.push_back(temp); // pushes the encrypted character in the string (encryptedText).
        }
        else { // if charachter is not an alphabetic character leave it without encryption. 
            encryptedText.push_back(message[i]);
        }



    }

    cout << encryptedText;
}

// fucntion that decrypts the message
static void vignereDecryption() { //makes sure to loop over the whole message to do the decryption in the following steps
    string decryptedText;

    for (int i = 0; i < message.length(); i++)
    {

        if (message[i] >= 'A' && message[i] <= 'Z') { //makes sure that the decryption happens to alphabetic characters only

            char temp = ((message[i] - keyword[i] + 26) % 26) + 'A'; //the formula of decryption
            decryptedText.push_back(temp);// pushes the decrypted character in the string (decryptedText).
        }

        else
        {    // if charachter is not an alphabetic character leave it without decryption. 
            decryptedText.push_back(message[i]);
        }



    }
    cout << decryptedText;
}









int main() {
    cout << "Welcome to our Cipher and Decipher program";
    while (true) {
        cout << "\nWhat would you like to do?\n";
        cout << "1-Cipher a message\n" << "2-Decipher a message\n" << "3-End the Program\n";
        string choice1_str;
        cin >> choice1_str;
        while (!isInteger(choice1_str) || stoi(choice1_str) < 1 || stoi(choice1_str) > 3) {
            cout << "Please enter a valid choice\n";
            cin >> choice1_str;
        }
        int choice1 = stoi(choice1_str);
        if (choice1 == 1 || choice1 == 2) {
            cout << "Which cipher would you like to choose?\n";
            cout << "1-Affine Cipher\n" << "2-Vignere Cipher\n" << "3-Bocanian Cipher\n";
            string choice2_str;
            cin >> choice2_str;
            while (!isInteger(choice2_str) || stoi(choice2_str) < 1 || stoi(choice2_str) > 3) {
                cout << "Please enter a valid choice\n";
                cin >> choice2_str;
            }
            int choice2 = stoi(choice2_str);
            if (choice1 == 1) {
                if (choice2 == 1) {
                    Affine_encryption();
                }
                else if (choice2 == 3) {
                    bocanianCipher();
                }
                else {
                    vigneregetInputs();
                    vignereEncrypt();
                }
            }
            else {
                if (choice2 == 1) {
                    Affine_decryption();
                }
                else if (choice2 == 3) {
                    bocanianDecipher();
                }
                else {
                    vigneregetInputs();
                    vignereDecryption();
                }
            }
        }
        else {
            cout << "End of Program\n";
            return 0;
        }
    }
}