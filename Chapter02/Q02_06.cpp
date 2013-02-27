//
//  Q02_06.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/26/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "../Utility/DoubleLinkList_sharedPointer.cpp"
#include <vector>

std::shared_ptr<util::Node<int> > findBeginning(std::shared_ptr<util::Node<int> > list){
    std::shared_ptr<util::Node<int> > slow = list;
    std::shared_ptr<util::Node<int> > fast = list;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }
    
    slow = list;
    
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main(){
    int listLength = 100;
    int k = 10;
    
    std::vector<std::shared_ptr<util::Node<int> > > list;
    for (int i = 0; i < listLength; i++) {
        list.push_back(std::shared_ptr<util::Node<int> >(new util::Node<int>(i)));
        if (i > 0) {
            list[i-1]->next = list[i];
        };
    }
    
//    std::shared_ptr<util::Node<int> > cur = list[0];
//    while (cur != NULL) {
//        std::cout << cur->data << " ";
//        cur = cur->next;
//    }
//    std::cout << std::endl;
    
    list[listLength-1]->next = list[listLength-k];
    std::shared_ptr<util::Node<int> > begin = findBeginning(list[0]);
    std::cout << "loop begin at: " << begin->data << std::endl;
    return 0;    
}


