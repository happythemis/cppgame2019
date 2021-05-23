//
//  player.hpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/11/19.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "ofMain.h"

class Player {
public:
    ofPoint pos;
    ofImage * img;
    float speed, height, width;
    void setup(ofImage * image);
    void update(int key, int step);
    void draw();
};

#endif /* player_hpp */
