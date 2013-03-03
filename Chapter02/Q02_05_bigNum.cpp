//
//  Q02_05_bigNum.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/3/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

class Node{
public:
    int d;
    Node *prev;
    Node *next;
    Node(int _d):d(_d), prev(NULL), next(NULL){}
};

class PartSum{
public:
    Node *sum;
    int carry;
    PartSum():sum(NULL), carry(0){}
};

Node* insertBefore(Node *head, int _d){
    Node *tmp = new Node(_d);
    if (head != NULL) {
        tmp->next = head;
        head->prev = tmp;
    }    
    return tmp;
}

int length(Node *n){
    int count = 0;
    Node *cur = n;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

Node* convert2list(const std::string &str){
    Node *begin = NULL;
    Node *end = NULL;
    size_t s = str.size();
    for (int i = 0; i < s; i++) {
        Node *tmp = new Node(str[i] - '0');
        if (NULL == begin) {
            begin = tmp;
            end = tmp;
        }else{
            end->next = tmp;
            tmp->prev = end;
            end = tmp;
        }
    }
    return begin;
}

void printLinkList(Node *head){
    while (head != NULL) {
        std::cout << head->d << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void releaseLinkList(Node *head){
    while (head->next != NULL) {
        Node *next = head->next;
        delete head;
        head = next;
    }
    delete head;
    head = NULL;
}

Node* patchList(Node *head, int diff){
    for (int i = 0; i < diff; i++) {
        head = insertBefore(head, 0);
    }
    return head;
}

PartSum addLinkListHelper(Node *l1, Node *l2){
    if (l1 == NULL || l2 == NULL) {
        return PartSum();
    }
    
    PartSum tmpsum = addLinkListHelper(l1->next, l2->next);
    
    int val = l1->d + l2->d + tmpsum.carry;
    
    tmpsum.sum = insertBefore(tmpsum.sum, val % 10);
    tmpsum.carry = val / 10;
    
    return tmpsum;
}

Node* addLinkList(Node *l1, Node *l2){
    int c1 = length(l1);
    int c2 = length(l2);
    
    if (c1 > c2) {
        l2 = patchList(l2, abs(c1-c2));
    }else{
        l1 = patchList(l1, abs(c1-c2));
    }
    
    PartSum res = addLinkListHelper(l1, l2);
    
    if (res.carry == 0) {
        return res.sum;
    }else{
        return insertBefore(res.sum, 1);
    }
    
}

int main(){
    std::string str1("78910");
    std::string str2("33561");
    Node *numList1 = convert2list(str1);
    Node *numList2 = convert2list(str2);
    int c1 = length(numList1);
    int c2 = length(numList2);
    
    Node *patchNumList2 = patchList(numList2, abs(c1-c2));
    printLinkList(numList1);
    printLinkList(patchNumList2);
    
    Node *res = addLinkList(numList1, numList2);
    printLinkList(res);

    releaseLinkList(numList1);
    releaseLinkList(numList2);
    releaseLinkList(res);

}