#ifndef NEWGAME_H
#define NEWGAME_H
#include "../../Texture/Seasons/Seasons.h"
#include "../Text/List/DrawTextList.h"
#include "../../../GameEngine/raylib/src/raylib.h"
 

class NewGame
{
public:
	void Init();
	void Update();
	void Render();
	char player_name[12] = "Player";
	int gender = 0;
	int bornday = 1;
	int bornmonth = 1;
	GameTexture::Seasons SeasonsTexture;
	Font SelectorFont;
	Font TitleFont;
	Font LabelFont;
private:
	typedef struct UIPosition
	{
		Vector2 newgamelabel;
		Rectangle txtname;
		Rectangle genderselector;
		Rectangle chkboxpolyamory;
		Rectangle bornboxday;
		Rectangle bornboxmonth;
		bool selectgendertoggle = false;
		bool chkboxpolyamorytoggle = false;
	}UIPosition;
	UIPosition uiposition;
	DrawTextList drawtextlist;
};
#endif
