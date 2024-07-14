#pragma once

typedef void (*KeyCallback)(int key, int scancode, int action, int mods);
typedef void (*MouseCallback)(double xpos, double ypos);
typedef void (*ScrollCallback)(double xoffset, double yoffset);

struct WindowData {
	bool vsync;
	bool disableCursor;
	KeyCallback keyCallback;
	MouseCallback mouseCallback;
	ScrollCallback scrollCalback;
};