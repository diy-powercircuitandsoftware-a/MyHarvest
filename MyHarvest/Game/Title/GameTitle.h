#ifndef GAMETITLE_H
#define GAMETITLE_H
#include "../../GameEngine/raylib/src/raylib.h"
#include "../UI/GameFont.h"
class GameTitle
{
public:
	GameTitle(int w, int h,bool hadsavegame);
	void Update();
	void Render();	
	void Init();
	GameFont SelectorFont;
	char player_name[12] = "Player";
private :
	typedef enum Selector { MAIN,   NEWGAME, LOADGAME} Selector;	 
	Selector main_scene_selector;
	Selector scene;
	int w; 
	int h;  
	bool hadsavegame;
	Vector2 main_newgame;
	Vector2 main_loadgame;
	Rectangle txt_newgame_rect;
};
#endif
