#ifndef CONTROLS_DROPDOWNBOX_H
#define CONTROLS_DROPDOWNBOX_H
#include "../../../GameEngine/raylib/src/raylib.h"
#include <string>
#include <map>
#include <vector>
namespace Controls {
	class DropDownBox
	{
	public:
		
		typedef enum Alignment { Left, Center, Right } Alignment;		 
		DropDownBox();
		DropDownBox(Rectangle rect);
		Color BackgroundColor = WHITE;
		Color BorderColor = BLACK;
		Color TextColor = BLACK;
		int BorderSize = 1;
		Font Font = GetFontDefault();
		int MaxLength = 12;		
		Rectangle Position;
		void AddList(int id, std::string value);
		void Render();
		int ReadOnly = false;
		Alignment TextAlignment = Alignment::Left;
		int Value;
	private:
		typedef struct DropDownList
		{
			int id;
			std::string s;
			Rectangle position;
		} DropDownList;
		std::vector<DropDownList> list;
		DropDownList selectedvalue;
		bool togglelist = false;
		
	};
}
#endif