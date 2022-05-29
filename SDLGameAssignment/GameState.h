#pragma once
class GameState
{
public:
	virtual ~GameState() = default;

	virtual bool OnEnter() = 0;      // Load assets in this function
	virtual GameState* Update() = 0; // TODO: make sure to find a way to use
									 // unique pointers for return values here
	virtual bool Render() = 0;       // Here we draw all of our scene's game objects
	virtual void OnExit() = 0;       // Unload assets in this function

	std::unique_ptr<Background> m_background = std::make_unique<Background>();
	std::unique_ptr<MenuOptions> m_replay = std::make_unique<MenuOptions>();
	std::unique_ptr<Score> m_score = std::make_unique<Score>();
	std::unique_ptr<MenuOptions> m_menu = std::make_unique<MenuOptions>();
	std::unique_ptr<CowboyP2> m_cowboy = std::make_unique<CowboyP2>();
	std::unique_ptr<Player> m_player = std::make_unique<Player>();
	std::unique_ptr<Bullet> m_bullet = std::make_unique<Bullet>();
	std::unique_ptr<Timer> m_timer = std::make_unique<Timer>();
};
