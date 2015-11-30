/* 
 * File:   main.cpp
 * Author: TimberDragon
 *
 * Created on November 29, 2015, 4:19 PM
 */

#include <cstdlib>
#include <iostream>
#include "StringTest.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    StringTest* StringT = new StringTest();
    
    bool unique = StringT->isUniqueCharacters("Test");
    
    cout << "Is unique: " << unique << '\n';
    
    bool anagram = StringT->isAnagram("Testing","qwertytr");
    
    cout << "Is Anagram: " << anagram << '\n';
    
    return 0;
}

