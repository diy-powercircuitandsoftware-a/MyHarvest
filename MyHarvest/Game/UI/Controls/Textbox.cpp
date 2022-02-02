#include "Textbox.h"
#include <iostream>

Controls::Textbox::Textbox()
{
}

Controls::Textbox::Textbox(Rectangle rect)
{
	this->Position = rect;
}

void Controls::Textbox::Render()
{
	DrawRectangle(
		this->Position.x  ,
		this->Position.y ,
		this->Position.width  ,
		this->Position.height ,
		this->BorderColor);

	DrawRectangle(
		this->Position.x+ this->BorderSize,
		this->Position.y+ this->BorderSize,
		this->Position.width- (this->BorderSize*2), 
		this->Position.height- (this->BorderSize*2),
		this->BackgroundColor);
		Vector2 mousePoint = GetMousePosition();

	if (CheckCollisionPointRec(mousePoint, this->Position)&& IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		this->focus = true;
		
	}
	else if (!CheckCollisionPointRec(mousePoint, this->Position) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		this->focus = false;		
	}

	if (!this->ReadOnly&& this->focus) {
		
		if ((this->Value.length() <( this->MaxLength - 1))&& (!IsKeyPressed(KEY_BACKSPACE))) {
			 
			int key = GetCharPressed();
			if (key > 0) {
				int byteSize = 0;
				const char* textUTF8 = CodepointToUTF8(key, &byteSize);
				for (int i = 0; i < byteSize; i++)
				{
					this->Value = this->Value + textUTF8[i];
				}
				 
			}		
				
		}
		else if (IsKeyPressed(KEY_BACKSPACE)&& this->Value.length()>0) {
			this->Value.pop_back();
		}
	}
	std::string clonetext = this->Value;
	Vector2 textpos;
	textpos=MeasureTextEx(this->Font, clonetext.c_str(), this->Font.baseSize, 1);
	 
	if (textpos.x > this->Position.width) {
	 
		do {

			clonetext.erase(0, 1);
			textpos = MeasureTextEx(this->Font, clonetext.c_str(), this->Font.baseSize, 1);
		} while (textpos.x > this->Position.width);
	 }
	
	
	
	Vector2 startdraw;
	
 	 
	if (this->TextAlignment== Alignment::Center){
		 
		float posx;
		posx = (this->Position.width/2) -  (   textpos.x / 2);
		 
		posx = posx + this->Position.x + this->BorderSize;
	
		startdraw = (Vector2)
		{
		posx , this->Position.y + this->BorderSize
		};
	}
	else if (this->TextAlignment == Alignment::Right) {
		float posx;
		posx = (this->Position.width ) - (textpos.x );

		posx = posx + this->Position.x + this->BorderSize;

		startdraw = (Vector2)
		{
		posx , this->Position.y + this->BorderSize
		};
	}
	else {
		startdraw = (Vector2)
		{
		this->Position.x + this->BorderSize, this->Position.y + this->BorderSize
		};
	}
	 
	DrawTextEx(this->Font,
		clonetext.c_str(),
		startdraw, this->Font.baseSize, 0, this->TextColor);
		
	 startdraw.x = startdraw.x + textpos.x+ this->Font.glyphPadding;
	if (!this->ReadOnly && this->focus) {
	 	DrawLineEx(startdraw, (Vector2) { startdraw.x,startdraw.y+  textpos.y}, 10, this->TextColor);
	}
	 
	
}
