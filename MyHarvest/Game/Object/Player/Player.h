#ifndef PLAYER_H
#define PLAYER_H
#include "../../../GameEngine/raylib/src/raylib.h"
class Player
{
public:
	typedef enum  Gender { MAN ,WOMAN ,LGBTQ } Gender;
	struct Map
	{
		int id;
		int submapid;
		Vector3 pos;
	};
	const char* name = "";
	char* born;
	Gender gender;
	Map map;
	
};

#endif
