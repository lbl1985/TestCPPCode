//
//  Q02_03.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/26/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "../Utility/DoubleLinkList_sharedPointer.cpp"

template <class T>
bool deleteNode(std::shared_ptr<T> node) {
    if (!node || !node->next ) {
        return false;
    }
    std::shared_ptr<T> next = node->next;
    node->next = next->next;
    node->data = next->data;
    return true;
}


int main(){
    util::DoubleLinkList<int> l;
    util::genearteRandomDoubleLinkedList(l, 10, 0, 5);
    l.displayNodeForward();
    
    deleteNode<util::Node<int> >(l.begin()->next->next->next->next);
    l.displayNodeForward();
    
    return 0;
}