# Life of CS major Student

An openframework game project depicting the life of CS student at UIUC by catching the falling objects from the top of the screen.


## Table of Contents
1. [Get Started](#get-started)
2. [About the Game](#about-the-game)
3. [Built With](#built-with)
4. [Author](#author)
5. [Acknowledgements](#acknowledgements)


Get Started
-----------
### Prerequisites
install openFrameworks

### Installing and how to start
First, clone the project in the github. It would work if you have git account inside uiuc-sp19-cs126 since it is a private git classroom.

```
$ git clone https://github.com/USERNAME/final-project-happythemis 
```
Then using the builtin project generator for the openFrameworks, create a new project for the cloned project. 

Second, check if the libraries are working well before testing the game. Although the libraries are using the openFrameworks libraries, it would be better to ckeck once more.


About the Game
--------------
Run the project with the debug.

### Overview

This game is to basically survive from each level of the game and reach until it ends. The player can level up by completing the specific amount of workload from each level. Each level, the player have to earn skills before to earn projects to level up. However, the player have to also maintain its health point(hp) level in order to survive.

### Falling Objects (features of the game)

There are three types of items falling from the top of the screen but they all have different characteristics.

1. Food 
    - There are three types of food objects which are apple, burger, and chicken. 
    - These foods are for the health point.
2. Skill
    - Each level has certain amount of skills in order to make the projecs falling from the top of the screen.
3. Project
    - Each level has certain amount of projects required to level up. 
    - ex) level 125 requires 6 projects and 126 requires 12 projects.

### How to play
 
 The game is simply catching the falling objects from the top of the screen. The player can move by pressing the a and d keys. However, the player has to catch the food items in order to survice since when hp drops down below 0, the game ends. According to the rule of game, the player needs to catch skill items and projects to level up. The last level would 498.
 
 


Built With 
---
- openFrameworks 
- c++ 

Author
----
JaeEun Themis Lee


Acknowledgements
----
⋅ https://www.fesliyanstudios.com/royalty-free-music/downloads-c/action-music/9

⋅ https://opengameart.org/

⋅ https://www.fontspace.com/category/video%20game

⋅ https://openframeworks.cc/ofBook/chapters/game_design.html : 
inspired by the usage of the vectors for the falling objects










