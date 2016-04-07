#ifndef KEYBOARD_HPP
# define KEYBOARD_HPP

# include <map>
# include "Windows.hpp"

class Keyboard
{
public:
	static void callback(GLFWwindow * window, int key, int scancode, int action, int mods);
	static bool isKeyPressed(int key);
	static bool isKeyPress(int key);
	static bool isKeyReleased(int key);

private:
	Keyboard(void);
	virtual ~Keyboard(void);

	Keyboard(Keyboard const & keyboard);
	Keyboard & operator=(Keyboard const & keyboard);

	static std::map<int, int>	m_keys;

};

#endif
