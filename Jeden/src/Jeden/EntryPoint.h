#pragma once

#ifdef JD_PLATFORM_WINDOWS

extern Jeden::Application* Jeden::CreateApplication();

int main(int argc, char** argv)
{
	Jeden::Log::Init();
	JD_CORE_WARN("Initialized Log!");
	int a = 5;
	JD_INFO("Hello! Var={0}", a);

	auto app = Jeden::CreateApplication();
	app->Run();
	delete app;
}

#endif