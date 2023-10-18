#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> mp;
class stack
{
private:
	int top,num[100];
	char op[100];
public:
	stack()
	{
	top=0;
	}
	bool empty()
	{
		if(top == 0)
		return true;
		return false;
	}
	bool full()
	{
		if(top==99)
		return true;
		return false;
	}
		void push(int x)
		{
			num[top]=x;
			top++;
		}
		void push(char y)
		{
			op[top]=y;
			top++;
		}
		int top_()
		{
			return num[top-1];
		}
		char _top_()
		{
			return op[top-1]; 
		} 
		void pop()
		{
			top--;
		}
		
};
stack num;
stack op;
 int yxj(char a) //Determine operator priority 
{
	int k;
	if(a=='=')
	{k=0;}
	if(a=='('||a==')')
	{k=1;}
	if(a=='+'||a=='-')
	{k=2;}
	if(a=='*'||a=='/')
	{k=3;}
	return k;
}
void count() 
{
	int m=num.top_();
	num.pop();
	int n=num.top_();
	num.pop();
	if(op._top_()=='+')
	num.push(m+n);
	if(op._top_()=='-')
	num.push(n-m);
	if(op._top_()=='*')
	num.push(m*n);
	if(op._top_()=='/')
	num.push(n/m);
	op.pop(); //pop out the operator after calculation
}
int account(string &str)
{
	
	int len=str.size();
	char c;
	int l,s,j;
	for (c = '0',l=0; c <= '9';c++,l++) //The map method converts characters to integers 
        mp[c] = l;
	for(int i=0;i<len;++i)
	{
		if(op.full()||num.full())
		break;
		if(str[i]>='0'&&str[i]<='9')
		{
			s=0;
			for(j=i;str[j]>='0'&&str[j]<='9';j++)
			{
		    s=s*10+mp[str[j]];
			}
			num.push(s);
			i=j-1;
		}
		else
		{
			if(op.empty()) //push when the op stack is empty 
			{
				op.push(str[i]);
			}
			
		    else if(yxj(str[i])>yxj(op._top_())||str[i]=='('||str[i]==')')//The operator to be put on the stack has high priority or '('and') 'push 
			{
			op.push(str[i]);
			if(str[i]==')')        //When it is') ', pop') ' 
			{
				op.pop();
				if(op._top_()!='(') //op.top Evaluate operators in parentheses when not '(' 
				{
					count();
				}
				op.pop(); //pop drop '('
			}
			}
		    else  //To stack operator str[i] has lower priority than op.top The top of stack operator is calculated first
		    {
			    count();
				op.push(str[i]); //Put str[i] into the op stack
			}
			if(op._top_()=='=')
			break;
		}
	}
	if(op._top_()=='=')
	{
	op.pop();
	while(op.empty()!=1)
	{
	count();
	}
	}
	return num.top_();
}

int main()
{
	string str;
	cin>>str;
	int jg=account(str);
	cout<<jg<<endl;
	return 0;
}
