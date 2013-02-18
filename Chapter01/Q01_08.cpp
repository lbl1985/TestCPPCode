//
//  Q1_8.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <string>

bool isSubstring(std::string const &strSrc, std::string const &strQuery){
    if (strSrc.find(strQuery) != std::string::npos) {
        return true;
    }
    return false;
}

bool isRotate(std::string const &str1, std::string const &str2){
    size_t s = str1.size();
    if (s != 0 && str1.size() == str2.size()) {
        return isSubstring(str1+str1, str2);
    }
    return false;
}

int main(){
    std::string str1("waterbottle");
    std::string str2("erbottlewat");
    std::cout << isRotate(str1, str2) << std::endl;
    return 0;
}