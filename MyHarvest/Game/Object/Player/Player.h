#ifndef PLAYER_H
#define PLAYER_H
#include "../../../GameEngine/raylib/src/raylib.h"
class Player
{
public:
	typedef enum  GameGender { MAN ,WOMAN , GAY,LESBIAN, BISEXUAL} GameGender;
	typedef struct GameMap
	{
		int id;
		int submapid;
		Vector3 pos;
	} GameMap;
	typedef struct GameHome {
		int mapid;
		int homeid;
	} GameHome;
	const char* name = "";
	char* born;
	 
	 
	
};

#endif
