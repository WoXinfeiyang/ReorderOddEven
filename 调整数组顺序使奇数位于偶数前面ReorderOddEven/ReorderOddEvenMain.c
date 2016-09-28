#include <stdio.h>
#include <stdlib.h>

/*
文件名称：《剑指Offer：名企面试官精讲典型编程题(纪念版)》面试题14：调整数组顺序使奇数位于偶数前面
时间：2016-8-13 21:53
说明：1、题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
奇数位于数组的前半部分，所有的偶数位于数组的后半部分。
2、为了便于解耦，在Reorder函数参数中传入一个函数指针。 
*/


void Reorder(int *array,int length,int (*fun)(int))
{
	if(array==NULL||length==0){
		return;
	}
	
	int *start=array;
	int *end;
	while(start<end){
		while((start<end)&&(!fun(*start))){
			start++;
		}
		en=start+1;
		while((start<end)&&(fun(*end))){
			end++;
		}
		if(start<end){
			int temp=*start;
			*start=*end;
			*end=temp;
		}
	}
}

int isEven(int n)
{
	return (n&0x01)==0;
}

void ReorderOddEven(int *array,int length)
{
	Reorder(array,length,isEven);
}


int main(int argc, char *argv[]) {
	
	int i=0;
	int n=0;
	while(scanf("%d",&n)){
		int *array=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++){
			scanf("%d",&(array[i]));
		}
		ReorderOddEven(array,n);
		for(i=0;i<n;i++){
			printf("%d ",array[i]);
		}
		printf("\n");
		free(array);
	}
	
	return 0;
}
