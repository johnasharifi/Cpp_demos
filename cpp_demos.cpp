// cpp_demos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "cpp_demos.h"
#include <cmath>

using namespace std;

int main()
{
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

	BinaryTree<int>* bt = new BinaryTree<int>(0);
	for (int i = -1000; i < 1000; i++) {
		bt->Insert(i);
	}

	cout << "Min node is " << bt->GetMin() << endl;
	cout << "Max node is " << bt->GetMax() << endl;

	bt->FreeMem();
	delete(bt);

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

	int in_value;
	cin >> in_value;
	return in_value;
}