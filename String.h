#include<iostream>
#include<string>

using namespace std;

class String {
	struct Srep;			//Srep����ʹһ��ʵ�ʱ�ʾ�ܹ�����������ͬ��ֵ��String����
	Srep* rep;

	class Cref;			//Cref����ʵ���±����㣬���������Ҫ����Դ���������д����
public:

	class Range { };		//�����쳣

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
	char* s;	// ��Ԫ�ص�ָ��
	int sz;		// �ַ�����
	int n;		// ���ü���

	Srep(int nsz, const char* p)
	{
		n = 1;
		sz = nsz;
		s = new char[sz + 1];	//Ϊ���������ӿռ�
		strcpy(s, p);
	}
	~Srep() { delete[] s; }

	Srep* get_own_copy()	//��Ҫʱ��¡
	{
		if (n == 1) return this;
		n--;
		return new Srep(sz, s);
	}

	void assign(int nsz, const char* p)   //�ı�ֵ
	{
		if (sz != nsz) {
			delete[] s;
			sz = nsz;
			s = new char[sz + 1];
		}
		strcpy(s, p);
	}

private:				// ��ֹ����
	Srep(const Srep&);
	Srep& operator=(const Srep&);
};

class String::Cref {		// ����s[i]
	friend class String;
	String& s;
	int i;

	Cref(String& ss, int ii) : s(ss), i(ii) { }   //��ֵ����

public:
	operator char() const { s.check(i); return s.read(i); }	// ����ֵ
	void operator=(char c) { s.write(i, c); }			// �޸�ֵ
};

String::String()		//�Կմ���ΪĬ��ֵ
{
	rep = new Srep(0, "");
}

String::String(const String& x)	//���ƹ��캯��
{
	x.rep->n++;
	rep = x.rep;	// �����ʾ
}

String::~String()
{
	if (--rep->n == 0) delete rep;
}

String& String::operator=(const String & x)	// ���Ƹ�ֵ
{
	x.rep->n++;				// ��������ֹ"st = st"
	if (--rep->n == 0) delete rep;
	rep = x.rep;				// �����ʾ
	return *this;
}

String::String(const char* s)
{
	rep = new Srep(strlen(s), s);
}

String& String::operator=(const char* s)
{
	if (rep->n == 1)			//������Srep
		rep->assign(strlen(s), s);
	else {					//ʹ����Srep
		rep->n--;
		rep = new Srep(strlen(s), s);
	}
	return *this;
}

void String::check(int i) const
{
	if (i < 0 || rep->sz <= i) throw Range();
}

char String::read(int i) const  //��ȡ��i���ַ�
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

int String::size() const      //����size
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

bool operator==(const String & x, const char* s)   //���ͷָ��Ƚ�
{
	return strcmp(x.rep->s, s) == 0;    //���ʱstrcmp����0����������1
}

bool operator==(const String & x, const String & y) //������Ƚ�
{
	return strcmp(x.rep->s, y.rep->s) == 0;
}

bool operator!=(const String & x, const char* s)  //���ͷָ��Ƚ�
{
	return strcmp(x.rep->s, s) != 0;
}

bool operator!=(const String & x, const String & y)  //�����Ƚ�
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
	for (int i = 1; i < max; i++) h ^= s.read(i) >> 1;	// ���Ӽ��ط���s
	return h;
}

String f(String a, String b)
{
	a[2] = 'x';
	char c = b[3];
	cout << "in f: " << a << ' ' << b << ' ' << c << '\n';
	return b;
}
