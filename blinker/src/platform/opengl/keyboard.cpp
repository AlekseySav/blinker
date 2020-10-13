#include <pch.h>
#include <core.h>
#include "core.h"
#include <renderer/Window.h>
#include <input/keyboard.h>

static Keyboard keyboard;

static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(action == GLFW_PRESS)
		keyboard.keys[key] = true;
	else if(action == GLFW_RELEASE)
		keyboard.keys[key] = false;
}

void Keyboard::Initialize(const Window& window)
{
	glfwSetKeyCallback((GLFWwindow*)window.m_Window, KeyCallback);
}

void Keyboard::OnUpdate()
{
	glfwPollEvents();
}

bool Keyboard::KeyPressed(int key)
{
	return keyboard.keys[key];
}

bool Keyboard::Up() 
{ 
	return KeyPressed(GLFW_KEY_W) || KeyPressed(GLFW_KEY_UP); 
}

bool Keyboard::Down()
{
	return KeyPressed(GLFW_KEY_S) || KeyPressed(GLFW_KEY_DOWN);
}

bool Keyboard::Left()
{
	return KeyPressed(GLFW_KEY_A) || KeyPressed(GLFW_KEY_LEFT);
}

bool Keyboard::Right()
{
	return KeyPressed(GLFW_KEY_D) || KeyPressed(GLFW_KEY_RIGHT);
}
