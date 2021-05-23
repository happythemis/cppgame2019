//
//  player.cpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/11/19.
//

#include "player.hpp"
void Player::setup(ofImage * image) {
    pos.x = 0;
    pos.y = ofGetHeight();
    img = image;
    width = img->getWidth();
    height = img->getHeight();
}
void Player::update(int key, int step) {
    if(key == 'a') pos.x = pos.x - step;
    if(key == 'd') pos.x = pos.x + step;
}

void Player::draw() {
    img->draw(pos.x - width/2, pos.y - height);
}

