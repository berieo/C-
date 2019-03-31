//Write a function for entering new words into a tree of Tnodes.
//Write a function to write out a tree of Tnodes.
//Write a function to write out a tree of Tnodes with the words in alphabetical order.
//Modify Tnodes so that it stores(only) a pointer to an arbitrarily 
//long word stored as an array of characters on free store using new.
//Modify the functions to use the new definition of Tnodes

#include<iostream>
#include<string>
using namespace std;
 
typedef struct Tnode {
	char *word = new char[6];
	int count = 0;
	Tnode* left;
	Tnode* right;
}Tnode;

Tnode* tree;
int num = 0;
char name[10][10];
int i = 0;

void insert_word(Tnode* &tree) {
	char *ch = new char[6];
	cin >> ch;
	if (!strcmp(ch, "END")) {
		tree = NULL;
	}
	else {
		tree = new Tnode;
		strcpy_s(tree->word, 10, ch);
		tree->count = num++;
		insert_word(tree->left);
		insert_word(tree->right);
	}
}

void print_tree(Tnode* &tree) {
	//先序递归遍历二叉树 
	if (tree) {//当结点不为空的时候执行 
		printf("%s ", tree->word);
		print_tree(tree->left);
		print_tree(tree->right);
	}
	else cout << "";
}

void print_inorder(Tnode*& tree) {
	if (tree) {//当结点不为空的时候执行 
		strcpy_s(name[i++],tree->word);
		print_inorder(tree->left);
		print_inorder(tree->right);
	}
	else cout << "";
}

void order_word() {
	char temp[10] = { 0 };
	int m;
	for (m = 0; m < 10 - 1; m++) {
		for (int n = 0; n < 10 - 1 - m; n++) {
			if (strcmp(name[n], name[n + 1]) > 0) {
				//对字符串进行交换时,使用strcpy函数.
				strcpy_s(temp, name[n]);
				strcpy_s(name[n], name[n + 1]);
				strcpy_s(name[n + 1], temp);
			}
		}
	}
	for (m = 0; m < 10; m++) {
		printf("%s ", name[m]);
	}
}
int main() {
	cout << "Please write down the word you want to insert:" << endl;
	insert_word(tree);
	cout << "Output the words:" << endl;
	print_tree(tree);
	print_inorder(tree);
	cout << endl << "rank in alphabetical order: " << endl;
	order_word();
	return 0;
}