#define whF FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY  //�Ա�־λ����������óɰ��ֺ��
#define whF_rBc  BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_INTENSITY  //�Ա�־λ����������óɺ��ְ׵�

#include<iostream>  
#include<string>    
using namespace std;

class ColorTextChoose_teacher
	//ʵ����
{
private:
	string str[6];
	//str Ϊ�˵�
	int index;
public:
	ColorTextChoose_teacher();  //���캯����ʼ������
	int TextGoing();			//ʵ�����к���
	void showText();			//��ʾ��ť
};

class ColorTextChoose_student
	//ʵ����
{
private:
	string str[3];
	//str Ϊ�˵�
	int index;
public:
	ColorTextChoose_student();  //���캯����ʼ������
	int TextGoing();			//ʵ�����к���
	void showText();			//��ʾ��ť
};

class ColorTextChoose_admin
	//ʵ����
{
private:
	string str[7];
	//str Ϊ�˵�
	int index;
public:
	ColorTextChoose_admin();  //���캯����ʼ������
	int TextGoing();		//ʵ�����к���
	void showText();		//��ʾ��ť
};
