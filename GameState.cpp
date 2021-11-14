#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include <SFML/Audio.hpp>

#include <iostream>

using namespace sf;

namespace TheFrog
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("car", CAR_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_car.setTexture(this->_data->assets.GetTexture("car"));
		_car.setTextureRect(IntRect(160, 0, 32, 32));
		_car.setPosition(430, 20);
		_car.scale(2, 2);

		dangerzone.setPosition(370, 290);
		dangerzone.setSize(Vector2f(230, 120));
		dangerzone.setFillColor(sf::Color::Red);

		_gameState = GameStates::eReady;

	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}

			if (GameStates::eGameOver != _gameState)
			{
				_gameState = GameStates::ePlaying;
			}

			if (sf::Event::KeyReleased == event.type) 
			{
				if (sf::Keyboard::P == event.key.code)
				{
					// Switch To Pause
					this->_data->machine.AddState(StateRef(new PauseState(_data)), false);
				}
			}
			
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			_car.move(-2, 0);

			currentFrame = 1;
			if (currentFrame > 6) currentFrame -= 6;

			_car.setTextureRect(IntRect(32 * int(currentFrame), 0, 32, 32));

		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			_car.move(2, 0);
			currentFrame = 1;
			if (currentFrame > 6) currentFrame -= 6;

			_car.setTextureRect(IntRect(160 * int(currentFrame), 0, 32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			_car.move(0, -2);
			currentFrame = 1;
			if (currentFrame > 6) currentFrame -= 6;
			_car.setTextureRect(IntRect(96 * int(currentFrame), 0, 32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			_car.move(0, 2);
			currentFrame = 1;
			if (currentFrame > 6) currentFrame -= 6;
			_car.setTextureRect(IntRect(224 * int(currentFrame), 0, 32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (Keyboard::isKeyPressed(Keyboard::Right))
				_car.setTextureRect(IntRect(192 * int(currentFrame), 0, 32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			if (Keyboard::isKeyPressed(Keyboard::Left))
				_car.setTextureRect(IntRect(0 * int(currentFrame), 0, 32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (Keyboard::isKeyPressed(Keyboard::Left))
				_car.setTextureRect(IntRect(64 * int(currentFrame), 0, 32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			if (Keyboard::isKeyPressed(Keyboard::Right))
				_car.setTextureRect(IntRect(128 * int(currentFrame), 0, 32, 32));
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			sound.play();
		}
	}

	void GameState::Update(float dt)
	{
		if (GameStates::eGameOver != _gameState)
		{
		
		}

		if (GameStates::ePlaying == _gameState)
		{
			if (_car.getGlobalBounds().intersects(dangerzone.getGlobalBounds()))
			{
				_car.setColor(sf::Color::Blue),
				_gameState = GameStates::eGameOver;
			}
		}

		if (GameStates::eGameOver == _gameState)
		{
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				music.stop();
				this->_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}
		
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear( sf::Color::White );

		this->_data->window.draw(this->_background);

		this->_data->window.draw(this->_car);

		//this->_data->window.draw(this->dangerzone);

		this->_data->window.display();
	}
}