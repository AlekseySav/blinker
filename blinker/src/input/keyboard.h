#pragma once

class Keyboard
{
public:
	static void Initialize(const Window& window);
	static void OnUpdate();

	static bool KeyPressed(int key);
	static bool Up();
	static bool Down();
	static bool Left();
	static bool Right();

	bool keys[512];
};
