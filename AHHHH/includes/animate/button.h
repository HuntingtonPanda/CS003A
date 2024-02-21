#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iomanip>
#include <set>
#include <vector>

#include <iostream>
#include <math.h> 
#include <fstream>

#include "constants.h"

#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include "../../includes/token/function.h"
#include "../../includes/token/leftparen.h"
#include "../../includes/token/rightparen.h"

#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
#include "system.h"
#include "sidebar.h"
class Button{
    public:
        Button();

        //Blueprints the buttons
        void traceButton();

        //Sees what button user clicked
        bool processButton(sf::RenderWindow& window);

        //Allows user to type to text
        void typingText(sf::Event input);

        //Allows user to press back-space to delete
        void deleteLastChar();

        //writes teh history
        void writeHistory(sf::RenderWindow& window);

        //Updates the history
        void updateHistory();

        //Draws all the buttons
        void Draw(sf::RenderWindow& widnow);
        
        //Returns _input
        string getInput(){return _input;}

    private:
        //Draws out the text box
        string _input = ""; //Takes in input which later is submitted
        bool isSelected = false;
        sf::RectangleShape textBox;
        sf::RectangleShape* button;

        //Where in history did you click
        int whereHistory;

        //If help is needed
        bool needHelp = false;
        
        //Drawing the help box
        sf::RectangleShape helpButton;
        sf::RectangleShape helpBox;
        sf::CircleShape helpButtonCircle;
        
        //Help box text
        sf::Text help_text;

        sf::Font font;                      //used to draw text
        
        //Button label
        sf::Text button_text;                   //used to draw strings on the window object

        //Text for the history
        sf::Text history_text; 

        //setting up button text
        const char* colour[25]
      = { "sin", "cos", "tan", "^", 
          "X", "(", ")", "/",
          "7", "8", "9", "*",
          "4", "5", "6", "-",
          "1", "2", "3", "+",
          "0", ".", "Enter", "clear"};

};

string mouse_pos_string(sf::RenderWindow& window);

#endif // GAME_H