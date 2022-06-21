#pragma once

#ifdef FURY_PLATFORM_WINDOWS

extern FuryEngine::Application* FuryEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = FuryEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif