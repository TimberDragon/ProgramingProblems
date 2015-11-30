/* 
 * File:   StringTest.cpp
 * Author: TimberDragon
 * 
 * Created on November 29, 2015, 4:21 PM
 */

#include "StringTest.h"

StringTest::StringTest() {
}

StringTest::StringTest(const StringTest& orig) {
}

StringTest::~StringTest() {
}

// This function would have O(n^2). To do it much faster you can do a bucket sort
// where each bucket is a case-less character in the English language and just 
// pass through the string once returning false if you are about to add a 
// character to a bucket with a count of 1.
bool StringTest::isUniqueCharacters(std::string strInput) {
    for (int i = 0; i < strInput.length() - 1; i++) {
        for(int j = i + 1 ; j < strInput.length() -1; i++ ) {
            if(strInput.at(i) == strInput.at(j))
                return false;
        } 
    }

    return true;
}

// This function will map all the letters in the first input into a <char,int> map 
// Then it will decrement the value for each letter in the second until it 
// finishes the string
bool StringTest::isAnagram(std::string strInput1, std::string strInput2) {
    std::map<char,int> boxes;
    
    //if they are not equal in length then we don't even need to do a comparison
    if(strInput1.length() != strInput2.length())
        return false;
    
    //sort the first string into boxes
    for(int i = 0; i < strInput1.length(); i++) {
        char character = strInput2.at(i);
        std::map<char,int>::iterator it = boxes.find(character);
        if(it == boxes.end()){
            boxes.insert({character,1});
        }else{   
            int value = it->second;
            it->second = value + 1;
        }
    }
    
    //remove letters from map for second string input if an element is 0 before 
    //removal return false
    for(int j = 0; j < strInput2.length(); j++) {
        std::map<char,int>::iterator it = boxes.find(strInput2.at(j));
        if(it == boxes.end())
            return false;
        
        int value = it->second;
        if(value == 0)
            return false;
        it->second = value - 1;
    }
    
    return true;
}
