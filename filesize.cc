/*
* Name:         Matthew Lang
* Date:         1-14-2022
* Description:  CS 4420 Assignment 0 - 
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
    ifstream instream;
    for (int i = 1; i < argc; i++)
    {
        instream.open(argv[i]);
        if (instream.fail())
        {
            cout << argv[i] << ": -1" << endl;
        }
        else
        {
            int line_count = 0;
            string line;
            while (!instream.eof())
            {
                getline(instream, line);
                line_count++;
            }
            if (line == "")
            {
                line_count = line_count - 1;
            }
            cout << argv[i] << ": " << line_count << endl;
            line_count = 0;
        }
        instream.close();
    }

    exit(0); // this means that the program executed correctly!
}
