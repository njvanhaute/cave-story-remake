//
//  player.cpp
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#include "player.h"
#include "graphics.h"

namespace player_constants {
    const float WALK_SPEED = 0.2f;
    const float GRAVITY = 0.002f;
    const float GRAVITY_CAP = 0.8f;
}

Player::Player() {
    
}

Player::Player(Graphics &graphics, Vector2 spawnPoint) :
    AnimatedSprite(graphics, "content/sprites/MyChar.png", 0, 0, 16, 16, spawnPoint.x, spawnPoint.y, 100),
    _dx(0),
    _dy(0),
    _facing(RIGHT),
    _grounded(false)
{
    graphics.loadImage("content/sprites/MyChar.png");
    setupAnimations();
    playAnimation("RunLeft");
}

void Player::setupAnimations() {
    addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0,0));
    addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0,0));
    addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0,0));
    addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0,0));
}

void Player::animationDone(std::string currentAnimation) {
    
}

const float Player::getX() const {
    return _x;
}

const float Player::getY() const {
    return _y;
}

void Player::moveLeft() {
    _dx = -player_constants::WALK_SPEED;
    playAnimation("RunLeft");
    _facing = LEFT;
}

void Player::moveRight() {
    _dx = player_constants::WALK_SPEED;
    playAnimation("RunRight");
    _facing = RIGHT;
    
}

void Player::stopMoving() {
    _dx = 0.0f;
    playAnimation(_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::handleTileCollisions(std::vector<Rectangle> &others) {
    // Determine which side the collision happened on and move the player accordingly :
    for (int i = 0; i < others.size(); i++) {
        sides::Side collisionSide = Sprite::getCollisionSide(others.at(i));
        if (collisionSide != sides::NONE) {
            switch (collisionSide) {
                case sides::TOP:
                    _y = others.at(i).getBottom() + 1;
                    _dy = 0;
                    break;
                case sides::BOTTOM:
                    _y = others.at(i).getTop() - _boundingBox.getHeight() - 1;
                    _dy = 0;
                    _grounded = true;
                    break;
                case sides::LEFT:
                    _x = others.at(i).getRight() + 1;
                    _dx = 0;
                    break;
                case sides::RIGHT:
                    _x = others.at(i).getLeft() - _boundingBox.getWidth() - 1;
                    _dx = 0;
                    break;
                case sides::NONE:
                    return;
                    break;
            }
        }
    }
}

void Player::update(float elapsedTime) {
    // Apply gravity:
    if (_dy <= player_constants::GRAVITY_CAP) {
        // If player has not yet reached terminal velocity, increase falling speed.
        _dy += player_constants::GRAVITY * elapsedTime;
    }
    
    // Move by _dx
    _x += _dx * elapsedTime;
    
    // Move by _dx
    _y += _dy * elapsedTime;
    
    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
    AnimatedSprite::draw(graphics, _x, _y);
}
