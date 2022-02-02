#include "DropDownBox.h"
#include <iostream>
Controls::DropDownBox::DropDownBox()
{
}

Controls::DropDownBox::DropDownBox(Rectangle rect)
{
	this->Position = rect;
}



void Controls::DropDownBox::AddList(int id,std::string value)
{
	DropDownList ddl;
	ddl.id = id;
	ddl.s = value;
	ddl.position.x = this->Position.x;
	ddl.position.width = this->Position.width + this->BorderSize;
	ddl.position.height = this->Position.height - (this->BorderSize * 2);
	if (!this->list.empty()) {
		DropDownList lastdd = this->list.back();
		ddl.position.y = lastdd.position.y + lastdd.position.height;
	}
	else {
		ddl.position.y = this->Position.y + this->Position.height;
	}
	this->list.push_back(ddl);
	this->selectedvalue = this->list[0];
	 
}

void Controls::DropDownBox::Render()
{
	if (this->list.size()>0) {
		DrawRectangle(
			this->Position.x,
			this->Position.y,
			this->Position.width,
			this->Position.height,
			this->BorderColor);

		DrawRectangle(
			this->Position.x + this->BorderSize,
			this->Position.y + this->BorderSize,
			this->Position.width - (this->BorderSize * 2),
			this->Position.height - (this->BorderSize * 2),
			this->BackgroundColor);
		Vector2 mousePoint = GetMousePosition();
	

		if (!this->ReadOnly) {
			if (this->togglelist) {

				for (auto i = this->list.begin(); i != this->list.end(); ++i) {
					if (CheckCollisionPointRec(mousePoint, i->position) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
						this->selectedvalue = *i;
						break;
					}
				}
				

			}
			if (CheckCollisionPointRec(mousePoint, this->Position) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				this->togglelist = !this->togglelist;
			
			}
			
			else if (!CheckCollisionPointRec(mousePoint, this->Position) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				this->togglelist = false;
			}
		}
		
		else   {
			this->togglelist = false;
		}

		DrawTextEx(this->Font,
			this->selectedvalue.s.c_str(),
			(Vector2) {
			this->Position.x + this->BorderSize, this->Position.y + this->BorderSize
		}, this->Font.baseSize, 0, this->TextColor);

		if (this->togglelist) {
			for (auto i = this->list.begin(); i != this->list.end(); ++i) {
				DrawRectangle(
					i->position.x,
					i->position.y,
					i->position.width,
					i->position.height,
					this->BackgroundColor);

				DrawTextEx(this->Font,
					i->s.c_str(),
					(Vector2) {
					i->position.x, i->position.y
				}, this->Font.baseSize, 0, this->TextColor);



			}
		 
		}
		//toggle if list >displaysize add schoolbar
	}

}
