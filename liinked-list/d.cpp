#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    
    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};



ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode *odd = head, *even = head->next, *evenHead = even;
    
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = evenHead;
    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    ListNode* result = oddEvenList(head);
    cout << "After oddEvenList: ";
    printList(result);

    // Create another sample list: 2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(5);
    head2->next->next->next->next = new ListNode(6);
    head2->next->next->next->next->next = new ListNode(4);
    head2->next->next->next->next->next->next = new ListNode(7);

    cout << "\nSecond test case - Original list: ";
    printList(head2);

    ListNode* result2 = oddEvenList(head2);
    cout << "After oddEvenList: ";
    printList(result2);

    return 0;
}