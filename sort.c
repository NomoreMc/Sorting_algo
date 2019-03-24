#include <stdio.h>
#include <stdlib.h>
int partition(int a[], int lo, int hi);
int partition2(int a[], int lo, int hi);
void merge(int a[], int lo, int mid, int hi);


void insertionSort(int a[], int lo, int hi){
    int i,j,temp;
    for(i=lo+1;i<=hi;i++){
        temp=a[i];
        for(j=i;j>lo;j--){
            if(temp > a[j-1])
                break;
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
}

void selectionSort(int a[], int lo, int hi){
    int i,j,min,index;
    for(i=lo;i<hi;i++){
        min=a[i];
        for(j=i+1;j<=hi;j++){
            if(a[j]<min){
                min=a[j];
                index=j;
            }
        }
        a[index]=a[i];
        a[i]=min;
        min=0;
    }
}

void bubbleSort(int a[], int lo, int hi){
    int i,j,temp,count;
    for(i=lo;i<hi;i++){
        count=0;
        for(j=hi;j>lo;j--){
            if(a[j]<a[j-1]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                count++;
            }
        }
        if(count==0)
            break;
    }
}

void shellSort(int a[], int lo, int hi){
    int len=hi-lo,i,j,temp;
    for(int inc=len/2;inc>0;inc=inc/2){
        for(i=inc;i<=len;i++){
            temp=a[i];
            for(j=i-inc;j>=0;j-=inc)
                if(a[j]>temp){
                    a[j+inc]=a[j];
                }
                else{
                    break;
                }
        a[j+inc]=temp;
        }
    }
}

void quickSort(int a[], int lo, int hi){
    int i;
    if(lo>=hi)
        return;
    //printf("here!\n");
    i=partition(a,lo,hi);
    quickSort(a,lo,i-1);
    quickSort(a,i+1,hi);
}
int partition(int a[], int lo, int hi){
    int v=a[lo]; //pivot
    int i=lo+1, j=hi;
    int temp;
    for(;;){
        while(a[i]>v && i<j) i++;
        while(a[j]<v && j>i) j--;
        if(i==j) break;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    if(a[i]>v)
        j=i;
    else
        j=i-1;
    temp=a[lo];
    a[lo]=a[j];
    a[j]=temp;
    return j;
}

void quickSort2(int a[], int lo, int hi){
    if(lo>=hi)
        return;
    int Pivot=partition2(a, lo, hi);
    quickSort2(a,lo,Pivot-1);
    quickSort2(a,Pivot+1,hi);
}

int partition2(int a[], int lo, int hi){
    int Pivot=a[hi];
    int Pindex=lo;
    int temp;
    for(int i=lo;i<hi;i++){
        if(a[i]<=Pivot){
            temp=a[i];
            a[i]=a[Pindex];
            a[Pindex]=temp;
            Pindex++;
        }
    }
    temp=a[hi];
    a[hi]=a[Pindex];
    a[Pindex]=temp;
    return Pindex;
}

void mergeSort(int a[], int lo, int hi){
    if(lo>=hi)
        return;
    int mid=(lo+hi)/2;
    mergeSort(a,lo,mid);
    mergeSort(a,mid+1,hi);
    merge(a,lo,mid,hi);
}

void merge(int a[], int lo, int mid, int hi){
    int i,j,k,total=hi-lo+1;
    int *temp=malloc(total*sizeof(int));
    i=lo;
    j=mid+1;
    k=0;
    while(i<=mid && j<=hi){
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=hi)
        temp[k++]=a[j++];
    for(i=lo,k=0;i<=hi;i++,k++)
        a[i]=temp[k];
    free(temp);
}

void non_recursive_mergeSort(int a[], int lo, int hi){
    int m;
    int end;
    int i;
    for(m=1;m<=hi;m=m*2){
        for(i=lo;i<=hi-m;i+=2*m){
            if((i+2*m-1)<hi)
                end=i+2*m-1;
            else
                end=hi;
            merge(a,i,i+m-1,end);
        }
    }
}
