#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

#include <iostream>
#include <fstream>

namespace TheFrog
{
    GameOverState::GameOverState(GameDataRef data) : _data(data)
    {

    }

    void GameOverState::Init()
    {      

        this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        _retryButton.setTexture(this->_data->assets.GetTexture("Play Button"));

        _retryButton.setPosition((SCREEN_WIDTH / 2) - (_retryButton.getGlobalBounds().width / 4), (SCREEN_HEIGHT / 2) - (_retryButton.getGlobalBounds().height / 2) + 200);
        _retryButton.setScale(0.5, 0.5);
    }

    void GameOverState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }

            if (this->_data->input.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void GameOverState::Update(float dt)
    {

    }

    void GameOverState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);

        this->_data->window.draw(this->_background);

        _data->window.draw(_retryButton);

        this->_data->window.display();
    }
}
