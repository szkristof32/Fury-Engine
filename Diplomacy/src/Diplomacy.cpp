#include <FuryEngine.h>

class Diplomacy : public FuryEngine::Application {
public:
	Diplomacy() {
	}

	~Diplomacy() {
	}

};

FuryEngine::Application* FuryEngine::CreateApplication() {
	return new Diplomacy();
}