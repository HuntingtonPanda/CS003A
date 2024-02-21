#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
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
#include "../../includes/token/tokenizer.h"

#include "../../includes/queue/MyQueue.h"

#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"

using namespace std;
class System
{
public:
    System();
    void Axis(sf::RectangleShape& yAxis, sf::RectangleShape& xAxis);

    void xGraduationMark();
    void yGraduationMark();

    void calc_points();
    void calc_points(string eq);

    void calc_xgraduation(float& xgraduation);
    void calc_ygraduation(float& ygraduation);
    //void Step(int command);
    void Pan(int command);

    void Zoom(int command);

    //int Size();
    void Draw(sf::RenderWindow& widnow);

    Queue<string>& getList(){return equations;}
private:
//    vector<Particle> system;
    // sf::CircleShape* shapePtr;
    // sf::Vector2f* velPtr;

    Queue<string> equations;
    string equation;

    sf::CircleShape* Points;

    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;     

    sf::RectangleShape yAxis;
    sf::RectangleShape* yAxisGraduation;
    sf::Text yGLabel;
    int* yGLabelNum;
    float* yGLabelCoord;

    sf::RectangleShape xAxis;
    sf::RectangleShape* xAxisGraduation;
    sf::Text xGLabel;
    int* xGLabelNum;
    float* xGLabelCoord;

    float xmin = -7;
    float xmax = 7;
    float xmid;

    float ymin = -7;
    float ymax = 7;
    float ymid;

    float xgraduation;
    float ygraduation;

    float zoom = 1.0;
    

};

#endif // SYSTEM_H
