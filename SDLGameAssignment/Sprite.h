#pragma once

#include <string>
#include <SDL.h>
#include "Screen.h"

class Sprite
{

	enum Flip
	{
		NO_FLIP = SDL_FLIP_NONE,
		HORZ_FLIP = SDL_FLIP_HORIZONTAL,
		VERT_FLIP = SDL_FLIP_VERTICAL
	};

public:

	Sprite();
	~Sprite() {}

	void IsAnimated(bool flag);
	void IsAnimationLooping(bool flag);

	void SetImageCel(int column, int row);

	void SetAnimationVelocity(float velocity);
	void SetSpriteDimension(int width, int height); //on screen
	void SetImageDimension(int columns, int rows, int width, int height); //in folder

	bool Load(const std::string& filename, Screen& screen);
	void Unload();

	void Update();
	void Render(int xPos, int yPos, double angle, Screen& screen);

	

private:

	bool m_isAnimated;
	bool m_isAnimationLooping;
	bool m_isAnimationDead;

	Flip m_flip;

	SDL_Texture* m_image;
	SDL_Point m_spriteDimension;
	SDL_Point m_celDimension;
	SDL_Point m_imageDimension;

	float m_animationVelocity;
	int m_imageCel;

};