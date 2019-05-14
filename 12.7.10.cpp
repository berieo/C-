#include<iostream>
#include<math.h>
using namespace std;
#define PI 3.14

class Shape{
public:
	double area;
	virtual ~Shape() {}     //析构函数
	void virtual Area() = 0;//面积，纯虚数
};

class Circle : public Shape{
private:
	double radius;//数据成员，表示半径
public:
	Circle(double r = 0) :radius(r) {}//构造函数
	void Area() { area = PI * radius * radius; }
};

class Square : public Shape {
private:
	double side;
public:
	Square(double s) : side(s){}//构造函数
	void Area() { area = side * side ; }
};

class Triangle : public Shape {
private:
	double a, b, c;
public:
	Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
	void Area(){ 
		area = sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a)) / 4; 
	}
};

bool intersect(Shape* shape1, Shape* shape2) {
	//Some code to judge if overlap
	cout << "Function intersect" << endl;
	if (1)
		return 1;
	else
		return 0;
}

int main() {
	Circle c(1);
	Square s(1);
	Triangle t(3, 4, 5);
	intersect(&c, &s);
	intersect(&s, &t);
	intersect(&c, &t);
	return 0;
}