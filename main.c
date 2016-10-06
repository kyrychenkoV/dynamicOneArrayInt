#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "funkc.h"
#include "funkc.c"
int *addDynamicArray();
int count;
int main()
{
    char *teststring="10 20 13 40 50 70 80 90 100";
    addNewFiles(teststring);
    int *arr=addDynamicArray();
    int sum=functionSumElementArray(arr,count);
    recordSumToFile(sum);

    return 0;
}
int *addDynamicArray(){
    FILE * myfile ;
    myfile=fopen(fileName(),"r");
    int i=0;
    int *arr=(int*)malloc(sizeof(int));
    while(fscanf(myfile, "%d", &arr[i])!=EOF){
        printf("%d ",*(arr+i));
        i++;
        arr = (int*)realloc(arr, (i + 1) * sizeof(int));
        count++;
    }
    fclose(myfile);
    return arr;
}
