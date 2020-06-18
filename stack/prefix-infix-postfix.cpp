#include <iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        return 1;
    }
    return 0;
} 

int priority(char c){
    if(c=='^'){
        return 3;
    }
    if(c=='*' || c=='/'){
        return 2;
    }
    if(c=='+' || c=='-'){
        return 1;
    }
    return 0;
}

string prefixToInfix(string str){
    int i;
    stack<char> st;
    string ns;
    for(i=0;str[i];i++){
        if(isOperator(str[i])){
            ns+='(';
            st.push(')');
            st.push(str[i]);
        }
        else{
            ns+=str[i];
            while(!st.empty() && st.top()==')'){
                ns+=st.top();
                st.pop();
            }
            if(!st.empty()){
                ns+=st.top();
                st.pop();
            }
            
        }
    }
    
    return ns;
}

string postfixToInfix(string str){
    int i;
    int l=str.length();
    stack<char> st;
    string ns;
    for(i=l-1;i>=0;i--){
        if(isOperator(str[i])){
            ns=')'+ns;
            st.push('(');
            st.push(str[i]);
        }
        else{
            ns=str[i]+ns;
            while(!st.empty() && st.top()=='('){
                ns=st.top()+ns;
                st.pop();
            }
            if(!st.empty()){
                ns=st.top()+ns;
                st.pop();
            }
            
        }
    }
    
    return ns;
}

string prefixToPostfix(string str){
    int i;
    int l=str.length();
    stack<char> st;
    string ns;
    int flag;
    char n1, n2, n3;
    for(i=0;i<l;i++){
        if(isOperator(str[i])){
            st.push(str[i]);
        }
        else{
            ns+=str[i];
            n1='n';
            n2=0;
            n3=0;
            n2=st.top();
            st.pop();
            if(!st.empty()){
                n3=st.top();
                st.pop();
            }
            while(n1=='n' && n2=='n' && isOperator(n3)){
                ns+=n3;
                n1='n';
                n2=0;
                n3=0;
                if(!st.empty()){
                    n2=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    n3=st.top();
                    st.pop();
                }
               
            }
            if(n3){
                st.push(n3);
            }
            if(n2){
                st.push(n2);
            }
            if(n1){
                st.push(n1);
            }
        }
    }
    
    while(!st.empty() && st.top()!='n'){
        ns+=st.top();
        st.pop();
    }
    
    return ns;
}

string postfixToPrefix(string str){
    int l= str.length();
    int i;
    stack<string> st;
    for(i=0;i<l;i++){
        if(isOperator(str[i])){
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp = str[i] + op2 + op1;
            st.push(temp);
        }
        else{
            st.push(string(1,str[i]));
        }
    }
    return st.top();
}

string infixToPrefix(string str){
    int i;
    int l= str.length();
    stack<char> st;
    string ns;
    for(i=l-1;i>=0;i--){
        if(str[i]==')'){
            st.push(str[i]);
        }
        if(str[i]=='('){
            while(!st.empty() && st.top()!=')'){
                ns=st.top()+ns;
                st.pop();
            }
            st.pop();
        }
        if(isOperator(str[i])){
            while(!st.empty() && priority(st.top())>priority(str[i])){
                ns=st.top()+ns;
                st.pop();
            }
            st.push(str[i]);
        }
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            ns=str[i]+ns;
        }
        
    }
    while(!st.empty()){
        ns=st.top()+ns;
        st.pop();
    }
    
    return ns;
}

string infixToPostfix(string str){
    int i;
    int l= str.length();
    stack<char> st;
    string ns;
    for(i=0;i<l;i++){
        if(str[i]=='('){
            st.push(str[i]);
        }
        if(str[i]==')'){
            while(!st.empty() && st.top()!='('){
                ns+=st.top();
                st.pop();
            }
            st.pop();
        }
        if(isOperator(str[i])){
            while(!st.empty() && priority(st.top())>priority(str[i])){
                ns+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            ns+=str[i];
        }
        
    }
    while(!st.empty()){
        ns+=st.top();
        st.pop();
    }
    
    return ns;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	   string str;
	   cin>>str;
	   cout<<infixToPrefix(str);
	   cout<<endl;
	}
	return 0;
}