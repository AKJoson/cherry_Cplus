#include <stdio.h>
#include <iostream>

void swap(int* a,int* b);

int main(){
	int value[] = {1,2,3};
	//�������ַ�ʽ��Ч 
	int* a = &(value[0]);
//	int* a = value; 
	
	std::cout << "hi sam!" << value[1] <<a[0] << "\n"; 
	
	//����������ֵ
	int c = 10;
	int d = 20;
	std::cout<< " 1 the memory address:" << &c << "--"<< &d << "\n"; 
	std::cout<< "origin value: "<< c <<"--"<<d << "\n"; 
	swap(&c,&d);
	std::cout<< "origin value: "<< c <<"--"<<d << "\n"; 
	std::cout<< " 4 the memory address:" << &c << "--"<< &d << "\n"; 
	return 0;
} 

void swap(int* a, int* b){
	
	std::cout<< " 2 the memory address:" << a << "--"<< b << "\n"; 
	
//�ı� ָ�� ��ָ�ı���  ����>> ����ָ����ָ���ֵ �� ��11�� 
	int temp = *a;
	*a = *b;
	*b = temp;
	
	
//�����⼸�д������뽻��ָ���ֵַ��ָ��Ҳ�����ã���Ч��������Ϊ�����������ʵ���˽��������ǲ�û��������ʵ�ֽ���  ��2�� 
//	int* temp = a;
//	a = b;
//	b = temp;   
	
	
	std:: cout << *a << *b << "\n"; //���  20   10 
	std::cout<< " 3 the memory address:" << a << "--"<< b << "\n"; 
}

	/** ��11��   Notice: ָ��ĵ�ַ��û�н���������ָ���ֵȴʵ���������Ľ��� 
	hi sam!21
	 1 the memory address:0x6ffdec--0x6ffde8
	origin value: 10--20
	 2 the memory address:0x6ffdec--0x6ffde8
	2010
	 3 the memory address:0x6ffdec--0x6ffde8
	origin value: 20--10
	 4 the memory address:0x6ffdec--0x6ffde8
	*/ 

	/** ��2��    Notice: ָ��ĵ�ַ�����ˣ�����ָ����ָ���ֵȴûӰ�졣 
	hi sam!21
	 1 the memory address:0x6ffdec--0x6ffde8
	origin value: 10--20
	 2 the memory address:0x6ffdec--0x6ffde8
	2010
	 3 the memory address:0x6ffde8--0x6ffdec
	origin value: 10--20
	 4 the memory address:0x6ffdec--0x6ffde8
		*/
