//
//  Q02_03.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/26/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "../Utility/DoubleLinkList_sharedPointer.cpp"

template <class T>
void deleteNode(std::shared_ptr<T> node) {
    node->next = node->next->next;
    node->data = node->next->data;
    
}


int main(){
    util::DoubleLinkList<int> l;
    util::genearteRandomDoubleLinkedList(l, 10, 0, 5);
    l.displayNodeForward();
    
    deleteNode<util::Node<int> >(l.begin()->next->next->next->next);
    l.displayNodeForward();
    
    return 0;
}