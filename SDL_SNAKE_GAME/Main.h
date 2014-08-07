#pragma once
#include "stdafx.h"
#include "SDL_Setup.h"
#include"Sprite.h"
using namespace std;
class CMain
{
public:
	CMain(int passed_ScreenWidth, int passed_ScreenHight);
	~CMain();
	void GameLoop();
	void GameIntro();
	int drop(int col);
	bool check(int a, int b);
	Mix_Music *gMusic = NULL;

	//The sound effects that will be used
	Mix_Chunk *gScratch = NULL;
	Mix_Chunk *win = NULL;
	Mix_Chunk *SELECT = NULL;
	Mix_Chunk *DROP = NULL;
	bool success;
	SDL_Surface *screen;
	Uint32 clearColor;
	Uint8  video_bpp = 32;
	SDL_Rect screenRect;
	SDL_Rect r;	
	bool up;
	bool down;
	bool right;
	bool left;

	int timecheck;

private:
	int ScreenWidth;
	int ScreenHeight;
	bool quit;

	CSprite* Snake;

	//CSprite* red_coin;

	//CSprite* yellow_coin;

	//CSprite* red_win;

	//CSprite* yellow_win;

	//CSprite* no_winner;

	//CSprite* intro_1;

	//CSprite* red_turn;

	//CSprite* yellow_turn;

	CSDL_Setup* csdl_setup;

};

