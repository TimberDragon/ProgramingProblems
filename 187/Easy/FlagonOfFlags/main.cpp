/* 
 * File:   main.cpp
 * Author: TimberDragon
 *
 * Created on November 6, 2014, 12:19 AM
 */

#include <cstdlib>
#include <map>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    string commandLine;
    int numberOfInputs;
    std::map<string,string> shortFlags;
    std::map<string,string> longFlags;
    
    cin>>numberOfInputs;
    if(numberOfInputs != NULL)
    {
        for(int i = 0; i < numberOfInputs; i++)
        {
            string input = "";
            cin >> input;
            if(input.compare("") != 0)
            {
                int indexOfSplit;
                string shortFlag;
                string longFlag;
                
                indexOfSplit = input.find_first_of(":");
                
                shortFlag = input.substr(0,indexOfSplit-1);
                longFlag = input.substr(indexOfSplit+1);
                
                shortFlags[shortFlag] = longFlag;
                longFlags[longFlag] = shortFlag;
            }
        }
    }
    
    cin>>commandLine;
    
    return 0;
}

