#pragma once
#include "GameObject.h"
#include "Text.h"
#include "Vector.h"
class MenuOptions : public GameObject
{
public:
	MenuOptions();
	virtual ~MenuOptions();
	void SetPosition(int x, int y) final;
	void SetText(std::string const& text);
	void SetDimension(const int width, const int height);
	void Update() final {}
	void Render() final;
private:
	Text m_line{};
};