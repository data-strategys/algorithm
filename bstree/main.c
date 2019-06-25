
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
struct TreeNode_;

typedef struct TreeNode_ TreeNode;

typedef int Data;

struct TreeNode_{
	TreeNode *left;
	TreeNode *right;       
	Data data;
};

typedef TreeNode  TreeNode;
typedef TreeNode* Tree;

void preOrder(Tree root)
{
	if (root==NULL)return ;
 	printf("%d \n",root->data);
	preOrder(root->left);
	preOrder(root->right);	

}

void inOrder(Tree root){
	if (root==NULL)return ;
	inOrder(root->left);
	printf("%d \n",root->data);
	inOrder(root->right);
}

void postOrder(Tree root){
	if (root==NULL)return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d \n",root->data);


}

TreeNode* newTreeNode(Data data)
{
	Tree tree =0;
	do {
	  tree = (Tree) malloc(sizeof(TreeNode));
	}while(tree==0);
	memset(tree,0,sizeof(TreeNode));
	tree->data = data;
	return tree;
}

void Add2Left(Tree root,TreeNode *n){
     if (root==NULL) return ;
	root->left =n;
}
void Add2Right(Tree root,TreeNode *n){
     if (root==NULL) return;
	root->right=n;
}

void DeleteByPostOrder(Tree root){
 if (root==NULL)return;
        DeleteByPostOrder(root->left);
        DeleteByPostOrder(root->right);
        printf("%d will delete ..\n",root->dat`a);
        free(root);
}


//bs tree insert implimation has sort function
void insertNode(Tree root,TreeNode* n){
	if (root==NULL || n==NULL) return ;
	if (root->data < n->data){ //turn right
		if (root->right==NULL){
		    root->right=n;
		}else{
		    insertNode(root->right,n);
		}
	}else{ //turn left
		if (root->left==NULL){
		    root->left=n;	
		}else{
		    insertNode(root->left,n);
		}
	}
}


int main(int argc,const char *argvs[]){
		
	Tree tree = newTreeNode(10);

	// human insert
	TreeNode *layer1_left = newTreeNode(1);
	TreeNode *layer1_right = newTreeNode(2);
		
	Add2Left(tree,layer1_left);
	Add2Right(tree,layer1_right);

	TreeNode *layer1_left_left = newTreeNode(11);
	TreeNode *layer1_left_right= newTreeNode(12);
	Add2Left(layer1_left,layer1_left_left);
	Add2Right(layer1_left,layer1_left_right);	


	TreeNode *layer1_right_left = newTreeNode(22);
	TreeNode *layer1_right_right = newTreeNode(23);
	Add2Left(layer1_right,layer1_right_left);
	Add2Right(layer1_right,layer1_right_right);
	

	printf("preOder...\n");
	preOrder(tree);
			
	printf("inOder...\n");
	inOrder(tree);
	
	printf("postOder...\n");
	postOrder(tree);
	
	DeleteByPostOrder(tree);
	
	return 0;
}

