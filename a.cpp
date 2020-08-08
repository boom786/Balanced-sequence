//Name : Himanshu Shekhar Padhi
// CODE FOR ROUND1 OF CIPHER SCHOOLS

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		
		stack<char> seq;
		
		int n = s.size() , len = 0;
		bool flag = true;
		for(int i = 0 ; i < n ; i++){
			if(s[i] == '(' || s[i] == '{' || s[i] == '['){ 
				seq.push(s[i]);		//if opening backet, push on stack
				len++;
			}
			else{	// check the corresponding opening bracket, and pop 
				if(s[i] == ')' && len && seq.top() == '('){
					seq.pop();
					len--;
				}
				else if(s[i] == '}' && len && seq.top() == '{'){
					seq.pop();
					len--;
				}
				else if(s[i] == ']' && len && seq.top() == '['){
					seq.pop();
					len--;
				}
				else{	// if no corresponding opening bracket is tere then the sequence is not balanced
					flag = false;
					break;
				}
			}
		}
		
		if(len)		// if at the end the stack is not empty, sequence is unbalanced
			flag = false;
		
		if(flag)	// seq balanced
			cout << "YES" << endl;
		else        // seq unbalanced
			cout << "NO" << endl;
	}
}
