//
//  skill.cpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/26/19.
//

#include "skill.hpp"

void Skill::setup(ofImage * image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = image;
    width = img->getWidth();
    height = img->getHeight();
    speed = 0.5;
}
void Skill::update() {
    pos.y += speed;
}
void Skill::draw() {
    img->draw(pos.x - width/2, pos.y - height/2);
}


