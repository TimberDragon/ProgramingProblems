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
    
    string commandLine = "";
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
                
                shortFlag = input.substr(0,indexOfSplit);
                
                shortFlags[shortFlag] = longFlag;
            }
        }
    }
    
    cin>>commandLine;
    while(commandLine.compare("\n") != 0)
    {
        if(commandLine.find("--") != string::npos)
        {
            cout<<"Flag: "<<commandLine.substr(2)<<endl;
        }else if(commandLine.find("-") != string::npos){
            for(int i = 1; i < commandLine.length(); i++)
            {
                string shortFlag = commandLine.substr(i,i);
                cout<<"Flag: " <<shortFlags[shortFlag]<<endl;
            }
        }else{
            cout<<"Parameter: "<<commandLine<<endl;
        }
        cin>>commandLine;
    }
    
    return 0;
}

