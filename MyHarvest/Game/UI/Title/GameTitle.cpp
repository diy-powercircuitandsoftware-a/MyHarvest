#include "GameTitle.h"
#include "../../../GameEngine/raylib/src/raylib.h"
#include "../Text/List/DrawTextList.h"
#include <string>
 

GameTitle::GameTitle(    bool hadsavegame) {
	 
	 
	this->hadsavegame = hadsavegame;

}
void GameTitle::Init()
{
	
	Vector2 measuretextnewgame= MeasureTextEx(this->SelectorFont, "New Game", this->SelectorFont.baseSize, this->SelectorFont.glyphPadding);
	this->labelnewgamepos.x = (GetScreenWidth() / 2) - (measuretextnewgame.x / 2);
	this->labelnewgamepos.y = (GetScreenHeight() / 2) - (measuretextnewgame.y / 2);
	if (this->hadsavegame) {
		Vector2 measuretextloadgame = MeasureTextEx(this->SelectorFont, "Load Game", this->SelectorFont.baseSize, this->SelectorFont.glyphPadding);				
		this->labelloadgamepos.x = (GetScreenWidth() / 2) - (measuretextloadgame.x / 2);
		this->labelloadgamepos.y = (GetScreenHeight() / 2) - (measuretextloadgame.y / 2) + measuretextnewgame.y;
		this->labelnewgamepos.y = this->labelnewgamepos.y - (measuretextnewgame.y / 2);
		this->labelloadgamepos.y = this->labelloadgamepos.y - (measuretextloadgame.y / 2);
	}
	 
	 
	 
	 
}
void GameTitle::Update() {

	if (this->scene == Selector::Main) {
	 
		if (IsKeyDown(KEY_UP)) {
			this->modeselector = Selector::Newgame;
		}
		else if (IsKeyDown(KEY_DOWN)&& this->hadsavegame) {
			this->modeselector = Selector::Loadgame;
		}
		else if (IsKeyDown(KEY_ENTER) && this->modeselector == Selector::Newgame) {
			uinewgame.LabelFont = this->LabelFont;
			uinewgame.TitleFont = this->TitleFont;
			uinewgame.SelectorFont = this->SelectorFont;
			uinewgame.Init();
			this->scene = Selector::Newgame;
		}
		else if (IsKeyDown(KEY_ENTER) && this->modeselector == Selector::Loadgame) {
			this->scene = Selector::Loadgame;
		}


		 
	}
	
	

}
void GameTitle::Render() {
	ClearBackground((Color) { 40, 139, 34 });
	 
	
	if (this->scene == Selector::Main&& this->hadsavegame) {
		if (this->modeselector == Selector::Newgame) {
			DrawTextEx(this->SelectorFont, "New Game", this->labelnewgamepos, this->SelectorFont.baseSize  , this->SelectorFont.glyphPadding, WHITE);
			DrawTextEx(this->SelectorFont, "Load Game", this->labelloadgamepos, this->SelectorFont.baseSize, this->SelectorFont.glyphPadding, BLACK);
		}else if (this->modeselector == Selector::Loadgame && this->hadsavegame) {
			DrawTextEx(this->SelectorFont, "New Game", this->labelnewgamepos, this->SelectorFont.baseSize, this->SelectorFont.glyphPadding, BLACK);
			DrawTextEx(this->SelectorFont, "Load Game", this->labelloadgamepos, this->SelectorFont.baseSize, this->SelectorFont.glyphPadding, WHITE);
		}
	}
	else if (this->scene == Selector::Main && !this->hadsavegame) {
		DrawTextEx(this->SelectorFont, "New Game", this->labelnewgamepos, this->SelectorFont.baseSize, this->SelectorFont.glyphPadding, WHITE);
	}
	else if (this->scene == Selector::Newgame) {
		uinewgame.Render();
	
		 

	}
	

	
}


