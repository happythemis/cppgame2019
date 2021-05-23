//
//  food_chicken.cpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/24/19.
//

//#include "food_chicken.hpp"

#include "food.hpp"

void Chicken::setup(ofImage * image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = image;
    width = img->getWidth();
    height = img->getHeight();
    speed = 0.25;
}
void Chicken::update() {
    pos.y += speed;
}
void Chicken::draw() {
    img->draw(pos.x - width/2, pos.y - height/2);
}
