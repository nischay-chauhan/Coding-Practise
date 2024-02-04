/* Reverse the linked list */
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* newNode(int data){
    node* n = new node();
    n->data = data;
    n->next = NULL;
    return n;
}

void printList(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

void reverseLinkedList(node* &head){
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    head = prev;

}


int main(){
    node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    printList(head);
    cout << endl;
    reverseLinkedList(head);
    printList(head);
    return 0;
}