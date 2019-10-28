#include <stdio.h>
#include <iostream>

void swap(int* a,int* b);

int main(){
	int value[] = {1,2,3};
	//下面两种方式等效 
	int* a = &(value[0]);
//	int* a = value; 
	
	std::cout << "hi sam!" << value[1] <<a[0] << "\n"; 
	
	//交换两个数值
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
	
//改变 指针 所指的变量  ——>> 交换指针所指向的值 ， 【11】 
	int temp = *a;
	*a = *b;
	*b = temp;
	
	
//下面这几行代码是想交换指针地址值，指针也是引用，无效。作用域为这个方法当中实现了交换，但是并没有真正的实现交换  【2】 
//	int* temp = a;
//	a = b;
//	b = temp;   
	
	
	std:: cout << *a << *b << "\n"; //输出  20   10 
	std::cout<< " 3 the memory address:" << a << "--"<< b << "\n"; 
}

	/** 【11】   Notice: 指针的地址斌没有交换，但是指向的值却实现了真正的交换 
	hi sam!21
	 1 the memory address:0x6ffdec--0x6ffde8
	origin value: 10--20
	 2 the memory address:0x6ffdec--0x6ffde8
	2010
	 3 the memory address:0x6ffdec--0x6ffde8
	origin value: 20--10
	 4 the memory address:0x6ffdec--0x6ffde8
	*/ 

	/** 【2】    Notice: 指针的地址交换了，但是指针所指向的值却没影响。 
	hi sam!21
	 1 the memory address:0x6ffdec--0x6ffde8
	origin value: 10--20
	 2 the memory address:0x6ffdec--0x6ffde8
	2010
	 3 the memory address:0x6ffde8--0x6ffdec
	origin value: 10--20
	 4 the memory address:0x6ffdec--0x6ffde8
		*/
