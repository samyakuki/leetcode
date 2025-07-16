#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val, head);
    return temp;
}
Node* insertTail(Node* head, int val) {
    Node* temp = new Node(val);
    if (head == nullptr) return temp;

    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

Node* insertMiddle(Node* head, int pos, int val) {
    if (pos == 1) return insertHead(head, val);

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    if (curr == nullptr) return head; 
    Node* temp = new Node(val, curr->next);
    curr->next = temp;
    return head;
}

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* curr = head;
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;
    return head;
}

Node* deleteMiddle(Node* head, int pos) {
    if (head == nullptr) return nullptr;
    if (pos == 1) return deleteHead(head);

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != nullptr; i++) {
        curr = curr->next;
    }

    if (curr->next == nullptr) return head;

    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}
int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == desiredElement)
            return 1; 

        temp = temp->next;
    }

    return 0;  
}
Node*reversal(Node*head){
    if(head==nullptr||head->next==nullptr) return head;
    Node*curr=reversal(head->next);
    head->next->next=head;
    head->next=head;
    return curr;

}
int main() {
    Node* head = nullptr;

    head = insertHead(head, 10); // 10
    head = insertTail(head, 30); // 10 -> 30
    head = insertMiddle(head, 2, 20); // 10 -> 20 -> 30
    cout << "List after insertions: ";
    printLL(head);

    head = deleteHead(head); // 20 -> 30
    cout << "After delete head: ";
    printLL(head);

    head = deleteTail(head); // 20
    cout << "After delete tail: ";
    printLL(head);

    head = insertTail(head, 40); // 20 -> 40
    head = insertTail(head, 50); // 20 -> 40 -> 50
    head = deleteMiddle(head, 2); // delete 40
    cout << "After delete position 2: ";
    printLL(head);

    return 0;
}
