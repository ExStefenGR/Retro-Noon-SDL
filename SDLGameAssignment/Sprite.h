#pragma once
#include <string>
#include <SDL_image.h>
#include "Screen.h"

class Sprite
{
	enum class Flip
	{
		No_Flip = SDL_FLIP_NONE,
		Horz_Flip = SDL_FLIP_HORIZONTAL,
		Vert_Flip = SDL_FLIP_VERTICAL
	};
public:
	Sprite() = default;
	~Sprite() = default;
	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);
	void SetImageCel(int column, int row);
	void SetAnimationVelocity(float velocity);
	void SetSpriteDimension(int width, int height); //on screen
	void SetImageDimension(int columns, int rows, int width, int height); //in folder
	bool Load(const std::string& filename);
	void Unload() const;
	void Update();
	void Render(int xPos, int yPos, double angle);
private:
	bool m_isAnimated{false};
	bool m_isAnimationLooping{false};
	bool m_isAnimationDead{false};
	Flip m_flip{Flip::No_Flip};
	SDL_Texture* m_image{ nullptr };
	SDL_Point m_spriteDimension{0,0};
	SDL_Point m_celDimension{0,0};
	SDL_Point m_imageDimension{0,0};
	float m_animationVelocity{ 0.0f };
	int m_imageCel{0};
};