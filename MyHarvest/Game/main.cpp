
#include "../GameEngine/raylib/src/raylib.h"
#include "UI/Title/GameTitle.h";
#include "Config/ReadXMLConfig.h"
#include <iostream>


int main()
{
    typedef enum GameScene { Title, Newgame, Gameplay, Pausegame, Savegame, Ending, Error } GameScene;
    GameScene currentscene;
    ReadXMLConfig xmlconfig;
    std::map < std::string, Font> fontlist;
    if (xmlconfig.LoadConfig()) {  
        InitWindow(xmlconfig.DisplaySize.width, xmlconfig.DisplaySize.height, "MyHarvest");
        currentscene = GameScene::Title;
    }
    else {
        InitWindow(100, 100, "MyHarvest");
        currentscene = GameScene::Error;
        
    }
    std::string maintitleaudiopath = xmlconfig.AssetPath + xmlconfig.TitleConfig["Main_audiopath"];
    std::map<std::string, std::pair<std::string, float>> fontconfig = xmlconfig.FontConfigList;
    InitAudioDevice();
    Music background_music = LoadMusicStream(maintitleaudiopath.c_str());
    PlayMusicStream(background_music);
    for (std::map<std::string, std::pair<std::string, float>>::iterator it = fontconfig.begin(); it != fontconfig.end(); ++it)
        {
            std::string fontpath = xmlconfig.AssetPath + it->second.first;
            if (std::ifstream(fontpath).good()) {
                fontlist[it->first] = LoadFontEx(fontpath.c_str(), it->second.second, 0, 0);               
            } 
        }
    
   
    GameTitle gametitle(true);
    gametitle.SelectorFont = fontlist["Selector"];
    gametitle.LabelFont = fontlist["Label"];
    gametitle.TitleFont = fontlist["Title"];
    gametitle.SetSeasonsTexture(xmlconfig.SeasonsTexture);
    gametitle.Init();
   
    
  /*   
   
    game_title.SeasonsIcon = xmlconfig.SeasonsIcon;
   
                

   
    
   */
     

    SetTargetFPS(60);
   


     
    while (!WindowShouldClose())
    {
        UpdateMusicStream(background_music);
        if (currentscene == GameScene::Title) {
            gametitle.Update();
        }
        BeginDrawing();                  
        if (currentscene == GameScene::Title) {
            gametitle.Render();
        } 
        else if (currentscene == GameScene::Error) {
           ClearBackground(WHITE);
           DrawText("Error", 0, 0, 100, BLACK);
        }
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
 