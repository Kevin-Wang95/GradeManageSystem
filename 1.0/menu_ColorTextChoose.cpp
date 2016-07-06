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
	str[0] = "	1、录入学生信息		";
	str[1] = "	2、修改学生成绩		";
	str[2] = "	3、查询学生成绩		";
	str[3] = "	4、单一学科成绩信息	";
	str[4] = "	5、查询不及格学生信息";
	str[5] = "	6、退出				";

	index = 0;
}

int ColorTextChoose_teacher::TextGoing()			//实际运行函数
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
			break;//按w向上
		case 's':
		case 'S':
			if (index == 5)
			{
				this->showText();
				break;
			}
			index++;
			this->showText();
			break;//按s向下
		case 13:
			if (index == 5)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//退格
		}
	}
}

void ColorTextChoose_teacher::showText()			//显示按钮
{
	system("color 07");//还原原系统的字体颜色和背景色
	system("cls");      //清空控制台
	menu_teacher();
	cout << "按 w/s 选择菜单,Enter进入,Esc退出" << endl << endl;
	for (int i = 0; i < 6; i++)
	{
		if (i != index)
		{
			//没选子项没选中和选择下拉框的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF);//设置白字黑背景
		}
		else
		{
			//没选子项的情况选中当前项的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//设置文本背景设为红色,前景色为白色
		}
		cout << str[i] << endl;//输出主字符穿菜单选项

	}//显示主菜单
}

ColorTextChoose_student::ColorTextChoose_student()			//实际运行函数
{
	str[0] = "	1、查询所有成绩		";
	str[1] = "	2、查询不及格课程信息";
	str[2] = "	3、退出				";

	index = 0;
}

int ColorTextChoose_student::TextGoing()			//显示按钮
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
			break;//按w向上
		case 's':
		case 'S':
			if (index == 2)
			{
				this->showText();
				break;
			}
			index++;
			this->showText();
			break;//按s向下
		case 13:
			if (index == 2)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//退格
		}
	}
}

void ColorTextChoose_student::showText()			//显示按钮
{
	system("color 07");//还原原系统的字体颜色和背景色
	system("cls");      //清空控制台
	menu_student();
	cout << "按 w/s 选择菜单,Enter进入,Esc退出" << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		if (i != index)
		{
			//没选子项没选中和选择下拉框的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF);//设置白字黑背景
		}
		else
		{
			//没选子项的情况选中当前项的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//设置文本背景设为红色,前景色为白色
		}
		cout << str[i] << endl;//输出主字符穿菜单选项

	}//显示主菜单
}

ColorTextChoose_admin::ColorTextChoose_admin()  //构造函数初始化数据
{
	str[0] = "	1、录入学生信息		";
	str[1] = "	2、修改学生成绩		";
	str[2] = "	3、查询学生成绩		";
	str[3] = "	4、录入教师信息		";
	str[4] = "	5、修改教师信息		";
	str[5] = "	6、查询教师信息		";
	str[6] = "	7、退出				";

	index = 0;
}

int ColorTextChoose_admin::TextGoing()			//实际运行函数
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
			break;//按w向上
		case 's':
		case 'S':
			if (index == 6)
			{
				this->showText();
				break;
			}
			index++;
			this->showText();
			break;//按s向下
		case 13:
			if (index == 6)
				return -1;
			else
				return index;//Enter
		case 27:
			return -1;//ESC
		default:
			cout << "\b";//退格
		}
	}
}

void ColorTextChoose_admin::showText()			//显示按钮
{
	system("color 07");//还原原系统的字体颜色和背景色
	system("cls");      //清空控制台
	cout << "按 w/s 选择菜单,Enter进入,Esc退出" << endl << endl;
	menu_admin();
	for (int i = 0; i < 7; i++)
	{
		if (i != index)
		{
			//没选子项没选中和选择下拉框的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF);//设置白字黑背景
		}
		else
		{
			//没选子项的情况选中当前项的情况
			HANDLE outPutHandle = GetStdHandle(STD_OUTPUT_HANDLE);//获得控制台设备描述表的句柄
			SetConsoleTextAttribute(outPutHandle, whF_rBc);//设置文本背景设为红色,前景色为白色
		}
		cout << str[i] << endl;//输出主字符穿菜单选项

	}//显示主菜单
}


void menu_admin()
{
	cout << "===================================" << endl;
	cout << "|                                 |" << endl;
	cout << "|        管  理  员  您  好 ！    |" << endl;
	cout << "|                                 |" << endl;
	cout << "|             欢迎进入            |" << endl;
	cout << "|                                 |" << endl;
	cout << "|          清  华  大  学         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|       学生成绩管理系统v1.0      |" << endl;
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
	cout << "|          老  师  您  好 ！      |" << endl;
	cout << "|                                 |" << endl;
	cout << "|             欢迎进入            |" << endl;
	cout << "|                                 |" << endl;
	cout << "|          清  华  大  学         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|        学生成绩管理系统v1.0     |" << endl;
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
	cout << "|          同  学  您  好 ！      |" << endl;
	cout << "|                                 |" << endl;
	cout << "|             欢迎进入            |" << endl;
	cout << "|                                 |" << endl;
	cout << "|          清  华  大  学         |" << endl;
	cout << "|                                 |" << endl;
	cout << "|       学生成绩管理系统v1.0      |" << endl;
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