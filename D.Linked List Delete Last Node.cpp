#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node* next;
    Node* prev;
};

void InsertAtBeginning(Node*& head, int value)
{

    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

Node* Find(Node* head, int Value)
{

    while (head != NULL) {

        if (head->value == Value)
            return head;


        head = head->next;
    }

    return NULL;


}

void InsertAfter(Node* current, int value)
{

    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}


void InsertAtEnd(Node* head, int value) 
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void DeleteNode(Node*& head, Node*& NodeToDelete) 
{ 
    if (head == NULL || NodeToDelete == NULL) {
        return;
    }
    if (head == NodeToDelete) {
        head = NodeToDelete->next;
    }
    if (NodeToDelete->next != NULL) {
        NodeToDelete->next->prev = NodeToDelete->prev;
    }
    if (NodeToDelete->prev != NULL) {
        NodeToDelete->prev->next = NodeToDelete->next;
    }
    delete NodeToDelete;
}

void DeleteFirstNode(Node*& head) 
{
    if (head == NULL) {
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void DeleteLastNode(Node*& head) {
    
    /*
        1-Traverse the list to find the last node.
        2-Set the next pointer of the second-to-last node to NULL.
        3-Delete the last node.
    */

  //if the list is empty
if (head == NULL)
    return;

if (head->next == NULL)
{
    delete head;
    head = NULL;
    return;
}

Node* current = head;

// means at the end of the loop i will be standing at the node before the last node
while (current->next->next != NULL)
{
    current = current->next;
}
//after loop we have node that come befor last node 

Node* temp = current->next;
//here the temp have the last node .
current->next = NULL;
delete temp;
   
}


void PrintNodeDetails(Node* head)
{

    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";

}

// Print the linked list
void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
}


// Print the linked list
void PrintList(Node* head)

{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";

}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    PrintListDetails(head);

    DeleteLastNode(head);
  
    cout << "\n\n\nLinked List Contenet after delete last node:\n";
    PrintList(head);
    PrintListDetails(head);
    system("pause>0");

}
