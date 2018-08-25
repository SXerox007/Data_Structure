//Assignment-4 Stack
//Linked list
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Node.h"
#include "Linked_List.h"
using namespace std;
//class to implement some common funtion on linked list.
//functions are made static because we wont need to initialize object to use these functions.
class CommonFunctions
{
public:
    static void Push(LinkedList&,int);
    static void Pop(LinkedList&);
    static void Print_Linked_list(LinkedList&);
    static void max_min_find(LinkedList&);
};

//find maximum and minimum element in the linked list
void CommonFunctions::max_min_find(LinkedList& linkedlist)
{
    
    Node *start=linkedlist.getHeadLast();
    int max=linkedlist.maxx_minn(start,true);
    cout<<"Maximum element in the linked list is: "<<max<<endl;
    int min=linkedlist.maxx_minn(start,false);
    cout<<"Minimum element in the linked list is: "<<min<<endl;
}

//pop the element in the stack
void CommonFunctions::Pop(LinkedList& linkedlist)
{
    Node *a=linkedlist.getHeadLast();
    a=a->getNextPrevious();
    linkedlist.setHeadLast(a);
    linkedlist.decrease_total();
}

//add node in the first for performing push operation
void CommonFunctions::Push(LinkedList& linkedList,int value)
{
    Node *temp = linkedList.getHeadLast(true);
    Node *newNode = Node::getNewNode(value);
    if(temp==NULL){
        linkedList.setHeadLast(newNode);
    }
    else
    {
        linkedList.setHeadLast(newNode);
        newNode->setNextPrevious(temp);
        linkedList.setHeadLast(newNode);
    }
    if( linkedList.getTotalNodes() == 0)
        linkedList.setHeadLast(newNode);
    linkedList.setTotalNodes();
}

//Print the linked list
void CommonFunctions::Print_Linked_list(LinkedList &linkedlist)
{
    Node *a=linkedlist.getHeadLast();
    while(a!=NULL)
    {
        cout<<a->getData();
        a=a->getNextPrevious();
    }
}

//for main option which user can select to perform a specific task
void options()
{
    cout<<"Enter the option of the following: \n"<<"Press 1 for Enter to push the element in a stack \n"<<"Press 2 to print the linked list \n"<<"Press 3 for pop the element \n"<<"Press 4 for find the maximum and minimum element in the linked list \n"<<"Press 5 for the push the element in stack \n"<<"Press 6 for Compare 2 stack \n"<<"Press 7 for Reverse the stack1 \n";
}

int main()
{
    LinkedList linkedList;
    LinkedList linkedList3;
    LinkedList linkedList1;
    LinkedList::noOfLinkedLists++;
    int choice;
    
    while(1)
    {
        options();
        printf( "Enter your choice\n" );
        scanf("%d" ,&choice);
        switch(choice)
        {
            case 1:
                CommonFunctions::Push(linkedList, 5);
                CommonFunctions::Push(linkedList, 13);
                CommonFunctions::Push(linkedList, 10);
                CommonFunctions::Push(linkedList, 6);
                CommonFunctions::Push(linkedList, 8);
                CommonFunctions::Push(linkedList, 9);
                break;
            case 2:
                CommonFunctions::Print_Linked_list(linkedList);
                break;
            case 3:
                CommonFunctions::Pop(linkedList);
                break;
            case 4:
                CommonFunctions::max_min_find(linkedList);
                break;
            case 5:
                CommonFunctions::Push(linkedList1, 5);
                CommonFunctions::Push(linkedList1, 12);
                CommonFunctions::Push(linkedList1, 10);
                CommonFunctions::Push(linkedList1, 6);
                CommonFunctions::Push(linkedList1, 8);
                CommonFunctions::Push(linkedList1, 9);
                break;
            case 6:
                linkedList==linkedList1?
                cout<<"Equal stack \n":
                cout<<"Not Equal stack \n";
                break;
            case 7:
                !linkedList;
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
