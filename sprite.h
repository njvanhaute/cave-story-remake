//
//  sprite.h
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>

class Graphics;

// Sprite Class:
// Holds all information for individual sprites.

class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;
    
    float _x, _y;
private:
};

#endif /* sprite_h */
