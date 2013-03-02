//
//  Q09_05.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/1/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> getPermutations(std::string const &str, int index){
    std::vector<std::string> substrings;
    if (index == 0) {
        substrings.push_back(str.substr(index, 1));
    }else{
        std::string current(str.substr(index, 1));
        std::vector<std::string> copy(getPermutations(str, index-1));
        std::for_each(copy.cbegin(), copy.cend(), [&substrings, current](std::string const &tmp){
            for (int i = 0; i <= tmp.size(); i++) {
                substrings.push_back(tmp.substr(0, i) + current + tmp.substr(i));
            }
        });
    }
    return substrings;
}

int main(){
    std::string str("1234");
//    for (int i = 0; i <= str.size(); i++) {
//        std::cout << str.substr(0, i) + "a" + str.substr(i) << std::endl;
//    }
//    std::cout << str.substr(0, 1) << std::endl;
    
    std::vector<std::string> strPermutation = getPermutations(str, (int)(str.size()-1));
    std::cout << "There are total " << strPermutation.size() << " Permutations" << std::endl;
    std::for_each(strPermutation.cbegin(), strPermutation.cend(), [](std::string const &tmp){
        std::cout << tmp << std::endl;
    });
    
    return 0;
}
