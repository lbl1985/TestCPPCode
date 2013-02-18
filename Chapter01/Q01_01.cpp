//
//  Q1_1.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

bool checkIsAllUnique(const std::string & str){
    std::vector<bool> record(256, false);
    int s = (int)str.size();
    int index;
    for (int i = 0; i < s; i++) {
        index = (int)str[i];
        if (record[index]) {
            return 0;
        }
        record[index] = true;
    }
    return true;
}

bool checkIsAllUnique2(const std::string & str){
    int r;
    int index;
    size_t s = str.size();
    for (size_t i = 0; i < s; i++) {
        index = (int)str[i];
        if (r & (1 << index)) {
            return false;
        }
        r = r | (1 << index);
    }
    return true;
}

int main(){
    std::vector<std::string> str;
    str.push_back("abcde");
    str.push_back("hello");
    str.push_back("apple");
    str.push_back("kite");
    str.push_back("padle");
    
    size_t len = str.size();
    for (size_t i = 0; i < len; i++) {
        std::cout << str[i] << ": " << checkIsAllUnique(str[i]) <<  " : " << checkIsAllUnique2(str[i]) <<std::endl;
    }
    
}
