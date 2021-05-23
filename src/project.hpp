//
//  project.hpp
//  finalproject-happythemis
//
//  Created by JaeEun Lee on 4/26/19.
//

#ifndef project_hpp
#define project_hpp

#include <stdio.h>
#include "ofMain.h"

class Project {
public:
    ofPoint pos;
    ofImage * img;
    float speed, height, width;
    void setup(ofImage * image);
    void update();
    void draw();
};
#endif /* project_hpp */
