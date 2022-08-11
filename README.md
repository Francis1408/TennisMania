<img src = "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/GameLogo.png" align = "center">  

#### Developed by: Francisco Abreu Gonçalves


<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/RacketSelect.png" width="60" height="40" text-align = "left">

#### About:

Tennis Mania is game project developed during the Computer Graphics classes. The game is inspired by the classics Pong genre games, in which two players compete to score more points by rebounding the ball to the rival area.

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/RacketSelect.png" width="60" height="40" text-align = "left">

#### Controls:

| Controls | Action            |
|----------|:------------------|
| `W`      |Player 1 Move up   |
| `S`      |Player 1 Move down |
| `O`      |Player 2 Move up   |
| `L`      |Player 2 Move down |
| `P`      |Pause game         |
| `Esc`    |Exit game          |

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/RacketSelect.png" width="60" height="40" text-align = "left">

#### Rules

Two players will compete against each other in order to score points. Whenever a player scores 12 points, he clinches a set. The first player to clinch 3 sets is the winner.

#### Characters 

Before the match, the game lets the players choose between 6 playable characters. All of them are from the classic [Mario Tennis](https://www.mariowiki.com/Mario_Tennis_(Game_Boy_Color)) From GameBoy Color:

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/acozIcon.png" text-align = "left" width="50" height="50"> Acoz

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/bobIcon.png" text-align = "left" width="50" height="50"> Bob

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/brianIcon.png" text-align = "left" width="50" height="50"> Brian

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/harryIcon.png" text-align = "left" width="50" height="50"> Harry

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/pamIcon.png" text-align = "left" width="50" height="50"> Pam

<img src= "https://github.com/Francis1408/TennisMania/blob/main/bin/Debug/sammyIcon.png" text-align = "left" width="50" height="50"> Sammy

#### How to run

In order to run the game you need, at first, install the following libraries:

| Libraries    | Download command in Linux             | 
|--------------|:--------------------------------------|
| OpenGl / Glut|`$sudo apt-get install freeglut3-dev`  |
| SOIL         |`sudo apt-get install libsoil-dev`     |

After they are all installed, execute the makefile by running the following commands in your Shell Terminal:

```
make
make run
```
If you wish to remove the executable file, simply run the command:

```
make clean
```