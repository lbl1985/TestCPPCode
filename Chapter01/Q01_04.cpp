//
//  Q1_4.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <memory>
// Since the string + is n^2 operation.
// The book solution may be more efficient
std::string replaceSpace(const std::string& str){
    std::string dst;
    size_t s = str.size();
    int begin = 0;
    int end = 0;
    for( ; end < s; end++){
        if (str[end] == ' ') {
            dst = dst + str.substr(begin, end-begin) + "%20";
            begin = end + 1;
        }
    }
    if (str[end] != ' ') {
        dst = dst + str.substr(begin);
    }
    return dst;
}

std::string replaceSpace2(const std::string &str){
    int space = 0;
    int s = (int)str.size();
    for (int i = 0; i < s; i++) {
        if (str[i] == ' ') {
            space++;
        }
    }
    
    int finalSize = s + 2 * space;
    
    char *tmpStr = new char[finalSize + 1];
    //    tmpStr[finalSize] = '\0';
//    char* p = tmpStr + finalSize - 1;
//    for (int i = s-1; i >= 0; i--) {
//        if (str[i] != ' ') {
//            *p = str[i];
//        }else{
//            *(--p) = '0';
//            *(--p) = '2';
//            *(--p) = '%';
//        }
//        --p;
//    }
    int p = finalSize - 1;
    for (int i = s - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            tmpStr[p] = str[i];
        }else{
            tmpStr[p--] = '0';
            tmpStr[p--] = '2';
            tmpStr[p] = '%';
        }
        p--;
    }
    std::string strDst(tmpStr);
    delete [] tmpStr;
    return strDst;
}

int main(){
    std::string str = "Mr Binlong Li";
    std::cout << replaceSpace2(str);
    
    return 0;
}