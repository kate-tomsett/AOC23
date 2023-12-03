#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int main(int, char**){
    
    string filename = "../input.txt";
    ifstream inputFile(filename);
    if (!inputFile)
    {
        cerr << "Cannot open input file: " << filename << endl;
    }

    string line;
    int part1 = 0;
    int part2 = 0;
    char delimit[] = " :;,";
   
    map<string,int> colourMap{{"red", 12},{"green",13},{"blue",14}};

    while (getline(inputFile, line))
    {
        bool possible = true;
        map<string,int> myMaxColours{{"red",0},{"green",0},{"blue",0}};
        vector<string> temp;
        char* dup = strdup(line.c_str());
        char* token = strtok(dup, delimit);
        int gameNum = stoi(strtok(NULL, delimit));
        while (token != nullptr)
        {
            token = strtok(NULL, delimit);
            
            if (token != nullptr)
            {
                temp.push_back(token);
            }
            
        }
        for (size_t i = 0; i < temp.size()-1; i+=2)
        {
            int currentNum = stoi(temp.at(i));
            string currentColour = temp.at(i+1);
            int maxNum = colourMap.at(currentColour);
            int currentMax = myMaxColours.at(currentColour);

            if (currentNum > maxNum)
            {
                possible = false;
            }
            if (currentNum > currentMax)
            {
                myMaxColours.at(currentColour) = currentNum;
            }
        }
        if (possible)
        {
            part1+=gameNum;
        }
        int productToAdd = 1;
        for (auto const& [key,val] : myMaxColours)
        {
            productToAdd *= val;
        }
        part2+=productToAdd;
    }    
    cout << "Part 1: " << part1 << endl;
    cout << "Part 2: " << part2 << endl;
}
