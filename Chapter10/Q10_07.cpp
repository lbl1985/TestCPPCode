//
//  Q10_07.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/1/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

class HtWt {
    int h;
    int w;
public:
    HtWt(int _h, int _w):h(_h), w(_w){}
    bool operator < (HtWt const &other) const;
    bool isBefore(HtWt const other) const;
    void print() const;
};

bool HtWt::operator<(const HtWt &other) const{
    if (this->h != other.h) {
        return this->h < other.h;
    }else{
        return this->w < other.w;
    }
}

bool HtWt::isBefore(const HtWt other) const{
    if (this->h < other.h && this->w < other.w) {
        return true;
    }else{
        return false;
    }
}

void HtWt::print() const{
    std::cout << h << " " << w << std::endl;
}

void initial(std::vector<HtWt> &items){
    items.push_back(HtWt(65, 60));
    items.push_back(HtWt(70, 150));
    items.push_back(HtWt(56, 90));
    items.push_back(HtWt(75, 190));
    items.push_back(HtWt(60, 95));
    items.push_back(HtWt(68, 110));
    items.push_back(HtWt(35, 65));
    items.push_back(HtWt(40, 60));
    items.push_back(HtWt(45, 63));
}

std::vector<HtWt> seqWithMaxLength(std::vector<HtWt> const &seq1, std::vector<HtWt> const &seq2){
    if (seq1.empty()) {
        return seq2;
    }
    if (seq2.empty()) {
        return seq1;
    }
    return seq1.size() >= seq2.size() ? seq1 : seq2;
}

void longestSequence(std::vector<HtWt> const &items, std::vector< std::vector<HtWt> > &solutions, int currentId){
    
    if (currentId >= items.size()) {
        return;
    }
    
    HtWt current(items[currentId]);    
    std::vector<HtWt> bestSeq;
    
    for (int i = 0; i < currentId; i++) {
        if (items[i].isBefore(current)) {
            bestSeq = seqWithMaxLength(bestSeq, solutions[i]);
        }
    }
    
    bestSeq.push_back(current);
    
    solutions.push_back(bestSeq);
    
    longestSequence(items, solutions, currentId+1);
    
}

std::vector<HtWt> longestSequence(std::vector<HtWt> &items){
    std::sort(items.begin(), items.end());
    std::vector< std::vector<HtWt> > solutions;
    
    longestSequence(items, solutions, 0);
    
    std::vector<HtWt> bestSeq;
    std::for_each(solutions.cbegin(), solutions.cend(), [&bestSeq](std::vector<HtWt> const &seq){
        bestSeq = seqWithMaxLength(bestSeq, seq);
    });
    return bestSeq;
}

int main(){
    std::vector<HtWt> items;
    initial(items);
    
    std::vector<HtWt> res = longestSequence(items);
    
    std::for_each(res.cbegin(), res.cend(), [](HtWt const &item){
        item.print();
    });
}