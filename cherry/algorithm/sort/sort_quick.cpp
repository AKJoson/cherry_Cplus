#include <iostream>
#include <stdlib.h>
#define GET_LENGTH(arr, len){len = sizeof(arr)/sizeof(arr[0]);} 
using namespace std;

/**
���������� 

*/

void quickSort(int* a,int leftIndex,int rightIndex);
void log(int* a, int len);

int main(){
	int a[] = {15,25,154,21,7};
	
	int len = 0;
	GET_LENGTH(a,len); 
	log(a,len);
	quickSort(a,0,len-1); 
	log(a,len);
	return 0;
} 


void quickSort(int* a, int leftIndex,int rightIndex){
	if(leftIndex > rightIndex){
		return; //��ײ 
	} 
	
	 //�ҳ���׼ֵ Ĭ��Ϊ��һ�� 
	int temp = a[leftIndex];
	int i = leftIndex;
	int j = rightIndex;
	while(i!=j){
		//���������� С�ڻ�׼ֵ��Ԫ�� : �ұ�ֻ���� ���ڻ�׼�� 
		while(a[j] >= temp && i<j){
			j--;
		} 
		// �������ҿ�ʼ�� �Ҵ��ڻ�׼ֵ�� �����ֻ���� С�ڻ�׼�� 
		while(a[i] <= temp && i<j){
			i++;
		} 
		//�����������������е�λ��       �� ����Ѿ��ҵ����ڻ�׼�ģ��ұ�Ҳ�Ѿ��ҵ�С�ڻ�׼�ģ���˽�������ֵ 
		if(i<j){
			a[i] = a[i]+a[j];
			a[j] = a[i]-a[j];
			a[i] = a[i]-a[j];
		} 
		 
	} 
	
	//������ײ����ײ��λ�þ��� ���С�ڻ�׼���ұߴ��ڻ�׼ ,������Ҫ����׼�����м� 
	
	a[leftIndex] = a[i];
	a[i] = temp;
	
	
	//������ߵ�
	quickSort(a,leftIndex,i-1);  //i ��λ�ô����� �Ѿ��źã�����Ҫ���� 
	//�����ұߵ�
	quickSort(a,i+1,rightIndex); 
}

void log(int* a,int len){
	int index = 0;
	while(index < len){
		cout << "--" << a[index++]<<"--";
	}
	cout << "\n";
} 
