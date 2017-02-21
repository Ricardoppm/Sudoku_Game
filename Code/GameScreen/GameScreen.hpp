//
//  GameScreen.hpp
//  Sudoku_Game
//
//  Created by Ricardo Martins on 18/02/2017.
//  Copyright © 2017 Ricardo Martins. All rights reserved.
//

#ifndef GameScreen_hpp
#define GameScreen_hpp

#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>


#include "Window.hpp"
#include "Sudoku.hpp"
#include "RectButton.hpp"
#include "SelectorButton.hpp"
#include "Font.hpp"

#define MAX_HINTS 3

class GameScreen
{
    public:
        GameScreen(int windowWidth, int windowHeight);

        // Initialize Screen
        bool init();

        // Start Screen Functions
        void start();
    
    
    protected:
        // Load Screen Buttons
        virtual bool loadButtons();
    
        //Process Handlers
        virtual bool processHandlers();
    
        // Render screen
        virtual void render();
    
        // Proccess Difficulty picker input
        bool loadPickedPuzzle( int difficulty);


    private:
        // Screen Size
        int windowWidth_;
        int windowHeight_;
    
        // Window variable
        Window* window_=nullptr;
    
        // Screen Renderer
        SDL_Renderer* renderer_ = nullptr;
    
        //TTF font
        Font* font_ = nullptr;
    
        // List of Buttons
        std::vector<Button*> listButtons;

        // List of Handlers (event tracker)
        std::queue<Handler> handlerQueue_;
    
        //Sudoku game
        Sudoku* sudoku_ = nullptr;
    
        // Bool indicates if initiated correctly
        bool hasInitiated=false;
    
        //Verify Mode active
        bool isVerify_ = false;
    
        // Board is completed and correct
        bool isFinished = false;
    
        // Puzzle Picking Variables
        bool isPlaying_ = false;           // User is Playing Puzzle
        Texture* pickingText_ = nullptr; // Texture with text for picking
        std::vector<Button*> difficultyPickerButtons_;  // list with buttons for difficulty picking
        int buttonWidth_ = 80;  // Button Width
        int buttonHeight_ = 35;  // Button Height
        SDL_Color textColor_ = { 0, 0, 0, 0xFF }; // text color
        enum Difficulty { DIFFICULTY_EASY, DIFFICULTY_MEDIUM, DIFFICULTY_HARD, DIFFICULTY_VERYHEARD, DIFFICULTY_CUSTOM};
    
        // Sudoku File Name
        std::string filename_ = "Puzzles/Hard/hard3.txt";
    
        // Number of available hints
        int hintNo = MAX_HINTS;
};

#endif /* GameScreen_hpp */
