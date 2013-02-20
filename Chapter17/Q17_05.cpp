//
//  Q17_05.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/18/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//


#include <string>
#include <iostream>

const int max_size = 4;

int getCode(char code){
    switch (code) {
        case 'R':
            return 0;
        case 'G':
            return 1;
        case 'B':
            return 2;
        case 'Y':
            return 3;
        default:
            return -1;
    }
}

// if any answer contains invalidate color, will return false
bool getHit(std::string const guess, std::string const solution, int &hit, int &psudoHit){
    hit = 0;
    psudoHit = 0;
    size_t sg = guess.size();
    size_t ss = solution.size();
    if (sg != ss) {
        return false;
    }
    
    int frequence[max_size];
    for (int i = 0; i < max_size; i++) {
        frequence[i] = 0;
    }
    
    for (int i = 0; i < ss; i++) {
        if (getCode(solution[i]) == -1 || getCode(guess[i]) == -1 ) {
            return false;
        }
        
        if (guess[i] == solution[i]) {
            hit++;
        }else{
            frequence[getCode(solution[i])]++;
        }
    }
    
    for (int i = 0; i < sg; i++) {
        if (guess[i] != solution[i]) {
            if (frequence[getCode(guess[i])] > 0) {
                psudoHit++;
                frequence[getCode(guess[i])]--;
            }
        }
    }
    return true;
}

int main(){
    std::string solution("RGBY");
    std::string guess("YGBG");
    int hit = 0;
    int psudoHit = 0;
    if (getHit(guess, solution, hit, psudoHit)) {
        std::cout << hit << " hit(s) and " << psudoHit << " psudoHit(s)." << std::endl;
    }else{
        std::cout << "invalidate" << std::endl;
    }
    return 0;
}