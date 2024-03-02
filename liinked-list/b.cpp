/* Find the middle of a given linked list */
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

void middleElement(node* root){
    if(root == NULL){
        return;
    }
    node* slow = root;
    node* fast = root;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

int main(){
    node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    middleElement(head);
    return 0;
}