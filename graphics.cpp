//
//  graphics.cpp
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/15/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "graphics.h"
#include "globals.h"

// Graphics Class:
// Holds all information for dealing with graphics in the game.

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &_window, &_renderer);
    SDL_SetWindowTitle(_window, "Cave Story Remake");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
    if (_spriteSheets.count(filePath) == 0) {
        _spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return _spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(_renderer, source, sourceRectangle, destinationRectangle);
    
}

void Graphics::flip() {
    SDL_RenderPresent(_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return _renderer;
}
