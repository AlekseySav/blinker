#pragma once

class Window
{
public:
	Window(const char* title, uint32_t width, uint32_t height);
	void SwapBuffers() const;
	bool IsClosed() const;
private:
	const void* m_Window;
	friend class Keyboard;
};
