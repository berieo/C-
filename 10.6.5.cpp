#include <iostream>

class Histogram {
	int array[10][3];
	int i = 0;
public:
	Histogram(int start = 0, int end = 0, int count = 0);
	void value(int start = 0, int end = 0, int count = 0);
	void print_Histogram();
	struct Bad_Histogram {};
};

Histogram::Histogram(int start, int end, int count) {
	array[i][0] = start;
	array[i][1] = end;
	array[i][2] = count;
	i++;
}

void Histogram::value(int start, int end, int count) {
	try {
		if (start < array[0][0] || end > array[0][1] || start >= array[0][1] || end <= array[0][0]) {
			throw - 1;
		}
		else if (end - start != 1)
			throw - 2;
	}
	catch (int th) {
		switch (th) {
		case -1 : std::cerr << "Range overload" << std::endl;
		case -2: std::cerr << "The section is not 1" << std::endl;
		}
		
	}
	array[i][0] = start;
	array[i][1] = end;
	array[i][2] = count;
	i++;
}

void Histogram::print_Histogram() {
	int m = 0;
	int n = 0;
	for(; n < i; n++)
		for (m = n + 1; m < i; m++) {
			if (array[n][0] == array[m][0]) {
				array[n][2] += array[m][2];
				array[m][2] = 0;
			}
		}
	for (m = 0; m < i; m++) {
		if (array[m][2] != 0)
			std::cout << '(' << array[m][0] << ',' << array[m][1] << ')' << ' ' << array[m][2] << std::endl;
	}
}

int main() {
	Histogram histogram(0, 10, 0);
	histogram.value(0, 1, 2);
	histogram.value(2, 4, 2);
	histogram.value(1, 2, 4);
	histogram.value(1, 2, 5);
	histogram.value(3, 4, 2);
	histogram.print_Histogram();
	return 0;
}