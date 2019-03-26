#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;

enum Token_value {
	NAME, NUMBER, END, PLUS = '+',
	MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')',
};
Token_value curr_tok = PRINT;
double expr(bool);
double term(bool);
double prim(bool);
Token_value get_token();
double error(const string&);
map<string, double> table;
int no_of_errors;

int main()
{
	table["pi"] = 3.1415924535;
	table["e"] = 2.178;

	while (cin) {
		get_token();
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
		cout << expr(false) << '\n';
	}
	return no_of_errors;
}

//处理加减
double expr(bool get) {
	double left = term(get);
	for (;;) {
		switch (curr_tok) {
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left += term(true);
			break;
		default:
			return left;
		}
	}
}

// 处理乘除
double term(bool get) {
	double left = prim(get);
	for (;;) {
		switch (curr_tok) {
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true)) {
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
		}
	}
}

double number_value;
string string_value;

// prim处理优先级高的
double prim(bool get) {
	if (get) get_token();

	switch (curr_tok) {
	case NUMBER: {
		double v = number_value;
		get_token();
		return v;
	}
	case NAME: {
		double& v = table[string_value];
		if (get_token() == ASSIGN) v = expr(true);
		return v;
	}
	case MINUS:
		return -prim(true);
	case LP: {
		double e = expr(true);
		if (curr_tok != RP) return error(" ) expected");
		get_token();
		return e;
	}
	default:
		return error("primary expected");
	}
}

Token_value get_token() {
	char ch;

	do { // 低级输入，改进输入
		if (!cin.get(ch)) return curr_tok = END;
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case 0:
		return curr_tok = END;
	case '\n':
		return curr_tok = PRINT;
	case '+':
	case '-':
	case '*':
	case '/':
	case ';':
	case '(':
	case ')':
	case '=':
		return curr_tok = Token_value(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		cin.putback(ch);
		cin >> number_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch)) {
			string_value = ch;
			while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
			cin.putback(ch);
			return curr_tok = NAME;
		}
		error("bad token");
		return curr_tok = PRINT;
	}
}

double error(const string & s) {
	no_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}