//
//  level.cpp
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "level.h"
#include "graphics.h"
#include "globals.h"

#include <SDL2/SDL.h>

Level::Level() {
    
}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) : _mapName(mapName),
_spawnPoint(spawnPoint),
_size(Vector2(0, 0))
{
    loadMap(mapName, graphics);
}

Level::~Level() {
    
}

void Level::loadMap(std::string mapName, Graphics &graphics) {
    // TEMPORARY CODE TO LOAD THE BACKGROUND
    _backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
        graphics.loadImage("content/backgrounds/bkBlue.png"));
    _size = Vector2(1280, 960);
}

void Level::update(int elapsedTime) {
    
}

void Level::draw(Graphics &graphics) {
    // Draw the background
    SDL_Rect sourceRect = {0, 0, 64 ,64};
    SDL_Rect destRect;
    for (int x = 0; x < _size.x / 64; x++) {
        for (int y = 0; y < _size.y / 64; y++) {
            destRect.x = x * 64 * globals::SPRITE_SCALE;
            destRect.y = y * 64 * globals::SPRITE_SCALE;
            destRect.w = 64 * globals::SPRITE_SCALE;
            destRect.h = 64 * globals::SPRITE_SCALE;
            graphics.blitSurface(_backgroundTexture, &sourceRect, &destRect);
        }
        
    }
}
