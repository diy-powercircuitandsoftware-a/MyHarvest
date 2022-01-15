
#include "../GameEngine/raylib/src/raylib.h"
#include "Title/MainTitle.h"
#include "FilesManager/FilesManager.h"
#include <iostream>
//GetFontDefault().baseSize
typedef enum GameScreen { TITLE,NEWGAME, GAMEPLAY, PAUSEGAME,SAVEGAME, ENDING,ERROR } GameScreen;

int main()
{
     
     int screen_fontsize=14 ;
    GameScreen current_screen ;
    FilesManager file_manager;
    if (file_manager.HadConfig()) {
        file_manager.LoadConfig();
        screen_fontsize= file_manager.displayconfig.FontSize;      
        InitWindow(file_manager.displayconfig.Width, file_manager.displayconfig.Height, "MyHarvest");
        current_screen = GameScreen::TITLE;
    }
    else {
        InitWindow(1024, 768, "MyHarvest");
        current_screen = GameScreen::ERROR;
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
 