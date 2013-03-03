//
//  Q18_10.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/3/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <deque>
#include <boost/algorithm/string.hpp>
#include <stack>

typedef std::unordered_map<std::string, std::string> hashset;
typedef std::unordered_map<std::string, bool> hashBool;

std::vector<std::string> getWordModifyByOne(const std::string &str){
    size_t s = str.size();
    std::vector<std::string> modifiedWords;
    for (int i = 0; i < s; i++) {
        char current = str[i];
        for (char c = 'A'; c <= 'Z'; c++) {
            if (current != c) {
                std::string tmp(str);
                tmp[i] = c;
                modifiedWords.push_back(tmp);
            }
        }
    }
    return modifiedWords;
}

std::vector<std::string> transform(std::string str1, std::string str2, hashset dict){
    
    std::deque<std::string> actionList;
    hashBool visited;
    hashset backtrackMap;
    
    boost::to_upper(str1);
    boost::to_upper(str2);
    
    actionList.push_back(str1);
    visited[str1] = true;
    
    while (!actionList.empty()) {
        std::string word(actionList.front());
        actionList.pop_front();
        
        for(const auto &x : getWordModifyByOne(word)){
            if (x.compare(str2) == 0) { // finding the match
                std::vector<std::string> res;
                res.push_back(x);
                res.push_back(word);
                while (backtrackMap.find(word) != backtrackMap.end()) {
                    std::string prev = backtrackMap[word];
                    word = prev;
                    res.push_back(prev);
                }
                return res;
            }else{
                if (dict.find(x) != dict.end()) {
                    if (!visited[x]) {
                        actionList.push_back(x);
                        visited[x] = true;
                        backtrackMap[x] = word;
                    }
                    
                }
            }
        }
    }
}

hashset buildDict(std::vector<std::string> vs){
    hashset tmpDict;
    for (auto &x : vs){
        boost::to_upper(x);
        tmpDict[x] = "";
    }
    return tmpDict;
}

int main(){
    std::vector<std::string> dictStr{"maps", "tan", "tree", "apple", "cans", "help", "aped", "free", "apes", "flat", "fret", "trip", "trie", "frat", "fril"};
    hashset dict(buildDict(dictStr));
    std::vector<std::string> path(transform("tree", "flat", dict));
    std::stack<std::string> s;
    
    std::for_each(path.cbegin(), path.cend(), [&s](std::string const &str){
        s.push(str);
    });
    
    while (!s.empty()) {
        std::cout << s.top() << " -> ";
        s.pop();
    }
    std::cout << std::endl;
}
