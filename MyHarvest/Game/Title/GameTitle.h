#ifndef GAMETITLE_H
#define GAMETITLE_H
#include "../../GameEngine/raylib/src/raylib.h"
#include "../Config/FontConfig.h"
#include "../UI/DrawTextList.h"
class GameTitle
{
public:
	GameTitle( bool hadsavegame);
	void Update();
	void Render();	
	void Init();
	FontConfig SelectorFont;
	FontConfig TitleFont;
	FontConfig LabelFont;
	char player_name[12] = "Player";
	 
	int gender=0;
private :
	typedef enum Selector { MAIN,   NEWGAME, LOADGAME} Selector;
	typedef struct UINewGamePosition
	{
		Vector2 newgamelabel;
		 
		Rectangle txtname;
		 
		Rectangle genderselector;			 
		Rectangle chkboxpolyamory;
		bool selectgendertoggle = false;
		bool chkboxpolyamorytoggle = false;
	}UINewGamePosition;
	typedef	struct UILoadGamePosition
	{
		Vector2 loadgamelabel;
	}UILoadGamePosition;
	Selector main_scene_selector;
	Selector scene;	 
	UINewGamePosition newgamepos;
	UILoadGamePosition loadgamepos;
	DrawTextList drawtextlist;
	bool hadsavegame;
	
	
	  
};
#endif
