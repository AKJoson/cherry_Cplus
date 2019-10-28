#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//仍然定义一个有趣的宏 
#define GET_ARRAY_LEN(arr, len){len = sizeof(arr)/sizeof(arr[0]);} 

using namespace std;

/**
	【冒泡排序】
Thinking:
	当前位置的值和后一个进行比较， 
	然后进行交换，当前两个进行交换，这样依次往后走。
	最终完成所以邻近值得两两比较，也就完成了排序。 
时间复杂度：	
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
