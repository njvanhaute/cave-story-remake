//
//  game.cpp
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/15/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include <SDL2/SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}
// Game Class:
// Holds all the information for the main game loop.

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    gameLoop();
}

Game::~Game() {
    
}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;
    
    int LAST_UPDATE_TIME = SDL_GetTicks();
    // Start game loop
    while (true) {
        input.beginNewFrame(); // Resets pressed/released/held keys
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) { // Makes sure that you aren't holding down a key
                    input.keyDownEvent(event);
                }
            }
            else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
            else if (event.type == SDL_QUIT) {
                return;
            }
        }
        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
            return;
        }
        // Calculates how long the current frame took.
        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        // If frame took more than max time, use max time. Limits game to 50 fps
        // Physics is based on how long the frame took, so it's necessary to limit it.
        LAST_UPDATE_TIME = CURRENT_TIME_MS;
    }
}

void Game::draw(Graphics &graphics) {
    
}

void Game::update(float elapsedTime) {
    
}
