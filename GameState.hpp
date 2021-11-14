#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"

namespace TheFrog
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

		float currentFrame = 0;

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _car;

		sf::RectangleShape dangerzone;

		int _gameState;

		sf::Clock clock;

		sf::SoundBuffer soundbuffer;
		sf::Sound sound;
		sf::Music music;

	};
}