//
//  Q9_1.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/3/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <boost/unordered_map.hpp>
#include <iostream>

typedef boost::unordered_map<int, int> hashmap;

int countWayDP(int n, hashmap& h){
    if (h.find(n) != h.end()) {
        return h.at(n);
    }
    
    int q = 0;
    if (n < 0) {
        return 0;
    }else if (n == 0){
        q = 1;
    }else{
        q = countWayDP(n-1, h) + countWayDP(n-2, h) + countWayDP(n-3, h);
    }
    h[n] = q;
    return q;
}

int main(){
    hashmap h;
    std::cout << countWayDP(36, h) << std::endl;
    return 0;
    
}

