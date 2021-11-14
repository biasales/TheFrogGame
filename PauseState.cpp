#pragma once

#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "PauseState.hpp"

#include <iostream>

namespace TheFrog
{
	PauseState::PauseState(GameDataRef data) : _data(data)
	{

	}

	void PauseState::Init()
	{
		this->_data->assets.LoadTexture("Game Background Pause", GAME_PAUSE_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Game Background Pause"));
	}

	void PauseState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (sf::Event::KeyReleased == event.type)
			{
				if (sf::Keyboard::P == event.key.code)
				{
					// Switch To Pause
					this->_data->machine.RemoveState();
				}
			}

		}
	}

	void PauseState::Update(float dt)
	{
		
	}

	void PauseState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);

		this->_data->window.display();
	}
}