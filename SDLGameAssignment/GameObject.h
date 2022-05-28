#pragma once
#include <SDL.h>
#include <string>
#include "Vector.h"

class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = default;
	bool IsActive() const;
	bool IsAlive() const;
	bool IsVisible() const;
	const std::string& GetTag() const;
	const Vector<int>& GetPosition() const;
	const Vector<int>& GetSize() const;
	double GetAngle() const;

	virtual void Render() = 0;
	virtual void Update() = 0;

	void IsActive(bool flag);
	void IsAlive(bool flag);
	void IsVisible(bool flag);
	virtual void SetPosition(const Vector<int>& position);
	virtual void SetPosition(int x, int y);
	void SetAngle(double angle);
	void SetSize(const Vector<int>& size);
	void SetSize(int width, int height);
	void SetTag(const std::string_view& tag);
protected:
	bool m_isActive{ false };
	bool m_isAlive{ false };
	bool m_isVisible{ false };
	double m_angle{ 0.0f };
	std::string m_tag{};
	Vector<int> m_position{0,0};
	Vector<int> m_size{0,0};
};