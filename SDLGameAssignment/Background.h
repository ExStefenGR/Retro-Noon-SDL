#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
class Background : public GameObject
{
public:
	Background();
	virtual ~Background();
	void PlayMusic();
	void Update() final{};
	void Render() final;
	virtual void Stop() { music.Stop(); };

private:
	Music music{};
	Sprite m_images{};
};