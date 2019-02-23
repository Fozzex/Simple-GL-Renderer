#pragma once
#include <GL/glew.h>
#include <iostream>

#if defined(RENDERER_DEBUG)
#	define ASSERT(x, str) { if (!(x)) { std::cout << "ASSERTION FAILED: " << str << std::endl; __debugbreak(); } }
#	define VERIFY(x, str) { if (!(x)) { std::cout << "ASSERTION FAILED: " << str << std::endl; __debugbreak(); } }
#	define GLCall(fn_call) while (glGetError() != GL_NO_ERROR);\
						   fn_call;\
						   { GLenum error;\
						   ASSERT((error = glGetError()) == GL_NO_ERROR, "OpenGL Error: [" << error << "]\nFILE: " << __FILE__ << "\nLINE: " << __LINE__) }
#else
#	define ASSERT(x, str)
#	define VERIFY(x, str) (x)
#	define GLCall(fn_call) (fn_call)
#endif


#define BIND_EVENT_CALLBACK(fn) std::bind(&fn, this, std::placeholders::_1)