//
//  Q2_1.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <string>
#include <boost/unordered_map.hpp>
#include "Random2DArray.cpp"

template <class T> void removeDuplicate(std::list<T> &l){
    typename boost::unordered_map<T, bool> h;
    typename std::list<T>::iterator iter = l.begin();
    while (iter != l.end()) {
        if (h.find(*iter) != h.end()) {
            iter = l.erase(iter);
        }else{
            h[*iter] = true;
            iter++;
        }
    }
}

template <class T>
void removeDuplicate2(std::list<T> &l) {
    typename std::list<T>::iterator archor = l.begin();
    typename std::list<T>::iterator runner;
    
    while (archor != l.end()) {
        runner = ++archor;
        archor--;
        while (runner != l.end()) {
            if (*archor == *runner) {
                runner = l.erase(runner);
            }else{
                runner++;
            }
        }
        archor++;
    }
}


int main(){
    std::list<int> list1 = getRandList(10, 0, 10);    
    
    std::cout << "random list:" << std::endl;
    printList(list1);
    std::cout << "remove duplicate" << std::endl;
    
    removeDuplicate(list1);
    printList(list1);
    
    std::list<std::string> list_str;
    list_str.push_back("Binlong");
    list_str.push_back("Minjie");
    list_str.push_back("Yihan");
    list_str.push_back("Binlong");
    
    printList(list_str);
    std::cout << " ========== " << std::endl;
    removeDuplicate2(list_str);
    printList(list_str);
    
    return 0;
}