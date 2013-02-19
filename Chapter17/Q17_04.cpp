//
//  Q17_04.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/18/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>

int flip(int bit){
    return 1^bit;
}

int sign(int in){
    return flip((in >> 31) & (0x01));
}

int getMax(int a, int b){
    int c = a - b;
    
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    
    int use_sign_a = sa ^ sb;
    int use_sign_c = flip(sa ^ sb);
    
    int sign = use_sign_a * sa + use_sign_c * sc;
    return sign*a + flip(sign) * b;
}

int main(){
    int a = 0;
    int b = 1;
    std::cout << getMax(a, b) << std::endl;
}
