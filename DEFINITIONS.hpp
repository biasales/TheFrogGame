#pragma once

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 512

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/splashBackground.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky.png"
#define GAME_BACKGROUND_FILEPATH "Resources/res/bgcar.png"
#define GAME_PAUSE_FILEPATH "Resources/res/pause.png"

#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/gameover.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

#define CAR_FILEPATH "Resources/res/red.png"
#define ICON_FILEPATH "Resources/res/redicon.png"

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f