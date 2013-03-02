//
//  Q09_04.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/1/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// recursive
std::vector< std::vector<int> > getSubsets(int const *arr, int index){
    std::vector< std::vector<int> > subsets;
    if (index == 0) {
        std::vector<int> tmp;
        subsets.push_back(tmp);
        tmp.push_back(arr[index]);
        subsets.push_back(tmp);
    }else{
        int current = arr[index];
        subsets = getSubsets(arr, index - 1);
        std::vector<std::vector<int> > subsetscopy(subsets);
        std::for_each(subsets.begin(), subsets.end(), [current](std::vector<int> &tmp){
            tmp.push_back(current);
        });
        std::for_each(subsetscopy.cbegin(), subsetscopy.cend(), [&subsets](std::vector<int> const &tmp){
            subsets.push_back(tmp);
        });
    }
    return subsets;
}

std::vector<int> convertInt2Set(int const *arr, int k, int n){
    std::vector<int> tmp;
    for (int i = 0; i <= n; i++) {
        if ( ((k>>i) & 1) == 1 ) {
            tmp.push_back(arr[i]);
        }
    }
    return tmp;
}

std::vector< std::vector<int> > getSubsets2(int const *arr, int n){
    std::vector< std::vector<int> > subsets;
    int max = static_cast<int>(std::pow(2, n));
    for (int i = 0; i < max; i++) {
        std::vector<int> tmp = convertInt2Set(arr, i, n);
        subsets.push_back(tmp);
    }
    return subsets;
}

int main(){
    int set[] = {0, 1, 2, 3};
//    std::vector< std::vector<int> > res = getSubsets(set, sizeof(set)/sizeof(int) - 1);
    std::vector< std::vector<int> > res = getSubsets2(set, sizeof(set)/sizeof(int));
    std::for_each(res.cbegin(), res.cend(), [](std::vector<int> const &tmp){
        if (tmp.empty()) {
            std::cout << "[]" << std::endl;
        }else{
            std::for_each(tmp.cbegin(), tmp.cend(), [](int i){
                std::cout << i << " ";
            });
            std::cout << std::endl;
        }
    });
}
