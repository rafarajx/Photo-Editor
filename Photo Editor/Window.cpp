
#include "Window.h"

#define CB(x) if (w-> ## x ## CB != nullptr) w-> ## x ## CB(hwnd)

__int64 __stdcall WndProc(HWND hwnd, unsigned __int32 msg, unsigned __int64 wParam, __int64 lParam) {
	Window* w = Window::handles[hwnd];
	if (w == nullptr) return DefWindowProc(hwnd, msg, wParam, lParam);
	
	switch (msg) {
	case WM_INITDIALOG:
		std::cout << "WM_INITDIALOG" << std::endl;
		break;
	case WM_CREATE:
		std::cout << "WM_CREATE" << std::endl;
		CB(Create);
		break;
	case WM_COMMAND:
		CB(Command);
		break;
	case WM_PAINT:
		CB(Paint);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

std::map<HWND, Window*> Window::handles;

Window::Window(int width, int height) : width(width), height(height) { }

void Window::create() {

	WNDCLASS wc = { };
	wc.lpfnWndProc = WndProc;
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = "classname";

	if (!RegisterClass(&wc)) {
		MessageBox(NULL, "Failed to register class", "Error", MB_ICONERROR);
		exit(0);
	}

	RECT drect;
	HWND dhwnd = GetDesktopWindow();
	GetWindowRect(dhwnd, &drect);

	hwnd = CreateWindow(
		wc.lpszClassName,
		"Photo Editor by Rafal Rajtar",
		WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		(drect.right - width) / 2, (drect.bottom - height) / 2, width, height,
		NULL, NULL, NULL, NULL
	);

	if (hwnd == NULL) {
		MessageBox(NULL, "Failed to create a window", "Error", MB_ICONERROR);
		exit(0);
	}

	ShowWindow(hwnd, 1);

	HDC hdc = GetDC(hwnd);
	
	handles[hwnd] = this;

	for (int i = 0; i < controls.size(); i++) {
		Control *c = controls[i];
		c->create(hwnd);
	}
}

void Window::update() {
	while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE) > 0) {
		if (message.message == WM_QUIT) exit(0);
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
}

void Window::add(Button *button) {
	controls.push_back(button);
}