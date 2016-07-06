#ifndef BASECLASS_H_
#define BASECLASS_H_

#include<iostream>
using namespace std;

class status							//验证身份所使用的类
{
public:
	status(char n = '0', int pn = -1, int pw = -1);
	int get_pn() const;
	int get_pw() const;
	char get_sta() const;
	void set_pn(int);
	void set_pw(int);
	void set_sta(char);
	friend istream & operator>>(istream &, status &);
private:
	char status_;
	int pass_name;
	int pass_word;
};

class person							//定义基本的person抽象类
{
public:
	person(char *n = "person", int no_ = -1, int a = -1, char s = 'M');
	int get_age() const;
	char *get_name() const;
	char get_sex() const;
	int get_no() const;
	void set_age(int);
	void set_name(char*);
	void set_sex(char);
	void set_no(int);
	void print() const;
protected:
	int age;
	char name[20];
	char sex;
	int no;
};

class course							//定义基本的course抽象类
{
public:
	course(int cm = -1, int cn = -1, char *n = "course", int cr = -1);
	char *get_courname() const;
	void set_courname(char*);
	int get_courmode() const;
	void set_courmode(int);
	int get_credit() const;
	void set_credit(int); 
	int get_cournum() const;
	void set_cournum(int);
	virtual void display() const = 0;
protected:
	int coursemode;						//课程模式，1代表pass类课程，0代表score类课程
	char coursename[20];
	int coursenum;						//课程号
	int credit;							//学分
};

class coursescore :public course		//声明记分数课程类
{
public:
	coursescore(int cm = -1, int cn = -1, char *n = "course", int cr = -1, int sc = -1);
	void display() const;
	int get_score() const;
	void set_score(int);
protected:
	int score;
	
};

class coursepass :public course			//声明记通过课程类
{
public:
	coursepass(int cm = -1, int cn = -1, char *n = "course", int cr = -1, char gr = 'P');
	void display() const;
	char get_grade() const;
	void set_grade(char);
protected:
	char grade;
};

class studentscore :public person, public coursescore				//声明学生记分数类
{
public:
	studentscore(char *n = "person", int no_ = -1, int a = -1, char s = 'M', int cm = -1, int cn = -1, char *m = "course", int cr = -1, int sc = -1);
	void display() const;
	friend ostream & operator<<(ostream &, studentscore &);
	friend istream & operator>>(istream &, studentscore &);
};

class studentpass :public person, public coursepass					//声明学生记通过类
{
public:
	studentpass(char *n = "person", int no_ = -1, int a = -1, char s = 'M', int cm = -1, int cn = -1, char *m = "course", int cr = -1, char gr = 'P');
	void display() const;
	friend ostream & operator<<(ostream &, studentpass &);
	friend istream & operator>>(istream &, studentpass &);
};

class teacher :public person, public course							//声明教师类
{
public:
	teacher(char *n = "teacher", int no_ = -1, int a = -1, char s = 'M', int cm = -1, int cn = -1, char *m = "course", int cr = -1);
	void print() const;
	void display() const;
	friend ostream & operator<<(ostream &, teacher &);
	friend istream & operator>>(istream &, teacher &);
};
#endif