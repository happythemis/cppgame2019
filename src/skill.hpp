//
//  skill.hpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/26/19.
//

#ifndef skill_hpp
#define skill_hpp

#include <stdio.h>
#include "ofMain.h"

class Skill {
public:
    ofPoint pos;
    ofImage * img;
    float speed, height, width;
    void setup(ofImage * image);
    void update();
    void draw();
};

#endif /* skill_hpp */
