#include<iostream>
#include<conio.h>      
#include<windows.h>
#include<string>
#include"menu_ColorTextChoose.h"
using namespace std;

void menu_teacher();
void menu_student();
void menu_admin();

ColorTextChoose_teacher::ColorTextChoose_teacher()
{
	str[0] = "	1��¼��ѧ����Ϣ		";
	str[1] = "	2���޸�ѧ���ɼ�		";
	str[2] = "	3����ѯѧ���ɼ�		";
	str[3] = "	4����һѧ�Ƴɼ���Ϣ	";
	str[4] = "	5����ѯ������ѧ����Ϣ";
	str[5] = "	6���˳�				";

	index = 0;
}

int ColorTextChoose_teacher::TextGoing()			//ʵ�����к���
{
	this->showText();
	while (true)
	{
		char buffer = _getch();
		switch (buffer)
		{

		case 'w':
		case 'W':
			if (index == 0)
			{
				this->showText();
				break;
			}
			index--;
			this->showText();
			break;//��w����
		case 's':
		case 'S':
			if (index == 5)
			{
				this->showText();
				break;
			}
			index++;
			this->showText();
			break;//��s����
		case 13:
			if (index == 5)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//�˸�
		}
	}
}

void ColorTextChoose_teacher::showText()			//��ʾ��ť
{
	system("color 07");//��ԭԭϵͳ��������ɫ�ͱ���ɫ
	system("cls");      //��տ���̨
	menu_teacher();
	cout << "�� w/s ѡ��˵�,Enter����,Esc�˳�" << endl << endl;
	for (int i = 0; i < 6; i++)
	{
		if (i != index)
		{
			//ûѡ����ûѡ�к�ѡ������������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF);//���ð��ֺڱ���
		}
		else
		{
			//ûѡ��������ѡ�е�ǰ������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//�����ı�������Ϊ��ɫ,ǰ��ɫΪ��ɫ
		}
		cout << str[i] << endl;//������ַ����˵�ѡ��

	}//��ʾ���˵�
}

ColorTextChoose_student::ColorTextChoose_student()			//ʵ�����к���
{
	str[0] = "	1����ѯ���гɼ�		";
	str[1] = "	2����ѯ������γ���Ϣ";
	str[2] = "	3���˳�				";

	index = 0;
}

int ColorTextChoose_student::TextGoing()			//��ʾ��ť
{
	this->showText();
	while (true)
	{
		char buffer = _getch();
		switch (buffer)
		{

		case 'w':
		case 'W':
			if (index == 0)
			{
				this->showText();
				break;
			}
			index--;
			this->showText();
			break;//��w����
		case 's':
		case 'S':
			if (index == 2)
			{
				this->showText();
				break;
			}
			index++;
			this->showText();
			break;//��s����
		case 13:
			if (index == 2)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//�˸�
		}
	}
}

void ColorTextChoose_student::showText()			//��ʾ��ť
{
	system("color 07");//��ԭԭϵͳ��������ɫ�ͱ���ɫ
	system("cls");      //��տ���̨
	menu_student();
	cout << "�� w/s ѡ��˵�,Enter����,Esc�˳�" << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		if (i != index)
		{
			//ûѡ����ûѡ�к�ѡ������������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF);//���ð��ֺڱ���
		}
		else
		{
			//ûѡ��������ѡ�е�ǰ������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//�����ı�������Ϊ��ɫ,ǰ��ɫΪ��ɫ
		}
		cout << str[i] << endl;//������ַ����˵�ѡ��

	}//��ʾ���˵�
}

ColorTextChoose_admin::ColorTextChoose_admin()  //���캯����ʼ������
{
	str[0] = "	1��¼��ѧ����Ϣ		";
	str[1] = "	2���޸�ѧ���ɼ�		";
	str[2] = "	3����ѯѧ���ɼ�		";
	str[3] = "	4��¼���ʦ��Ϣ		";
	str[4] = "	5���޸Ľ�ʦ��Ϣ		";
	str[5] = "	6����ѯ��ʦ��Ϣ		";
	str[6] = "	7���˳�				";

	index = 0;
}

int ColorTextChoose_admin::TextGoing()			//ʵ�����к���
{
	this->showText();
	while (true)
	{
		char buffer = _getch();
		switch (buffer)
		{

		case 'w':
		case 'W':
			if (index == 0)
			{
				this->showText();
				break;
			}
			index--;
			this->showText();
			break;//��w����
		case 's':
		case 'S':
			if (index == 6)
			{
				this->showText();
				break;
			}
			index++;
			this->showText();
			break;//��s����
		case 13:
			if (index == 6)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//�˸�
		}
	}
}

void ColorTextChoose_admin::showText()			//��ʾ��ť
{
	system("color 07");//��ԭԭϵͳ��������ɫ�ͱ���ɫ
	system("cls");      //��տ���̨
	cout << "�� w/s ѡ��˵�,Enter����,Esc�˳�" << endl << endl;
	menu_admin();
	for (int i = 0; i < 7; i++)
	{
		if (i != index)
		{
			//ûѡ����ûѡ�к�ѡ������������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF);//���ð��ֺڱ���
		}
		else
		{
			//ûѡ��������ѡ�е�ǰ������
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//��ÿ���̨�豸������ľ��
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//�����ı�������Ϊ��ɫ,ǰ��ɫΪ��ɫ
		}
		cout << str[i] << endl;//������ַ����˵�ѡ��

	}//��ʾ���˵�
}


void menu_admin()
{
	cout << "===================================" << endl;
	cout << "|                                 |" << endl;
	cout << "|        ��  ��  Ա  ��  �� ��    |" << endl;
	cout << "|                                 |" << endl;
	cout << "|             ��ӭ����            |" << endl;
	cout << "|                                 |" << endl;
	cout << "|          ��  ��  ��  ѧ         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|       ѧ���ɼ�����ϵͳv1.0      |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "===================================" << endl;
}

void menu_teacher()
{
	cout << "===================================" << endl;
	cout << "|                                 |" << endl;
	cout << "|          ��  ʦ  ��  �� ��      |" << endl;
	cout << "|                                 |" << endl;
	cout << "|             ��ӭ����            |" << endl;
	cout << "|                                 |" << endl;
	cout << "|          ��  ��  ��  ѧ         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|        ѧ���ɼ�����ϵͳv1.0     |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "===================================" << endl;
}

void menu_student()
{
	cout << "===================================" << endl;
	cout << "|                                 |" << endl;
	cout << "|          ͬ  ѧ  ��  �� ��      |" << endl;
	cout << "|                                 |" << endl;
	cout << "|             ��ӭ����            |" << endl;
	cout << "|                                 |" << endl;
	cout << "|          ��  ��  ��  ѧ         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|       ѧ���ɼ�����ϵͳv1.0      |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "|                                 |" << endl;
	cout << "===================================" << endl;
}

void line()
{
	cout << "===================================" << endl;
}