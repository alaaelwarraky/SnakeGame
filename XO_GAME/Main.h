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
	int select();
	struct cell
	{
		int in;
		char player;
	};
	cell place[3][3];
	Mix_Music *gMusic = NULL;

	//The sound effects that will be used
	Mix_Chunk *gScratch = NULL;
	Mix_Chunk *win = NULL;
	Mix_Chunk *SELECT = NULL;
	Mix_Chunk *DROP = NULL;
	/*
	Uint32 clearColor;
	Uint8  video_bpp = 32;*/
	SDL_Rect screenRect;
	SDL_Rect r;
	vector<SDL_Rect>Rect1, Rect2;
	int number_of_coin = 0;
	bool up;
	bool down;
	bool right;
	bool left;

	int timecheck;
	int MouseY = 0;
	int MouseX = 0;
private:
	int ScreenWidth;
	int ScreenHeight;
	bool quit;

	CSprite* X;

	CSprite* O;

	CSprite* Board;
	CSDL_Setup* csdl_setup;

};

