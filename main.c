#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
int functionSumElementArray (int *arr,int count);
int main()
{
    FILE * myfile ;
    myfile=fopen("textstring.txt","w");

    char *teststring="10 20 13 40 50 70 80 90 100";
    fprintf(myfile,"%s",teststring);
    fclose(myfile);
    // add dynamic memory for 0 element
    int *arr=(int*)malloc(sizeof(int));

    myfile=fopen("textstring.txt","r");
    int i=0;
    int count=0;
    //1)scan from the file to array
    while(fscanf(myfile, "%d", &arr[i])!=EOF){
        printf("%d ",*(arr+i));
        i++;
        // add dynamic memory for i+1 element
        arr = (int*)realloc(arr, (i + 1) * sizeof(int));

        count++;
    }

    fclose(myfile);
    //2 Finding the sum of the elements
    int sum;
    sum=functionSumElementArray(arr,count);
    //3 record sum to file
    myfile=fopen("textstring.txt","a+");
    fprintf(myfile,"\nSum=%d\r",sum);
    fclose(myfile);

    return 0;
}
int functionSumElementArray (int *arr,int count){
    int i=0;
    int sumelement=0;
    while (i<count) {
        sumelement+=*(arr+i);
        i++;
    }
    return sumelement;
}
