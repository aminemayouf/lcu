#pragma once


#ifdef __ANDROID__

#elif __APPLE__ && __MACH__

#elif __linux__
#include <X11/Xlib.h>
#elif _WIN32
#include <Windows.h>
#endif


namespace LCU {
	inline namespace System {
		/**
		 * Display Class
		 *
		 * @project System
		 * @author Amine MAYOUF
		*/
		class Display {
		public:
			struct Resolution {
				size_t horizontal;
				size_t vertical;
			};
			/*
			 *	Methods
			 */
			Display() = delete;
			~Display() = delete;

			static Resolution DesktopResolution();
		};
	}
}
