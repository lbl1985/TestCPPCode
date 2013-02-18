//
//  Q1_5.cpp
//  aabcccccaaa -> a2b1c5a3
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>



// How many char after the compression
int compressionTest(const std::string &str){
    int size = 0;
    char last = str[0];
    int count = 1;
    size_t s = str.size();
    
    for (size_t i = 1; i < s; i++) {
        if (last == str[i]) {
            count++;
        }else{
            size += 1 + boost::lexical_cast<std::string>(count).size();
            last = str[i];
            count = 1;
        }
    }
    size += 1 + boost::lexical_cast<std::string>(count).size();
    return size;
}

// compress the string
std::string compressString(const std::string &str){
    int size = compressionTest(str);
    int s = (int)str.size();
        
    if (size > s) {
        return str;
    }
    std::string strDst;
    
    char last = str[0];
    int count = 1;

    for (int i = 1; i < s; i++) {
        if (last == str[i]) {
            count++;
        }else{
            strDst = strDst + last;
            strDst = strDst + boost::lexical_cast<std::string>(count);
            last = str[i];
            count = 1;
        }
    }
    strDst = strDst + last;
    strDst = strDst + boost::lexical_cast<std::string>(count);
    return strDst;   
    
}

int main(){
    std::string str = "abbcccccde";
//    std::string str = "aa";
    std::cout << str << " after compression: " << compressString(str) << std::endl;
    return 0;
}
