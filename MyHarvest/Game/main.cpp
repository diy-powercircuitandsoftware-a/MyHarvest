
#include "../GameEngine/raylib/src/raylib.h"
#include "Title/GameTitle.h";
#include "FilesManager/FilesManager.h"
#include <iostream>
//https://unityinsight.wordpress.com/unity-dictionary/

int main()
{
    typedef enum GameScene { TITLE, NEWGAME, GAMEPLAY, PAUSEGAME, SAVEGAME, ENDING, ERROR } GameScene;
    GameScene current_scene;
    FilesManager file_manager;
    if (file_manager.LoadConfig()) {
        InitWindow(file_manager.DisplayConfig.Width, file_manager.DisplayConfig.Height, "MyHarvest");
        current_scene = GameScene::TITLE;
    }
    else {
        InitWindow(1024, 768, "MyHarvest");
        current_scene = GameScene::ERROR;
        
    }
    GameTitle game_title(GetScreenWidth(), GetScreenHeight(), file_manager.HadSaveGame());
    game_title.SelectorFont = file_manager.SelectorFont;
    game_title.Init();
     InitAudioDevice();             

     Music background_music = LoadMusicStream("a.mp3");
    PlayMusicStream(background_music);
    
   


    SetTargetFPS(60);
   


     
    while (!WindowShouldClose())
    {
        UpdateMusicStream(background_music);


        if (current_scene == GameScene::TITLE) {
            game_title.Update();
        }

       
        BeginDrawing();
        
       
       if (current_scene == GameScene::TITLE) {
           game_title.Render();
        } 
      else if (current_scene == GameScene::ERROR) {
           ClearBackground(WHITE);
           DrawText("Error", 0, 0, 100, BLACK);
       }
            
       

         EndDrawing();

    }

    CloseWindow();
    return 0;
}
 