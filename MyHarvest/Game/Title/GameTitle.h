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
private :
	typedef enum Selector { MAIN,   NEWGAME, LOADGAME} Selector;	 
	Selector TitleSceneSelector;
	Selector scene;
	int w; 
	int h; 
	bool hadsavegame;
};
#endif
