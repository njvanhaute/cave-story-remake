//
//  graphics.cpp
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/15/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include <SDL2/SDL.h>
#include "graphics.h"

// Graphics Class:
// Holds all information for dealing with graphics in the game.

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_renderer);
    SDL_SetWindowTitle(_window, "Cave Story Remake");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(_window);
}
