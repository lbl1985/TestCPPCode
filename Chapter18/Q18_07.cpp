//
//  Q18_07.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/3/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

typedef std::unordered_map<std::string, bool> hashmap;

bool beMadeUpOf(std::string const &str, bool isOriginal, hashmap &h){
    if (h.find(str) != h.end() && !isOriginal) {
        return h[str];
    }
    
    size_t s = str.size();
    for (int i = 0; i < s; i++) {
        std::string leftString(str.substr(0, i));
        std::string rightString(str.substr(i));
        if (h.find(leftString) != h.end() && h[leftString] && beMadeUpOf(rightString, false, h)) {
            return true;
        }        
    }
    h[str] = false;
    return false;    
}

std::string getLongestWord(std::vector<std::string> &vstr){
    hashmap h;
    for(const auto &x :vstr){
        h[x] = true;
    }
    
    std::sort(vstr.begin(), vstr.end(), [](std::string &str1, std::string &str2) -> bool{
        return str1.size() > str2.size();
    });
    
    for (auto const &x : vstr){
        bool checker = beMadeUpOf(x, true, h);
        if (checker) {
            return x;
        }
    }
    
    return std::string("");
}

int main(){
    
    std::vector<std::string> vstr = {"cat", "banana", "dog", "nana", "walk", "walker", "dogwalker"};
    
    
    
    std::sort(vstr.begin(), vstr.end(), [](std::string &str1, std::string &str2) -> bool{
        return str1.size() > str2.size();
    });
    
    for(auto const &x : vstr){
        std::cout << x << " ";
    }
    
    std::cout << std::endl;
    std::string res(getLongestWord(vstr));
    std::cout << getLongestWord(vstr) << std::endl;
    
}