#ifndef PLAYER_H
#define PLAYER_H
#include "../../../GameEngine/raylib/src/raylib.h"
namespace GameObject {

class Player
{
public:

	typedef struct PlayerPosition
	{
		int id;
		int submapid;
		Vector3 pos;
	} PlayerPosition;
	typedef struct PlayerHomePosition {
		int mapid;
		int homeid;
	} PlayerHomePosition;
	 
	 
	 
	
};
}
#endif
