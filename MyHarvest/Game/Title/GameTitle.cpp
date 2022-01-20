#include "GameTitle.h"
#include "../../GameEngine/raylib/src/raylib.h"
#include "../../GameEngine/raylib/src/extras/raygui.h"
#include <string>
 

GameTitle::GameTitle(    bool hadsavegame) {
	this->scene = Selector::MAIN;
	this->main_scene_selector = Selector::NEWGAME;
	 
	this->hadsavegame = hadsavegame;

}
void GameTitle::Init()
{
	
	Vector2 measuretextnewgame;
	
	if (!this->hadsavegame) {
		measuretextnewgame =MeasureTextEx(this->SelectorFont.GetFont(), "New Game", this->SelectorFont.size * 4, this->SelectorFont.spacing);
		this->newgamepos.newgamelabel.x = (GetScreenWidth() / 2) - (measuretextnewgame.x / 2);
		this->newgamepos.newgamelabel.y = (GetScreenHeight() / 2) - (measuretextnewgame.y / 2);			 
	}
	else {
		Vector2 measuretextloadgame= MeasureTextEx(this->SelectorFont.GetFont(), "Load Game", this->SelectorFont.size, this->SelectorFont.spacing);
		measuretextnewgame = MeasureTextEx(this->SelectorFont.GetFont(), "New Game", this->SelectorFont.size , this->SelectorFont.spacing);
		this->newgamepos.newgamelabel.x = (GetScreenWidth() / 2) - (measuretextnewgame.x / 2);
		this->newgamepos.newgamelabel.y = (GetScreenHeight() / 2) - (measuretextnewgame.y / 2);
		this->loadgamepos.loadgamelabel.x = (GetScreenWidth() / 2) - (measuretextloadgame.x / 2);
		this->loadgamepos.loadgamelabel.y = (GetScreenHeight() / 2) - (measuretextloadgame.y / 2)+ measuretextnewgame.y;
	 
	}
	 
	 
}
void GameTitle::Update() {

	if (this->scene == Selector::MAIN) {
	 
		if (IsKeyDown(KEY_UP)) {
			this->main_scene_selector = Selector::NEWGAME;
		}
		else if (IsKeyDown(KEY_DOWN)&& this->hadsavegame) {
			this->main_scene_selector = Selector::LOADGAME;
		}
		else if (IsKeyDown(KEY_ENTER) && this->main_scene_selector == Selector::NEWGAME) {
			 GuiSetFont(this->LabelFont.GetFont());
			Vector2	measuretext  = MeasureTextEx(this->TitleFont.GetFont(), "New Game", this->TitleFont.size  , this->TitleFont.spacing);
			this->newgamepos.newgamelabel.x = (GetScreenWidth() / 2) - (measuretext.x / 2);
			this->newgamepos.newgamelabel.y = 0;

			this->drawtextlist.SetInitPosition( 0, measuretext.y );
			this->drawtextlist.Add((DrawTextList::TextData) { "Name:", this->LabelFont.GetFont(), this->LabelFont.size, this->LabelFont.spacing,WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Gender:", this->LabelFont.GetFont(), this->LabelFont.size, this->LabelFont.spacing ,WHITE});
			this->drawtextlist.Add((DrawTextList::TextData) { "Polyamory:", this->LabelFont.GetFont(), this->LabelFont.size, this->LabelFont.spacing,WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Born:", this->LabelFont.GetFont(), this->LabelFont.size, this->LabelFont.spacing,WHITE });
			
			 
			this->drawtextlist.Update();
			std::map<std::string, Vector2> hashmap = this->drawtextlist.GetMapPosition();
			
			this->newgamepos.txtname.x = this->drawtextlist.MaxDistanceString.x;
			this->newgamepos.txtname.y = hashmap["Name:"].y;
			this->newgamepos.txtname.width = GetScreenWidth()- this->newgamepos.txtname.x;
			this->newgamepos.txtname.height = this->drawtextlist.MaxDistanceString.y;
			
		 	this->newgamepos.genderselector.x = this->drawtextlist.MaxDistanceString.x;
		 	this->newgamepos.genderselector.y = hashmap["Gender:"].y;
		 	this->newgamepos.genderselector.width = GetScreenWidth() - this->newgamepos.genderselector.x;
		    this->newgamepos.genderselector.height = this->drawtextlist.MaxDistanceString.y;
			
			this->newgamepos.chkboxpolyamory.x = this->drawtextlist.MaxDistanceString.x;
			this->newgamepos.chkboxpolyamory.y = hashmap["Polyamory:"].y;
			this->newgamepos.chkboxpolyamory.width = this->drawtextlist.MaxDistanceString.y;
			this->newgamepos.chkboxpolyamory.height = this->drawtextlist.MaxDistanceString.y;
			
			this->scene = Selector::NEWGAME;
		}
		else if (IsKeyDown(KEY_ENTER) && this->main_scene_selector == Selector::LOADGAME) {
			this->scene = Selector::LOADGAME;
		}


		 
	}
	
	

}
void GameTitle::Render() {
	ClearBackground((Color) { 40, 139, 34 });
 
	 
	if (this->scene == Selector::MAIN&& this->hadsavegame) {
		 
		if (this->main_scene_selector == Selector::NEWGAME) {
			DrawTextEx(this->SelectorFont.GetFont(), "New Game", this->newgamepos.newgamelabel, this->SelectorFont.size  , this->SelectorFont.spacing, WHITE);
			DrawTextEx(this->SelectorFont.GetFont(), "Load Game", this->loadgamepos.loadgamelabel, this->SelectorFont.size, this->SelectorFont.spacing, BLACK);
		}else if (this->main_scene_selector == Selector::LOADGAME && this->hadsavegame) {
			DrawTextEx(this->SelectorFont.GetFont(), "New Game", this->newgamepos.newgamelabel, this->SelectorFont.size, this->SelectorFont.spacing, BLACK);
			DrawTextEx(this->SelectorFont.GetFont(), "Load Game", this->loadgamepos.loadgamelabel, this->SelectorFont.size, this->SelectorFont.spacing, WHITE);
		}
	}
	else if (this->scene == Selector::MAIN && !this->hadsavegame) {
		 
	  	DrawTextEx(this->SelectorFont.GetFont(), "New Game", this->newgamepos.newgamelabel, this->SelectorFont.size*4, this->SelectorFont.spacing, WHITE);
		 
	}
	else if (this->scene == Selector::NEWGAME) {
		DrawTextEx(this->TitleFont.GetFont(), "New Game", this->newgamepos.newgamelabel, this->TitleFont.size, this->TitleFont.spacing, WHITE);
		this->drawtextlist.Render();
	    //Draw Name Input		 
	 	GuiTextBox(this->newgamepos.txtname, this->player_name, 12, true);
		//Draw Gender Input
	 	if (GuiDropdownBox(this->newgamepos.genderselector, "Man;Woman;Gay;Lesbian;Bisexual", &this->gender, this->newgamepos.selectgendertoggle))	this->newgamepos.selectgendertoggle = !this->newgamepos.selectgendertoggle;
		//Draw Polyamory Input
		this->newgamepos.chkboxpolyamorytoggle = GuiCheckBox(this->newgamepos.chkboxpolyamory, "(Not Love One)", this->newgamepos.chkboxpolyamorytoggle);



		//if (GuiButton((Rectangle) { 20, 20, 20, 20 }, "Press me!")) {
		//	std::cout << "Pressed";
	//	}
		 

	}
	

	
}


