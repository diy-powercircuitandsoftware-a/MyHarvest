#include "GameTitle.h"
#include "../../GameEngine/raylib/src/raylib.h"

GameTitle::GameTitle(int w,int h,   bool hadsavegame) {
	this->scene = Selector::MAIN;
	this->w = w;
	this->h = h;
	 
	this->hadsavegame = hadsavegame;
}
void GameTitle::Init()
{
}
void GameTitle::Update() {

	if (this->scene == Selector::MAIN) {
	//	

		if (IsKeyDown(KEY_UP)) {
			this->TitleSceneSelector = Selector::NEWGAME;
		}
		else if (IsKeyDown(KEY_DOWN)&& this->hadsavegame) {
			this->TitleSceneSelector = Selector::LOADGAME;
		}


		//MeasureTextEx(GetFontDefault(), "", GetFontDefault().baseSize * 2.0f, 2);
	}
	
	

}
void GameTitle::Render() {
	ClearBackground(WHITE);
	if (this->scene == Selector::MAIN&& this->hadsavegame) {
		 
		if (this->TitleSceneSelector == Selector::NEWGAME) {
			 
			//DrawText("NewGame", 0, 0, this->SelectorFont.baseSize, GREEN);
			//DrawText("LoadGame", 0, 10, this->fontsize, BLACK);
		}else if (this->TitleSceneSelector == Selector::LOADGAME && this->hadsavegame) {
			//DrawText("NewGame", 0, 0, this->fontsize, BLACK);
			//DrawText("LoadGame", 0, 10, this->fontsize, GREEN);
		}
	}
	else if (this->scene == Selector::MAIN && !this->hadsavegame) {
		Vector2 pos;
		pos.x = 0;
		pos.y = 0;
	//	DrawTextEx(this->SelectorFont.font, "New Game", pos, this->SelectorFont.size, 1, GREEN);
		 
	}


	
}


