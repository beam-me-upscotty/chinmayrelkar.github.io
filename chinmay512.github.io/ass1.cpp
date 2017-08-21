/**
 * Created by chinmay on 11/12/16.
 * Copyright 2016, Chinmay Relkar
 */
#include<iostream>
#include<string.h>
#define size 30
using namespace std;

template<typename T>
class node
{
	public:
		T data;
		node<T>*next;
};

template<typename T>
class stack
{
	node<T>*start;
	public:
		stack()
		{
			start=NULL;
		}
		
		void push(T x)
		{
			node<T>*temp;
			temp=new node<T>;
			temp->data=x;
			temp->next=NULL;
			if(start==NULL)
				start=temp;
			else
			{
				temp->next=start;
				start=temp;
			}
		}
		
		T pop()
		{
			node<T>*temp=start;
			T t=temp->data;
			start=start->next;
			delete(temp);
			return t;
		}

		int is_empty()
		{
			if(start==NULL)
				return 1;
			return 0;
		}

		T top()
		{
			return (start->data);
		}

};

template<typename T>
class Infix
{
	T exp[size],postfix[size],prefix[size];
	public:
	void read();
	void display();
	void toPostfix();
	int priority(T op);
	int onstackpriority(T op);
	void reverse(T string1[],T string2[]);
	void toPrefix();
	int evalPostfix();
	int evalPretfix();
};

template<typename T>
int Infix<T>::priority(T op)
{
	if(op=='+' || op=='-')
		return 1;
	if(op=='*' || op=='/')
		return 2;
	if(op=='$')
		return 3;
	if(op=='(')
		return 4;
	if(op==')')
		return 0;
}

template<typename T>
int Infix<T>::onstackpriority(T op)
{
	if(op=='+' || op=='-')
		return 1;
	if(op=='*' || op=='/')
		return 2;
	if(op=='$')
		return 3;
	if(op=='(')
		return 0;
	if(op==')')
		return -1;
}

template<typename T>
void Infix<T>::read()
{
	int flag=0;
	cout<<"Enter the Infix"<<endl;
	cin>>exp;
}

template<typename T>
void Infix<T>::display()
{
	cout<<"The Infix is "<<exp<<endl;
}

template<typename T>
void Infix<T>::toPostfix()
{
	stack<char>s;
	int i=0,j=0;
	T p;
	while(exp[i]!='\0')
	{
		if(exp[i]!='+' && exp[i]!='-' && exp[i]!='*' && exp[i]!='/' && exp[i]!='$' && exp[i]!='('&& exp[i]!=')')
		{
			postfix[j++]=exp[i];
		}
		else if(exp[i]=='(')
			s.push(exp[i]);
		else if(exp[i]==')')
		{
			while(s.top() != '(')
			{
				if(s.is_empty()==1)
					break;
				else
					postfix[j++]=s.pop();
			}
			p=s.pop();
		}
		else
		{
			if(s.is_empty())
				s.push(exp[i]);
			else
			{
				if(priority(exp[i])>onstackpriority(s.top()))
					s.push(exp[i]);
				else
				{
					while(s.is_empty()==0 && priority(exp[i])<=onstackpriority(s.top()))
					{
						if(s.top()!='(')
							postfix[j++]=s.pop();
						else
							p=s.pop();
					}
					s.push(exp[i]);
				}
			}
		}
		i++;
	}
	
	while(s.is_empty()!=1)
	{
		if(s.top()!='(')
			postfix[j++]=s.pop();
		else
			p=s.pop();
	}
	
	postfix[j]='\0';
	cout<<"Postfix Infix is "<<postfix<<endl;
}
/**
 * Created by chinmay on 11/12/16.
 * Copyright 2016, Chinmay Relkar
 */
template<typename T>
void Infix<T>::reverse(T string1[30],T string2[30])
{
	int length=0,i,j;
	length=strlen(string2);
	for(i=0,j=length-1;j>=0;i++,j--)
	{
		string1[i]=string2[j];
	}
	string1[i]='\0';
}

template<typename T>
void Infix<T>::toPrefix()
{
	stack<char> operatr;
	int i=0,j=0;
	T rev[size],p,result[size];
	reverse(rev,exp);
	while(rev[i]!='\0')
	{
		//operand
		if(rev[i]!='+' && rev[i]!='-' && rev[i]!='*' && rev[i]!='/' && rev[i]!='$' && rev[i]!='(' && rev[i]!=')')
			prefix[j++]=rev[i];
		else if(rev[i]==')')
			operatr.push(rev[i]);
		else if(rev[i]=='(')
		{
			while(operatr.top() != ')')
			{
				if(operatr.is_empty()==1)
					break;
				else
					prefix[j++]=operatr.pop();
			}
			if(operatr.is_empty()!=1)
				p=operatr.pop();
		}
		//operator
		else
		{
			if(operatr.is_empty()==1)
				operatr.push(rev[i]);
			else
			{
				if(priority(rev[i]) >= onstackpriority(operatr.top()))
					operatr.push(rev[i]);
				else
				{
					while(operatr.is_empty()==0 && priority(rev[i]) < onstackpriority(operatr.top()))
					{
						if(operatr.top()!='(')
							prefix[j++]=operatr.pop();
						else if(operatr.is_empty() !=1)
							p=operatr.pop();
					}
					
					operatr.push(rev[i]);
				}
			}
			
		}
		i++;
	}
	while(operatr.is_empty() != 1)
	{
		prefix[j++]=operatr.pop();
	}
	
	prefix[j]='\0';
	reverse(result,prefix);
	cout<<"Prefix Infix is "<<result<<endl;
	strcpy(prefix,result);
}

template<typename T>
int Infix<T>::evalPostfix()
{
	int result,value;
	int i=0,j=0,count=0,flag=0,power;
	T op1,op2,op3,op;
	stack<char> output;
	T var[size];
	int val[size];
	
	while(postfix[i] != '\0')
	{
		if(postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] !='$')
		{
			flag=0;
			for(j=0;j<count;j++)
			{
				if(var[j]==postfix[i])
				{
					value=val[j];
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout<<"Enter value of "<<postfix[i]<<endl;
				cin>>value;
				var[count]=postfix[i];
				val[count]=value;
				count++;
			}
		
		output.push(value);
		}
		else
		{
			op=postfix[i];
			op2=output.pop();
			op1=output.pop();
			switch(op)
			{
				case '+' :
					op3=op1+op2;
					break;
				case '-' :
					op3=op1-op2;
					break;
				case '*' :
					op3=op1*op2;
					break;	
				case '/' :
					op3=op1/op2;
					break;	
				case '$' :
					result=1;
					for(power=1;power<=op2;power++)
					{
						result=result*op1;
					}
					op3=result;
					break;
			}
			output.push(op3);
		}
		i++;
	}
	result=output.pop();
	cout<<"Result "<<result<<endl;
}

/**
 * Created by chinmay on 11/12/16.
 * Copyright 2016, Chinmay Relkar
 */template<typename T>
int Infix<T>::evalPretfix()
{

	char var_array[30];int val_array[30];
	int var_count = 0;
	int i = strlen(prefix)-1;
	int value;
	stack<int> output;
	
	while(i>=0)
	{
		if(prefix[i] != '+' && prefix[i] != '-' && prefix[i] != '*' && prefix[i] != '/' && prefix[i] !='$')
		{
			bool flag = false;
			for(int j = 0; j < var_count; j++)
				if(var_array[j]==prefix[i])
				{
					value = val_array[j];
					flag = true;
					break;
				}

			if(!flag)
			{
				cout<<"Enter value of "<<prefix[i]<<endl;
				cin>>value;
				var_array[var_count]=prefix[i];
				val_array[var_count]=value;
				var_count++;
			}
			output.push(value);
		}
		else
		{
			char op=prefix[i];
			int operand1 = output.pop();
			int operand2 = output.pop();
			int op3;
			switch(op)
			{
				case '+' :
					op3 = operand1 + operand2;
					break;
				case '-' :
					op3 = operand1-operand2;
					break;
				case '*' :
					op3=operand1*operand2;
					break;	
				case '/' :
					op3=operand1/operand2;
					break;	
				case '$' :
					int result=1;
					for(int power=1;power<=operand2;power++)
					{
						result=result*operand1;
					}
					op3=result;
					break;
			}
		
			output.push(op3);
		}
		i--;
	}
	cout<<"\nThe answer is :";
	cout<<output.pop();
}
/**
 * Created by chinmay on 11/12/16.
 * Copyright 2016, Chinmay Relkar
 */
int main()
{
	Infix<char> infix;
	int choice;
	while(true)
	{
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"1. Input Infix"<<endl;
		cout<<"2. Get Postfix"<<endl;
		cout<<"3. Get Prefix"<<endl;
		cout<<"4. Evaluate Postfix"<<endl;
		cout<<"5. Evaluate Prefix"<<endl;
		cin>>choice;
		cout<<"---------------------------------------------------------"<<endl;
		
		switch(choice)
		{
			case 1:
				infix.read();
				break;
			case 2:
				infix.toPostfix();
				break;
			case 3:
				infix.toPrefix();
				break;
			case 4:
				infix.evalPostfix();
				break;
			case 5:
				infix.evalPretfix();
				break;
			case 6:
				return 0;
			default: cout<<"Incorrect Choice\n";
		}
	}
}

		
		
