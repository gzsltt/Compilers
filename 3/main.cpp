#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//函数声明
void E();
void E1();
void T();
void T1();
void F();

void getsymbol();
void error();

char ch;
char a[50];
int count=0;

void getsymbol()
{
	ch=a[count++];
	if(ch=='i')
        E();
}
void error()
{
	cout<<"It's error!"<<endl;
	system("pause");
	exit(0);
}
void E()
{
	cout<<"E -> TE1"<<endl;
	T();
	E1();
}
void E1()
{
	if(ch=='+')
	{
		cout<<"E1 -> +TE1"<<endl;
		getsymbol();
		T();
		E1();
	}
	else
		return ;

}
void T()
{
	cout<<"T -> FT1"<<endl;
	F();
	T1();
}
void T1()
{
	if(ch=='*')
	{
		cout<<"T1 -> *FT1"<<endl;
		getsymbol();
		F();
		T1();
	}
	else
		return ;

}
void F()
{
	if(ch=='i')
	{
		cout<<"F -> id"<<endl;
		count++;
		getsymbol();
	}
	else if(ch=='(')
    {
		cout<<"F -> (E)"<<endl;
		getsymbol();
        E();
        if(ch==')')
			getsymbol();
        else
			error();
    }
    else if(ch=='#')
		exit(0);
	else
		error();
}
int main()
{
	int i=0;
	char ch;
	cout<<"请输入字符串(以#结尾)"<<endl;
	while(ch!='#')
    {
        cin>>ch;
        a[i]=ch;
        i++;
    }
	a[i]='#';
	getsymbol();
	if(ch=='#')
		cout<<"Success"<<endl;
	_getch() ;
	return 0 ;
}
