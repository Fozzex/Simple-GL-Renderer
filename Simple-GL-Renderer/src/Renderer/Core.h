#pragma once
#include <iostream>

#if defined(GL_DEBUG)
#	define ASSERT(x, str) { if (!(x)) { std::cout << "ASSERTION FAILED: " << str << std::endl; __debugbreak(); } }
#	define VERIFY(x, str) { if (!(x)) { std::cout << "ASSERTION FAILED: " << str << std::endl; __debugbreak(); } }
#else
#	define ASSERT(x, str)
#	define VERIFY(x, str) (x)
#endif