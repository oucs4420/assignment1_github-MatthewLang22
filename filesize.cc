/*
* Name:         Matthew Lang
* Date:         1-14-2022
* Description:  CS 4420 - Assignment 0 - Github Familiarity: Counts the number of lines in each file
*/

#include <iostream>
#include <fstream>

using namespace std;

// output format to use IDENTICALLY:
// BSH:Saru> ./filesize input.3lines input.1line 
// program: ./filesize
// input.3lines: 3
// input.1line: 1

int main(int argc, char* argv[])
{
    cout << "program: " << argv[0] << endl; // First printing the name of the program

    ifstream instream;

    for (int i = 1; i < argc; i++) // Looping through each file provided
    {
        instream.open(argv[i]);
        if (instream.fail()) // If there is no file with the provided name, print -1
        {
            cout << " " << argv[i] << ": -1" << endl;
        }
        else
        {
            int line_count = 0;
            string line;
            while (!instream.eof()) // While loop to count each getline
            {
                getline(instream, line);
                line_count++;
            }
            if (line == "") // If the last line is blank, it needs subtracted out from the count
            {
                line_count = line_count - 1;
            }
            cout << " " << argv[i] << ": " << line_count << endl;
            line_count = 0;
        }
        instream.close();
    }

    exit(0); // this means that the program executed correctly!
}
