#include "NewGame.h"
#include "../../../GameEngine/raylib/src/extras/raygui.h"

void NewGame::Init()
{
		    Vector2	measuretext = MeasureTextEx(this->TitleFont, "New Game", this->TitleFont.baseSize, this->TitleFont.glyphPadding);
			this->newgamelabel.x = (GetScreenWidth() / 2) - (measuretext.x / 2);
			this->newgamelabel.y = 0;
		
			
			//caculate ui position
			this->drawtextlist.SetInitPosition(0, measuretext.y);
			this->drawtextlist.Add((DrawTextList::TextData) { "Name:", this->LabelFont, WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Farm Name:", this->LabelFont, WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Gender:", this->LabelFont,  WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Polyamory:", this->LabelFont,   WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Born:", this->LabelFont,   WHITE });
			this->drawtextlist.Update();		
			std::map<std::string, Vector2> hashmap = this->drawtextlist.GetMapPosition();

			this->txtname = Controls::Textbox((Rectangle){
				this->drawtextlist.MaxDistanceString.x,
				hashmap["Name:"].y,
				GetScreenWidth() - this->drawtextlist.MaxDistanceString.x,
				this->drawtextlist.MaxDistanceString.y
			});
			this->txtname.Font = this->LabelFont;
			 
			this->txtfarmname = Controls::Textbox((Rectangle) {
				this->drawtextlist.MaxDistanceString.x,
					hashmap["Farm Name:"].y,
					GetScreenWidth() - this->drawtextlist.MaxDistanceString.x,
					this->drawtextlist.MaxDistanceString.y
			});
			this->txtfarmname.Font = this->LabelFont;
			this->genderselector = Controls::DropDownBox((Rectangle) {
					this->drawtextlist.MaxDistanceString.x,
					hashmap["Gender:"].y,
					GetScreenWidth() - this->drawtextlist.MaxDistanceString.x,
					this->drawtextlist.MaxDistanceString.y
			});

			  
			this->genderselector.AddList(GameObject::Person::Gender::Bisexual, "Bisexual");
			this->genderselector.AddList(GameObject::Person::Gender::Gay, "Gay");
			this->genderselector.AddList(GameObject::Person::Gender::Lesbian, "Lesbian");
			this->genderselector.AddList(GameObject::Person::Gender::Man, "Man");
			this->genderselector.AddList(GameObject::Person::Gender::Woman, "Woman");
			this->genderselector.Font = this->LabelFont;
			 /*

  

			this->uiposition.chkboxpolyamory.x = this->drawtextlist.MaxDistanceString.x;
			this->uiposition.chkboxpolyamory.y = hashmap["Polyamory:"].y;
			this->uiposition.chkboxpolyamory.width = this->drawtextlist.MaxDistanceString.y;
			this->uiposition.chkboxpolyamory.height = this->drawtextlist.MaxDistanceString.y;

			measuretext = MeasureTextEx(this->LabelFont, "30/12", this->LabelFont.baseSize, this->LabelFont.glyphPadding);
			this->uiposition.bornboxday.x = this->drawtextlist.MaxDistanceString.x;
			this->uiposition.bornboxday.y = hashmap["Born:"].y;
			this->uiposition.bornboxday.width = measuretext.x;
			this->uiposition.bornboxday.height = this->drawtextlist.MaxDistanceString.y;

			this->uiposition.bornboxmonth.x = this->drawtextlist.MaxDistanceString.x+ this->uiposition.bornboxday.width+ (this->uiposition.bornboxday.width*0.2);
			this->uiposition.bornboxmonth.y = hashmap["Born:"].y;
			this->uiposition.bornboxmonth.width = measuretext.x;
			this->uiposition.bornboxmonth.height = this->drawtextlist.MaxDistanceString.y;
			  
			Image image = LoadImage(this->SeasonsTexture.path.c_str());  
			this->seasonstexture2d= LoadTextureFromImage(image);			
			this->uiposition.seasonpos.y = hashmap["Born:"].y + this->drawtextlist.MaxDistanceString.y;
			UnloadImage(image);

			this->uiposition.bnnewgame.x = 0;
			this->uiposition.bnnewgame.width= GetScreenWidth();
			this->uiposition.bnnewgame.height = this->drawtextlist.MaxDistanceString.y;
			*/


}

void NewGame::Update()
{
/*
	if (this->BornMonth <= 3) {
		this->seasondrawrect = this->SeasonsTexture.spring;
	}
	else if (this->BornMonth >= 3 && this->BornMonth <= 6) {
		this->seasondrawrect = this->SeasonsTexture.summer;
	}
	else if (this->BornMonth >= 6 && this->BornMonth <= 9) {
		this->seasondrawrect = this->SeasonsTexture.autumnand;
	}
	else if (this->BornMonth > 9) {
		this->seasondrawrect = this->SeasonsTexture.winter;
	}
	this->uiposition.seasonpos.x = (GetScreenWidth() / 2) - (this->seasondrawrect.width /2);
	this->uiposition.bnnewgame.y = this->uiposition.seasonpos.y + this->seasondrawrect.height;*/
}

void NewGame::Render()
{
	DrawTextEx(this->TitleFont, "New Game", this->newgamelabel, this->TitleFont.baseSize, this->TitleFont.glyphPadding, WHITE);
	this->drawtextlist.Render();
	//Draw Name Input
	this->txtname.Render();
	this->txtfarmname.Render();

	//Draw Seasons Icon //raygui not have zindex
	DrawTextureRec(this->seasonstexture2d, this->seasondrawrect, this->uiposition.seasonpos, WHITE);


	//Draw Gender Input
	this->genderselector.Render();
	 

	/*
	

	
	//prevent render gender input reduce cpu used
	if (!this->uiposition.selectgendertoggle) {
		//Draw Polyamory Input
		this->uiposition.chkboxpolyamorytoggle = GuiCheckBox(this->uiposition.chkboxpolyamory, "(Not Love One)", this->uiposition.chkboxpolyamorytoggle);
		//Draw Born Input
		GuiSpinner(this->uiposition.bornboxday, "", &this->BornDay, 1, 30, true);
		GuiSpinner(this->uiposition.bornboxmonth, "", &this->BornMonth, 1, 12, true);
	}	
	GuiButton(this->uiposition.bnnewgame, "New Game");
	*/
}

 
NewGame::~NewGame()
{
	UnloadTexture(this->seasonstexture2d);
}
 