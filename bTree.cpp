#include <iostream>
using namespace std;

class Node
{
public:
	int key;
	int item;
	Node* leftChild;
	Node* rightChild;

	~Node()
	{
		delete leftChild;
		delete rightChild;
	}

	void displayNode()
	{
		cout << "{" << key << ", " << item << "} ";
	}
};

class Tree
{
private:
	Node* root;

public:
	Tree() {root = NULL;}
	~Tree() {delete root;}
	

	//method traverses tree until correct key is found
	//if not found, method returns null
	Node* find(int lookUp)
	{
		Node* current = root;
		while(current->key != lookUp)
		{
			(lookUp < current->key) ? current = current->leftChild : current = current->rightChild;
			if(current == NULL) return NULL;
		}
		return current;
	}

	//method inserts a new node at appropriate path
	void insert(int newKey, int data)
	{
		Node* newNode = new Node();
		newNode->key = newKey;
		newNode->item = data;
		//if tree is empty, new item will be the root
		if(root == NULL) root = newNode;
		else
		{
			Node* current = root;
			Node* parent;
			while(true)
			{
				parent = current;
				if(newKey < current->key)
				{
					current = current->leftChild;
					if (current == NULL)
					{
						parent->leftChild = newNode;
						return;
					}
				}
				else
				{
					current = current->rightChild;
					if(current == NULL)
					{
						parent->rightChild = newNode;
						return;
					}
				}
			}
		}
	}

	Node* getSuccessor(Node* delNode)
	{
		Node* successorParent = delNode;
		Node* successor = delNode;
		Node* current = delNode->rightChild;

		while(current != NULL)
		{
			successorParent = successor;
			successor = current;
			current = current->leftChild;
		}

		if(successor != delNode->rightChild)
		{
			successorParent->leftChild = successor->rightChild;
			successor->rightChild = delNode->rightChild;
		}
		return successor;
	}

	bool deleteNode(int nodeToDelete)
	{
		Node* current = root;
		Node* parent = root;
		bool isLeftChild = true;

		while(current->key != nodeToDelete)
		{
			parent = current;
			if(nodeToDelete < current->key)
			{
				isLeftChild = true;
				current = current->leftChild;
			}
			else
			{
				isLeftChild = false;
				current = current->rightChild;
			}
			if(current == NULL) return false;
		}

		if(current->leftChild == NULL &&
			current->rightChild == NULL)
		{
			if(current == root) root = NULL;
			else if(isLeftChild) parent->leftChild = NULL;
			else parent->rightChild = NULL;
		}
		else if(current->rightChild == NULL)
		{
			if (current == root)
			{
				root = current->leftChild;
			}
			else if(isLeftChild)
			{
				parent->leftChild = current->leftChild;
			}
			else
			{
				parent->rightChild = current->leftChild;
			}
		}
		else if(current->leftChild == NULL)
		{
			if(current == root) root = current->rightChild;
			else if(isLeftChild) parent->leftChild = current->rightChild;
			else parent->rightChild = current->rightChild;
		}
		else
		{
			Node* successor = getSuccessor(current);
			if(current == root) root = successor;
			else if(isLeftChild) parent->leftChild = successor;
			else parent->rightChild = successor;
			successor->leftChild = current->leftChild;
		}
		delete current;
		return true;
	}

	void inOrder(Node* localRoot)
	{
		if(localRoot != NULL)
		{
			inOrder(localRoot->leftChild);
			cout << localRoot->key << " " << endl;
			inOrder(localRoot->rightChild);
		}
	}

	Node* giveNode()
	{
		return root;
	}
};

int main(int argc, char const *argv[])
{
	Tree theTree;
	theTree.insert(50,1);
	theTree.insert(25,1);
	theTree.insert(75,1);
	theTree.insert(12,1);
	theTree.insert(37,1);
	theTree.insert(43,1);
	theTree.insert(30,1);
	theTree.insert(33,1);
	theTree.insert(87,1);
	theTree.insert(93,1);
	theTree.insert(97,1);
	Node* d = theTree.giveNode();
	theTree.inOrder(d);
	return 0;
}