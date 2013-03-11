//
//  Q18_08.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/10/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

class SuffixTreeNode;

typedef std::unordered_map<char, std::shared_ptr<SuffixTreeNode> > hashmap;

class SuffixTreeNode {
    hashmap children;
    char value;
    std::vector<int> indexes;
public:
    void insertString(std::string s, int index){
        indexes.push_back(index);
        if (s.size()>0) {
            value = s.at(0);
            std::shared_ptr<SuffixTreeNode> child;
            if (children.find(value) != children.end()) {
                child = children[value];
            }else{
                child.reset(new SuffixTreeNode());
                children[value] = child;
            }
            std::string remain(s.substr(1));
            child->insertString(remain, index);
        }
    }
    
    std::vector<int> search(std::string s){
        if (s.length() == 0) {
            return indexes;
        }else{
            char first = s.at(0);
            if (children.find(first) != children.end()) {
                std::string remain(s.substr(1));
                return children[first]->search(remain);
            }
        }
        
        std::vector<int> tmp;
        return tmp;
    }
};

class SuffixTree {
    std::shared_ptr<SuffixTreeNode> root;
    
public:
    SuffixTree(const std::string &s){
        root.reset(new SuffixTreeNode);
        
        for (int i = 0; i < s.size(); i++) {
            std::string remain = s.substr(i);
            root->insertString(remain, i);
        }
    }
    
    std::vector<int> search(std::string s){
        return root->search(s);
    }
};

int main(){
    std::string testString("mississippi");
    std::string stringList[] = {"is", "sip", "hi", "sis"};
    SuffixTree *tree = new SuffixTree(testString);
    for (const auto &x : stringList){
        std::vector<int> list = tree->search(x);
        if (!list.empty()) {
            std::cout << x << ": ";
            for (const auto &y: list){
                std::cout << y << " ";
            }
            std::cout << std::endl;
        }else{
            std::cout << x << ": not found" << std::endl;
        }
    }
}