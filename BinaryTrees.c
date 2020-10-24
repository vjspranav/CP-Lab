#include<stdio.h>
#include<stdlib.h>


#define Bool int

struct node
{
    int data;
    struct node* right;
    struct node* left;

}Node;

struct node * newNode(int data)
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data  = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// Function to check if two given trees are identical 
int identicalTrees(struct node* a, struct node* b)
{
    if ((a == NULL)&&(b==NULL))
        {return 1;}
    if(a!=NULL && b!=NULL) 
    {
        return(
            a->data == b->data&& identicalTrees(a->right, b->right)&& identicalTrees(a->left,b->left)
        );
    }
    return 0;
}
//function to check if two binary trees are structurally same
int similarTrees(struct node * a, struct node * b)
{
    if ((a == NULL)&&(b==NULL))
        {return 1;}
    if(a!=NULL && b!=NULL) 
    {
        return(
            similarTrees(a->right, b->right)&& similarTrees(a->left,b->left)
        );
    }
    return 0;
}
// code to swap the values of two nodes
void swapRL(struct node * a , struct node * b)
{
    struct node* temp;
    temp = a;
    a = b;
    b = temp;
}
// fucntion to check if a given binary tree is a binary search tree
int isBST(struct node* a)
{
    
    if(a==NULL)
    { return 1;}
    if (a->right != NULL && a->left != NULL)
    {
        return ((a->left->data)<(a->data)&&(a->right->data)>(a->data)&&isBST(a->right)&&isBST(a->left));
    }
    if (a->right == NULL && a->left!= NULL)
    {
        return ((a->left->data)<(a->data)&&isBST(a->left));
    }
    if (a->right != NULL && a->left== NULL)
    {
        return ((a->right->data)>(a->data)&&isBST(a->right));
    }
    return 1;

}



//funtion to make the binary tree a mirror of itself
void treeMirror(struct node* a)
{
    if(a== NULL)
    {return;}
    else 
    {  
        
        swapRL(a->right, a->left);
        treeMirror(a->left);
        treeMirror(a->left);
    }
}
// funtion to countt the number of structurally different binary searh trees 
//for given N nodes
int countTrees(int n) {

  if (n<=1) {
    return(1);
  }
  else {
    
    int sum = 0;
    int left, right, root;

    for (root=1; root<=n; root++) {
      left = countTrees(root - 1);
      right = countTrees(n - root);

      
      sum += left*right;
    }

    return(sum);
  }
}

//funtion to find a path in a binary tree summing upto a number N

int hasPathSum(struct node* node, int sum) {
  
  if (node == NULL) {
    return(sum == 0);
  }
  else {
  
    int subSum = sum - node->data;
    return(hasPathSum(node->left, subSum) ||
           hasPathSum(node->right, subSum));
  }
}
//function to print an array
void printArray(int data[], int len) {
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}

//helper funtion to print paths of a binary tree
void printPathsRecur(struct node* node, int path[], int pathLen) {
  if (node==NULL) return;

  path[pathLen] = node->data;
  pathLen++;
  
  if (node->left==NULL && node->right==NULL) {
    printArray(path, pathLen);
  }
  else {
 
    printPathsRecur(node->right, path, pathLen);
    printPathsRecur(node->left, path, pathLen);
  }
}
// funtion to print the paths of a binary tree
void printPaths(struct node* node) {
  int path[100];
  printPathsRecur(node, path, 0);
}

//for printing the tree in graphic format, the right node has to printed first and an reverse 
//inorder traversal is observed with proper spacing
void printHelp( struct node* node, int space)
{
    if(node == NULL)
    {
        return;
    }

    space = space + 1;

    printHelp(node->right, space);
    
    int i;
    printf("\n");
    for(i=0; i<space; i++)
        {printf("\t");}
    printf("%d\n", node->data);
    
   
    
       
    printHelp(node->left, space);
    
    
} 
//funtion for printing the graphic represention of a binary tree
void printGraphic(struct node* node)
{
    printHelp(node, 0);
}
    
    
    


 

//driver function
int main()
{
    struct node *root   = newNode(1); 
    root->left   = newNode(2); 
    root->right  = newNode(3); 
  
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left  = newNode(6); 
    root->right->right = newNode(7); 
  
    //root->left->left->left  = newNode(8); 
    //root->left->left->right  = newNode(9); 
    //root->left->right->left  = newNode(10); 
    //root->left->right->right  = newNode(11); 
    //root->right->left->left  = newNode(12); 
   // root->right->left->right  = newNode(13); 
    //root->right->right->left  = newNode(14); 
   // root->right->right->right  = newNode(15);  
      
    printPaths(root); 
    //printf("\n%d", isBST(root));
    return 0;
}

