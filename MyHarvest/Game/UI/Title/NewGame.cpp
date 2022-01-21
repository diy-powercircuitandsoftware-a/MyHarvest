#include "NewGame.h"
#include "../../../GameEngine/raylib/src/extras/raygui.h"
void NewGame::Init()
{
		    Vector2	measuretext = MeasureTextEx(this->TitleFont, "New Game", this->TitleFont.baseSize, this->TitleFont.glyphPadding);
			this->uiposition.newgamelabel.x = (GetScreenWidth() / 2) - (measuretext.x / 2);
			this->uiposition.newgamelabel.y = 0;
			
			GuiSetFont(this->LabelFont);
		   	GuiSetStyle(DEFAULT, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);
			this->drawtextlist.SetInitPosition(0, measuretext.y);
			this->drawtextlist.Add((DrawTextList::TextData) { "Name:", this->LabelFont, WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Gender:", this->LabelFont,  WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Polyamory:", this->LabelFont,   WHITE });
			this->drawtextlist.Add((DrawTextList::TextData) { "Born:", this->LabelFont,   WHITE });
			this->drawtextlist.Update();		
			std::map<std::string, Vector2> hashmap = this->drawtextlist.GetMapPosition();

			this->uiposition.txtname.x = this->drawtextlist.MaxDistanceString.x;
			this->uiposition.txtname.y = hashmap["Name:"].y;
			this->uiposition.txtname.width = GetScreenWidth()- this->uiposition.txtname.x;
			this->uiposition.txtname.height = this->drawtextlist.MaxDistanceString.y;

			this->uiposition.genderselector.x = this->drawtextlist.MaxDistanceString.x;
			this->uiposition.genderselector.y = hashmap["Gender:"].y;
			this->uiposition.genderselector.width = GetScreenWidth() - this->uiposition.genderselector.x;
			this->uiposition.genderselector.height = this->drawtextlist.MaxDistanceString.y;

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
			 
}

void NewGame::Update()
{
}

void NewGame::Render()
{
	DrawTextEx(this->TitleFont, "New Game", this->uiposition.newgamelabel, this->TitleFont.baseSize, this->TitleFont.glyphPadding, WHITE);
	this->drawtextlist.Render();
	//Draw Name Input
	GuiTextBox(this->uiposition.txtname, this->player_name, 12, true);
	//Draw Gender Input
	if (GuiDropdownBox(this->uiposition.genderselector, "Man;Woman;Gay;Lesbian;Bisexual", &this->gender, this->uiposition.selectgendertoggle))	this->uiposition.selectgendertoggle = !this->uiposition.selectgendertoggle;
	//Draw Polyamory Input
	this->uiposition.chkboxpolyamorytoggle = GuiCheckBox(this->uiposition.chkboxpolyamory, "(Not Love One)", this->uiposition.chkboxpolyamorytoggle);
	//Draw Born Input
	GuiSpinner(this->uiposition.bornboxday, "", &this->bornday, 1, 30, true);
	GuiSpinner(this->uiposition.bornboxmonth, "", &this->bornmonth, 1, 12, true);

	if (this->bornmonth <= 3) {

	}
	else if (this->bornmonth >= 3 && this->bornmonth <= 6) {

	}
	else if (this->bornmonth >= 6 && this->bornmonth <= 9) {

	}
	else if (this->bornmonth > 9) {

	}

	/*

		
		*/
		//if (GuiButton((Rectangle) { 20, 20, 20, 20 }, "Press me!")) {
		//	std::cout << "Pressed";
	//	}
}
