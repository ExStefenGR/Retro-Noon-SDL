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
	
	float GetAngle() const;
	const std::string& GetTag() const;
	const Vector2D& GetSize() const;
	const Vector2D& GetPosition() const;
	void SetTag(const std::string& tag);
	void SetAngle(float angle);
	void SetPosition(int x, int y);
	void SetPosition(const Vector2D& position);
	void SetSize(const Vector2D& size);
	void SetSize(int width, int height);
	virtual void Update(Input& input) = 0;
	virtual void Render(Screen& screen) = 0;
	bool IsAlive() const;
	bool IsVisible() const;
	bool IsActive() const;
	void IsAlive(bool flag);
	void IsVisible(bool flag);
	void IsActive(bool flag);
protected:
	float m_angle;
	std::string m_tag;
	Vector2D m_size;
	Vector2D m_position;
	bool m_isAlive;
	bool m_isActive;
	bool m_isVisible;
};