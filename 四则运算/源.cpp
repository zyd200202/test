#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<time.h>
#include<cmath>
#include<fstream>
int imax;  //�����
int numofcalculate; //��ʽ����
int brackets; //�Ƿ�������
int decimal;  //�Ƿ���С��
char op[4] = { '+','-','*','/' };		  //�����
int ope;      //�û�����������
int outputform;//�����ʽ
void  integer_Cal();//����������������
void decimal_Cal();//����С����������
using namespace std;
ofstream outfile;//����д���ļ�
int main()
{
	cout << "---Сѧ������������ϰϵͳ---" << endl;
	cout << "********************** " << endl;
	cout << " ��:��������ʽ����: " << endl;
	cin >> numofcalculate;
	cout << " ��: �����������: " << endl;
	cin >> imax;
	cout << " ��:�����������: " << endl;
	cout << " 1����+ 2����- 3����* 4����/ ������������:" << endl;
	cin >> ope;
	cout << " ��:��ѡ����������: " << endl;
	cout << " 1�������� 2����С��" << endl;
	cin >> decimal;
	cout << " ��:��ѡ���Ƿ���Ҫ���� " << endl;
	cout << " 1������Ҫ���� 2������Ҫ����" << endl;
	cin >> brackets;
	cout << " ��:��ѡ�������ʽ " << endl;
	cout << " 1����������ļ� 2�����ӡ�����ӡ����Ļ" << endl;
	cin >> outputform;
	if (outputform == 1)
	{
		outfile.open("myfile.txt");//����д���ļ�
	}
	if (decimal == 1)
	{
		srand(time(NULL));//����һ��������ӣ�ÿ�����ж��ܱ�֤������Ӳ�ͬ
		for (int i = 0; i < numofcalculate; i++)
		{
			integer_Cal();
		}
	}
	else
	{
		srand(time(NULL));
		for (int i = 0; i < numofcalculate; i++)
		{
			decimal_Cal();
		}
	}
	outfile.close();
	cout << "********************* " << endl;
	cout << "---��лʹ�ô�ϵͳ��ף��ѧϰ����---" << endl;
	return 0;
}
void integer_Cal()//����������������
{
	int a, b, c, d;
	a = (rand() % imax) + 1;//�õ�һ��1��imax�������a
	b = (rand() % imax) + 1;//�õ�һ��1��imax�������b
	c = (rand() % imax) + 1;//�õ�һ��1��imax�������c
	int op1, op2, op3;
	op1 = rand() % 4;//����õ�"+" "-" "*" "/"�е�һ��
	op2 = rand() % 4;
	if (brackets == 1)//����Ҫ����
	{
		if (ope == 1)//ִ��"+"����
		{
			//f=a+b+c;
			cout << a << "+" << b << "+" << c << "=" << endl;
			outfile << a << "+" << b << "+" << c << "=" << endl;
		}
		else if (ope == 2)//ִ��"-"����
		{
			cout << a << "-" << b << "-" << c << "=" << endl;
			outfile << a << "-" << b << "-" << c << "=" << endl;
		}
		else if (ope == 3)//ִ��"*"����
		{
			cout << a << "*" << b << "*" << c << "=" << endl;
			outfile << a << "*" << b << "*" << c << "=" << endl;
		}
		else if (ope == 4)//ִ��"/"����
		{
			cout << a << "/" << b << "/" << c << "=" << endl;
			outfile << a << "/" << b << "/" << c << "=" << endl;
		}
		else//ִ�л������
		{
			cout << a << op[op1] << b << op[op2] << c << "=" << endl;//����������������������
			outfile << a << op[op1] << b << op[op2] << c << "=" << endl;
		}
	}
	else
	{
		int k;
		k = rand() % 2;//�������"0"��"1"
		if (k == 0)//����λ����ǰ
		{
			if (ope == 1)
			{
				cout << "(" << a << "+" << b << ")" << "+" << c << "=" << endl;
				outfile << "(" << a << "+" << b << ")" << "+" << c << "=" << endl;
			}
			else if (ope == 2)
			{
				cout << "(" << a << "-" << b << ")" << "-" << c << "=" << endl;
				outfile << "(" << a << "-" << b << ")" << "-" << c << "=" << endl;
			}
			else if (ope == 3)
			{
				cout << "(" << a << "*" << b << ")" << "*" << c << "=" << endl;
				outfile << "(" << a << "*" << b << ")" << "*" << c << "=" << endl;
			}
			else if (ope == 4)
			{
				cout << "(" << a << "/" << b << ")" << "/" << c << "=" << endl;
				outfile << "(" << a << "/" << b << ")" << "/" << c << "=" << endl;
			}
			else
			{
				cout << "(" << a << op[op1] << b << ")" << op[op2] << c << "=" << endl;
				outfile << "(" << a << op[op1] << b << ")" << op[op2] << c << "=" << endl;
			}
		}
		else//����λ���ں�
		{
			if (ope == 1)
			{
				cout << a << "+" << "(" << b << "+" << c << ")" << "=" << endl;
				outfile << a << "+" << "(" << b << "+" << c << ")" << "=" << endl;
			}
			else if (ope == 2)
			{
				cout << a << "-" << "(" << b << "-" << c << ")" << "=" << endl;
				outfile << a << "-" << "(" << b << "-" << c << ")" << "=" << endl;
			}
			else if (ope == 3)
			{
				cout << a << "*" << "(" << b << "*" << c << ")" << "=" << endl;
				outfile << a << "*" << "(" << b << "*" << c << ")" << "=" << endl;
			}
			else if (ope == 4)
			{
				cout << a << "/" << "(" << b << "/" << c << ")" << "=" << endl;
				outfile << a << "/" << "(" << b << "/" << c << ")" << "=" << endl;
			}
			else
			{
				cout << a << op[op1] << "(" << b << op[op2] << c << ")" << "=" << endl;
				outfile << a << op[op1] << "(" << b << op[op2] << c << ")" << "=" << endl;
			}
		}
	}
}
void decimal_Cal()//����С����������
{
	double a, b, c, d;
	a = (double)rand() / RAND_MAX * imax + 1.0;
	b = (double)rand() / RAND_MAX * imax + 1.0;
	c = (double)rand() / RAND_MAX * imax + 1.0;
	int op1, op2;
	op1 = rand() % 4;
	op2 = rand() % 4;
	if (brackets == 1)
	{
		if (ope == 1)
		{
			cout << a << "+" << b << "+" << c << "=" << endl;
			outfile << a << "+" << "(" << b << "+" << c << ")" << "=" << endl;
		}
		else if (ope == 2)
		{
			cout << a << "-" << b << "-" << c << "=" << endl;
			outfile << a << "-" << "(" << b << "-" << c << ")" << "=" << endl;
		}
		else if (ope == 3)
		{
			cout << a << "*" << b << "*" << c << "=" << endl;
			outfile << a << "*" << "(" << b << "*" << c << ")" << "=" << endl;
		}
		else if (ope == 4)
		{
			cout << a << "/" << b << "/" << c << "=" << endl;
			outfile << a << "/" << "(" << b << "/" << c << ")" << "=" << endl;
		}
		else
		{
			cout << a << op[op1] << b << op[op2] << c << "=" << endl;
			outfile << a << op[op1] << "(" << b << op[op2] << c << ")" << "=" << endl;
		}
	}
	else
	{
		int k;
		k = rand() % 2;
		if (k == 0)
		{
			if (ope == 1)
			{
				cout << "(" << a << "+" << b << ")" << "+" << c << "=" << endl;
				outfile << "(" << a << "+" << b << ")" << "+" << c << "=" << endl;
			}
			else if (ope == 2)
			{
				cout << "(" << a << "-" << b << ")" << "-" << c << "=" << endl;
				outfile << "(" << a << "-" << b << ")" << "-" << c << "=" << endl;
			}
			else if (ope == 3)
			{
				cout << "(" << a << "*" << b << ")" << "*" << c << "=" << endl;
				outfile << "(" << a << "*" << b << ")" << "*" << c << "=" << endl;
			}
			else if (ope == 4)
			{
				cout << "(" << a << "/" << b << ")" << "/" << c << "=" << endl;
				outfile << "(" << a << "/" << b << ")" << "/" << c << "=" << endl;
			}
			else
			{
				cout << "(" << a << op[op1] << b << ")" << op[op2] << c << "=" << endl;
				outfile << "(" << a << op[op1] << b << ")" << op[op2] << c << "=" << endl;
			}
		}
		else
		{
			if (ope == 1)
			{
				cout << a << "+" << "(" << b << "+" << c << ")" << "=" << endl;
				outfile << a << "+" << "(" << b << "+" << c << ")" << "=" << endl;
			}
			else if (ope == 2)
			{
				cout << a << "-" << "(" << b << "-" << c << ")" << "=" << endl;
				outfile << a << "-" << "(" << b << "-" << c << ")" << "=" << endl;
			}
			else if (ope == 3)
			{
				cout << a << "*" << "(" << b << "*" << c << ")" << "=" << endl;
				outfile << a << "*" << "(" << b << "*" << c << ")" << "=" << endl;
			}
			else if (ope == 4)
			{
				cout << a << "/" << "(" << b << "/" << c << ")" << "=" << endl;
				outfile << a << "/" << "(" << b << "/" << c << ")" << "=" << endl;
			}
			else
			{
				cout << a << op[op1] << "(" << b << op[op2] << c << ")" << "=" << endl;
				outfile << a << op[op1] << "(" << b << op[op2] << c << ")" << "=" << endl;
			}
		}
	}
}