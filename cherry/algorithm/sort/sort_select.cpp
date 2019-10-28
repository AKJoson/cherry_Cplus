#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//定义一个有趣的宏 
#define GET_ARRAY_LENGTH(arrName,len){len = sizeof(arrName)/sizeof(arrName[0]);}
/**
 ## 选择排序 ##
Thinking: 
	以当前的值为基准，后面是否有大(小)于当前值的，
	有就进行交换。保证本次循环一定能找出一个最大(小)的值。 
事件复杂度：
	外层循环将会执行n次 内层循环执行 n-1次
	所以时间复杂度为  O(n^2) 	
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
