#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define GET_ARRAY_LENGTH(arr,len){len = sizeof(arr)/sizeof(arr[0]);}
/**
	����������
Thinkink:
	�Ե�ǰ���Ԫ��Ϊ��׼���ٶ��Ѿ��ź���
	�����Ԫ���Ǽ���Ҫ��������ݣ���ǰһ����Ƚϡ�
	���С����ǰһ������ǰһ�������ƶ���
	��ǰ��Ԫ���ٴκ�ǰ���ǰ����бȽϡ�
	���ǰ���Ԫ��С���˵�ǰ��Ԫ�أ���ô��������ڴ������Ԫ��
	����ǰ��ĺ�һ��λ��.
	
ʱ�临�Ӷ�:  O(n^2)	 


*/ 
using namespace std;

void showArray(int *arr, int len);
int main(){
	int a[] = {15,25,8,96,32,14,65,12,23,8};
	int len = 0;
	GET_ARRAY_LENGTH(a,len);
	showArray(a,len);
	for(int i = 1;i<len;i++){
		int temp  = a[i]; 		// ��Ϊ a[i] ��ǰ�Ƚϵ�ʱ�򣬺����Ԫ�ؿ��ܻ���ǰ�ƶ�����ˣ��Ḳ��a[i]��λ�á� 
		for(int j = i-1;j>=0;j--){	//�������ѭ��Ӧ���ǿ���д�ɵݹ���õģ������Ż��� 
			if(temp < a[j]){		//ǰ���Ԫ�ش���Ҫ����ƶ� 
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
	showArray(a,len);
	return 0;
} 

void showArray(int *arr, int len){
	for(int i =0;i<len;i++){
		cout << "--" << arr[i] << "--";
	}
	cout << "\n";
}
