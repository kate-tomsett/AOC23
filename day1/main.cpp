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
    int part2 = 0;

    vector<string> words{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (getline(inputFile, line))
    {
        vector<string> digits1;
        vector<string> digits2;
        for (size_t i = 0; i < line.size(); i++)
        {
            if (isdigit(line[i]))
            {
                string digit;
                digit = line[i];
                digits1.push_back(digit);
                digits2.push_back(digit);
            }
            for (size_t wordIndex = 1; wordIndex < words.size(); wordIndex++)
            {
                if (line.find(words.at(wordIndex), i) == i)
                {
                    digits2.push_back(to_string(wordIndex));
                }
            }
        }

        if (digits1.size() > 0)
        {
            part1 += stoi(digits1.front() + digits1.back());
        }
        if (digits2.size() > 0)
        {
            part2 += stoi(digits2.front() + digits2.back());
        }
    }

    cout << "Solution for part 1: " << part1 << endl;
    cout << "Solution for part 2: " << part2 << endl;
}
