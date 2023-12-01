#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int, char **)
{
    string filename = "../input.txt";

    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Cannot open input file: " << filename << endl;
    }

    string line;
    int part1 = 0;

    while (getline(inputFile, line))
    {
        vector<string> digits;
        if (line.size() > 0)
        {
            for (auto &&character : line)
            {
                if (isdigit(character))
                {
                    string digit;
                    digit = character;
                    digits.push_back(digit);
                }
            }
        }
        part1 += stoi(digits.front() + digits.back());
    }

    cout << "Solution for part 1: " << part1 << endl;
}
