
#include "../GameEngine/raylib/src/raylib.h"
#include "Title/GameTitle.h";
#include "Config/ReadXMLConfig.h"
#include <iostream>


int main()
{
    typedef enum GameScene { TITLE, NEWGAME, GAMEPLAY, PAUSEGAME, SAVEGAME, ENDING, ERROR } GameScene;
    GameScene current_scene;
    ReadXMLConfig xmlconfig;
    if (xmlconfig.LoadConfig()) {
        InitWindow(xmlconfig.DisplayConfig.Width, xmlconfig.DisplayConfig.Height, "MyHarvest");
        current_scene = GameScene::TITLE;
    }
    else {
        InitWindow(1024, 768, "MyHarvest");
        current_scene = GameScene::ERROR;
        
    }
    xmlconfig.UpdateFont();
    GameTitle game_title( false);
    game_title.SelectorFont = xmlconfig.SelectorFont;
    game_title.TitleFont = xmlconfig.TitleFont;
    game_title.LabelFont = xmlconfig.LabelFont;
    game_title.Init();
     InitAudioDevice();             

    Music background_music = LoadMusicStream(xmlconfig.TitleAsset.MainAudioPath.c_str());
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
 