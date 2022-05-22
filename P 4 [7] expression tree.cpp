//P-4
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
class TreeN //node declaration
{
	public:char d;
	TreeN *I, *r;
	TreeN(char d)
	{
		this->d=d;
		this->I=NULL;
		this->r=NULL;
	}
};
class StackNod //stack declaration
{
	public:TreeN *treeN;
	StackNod *n;
	StackNod(TreeN *treeN) //constructor
	{
		this->treeN=treeN;
		n=NULL;
	}
};
class ExpressionTree
{
	private:StackNod *top;
	public:ExpressionTree()
	{
		top=NULL;
	}
	void clear()
	{
		top=NULL;
	}
	void push(TreeN*ptr)
	{
		if(top==NULL)
		top=new StackNod(ptr);
		else
		{
			StackNod*nptr=new StackNod(ptr);
			nptr->n=top;
			top=nptr;
		}
	}
	TreeN*pop()
	{
		if(top==NULL)
		{
			cout<<"Underflow"<<endl;
		}
		else
		{
			TreeN*ptr=top->treeN;
			top=top->n;
			return ptr;
		}
	}
	TreeN *peek()
	{
		return top->treeN;
	}
	void insert(char val)
	{
		if(isDigital(val))
		{
			TreeN*nptr=new TreeN(val);
			push(nptr);
		}
		else if (isOperator(val))
		{
			TreeN*nptr=new TreeN(val);
			nptr->I=pop();
			nptr->r=pop();
			push(nptr);
		}
		else
		{
			cout<<"invalid expression"<<endl;
			return;
		}
	}
	bool isDigital(char ch)
	{
		return ch>='0'&& ch<='9';
	}
	bool isOperator(char ch)
	{
		return ch=='+' ||ch=='-' || ch=='/';
	}
	int toDigit(char ch)
	{
		return ch-'0';
	}
	void buildTree(string eqn)
	{
		for(int i=eqn.length()-1;i>=0;i--)
		insert(eqn[i]);
	}
	void postfix()
	{
		postOrder(peek());
	}
	void postOrder(TreeN*ptr)
	{
		if(ptr!=NULL)
		{
			postOrder(ptr->I);
			postOrder(ptr->r);
			cout<<ptr->d;
		}
	}
	void infix()
	{
		inOrder(peek());
	}
	void inOrder(TreeN*ptr)
	{
		if(ptr!=NULL)
		{
			inOrder(ptr->I);
			cout<<ptr->d;
			inOrder(ptr->r);
	    }
    }
    void prefix()
    {
    	preOrder(peek());
	}
	void preOrder(TreeN*ptr)
	{
		if(ptr!=NULL)
		{
			cout<<ptr->d;
			preOrder(ptr->I);
			preOrder(ptr->r);
	    }
    }
};
int main()
{
	string s;
	ExpressionTree et;
	cout<<"\nEnter equation in Prefix form:";
	cin>>s;
	et.buildTree(s);
	cout<<"\nPrefix :";
	et.prefix();
	cout<<"\nInfix :";
	et.infix();
	cout<<"\nPostfix :";
	et.postfix();
}
