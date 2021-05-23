//
//  project.cpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/26/19.
//

#include "project.hpp"

void Project::setup(ofImage * image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = image;
    width = img->getWidth();
    height = img->getHeight();
    speed = 1;
}
void Project::update() {
    pos.y += speed;
}
void Project::draw() {
    img->draw(pos.x - width/2, pos.y - height/2);
}

