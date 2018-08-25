//
//  Linked_List.h
//  DataStructure
//
//  Created by SUMIT_THAKUR on 29/11/16.
//  Copyright © 2016 Sumit. All rights reserved.
//

class LinkedList
{
    Node *head;
    Node *last;
    int totalNodes;
    
public:
    explic  it LinkedList();
    void addNewValueAtLast(int);
    int getTotalNodes();
    void decrease_total();
    void setTotalNodes( bool isReset = false);
    void setHeadLast( Node*, bool isHead = true);
    Node* getHeadLast( bool isHead = true ) const;
    static int noOfLinkedLists;
    int maxx_minn(Node*,bool);
    bool operator == (LinkedList&);
    void operator!();
    
};

//Reverse the stack
void LinkedList::operator!()
{
    
    Node *head=getHeadLast();
    Node *temp=NULL,*r;
    while(head!=NULL)
    {
        r=head->getNextPrevious();
        head->setNextPrevious(temp);
        temp=head;
        head=r;
    }
    setHeadLast(temp);
}
 

//compare the two stack
bool LinkedList::operator==(LinkedList& linkedlist1)
{
    Node*a=this->getHeadLast();
    Node*b=linkedlist1.getHeadLast();
    while (a != NULL && b != NULL)
    {
        if (a->getData() != b->getData())
            return false;
        
        /* If we reach here, then a and b are not NULL and
         their data is same, so move to next nodes in both
         lists */
        a = a->getNextPrevious();
        b = b->getNextPrevious();
    }
    
    // If linked lists are identical, then 'a' and 'b' must
    // be NULL at this point.
    return (a==NULL && b==NULL);
}

//find maxx in the stack
int LinkedList::maxx_minn(Node *start,bool value)
{
    int temp=start->getData();
    start=start->getNextPrevious();
    if(value)
    {
        while (start!=NULL)
        {
            if(start->getData()>temp)
                temp=start->getData();
            start=start->getNextPrevious();
        }
    }
    else
    {
        while (start!=NULL)
        {
            if(start->getData()<temp)
                temp=start->getData();
            start=start->getNextPrevious();
        }
    }
    return temp;
}

//decrese the total
void LinkedList::decrease_total()
{
    this->totalNodes--;
}
int LinkedList::getTotalNodes()
{
    return this->totalNodes;
}

void LinkedList::setTotalNodes(bool isReset)
{
    if(isReset)
        this->totalNodes = 0;
    else
        totalNodes++;
    
    printf("total nodes are %d\n",totalNodes);
}

int LinkedList::noOfLinkedLists = 0;

LinkedList:: LinkedList(): head(NULL),
last(NULL),
totalNodes(0)
{
}

Node* LinkedList::getHeadLast( bool isHead ) const
{
    if ( isHead )
        return this->head;
    else
        return this->last;
}

void LinkedList::setHeadLast ( Node *headLast, bool isHead)
{
    if(isHead)
        this->head = headLast;
    else
        this->last = headLast;
}

