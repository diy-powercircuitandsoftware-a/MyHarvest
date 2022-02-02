#ifndef CONTROLS_TEXTBOX_H
#define CONTROLS_TEXTBOX_H
#include "../../../GameEngine/raylib/src/raylib.h"
#include <string>
namespace Controls {
	class Textbox
	{
	public:
		typedef enum Alignment { Left ,Center,Right} Alignment;
		Textbox();
		Textbox(Rectangle rect);
	
		Color BackgroundColor = WHITE;
		Color BorderColor = BLACK;
		Color TextColor = BLACK;
		int BorderSize = 1;
		Font Font=GetFontDefault();
		int MaxLength = 12;
		Rectangle Position;
		void Render();
		int ReadOnly = false;
		Alignment TextAlignment = Alignment::Left;	
		std::string Value = "";
	private:
		bool focus = false;
	};
}

#endif
