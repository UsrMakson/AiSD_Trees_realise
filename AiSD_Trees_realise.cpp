#include <iostream>



using namespace std;

//#################################################################################################
//struct

typedef struct tree_s {
	char* data;
	struct tree_s* child[3];
} tree;

//#################################################################################################
//func

tree* new_tree(const char* init) { // constructor
	data = strdup(init);
	child[0] = child[1] = child[2] = NULL;
}

//#################################################################################################

int main()
{
	tree* root = new_tree("foo");
	root->child[0] = new_tree("bar");
	root->child[1] = new_tree("abr");
	root->child[2] = new_tree("aca");
	root->child[0]->child[0] = new_tree("dab");
	root->child[0]->child[1] = new_tree("ra");
	system("pause");
}
