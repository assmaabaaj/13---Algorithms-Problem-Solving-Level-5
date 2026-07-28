#include <iostream>
using namespace std;

// Create a node
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


void DeleteNode(Node*& head, Node*& NodeToDelete) {
    

    /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
        3-Delete the current node.
    */
   //means the is no node in the list
 if (head == NULL || NodetoDelete == NULL)
     return;
 //means if there is one node only  head = NodetoDelete->next; which mean null
 if (head == NodetoDelete)
     head = NodetoDelete->next;

 //means that there are more node after the NodetoDelete
 if (NodetoDelete->next != NULL)
     NodetoDelete->next->prev = NodetoDelete->prev;
  // i am standing on the node i wanna delete (NodetoDelete) then 
 // NodetoDelete->next so now i stand on the next node that code after the one i wanna delete
// NodetoDelete->next->prev and i wanna chanege the prev for the node that come after NodetoDelete


 // means that the node to delete is not the first one in the list
 if (NodetoDelete->prev != NULL)
     NodetoDelete->prev->next = NodetoDelete->next;
 //i am standing at the NodetoDelete then NodetoDelete->prev so 
 //i stand now at the node that is before the NodetoDelete and
 // i wanna the node that come befor NodetoDelete its next pinter be pointing to : NodetoDelete->prev->next 

 delete NodetoDelete;
   
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

    //Traverse the list to find the node to be deleted.
    Node* N1 = Find(head, 4);

    DeleteNode(head, N1);
   
    cout << "\n\n\nLinked List Contenet after delete:\n";
    PrintList(head);
    PrintListDetails(head);
    system("pause>0");

}
