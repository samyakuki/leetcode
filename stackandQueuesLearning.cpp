#include <bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int size;
    int *arr;
    public:
    Stack(){
        top=-1;
        size=1000;
        arr=new int[size];
    }
    void push(int x){
         if (top >=size - 1) {
            cout << "Stack overflow" << endl;
            return ;
        }
        top++;
        arr[top]=x;
    }
    int pop(){
         if (top < 0) {
            cout << "Stack underflow!" << endl;
            return -1; 
        }
        int x=arr[top];
        top--;
        return x;
    }
    int Top(){
         if (top < 0) {
            cout << "Stack is Empty!" << endl;
            return -1; 
        }
        return arr[top];

    }
    int Size(){
        return top+1;
    }
    bool isEmpty(){
        return (top < 0);
    }
};


class Queue {
    int front, rear, size;
    int* arr;
public:
    Queue(int s = 1000) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear >= size - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
    if (front > rear) {
        cout << "Queue Underflow!" << endl;
        return -1;
    }
    int x = arr[front];
    front++;  
    return x; 
    }

    int Front() {
        if ( front > rear) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    
    int Size() {
        return  (rear - front + 1);
    }

    bool isEmpty() {
        return (front > rear);
    }
};



class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLL {
    Node* topNode;

public:
    StackLL() {
        topNode = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    int pop() {
        if (!topNode) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return val;
    }

    int top() {
        if (!topNode) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

class QueueLL{
    Node* frontNode;
    Node* rearNode;

public:
    QueueLL() {
        frontNode = rearNode = nullptr;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (!rearNode) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    int dequeue() {
        if (!frontNode) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (!frontNode) rearNode = nullptr;
        delete temp;
        return val;
    }

    int front() {
        if (!frontNode) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return frontNode->data;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};


class MyStack {
    queue<int> q;

public:
    MyStack() {
    }
    
    void push(int x) {
          q.push(x);
        int n = q.size();
        for (int i = 1; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        
        return q.front();
    }
    
    bool empty() {
         return q.empty();
    }
};

class MyQueue {
      stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x); 

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }
    
    int peek() {
         return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
class MinStack {
    stack<int> s;
    stack<int> minS;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(minS.empty()|| val<=minS.top()) minS.push(val);
        
    }
    
    void pop() {
        if(s.top()==minS.top()){
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
      return  s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(c=='('||c=='['||c=='{') st.push(c);
            else{
                if(st.empty()) return false;
                char top=st.top();
                if((c==')'&& top!='(')||(c==']'&& top!='[')||(c=='}'&& top!='{')) return false;
                st.pop();
            }
        }
        return st.empty();
}


int main(){


    return 0;
}