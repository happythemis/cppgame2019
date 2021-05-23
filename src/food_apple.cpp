//
//  food_apple.cpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/24/19.
//

//#include "food_apple.hpp"
#include "food.hpp"

void Apple::setup(ofImage * image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = image;
    width = img->getWidth();
    height = img->getHeight();
    speed = 1;
}
void Apple::update() {
    pos.y += speed;
}
void Apple::draw() {
    img->draw(pos.x - width/2, pos.y - height/2);
}
