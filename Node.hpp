//
//  Node.hpp
//  lol
//
//  Created by ZhangFan on 2018/11/1.
//  Copyright © 2018 ZhangFan. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include <string>
using namespace std;
class Node{
private:
    char _data;
    int _weigth;
    Node*_parent, *_left, *_right;
    
public:
    Node();
    Node(const char dat,int wei=0,Node* par=nullptr,Node* lef=nullptr,Node* rig=nullptr);
    
    //getter
    Node* left();
    Node* parent();
    Node* right();
    char data();
    int weigth();
    //setter
    void left(Node*);
    void parent(Node*);
    void right(Node*);
    void data(char);
    void weigth(int);
};
#endif /* Node_hpp */
