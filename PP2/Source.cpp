#include "C:\Users\danie\Programacion\boost\boost_1_71_0\boost\lambda\lambda.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace boost::lambda;
using namespace std;

int main()
{
	using namespace boost::lambda;
	typedef std::istream_iterator<int> in;

	std::for_each(
		in(std::cin), in(), std::cout << (_1 * 3) << " ");
}