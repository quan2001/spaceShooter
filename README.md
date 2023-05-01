
# Space Shooter

Created by Quan Nguyen, Maya Chidambaram, and Ana Sanchez

We created a space shooter game that works similar to Space Invaders. We have a player space ship that moves around and shoots lasers. We made three kinds of enemys to defeat. The first enemy is a basic small enemy that takes one hit to kill. The second enemy is a mid-enemy that takes 3 hits to kill. The final enemy is the boss that takes 10 hits to kill. These enemies appear on the screen, starting with the small enemies, then the mid enemies appear, and finally the boss will appear. We implemented a score counter and if you get hit you die. As well a timer that lasts for 30 seconds. Once the 30 seconds passed the game is over.

For our game we had to create three objects: the enemy, the player, and the game. We created these objects using .h files and had our Test.cpp file act as a driver file for our .h files. For the player.h file, we had that act as the player and for our interactive component, they moved around using the WASD keys and it shoots lasers with the enter button. Our enemy object moves autonomously around independently as it travels to various parts of the screen to challenge the player to hit it. The player interacts with the autonomous object by shooting it with the laser and killing it. We made use of polymorphism, abstract classes, and upcasting in our enemy object as we created three child classes from that which defined which kind of enemy each object was--a small enemy, a mid enemy or if it was a boss.

In terms of how we divided the work, Quan created the objects like the player.h file, the enemy.h file and the game.h file. He also created the driver cpp file to actually run our code. Ana worked on the graphics and created the shapes of the enemies, player, and the laser. Maya helped out with general debugging and game logic, creating the score/text display, and GitHub basics to actually upload our code on.
