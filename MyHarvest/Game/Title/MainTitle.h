class MainTitle
{
public:
	MainTitle(int w, int h, int fontsize);
	void Update();
	void Render();	
private :
	typedef enum Selector {   NEWGAME_SELECTOR, LOADGAME_SELECTOR} Selector;
	typedef enum Scene { SCENE_TITLE, SCENE_NEWGAME, SCENE_LOADGAME } Scene;
	Selector TitleSceneSelector;
	Scene scene;
	int w; 
	int h; 
	int fontsize;
};