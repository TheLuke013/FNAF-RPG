#include "Core/Core.h"
#include "Core/GameApplication.h"

#ifdef _WIN32

extern Engine::GameApplication* Engine::CreateApplication();

int main(int, char**)
{
	Engine::Log::Init();
	LOG_INFO("Engine initialized");

	auto app = Engine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif