#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* pre;
    Node* next;

    Node() {
        this->pre = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->pre = NULL;
        this->next = NULL;
    }
};

void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->" ;
        temp = temp->next;
    }
}

int findLength(Node* &head) {
    Node* temp = head;
    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len; 
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        head->pre = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->pre = tail;
        tail = newNode;
    }
}


int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    print(head);
    insertAtTail(head,tail,60);
    cout<<endl;
    print(head);
}
