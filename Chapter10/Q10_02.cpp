//
//  Q10_02.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/28/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <boost/unordered_map.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef boost::unordered_map<string, vector<string> > hashmap;
int main(){
    hashmap h;
    string s0("bcda");
    string s1("cdba");
    string s2("ddba");
    string s3("dbac");
    
    std::vector<std::string> original;
    std::vector<std::string> uniqueString;
    original.push_back(s0);     original.push_back(s1);
    original.push_back(s2);     original.push_back(s3);
    
    for_each(original.begin(), original.end(), [&h, &uniqueString](string s){
        string sorted(s);
        sort(sorted.begin(), sorted.end());
        if (h.find(sorted) == h.end()) {
            vector<string> tmp;
            tmp.push_back(s);
            h[sorted] = tmp;
            uniqueString.push_back(sorted);
        }else{
            vector<string> tmp = h[sorted];
            tmp.push_back(s);
            h[sorted] = tmp;
        }
    });
    
    for (int i = 0; i < uniqueString.size(); i++) {
        std::cout << uniqueString[i] << ": " <<  std::endl;
        std::vector<std::string> tmp = h[uniqueString[i]];
        for (int j = 0; j < tmp.size(); j++) {
            std::cout << tmp[j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;    
}

