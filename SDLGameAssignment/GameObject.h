#pragma once

#include <SDL.h>
#include <string>
#include "Screen.h"
#include "Input.h"
#include "Vector2D.h"

//Abstract base class - any class with at least 1 pure virtual function

class GameObject
{	
public:
	GameObject();
	
	bool IsActive() const;
	bool IsAlive() const;
	bool IsVisible() const;
	
	const std::string& GetTag() const;
	const Vector2D& GetPosition() const;
	const Vector2D& GetSize() const;
	
	float GetAngle() const;
	
	virtual void Render(Screen& screen) = 0;
	virtual void Update(Input& input) = 0;
	
	void IsActive(bool flag);
	void IsAlive(bool flag);
	void IsVisible(bool flag);
	
	void SetPosition(const Vector2D& position);
	void SetPosition(int x, int y);
	void SetAngle(float angle);
	void SetSize(const Vector2D& size);
	void SetSize(int width, int height);
	void SetTag(const std::string& tag);
protected:
	bool m_isActive = false;
	bool m_isAlive = false;
	bool m_isVisible = false;
	float m_angle = 0.0f;
	std::string m_tag = {};
	Vector2D m_position = {0,0};
	Vector2D m_size = {0,0};
};