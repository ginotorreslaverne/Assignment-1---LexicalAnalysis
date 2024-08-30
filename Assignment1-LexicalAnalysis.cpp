// -----------------------------------------------------------------------------------------------------------------------
//                                               Name Gino Torres 
//                                               Course CMPS 455, Fall 2024
//                                               Assignment Assignment 1 - LexicalAnalysis
//                                               Due date September/5/2024
// Purpose: 
/* 
Please create a program that reads a TXT file and outputs all the words and punctuation marks it contains.

File name: LexicalAnalysis.cpp 

Input: source code file name with directory and output file name to save the words and punctuation marks

Return: 0: correct  -1: error

Due day: Please submit source code with running screenshots  to Github before next Thursday's class.
*/
//------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a character is a punctuation mark
bool isPunctuation(char ch) 
{
    return ispunct(ch);  
}

// Function to check if a character is part of a word 
bool isWordCharacter(char ch) 
{
    return isalnum(ch);  
}

int main() 
{
    string inputFileName, outputFileName;

    // Get input and output file names from the user
    cout << "Enter the input file name with directory: ";
    getline(cin, inputFileName);  // Reads the input file name from the user

    cout << "Enter the output file name with directory: ";
    getline(cin, outputFileName);  // Reads the output file name from the user

    // Open the input file for reading
    ifstream inputFile(inputFileName);
    if (!inputFile) 
    {
        cerr << "Error opening input file: " << inputFileName << endl;
        return 1;  // Exit the program if the input file cannot be opened
    }

    // Open the output file for writing
    ofstream outputFile(outputFileName);
    if (!outputFile) 
    {
        cerr << "Error opening output file: " << outputFileName << endl;
        return 1;  // Exit the program if the output file cannot be opened
    }

    char ch;
    string word;

    // Read the input file character by character
    while (inputFile.get(ch)) 
    {
        if (isWordCharacter(ch)) 
        {
            word += ch;  // If the character is alphanumeric, add it to the current word
        } 
        else 
        {
            if (!word.empty()) 
            {
                outputFile << word << '\n';  // Write the word to the output file if it exists
                word.clear();  // Clear the word buffer for the next word
            }
            if (isPunctuation(ch)) 
            {
                outputFile << ch << '\n';  // Write the punctuation mark to the output file
            }
        }
    }

    // If there is any remaining word after the loop ends, write it to the output file
    if (!word.empty()) 
    {
        outputFile << word << '\n';
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    // Notify the user that the process is complete
    cout << "Words and punctuation marks have been extracted and saved to " << outputFileName << endl;

    return 0; 
}