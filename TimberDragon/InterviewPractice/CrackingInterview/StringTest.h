/* 
 * File:   StringTest.h
 * Author: TimberDragon
 *
 * Created on November 29, 2015, 4:21 PM
 */
#include <string>
#include <Algorithm>
#include <map>
#ifndef STRINGTEST_H
#define	STRINGTEST_H

class StringTest {
public:
    StringTest();
    StringTest(const StringTest& orig);
    virtual ~StringTest();
    bool isUniqueCharacters(std::string strInput);//1.1
    bool isAnagram(std::string strInput1, std::string strInput2);//1.4
private:

};

#endif	/* STRINGTEST_H */

