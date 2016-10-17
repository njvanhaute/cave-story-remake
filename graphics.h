//
//  graphics.h
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/15/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

#include <map>
#include <string>

// Graphics Class:
// Holds all information for dealing with graphics in the game.

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
    Graphics();
    ~Graphics();
    
    // SDL_Surface* loadImage
    // Loads an image into the _spriteSheets map if it doesn't already exist.
    // As a result, each image will only ever be loaded once.
    // Returns the image from the map regardless of whether or not it was just loaded.
    
    SDL_Surface* loadImage(const std::string &filePath);
    
    // void blitSurface
    // Draws a texture to a certain part of the screen.
    //
    // source specifies the sprite sheet, sourceRectangle specifies which part of the sprite
    // sheet is to be drawn, and destinationRectangle specifies which part of the screen
    // the sprite should be drawn to.
    
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
    
    // void flip
    // Renders everything to the screen.
    
    void flip();
    
    // void clear
    // Clears the screen.
    
    void clear();
    
    // SDL_Renderer* getRenderer
    // Returns the renderer so that we can use it elsewhere.
    
    SDL_Renderer* getRenderer() const;
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    
    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif /* graphics_h */
