#include <iostream>
#include <stdlib.h>
#define GET_LENGTH(arr, len){len = sizeof(arr)/sizeof(arr[0]);} 
using namespace std;

/**
【快速排序】 

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
		return; //碰撞 
	} 
	
	 //找出基准值 默认为第一个 
	int temp = a[leftIndex];
	int i = leftIndex;
	int j = rightIndex;
	while(i!=j){
		//从右向左找 小于基准值的元素 : 右边只留下 大于基准的 
		while(a[j] >= temp && i<j){
			j--;
		} 
		// 从左向右开始找 找大于基准值的 ：左边只留下 小于基准的 
		while(a[i] <= temp && i<j){
			i++;
		} 
		//交换两个数在数组中的位置       ： 左边已经找到大于基准的，右边也已经找到小于基准的，因此交换两个值 
		if(i<j){
			a[i] = a[i]+a[j];
			a[j] = a[i]-a[j];
			a[i] = a[i]-a[j];
		} 
		 
	} 
	
	//发生碰撞，碰撞的位置就是 左边小于基准，右边大于基准 ,所以需要将基准放在中间 
	
	a[leftIndex] = a[i];
	a[i] = temp;
	
	
	//处理左边的
	quickSort(a,leftIndex,i-1);  //i 的位置代表着 已经排好，不需要动他 
	//处理右边的
	quickSort(a,i+1,rightIndex); 
}

void log(int* a,int len){
	int index = 0;
	while(index < len){
		cout << "--" << a[index++]<<"--";
	}
	cout << "\n";
} 
