//
//  Q02_07.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/26/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include "../Utility/DoubleLinkList_sharedPointer.cpp"

bool checkPattern(std::shared_ptr< util::Node<int> >  const &begin){
    auto slow = begin;
    auto fast = begin;
    std::stack<int> st;
    
    while (fast != NULL && fast->next != NULL) {
        st.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (fast != NULL) {
        slow = slow->next;
    }
    
    while (slow != NULL ) {
        int tmp = st.top();
        if (tmp != slow->data) {
            return false;
        }
        slow = slow->next;
        st.pop();
    }
    return true;    
}


int main(){
    int k = 7;
    std::vector< std::shared_ptr< util::Node< int > > >nodeList;
    
    for (int i = 0; i < k; i++) {
        nodeList.push_back(std::shared_ptr< util::Node<int> >(new util::Node<int>(i)));
        if (i > 0) {
            nodeList[i-1]->next = nodeList[i];
        }
    }
    
    for (int i = 0; i <= k; i++) {
        nodeList.push_back(std::shared_ptr< util::Node<int> >(new util::Node<int>(k-i)));
        nodeList[k + i-1]->next = nodeList[k+i];
    }
    
    std::shared_ptr< util::Node<int> > cur = nodeList[0];
    
    while (cur != NULL) {
        std::cout << cur->data << " ";
        cur = cur->next;
    }    
    std::cout << std::endl;
    
    std::cout << "This sequence is sysmetric? " << checkPattern(nodeList[0]);
    return 0;
}