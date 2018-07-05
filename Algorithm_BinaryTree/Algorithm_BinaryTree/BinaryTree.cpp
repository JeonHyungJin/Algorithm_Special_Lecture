#include<iostream>
#include<string>
using namespace std;

struct NODE
{
	char value;
	NODE *left, *right;
};

NODE* reconstructTree(string preOrder, string inOrder) {	//트리를 재구성
	NODE *r = NULL;

	if (preOrder.size() == 0) {
		return NULL;
	}
	r = new NODE;
	r->value = preOrder[0];
	r->left = r->right = NULL;
	
	int pos = inOrder.find(preOrder[0]);
	r->left = reconstructTree(preOrder.substr(pos, pos), inOrder.substr(0, pos));
	r->right = reconstructTree(preOrder.substr(pos + 1, preOrder.size()), inOrder.substr(pos + 1, inOrder.size()));

	return r;
}

void post(NODE *root) {	//후위 순회
	if (root == NULL)
		return;
	post(root->left);
	post(root->right);
	cout << root->value << " ";
}

int main() {
	string preOrder, inOrder;
	cin >> preOrder >> inOrder;

	NODE *root = reconstructTree(preOrder, inOrder);
	post(root);
	
	return 0;
}