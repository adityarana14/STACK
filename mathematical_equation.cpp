/* Represent mathematical equations such as “(( 3 + 4) + 5) * 3” in an 
 efficient data structure. For the next step, assume that the data is
 in the designed data structure, write helper functions to compute the
 result of the equation stored. */


//method 1 : We can use Stack or queue to store the mathematical expression.


#include<iostream>
#include<stack>

using namespace std;

int pri(char ch)
{
    switch (ch)
    {
    	case '(':
    		return 1;
	    case '+':
	    case '-':
	        return 2;

	    case '*':
	    case '/':
	        return 3;

	    case '^':
	        return 4;
    }
    return -1;
}


int calculate(char op, int l , int r){
	if(op == '+'){
		return l + r;
	}else if(op == '-'){
		return l - r ;
	}else if(op == '*'){
		return l * r;
	}else if(op == '/'){
		if(r > 0){
			return l/r;
		}
		return 0;
	}else if(op == '^'){
		return l ^ r;
	}
	return -1;
}


int main(void){
	char str[] = "((3+4)+5)*3";
	//char str[] = "3+4*5*4+3-1/2+1";
	int l = sizeof(str)/sizeof(char);
	int k = 0;
	stack<char> s;
	stack<int> op_s;
	cout <<"InFix Expression: " << str << endl;
	int i = 0;
	while(str[i] != '\0'){
		if(str[i] == '('){
			s.push('(');
		}else if(str[i] == ')'){
			while(s.top() != '('){
				int r = op_s.top();
				op_s.pop();
				int l = op_s.top();
				op_s.pop();
				int re = calculate(s.top(),l,r);
				op_s.push(re);
			  s.pop(); 
			}
			s.pop();
		}else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){
			int pC = pri(str[i]);
			while(!s.empty() && pri(s.top()) >= pC){
				int r = op_s.top();
				op_s.pop();
				int l = op_s.top();
				op_s.pop();
				int re = calculate(s.top(),l,r);
				op_s.push(re);
				s.pop(); 
			}
			s.push(str[i]);
		}else{
			op_s.push(int(str[i])- 48);
		}
		i++;
	}
	while(!s.empty()){
		int r = op_s.top();
		op_s.pop();
		int l = op_s.top();
		op_s.pop();
		int re = calculate(s.top(),l,r);
		op_s.push(re);
		s.pop(); 
	}

	cout <<"Result: " << op_s.top() << endl;
	return 0;
}