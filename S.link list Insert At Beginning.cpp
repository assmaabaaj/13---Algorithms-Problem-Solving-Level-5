#include <iostream>
using namespace std;

// Create a node
class Node 
{
public:
    int value;
    Node* next;
};

void InsertAtBeginning(Node* &head, int value) 
{
    
    // Allocate memory to a node
    Node * new_node = new Node();

    // insert the data
    new_node->value = value;
    new_node->next = head;

    // Move head to new node
    head = new_node;
   
}

// ok what happen here that if we start with no node the linked list is empty the head = NULL 
// we wanna add a node it is the new_node ok so new Node() = Create a new Node in the Heap
// new_node->value = value; then   new_node->next = head;  this node will become the last node in the linked list after adding more (or can stay the only node in linked list)
// so head = new_node; this line will make the new_node->next = NULL.
// we wanna add more head pointing on the first node in the linked list and the first node is pointing to the node next (or pointing to NULL if there was one nod only)
// so the new_node will point the first node( what head is pointing to [for now ] and then we will let head point on the now node ) 
// the first node will become the next node that come after the new_node which is the first node in the linled list. 

// Print the linked list
void PrintList( Node* head) 

{
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main() 
{
    Node * head = NULL;

    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);

    PrintList(head);

    system("pause>0");

}





//Linked List Node contains :
//1. value->stores data
//2. next->points to the next node
//
//Insert At Beginning :
//1. Create a new node
//2. Store the value
//3. Point new_node->next to current head
//4. Move head to the new node
//
//Example :
//
//Insert 1 :
//    Head -> 1->NULL
//
//    Insert 2 :
//    Head -> 2 -> 1->NULL
//
//    Insert 3 :
//    Head -> 3 -> 2 -> 1->NULL
//
//    PrintList :
//Start from head
//Print current value
//Move to next node
//Stop when reaching NULL
//
//Time Complexity :
//Insert At Beginning = O(1)
//Print List = O(n)
