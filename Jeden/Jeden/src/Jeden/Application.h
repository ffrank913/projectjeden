#pragma once

#include "Core.h"

namespace Jeden {

	class JEDEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// to be defined in client
	Application* CreateApplication();
}
