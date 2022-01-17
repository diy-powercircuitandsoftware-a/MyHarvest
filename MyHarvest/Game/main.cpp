
#include "../GameEngine/raylib/src/raylib.h"
#include "Title/GameTitle.h";
#include "FilesManager/FilesManager.h"
#include <iostream>
//https://unityinsight.wordpress.com/unity-dictionary/

int main()
{
    typedef enum GameScene { TITLE, NEWGAME, GAMEPLAY, PAUSEGAME, SAVEGAME, ENDING, ERROR } GameScene;
    GameScene current_screen ;
    FilesManager file_manager;
    if (file_manager.LoadConfig()) {
        InitWindow(file_manager.displayconfig.Width, file_manager.displayconfig.Height, "MyHarvest");
        current_screen = GameScene::TITLE;
    }
    else {
        InitWindow(1024, 768, "MyHarvest");
        current_screen = GameScene::ERROR;
    }
  //  InitAudioDevice();             

  //  Music music = LoadMusicStream("test.mp3");

   // PlayMusicStream(music);
    
    GameTitle game_title(GetScreenWidth(), GetScreenHeight(),  file_manager.LoadSaveGame());
    


    SetTargetFPS(60);
   


   
    while (!WindowShouldClose())
    {
       // UpdateMusicStream(music);


       /* if (current_screen == GameScene::TITLE) {
            game_title.Update();
        }*/

       
        BeginDrawing();

       
        if (current_screen == GameScene::TITLE) {
            game_title.Render();
        }
       

        EndDrawing();

    }

    CloseWindow();
    return 0;
}
 