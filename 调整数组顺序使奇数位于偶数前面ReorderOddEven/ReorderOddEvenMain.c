#include <stdio.h>
#include <stdlib.h>

/*
�ļ����ƣ�����ָOffer���������Թپ������ͱ����(�����)��������14����������˳��ʹ����λ��ż��ǰ��
ʱ�䣺2016-8-13 21:53
˵����1����Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֡�
2��Ϊ�˱��ڽ����Reorder���������д���һ������ָ�롣 
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
