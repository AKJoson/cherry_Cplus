#include <iostream>
#include <string>
#include "test.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv) {
	cout << "hello world" << "\n";
	Test* test = new Test();
	test->setA(59201314);
	cout << test->getA();
	delete test;
	return 0;
}
