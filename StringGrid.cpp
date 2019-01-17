#include "stdafx.h"
#include "StringGrid.h"

StringGrid::StringGrid(char** data, int _dim)
{
	dim = _dim;

	for (int i = 0; i < alphabet_count; i++)
		for (int j = 0; j < alphabet_count; j++)
			emission[i][j] = false;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			int ind1 = (int)(toupper(data[i][j]) - (int) 'A');

			for (int local_i = i - 1; local_i < i + 2; local_i++) {
				for (int local_j = j - 1; local_j < j + 2; local_j++) {
					if (local_i < 0 || local_j < 0 || local_i >= dim || local_j >= dim || (local_i == i && local_j == j))
						continue;

					int ind2 = (int)(toupper(data[local_i][local_j]) - (int) 'A');

					emission[ind1][ind2] = true;
				}
			}
			

		}
	}

	printf("Grid: ---\n");
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("%c ", data[i][j]);
		}
		printf("\n");
	}

	/*
	for (int i = 0; i < alphabet_count; i++) {
		for (int j = 0; j < alphabet_count; j++) {
			printf("%s", emission[i][j]? "T ":". ");
		}
		printf(" row %i\n", i);
	}
	*/

}

StringGrid::~StringGrid()
{
}

bool StringGrid::Contains(char* str, int str_len)
{
	if (str_len == 1)
		return(ContainsSingle(str[0]));

	for (int i = 1; i < str_len; i++) {
		bool query = AToB(str[i - 1], str[i - 0]);
		if (!query) return(false);
	}

	return(true);
	
}

bool StringGrid::AToB(char a, char b) {
	int ind1 = toupper(a) - 'A';
	int ind2 = toupper(b) - 'A';
	return(emission[ind1][ind2]);
}

bool StringGrid::ContainsSingle(char single) {
	int ind1 = toupper(single) - 'A';
	for (int i = 0; i < alphabet_count; i++)
		if (emission[ind1][i] == true)
			return(true);
	return(false);
}