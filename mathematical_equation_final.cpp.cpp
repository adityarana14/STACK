#include<bits/stdc++.h>
using namespace std;

stack<char> operators;    // + , - etc
stack<int> operands;     // 1 2 3 etc

int priority(char op)
{
    if(op=='('||op==')')
    {
        return 1;
    }
    else if(op=='+'||op=='-')
    {
        return 3;
    }
    else if(op=='/'||op=='*')
    {
        return 2;
    }
    else return 10;
     
}

int operation(int left , int right , char op)
{
    switch(op)
    {
        case '+' : return left+ right;
        break;

        case '-' : return left-right;
        break;

        case '*' : return left*right;
        break;

        case '/' : return left/right; //right != 0;
        break;
        
    }

    return -1;
}
int main()
{

    string s;
    cout<<"enter the string of mathematical expression"<<endl;
    cin>>s;

        int i=0;
        int len= s.size();

    while(i!=len)
    {
        if(s[i]=='(')
        {
            operators.push(s[i]);
            //cout<<"we are here "<<s[i]<<endl;
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]==')')
        {
                int pri = priority(s[i]);
                if(operators.empty()==1 || pri>priority(operators.top()))
                {
                    operators.push(s[i]);
                    //cout<<"we are here val :"<< s[i]<<endl;
                }
                else{
                    int l=operands.top();
                    operands.pop();
                    int r = operands.top();
                    operands.pop();

                    int val=operation(l,r,operators.top());

                    operators.pop();
                    operators.pop();
                    operands.push(val);
                }
        }
        else operands.push(s[i]-48);

        i++;
    
        if(i==len)
        {
            if(operands.size()>1)
            {
            cout<<"the final output is "<<endl;
            int l=operands.top();
                    operands.pop();
                    int r = operands.top();
                    operands.pop();
                    int val=operation(l,r,operators.top());

                    cout<<val<<endl;
            }
            else{
                cout<<"the final vlaue is "<<endl;
                cout<<operands.top()<<endl;
            }

        }
        
    }



    return 0;

}