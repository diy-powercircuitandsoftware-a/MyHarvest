#include "GameTitle.h"
#include "../../GameEngine/raylib/src/raylib.h"
#include "../../GameEngine/raylib/src/extras/raygui.h"
#include <string>
 

GameTitle::GameTitle(int w,int h,   bool hadsavegame) {
	this->scene = Selector::MAIN;
	this->main_scene_selector = Selector::NEWGAME;
	this->w = w;
	this->h = h;
	this->hadsavegame = hadsavegame;
}
void GameTitle::Init()
{
	
	Vector2 pos_main_newgame;
	  
	if (!this->hadsavegame) {
		pos_main_newgame=	MeasureTextEx(this->SelectorFont.GetFont(), "New Game", this->SelectorFont.size * 4, this->SelectorFont.spacing);
		this->main_newgame.x = (GetScreenWidth() / 2) - (pos_main_newgame.x / 2);
		this->main_newgame.y = (GetScreenHeight() / 2) - (pos_main_newgame.y / 2);
		
	 
	}
	else {
		pos_main_newgame = MeasureTextEx(this->SelectorFont.GetFont(), "New Game", this->SelectorFont.size , this->SelectorFont.spacing);
		this->main_newgame.x = (GetScreenWidth() / 2) - (pos_main_newgame.x / 2);
		this->main_newgame.y = (GetScreenHeight() / 2) - (pos_main_newgame.y / 2);
	 
	}
	this->txt_newgame_rect.x = (float)(GetScreenWidth() * 0.2);
	this->txt_newgame_rect.y = this->main_newgame.y + pos_main_newgame.y;
	this->txt_newgame_rect.width = (float)GetScreenWidth() - this->txt_newgame_rect.x;
	this->txt_newgame_rect.height = this->SelectorFont.size * 2;
	 
}
void GameTitle::Update() {

	if (this->scene == Selector::MAIN) {
	//	

		if (IsKeyDown(KEY_UP)) {
			this->main_scene_selector = Selector::NEWGAME;
		}
		else if (IsKeyDown(KEY_DOWN)&& this->hadsavegame) {
			this->main_scene_selector = Selector::LOADGAME;
		}
		else if (IsKeyDown(KEY_ENTER) && this->main_scene_selector == Selector::NEWGAME) {
			this->scene = Selector::NEWGAME;
		}
		else if (IsKeyDown(KEY_ENTER) && this->main_scene_selector == Selector::LOADGAME) {
			this->scene = Selector::LOADGAME;
		}


		 
	}
	
	

}
void GameTitle::Render() {
	ClearBackground((Color) { 40, 139, 34 });
 
	 
	if (this->scene == Selector::MAIN&& this->hadsavegame) {
		 
		if (this->main_scene_selector == Selector::NEWGAME) {
			 
			//DrawText("NewGame", 0, 0, this->SelectorFont.baseSize, GREEN);
			//DrawText("LoadGame", 0, 10, this->fontsize, BLACK);
		}else if (this->main_scene_selector == Selector::LOADGAME && this->hadsavegame) {
			//DrawText("NewGame", 0, 0, this->fontsize, BLACK);
			//DrawText("LoadGame", 0, 10, this->fontsize, GREEN);
		}
	}
	else if (this->scene == Selector::MAIN && !this->hadsavegame) {
		 
	  	DrawTextEx(this->SelectorFont.GetFont(), "New Game", this->main_newgame, this->SelectorFont.size*4, this->SelectorFont.spacing, WHITE);
		 
	}
	else if (this->scene == Selector::NEWGAME) {
		this->txt_newgame_rect.y = this->txt_newgame_rect.y - this->main_newgame.y;
		this->main_newgame.y = 0;
		DrawTextEx(this->SelectorFont.GetFont(), "New Game", this->main_newgame, this->SelectorFont.size * 4, this->SelectorFont.spacing, WHITE);
		GuiTextBox(this->txt_newgame_rect, this->player_name, 12, true);


	}
	

	
}


