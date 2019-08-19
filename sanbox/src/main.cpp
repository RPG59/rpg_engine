#include <time.h>

namespace graphics {
	__declspec(dllimport) void Print();
}

int main()
{
	graphics::Print();

	return 0;
}

