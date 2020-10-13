#include <pch.h>
#include <core.h>
#include "core.h"
#include "util.h"

static void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	LOG_ERROR("GL: %s\n", message);
}

void LogInitialize()
{
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);
}

void Terminate()
{
	glfwTerminate();
}
