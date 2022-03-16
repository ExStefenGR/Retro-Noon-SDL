#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
class Background : public GameObject
{
public:
	Background(Screen& screen);
	~Background();
	void PlayMusic();
	virtual void Update(Input& input) {};
	virtual void Render(Screen& screen);
	virtual void Stop() {music.Stop();};
private:
	Music music{};
	Sprite m_images{};
};