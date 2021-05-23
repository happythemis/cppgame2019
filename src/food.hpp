//
//  food.hpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/26/19.
//

#ifndef food_hpp
#define food_hpp

#include <stdio.h>
#include "ofMain.h"

class Burger {
public:
    ofPoint pos;
    ofImage * img;
    float speed, height, width;
    void setup(ofImage * image);
    void update();
    void draw();
};

class Apple {
public:
    ofPoint pos;
    ofImage * img;
    float speed, height, width;
    void setup(ofImage * image);
    void update();
    void draw();
};

class Chicken {
public:
    ofPoint pos;
    ofImage * img;
    float speed, height, width;
    void setup(ofImage * image);
    void update();
    void draw();
};
#endif /* food_hpp */
