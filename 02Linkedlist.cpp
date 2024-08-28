#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }


};

//I want to insert a node right at the head of Linked List
void insertAtHead(Node* &head, Node* &tail, int data) {
        //check for Empty LL
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
        }
        else {
                //step1:
                Node* newNode = new Node(data);
                //step2:
                newNode -> next = head;
                //step3:
                head = newNode;
        }


}
//I want to insert a node right at the end of LINKED LIST
void insertAtTail(Node* &head,Node* &tail, int data) {
        if(head == NULL) {
                Node* newNode = new Node(data);
                head = newNode;
                tail = newNode;
                
        }
        else {
            //step1: creatae a node
            Node* newNode = new Node(data);
            //step2: connect woth tail ndoe
            tail->next = newNode;
            //step3: update tail;
            tail = newNode;
        }

}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void insertAtPosition(int data, int position, Node* &head, Node* &tail) {
        int len = findLength(head);
        
        if(position == 1) {
                insertAtHead(head, tail , data);
                return;
        }
        else if(position > len) {
                insertAtTail(head, tail, data);
                return;
        }
        else {
            Node* newNode = new Node(data);
            
            Node* prev = NULL;
            Node* curr = head;
            while(position != 1) {
                position--;
                prev = curr;
                curr = curr->next;
            }
            
            //step3:
            newNode -> next = curr;

            //step4:
            prev -> next = newNode;
            
        }
        
}
// void deleteNode(Node* &head,Node* &tail,int position){
//         int length =findLength(head);

//         if(head==NULL){
//                 cout<<"Can't Delete Bcz LL is empty"<<endl;

//         }
//         if(head==tail){
//                 Node*temp=head;
//                 delete temp;
//                 head=NULL;
//                 tail=NULL;

//         }
//          if(position==1){
//                 // delete form head 
//                 Node *temp =head;
//                 head=head->next;
//                 temp->next=NULL;
//                 delete temp;
//          }
//          else if (position==length){
//                 // delete the last node
//                 Node*prev=head;
//                 while(prev->next!=tail){
//                         prev=prev->next;
//                         prev->next=NULL;
//                         delete tail;
//                         tail=prev;

//                 }
//          }
//          else{
//                 // middle me koi node ko delete kar na hai
//                 Node*prev=NULL;
//                 Node*curr=head;
//                 while(position!=1){
//                         position--;
//                         prev=NULL;
//                         curr=curr->next;
//                 }
//                 prev->next=curr->next;
//                 curr->next=NULL;
//                 delete curr; 

//          }
// }

void deleteNode(Node* &head, Node* &tail, int position) {
    int length = findLength(head);

    if (head == NULL) {
        cout << "Can't Delete Because LL is empty" << endl;
        return;
    }

    if (head == tail) {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    if (position == 1) {
        // delete from head 
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (position == length) {
        // delete the last node
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        delete tail;
        tail = prev;
        tail->next = NULL;
        return;
    }

    // delete a node from the middle
    Node* prev = NULL;
    Node* curr = head;
    while (position > 1 && curr != NULL) {
        prev = curr;
        curr = curr->next;
        position--;
    }
    if (curr != NULL) {
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main() {

        Node* head = NULL;
        Node* tail = NULL;
        insertAtHead(head, tail,90);
        insertAtHead(head, tail,80);
        insertAtHead(head, tail,70);
        insertAtHead(head,tail, 60);
        insertAtHead(head, tail, 50);
        insertAtHead(head, tail, 40);


        print(head);
        cout << endl;
        int  length = findLength(head); // Move length declaration inside main
    cout << "Length of the linked list: " << length << endl;

                deleteNode(head,tail,5);
                        print(head);
                        

        return 0;
}
