#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <stack>

using namespace std;

//#################################################################################################
//struct

struct TNode
{
	int Data;
	TNode* Left, * Right;
};
typedef TNode* PNode;

//#################################################################################################
//func

int Trans(string str)
{
	if (str == "+") return -1;
	if (str == "-") return -2;
	if (str == "*") return -3;
	if (str == "/") return -4;
	if (str == "^") return -5;
	return stoi(str);
}

char Printing(int x)
{
	if (x == -1) return '+';
	if (x == -2) return '-';
	if (x == -3) return '*';
	if (x == -4) return '/';
	if (x == -5) return '^';
}

void Print(PNode& Root, int level)
{
	if (Root != NULL) {
		Print(Root->Right, level + 1);
		for (int i = 0; i < level; i++)
			cout << setw(4) << ' ';
		if (Root->Data < 0)
			cout << setw(4) << Printing(Root->Data) << endl;
		else
			cout << setw(4) << Root->Data << endl;
		Print(Root->Left, level + 1);
	}
}

int Calc(PNode Root)
{
	if (Root->Data > 0) return Root->Data;
	switch (Root->Data)
	{
	case -1: return Calc(Root->Left) + Calc(Root->Right);
	case -2: return Calc(Root->Left) - Calc(Root->Right);
	case -3: return Calc(Root->Left) * Calc(Root->Right);
	case -4: return Calc(Root->Left) / Calc(Root->Right);
	case -5: return (int)pow(Calc(Root->Left), Calc(Root->Right));
	}
}

void Del(PNode Root)
{
	if (Root != NULL)
	{
		Del(Root->Left);
		Del(Root->Right);
		delete Root;
	}
}


//#################################################################################################

int main()
{
	ifstream f("input.txt");
	string str;
	stack <PNode> st;
	PNode t = NULL, Root;
	while (f >> str)
	{
		int op = Trans(str);
		t = new TNode;
		t->Data = op;
		t->Left = t->Right = NULL;
		if (op >= 0)
			st.push(t);
		else {
			t->Right = st.top();
			st.pop();
			t->Left = st.top();
			st.pop();
			st.push(t);
		}
	}
	Root = t;
	Print(Root, 0);
	cout << Calc(Root);
	Del(Root);
	return 0;
}
