#ifndef DRAWTEXTLIST_H
#define DRAWTEXTLIST_H
#include <string>
#include <vector>

#include "../../GameEngine/raylib/src/raylib.h"
#include <map>

class DrawTextList
{
public:
	typedef enum UpdatePosition { X, Y, ALL } UpdatePosition;
	typedef struct TextData
	{
		
		std::string text;
		Font f;
		float size;
		float spacing;
		Vector2 pos;
		Color col;
		TextData(std::string text, Font f, float size, float spacing, Color col) {
			this->text = text;
			this->f = f;
			this->size = size;
			this->spacing = spacing;
			this->col = col;
		}
		 
	}TextData;
	void Add(TextData td);
	void Clear();
	std::vector<TextData> GetData();
	void Update();
	void Render();
	void SetInitPosition(Vector2 vec);
	void SetInitPosition(float x, float y);
	Vector2 MaxDistanceString;
	std::map<std::string, Vector2> GetMapPosition();
	DrawTextList() {
		this->accumulateposition.x = 0;
		this->accumulateposition.y = 0;
		this->MaxDistanceString.x = 0;
		this->MaxDistanceString.y = 0;
		this->updatepos = UpdatePosition::Y;
	}
private: 
	std::vector<TextData> td;	
	Vector2 accumulateposition;
	UpdatePosition updatepos;
};
#endif
