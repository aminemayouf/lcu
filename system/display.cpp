#include "display.h"


namespace lcu
{
	inline namespace system
	{
		// @return the horizontal and vertical screen sizes in pixels
		Display::Resolution Display::DesktopResolution()
		{
			Resolution desktopResolution;
#if defined(__linux__)
			Display* pDisplay = XOpenDisplay(NULL);
			Screen* pScreen = DefaultScreenOfDisplay(pDisplay);
			desktopResolution.horizontal = pScreen->width;
			desktopResolution.vertical = pScreen->height;
#elif defined(_WIN32) || defined(_WIN64)
			RECT desktop;
			// Get a handle to the desktop window
			const HWND hDesktop = GetDesktopWindow();
			// Get the size of screen to the variable desktop
			GetWindowRect(hDesktop, &desktop);
			// The top left corner will have coordinates (0,0)
			// and the bottom right corner will have coordinates
			// (horizontal, vertical)
			desktopResolution.horizontal = desktop.right;
			desktopResolution.vertical = desktop.bottom;
#endif
			return desktopResolution;
		}
	}
}
