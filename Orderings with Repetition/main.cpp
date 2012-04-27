//	Copyright (C) 2010, 2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
/*
 *	This file is part of Orderings with Repetition.
 *
 *	Orderings with Repetition is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Orderings with Repetition is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Orderings with Repetition.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include <iomanip>
using std::setw;

#include <cstdlib>
using std::system;

#define length(A) (sizeof(A)/sizeof(A[0]))

static char array1[] = {'0','1'};
static char array2[] = {'[',']'};
static char array3[] = {'a','b','c'};
static char array4[] = {'#','@','$'};
static char array5[] = {'&','^','*'};

static char *arrays[] = {array1,array2,array3,array4,array5};
static int lengths[length(arrays)] = {length(array1),length(array2),length(array3),length(array4),length(array5)};


int main()
{
	int indices[length(arrays)];
	int i;
	int c = 0;

	for(int c = 0 ; c < length(indices) ; ++c)	// initialize indices
		indices[c] = 0;

	for(;;)
	{
		cout << std::left << setw(5) << ++c << ": ";
		for(int c = length(arrays)-1 ; c >= 0  ; --c)
			cout << arrays[c][indices[c]] << ' ';
		cout << '\n';
		
		i = 0;
		goto increment;
		do
		{
			indices[i++] = 0;
			if(i >= length(arrays)) goto end;
increment:
			indices[i]++;
		}
		while(indices[i] >= lengths[i]);
	} // end for
end:

	system("PAUSE");
	return 0;
} // end function main
