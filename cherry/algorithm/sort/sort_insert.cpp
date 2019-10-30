#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define GET_ARRAY_LENGTH(arr,len){len = sizeof(arr)/sizeof(arr[0]);}
/**
	【插入排序】
Thinkink:
	以第前面的元素为基准，假定已经排好序。
	后面的元素是即将要插入的数据，和前一个相比较。
	如果小于了前一个，将前一个往后移动。
	当前的元素再次和前面的前面进行比较。
	如果前面的元素小于了当前的元素，那么将这个用于待排序的元素
	插入前面的后一个位置.
	
时间复杂度:  O(n^2)	 


*/ 
using namespace std;

void showArray(int *arr, int len);
int main(){
	int a[] = {15,25,8,96,32,14,65,12,23,8};
	int len = 0;
	GET_ARRAY_LENGTH(a,len);
	showArray(a,len);
	for(int i = 1;i<len;i++){
		int temp  = a[i]; 		// 因为 a[i] 向前比较的时候，后面的元素可能会向前移动，因此，会覆盖a[i]的位置。 
		for(int j = i-1;j>=0;j--){	//这个内曾循环应该是可以写成递归调用的，后续优化， 
			if(temp < a[j]){		//前面的元素大，需要向后移动 
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
