//
//  Q17_12.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/20/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

template <class T>
void obtainPairs(std::vector<T> l, std::vector< std::pair<T, T> > &lpair, T sum){
    std::sort(l.begin(), l.end());
    int begin = 0;
    int end = int(l.size()-1);
    
    while (begin < end) {
        if ((l[begin] + l[end]) == sum) {
            lpair.push_back(std::pair<T, T>(l[begin], l[end]));
            end--;
        }else if( l[begin] + l[end] < sum){
            begin++;
        }else if( l[begin] + l[end] > sum){
            end--;
        }
    }    
}

int main(){
    int data[] = {9, 3, 6, 5, 7, -1, 13, 14, -2, 12, 0};
    int sum = 12;
    std::vector<int> lint(data, data + sizeof(data) / sizeof(int));
    std::vector< std::pair<int, int> > lpair;
    obtainPairs(lint, lpair, sum);
//    lpair.push_back(std::pair<int, int>(50, 50));
//    lpair.push_back(std::pair<int, int>(40, 60));
    
    for (std::vector< std::pair<int, int> >::const_iterator iter = lpair.cbegin(); iter != lpair.cend(); iter++) {
        std::cout << (*iter).first << " " << (*iter).second << std::endl;
    }
    return 0;
}