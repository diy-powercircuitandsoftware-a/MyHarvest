#ifndef NEWGAME_H
#define NEWGAME_H
#include "../../../GameEngine/raylib/src/raylib.h"
#include "../../Texture/Seasons/Seasons.h"
#include "../../Object/Person/Person.h"
#include "../Text/List/DrawTextList.h"
#include "../Controls/Textbox.h"
#include "../Controls/DropDownBox.h"

class NewGame
{
public:
	void Init();
	void Update();
	void Render();
	 
	 
	GameTexture::Seasons SeasonsTexture;
	Font SelectorFont;
	Font TitleFont;
	Font LabelFont;
	
	~NewGame();
private:
	Vector2 newgamelabel;
	typedef struct UIPosition
	{
		
		 
		 
 
		Rectangle chkboxpolyamory;
		Rectangle bornboxday;
		Rectangle bornboxmonth;
		Rectangle bnnewgame;
	 
		bool chkboxpolyamorytoggle = false;
		bool txtnametoggle = true;
		bool txtfarmnametoggle = true;	 
		bool txtborndaytoggle = true;
		bool txtbornmonthtoggle = true;
		Vector2 seasonpos;
	}UIPosition;
	UIPosition uiposition;
	DrawTextList drawtextlist;
	Texture2D seasonstexture2d;
	Rectangle seasondrawrect;

	Controls::Textbox txtname;
	Controls::Textbox txtfarmname;
	Controls::DropDownBox genderselector;
	

};
#endif
