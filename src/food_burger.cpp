//
//  food_burger.cpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/17/19.
//

//#include "food_burger.hpp"
#include "food.hpp"

void Burger::setup(ofImage * image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = image;
    width = img->getWidth();
    height = img->getHeight();
    speed = 0.5;
}
void Burger::update() {
    pos.y += speed;
}
void Burger::draw() {
    img->draw(pos.x - width/2, pos.y - height/2);
}
