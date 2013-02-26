//
//  Q02_04.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/26/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "../Utility/DoubleLinkList_sharedPointer.cpp"
//#include "../Utility/DoubleLinkList.cpp"

template <class T>
std::shared_ptr< util::Node<T> > partition(util::DoubleLinkList<T> &l, T x){
    std::shared_ptr<util::Node<T> > beforeList;
    std::shared_ptr<util::Node<T> > afterList;
    
    std::shared_ptr<util::Node<T> > cur = l.begin();
    
    
    while (cur != NULL) {
        std::shared_ptr<util::Node<T> > next = cur->next;
        if (cur->data < x) {
            cur->next = beforeList;
            beforeList = cur;
        }else{
            cur->next = afterList;
            afterList = cur;
        }
        cur = next;
    }
    
    if (beforeList == NULL) {
        return afterList;
    }
    
    cur = beforeList;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    
    cur->next = afterList;
    return beforeList;    
}

int main(){
    util::DoubleLinkList<int> l;
    util::genearteRandomDoubleLinkedList(l, 10, 0, 5);
    l.displayNodeForward();
    
    std::shared_ptr<util::Node<int> > node = partition(l, 3);
    
    while (node) {
        std::cout << node->data << " ";
        node = node->next;
    }
    
    return 0;
}
