#pragma once

#ifdef JD_PLATFORM_WINDOWS

extern Jeden::Application* Jeden::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Jeden::CreateApplication();
	app->Run();
	delete app;
}

#endif