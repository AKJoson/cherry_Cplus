#include <iostream>
#include <stdlib.h>
#define GET_ARRAY_LENGTH(arr,len){len = sizeof(arr)/sizeof(arr[0]);} 
using namespace std;
/**
 	【归并排序】
Thinking：
	递归 ---> 分解
	合并排序 --->治	 
	  
*/ 

void start(int* a,int len,int* resultArr);
void split(int startIndex, int denIndex,int* a,int* resultArr);
void merge(int startIndex,int middle,int endIndex, int* a,int* resultArr);
void log(int* a,int len);
int main(){
	int a[] = {27,67,32,17,22,64,0,124,65,78,42,96,25,1};
	int len = 0;
 	GET_ARRAY_LENGTH(a,len);
	int resultArr[len];
	log(a,len);
	start(a,len,resultArr);
	log(a,len);
	return 0;
}

void start(int* a, int len, int* resultArr){
	split(0, len-1,a,resultArr);
}

void split(int startIndex, int endIndex,int* a,int* resultArr){


	
	// 已经只剩下一个元素或者刚好两个
	if(endIndex == startIndex){  //一开始我这写 的是 endIndex - startIndex <=1  如果等于1  那么 其实数组还有两个值，两个值是需要进行排序的 
//		cout << "startIndex = " << startIndex << "endIndex = " << endIndex << "\n"; 
		return;
	}
	
	//还没有分解到只剩最后两个或者一个接着分解
	int middle = (endIndex + startIndex)/2;     // 一开始我这写的是 (endIndex - startIndex)/2
	
	//左边 
	split(startIndex,middle,a,resultArr); 
	//右边 
	split(middle+1,endIndex,a,resultArr);
	merge(startIndex,middle,endIndex,a,resultArr);
	
}
void merge(int startIndex,int middle, int endIndex,int* a, int* resultArray){
//	cout << "merge" << "---startIndex----"<< startIndex << "---middle--"<< middle << "---endIndex---" << endIndex << "\n"; 
	
		//到这就成了两个数组排序问题了 
		//第一个 是  startIndex 到 middle 
  	 // 第二个是   middle+1  到 endIndex 
    //锁定两个端点 startIndex 另一个是 endIndex
    int arr1StartIndex = startIndex;
    int arr1EndIndex = middle;
    int arr2StartIndex = middle + 1;
    int arr2EndIndex = endIndex;
    
    int startPosition = startIndex;
    
    while(arr1StartIndex <= arr1EndIndex || arr2StartIndex <= arr2EndIndex){
    		//两个数组自己的交换
			 if(arr1StartIndex>arr1EndIndex) { //第一个数组已经，没有值 
			 	resultArray[startPosition++] = a[arr2StartIndex++]; 
			 }else if(arr2StartIndex > arr2EndIndex){
			 	resultArray[startPosition++] = a[arr1StartIndex++];
			 } else{  //两个数组都没有比较完毕 
			 	if(a[arr1StartIndex] < a[arr2StartIndex]){
			 		resultArray[startPosition++] = a[arr1StartIndex++];
				 }else{
				 	resultArray[startPosition++] = a[arr2StartIndex++];
				 }	
			 } 
	}   
	
	    	//操作原数组
		 for(int i = startIndex;i<= endIndex;i++){
		 	a[i] = resultArray[i];
		 } 
		 
}

void log(int* a, int len){
	for(int i = 0;i < len;i++){
		cout << "~~" << a[i] << "~~"; 
	}
	cout << "\n";
}

/**
讲句真心话，这个算法要是没有好好思考，好好写过几次，应该是没那么简单的。
一路走来跌跌撞撞的。 不过没关系！干就是了。 

~~27~~~~67~~~~32~~~~17~~~~22~~~~64~~~~0~~~~124~~~~65~~~~78~~~~42~~~~96~~~~25~~~~1~~
~~0~~~~1~~~~17~~~~22~~~~25~~~~27~~~~32~~~~42~~~~64~~~~65~~~~67~~~~78~~~~96~~~~124~~

*/ 


