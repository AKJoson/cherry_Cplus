#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//��Ȼ����һ����Ȥ�ĺ� 
#define GET_ARRAY_LEN(arr, len){len = sizeof(arr)/sizeof(arr[0]);} 

using namespace std;

/**
	��ð������
Thinking:
	��ǰλ�õ�ֵ�ͺ�һ�����бȽϣ� 
	Ȼ����н�������ǰ�������н������������������ߡ�
	������������ڽ�ֵ�������Ƚϣ�Ҳ����������� 
ʱ�临�Ӷȣ�	
	N*(N-1)/2   ==>  O (n^2)
	 
*/

void log_array(int *array,int len);
int main(){
	int a[]  = {58,12,64,7,98,75,32,16};
	int len = 0;
	GET_ARRAY_LEN(a,len);
	log_array(a,len);
//	for(int i = 0;i<len;i++){  			Error code.  the i is use to limit range. each time can get the Max/Min value and the position is in the end, not First , so this is mistake.
//		for(int j = 0;j<len-i;j++){                   
//			if(a[j]>a[j+1]){
//				a[j] = a[j]+a[j+1];
//				a[j+1]  = a[j] - a[j+1];
//				a[j] = a[j] - a[j+1];
//			}
//		}
//	}
	for(int i = len-1; i >= 0;i--){  // invoke once mean you have gey one Max/Min value.
		for(int j = 0;j < i; j++){
			if(a[j]>a[j+1]){
				a[j] = a[j] + a[j+1];
				a[j+1] = a[j] - a[j+1];
				a[j] = a[j] - a[j+1];
			}
		}
	}
	log_array(a,len);
	return 0;
} 

void log_array(int *array, int len){
	for(int i = 0; i<len; i++){
		cout << array[i] << "--";
	}
	cout << "\n";
}
