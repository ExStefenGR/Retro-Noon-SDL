#pragma once
#include "GameObject.h"
#include "Text.h"
class MenuOptions final : public GameObject
{
public:
	MenuOptions();
	virtual ~MenuOptions();
	void SetPosition(int x, int y) override;
	void SetText(std::string const &text);
	auto SetDimension(int width, int height) -> void;
	void Update() override {}
	void Render() override;

private:
	Text m_line{};
};