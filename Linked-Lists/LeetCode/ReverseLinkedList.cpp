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

// reverse linked list - Recursive
Node* reverse_recursive(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* reversedHead =  reverse(head->next);

    head->next->next = head;
    head->next = NULL;
    return reversedHead;
}

Node* reverse_iterative(Node *head){

    Node* fwd = head;
    Node* back = NULL;

    while(fwd != NULL){
        Node* nextNode = fwd->next;
        fwd->next = back;
        back = fwd;
        fwd = nextNode;
    }

    return back;
}