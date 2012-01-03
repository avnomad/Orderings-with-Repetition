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

	do
	{
		cout << std::left << setw(5) << ++c << ": ";
		for(int c = length(arrays)-1 ; c >= 0  ; --c)
			cout << arrays[c][indices[c]] << ' ';
		cout << '\n';
		
		i = 0;
		indices[0]++;
		while(indices[i] >= lengths[i])
		{
			indices[i++] = 0;
			if(i >= length(arrays)) break;
			indices[i]++;
		} // end while
	}
	while(i < length(arrays));

	system("PAUSE");
	return 0;
} // end function main
