#include <Jeden.h>

class Sandbox : public Jeden::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Jeden::Application* Jeden::CreateApplication()
{
	return new Sandbox();
}