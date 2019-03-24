#include <stdio.h>
#include "sort.h"
#include <string.h>

#define NUM 10

int main(){
    int a[NUM]={5,1,7,2,3,4,6,9,8,0};
    for(int i=0;i<NUM;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    quickSort(a,0,NUM-1);
    for(int i=0;i<NUM;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
