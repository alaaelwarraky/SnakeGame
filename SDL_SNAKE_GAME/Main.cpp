#include "stdafx.h"
#include "Main.h"
#include "Sprite.h"

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHight)
{
	//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	//winner = false;
	//number_of_coin = 0;
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHight;
	quit = false;
	csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight);
	Snake = new CSprite(csdl_setup->GetRenderer(), "snake.png", 200, 100, 53, 53);
	up = false;
	down = false;
	left = false;
	right = false;
	timecheck = SDL_GetTicks();
	//red_coin = new CSprite(csdl_setup->GetRenderer(), "player 1.png", 8, 10, 99, 80);
	//yellow_coin = new CSprite(csdl_setup->GetRenderer(), "player 2.png", 8, 10, 99, 80);
	//red_win = new CSprite(csdl_setup->GetRenderer(), "player 1_win.png", 0, 0, 1073, 571);
	//yellow_win = new CSprite(csdl_setup->GetRenderer(), "player 2_win.png", 0, 0, 1073, 571);
	//no_winner = new CSprite(csdl_setup->GetRenderer(), "nowinner.png", 0, 0, 1073, 571);
	//intro_1 = new CSprite(csdl_setup->GetRenderer(), "intro 1.png", 0, 0, 1073, 571);
	//red_turn = new CSprite(csdl_setup->GetRenderer(), "red turn.png", 730, 100, 315, 348);
	//yellow_turn = new CSprite(csdl_setup->GetRenderer(), "yellow turn.png", 730, 100, 315, 348);

	//Initialize SDL_mixer
	/*if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
*/
	// COLOR BACKGROUND
	SDL_SetRenderDrawColor(csdl_setup->GetRenderer(), 239, 228, 176, 66);
	r = { 0, 0, 1073, 570 };

	//Load sound effects
	/*win = Mix_LoadWAV("CHEER2.wav");
	SELECT = Mix_LoadWAV("SELECT.wav");
	DROP = Mix_LoadWAV("low.wav");*/
}

CMain::~CMain()
{   //memory leaks
	delete csdl_setup;
	delete Snake;
	//delete red_coin;
	//delete yellow_coin;
	//delete red_win;
	//delete yellow_win;
	//delete no_winner;
	//delete intro_1;
	//Mix_FreeChunk(SELECT);
	//Mix_FreeChunk(DROP);
	//SELECT = NULL;
	//DROP = NULL;
}

void CMain::GameLoop(void)
{
	while (!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT)
	{
		csdl_setup->begain();
		SDL_RenderFillRect(csdl_setup->GetRenderer(), &r);
		Snake->draw();
		//moving with keyboard
		switch (csdl_setup->GetMainEvent()->type)
		{
		case SDL_KEYDOWN:
			switch (csdl_setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_a ://left
				Mix_PlayChannel(-1, SELECT, 0);
				left = true;
				break;
			case SDLK_d://right
				Mix_PlayChannel(-1, SELECT, 0);
				right = true;
				break;
			case SDLK_s:
				down = true;
				break;
			case SDLK_w:
				up = true;
				break;

			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (csdl_setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_a://left
				left = true;
				break;
			case SDLK_d://right
				right = true;
				break;
			case SDLK_s:
				down = true;
				break;
			case SDLK_w:
				up = true;
				break;

			default:
				break;
			}
			break;
		default:
			break;
		}
		if (timecheck + 50 < SDL_GetTicks())
		{
	
			if (left)
			{
				if (Snake->GetX() > 8)//RED COIN "even number" and don't move out the board
					Snake->SetX(Snake->GetX() - 10);
			}
			else if (right)
			{

				if (Snake->GetX() < 1020)//RED COIN "even number" and don't move out the board
					Snake->SetX(Snake->GetX() + 10);
			}
			 if (up)
			{
				if (Snake->GetY() > 8)//RED COIN "even number" and don't move out the board
					Snake->SetY(Snake->GetY() - 10);

			}
			 if (down)
			{
				if (Snake->GetY() < 520)//RED COIN "even number" and don't move out the board
					Snake->SetY(Snake->GetY() + 10);
			}
			timecheck = SDL_GetTicks();
		}
		csdl_setup->end();//upload the picture
	}
}