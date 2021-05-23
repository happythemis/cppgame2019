#pragma once
#include <cmath>
#include "ofMain.h"
#include "ofImage.h"
#include "ofSoundPlayer.h"
#include "ofxGui.h"
#include "ofVec3f.h"
#include "player.hpp"
#include "controller.hpp"
#include "food.hpp"
#include "skill.hpp"
#include "project.hpp"


class ofApp : public ofBaseApp{
	public:
    float start_time;
    int current_progress;
    int score, health_point, skill_point, num_of_projects;
    bool end_game;
    ofImage image;
    ofImage endscreen;
    ofPoint myMouse;
    ofTrueTypeFont ending_font;
    ofTrueTypeFont ending_credit;
    ofTrueTypeFont ending_font_redo;
    ofTrueTypeFont score_font;
    ofTrueTypeFont hp_font;
    ofTrueTypeFont skill_font;
    ofTrueTypeFont num_of_projects_font, reach_num_pro_font;
    bool checkStartColl = false;
    Controller controller;
    ofImage player_image;
    Player p;
    ofImage burger_image;
    vector<Burger> burgers;
    ofImage apple_image;
    vector<Apple> apples;
    ofImage chicken_image;
    vector<Chicken> chicken;
    ofImage skill_image;
    vector<Skill> skills;
    ofImage project_image;
    vector<Project> projects;
    ofSoundPlayer mySound;
    ofVideoPlayer video;
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void handleKey(int key, bool value);
    bool checkBurgerCollisions();
    bool checkAppleCollisions();
    bool checkChickenCollisions();
    bool checkSkillCollisions();
    bool checkProjectlCollisions();
    void draw_score();
    void draw_health_point();
    void draw_skill_point();
    void draw_num_of_projects();
    void update_stage(int num_of_projects);
    void controll_decrease_hp(int score);
};
