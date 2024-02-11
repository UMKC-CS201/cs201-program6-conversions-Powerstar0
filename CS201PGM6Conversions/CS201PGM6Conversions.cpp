//Name: Johnny Diep
//Date: 2/11/2024
//PROGRAM 6: Conversions
//Purpose: Give the user the ability to make conversions between bases (between 2-16) to decimal, decimal to base,
//and from one base to another base with a simple menu.

// CS201PGM6Conversions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

//FUNCTION DECLARATIONS
bool isDigits(string inStr);
//PRE:  string is input to the function
//POST:  return true if nothing other than a digit is found{

string decToBin(const string& inVal);
//PRE: input string is sent to function
//POST: if valid, return a string that is the binary equivalent

string decToBase(const string& inVal, int base);
//PRE: input string is sent to function
//POST: if valid, return a string that is the equivalent value in the base given

int bintoDec(const string& inVal, int base);
//PRE: input string is sent to function
//POST: if valid, return the decimal value of the binary string

string baseToDecimal(const string& inVal, int base);
//PRE: input string is sent to function
//POST: if valid, return the string that is the decimal equivalent of the base and input given

int main() {
    //Pseudocode:
    /*
     * While user_input is not q:
     *  Print Menu (a is num to decimal, b is decimal to base, c is base to base, q is quit)
     *  Get user_input and check if it's valid
     *  if 'a' is chosen:
     *      Prompt for input and base values
     *      Feed values into function
     *      print result or error
     *  else if 'b' is chosen:
     *      Prompt for decimal and base values
     *      Feed values into function
     *      print result or error
     *  else if 'c' is chosen:
     *      Prompt for input and both base values
     *      Feed values into function
     *      print result or error
     *  else if 'q' is chosen:
     *      break loop
     *  else:
     *      Print incorrect selection error
     * */
    //Loops through the menu until user quits
    char user_input = 'y';
    while (true) {
        cout << "Please enter what you would like to do: " << endl;
        cout << "\t" << "a. Convert a number to decimal (enter a value and a given base)" << endl;
        cout << "\t" << "b. Convert a decimal to another base (enter a decimal value and a base)" << endl;
        cout << "\t" << "c. Convert a number from base1 to base2 (enter number, base1, base2)" << endl;
        cout << "\t" << "q. Quit" << endl;
        // This error checking part came from CHATGPT https://chat.openai.com/c/e4fb3f53-bb50-4003-a1a2-ee4ad067e36f
        string check_input;
        cin >> check_input;
        if (check_input.size() != 1) {
            cout << "Error. Please enter a single character" << endl;
            cout << endl;
            continue;
        }
        user_input = check_input[0];
        if (user_input == 'a') {
            // num to decimal
            string input;
            int base;
            cout << "Enter your input value: ";
            cin >> input;
            cout << "Enter given base value: ";
            cin >> base;
            string result = baseToDecimal(input, base);
            cout << endl;
            // This error handling came from CHATGPT
            size_t pos = result.find("Error");
            if (pos != string::npos) {
                cout << result << endl;
            }
            else {
                cout << "The value " << input << " in base " << base << " is " << result << " in decimal" << endl;
            }
        }
        else if (user_input == 'b') {
            // decimal to base
            string input;
            int base;
            cout << "Enter your decimal value: ";
            cin >> input;
            cout << "Enter resulting base value: ";
            cin >> base;
            string result = decToBase(input, base);
            cout << endl;
            if (result == "Error") {
                cout << "Invalid Input" << endl;
            }
            else {
                cout << "The decimal value " << input << " is " << result << " in base " << base << endl;
            }
        }
        else if (user_input == 'c') {
            // base to base
            // This code was written by me, but the idea for doing so came from CHATGPT
            string input;
            int original_base;
            int output_base;
            cout << "Enter your input value: ";
            cin >> input;
            cout << "Enter original base: ";
            cin >> original_base;
            cout << "Enter output base: ";
            cin >> output_base;
            cout << endl;
            string tempvalue = baseToDecimal(input, original_base);
            cout << "The value " << input << " in base " << original_base << " is " << tempvalue << " in decimal." << endl;
            string result = decToBase(tempvalue, output_base);
            cout << "The value " << input << " is " << result << " in base " << output_base << endl;
        }
        else if (user_input == 'q') {
            // Exit condition
            break;
        }
        else {
            // All other inputs
            cout << "That is not a valid menu item" << endl;
        }
        cout << endl;
    }
}

//FUNCTION DEFINITIONS
bool isDigits(string inStr) {
    return (inStr.find_first_not_of("0123456789") == string::npos);
}

string decToBase(const string& inVal, int base) {
    // Purpose: Given a number in decimal, and a base, convert the decimal to that base

    // Code taken from CHATGPT using the pseudocode https://chat.openai.com/c/e4fb3f53-bb50-4003-a1a2-ee4ad067e36f

    //Placeholder Variable
    string outVal = "";

    // Pseudocode
    /*
    IF (isDigits(inVal) && base >= 2 and base <=16) {
        set inVal to integer type
        outVal = ??
        decVal = inVal string converted to decimal
        WHILE (decVal > 0)
            tempVal = decValue % base
            if (tempVal == 10)      outVal = 'A' + outVal
            else if (tempVal == 11) outVal = 'B' + outVal
            :
            else outVal = char(tempVal) + outVal
            decVal = decVal/base
        ENDWHILE
        PRINT output
    ELSE
        PRINT error
    ENDIF
    */

    if (isDigits(inVal) && base >= 2 && base <= 16) {
        int decVal = stoi(inVal);

        while (decVal > 0) {
            int tempVal = decVal % base;
            if (tempVal >= 10) {
                outVal = char('A' + tempVal - 10) + outVal;
            } else {
                outVal = char('0' + tempVal) + outVal;
            }
            decVal /= base;
        }
    } else {
        outVal = "Error";
    }

    return outVal;
}

string baseToDecimal(const string& inVal, int base) {
    // Purpose: Given a number and its given base, convert the number to decimal

    // Code and function taken from CHATGPT, prompting it to create code to convert a number from any base to decimal https://chat.openai.com/c/e4fb3f53-bb50-4003-a1a2-ee4ad067e36f
    // The Pseudocode below for this function is also taken from CHATGPT

    /*
    int decimalValue = 0;
    int power = 0;

    // Lambda function to convert a character to its integer value
    auto charToInt = [](char c) {
        if (isdigit(c))
            return c - '0';
        else
            return toupper(c) - 'A' + 10;
    };

    // Check if input is valid
    FOR each character c in inVal DO
        IF c is not a digit AND (c is not between 'A' and 'F' OR c is not between 'a' and 'f') THEN
            RETURN "Error: Invalid input"
        ENDIF
        IF charToInt(c) >= base THEN
            RETURN "Error: Digit not valid in base " + to_string(base)
        ENDIF
    ENDFOR

    // Convert the number to decimal
    FOR i from length of inVal - 1 DOWN TO 0 DO
        decimalValue += charToInt(inVal[i]) * pow(base, power)
        power++
    ENDFOR

    RETURN to_string(decimalValue)
    */

    int decimalValue = 0;
    int power = 0;

    auto charToInt = [](char c) {
        if (isdigit(c))
            return c - '0';
        else
            return toupper(c) - 'A' + 10;
    };

    // Check if input is valid
    for (char c : inVal) {
        if (!isdigit(c) && (toupper(c) < 'A' || toupper(c) > 'F')) {
            return "Error: Invalid input";
        }
        if (charToInt(c) >= base) {
            return "Error: Digit not valid in base " + to_string(base);
        }
    }

    for (int i = inVal.length() - 1; i >= 0; --i) {
        decimalValue += charToInt(inVal[i]) * pow(base, power);
        power++;
    }

    return to_string(decimalValue);
}


int bintoDec(const string& inVal, int base) {
    // Didn't need to use this preset function
    /*
    IF(str1 contains only 1s and 0s)
        outVal = 0
        placeValue = 1
        tempVal = int(str1)
        WHILE(tempVal > 0)
             digit = tempVal % 10
             outVal = outVal + digit * placeValue
             placeValue *= base
             tempVal = tempVal / 10
        ENDWHILE
        RETURN outVal
     ELSE
        PRINT error
     ENDIF
     */
    return 0;
}

string decToBin(const string& inVal) {
    // Didn't need to use this preset function
    string outVal = "";
    /*
    IF (isDigits(inVal)) {
        set inVal to integer type
        outVal = ??
        decVal = inVal string converted to decimal
        WHILE (decVal > 0)
            tempVal = decValue % 2
            outVal = char(tempVal) + outVal
            decVal = decVal/2
        ENDWHILE
        PRINT output
    ELSE
        PRINT error
    ENDIF
    */
    return outVal;
}