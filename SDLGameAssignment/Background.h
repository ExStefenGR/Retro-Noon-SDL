#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"
class Background : public GameObject
{
public:
	Background();
	~Background() override;
	void PlayMusic();
	void Update() final {};
	void Render() final;
	virtual void Stop() {music.Stop();};

	Music music{};
	Sprite m_images{};
};