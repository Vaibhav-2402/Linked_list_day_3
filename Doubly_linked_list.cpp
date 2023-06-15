#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    
    //constructor
    Node(int d) {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    ~Node() {
        int val = this-> data;
        if (next != NULL){
            delete next;    
            next = NULL;
        }
    cout << " memory is freed for : " << this -> data << endl;
    }
};

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}

void InsertAtPosition(Node* &head, Node* &tail, int position, int d) {
    int cnt = 1;
    
    if(position == 1) {
        InsertAtHead(head, d);
        return;
    }
    
    Node* temp = head;
    
        while(cnt < position-1) {
            temp = temp -> next;
            cnt++;
        }
        if(temp -> next == NULL ) {
            InsertAtTail(tail, d);
            return;
        }
        
    Node* Nodetoinsert = new Node(d);
    Nodetoinsert -> next = temp -> next;
    Nodetoinsert -> prev = temp;
    temp -> next = Nodetoinsert;
    temp -> next -> prev = Nodetoinsert;
    
}

void DeleteNode(Node* &head, int position) {
    if(position == 1 ){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
        int cnt = 1;
        Node* previous = head;
        Node* current = head;
        while(cnt <= position-1) {
            previous = current;
            current = current -> next;
            cnt++;
        }
        
        current -> prev = NULL;
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

void print(Node* &head) {
    Node* temp = head;
    
    while( temp != NULL) {
        cout << temp -> data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);
    
    InsertAtHead(head, 89);
    print(head);
    Node* tail = node1;
    InsertAtTail(tail, 72);
    print(head);
    
    InsertAtPosition(head, tail, 3, 84);
    print(head);
    
    DeleteNode(head, 4);
    print(head);
    
    cout << "Head is " << head-> data << endl;
    cout << "tail is " << tail-> data << endl;
    return 0;
}