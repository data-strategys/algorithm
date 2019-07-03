#include <stdio.h>


#define swap(a,b)\ 
	do{\
		a=a-b;\
		b=a+b;\
		a=a+b;\
}while(0);
	
#define swapInt(a,b)\ 
	do{\
		a=a^b;\
		b=a^b;\
		a=a^b;\
}while(0);
	
#define swapNoZero(a,b)\ 
	do{\
		a=a*b;\
		b=a/b;\
		a=a/b;\
}while(0);


//多用索引，操作索引
//index space
//O(N^2)
void selectionSort(int *arr,int n)
{
	if (arr==NULL || n<=0) return ;

    int i;
	int layMinIndex = 0;
	int j;
	for (i=0;i<n;i++){ //selector as mini value
		layMinIndex = i;

		for (j=i+1;j<n;j++){ //after compare before select as-so minivalue
				if (arr[j]>=arr[layMinIndex])
				{
					swap(arr[j],arr[layMinIndex]);
				}
			}		
	}

}


void selectionSort2(int * arr, int n)
{
	if (arr==NULL || n==0) return ;
	int i,j;
	for (i=0;i<n;i++){
		int layMiniIndex = i;

		for (j=i;j<n;j++){
			 if (arr[j]>arr[layMiniIndex]){
				 swapInt(arr[j], arr[layMiniIndex]);
			 }
		}

		}

}


#define selectionSortTmpl(arr,n)\
	do{\
    if (arr!=NULL && n>0){ \
	int i,j;\
	for (i=0;i<n;i++){\
		int layMiniIndex = i;\
		for (j=i;j<n;j++){\
			 if (arr[j]>arr[layMiniIndex]){\
				 swap(arr[j], arr[layMiniIndex]);\
			 }\
		}\
		}\
    	}\
	}while(0);


int main(int argc,const char *argvs[]){

	int arr[]={1,2,5,8,18,2,1,9,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSortTmpl(arr,n);

	int i;
	for (i=0;i<n;i++)
	{
		printf("%d ",i);

	}

	printf("\n complete!");


	return 0;
}













