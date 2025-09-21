#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL){}
};

class LinkedList{
    Node* head;
    public:
        LinkedList() :  head(NULL){}


    void insertAthead(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    } 
    
    void deleteHead(){
        if(!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteTail(){
        if(!head) return;
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void deleteNode(int val){
        if(!head) return;
        if(head->data == val){
            deleteHead();
            return;
        }
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != val){
            temp = temp->next;
        }
        if(temp->next == NULL) return;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};