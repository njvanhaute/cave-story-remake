//
//  player.h
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "animatedsprite.h"

class Graphics;

class Player : public AnimatedSprite {
public:
    Player();
    Player(Graphics &graphics, Vector2 spawnPoint);
    void draw(Graphics &graphics);
    void update(float elapsedTime);
    
    // void moveLeft
    // Moves the player left by dx
    
    void moveLeft();
    
    // void moveRight
    // Moves the player right by dx
    
    void moveRight();
    
    // void stopMoving
    // Stops moving the player
    
    void stopMoving();
    
    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimations();
    
    // void handleTileCollisions :
    // Determine behavior when character collides with a rectangle
    
    void handleTileCollisions(std::vector<Rectangle> &others);
    
    // Getter functions to get x and y coordinates
    
    const float getX() const;
    const float getY() const;
private:
    float _dx, _dy;
    bool _grounded; // True if standing on ground, false if not
    Direction _facing;
};

#endif /* player_h */
