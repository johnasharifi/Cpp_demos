// cpp_demos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "cpp_demos.h"
#include <cmath>

using namespace std;

void TestStringGrid() {
	char* data1[] = { "lrow", "adrg", "nieh", "dmst" };

	StringGrid sg = StringGrid(data1, 4);

	char* str1 = "row";
	char* str2 = "land";
	char* str3 = "grid";
	char* str4 = "lrowgrdaniehtsmd";
	char* str5 = "l";
	
	char* str6 = "kjlkjsdf";
	char* str7 = "dimo";
	char* str8 = "ldte";

	printf("Does grid contain %s? %s\n", str1, (sg.Contains(str1, 3)? "True": "False"));
	printf("Does grid contain %s? %s\n", str2, (sg.Contains(str2, 4)? "True": "False"));
	printf("Does grid contain %s? %s\n", str3, (sg.Contains(str3, 4)? "True": "False"));
	printf("Does grid contain %s? %s\n", str4, (sg.Contains(str4, 17)? "True": "False"));
	printf("Does grid contain %s? %s\n", str5, (sg.Contains(str5, 9) ? "True" : "False"));
	printf("\n");
	printf("Does grid contain %s? %s\n", str6, (sg.Contains(str6, 1) ? "True" : "False"));
	printf("Does grid contain %s? %s\n", str7, (sg.Contains(str7, 4) ? "True" : "False"));
	printf("Does grid contain %s? %s\n", str8, (sg.Contains(str8, 4) ? "True" : "False"));
}

void TestSignalVec() {
	// signal vector operations

	const int cap = 1000;

	double* uniform = new double[cap];
	double* sin_vec = new double[cap];
	double* linear = new double[cap];

	for (int i = 0; i < cap; i++) {
		uniform[i] = 1.0 / cap;
		sin_vec[i] = sin((i - cap / 2) * 3.14 / cap);
		linear[i] = i * 1.0 / cap;
	}

	delete(uniform);
	delete(sin_vec);
	delete(linear);
}

void TestBinaryTree() {
	BinaryTree<int>* bt = new BinaryTree<int>(0);
	for (int i = -1000; i < 1000; i++) {
		bt->Insert(i);
	}

	cout << "Min node is " << bt->GetMin() << endl;
	cout << "Max node is " << bt->GetMax() << endl;

	bt->FreeMem();
	delete(bt);
}

void TestCircle() {
	Circle c = Circle(3.0, 4.5, 2.0);
	std::string str = string(c);

	cout << "circle params are " << str << endl;

	for (int i = 0; i < 5; i++) {
		bool contains = c.Contains(i, 3);
		cout << "circle " << string(c) << (contains ? " contains " : " does not contain ") << i << "," << 3 << endl;
	}

	for (int i = 0; i < 5; i++) {
		Circle c_inst = Circle(i, 3.5, 1);
		bool contains = c.ContainsOrOverlaps(&c_inst);
		cout << "circle " << string(c) << (contains ? " intersects " : " does not intersect ") << string(c_inst) << endl;
	}
}

int main()
{
	TestCircle();
	TestBinaryTree();
	TestSignalVec();
	TestStringGrid();

	int in_value;
	cin >> in_value;
	return in_value;
}