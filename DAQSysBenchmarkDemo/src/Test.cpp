#include "DAQSysBenchmarkCore.h"
#include <algorithm>
#include <execution>
#include <numeric>

int main()
{

	{
		nmros::ScopedTimer timer("reduce");
		std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		auto ret = std::reduce(std::execution::par, vec.begin(), vec.end(), 0.0, std::plus());
	}

	return 0;

}
