/*
BST implementation

insert ele 5, 10, 3, 4, 8, 1, 2, 13


                  5
            3           10
         1     4     8     13
           2




                         5
                   3          10
               1      4    8      13
                 2        
                   


inorder(LNR)
1 2 3 4 5 8 10 13


preOder(NLR)
5 3 1 2 4 10 8 13
5  3  1  2  4  10  8  13

postOrder(LRN)
2 1 4 3 8 13 10 5
2  1  4  3  8  13  10  5

inorder(LNR)
1 2 3 4 5 8 10 13

preOder(NLR)
5 3 1 2 4 10 8 13

postOrder(LRN)
2 1 4 3 8 13 10 5

*/

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
  int data;
  struct node *l;
  struct node *r;
}NODE;


NODE *createNode(int val)
{
  NODE *nn = (NODE *)malloc(sizeof(NODE));
  nn->data = val;
  nn->l = NULL;
  nn->r = NULL;
  printf("\nAdd: %p \t value= %d\n",nn,val);
  return nn;
}

NODE *insertNode(NODE *root,int val)
{
  if(root == NULL)
  {
    
    //return nn

    return createNode(val);
  }

  if(root->data < val)
  {
    //right sub tree
    root->r = insertNode(root->r,val);
  }
  else if(root->data > val)
  {
    //left sub tree
    root->l = insertNode(root->l,val);
  }
  else
  {
    printf("\n%d duplicate value found. Hence ignored\n",val);
  }

  return root;
}


void inOrderTrav(NODE *root)
{
  if (root == NULL)
    return;
  
  inOrderTrav(root->l);
  printf(" %d ",root->data);
  inOrderTrav(root->r);
}


void preOrderTrav(NODE *root)
{
  if (root == NULL)
    return;
  
  printf(" %d ",root->data);
  preOrderTrav(root->l);
  preOrderTrav(root->r);
}


void postOrderTrav(NODE *root)
{
  if (root == NULL)
    return;
  
  
  postOrderTrav(root->l);
  postOrderTrav(root->r);
  printf(" %d ",root->data);
}

int main()
{
  NODE *root=NULL;

  root = insertNode(root,5);
  insertNode(root,10);
  insertNode(root,3);
  insertNode(root,4);
  insertNode(root,8);
  insertNode(root,1);
  insertNode(root,2);
  insertNode(root,13);
  
  printf("\nIn Order Traversal\n");
  inOrderTrav(root);
  printf("\n\n");
  printf("\npre Order Traversal\n");
  preOrderTrav(root);
  printf("\n\n");
  printf("\npost Order Traversal\n");
  postOrderTrav(root);
  printf("\n\n");
  return 0;
  

}