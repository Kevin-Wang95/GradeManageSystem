#define whF FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY  //对标志位进行组合设置成白字红底
#define whF_rBc  BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY  //对标志位进行组合设置成红字白底

#include<iostream>  
#include<string>    
using namespace std;

class ColorTextChoose_teacher
	//实现类
{
private:
	string str[6];
	//str 为菜单
	int index;
public:
	ColorTextChoose_teacher();  //构造函数初始化数据
	int TextGoing();			//实际运行函数
	void showText();			//显示按钮
};

class ColorTextChoose_student
	//实现类
{
private:
	string str[3];
	//str 为菜单
	int index;
public:
	ColorTextChoose_student();  //构造函数初始化数据
	int TextGoing();			//实际运行函数
	void showText();			//显示按钮
};

class ColorTextChoose_admin
	//实现类
{
private:
	string str[7];
	//str 为菜单
	int index;
public:
	ColorTextChoose_admin();  //构造函数初始化数据
	int TextGoing();		//实际运行函数
	void showText();		//显示按钮
};
