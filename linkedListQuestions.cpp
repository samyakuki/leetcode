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
Node* deleteMiddle(Node* head) {
        if (!head || !head->next) return nullptr;

        Node* prev = nullptr;
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = slow->next;  
        delete slow;  

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


Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;  

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
}

Node* merge(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* temp = dummy;

        while (l1 && l2) {
            if (l1->data < l2->data) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = l1 ? l1 : l2;
        return dummy->next;
}

Node* sortList(Node* head) {
        if (!head || !head->next) return head;

        Node* mid = getMid(head);
        Node* right = mid->next;
        mid->next = nullptr;

        Node* leftSorted = sortList(head);     
        Node* rightSorted = sortList(right);

        return merge(leftSorted, rightSorted);
}

Node *getIntersectionNode(Node *headA, Node *headB) {
        Node*d1=headA;
        Node*d2=headB;
        while(d1!=d2){
            d1=d1==nullptr?headB:d1->next;
            d2=d2==nullptr?headA:d2->next;
        }

        return d1;
}
Node* addTwoNumbers(Node* l1, Node* l2) {
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        int carry=0;
        while(l1!=nullptr||l2!=nullptr||carry){
            int sum=0;
            if(l1!=nullptr){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2!=nullptr){
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            Node*node=new Node(sum%10);
            temp->next=node;
            temp=temp->next;
        }

        return dummy->next;
}
Node*reversal(Node*head){
        Node*temp=head;
        Node*prev=nullptr;
        while(temp!=nullptr){
            Node*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;
}
Node*getKth(Node*temp,int k){
        k-=1;
        while(temp!=nullptr&&k>0){
            k--;
            temp=temp->next;
        }
        return temp;
}
Node* reverseKGroup(Node* head, int k) {
        Node*temp=head;
        Node*prevLast=nullptr;
        while(temp!=nullptr){
            Node*kth=getKth(temp,k);
            if(kth==nullptr){
                if(prevLast) prevLast->next=temp;
                break;
            }
            Node*newNode=kth->next;
            kth->next=nullptr;
            reversal(temp);
            if(temp==head) head=kth;
            else prevLast->next=kth;
            prevLast=temp;
            temp=newNode;
        }
        return head;


}

Node* rotateRight(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;

        Node* temp = head;
        int len = 1;

        while (temp->next) {
            temp = temp->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        int steps = len - k;
        Node* curr = head;
        for (int i = 1; i < steps; i++) {
            curr = curr->next;
        }

        Node* newHead = curr->next;
        curr->next = nullptr;
        temp->next = head;  

        return newHead;
}
class CNode {
public:
    int data;
    CNode *next;
    CNode *child;

    CNode() : data(0), next(nullptr), child(nullptr) {};
    CNode(int x) : data(x), next(nullptr), child(nullptr) {}
    CNode(int x, CNode *nextNode, CNode *childNode) :
                    data(x), next(nextNode), child(childNode) {}
};
CNode* convertArrToLinkedList(vector<int>& arr){
    CNode* dummyNode = new CNode(-1);
    CNode* temp = dummyNode;

    for(int i = 0; i < arr.size(); i++){
        temp->child = new CNode(arr[i]); 
        
        temp = temp->child; 
    }
    return dummyNode->child; 
}

CNode* flattenLinkedList(CNode* head) {
    vector<int> arr;

    while (head != nullptr) {
        CNode* t2 = head;
        while (t2 != nullptr) {
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        head = head->next;
    }

    sort(arr.begin(), arr.end());
    return convertArrToLinkedList(arr);
}

class RNode {
public:
    int data;           
    RNode *next;        
    RNode *random;       

    RNode() : data(0), next(nullptr), random(nullptr){}; 
    RNode(int x) : data(x), next(nullptr), random(nullptr) {} 
    RNode(int x, RNode *nextNode, RNode *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};


RNode *cloneLL(RNode *head){
    RNode* temp = head;
    unordered_map<RNode*, RNode*> mpp;

    while(temp != NULL){
        RNode* newNode = new RNode(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    
    temp = head;
    while(temp != NULL){
        RNode* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    
    return mpp[head];
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
