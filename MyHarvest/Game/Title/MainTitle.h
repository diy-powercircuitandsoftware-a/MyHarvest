class MainTitle
{
public:
	void Update();
	void Render();	
	MainTitle(int w,int h,int fontsize);
private :
	typedef enum Selector {   NEWGAME_SELECTOR, LOADGAME_SELECTOR} Selector;
	typedef enum Scene { SCENE_TITLE, SCENE_NEWGAME, SCENE_LOADGAME } Scene;
	Selector TitleSceneSelector;
	Scene scene;
};