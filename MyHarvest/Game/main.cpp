
#include "../GameEngine/raylib/src/raylib.h"
#include "Title/MainTitle.h"
#include "FilesManager/FilesManager.h"
typedef enum GameScreen { TITLE,NEWGAME, GAMEPLAY, PAUSEGAME,SAVEGAME, ENDING } GameScreen;

int main()
{
     
     int screen_fontsize=14 ;
    GameScreen current_screen = TITLE;
    FilesManager file_manager;
    if (file_manager.HadConfig()) {
       // screen_width = 800;
        //screen_height = 600;
        //screen_fontsize = 14;
        InitWindow(0, 0, "MyHarvest");
    }
    else {
        InitWindow(0, 0, "MyHarvest");
        ToggleFullscreen();
    }
     
    
    MainTitle main_title(GetScreenWidth(), GetScreenHeight(), screen_fontsize);
    


    SetTargetFPS(60);
   


   
    while (!WindowShouldClose())
    {


        if (current_screen == GameScreen::TITLE) {
            main_title.Update();
        }


        BeginDrawing();

        
        if (current_screen == GameScreen::TITLE) {
            main_title.Render();
        }
       

        EndDrawing();

    }

    CloseWindow();
    return 0;
}
 