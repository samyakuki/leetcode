#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s){
    int i=0;
    stack<char>st;
    string ans="";
    int n=s.length();
    while(i<n){
        if((s[i]>='A'&& s[i]<='Z')||(s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while (st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
            
        }
        else {
            while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        /* code */
    } 
    


    return ans;
}



string infixToPrefix(string s){
    reverse(s.begin(), s.end());
     for (char &c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    int i=0;
    stack<char>st;
    string ans="";
    int n=s.length();
    while(i<n){
        if((s[i]>='A'&& s[i]<='Z')||(s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while (st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            st.pop();
            
        }
        else {
            while (!st.empty() && prec(st.top()) > prec(s[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        /* code */
    } 
    

    reverse(ans.begin(), ans.end());
    return ans;
}

string postfixToInfix(string s){
    int i=0; stack<string>st;
    int n=s.length();
    while(i<n){
        if((s[i]>='A'&& s[i]<='Z')||(s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9')){
            st.push(string(1, s[i]));
        }
        else {
            string top1 = st.top(); 
            st.pop();
            string top2 = st.top(); 
            st.pop();
            string temp = "(" + top2 + s[i] + top1 + ")";
            st.push(temp);
        }
        i++;
    }
    return st.top();
}

string prefixfixToInfix(string s){
    int i=s.length()-1; stack<string>st;
    
    while(i>=0){
        if((s[i]>='A'&& s[i]<='Z')||(s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9')){
            st.push(string(1, s[i]));
        }
        else {
            string top1 = st.top(); 
            st.pop();
            string top2 = st.top(); 
            st.pop();
            string temp = "(" + top1 + s[i] + top2 + ")";
            st.push(temp);
        }
        i--;
    }
    return st.top();
}

string postfixToPrefix(string s){
    int i=0; stack<string>st;
    int n=s.length();
    while(i<n){
        if((s[i]>='A'&& s[i]<='Z')||(s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9')){
            st.push(string(1, s[i]));
        }
        else {
            string top1 = st.top(); 
            st.pop();
            string top2 = st.top(); 
            st.pop();
            string temp = s[i]+ top2 + top1;
            st.push(temp);
        }
        i++;
    }
    return st.top();
}



string prefixfixToPostfix(string s){
    int i=s.length()-1; stack<string>st;
    
    while(i>=0){
        if((s[i]>='A'&& s[i]<='Z')||(s[i]>='a'&& s[i]<='z')||(s[i]>='0'&& s[i]<='9')){
            st.push(string(1, s[i]));
        }
        else {
            string top1 = st.top(); 
            st.pop();
            string top2 = st.top(); 
            st.pop();
            string temp = top1 + top2 + s[i];
            st.push(temp);
        }
        i--;
    }
    return st.top();
}
int main(){ 

    //  string infix = "(A+B)*C-D+F";
    // string postfix = infixToPostfix(infix);
    // cout << "Infix: " << infix << endl;
    // cout << "Postfix: " << postfix << endl;
    // string prefix = infixToPrefix(infix);
    // cout << "Infix: " << infix << endl;
    // cout << "Postfix: " << prefix << endl;
    // string postfix = "AB-DE+F*/";
    // string infix = postfixToInfix(postfix); 
    // cout << "Postfix: " << postfix << endl;
    // cout << "Infix: " << infix << endl;
    // string prefix = "*+PQ-MN";
    // string infix = prefixfixToInfix(prefix);    
    // cout << "Prefix: " << prefix << endl;
    // cout << "Infix: " << infix << endl;
    // string postfix = "AB-DE+F*/";
    // string prefix = postfixToPrefix(postfix);   
    // cout << "Postfix: " << postfix << endl;
    // cout << "Prefix: " << prefix << endl;
    // string prefix = "/-AB*+DEF";  
    // string postfix = prefixfixToPostfix(prefix);
    // cout << "Prefix: " << prefix << endl;
    // cout << "Postfix: " << postfix << endl;
    
    return 0;
}
