#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

int partition(int *,int,int);
int part(int *,int,int);

int qSort(int [],int,int);
int swap(int [], int *);
int display(int *, int);
int disp(int *,int,int);


int display(int a[],int n)
{
    int i;
    printf("\n\n");
    for(i=0;i<n;i++)
        printf(" %d ", a[i]);
    printf("\n\n");
}

int disp(int a[],int low, int high)
{
    int i;
    printf("\nDisp intermediate array\n");
    for(i=low;i<=high;i++)
        printf(" %d ", a[i]);
    printf("\n\n");
}

int swap(int *v1, int *v2)
{
    int t = *v1;
    *v1 = *v2;
    *v2 = t;
    return 0;
}

int partition(int a[],int low,int high)
{
    int i = low - 1;
    int pivot = a[high];
    int j;
    printf("\nPivot=%d\n",pivot);
    for(j=low;j<high;j++){

        //printf("\nlptr=%d\trptr=%d\n",a[i],a[j]);
            
        if(a[j]<=pivot)
        {
            i++;
            printf("\nSwap ele lptr=%d\trptr=%d\n",a[i],a[j]);
            swap(&a[i],&a[j]);
            disp(a,low,high);
        }
    } 
    printf("\nSwap pivot lptr=%d\tpivot=%d\n",a[i+1],a[high]);   
    swap(&a[i+1],&a[high]);

    return (i+1);
}

int part(int a[],int low,int high)
{
    int rptr = high-1;
    int pivot = a[high];
    int lptr=low;
    int swapedl=0;
    int swapedr=0;
    disp(a,low,high);
    printf("\nPivot=%d\n",pivot);

    //lptr loop until lptr < pivot values and also stop 
    // if lptr is eqto rptr
START:
    swapedl = 0;
    swapedr = 0;
    printf("\nloop for lptr\n");
    printf("\nlptr=%d\trptr=%d\n",lptr,rptr);
    printf("\nlptr=%d\trptr=%d\n",a[lptr],a[rptr]);
    while((a[lptr]<=pivot)&&(lptr<rptr))
    {
        printf("\nin while left\tlptr=%d\trptr=%d\n",a[lptr],a[rptr]);

        lptr++;
        swapedl = 1;
    }

    //rptr loop until rptr > pivot values and also stop 
    // if rptr is eqto lptr
    printf("\nloop for rptr\n");
    printf("\nlptr=%d\trptr=%d\n",lptr,rptr);
    printf("\nlptr=%d\trptr=%d\n",a[lptr],a[rptr]);
    
    while((a[rptr]>=pivot)&&(rptr>lptr))
    {
        printf("\nin while right\tlptr=%d\trptr=%d\n",a[lptr],a[rptr]);

        rptr--;
        swapedr=1;
    }    

    //check if lptr == rptr
    //if so swap lptr with pivot
    //else swap lptr ele with rptr ele
    printf("\nswapedl=%d\tswapedr=%d",swapedl,swapedr);
    if(lptr == rptr)
    {
        if((swapedl==1)&&(swapedr==1)){
        printf("\nmeet 4 cond\nswap lptr with pivot\n");
        printf("\nSwap lptr=%d\tpivot=%d\n",a[lptr],a[high]);   
        swap(&a[lptr],&a[high]);
        return lptr;
        }
        else
        {
            printf("\nelse\n");
            
            printf("\nlptr=%d,rptr=%d,pivot=%d",a[lptr],a[rptr],a[high]);
            if((swapedl==0)&&(swapedr==0)){
                printf("\n**************\n");
                if(a[lptr]>a[high]){
                    printf("\nmeet 4 cond\nswap lptr with pivot\n");
                    printf("\nSwap lptr=%d\tpivot=%d\n",a[lptr],a[high]);   
                    swap(&a[lptr],&a[high]);
                    printf("\nswap ele = %d %d\tlptr=%d\n",a[lptr],a[high],lptr);
                    return lptr;
                }
                else{
                    printf("\nNo Swap\n");
                    return high;
                }
            }
            if((swapedl==1)&&(swapedr==0)){
                printf("\n******swapedl********\n");
                if(a[lptr]>a[high]){
                    printf("\nmeet 4 cond\nswap lptr with pivot\n");
                    printf("\nSwap lptr=%d\tpivot=%d\n",a[lptr],a[high]);   
                    swap(&a[lptr],&a[high]);
                    printf("\nswap ele = %d %d\tlptr=%d\n",a[lptr],a[high],lptr);
                    return lptr;
                }
                else{
                    printf("\nNo Swap\n");
                    return high;
                }
            }
            if((swapedl==0)&&(swapedr==1)){
                printf("\n******swapedr********\n");
                if(a[lptr]>a[high]){
                    printf("\nmeet 4 cond\nswap lptr with pivot\n");
                    printf("\nSwap lptr=%d\tpivot=%d\n",a[lptr],a[high]);   
                    swap(&a[lptr],&a[high]);
                    printf("\nswap ele = %d %d\tlptr=%d\n",a[lptr],a[high],lptr);
                    return lptr;
                }
            }   
        }
        

    }


    else
    {
        
        printf("\nswap lptr ele with rptr ele\n");
        printf("\nSwap lptr=%d\trptr=%d\n",a[lptr],a[rptr]);   
        swap(&a[lptr],&a[rptr]);
        disp(a,low,high);
        
        lptr++;
        if(lptr<rptr){
         
            rptr--;
        }
        printf("\nLPTR=%d\tRPTR=%d\n",lptr,rptr);
        
        goto START;
    }

    
}




int qSort(int a[],int low,int high)
{
    int pi=0; //partition index
    printf("\nlow=%d\thigh=%d",low,high);
    if (low<high)
    {
        // pi = partition(a,low,high);
        pi = part(a,low,high);
        
        printf("\npi = %d",pi);
        qSort(a,low,pi-1);
        disp(a,low,pi-1);
        printf("\n================================\n");
        qSort(a,pi+1,high);
        disp(a,pi+1,high);
    }
}

int main()
{
    // int a[] = {70,10,80,30,90,40,60,20,50};
    //sorted array
    // int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    //reverse sorted array
    // int a[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    // Array with Duplicates:
    // int a[] = {50, 20, 50, 10, 30, 50, 40, 20};
    // Array with Negative Numbers:
    // int a[] = {0, -10, 20, -30, 40, -50, 60, -70};

    // int a[] = {10,10,10,10,10};
    // int a[] = {0, 30, 10, 50, 0, 20};

    // int a[] = {};
    int a[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0, -10, -20, -30, -40, -50, -60, -70, -80, -90};



    int size = sizeof(a)/sizeof(a[0]);
    int low = 0, high = size-1;
    printf("\nBefore Sort\n");
    display(a,size);

    qSort(a,low,high);
    printf("\nAfter Sort\n");
    display(a,size);
    printf("\n\n");
    return 0;
}