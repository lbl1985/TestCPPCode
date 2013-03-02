//
//  Q09_06.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/1/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void addParen(std::vector< std::string> &list, char *a, int leftRem, int rightRem, int count){
    if (leftRem < 0 || rightRem < leftRem) {
        return;
    }
    
    if (leftRem == 0 && rightRem == 0) {
        std::string tmp(a);
        list.push_back(tmp);
    }else {
        if(leftRem > 0) {
            a[count] = '(';
            addParen(list, a, leftRem-1, rightRem, count+1);
        }
        if (rightRem > leftRem) {
            a[count] = ')';
            addParen(list, a, leftRem, rightRem-1, count+1);
        }
    }
}

int main(){
    int count = 3;
    char a[2*count];
    std::vector<std::string> res;
    addParen(res, a, count, count, 0);
    std::for_each(res.cbegin(), res.cend(), [](std::string const &str){
        std::cout << str << std::endl;
    });
//    delete [] a;
}
