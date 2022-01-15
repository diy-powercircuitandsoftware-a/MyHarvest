#include "MainTitle.h"
#include "../../GameEngine/raylib/src/raylib.h"

MainTitle::MainTitle(int w,int h, int fontsize) {
	this->scene = Scene::SCENE_TITLE;
	this->w = w;
	this->h = h;
	this->fontsize = fontsize;
}
 
void MainTitle::Update() {

	if (this->scene == Scene::SCENE_TITLE) {
		MeasureTextEx(GetFontDefault(), "", GetFontDefault().baseSize * 2.0f,2);

		if (IsKeyDown(KEY_UP)) {
			this->TitleSceneSelector = Selector::NEWGAME_SELECTOR;
		}
		else if (IsKeyDown(KEY_DOWN)) {
			this->TitleSceneSelector = Selector::LOADGAME_SELECTOR;
		}
	}
	
	

}
void MainTitle::Render() {
	ClearBackground(WHITE);
	if (this->scene == Scene::SCENE_TITLE) {
		 
		if (this->TitleSceneSelector == Selector::NEWGAME_SELECTOR) {
			 
			DrawText("NewGame", 0, 0, this->h/4, GREEN);
			DrawText("LoadGame", 0, 10, this->h / 4, BLACK);
		}else if (this->TitleSceneSelector == Selector::LOADGAME_SELECTOR) {
			DrawText("NewGame", 0, 0, this->h / 4, BLACK);
			DrawText("LoadGame", 0, 10, this->h / 4, GREEN);
		}
	}
	
}