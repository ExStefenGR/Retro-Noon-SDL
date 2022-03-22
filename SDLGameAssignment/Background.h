#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
class Background : public GameObject
{
public:
	Background();
	~Background();
	void PlayMusic();
	virtual void Update() {};
	virtual void Render();
	virtual void Stop() {music.Stop();};
private:
	Music music{};
	Sprite m_images{};
};