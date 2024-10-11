// File:A1_T1_S5_20230419
// Purpose: Assignment 1 , task 1
// Author: Malak Nour El Hussein Samir
// Section: S5
// ID: 20230419
// Date: 30/9/2024.
//                                                    FULL DESCRIPTION
// problem 3 : By using this program we're able to exclude unwanted characters of a given string and put the surrounding words in a separate "" .
// problem 6 : Part 1 : Converting Decimal number to a binary one .
// part 2 : with a given binary digits as prefix and a key number , we will create all the possible combinations from 0 to 2^key with number of bits (prefix's + key's)bits.
// problem 9 : A Game to won it you must reach 42 . you will be given a number, and you will try all possible probability to figure if you can win or not.
// problem 12 : A program to discover and count the suspicious words in the email that has been sent to you and give you a total points as each word has a value point .

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

// Utility function to check if input is numeric (for the big menu)
bool isValidNumber(const string& input) {
    // Return true if all characters in the string are digits
    return !input.empty() && all_of(input.begin(), input.end(), ::isdigit);
}

// Stronger character validation (exactly one character) for problem 6's menu .
bool isValidCharacterInput(const string& input) {
    return input.length() == 1 && isalpha(input[0]);
}
// Stronger numeric validation
bool isValidNumericInput(const string& str) {
    if (str.empty()) return false;  // Empty input is invalid
    for (char ch : str) {
        if (!isdigit(ch)) {  // Only allow digits
            return false;
        }
    }
    return true;
}

//problem3
vector<string> splitRecursive(string str, string delim) {
    // Base case: If no delimiter is found, return the string as the last part
    if (str.find(delim) == string::npos) {
        return {str};  // Return the entire string as a single-element vector
    }
    // Find the position of the delimiter
    size_t pos = str.find(delim);

    // Extract the first part before the delimiter
    string token = str.substr(0, pos);

    // Recursively call the function for the rest of the string after the delimiter
    vector<string> result = splitRecursive(str.substr(pos + delim.length()), delim);

    // Insert the current token at the beginning of the result
    result.insert(result.begin(), token);

    return result;
}

void p3Main() {
    string str, delim;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter your string and the delimiter :\n";

    cout << "String: ";
    getline(cin, str);  // Get the entire string input

    cout << "Delimiter: ";
    getline(cin, delim);  // Get the entire delimiter input

    vector<string> result = splitRecursive(str, delim);

    // Print the result as ["str1", "str2", ...]
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << '"' << result[i] << '"';
        if (i < result.size() - 1) {
            cout << ", ";  // Add comma between elements
        }
    }
    cout << "]" << endl;
}


//problem 6

//part 1
// Recursive function to convert decimal to binary string
string binaryNumberRecursive(int n) {
    if (n == 0) return "0";  // Special case for zero
    if (n == 1) return "1";  // Base case: If n is 1, return "1"

    // Recursively calculate binary of n / 2 and add the remainder (n % 2)
    return binaryNumberRecursive(n / 2) + (n % 2 == 0 ? "0" : "1");
}

// Function to format binary with ".00" for large numbers
string formatBinaryWithDecimal(int n) {
    string binary = binaryNumberRecursive(n);
    if (n >= 100000) {  // Adjust threshold for large numbers
        binary += ".00";
    }
    return binary;
}

// Function to check if the prefix contains only binary digits (0 and 1)
bool isValidBinaryPrefix(const string& prefix) {
    for (char ch : prefix) {
        if (ch != '0' && ch != '1') {
            return false; // Invalid if character is not '0' or '1'
        }
    }
    return true;
}

// Function to remove leading zeros and ensure only one zero if all are zeros
string formatBinaryOutput(const string& binary) {
    // Remove leading zeros
    string formatted = binary;
    while (formatted.length() > 1 && formatted.front() == '0') {
        formatted.erase(formatted.begin()); // Remove the leading zero
    }
    return formatted.empty() ? "0" : formatted; // Return "0" if empty
}

//part 2
// Function to generate binary combinations using recursion
/*
Prefix: A string that is prepended to each generated binary combination. This could be any fixed sequence of characters (possibly user-defined).
keyLength: The length of the binary keys (combinations) to generate. It controls how many bits each key should have.
current: The current number being processed, which will be converted to its binary form. It starts from 0 and goes up to 2^keyLength - 1.
combinations: A vector that stores all generated binary combinations (with the prefix).
 */
void generateBinaryCombinationsRecursive(const string& prefix, int keyLength, int current, vector<string>& combinations) {
    // Base case: If we have processed all the key combinations, stop recursion
    // (1 << keyLength) means 2^keyLength, which gives us the total number of combinations possible
    if (current >= (1 << keyLength)) {
        return; // Exit the function when all combinations are generated
    }

    // Create a binary string for the current key combination
    // 'bitset<32>(current)' converts the current number to a 32-bit binary string
    // 'substr(32 - keyLength)' extracts the last 'keyLength' bits to match the desired length of the key
    string key = bitset<32>(current).to_string().substr(32 - keyLength);

    // Combine the prefix with the current key to form a full binary combination
    // The result is appended to the 'combinations' vector
    combinations.push_back(prefix + key);

    // Recursive call: Generate the next binary combination by incrementing the current value
    // The recursion continues until all possible combinations are generated
    generateBinaryCombinationsRecursive(prefix, keyLength, current + 1, combinations);
}


// Function to print combinations (Recursive version)
void printBinaryCombinationsRecursive(const vector<string>& combinations, int index = 0) {
    if (index >= combinations.size()) {
        return;  // Base case: when index exceeds the number of combinations
    }

    cout << formatBinaryOutput(combinations[index]) << endl;

    // Recursive call for the next element
    printBinaryCombinationsRecursive(combinations, index + 1);
}


void menu6() {
    while (true) {
        cout << "========================\n";
        cout << "What would you like to do?\n"
             << "A) Convert Decimal number to Binary.\n"
             << "B) Printing Many Numbers.\n";
        string choice;
        cin >> choice;

        if (!isValidCharacterInput(choice)) {  // Strong character validation
            cout << "Error: Invalid input. Please enter a single letter (A or B).\n";
            continue;
        }
        char option = toupper(choice[0]);

        if (option == 'A') {
            string input;
            cout << "Enter a positive integer:" << endl;
            cin >> input;

            if (!isValidNumericInput(input)) {  // Strong numeric validation
                cout << "Error: Please enter a valid positive integer.\n";
                continue;
            }

            int number = stoi(input);
            cout << "Binary representation: " << formatBinaryWithDecimal(number) << endl;
            break;

        } else if (option == 'B') {
            string prefix, keyLengthInput;

            cout << "Enter the prefix (binary digits): ";
            cin >> prefix;

            if (!isValidBinaryPrefix(prefix)) {  // Prefix validation
                cout << "Error: Prefix must contain only binary digits (0 and 1).\n";
                continue;
            }

            cout << "Enter the key length (0 or greater): ";
            cin >> keyLengthInput;

            if (!isValidNumericInput(keyLengthInput) || stoi(keyLengthInput) < 0) {
                cout << "Error: Key length must be a non-negative integer.\n";
                continue;
            }

            int keyLength = stoi(keyLengthInput);
            vector<string> combinations;
            generateBinaryCombinationsRecursive(prefix, keyLength, 0, combinations);
            printBinaryCombinationsRecursive(combinations);
            break;

        } else {
            cout << "Invalid Choice. Please enter A or B.\n";
            continue;
        }
    }
}

//problem 9
bool teddyGame(int n) {
    // Base cases
    if (n < 42) return false; // If n is less than 42, return false
    if (n == 42) return true; // If n is exactly 42, return true

    // Avoid excessive recursion by adding checks
    // Choice 1: If n is even, you may give back exactly n / 2 bears.
    if (n % 2 == 0) {
        if (teddyGame(n / 2)) return true; // Try giving back half
    }

    // Choice 2: If n is divisible by 5, you may give back exactly 42 bears.
    if (n % 5 == 0) {
        if (teddyGame(n - 42)) return true; // Try giving back 42 bears
    }

    // Choice 3: If n is divisible by 3 or 4, multiply the last two digits and give back this many bears.
    if (n % 3 == 0 || n % 4 == 0) {
        int lastDigit = n % 10;
        int secondLastDigit = (n % 100) / 10;
        int toGiveBack = lastDigit * secondLastDigit;

        // Avoid excessive recursion by checking if giving back is valid
        if (toGiveBack > 0 && n - toGiveBack >= 42 && teddyGame(n - toGiveBack)) {
            return true; // Try giving back the product of the last two digits
        }
    }

    return false; // If none of the choices worked, return false
}

void p9main() {
    int n;
    cout << "Enter the number of bears:\n";
    cin >> n;  // Input number of bears
    cout << (teddyGame(n) ?"True\n" :"False\n") ; // Output result
}

//problem 12
// Convert a string to lowercase
void toLowerCase(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

// Remove punctuation and formatting (e.g., **bold** or any HTML-like tags)
string removeFormatting(const string &word) {
    string result;
    for (char ch : word) {
        if (isalnum(ch) || ch == ' ') {  // Keep only alphanumeric and spaces
            result += ch;
        }
    }
    return result;
}

void p12main() {
    // Define phishing terms and their point values
    map<string, int> phishingTerms = {
            {"free", 3}, {"suspicious login", 2}, {"click", 2},
            {"reset your password", 3}, {"security alert", 2},
            {"bank account verification", 3}, {"congratulations", 3},
            {"paypal", 2}, {"github", 1}, {"reward", 3}, {"gift", 3},
            {"update your information", 3}, {"offer", 3}, {"fedex", 2},
            {"action", 2}, {"account verification required", 3},
            {"confirm your phone number", 2}, {"you won", 3},
            {"danger", 3}, {"verify", 3}, {"now", 2}, {"warning", 3},
            {"urgent", 3}, {"expire", 2}, {"enter", 2},
            {"unexpected behaviour", 3}, {"your account is locked", 3},
            {"claim your prize", 3}, {"limited time offer", 3},
            {"immediate action required", 3}, {"your shipment is on hold", 2},
            {"new message from your bank", 3}
    };

    // Get filename from user
    string filename;
    cout << "Enter the filename to scan for phishing terms: (e.g. file_name.txt)\n";
    cin >> filename;

    // Open the file for reading
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return;
    }

    // This block scans the entire file line by line and counts how many times each phishing term appears
    map<string, int> occurrences;  // Count occurrences
    string line;

    while (getline(file, line)) {  // Reads each line from the file into the string line
        toLowerCase(line);  // Convert line to lowercase
        line = removeFormatting(line);  // Remove any punctuation and formatting

        // Check for phishing terms
        for ( auto& [term, points] : phishingTerms) {
            size_t pos = 0;
            while ((pos = line.find(term, pos)) != string::npos) {  // Find the term in the line
                occurrences[term]++;  // Increase the count for this term
                pos += term.length();  // Move past the current term
            }
        }
    }

    file.close();  // Close the file after reading

    // Output results
    int grandTotal = 0;
    for (auto& [term, count] : occurrences) {
        if (count > 0) {
            int totalPoints = count * (int)phishingTerms[term];
            cout << "Term: " << term
                 << " - Occurrences: " << count
                 << " - Total Points: " << totalPoints << endl;
            grandTotal += totalPoints;  // Add to the overall phishing score
        }
    }

    // Output the final total phishing points for the scanned file
    cout << "Total Points for the entire message: " << grandTotal << endl;
}


int main() {
    while (true) {
        cout << "============================" << endl;
        cout << "Select a program to run:\n";
        cout << "1) String Split\n";
        cout << "2) Binary Conversion and Printing Numbers\n";
        cout << "3) Teddy Game\n";
        cout << "4) Phishing Scanner\n";
        cout << "5) Exit\n";

        string input;
        int choice;

        cout << "Enter your choice (1-5): ";
        cin >> input;

        // Validate if the input is a valid number and only contains digits
        if (!isValidNumber(input)) {
            cout << "Invalid input. Please enter a valid number between 1 and 5.\n";
            continue;  // Ask for input again
        }

        // Now we can safely convert the input to an integer
        choice = stoi(input);

        // Check if choice is within the valid range
        if (choice < 1 || choice > 5) {
            cout << "Please select a valid option between 1 and 5.\n";
            continue;
        }

        switch (choice) {
            case 1:
                p3Main();
                break;
            case 2:
                menu6();
                break;
            case 3:
                p9main();
                break;
            case 4:
                p12main();
                break;
            case 5:
                cout << "Exiting the program.";
                return 0;
        }
    }
}
