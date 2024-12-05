/*

remove dup elements
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct arr
{
  int data;
  struct arr *next;
  
}Array;

Array *createNode(int val)
{
    Array *nn = (Array *)malloc(sizeof(Array));
    nn->data = val;
    nn->next = NULL;
    return nn;
}

Array *appedNode(Array *head, int val)
{
    if(head == NULL)
    {
        head = createNode(val);
        return head;
    }
    else
    {
        while(head->next != NULL)
            head = head->next; 
        head->next = createNode(val);
        
    }
    return head;
}

void display(Array *head)
{
    printf("\n\n");
    while(head)
    {
        printf(" %d ",head->data);
        head = head->next;
    }
    printf("\n\n");
}

void sortA(Array *head)
{
    Array *prevptr = head,  *nextptr =head->next;
    int pVal,nVal;
    int t;
    while(prevptr)
    {
        nextptr = prevptr->next;
        while(nextptr)
        {
            
            if(prevptr->data >= nextptr->data)
            {
                
                t = prevptr->data;
                prevptr->data = nextptr->data;
                nextptr->data = t;
                
            }
            nextptr = nextptr->next;
        }
        prevptr = prevptr->next;
    }
    
}

void removeDup(Array *head)
{
    Array *prevptr = head,  *nextptr =head->next;
    int pVal,nVal;
    int dup;
    while(prevptr)
    {
        // printf("\nnode = %d = %u next=%u\n",prevptr->data,prevptr,prevptr->next);
                
        nextptr = prevptr->next;
        dup = prevptr->data;
        while(nextptr)
        {
            
            if(dup == nextptr->data)
            {
                //found
                // printf("\nfound\n");
                // printf(" %d %u %u \n",prevptr->data,nextptr,nextptr->next);
                prevptr->next = nextptr->next;
                
            }
            nextptr = nextptr->next;
        }
        prevptr = prevptr->next;
    }
    
}

int main() {
    Array *head=NULL;
    int n=5;
    int i;
        
    
    int a[5] = {1,1,1,3,3};
    int b[5] = {5,2,3,1,5};
    
    for(i=0;i<n;i++){
        if(head == NULL)
        {
            head = appedNode(head,b[i]);
            
        }
        else
            appedNode(head,b[i]);
    }
    display(head);
    sortA(head);
    display(head);
    removeDup(head);
    display(head);
    return 0;
}