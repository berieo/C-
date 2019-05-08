#include<iostream>
#include<vector>
using namespace std;

class vector4 {
public:
	float f1 = 1;
	float f2 = 2;
	float f3 = 3;
	float f4 = 4;
	vector4() {};
	vector4(float n1, float n2, float n3, float n4) {
		f1 = n1;
		f2 = n2;
		f3 = n3;
		f4 = n4;
	}
	void operator[] (int account) {
	}

	vector4 operator+ (vector4 v1) {
		vector4 ans1;
		ans1.f1 = f1 + v1.f1;
		ans1.f2 = f2 + v1.f2;
		ans1.f3 = f3 + v1.f3;
		ans1.f4 = f4 + v1.f4;
		return ans1;
	}

	vector4 operator- (vector4 v2) {
		vector4 ans2;
		ans2.f1 = f1 - v2.f1;
		ans2.f2 = f2 - v2.f2;
		ans2.f3 = f3 - v2.f3;
		ans2.f4 = f4 - v2.f4;
		return ans2;
	}
	
	vector4 operator* (vector4 v3) {
		vector4 ans3;
		ans3.f1 = f1 * v3.f1;
		ans3.f2 = f2 * v3.f2;
		ans3.f3 = f3 * v3.f3;
		ans3.f4 = f4 * v3.f4;
		return ans3;
	}

	vector4 operator/ (int m) {
		vector4 ans4;
		ans4.f1 = f1 / m;
		ans4.f2 = f2 / m;
		ans4.f3 = f3 / m;
		ans4.f4 = f4 / m;
		return ans4;
	}

	void operator= (vector4 v5) {
		f1 = v5.f1;
		f2 = v5.f2;
		f3 = v5.f3;
		f4 = v5.f4;
	}

	void operator+= (vector4 v6) {
		f1 = v6.f1 + f1;
		f2 = v6.f2 + f2;
		f3 = v6.f3 + f3;
		f4 = v6.f4 + f4;
	}

	void operator-= (vector4 v7) {
		f1 = f1 - v7.f1;
		f2 = f2 - v7.f2;
		f3 = f3 - v7.f3;
		f4 = f4 - v7.f4;
	}

	void operator*= (vector4 v8) {
		f1 = f1 * v8.f1;
		f2 = f2 * v8.f2;
		f3 = f3 * v8.f3;
		f4 = f4 * v8.f4;
	}

	void operator/= (int n) {
		f1 = f1 / n;
		f2 = f2 / n;
		f3 = f3 / n;
		f4 = f4 / n;
	}
	
};

vector4 vect1;
vector4 vect2;

int main() {
	vector4 box;

	printf("vect1.f1 = 1, vect1.f2 = 2, vect1.f3 = 3, vect1.f4 = 4\n");
	printf("vect2.f1 = 1, vect2.f2 = 2, vect2.f3 = 3, vect2.f4 = 4\n\n");

	box = vect1 + vect2;
	printf("vec1 + vec2:\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", box.f1, box.f2, box.f3, box.f4);
	
	box = vect1 - vect2;
	printf("vec1 - vec2:\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", box.f1, box.f2, box.f3, box.f4);
	
	box = vect1 * vect2;
	printf("vec1 * vec2:\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", box.f1, box.f2, box.f3, box.f4);
	
	box = vect1 / 2;
	printf("vec1 / 2:\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", box.f1, box.f2, box.f3, box.f4);
	
	vector4 box1(1, 3, 5, 7);
	box = box1;
	printf("vec1 = (1, 3, 5, 7):\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", box.f1, box.f2, box.f3, box.f4);

	vect1 += box1;
	printf("vec1 += (1, 3, 5, 7):\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", vect1.f1, vect1.f2, vect1.f3, vect1.f4);
	vect1 = vect2;


	vect1 -= box1;
	printf("vec1 -= (1, 3, 5, 7):\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", vect1.f1, vect1.f2, vect1.f3, vect1.f4);
	vect1 = vect2;

	vect1 *= box1;
	printf("vec1 *= (1, 3, 5, 7):\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", vect1.f1, vect1.f2, vect1.f3, vect1.f4);
	vect1 = vect2;

	vect1 /= 2;
	printf("vec1 /= 2:\nf1 = %f  f2 = %f  f3 = %f  f4 = %f\n\n", vect1.f1, vect1.f2, vect1.f3, vect1.f4);
	return 0;
}