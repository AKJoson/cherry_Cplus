#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//����һ����Ȥ�ĺ� 
#define GET_ARRAY_LENGTH(arrName,len){len = sizeof(arrName)/sizeof(arrName[0]);}
/**
 ## ѡ������ ##
Thinking: 
	�Ե�ǰ��ֵΪ��׼�������Ƿ��д�(С)�ڵ�ǰֵ�ģ�
	�оͽ��н�������֤����ѭ��һ�����ҳ�һ�����(С)��ֵ�� 
�¼����Ӷȣ�
	���ѭ������ִ��n�� �ڲ�ѭ��ִ�� n-1��
	����ʱ�临�Ӷ�Ϊ  O(n^2) 	
*/

void log_array(int *array,int length);
int main(){
	int sortValue[] = {21,8,16,97,24,17,8,34}; 
	int length = 0;
	GET_ARRAY_LENGTH(sortValue,length);
	log_array(sortValue,length);
	for(int i = 0;i< length;i++){
		for(int j = i+1;j<length;j++){
			if(sortValue[i] > sortValue[j]){
				//swap
				sortValue[i] = sortValue[i] + sortValue[j];
				sortValue[j] = sortValue[i] - sortValue[j];
				sortValue[i] = sortValue[i] - sortValue[j];
			} 
		}
	}
	log_array(sortValue,length);
	return 0;
} 


void log_array(int *array, int length){
	for(int i = 0;i < length; i++){
		std::cout << array[i] << "--"; 
	}
	std::cout<< "\n";
}
