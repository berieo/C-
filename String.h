#include<iostream>
#include<string>

using namespace std;

class String {
	struct Srep;			//Srep用于使一个实际表示能够被几个具有同样值的String共享
	Srep* rep;

	class Cref;			//Cref帮助实现下标运算，这个运算需要区别对待读操作和写操作
public:

	class Range { };		//用于异常

	String();			// x = ""
	String(const char*);		// x = "abc" 
	String(const String&);	// x = other_string
	String& operator=(const char*);
	String& operator=(const String&);
	~String();

	void check(int i) const;
	char read(int i) const;
	void write(int i, char c);

	Cref operator[](int i);
	char operator[](int i) const;

	int size() const;

	String& operator+=(const String&);
	String& operator+=(const char*);

	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);

	friend bool operator==(const String& x, const char* s);

	friend bool operator==(const String& x, const String& y);

	friend bool operator!=(const String& x, const char* s);

	friend bool operator!=(const String& x, const String& y);
};

String operator+(const String&, const String&);
String operator+(const String&, const char*);

struct String::Srep {
	char* s;	// 到元素的指针
	int sz;		// 字符个数
	int n;		// 引用计数

	Srep(int nsz, const char* p)
	{
		n = 1;
		sz = nsz;
		s = new char[sz + 1];	//为结束符增加空间
		strcpy(s, p);
	}
	~Srep() { delete[] s; }

	Srep* get_own_copy()	//需要时克隆
	{
		if (n == 1) return this;
		n--;
		return new Srep(sz, s);
	}

	void assign(int nsz, const char* p)   //改变值
	{
		if (sz != nsz) {
			delete[] s;
			sz = nsz;
			s = new char[sz + 1];
		}
		strcpy(s, p);
	}

private:				// 防止复制
	Srep(const Srep&);
	Srep& operator=(const Srep&);
};

class String::Cref {		// 引用s[i]
	friend class String;
	String& s;
	int i;

	Cref(String& ss, int ii) : s(ss), i(ii) { }   //赋值操作

public:
	operator char() const { s.check(i); return s.read(i); }	// 产生值
	void operator=(char c) { s.write(i, c); }			// 修改值
};

String::String()		//以空串作为默认值
{
	rep = new Srep(0, "");
}

String::String(const String& x)	//复制构造函数
{
	x.rep->n++;
	rep = x.rep;	// 共享表示
}

String::~String()
{
	if (--rep->n == 0) delete rep;
}

String& String::operator=(const String & x)	// 复制赋值
{
	x.rep->n++;				// 保护，防止"st = st"
	if (--rep->n == 0) delete rep;
	rep = x.rep;				// 共享表示
	return *this;
}

String::String(const char* s)
{
	rep = new Srep(strlen(s), s);
}

String& String::operator=(const char* s)
{
	if (rep->n == 1)			//再利用Srep
		rep->assign(strlen(s), s);
	else {					//使用新Srep
		rep->n--;
		rep = new Srep(strlen(s), s);
	}
	return *this;
}

void String::check(int i) const
{
	if (i < 0 || rep->sz <= i) throw Range();
}

char String::read(int i) const  //读取第i个字符
{
	check(i);
	return rep->s[i];
}

void String::write(int i, char c)
{
	check(i);
	rep->s[i] = c;
}

String::Cref String::operator[](int i)
{
	check(i);
	return Cref(*this, i);
}

char String::operator[](int i) const      //
{
	check(i);
	return rep->s[i];
}

int String::size() const      //访问size
{
	return rep->sz;
}

ostream& operator<<(ostream & os, const String & s)
{
	return os << s.rep->s;
}

istream& operator>>(istream & is, String & x)
{
	char* s = new char[10];
	is >> s;
	x = s;
	return is;
}

bool operator==(const String & x, const char* s)   //类和头指针比较
{
	return strcmp(x.rep->s, s) == 0;    //相等时strcmp返回0，函数返回1
}

bool operator==(const String & x, const String & y) //两个类比较
{
	return strcmp(x.rep->s, y.rep->s) == 0;
}

bool operator!=(const String & x, const char* s)  //类和头指针比较
{
	return strcmp(x.rep->s, s) != 0;
}

bool operator!=(const String & x, const String & y)  //类和类比较
{
	return strcmp(x.rep->s, y.rep->s) != 0;
}

void ff(String s, const String & r)
{
	char c1 = s[1];
	s[1] = 'c';

	char c2 = r[1];
	//	r[1] = 'd';		// error: assignment to non-lvalue char, r.operator[](1) = 'd'
}

int hash(const String & s)
{
	int h = s.read(0);
	const int max = s.size();
	for (int i = 1; i < max; i++) h ^= s.read(i) >> 1;	// 不加检查地访问s
	return h;
}

String f(String a, String b)
{
	a[2] = 'x';
	char c = b[3];
	cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
	return b;
}
