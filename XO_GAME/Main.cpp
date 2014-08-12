#include "stdafx.h"
#include "Main.h"
#include "Sprite.h"

int CMain::select()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			180 * i;
		}
	}

}

bool CMain::check(int a, int b)
{
	if (place[a][b].in == 1)
	{
		int vertical = 1;//(|)
		int horizontal = 1;//(-)
		int diagonal1 = 1;//(\)
		int diagonal2 = 1;//(/)
		char player = place[a][b].player;
		int i;//vertical
		int j;//horizontal
		//check for vertical(|)
		for (i = a + 1; place[i][b].player == player && i < 3; i++, vertical++);//Check down
		for (i = a - 1; place[i][b].player == player && i >= 0; i--, vertical++);//Check up
		if (vertical >= 3)return true;
		//check for horizontal(-)
		for (j = b - 1; place[a][j].player == player && j >= 0; j--, horizontal++);//Check left
		for (j = b + 1; place[a][j].player == player && j < 3; j++, horizontal++);//Check right
		if (horizontal >= 3) return true;
		//check for diagonal 1 (\)
		for (i = a - 1, j = b - 1; place[i][j].player == player && i >= 0 && j >= 0; diagonal1++, i--, j--);//up and left
		for (i = a + 1, j = b + 1; place[i][j].player == player && i < 3 && j < 3; diagonal1++, i++, j++);//down and right
		if (diagonal1 >= 3) return true;
		//check for diagonal 2(/)
		for (i = a - 1, j = b + 1; place[i][j].player == player && i >= 0 && j < 3; diagonal2++, i--, j++);//up and right
		for (i = a + 1, j = b - 1; place[i][j].player == player && i < 3 && j >= 0; diagonal2++, i++, j--);//up and left
		if (diagonal2 >= 3) return true;
		return false;
	}
}

CMain::CMain(int passed_ScreenWidth, int passed_ScreenHight)
{
	//Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
	
	ScreenWidth = passed_ScreenWidth;
	ScreenHeight = passed_ScreenHight;
	quit = false;
	csdl_setup = new CSDL_Setup(&quit, ScreenWidth, ScreenHeight);
	X = new CSprite(csdl_setup->GetRenderer(), "X.png", 200, 100, 53, 53);
	O = new CSprite(csdl_setup->GetRenderer(), "O.png", 200, 100, 53, 53);
	Board = new CSprite(csdl_setup->GetRenderer(), "board.png", 0, 0, 554, 553);

	up = false;
	down = false;
	left = false;
	right = false;
	timecheck = SDL_GetTicks();
	
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
	delete X;
	delete O;
	delete Board;
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
		SDL_GetMouseState(&MouseX, &MouseY);
		SDL_RenderFillRect(csdl_setup->GetRenderer(), &r);
		Board->draw();
		for (int j = 0; j < Rect1.size(); j++)
		{
			SDL_RenderCopy(csdl_setup->GetRenderer(), X->Get_image(), NULL, &Rect1[j]);//save red coin in the vector 1

		}
		for (int j = 0; j < Rect2.size(); j++)
		{
			SDL_RenderCopy(csdl_setup->GetRenderer(), O->Get_image(), NULL, &Rect2[j]);//save the yellow coin in the vector two
		}
		if (number_of_coin % 2 == 0)
		{
			X->draw();//draw the red coin if the number of coin is even number
		}
		else
		{
			O->draw();//draw the yellow coin if the number of coin is odd number
		}


		csdl_setup->end();//upload the picture
	}
}