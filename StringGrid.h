#pragma once

class StringGrid
{
public:
	StringGrid(char**, int);
	~StringGrid();
	bool Contains(char*, int);
private:
	int dim;
	const static int alphabet_count = 26;
	// bool** emission;
	bool emission[alphabet_count][alphabet_count];
	bool AToB(char a, char b);
	bool ContainsSingle(char single);
};

