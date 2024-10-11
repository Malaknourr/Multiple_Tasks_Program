# Multiple_Tasks_Program

## Author Information
- **Author:** Malak Nour El Hussein Samir
- **Section:** S5
- **Student ID:** 20230419
- **Date:** 30/9/2024

## Purpose
This program is designed to perform multiple tasks as part of Assignment 1, Task 1. The tasks include string manipulation, binary conversion, a game involving probability, and a phishing scanner.

## Features
1. **String Manipulation (Problem 3)**:
   - The program excludes unwanted characters from a given string and puts the surrounding words in separate quotation marks.

2. **Binary Conversion (Problem 6)**:
   - Part 1: Converts a decimal number to its binary representation.
   - Part 2: Generates all possible binary combinations based on a specified prefix and a key number, where the total bits are the sum of the prefix's bits and the key's bits.

3. **Teddy Game (Problem 9)**:
   - A game where the goal is to determine if you can win by reaching a total of 42. You will input a number and try different combinations to figure out if it's possible to reach 42.

4. **Phishing Scanner (Problem 12)**:
   - The program scans an email for suspicious words and gives a total point score based on predefined phishing terms. Each term has an associated point value.

## Usage Instructions
1. **Compile and Run**:
   - Use a C++ compiler to compile the program. 
   - Execute the compiled binary to run the program.

2. **Main Menu**:
   - Upon running the program, a main menu will appear with the following options:
     - **1)** String Split
     - **2)** Binary Conversion and Printing Numbers
     - **3)** Teddy Game
     - **4)** Phishing Scanner
     - **5)** Exit

3. **Test Files**:
   - The program uses two test files:
     - **spam.txt**: Contains potentially phishing content to test the phishing scanner.
     - **safe.txt**: Contains safe content to verify that the phishing scanner functions correctly.
   - When prompted by the phishing scanner, enter the filename to scan (e.g., `spam.txt` or `safe.txt`).

4. **Input Guidelines**:
   - For the string manipulation task, you will be prompted to enter a string and a delimiter.
   - In the binary conversion task, you will be asked to provide a positive integer and optional binary prefix.
   - The teddy game will require you to enter the number of bears you have.
   - The phishing scanner will prompt you to enter the filename of the text file to scan.

## Notes
- Ensure the test files are in the same directory as the compiled program for the phishing scanner to work correctly.
- The program performs input validation to ensure that user inputs are appropriate for each task.

## Contact
For any questions or clarifications, please feel free to reach out.
