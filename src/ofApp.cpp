#include "ofApp.h"
#include "player.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    start_time = 0;
    end_game = false;
    video.load("IMG_0120.mov");
    endscreen.load("endgame.jpg");
    controller.setup(ofGetElapsedTimeMillis());
    current_progress = 0;
    score = 125;
    health_point = 0;
    skill_point = 0;
    num_of_projects = 0;
    player_image.load("pac1.png");
    player_image.resize(90, 90);
    p.setup(&player_image);
    burger_image.load("burger.png");
    burger_image.resize(90, 90);
    apple_image.load("apple.png");
    apple_image.resize(90, 90);
    chicken_image.load("chicken.png");
    chicken_image.resize(90, 90);
    skill_image.load("book.png");
    skill_image.resize(90, 90);
    project_image.load("folderfile.png");
    project_image.resize(100, 100);
    mySound.load("Crazy_Drummer.mp3");
    mySound.setVolume(0.1);
    mySound.play();
    ofBackground(0,0,0);
    score_font.load("SNES Italic.ttf", 20);
    hp_font.load("SNES Italic.ttf", 20);
    skill_font.load("SNES Italic.ttf", 20);
    num_of_projects_font.load("SNES Italic.ttf", 20);
    reach_num_pro_font.load("good times rg.ttf", 20);
    ending_font.load("SNES Italic.ttf", 50);
    ending_font_redo.load("SNES Italic.ttf", 50);
    ending_credit.load("SNES Italic.ttf", 80);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (health_point >= 0) {
        if (score == 498 && num_of_projects >= 70) {
            end_game = true;
            burgers.clear();
            apples.clear();
            chicken.clear();
            skills.clear();
            projects.clear();
            video.update();
            video.play();
            mySound.stop();
        } else {
            checkBurgerCollisions();
            checkSkillCollisions();
            checkChickenCollisions();
            checkAppleCollisions();
            checkProjectlCollisions();
            update_stage(num_of_projects);
            
            for (int i = 0; i < burgers.size(); i++) {
                burgers[i].update();
            }
            for (int i = 0; i < apples.size(); i++) {
                apples[i].update();
            }
            for (int i = 0; i < chicken.size(); i++) {
                chicken[i].update();
            }
            for (int i = 0; i < skills.size(); i++) {
                skills[i].update();
            }
            for (int i = 0; i < projects.size(); i++) {
                projects[i].update();
            }
            
            if (controller.controll_hp() && checkStartColl) {
                if ((ofGetElapsedTimeMillis() - start_time) > 10000) {
                    controll_decrease_hp(score);
                }
            }
            
            if (controller.generate() == 0) {
                Apple a;
                a.setup(&apple_image);
                apples.push_back(a);
                
                Skill s;
                s.setup(&skill_image);
                skills.push_back(s);
            } else if (controller.generate() == 1) {
                Burger e;
                e.setup(&burger_image);
                burgers.push_back(e);
                
                Chicken c;
                c.setup(&chicken_image);
                chicken.push_back(c);
            } else if (controller.generate() == 2) {
                if ((score == 125 && skill_point >= 200) || (score == 126 && skill_point >= 500)
                        || (score == 225 && skill_point >= 800) || (score == 233 && skill_point >= 1200)
                        || (score == 374 && skill_point >= 1700) ||  (score == 400 && skill_point >= 2500)
                        ||  (score == 498 && skill_point >= 4000)) {
                    Project pr;
                    pr.setup(&project_image);
                    projects.push_back(pr);
                }
            }
        }
    } else {
        mySound.stop();
        end_game = true;
        burgers.clear();
        apples.clear();
        chicken.clear();
        skills.clear();
        projects.clear();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (health_point >= 0) {
        if (score == 498 && num_of_projects >= 70) {
            video.draw(ofGetWidth() / 2 - (video.getWidth() / 6), ofGetHeight() / 2,
                       video.getWidth() / 3 , video.getHeight() / 3);
            ending_font.drawString("GAME SUCCESS", ofGetWidth() / 2 - 300, ofGetHeight() - 200);
            ending_credit.drawString("ENJOY THE QUAD", 100, 100);
            ending_font_redo.drawString("Try Again? Enter 'R'", ofGetWidth() / 2, 500);
        } else {
            p.draw();
            for (int i = 0; i < burgers.size(); i++) {
                burgers[i].draw();
            }
            for (int i = 0; i < apples.size(); i++) {
                apples[i].draw();
            }
            for (int i = 0; i < chicken.size(); i++) {
                chicken[i].draw();
            }
            for (int i = 0; i < skills.size(); i++) {
                skills[i].draw();
            }
            for (int i = 0; i < projects.size(); i++) {
                projects[i].draw();
            }
            draw_score();
            draw_skill_point();
            draw_health_point();
            draw_num_of_projects();
        }
    } else {
        end_game = true;
        endscreen.draw(ofGetWidth() / 2 - endscreen.getWidth() / 2, ofGetHeight() / 2 - endscreen.getHeight() / 2);
        ending_font.drawString("GAME FAIL", ofGetWidth() / 2 - 300, ofGetHeight() - 200);
        ending_font_redo.drawString("STILL IN THE END GAME \n Try Again? Enter 'R'", 100, 250);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (end_game) {
        if (key == 'r') {
            current_progress = 0;
            health_point = 0;
            score = 125;
            skill_point = 0;
            num_of_projects = 0;
            end_game = false;
            start_time = ofGetElapsedTimeMillis();
            controller.setup(start_time);
            p.setup(&player_image);
            mySound.play();
            mySound.setVolume(0.1);
        }
    } else {
        int step;
        switch (score) {
            case 125:
            case 126:
                step = 40;
                break;
            case 225:
            case 233:
                step = 60;
                break;
            case 241:
            case 374:
                step = 70;
                break;
            case 400:
            case 498:
                step = 80;
                break;
        }
        p.update(key, step);
    }
}
//--------------------------------------------------------------
bool ofApp::checkBurgerCollisions() {
    for (int i = 0; i < burgers.size(); i++) {
        if (ofDist(burgers[i].pos.x, burgers[i].pos.y, p.pos.x, p.pos.y) < (50)) {
            if (burgers[i].pos.y == ofGetHeight() - 20) {
                health_point += 10;
                checkStartColl = true;
                burgers.erase(burgers.begin() + i);
                return true;
            }
        }
    }
    return false;
}
//--------------------------------------------------------------
bool ofApp::checkAppleCollisions() {
    for (int i = 0; i < apples.size(); i++) {
        if (ofDist(apples[i].pos.x, apples[i].pos.y, p.pos.x, p.pos.y) < (50)) {
            if (apples[i].pos.y == ofGetHeight() - 20) {
                health_point += 3;
                checkStartColl = true;
                apples.erase(apples.begin() + i);
                return true;
            }
        }
    }
    return false;
}
//--------------------------------------------------------------
bool ofApp::checkChickenCollisions() {
    for (int i = 0; i < chicken.size(); i++) {
        if (ofDist(chicken[i].pos.x, chicken[i].pos.y, p.pos.x, p.pos.y) < (50)) {
            if (chicken[i].pos.y == ofGetHeight() - 45) {
                health_point += 5;
                checkStartColl = true;
                chicken.erase(chicken.begin() + i);
                return true;
            }
        }
    }
    return false;
}
//--------------------------------------------------------------
bool ofApp::checkSkillCollisions() {
    for (int i = 0; i < skills.size(); i++) {
        if (ofDist(skills[i].pos.x, skills[i].pos.y, p.pos.x, p.pos.y) < (50)) {
            if (skills[i].pos.y == ofGetHeight() - 20) {
                skill_point += 20;
                checkStartColl = true;
                skills.erase(skills.begin() + i);
                return true;
            }
        }
    }
    return false;
}
//--------------------------------------------------------------
bool ofApp::checkProjectlCollisions() {
    for (int i = 0; i < projects.size(); i++) {
        if (ofDist(projects[i].pos.x, projects[i].pos.y, p.pos.x, p.pos.y) < (50)) {
            if (projects[i].pos.y == ofGetHeight() - 20) {
                if ((score == 125 && skill_point >= 200) || (score == 126 && skill_point >= 500)
                    || (score == 225 && skill_point >= 800) || (score == 233 && skill_point >= 1200)
                    || (score == 374 && skill_point >= 1700) ||  (score == 400 && skill_point >= 2500)
                    ||  (score == 498 && skill_point >= 4000)) {
                    num_of_projects++;
                    checkStartColl = true;
                    projects.erase(projects.begin() + i);
                    return true;
                }
            }
        }
    }
    return false;
}
//--------------------------------------------------------------
void ofApp::draw_score() {
    score_font.drawString("STAGE\t\t" + ofToString(score), 30, 52);
}
//--------------------------------------------------------------
void ofApp::draw_health_point() {
    hp_font.drawString("HP\t\t\t" + ofToString(health_point), 30, 72);
}
//--------------------------------------------------------------
void ofApp::draw_skill_point() {
    skill_font.drawString("SKILL\t\t" + ofToString(skill_point), 30, 92);
}
//--------------------------------------------------------------
void ofApp::draw_num_of_projects() {
    reach_num_pro_font.drawString("/", 118, 112);
    switch (score) {
        case 125:
            num_of_projects_font.drawString("PROJECT\t" + ofToString(num_of_projects) + "\t 6", 30, 112);
            break;
        case 126:
            num_of_projects_font.drawString("PROJECT\t" + ofToString(num_of_projects) + "\t 12", 30, 112);
            break;
        case 225:
            num_of_projects_font.drawString("PROJECT\t" + ofToString(num_of_projects) + "\t 20", 30, 112);
            break;
        case 233:
            num_of_projects_font.drawString("PROJECT\t" + ofToString(num_of_projects) + "\t 30", 30, 112);
            break;
        case 241:
            num_of_projects_font.drawString("PROJECT\t" + ofToString(num_of_projects) + "\t 40", 30, 112);
            break;
        case 374:
            num_of_projects_font.drawString("PROJECT\t" + ofToString(num_of_projects) + "\t 52", 30, 112);
            break;
        case 400:
            num_of_projects_font.drawString("PROJECT\t" + ofToString(num_of_projects) + "\t 60", 30, 112);
            break;
        case 498:
            num_of_projects_font.drawString("PROJECT" + ofToString(num_of_projects) + "\t 70", 30, 112);
            break;
    }
}
//--------------------------------------------------------------
void ofApp::update_stage(int num_of_projects) {
    switch (num_of_projects) {
        case 7:
            score = 126;
            break;
        case 13:
            score = 225;
            break;
        case 21:
            score = 233;
            break;
        case 31:
            score = 241;
            break;
        case 41:
            score = 374;
            break;
        case 53:
            score = 400;
            break;
        case 61:
            score = 498;
            break;
    }
}
//--------------------------------------------------------------
void ofApp::controll_decrease_hp(int score) {
    switch (score) {
        case 125:
        case 126:
            health_point--;
            break;
        case 225:
        case 233:
            health_point-=2;
            break;
        case 241:
        case 374:
            health_point-=3;
            break;
        case 400:
        case 498:
            health_point-=5;
            break;
    }
}
