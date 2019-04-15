#include<iostream>
using namespace std;
//leap year
int leapyear(int yy){  
	if ((yy % 4 == 0 && yy / 100 != 0) || (yy % 400 == 0))
		return 1;  //is leap year
	else
		return 0;  //not leap year
}

class Date {
	int d, m, y;
	static Date default_date;
public:	
	enum Month{jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
	class Bad_date{};      
	Date(int dd = 1, Month mm = Month(1), int yy = 1);  //DONE

	int day() const;       //DONE
	Month month() const;   //DONE
	int year() const;      //DONE

	static void set_default(int, Month, int); //DONE

	Date& add_year(int n);
	Date& add_month(int n);
	Date& add_day(int n);

	void print_date() const;
};

Date::Date(int dd, Month mm, int yy) {
	if (yy == 0) yy = default_date.year();
	if (mm == 0) mm = default_date.month();
	if (dd == 0) dd = default_date.day();
	int max;
	switch (mm) {
	case feb:
		max = 28 + leapyear(yy);
		break;
	case apr: case jun: case sep: case nov:
		max = 30;
		break;
	case jan: case mar: case may: case jul: case aug: case oct: case dec:
		max = 31;
		break;
	default:
		throw Bad_date();
	}
	if (dd < 1 || max << dd) {
		try{
			throw Bad_date();
		}
		catch (Bad_date) {}	
	}	
	y = yy; 
	m = mm; 
	d = dd;
}

Date& Date::add_year(int n) {
	if (n == 0) return *this;

	if (n > 0) {
		if (leapyear(n) && m == 2 && d == 29) {  //If n is a leap year
			y += n;
			m = 3;
			d = 1;
			return *this;
		}
		else {
			y += n;
			return *this;
		}
	}
	return *this;
}

Date& Date::add_month(int n) {
	if (n == 0) return *this;
	
	if (n > 0) {
		int delta_y = n / 12;
		int mm = m + n % 12;
		if (12 < mm) {
			delta_y++;
			mm -= 12;
		}
		y += delta_y;
		m = Month(mm);
		return *this;
	}
	return *this;
}

Date& Date::add_day(int n)
{
	if (n == 0) return *this;
	if (n > 0) {
		while (true) {
			if (n >= 365 + leapyear(y))
				n -= 365 + leapyear(y);
			else
				break;
			add_year(1);
		}
		int max;
		while (true) {
			switch (m) {
			case feb:
				max = 28 + leapyear(y);
				break;
			case apr:case jun:case sep:case nov:
				max = 30;
				break;
			case jan:case mar:case may:case jul:case aug:case oct:case dec:
				max = 31;
				break;
			}
			if (n >= max)
				n -= max;
			else
				break;
			add_month(1);
		}
		if (d + n > max) {
			add_month(1);
			d = d + n - max;
		}
		else
			d = d + n;
		return *this;
	}
	n = -n;
	while (true) {
		if (n >= 365 + leapyear(y))
			n -= 365 + leapyear(y);
		else
			break;
		add_year(-1);
	}
	int max;
	while (true) {
		switch (m) {
		case feb:
			max = 28 + leapyear(y);
			break;
		case apr:case jun:case sep:case nov:
			max = 30;
			break;
		case jan:case mar:case may:case jul:case aug:case oct:case dec:
			max = 31;
			break;
		}
		if (n >= max)
			n -= max;
		else
			break;
		add_month(-1);
	}
	if (d - n <= 0) {
		add_month(-1);
		switch (m) {
		case feb:
			max = 28 + leapyear(y);
			break;
		case apr:case jun:case sep:case nov:
			max = 30;
			break;
		case jan:case mar:case may:case jul:case aug:case oct:case dec:
			max = 31;
			break;
		}
		d = d - n + max;
	}
	else
		d = d - n;
	return *this;
}

//Set the default value to Date
void Date::set_default(int d, Month m, int y) {
	default_date = Date(d, m, y);
}

//Only read
int Date::day() const{
	return d;
}

Date::Month Date::month() const {
	return Month(m);
}

int Date::year() const {
	return y;
}

void Date::print_date() const{        
	cout << y << '/' << m << '/' << d << endl;
}

Date Date::default_date(1, jan, 1);

int main() {
	Date date(31, Date::Month::mar, 1996); //initialize the date
	cout << "Output the set_default value:" << endl;
	Date::default_date.print_date();
	cout << "Output the initialial value:" << endl;
	date.print_date();
	cout << "After add_year:" << endl;
	date.add_year(2);
	date.print_date();
	cout << "After add_month:" << endl;
	date.add_month(1);
	date.print_date();
	cout << "After add_day:" << endl;
	date.add_day(20);
	date.print_date();
	return 0;
}