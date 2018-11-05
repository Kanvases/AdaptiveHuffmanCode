//
//  Node.cpp
//  lol
//
//  Created by ZhangFan on 2018/11/1.
//  Copyright © 2018 ZhangFan. All rights reserved.
//

#include "Node.hpp"
//Node Realization
Node::Node():
_weigth(0),_parent(nullptr),_left(nullptr),_right(nullptr),_data(' '){};
Node::Node(const char dat,int wei,Node*par,Node*lef,Node*rig):
_data(dat),_weigth(wei),_parent(par),_left(lef),_right(rig){};

Node* Node::left(){
    return _left;
}
Node* Node::right(){
    return _right;
}
Node* Node::parent(){
    return _parent;
}
int Node::weigth(){
    return _weigth;
}
char Node::data(){
    return _data;
}

void Node::left(Node* tmp){
    _left=tmp;
}
void Node::right(Node* tmp){
    _right=tmp;
}
void Node::parent(Node* tmp){
    _parent=tmp;
}
void Node::weigth(int tmp){
    _weigth=tmp;
}
void Node::data(char tmp){
    _data=tmp;
}

