#include "MainTitle.h"
#include "../../GameEngine/raylib/src/raylib.h"

MainTitle::MainTitle(int w,int h, int fontsize) {
	this->scene = Scene::SCENE_TITLE;
}
 
void MainTitle::Update() {

	if (this->scene == Scene::SCENE_TITLE) {
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
			DrawText("NewGame", 190, 200, 20, BLACK);
		}else if (this->TitleSceneSelector == Selector::LOADGAME_SELECTOR) {
			DrawText("LoadGame", 190, 200, 20, BLACK);
		}
	}
	
}