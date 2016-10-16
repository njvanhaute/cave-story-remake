//
//  animatedsprite.h
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

// AnimatedSprite Class:
// Holds logic for animating sprites

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate);
    
    // void playAnimation
    // Plays specified animation provided if not already playing. Optional boolean argument
    
    void playAnimation(std::string animation, bool once = false);
    
    // void update
    // Updates the animated sprite with a timer
    
    void update(int elapsedTime);
    
    // void draw
    // Draws the sprite to the screen
    
    void draw(Graphics &graphics, int x, int y);
    
    // virtual void setupAnimations
    // A required function that sets up all animations for a sprite
    
    virtual void setupAnimations();
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;
    
    // void addAnimation
    // Adds animation to the map of animations for the sprite
    
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
    
    // void resetAnimations
    // Clears all animations from the std::map _animations
    
    void resetAnimations();
    
    // void stopAnimation
    // Stops the current animation
    
    void stopAnimation();
    
    // void setVisible
    // Changes the visibility of the animated sprite
    
    void setVisible(bool visible);
    
    // virtual void animationDone
    // Logic that occurs when an animation ends
    
    virtual void animationDone(std::string currentAnimation);
private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;
    
    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};


#endif /* animatedsprite_h */
