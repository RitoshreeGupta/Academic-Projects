/*
Author: Ritoshree Gupta
Creation Date: 10/27/2019
Modification Date: 11/01/2019
Purpose: read values from the input file and find the tree is a the binary search tree or not. If BST, print the tree traversals(pre,in,post).
*/
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//Function Prototypes
int left(vector<int> input, int index);
int right(vector<int> input, int index);
int current(vector<int> input, int index);
bool isBSTorNot(vector<int> input, bool flag);
vector<int> Bst_preorder(vector<int> input, vector<int> preorder, int k = 1);
vector<int> Bst_inorder(vector<int> input, vector<int> inorder, int k = 1);
vector<int> Bst_postorder(vector<int> input, vector<int> postorder, int k);


vector<int> input; //Initializing a vector which will store the tree values from inputfile
vector <int> preorder; //Initializing a vector which will store the tree values as pre-order traversal
vector <int> inorder; //Initializing a vector which will store the tree values as in-order traversal
vector <int> postorder; //Initializing a vector which will store the tree values as post-order traversal

/*
Pre-Condition: This main function will read the input file, store that input file in a vector. By calling functions, it will print out "Yes" or "No" based on the
			   input file(tree) is binary search tree or not, If the tree is a binary search tree, it will print out Pre,In and Post-order traversals by
			   calling methods. 
Post_Condition: Find binary search tree or not successfully and print all the tree traversals (by calling pre,in,post-order the functions).
*/
int main() {

	ifstream infile;
	infile.open("tree.txt"); // open the input file
	
	input.push_back(-20); // for index 0, put garbage value for easy calculations
	
	int output;
	
	if (infile.peek() == EOF) {
		cout << "The file is empty." << endl;
	}
	
	else {
		if (infile.is_open()) {
			while (!infile.eof()) {
				
					while (infile >> output) {

						if (output >= -1) {
							input.push_back(output); //storing tree values in vector
						}
			}
		}

			bool flag = true;
			cout << "Is this a binary search tree? " << endl;
			bool result = isBSTorNot(input, flag); // call the binary search tree(isBSTorNot) function
			if (result == 1) {
				cout << "Yes" << endl; // if binary search tree then print yes

				preorder = Bst_preorder(input, preorder, 1); //call pre-order traversal
				inorder = Bst_inorder(input, inorder, 1); // call in-order traversal
				postorder = Bst_postorder(input, postorder, 1); // call post-order traversal

				cout << "Pre-order traversal: ";
				for (int i = 0; i < preorder.size(); i++) {
					cout << preorder[i] << " "; //display pre-order traversal
				}
				cout << endl;

				cout << "In-order traversal: ";
				for (int i = 0; i < inorder.size(); i++) {
					cout << inorder[i] << " "; //display in-order traversal
				}
				cout << endl;

				cout << "Post-order traversal: ";
				for (int i = 0; i < postorder.size(); i++) {
					cout << postorder[i] << " "; //display post-order traversal
				}
				cout << endl;
			}

			else {
				cout << "No" << endl; //if not binary search tree print no
			}

			}
		}
	
	system("pause");
	return 0;
}

/*
Pre-Condition: This function parameter take input vector and index of that vector which will returns the left child of the root.
Post_Condition: return left child of the root successfully.
*/

int left(vector<int> input, int index) {
	int k = index;
	int left = input[2 * k]; //formula

	return left;
}

/*
Pre-Condition: This function parameter take input vector and index of that vector which will returns the right child of the root.
Post_Condition: return right child of the root successfully.
*/

int right(vector<int> input, int index) {

	int k = index;
	int right = input[2 * k + 1]; // formula

	return right;
}

/*
Pre-Condition: This function parameter take input vector and index of that vector which will returns the root of the tree.
Post_Condition: return root of the tree successfully.
*/

int current(vector<int> input, int index) {

	int k = index;
	int current = input[k];

	return current;
}


/*
Pre-Condition: This function parameter will take the input vector and flag to check the all bst conditions
Post_Condition: this function return the flag which statisfies the bst conditions.
*/

bool isBSTorNot(vector<int> input, bool flag) {

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == -1) {
			continue;
		}
		else
		{
			left(input, i);
			right(input, i);

			if (input[2 * i] != -1 && input[2 * i] > input[i]) { // left is greater than the root
				flag = false; // make the flag false
			}

			if (input[2 * i + 1] != -1 && input[2 * i + 1] < input[i]) { // right is less than the root
				flag = false; // make the flag false
			}
		}
	}

	return flag; //return flag
}


/*
Pre-Condition: This function parameter will take the input vector, the pre-order vector and index to do the pre-order traversal for that tree
Post_Condition: this function return pre-order traversal successfully.
*/

vector<int> Bst_preorder(vector<int> input, vector<int> preorder, int k) {

	preorder.push_back(current(input, k)); //push the current value

	if (left(input, k) != -1) { // for left child
		vector<int> temp; // temporary vector
		for (int i : Bst_preorder(input, temp, 2 * k)) {
			preorder.push_back(i); 
		}
	}
	
	if (right(input, k) != -1) { //for right child
		vector<int> temp;
		for (int i : Bst_preorder(input, temp, 2 * k + 1)) {
			preorder.push_back(i);
		}
	}

	return preorder;
}

/*
Pre-Condition: This function parameter will take the input vector, the in-order vector and index to do the in-order traversal for that tree
Post_Condition: this function return in-order traversal successfully.
*/


vector<int> Bst_inorder(vector<int> input, vector<int> inorder, int k) {
	
	if (left(input, k) != -1) { // for left child
		vector<int> temp;
		for (int i : Bst_inorder(input, temp, 2*k)) {
			inorder.push_back(i);
		}
	}

	inorder.push_back(current(input, k)); // push the current value

	if (right(input, k) != -1) { // for right child
		vector<int> temp; // temporary vector
		for (int i : Bst_inorder(input, temp, 2 * k + 1)) {
			inorder.push_back(i);
		}
	}

	return	inorder;
}

/*
Pre-Condition: This function parameter will take the input vector, the post-order vector and index to do the post-order traversal for that tree
Post_Condition: this function return post-order traversal successfully.
*/

vector<int> Bst_postorder(vector<int> input, vector<int> postorder, int k) {

	if (left(input, k) != -1) { // for left child
		vector<int> temp; // temporary vector
		for (int i : Bst_postorder(input, temp, 2 * k)) {
			postorder.push_back(i);
		}
	}

	if (right(input, k) != -1) { // for right child
		vector<int> temp;
		for (int i : Bst_postorder(input, temp, 2 * k + 1)) {
			postorder.push_back(i);
		}
	}

	postorder.push_back(current(input, k)); // push the current value

	return postorder;
}