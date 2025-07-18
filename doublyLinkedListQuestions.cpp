#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

Node* insertEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (!head) return newNode;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteAllOccurrences(Node* head, int key) {
    Node* temp = head;
    while (temp) {
        if (temp->data == key) {
            Node* toDelete = temp;
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

void findPairsSorted(Node* head, int target) {
    Node* first = head;
    Node* second = head;
    while (second->next) second = second->next;
    bool found = false;
    while (first && second && first != second && second->next != first) {
        int sum = first->data + second->data;
        if (sum == target) {
            cout << "(" << first->data << ", " << second->data << ")\n";
            found = true;
            first = first->next;
            second = second->prev;
        } else if (sum < target) {
            first = first->next;
        } else {
            second = second->prev;
        }
    }
    if (!found) cout << "No pairs found with sum " << target << " in sorted DLL.\n";
}

void findPairsUnsorted(Node* head, int target) {
    unordered_set<int> seen;
    bool found = false;
    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        int complement = target - curr->data;
        if (seen.count(complement)) {
            cout << "(" << complement << ", " << curr->data << ")\n";
            found = true;
        }
        seen.insert(curr->data);
    }
    if (!found) cout << "No pairs found with sum " << target << " in unsorted DLL.\n";
}

void removeDuplicates(Node* head) {
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node* duplicate = curr->next;
            curr->next = duplicate->next;
            if (duplicate->next)
                duplicate->next->prev = curr;
            delete duplicate;
        } else {
            curr = curr->next;
        }
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* sortedHead = nullptr;
    Node* unsortedHead = nullptr;

    vector<int> sortedValues = {1, 2, 2, 3, 4, 4, 5, 6};
    for (int val : sortedValues)
        sortedHead = insertEnd(sortedHead, val);

    cout << "Original Sorted DLL: ";
    printList(sortedHead);

    removeDuplicates(sortedHead);
    cout << "After removing duplicates: ";
    printList(sortedHead);

    sortedHead = deleteAllOccurrences(sortedHead, 3);
    cout << "After deleting all 3s: ";
    printList(sortedHead);

    cout << "Pairs with sum 7 (sorted DLL):\n";
    findPairsSorted(sortedHead, 7);

    vector<int> unsortedValues = {5, 3, 2, 1, 4, 2};
    for (int val : unsortedValues)
        unsortedHead = insertEnd(unsortedHead, val);

    cout << "\nOriginal Unsorted DLL: ";
    printList(unsortedHead);

    cout << "Pairs with sum 6 (unsorted DLL):\n";
    findPairsUnsorted(unsortedHead, 6);

    return 0;
}
