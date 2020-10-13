#pragma once

#ifdef _DEBUG
#define LOG_ERROR(x, ...) do { \
	fprintf(stderr, x, __VA_ARGS__); \
	__debugbreak(); } while(0)

#define ASSERT(x) if(!(x)) LOG_ERROR("Assertation Failed\n")
#else
#define LOG_ERROR(x, ...) do { \
	fprintf(stderr, x, __VA_ARGS__); \
	exit(0); } while(0)

#define ASSERT(x) 
#endif

#define LOG_WARNING(x, ...)  do { \
	std::cout << "WARNING: "; \
	printf(x, __VA_ARGS__); } while(0) 

#define LOG(x, ...)	printf(x, __VA_ARGS__)

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
