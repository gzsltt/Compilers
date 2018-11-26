#include <iostream>
#include<stack>
#include<string.h>
using namespace std;


char c[500];
stack<string> s;
int count=0;
void analy();
void E();
void F();
void E1();
void T();
void T1();
void jia();
void cheng();
void zkh();
void ykh();

void zkh()
{
    if(c[count]=='(')
    {
        s.pop();
        count++;
        analy();
    }
    else
    {
        cout<<"弹栈，弹出终结符(，用户少输入了一个左括号"<<endl;
        s.pop();
        analy();
    }
}

void ykh()
{
    if(c[count]==')')
    {
        s.pop();
        count++;
        analy();
    }
    else
    {
        cout<<"弹栈，弹出终结符 ) ，用户少输入了一个右括号"<<endl;
        s.pop();
        analy();
    }
}

void E()
{
    if(c[count]=='i'){
        cout<<"E->TE'"<<endl;
        s.pop();
        s.push("E1");
        s.push("T");
        analy();}
    else if(c[count]=='('){
        cout<<"E->TE'"<<endl;
        s.pop();
        s.push("E1");
        s.push("T");
        analy();}
    else if (c[count]=='+'||c[count]=='*'){
        s.pop();
        analy();}
    else
        {
            if(c[count]==')')
            cout<<"括号不匹配"<<endl;
            else
                cout<<"出错！输入串为空"<<endl;
        count++;
        analy();
        }
}

void jia()
{
    if(c[count]=='+')
    {
        s.pop();
        count++;
        analy();
    }
}

void cheng()
{
    if(c[count]=='*')
    {
        s.pop();
        count++;
        analy();
    }
}
void E1()
{
    if(c[count]=='+'){
        cout<<"E'->+TE'"<<endl;
        s.pop();
        s.push("E1");
        s.push("T");
        s.push("+");
        analy();}
    else if(c[count]==')'||c[count]=='#'){
        s.pop();
        analy();
    }
    else{
        if(c[count]=='i')
        {
            cout<<"输入串跳过记号id，用户多输入了一个id"<<endl;
            count+=2;
            analy();
        }
        else{
        s.pop();
        analy();
    }
    }
}


void T()
{
    if(c[count]=='i'||'('){
        cout<<"T->FT'"<<endl;
        s.pop();
        s.push("T1");
        s.push("F");
        analy();}
    else if(c[count]=='*'){
       s.pop();
        analy();}
    else{
        if(c[count]=='+')
        cout<<"出错，多输入了+，跳过"<<c[count]<<endl;
        else
        cout<<"括号不匹配！多输入了),跳过"<<c[count]<<endl;
        count++;
        analy();
    }
}

void T1()
{
    if(c[count]=='*'){
        cout<<"T'->*FT'"<<endl;
        s.pop();
        s.push("T1");
        s.push("F");
        s.push("*");
        analy();}
    else if(c[count]=='+'||c[count]==')'||c[count]=='#'){
        s.pop();
        analy();}
    else{
            if(c[count]=='i')
        {
            cout<<"输入串跳过记号id，用户多输入了一个id"<<endl;
            count+=2;
            analy();
        }
        else{
        s.pop();
        analy();

}    }
}


void F()
{
   if(c[count]=='i'){
        cout<<"F->id"<<endl;
        s.pop();
        count+=2;
        analy();}
    else if(c[count]=='('){
        cout<<"F->(E)"<<endl;
        s.pop();
        s.push(")");
        s.push("E");
        s.push("(");
        analy();}
    else if(c[count]=='+'||c[count]=='*'){
        cout<<"弹栈，弹出非终结符F，用户少输入了一个id"<<endl;
        s.pop();
        analy();}
    else{
        cout<<"出错，跳过"<<c[count]<<endl;
        count++;
        analy();
    }
}
void analy()
{
    string tmpt;
    tmpt=s.top();
    if (tmpt!="$")
    {
        if(tmpt=="E") E();
        else if(tmpt=="E1") E1();
        else if(tmpt=="T") T();
        else if(tmpt=="T1") T1();
        else if(tmpt=="F") F();
        else if(tmpt=="+") jia();
        else if(tmpt=="*") cheng();
        else if(tmpt=="(") zkh();
        else if(tmpt==")") ykh();
    }
    else{
            cout<<"结束！"<<endl;
            s.pop();
    }
}

int main()
{
    int i=0;
    cout<<"输入串，以#结尾"<<endl;
    while(c[i-1]!='#')
    {
        cin>>c[i];
        i++;
    }
    s.push("$");
    s.push("E");
    analy();
}
