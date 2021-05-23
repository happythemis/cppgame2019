//
//  controller.hpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/17/19.
//

#ifndef controller_hpp
#define controller_hpp

#include <stdio.h>
#include "ofMain.h"
class Controller {
public:
    float current_time;
    int interval_time = 300;
    int interval_time_two = 500;
    int interval_time_three = 200;
    void setup(float e);
    int generate();
    bool controll_hp();
    
};

#endif /* controller_hpp */
