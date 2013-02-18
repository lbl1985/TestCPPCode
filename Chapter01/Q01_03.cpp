//
//  Q1_3.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>

bool permutation(const std::string &str1, const std::string &str2){
    int r[256] = {0};
    
    size_t l1 = str1.size();
    size_t l2 = str2.size();
    int index;
    
    for (size_t i = 0; i < l1; i++) {
        index = (int)str1[i];
        r[index]++;
    }
    
    for (size_t i = 0; i < l2; i++) {
        index = (int)str2[i];
        if (--r[index] < 0) {
            return false;
        }
    }
    return true;
}

typedef std::pair<std::string, std::string> strpair;

int main(){
    std::vector<strpair> pairs;
    pairs.push_back(std::make_pair("apple", "papel"));
    pairs.push_back(std::make_pair("carrot", "tarroc"));
    pairs.push_back(std::make_pair("hello", "llloh"));
    
    size_t len = pairs.size();
    for (size_t i = 0; i < len; i++) {
        std::cout << pairs[i].first << ", " << pairs[i].second << ": " << permutation(pairs[i].first, pairs[i].second) << std::endl;
    }
}
