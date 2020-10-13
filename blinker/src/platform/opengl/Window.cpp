#include <pch.h>
#include <core.h>
#include "core.h"
#include <renderer/Window.h>

Window::Window(const char* title, uint32_t width, uint32_t height)
{
	m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (!m_Window) LOG_ERROR("Window Init failed\n");
	glfwMakeContextCurrent((GLFWwindow*)m_Window);
}

void Window::SwapBuffers() const
{
	glfwSwapBuffers((GLFWwindow*)m_Window);
}

bool Window::IsClosed() const
{
    return glfwWindowShouldClose((GLFWwindow*)m_Window);
}
