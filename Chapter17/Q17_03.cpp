//
//  Q17_03.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/18/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>

int countZero(int num){
    if (num < 0) {
        return -1;
    }
    int count = 0;
    for (int i = 5; num/i > 0; i *= 5) {
        count += num/i;
    }
    return count;
}

int main(){
    for (int num = 0; num < 26; num++) {
        std::cout << "trailing for factorial " << num << " is: " << countZero(num) << std::endl;
    }
    
    return 0;
}