//
//  Node.h
//  DataStructure
//
//  Created by SUMIT_THAKUR on 29/11/16.
//  Copyright © 2016 Sumit. All rights reserved.
//

//Node class
class Node
{
    int data ;
    Node *next;
    Node *previous;
    
public:
    explicit Node();
    explicit Node(int);
    void setData(int);
    void setNextPrevious( Node*,bool isNext = true );
    int getData() const;
    Node* getNextPrevious( bool isNext = true ) const;
    static Node* getNewNode( int value = 0 );
};


Node* Node::getNewNode( int value )
{
    Node* newNode;
    if (!value )
        newNode = new Node();
    else
        newNode = new Node(value);
    
    return newNode;
}

Node::Node(): data(0),
next(NULL),
previous(NULL)
{}


Node::Node(int value): data(value),
next(NULL),
previous(NULL)
{}

Node* Node::getNextPrevious( bool isNext ) const
{
    if(isNext)
        return ( this->next );
    else
        return this->previous;
}


int Node::getData() const
{
    return ( this->data );
}

void Node::setData(int value)
{
    
    this->data = value;
}


void Node::setNextPrevious(Node *nextPrevious, bool isNext)
{
    if(isNext)
        this->next = nextPrevious;
    else
        this->previous = nextPrevious;
}

