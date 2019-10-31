#include <iostream>
#include <stdlib.h>
#define GET_ARRAY_LENGTH(arr,len){len = sizeof(arr)/sizeof(arr[0]);} 
using namespace std;
/**
 	���鲢����
Thinking��
	�ݹ� ---> �ֽ�
	�ϲ����� --->��	 
	  
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


	
	// �Ѿ�ֻʣ��һ��Ԫ�ػ��߸պ�����
	if(endIndex == startIndex){  //һ��ʼ����д ���� endIndex - startIndex <=1  �������1  ��ô ��ʵ���黹������ֵ������ֵ����Ҫ��������� 
//		cout << "startIndex = " << startIndex << "endIndex = " << endIndex << "\n"; 
		return;
	}
	
	//��û�зֽ⵽ֻʣ�����������һ�����ŷֽ�
	int middle = (endIndex + startIndex)/2;     // һ��ʼ����д���� (endIndex - startIndex)/2
	
	//��� 
	split(startIndex,middle,a,resultArr); 
	//�ұ� 
	split(middle+1,endIndex,a,resultArr);
	merge(startIndex,middle,endIndex,a,resultArr);
	
}
void merge(int startIndex,int middle, int endIndex,int* a, int* resultArray){
//	cout << "merge" << "---startIndex----"<< startIndex << "---middle--"<< middle << "---endIndex---" << endIndex << "\n"; 
	
		//����ͳ��������������������� 
		//��һ�� ��  startIndex �� middle 
  	 // �ڶ�����   middle+1  �� endIndex 
    //���������˵� startIndex ��һ���� endIndex
    int arr1StartIndex = startIndex;
    int arr1EndIndex = middle;
    int arr2StartIndex = middle + 1;
    int arr2EndIndex = endIndex;
    
    int startPosition = startIndex;
    
    while(arr1StartIndex <= arr1EndIndex || arr2StartIndex <= arr2EndIndex){
    		//���������Լ��Ľ���
			 if(arr1StartIndex>arr1EndIndex) { //��һ�������Ѿ���û��ֵ 
			 	resultArray[startPosition++] = a[arr2StartIndex++]; 
			 }else if(arr2StartIndex > arr2EndIndex){
			 	resultArray[startPosition++] = a[arr1StartIndex++];
			 } else{  //�������鶼û�бȽ���� 
			 	if(a[arr1StartIndex] < a[arr2StartIndex]){
			 		resultArray[startPosition++] = a[arr1StartIndex++];
				 }else{
				 	resultArray[startPosition++] = a[arr2StartIndex++];
				 }	
			 } 
	}   
	
	    	//����ԭ����
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
�������Ļ�������㷨Ҫ��û�кú�˼�����ú�д�����Σ�Ӧ����û��ô�򵥵ġ�
һ·��������ײײ�ġ� ����û��ϵ���ɾ����ˡ� 

~~27~~~~67~~~~32~~~~17~~~~22~~~~64~~~~0~~~~124~~~~65~~~~78~~~~42~~~~96~~~~25~~~~1~~
~~0~~~~1~~~~17~~~~22~~~~25~~~~27~~~~32~~~~42~~~~64~~~~65~~~~67~~~~78~~~~96~~~~124~~

*/ 


