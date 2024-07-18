#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// Node class to create Node objects of Linked lists
class Node{
    public:
        int value;
        Node *next;

    Node(int value){
        this->value = value;
        this->next = NULL;
    }

};

int promptAndGet(string prompt = "Enter value"){

    cout << prompt;
    int value;
    cin >> value; 
    return value;
}

// Insert at the tail end of the linked list
Node* insertAtTail(Node *head, int value){

    Node *new_node  = new Node(value);

    if(head == NULL){
        head = new_node;
        return head;
    }

    Node *walker = head;
    while(walker != NULL && walker->next != NULL){
        walker = walker->next;
    }


    walker->next = new_node;

    return head;

}

// insert at the head of the linked lists
Node* insertAtHead(Node *head, int value){
    Node *new_node = new Node(value);
       
    new_node->next = head;
    head = new_node;

    return head;
}

// position is 1-based indexed
Node* insertInBetween(Node* head, int value, int pos){
    
    int count = 1;

    Node *walker = head;
    Node *new_node = new Node(value);

    while(count<pos-1 && walker != NULL){
        walker = walker->next;
        count++;
    }

    new_node->next=walker->next;
    if(pos == 1){ // nodes are 1-based indexed
        head = new_node;
    }else{
       walker->next = new_node;
    }
    
    return head;
}

// print linked list
void printList(Node *head){
    Node *walker = head;
    while(walker != NULL){
        cout << walker->value<<" ";
        walker = walker->next;
    }
    cout<<"\n";
}


int main() {

    cout << "1. Insert at tail \n2. Insert at head\n3.Insert in between\n4.Print\n5.Press any key to stop.\n";
    
    Node *head = NULL;

    while(true){
        
        int choice;

        cout<<"Select Option:";
        bool stop = false;

        cin >> choice;

        int value = 0;
        int pos = 0;
        switch (choice)
        {
            // Insert to tail
            case 1: value = promptAndGet();
                    head = insertAtTail(head, value); 
                    break;
            //insert to head
            case 2: value = promptAndGet();
                    head = insertAtHead(head, value);
                    break;
            //insert in between
            case 3: value = promptAndGet();
                    pos = promptAndGet("Enter Position to Insert");
                    head = insertInBetween(head, value, pos);
                    break;
            // print  Linked List
            case 4: printList(head); 
                    break;
            // stop the program
            default:stop = true;
                    break;
        }

        if(stop) break;
    }


    return 0;
}