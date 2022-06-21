#include "Ui.h"

namespace FuryEngine {

	Ref<Panel> UiManager::s_ActivePanel = nullptr;

	void UiManager::Init() {

	}

	void UiManager::Update() {
		if (!s_ActivePanel)
			return;
		s_ActivePanel->Update();
	}

	void Panel::Update() {
		//Update
		for (auto child : children) {
			child->Update();
		}
	}

	void Panel::Render() {
		//render
		for (auto child : children) {
			child->Render();
		}
	}

}