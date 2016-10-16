//
//  globals.h
//  CaveStoryRemade
//
//  Created by Nicholas Vanhaute on 10/16/16.
//  Copyright © 2016 Nicholas Vanhaute. All rights reserved.
//

#ifndef GLOBALS_H
#define GLOBALS_H

// Prevents access to variables unless prefixed with "globals::"

namespace globals {
    const int SCREEN_WIDTH  = 640;
    const int SCREEN_HEIGHT = 480;
    const int SPRITE_SCALE = 2;
}

struct Vector2 {
    int x;
    int y;
    Vector2() :
        x(0), y(0)
    {}
    Vector2(int x, int y) :
        x(x), y(y)
    {}
    Vector2 zero() {
        return Vector2(0, 0);
    }
};

#endif /* globals_h */
