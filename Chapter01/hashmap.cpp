//
//  hashmap.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/3/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//
#include <boost/unordered_map.hpp>
#include <iostream>
#include <string>


int main(){
    typedef boost::unordered_map<std::string, int> hashmap;
    hashmap numbers;
    
    numbers["one"] = 1;
    numbers["two"] = 2;
    numbers["three"] = 3;
    
    boost::hash<std::string> hashfunc = numbers.hash_function();
    for (hashmap::const_iterator i = numbers.begin(), e = numbers.end(); i != e; ++i) {
        std::cout << i->first << " -> " << i->second << " (hash = " << hashfunc( i->first) << ")" << std::endl;
        std::cout << (numbers.find(i->first) == numbers.end()) << std::endl;
        
    }
//    
    std::cout << (numbers.find("missing") == numbers.end()) << std::endl; 
    return 0;
}
