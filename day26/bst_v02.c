#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int v;
    struct node *left;
    struct node *right;
}NODE;


NODE *createNode(int val)
{
    NODE *nn = (NODE *)malloc(sizeof(NODE));
    nn->v = val;
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

NODE *insertNode(NODE *root, int val)
{
    // printf("\ninserted nn\n");
    if (root == NULL )
    {
        //new tree/tree is not present hence
        //1 st node is the root node
        // printf("\nCreated nn\n");
        return(createNode(val)); 
    }
    else if(val < root->v )
    {
        //left sub tree
        root->left = insertNode(root->left,val);
    }
    else if(val > root->v)
    {
        //right sub tree
        root->right = insertNode(root->right,val);
    }
    else
    {
        printf("\n%d Duplicate Value detected. Hence ignored\n",val);
    }

    return root;
}


void inOrderTrav(NODE *root)
{
    //left->root->right
    if(root==NULL)
        return;
    inOrderTrav(root->left);
    printf(" %d ",root->v);
    inOrderTrav(root->right);

}
void preOrderTrav(NODE *root)
{
    //root->left-right
    if(root==NULL)
        return;
    printf(" %d ",root->v);
    preOrderTrav(root->left);
    preOrderTrav(root->right);
    
}
void postOrderTrav(NODE *root)
{
    //left->right->root
    if(root==NULL)
        return;
    
    postOrderTrav(root->left);
    postOrderTrav(root->right);
    printf(" %d ",root->v);
}



// Function to find the minimum value node in a tree
NODE *findMin(NODE *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node in the BST
NODE *deleteNode(NODE *root, int val) {
    if (root == NULL) {
        return root; // Tree is empty or value not found
    }

    // Find the node to be deleted
    if (val < root->v) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->v) {
        root->right = deleteNode(root->right, val);
    } else {
        // Node to be deleted is found
        // Case 1: Node has no child (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has one child (left or right)
        else if (root->left == NULL) {
            NODE *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node has two children
        else {
            NODE *temp = findMin(root->right); // Find in-order successor
            root->v = temp->v;                 // Replace value with successor
            root->right = deleteNode(root->right, temp->v); // Delete successor
        }
    }
    return root;
}


// Free the allocated memory of the tree nodes
void freeTree(NODE *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
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
    // insertNode(root,5);
/*
                         5
                   3          10
               1      4    8      13
                 2        
                   

inorder(LNR)
1 2 3 4 5 8 10 13

preOder(NLR)
5 3 1 2 4 10 8 13

postOrder(LRN)
2 1 4 3 8 13 10 5
2 1 4 3 5 8 13 10 5

*/

    //traversals
    printf("\ninOrder Traversal\n");
    inOrderTrav(root);
    printf("\npreOrder Traversal\n");
    preOrderTrav(root);
    printf("\npostOrder Traversal\n");
    postOrderTrav(root);

    deleteNode(root,10);


    //traversals
    printf("\ninOrder Traversal\n");
    inOrderTrav(root);
    printf("\npreOrder Traversal\n");
    preOrderTrav(root);
    printf("\npostOrder Traversal\n");
    postOrderTrav(root);

    freeTree(root);
    printf("\n\n");
    return 0;   
}