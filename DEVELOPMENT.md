week1 
--------
testing basic functions from the libraries
* sound - use the background music
* graphics - load the image
* util - laod the time/timer using gui(this will not be in the later version of the project) *it is just for the testing*
------------

week2
-----------
* created player class on a progress in designing the movement
* try to load image and make an object for the bullet and player
* keep finding way to randomly generate the falling objects..
    -> may use box2D for the physics...
    ->will not use box2d : instead using vector and random
* made the temporary player shape obejct that can move along the bottom of the screen 
* movement of the image falling is now possible using the vectors and random.
* created controller class to controll the falling objects
    -> it is not working well currently since it is generating too much objects.
        - need to work more on the controller

------------

week3
-----------
    --------
    04.21.2019
    --------
    * update the background music volume to make it easier for me to work since I need to run the game every time I update.
    * update enemy to fall straight forward from the top of the screen
    * checked the method ofGetElapsedTimeMillis 
    
    --------
    04.22.2019
    --------
    * edit method to update every millisecond with interval time to spawn the objects on time...but still need to work on more after I add more falling objects.
    * created the score and load on the screen which updates every time it updates the score.
    * checked the method ofGetElapsedTimeMillis 
    
    --------
    04.23.2019
    --------
    * make the collision check possible and updated the score when they collides.
        - beleive the collision needs to be improved
    
    --------
    04.24.2019
    --------
    * changed the name of the enemy file and class into food_burger and Burger. 
    * created one more falling objects: food_apple and updated the ofApp to according changes.
    * changed the background color into black.
        

------------

week 4
-----------
    ------
    04.26.2019
    -----
    * created the food_chicken class to generate more falling food objects
    * added food_hpp_~ files into one food.hpp file in order to make it easier to controll since they are the same functions except for the name change
    * updated the ofApp according to all the changes on 26th

    -----
    04.29.2019
    -----
    * first clean up the files by deleting all the unused codes
    * update the health and skill classes : the score for the health point and the skill point is now available on the game screen
    * change the size of all the falling food objects
    * since the score and points string fonts are not in the same indent, update fonts by moving the position and add the description of each numbers what they are meaning like SCORE, HP...
    * add controll_hp method to controller and ofApp file to control the health point and decrease the hp according to the elapsed time
    * updated the ofApp to load the project score on the screen 
    * change the speed of the falling objects 
    * change the controller to fix the bug that generates lots of falling objects at the beginning by moving the method into teh ofApp: setup
    * corrected the position of the falling to draw in the center of its current location
    * since the player was simply the circle object by drawCircle, update the circle player into image for better quality of the game
    * changed the speed of the falling objects and load the project score on the screen and update the score for every collision
    -----
    04.30.2019
    -----
    * update gernerate method in the controller
    * created the test files using catch but since the project is focusing on the visualization using OF methods and libraries, the tests were just two test cases for the inner helper functions
        before making tests, change the helper methods to functions with parameters to be able to test with.
        - update_stage
        - controll_decrease_hp
    * created the ending screen for the final level and the game over screen in to ofApp.
        - the final level ending screen would be as the video of the quad and the game over screen would be endgame poster screen
    * update controller to return int to generate falling objects according to the time for the difficulty of the time
    * add the starting time in the ofApp so it could re-calculate the time although it has restarted the game. And added the string to show the ending explanation for the game if the user wants to restart the game or not.

