#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include<string.h>
#include<cstdlib>
using namespace std;

int i=0;

string FormBuild(int n, char ch)
{
	string Form[12][9] = {
		"s5","","","s4","","","1","2","3",
		"","s6","","","","acc","","","",
		"","r2","s7","","r2","r2","","","",
		"","r4","r4","","r4","r4","","","",
		"s5","","","s4","","","8","2","3",
		"","r6","r6","","r6","r6","","","",
		"s5","","","s4","","","","9","3",
		"s5","","","s4","","","","","10",
		"","s6","","","s11","","","","",
		"","r1","s7","","r1","r1","","","",
		"","r3","r3","","r3","r3","","","",
		"","r5","r5","","r5","r5","","","",
	};
	if (n > -1 && n < 12)
	{
		switch(ch)
		{
		case 'x':{return Form[n][0];}
		case '+':{return Form[n][1];}
		case '*':{return Form[n][2];}
		case '(':{return Form[n][3];}
		case ')':{return Form[n][4];}
		case '$':{return Form[n][5];}
		case 'E':{return Form[n][6];}
		case 'T':{return Form[n][7];}
		case 'F':{return Form[n][8];}
		default: return "";
		}
	}

	return "error";
	exit(0);
}

int Analysis(string str)
{
	if(str == "")
	{
		cout << "error!" << endl;
		i++;
		return 0;
		//exit(1);
	}
	else if (str[0] == 's')               //״̬����1
		return 1;
	else if (str[0] == 'r')               //��Լ����2
		return 2;
	else if (str == "acc")
		return 3;                         //����״̬������3
}

string Grammar(int n)
{
	if(n < 1 || n > 6)
	{
		cout << "Grammar error" << endl;
		exit(1);
	}
	string str[6] = {
		"E->E+T","E->T","T->T*F","T->F","F->(E)","F->x"
	};
	return str[n - 1];
}

void SLR(string& str)                     //����һ�������ַ���
{
	stack<string> S;                       //charֻ�ܴ�һλ�������֣���������������
	S.push("0");
	//int i = 0;
	int Number = -1;
	while(str[i]!='\0')                    //!??!!!!!!!!!!!!!!!!!?????????????
	{
		string temp = "";
		int top = atoi(S.top().c_str());                  //ջ����Զ��string�����֣�ת����int��!!!!!!!
		temp += FormBuild(top, str[i]);
		Number = Analysis(temp);                     //�����������еĲ���

		if (Number == 1)
		{
			string MemoryTemp1 = "";
			string MemoryTemp2 = "";
			MemoryTemp1.push_back(str[i]);                //��charת��Ϊstring��
			MemoryTemp2.push_back(temp[1]);
			S.push(MemoryTemp1);
			S.push(MemoryTemp2);
			i++;
			cout << "�ƽ�" << endl;
			continue;
		}

		if (Number == 2)
		{
			string GrammarTemp = Grammar(temp[1] - '0');
			cout << "��" << GrammarTemp << "��Լ" << endl;
			for (int k = 0; k < (GrammarTemp.size() - 3) * 2; k++)
				S.pop();

			int SearchNumber = atoi(S.top().c_str());    //��char������ת��Ϊint��
			string StackTemp;
			StackTemp.push_back(GrammarTemp[0]);
			S.push(StackTemp);


			string FormTemp = FormBuild(SearchNumber, S.top()[0]);
			/*cout << SearchNumber << S.top() << "JILJEI" << FormTemp << endl;*/
			S.push(FormTemp);          //��string����ת��char��  charֻ�ܴ�һλ�������֣���λ��ֻ�ᱣ����������
			continue;
		}

		if (Number == 3)
		{
			cout << "����"  << endl;
			return;
		}
	}
}

int main ()
{
	string str;
	cout << "�����ַ���: ";
	cin >> str;
	//string *s;               �ɲ�����ֱ�����뵽һ��ָ�������������������������

	SLR(str);
}
