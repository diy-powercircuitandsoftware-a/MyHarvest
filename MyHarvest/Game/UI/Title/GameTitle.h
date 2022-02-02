#ifndef GAMETITLE_H
#define GAMETITLE_H
#include "../../../GameEngine/raylib/src/raylib.h"
#include "../Text/List/DrawTextList.h"
#include "../../Texture/Seasons/Seasons.h"
#include <string>
#include "NewGame.h"

class GameTitle
{
public:
	GameTitle( bool hadsavegame);
	 
	void Update();
	void Render();	
	void Init();
	Font SelectorFont;
	Font TitleFont;
	Font LabelFont;
	void SetSeasonsTexture(GameTexture::Seasons st);
	
private :
	typedef enum Selector { Main, Newgame, Loadgame } Selector;
	bool hadsavegame;
	Vector2 labelnewgamepos;
	Vector2 labelloadgamepos;
	Selector scene = Selector::Main;
	Selector modeselector = Selector::Newgame;
	NewGame uinewgame;
/*
	typedef	struct UILoadGamePosition
	{
		Vector2 loadgamelabel;
	}UILoadGamePosition;
	Selector main_scene_selector;
	Selector scene;	 
	
	UILoadGamePosition loadgamepos;
	DrawTextList drawtextlist;
	bool hadsavegame;
	*/
	
	  
};
#endif
