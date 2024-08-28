#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next; 
    
    // Node() {
    //     cout << "I am in default const" << endl;
    //     this->next = NULL;   
    
    Node(int data) {
        // cout << "I am in Param const" << endl;
        this->data = data;
        this->next = NULL; 
    }
};
void createTail(Node*head,Node*tail){
    Node*temp=head;
    while (temp->next !=NULL)
    {
        temp = temp->next;
       
    }
    tail=temp;
}


void printll(Node* head,) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
        //  count+=1;
    }
    cout << endl;
    
    // cout<<"The Size of linked List Is : "<<count<<endl;
}
void getLength(Node* head){
    node*temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;

    }
    return length;
}
void insertAtHead(Node*&head,Node *&tail,int data) {
    if(head==NULL){
        // Create a new Node
            Node* newNode = new Node(data);
                 head=newNode;
            tail=newNode;


    }
else{
    // Create a new Node
    Node* newNode = new Node(data);
    // Attach new node to head
    newNode->next = head;
    // Update head to point to the new node
    head = newNode;
}
}



void insertAtTail(Node*& head, Node*& tail,int data){
    if(head==NULL){
            Node* newNode = new Node(data);
            head=newNode;
            tail=newNode;

    }
    else{
        // create a new node
            Node* newNode = new Node(data);

// tail node ko attach koro new node se
tail->next=newNode;
// updata tail
tail=newNode;

    }

}

void insertAtAnyPosition(Node*& head, Node*& tail,int data,int position){
    int length = getLength(head);
    if(position==1){
        insertAtHead(head,tail,data);
    }
    else if(position==length +1){
        insertAtTail(head,tail,data);

    }
    else{

    }
}

 

int main() {
    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* forth = new Node(40);
    // Node* fifth = new Node(50);
    //     Node* tail=fifth;

    
    // first->next=second;
    // second->next=third;
    // third->next=forth;
    // forth->next=fifth;
    // // fifth->next=NULL;
 
//  Node *head=NULL;
 int count =0;
//  cout<<"the linked list is"<<endl;
//  printll(head,count);
//  insertAtHead(head,01);
//  printll(head,count);
//   insertAtTail(head,60,tail);
//    printll(head,count);
Node*head=NULL;
Node*tail=NULL;
insertAtHead(head,tail,10);
insertAtHead(head,tail,20);
insertAtHead(head,tail,30);
printll(head,);
insertAtTail(head,tail,40);
printll(head,);



    return 0;

}
