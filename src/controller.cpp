//
//  controller.cpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/17/19.
//

#include "controller.hpp"
int KNUMBER_TWO = 2;
void Controller::setup(float s) {
    current_time = s;
}
int Controller::generate() {
    if (ofGetElapsedTimeMillis() % interval_time == 0){
        current_time = ofGetElapsedTimeMillis();
        return 0;
    } else if (ofGetElapsedTimeMillis() % interval_time_two == 0) {
        current_time = ofGetElapsedTimeMillis();
        return 1;
    } else if (ofGetElapsedTimeMillis() % interval_time_three == 0) {
        current_time = ofGetElapsedTimeMillis();
        return KNUMBER_TWO;
    }
    return -1;
}
bool Controller::controll_hp() {
    if (ofGetElapsedTimeMillis() % interval_time == 0 ) {
        return true;
    }
    return false;
}

