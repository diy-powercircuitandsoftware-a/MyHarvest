#include "DrawTextList.h"

void DrawTextList::Add(TextData td)
{
	this->td.push_back(td);
}

void DrawTextList::Clear()
{
	this->td.clear();
}

std::vector<DrawTextList::TextData> DrawTextList::GetData()
{
	return this->td;
}

void DrawTextList::Update()
{
	Vector2	measuretext;	 
	for (int i = 0; i < this->td.size(); i++) {
		this->td[i].pos.x = this->accumulateposition.x;
		this->td[i].pos.y = this->accumulateposition.y;
		measuretext = MeasureTextEx(this->td[i].font, this->td[i].text.c_str(), this->td[i].font.baseSize, this->td[i].font.glyphPadding);
		if (this->updatepos == UpdatePosition::X) {
			this->accumulateposition.x = this->accumulateposition.x + measuretext.x;
		}
		else if (this->updatepos == UpdatePosition::Y) {
			this->accumulateposition.y = this->accumulateposition.y + measuretext.y;
		}
		else if (this->updatepos == UpdatePosition::ALL) {
			this->accumulateposition.x = this->accumulateposition.x + measuretext.x;
			this->accumulateposition.y = this->accumulateposition.y + measuretext.y;
		}
		this->MaxDistanceString.x = std::max(this->MaxDistanceString.x, measuretext.x);
		this->MaxDistanceString.y = std::max(this->MaxDistanceString.y, measuretext.y);
	}
	 
}

void DrawTextList::Render()
{	 
	for (int i = 0; i < this->td.size(); i++) {
		DrawTextEx(this->td[i].font, this->td[i].text.c_str(), this->td[i].pos, this->td[i].font.baseSize, this->td[i].font.glyphPadding, this->td[i].color);
	}
}

void DrawTextList::SetInitPosition(Vector2 vec)
{
	this->accumulateposition = vec;
}
void DrawTextList::SetInitPosition(float x, float y)
{
	this->accumulateposition.x=x;
	this->accumulateposition.y=y;
}

std::map<std::string, Vector2> DrawTextList::GetMapPosition()
{
	std::map<std::string, Vector2>  map;
	for (int i = 0; i < this->td.size(); i++) {
		map[this->td[i].text] = this->td[i].pos;		 
	}
	return map;
}
