#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val) , left(NULL) , right(NULL) {}
};

class DoubleLinkedList{
    Node* head;
    Node* tail;
    public:
        DoubleLinkedList() : head(NULL) , tail(NULL){}

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->left = NULL;
        newNode->right = head;
        head->left = newNode;
        head = newNode;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->left = tail;
        newNode->right = NULL;
        tail->right = newNode;
        tail = newNode;
    }

    void deleteHead(){
        if(!head) return;
        Node* temp = head;
        head = head->right;
        if (head) {
            head->left = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    void deleteTail(){
        if(!head) return;
        Node* temp = tail;
        tail = tail->left;
        if (tail) {
            tail->right = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }

    void deleteNode(int val){
        if(!head) return;
        if(head->data == val){
            deleteHead();
            return;
        }

        Node* temp = head;
        while (temp && temp->data != val) {
            temp = temp->right;
        }
        if (!temp) return;

        if (temp->left) temp->left->right = temp->right; else head = temp->right;
        if (temp->right) temp->right->left = temp->left; else tail = temp->left;

        delete temp;
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }
};

int main(){

}