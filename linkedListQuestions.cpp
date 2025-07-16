#include<bits/stdc++.h>
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

bool detectLoop(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}
Node*detectStartingLoopNode(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            slow=head;

            while (slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;

            }
            
            return slow;
        }
    }
    return nullptr;
}

int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Loop detected, now count length
            int count = 1;
            Node* temp = slow->next;
            while (temp != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0; // No loop
}

Node*reverseLinkedList(Node*head){
    if(head==nullptr||head->next==nullptr) return head;
    Node*curr=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=head;
    return curr;

}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true; 
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;  
        fast = fast->next->next;  
    }
    
    Node* newHead = reverseLinkedList(slow->next);
    
    Node* first = head;  
    
    Node* second = newHead; 
    while (second != NULL) {
        
    
        if (first->data != second->data) {
            
           
            reverseLinkedList(newHead);  
            

            return false;
        }
        
        first = first->next; 
        
        second = second->next;  
    }
    
    reverseLinkedList(newHead);  
    
    return true;  
}

Node*segregate(Node*head){
    if (!head || !head->next) return head;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    

}

Node* removeNthFromEnd(Node* head, int n) {
    
        Node* fast = head;
        Node* slow = head;
        
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        if(fast==nullptr) return head->next; 

        while (fast->next!=nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        Node* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return head;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Create loop: 4 -> 2
    head->next->next->next->next = head->next;

    Node* loopStart = detectStartingLoopNode(head);
    if (loopStart != nullptr) {
        cout << "Loop detected! Starting at node with data: " << loopStart->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;


}
