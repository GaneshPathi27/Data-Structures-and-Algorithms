// Coded by Ganesh Prasad

#include<bits/stdc++.h>
using namespace std;

// function to check if character is operator or not
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}

void prefixtoInfix(string s){
	
	stack<string> st;
	int n = s.length();
	
	// from right to left
	for(int i=n-1; i>= 0; i--){
		
		// if operator
		if(isOperator(s[i])){
			
			string op1 = st.top(); st.pop();
			string op2 = st.top(); st.pop();
			
			string temp = "(" + op1 + s[i] + op2 + ")";
			
			st.push(temp);
		}
		else{
			
			st.push(string(1,s[i]));
		}
		
	}
	
	cout<<st.top();
}

int main(){
	
	string exp = "*-A/BC-/AKL";
	prefixtoInfix(exp);
	return 0;
}


// output:

// ((A-(B/C))*((A/K)-L))