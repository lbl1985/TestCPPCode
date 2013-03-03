//
//  Q2_5.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "../Utility/Random2DArray.cpp"
void addList(std::list<int> const &list1, std::list<int> const &list2, std::list<int> &sum){
//    std::list<int> sum;
    int carry = 0;
    int tmp = 0;
    
    std::list<int>::const_iterator iter1 = list1.cbegin();
    std::list<int>::const_iterator iter2 = list2.cbegin();
    
    while (iter1 != list1.end() || iter2 != list2.end()) {
        
        tmp = carry;
        if (iter1 != list1.end()) {
            tmp += *iter1;
        }
        
        if(iter2 != list2.end()){
            tmp += *iter2;
        }
        
        if (tmp >= 10) {
            carry = 1;            
        }else{
            carry = 0;
        }
        
        sum.push_back((int)tmp%10);
        if (iter1 != list1.end()) {
            iter1++;
        }
        if (iter2 != list2.end()) {
            iter2++;
        }
    }
    
    if (carry == 1) {
        sum.push_back(1);
    }
}

int main(){
    std::list<int> list1 = util::getRandList(3, 0, 9);
    std::list<int> list2 = util::getRandList(5, 0, 9);
    std::cout << "list1 = ";
    util::printList(list1);
    std::cout << "list2 = ";
    util::printList(list2);
    
    std::list<int> sum;
    addList(list1, list2, sum);
    std::cout << "sum   = ";
    util::printList(sum);
}
