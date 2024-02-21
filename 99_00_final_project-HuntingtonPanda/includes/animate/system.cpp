#include "system.h"
#include "random.h"

using namespace std;

System::System()
{
    //Opening hisotry to see what was last inputed
    ifstream myFile("history.txt");
    string line;
    while (getline(myFile, line))
    {
        equations.push(line);
    }
    myFile.close();

    calc_xgraduation(xgraduation); //Caclulates the scale in the x-direction and puts it in xgraduation
    calc_ygraduation(ygraduation); //Caclulates the scale in the y-direction and puts it in ygraduation

    //cout << "xgraduation: " << xgraduation << " ygraduation: " << ygraduation << endl;

    //Draws the graph
    Axis(yAxis, xAxis);
    xGraduationMark();
    yGraduationMark();

    //Graphs the last equation in history
    calc_points();
    
}

//Calculate where the points of the graph should be given an equation
void System::calc_points(string eq){
    equations.push(eq);
    calc_points();
}
//Calculate where the points of the graph should be using the end of the equation
void System::calc_points(){
    equation = equations.back();
    
    //converting the string to postfix form
    Tokenizer current(equation);
    Queue<Token*> infix = current.getInfix();
    infix.print_pointers();
    ShuntingYard sy(infix);
    Queue<Token *> postfix = sy.postfix();
    
    RPN rpn(postfix);   //solves the math of the points

    //Makes the points for the graph
    Points = new sf::CircleShape[(int)WORK_PANEL];
    sf::CircleShape* velWalker = Points;
    for(int i = 0; i < WORK_PANEL; i++, velWalker++){
        *velWalker = sf::CircleShape(2);
        velWalker->setPosition(sf::Vector2f(i, (ymax*ygraduation - rpn(i/xgraduation + xmin)*ygraduation))); //Converting graph to window coord
        velWalker->setFillColor(sf::Color::Black);
    }

}

//Calculating the scale of the x-direction
void System::calc_xgraduation(float& xgraduation){
    //xmid = (xmin + xmax)/2;

    xgraduation = WORK_PANEL/(xmax - xmin);
}

//Calculating the scale of the y-direction
void System::calc_ygraduation(float& ygraduation){
    //ymid = (ymin + ymax)/2;

    ygraduation = SCREEN_HEIGHT/(ymax - ymin);
}

void System::Axis(sf::RectangleShape& yAxis, sf::RectangleShape& xAxis){
    
    //y-axis line construction
    yAxis.setSize(sf::Vector2f(0, SCREEN_HEIGHT));
    yAxis.setOutlineColor(sf::Color::Red);
    yAxis.setOutlineThickness(2);
    yAxis.setPosition((-1*xmin) * xgraduation, 0);

    //x-axis line construction
    xAxis.setSize(sf::Vector2f(WORK_PANEL, 0));
    xAxis.setOutlineColor(sf::Color::Red);
    xAxis.setOutlineThickness(2);
    xAxis.setPosition(0, ymax * ygraduation);
}

void System::xGraduationMark(){
    xAxisGraduation = new sf::RectangleShape[15];
    
    xGLabelCoord = new float[15];
    xGLabelNum = new int[15];

    sf::RectangleShape* shapeWalker = xAxisGraduation;

    float* coordWalker = xGLabelCoord;
    int* numWalker = xGLabelNum;

    float xdistance = WORK_PANEL/14;
    float xgrad = (xmax-xmin)/14;
    for(int i = 0; i < 15; i++, shapeWalker++, coordWalker++, numWalker++){
        //Makes tick marks on the x-axis
        *shapeWalker = sf::RectangleShape(sf::Vector2f(0, 30));
        shapeWalker->setOutlineColor(sf::Color::Red);
        shapeWalker->setOutlineThickness(2);
        shapeWalker->setPosition(i * xdistance, ymax*ygraduation - 15);
        
        //startng from left, finds window coordinates of where label of tick should go
        *coordWalker = i * xdistance - 5;

        //starting from left, declares label for each tick, only accepts integers otherwise throws it
        if( fabs(((xmin + i*xgrad)) - (int)((xmin + i*xgrad))) <= 0.1)
            *numWalker = (int)((xmin + i*xgrad));
        else{
            *numWalker = 0;
            *coordWalker = -100;
        }
        
        //Doesn't label the intersect
        if(fabs(*coordWalker - ((-1 * xmin) * xgraduation - 5)) <= 10){
            *coordWalker = -100;
            //cout << "\n<ACTIVATED>\n";
        }    
    }
}

void System::yGraduationMark(){
    yAxisGraduation = new sf::RectangleShape[15];
    yGLabelCoord = new float[15];
    yGLabelNum = new int[15];

    sf::RectangleShape* shapeWalker = yAxisGraduation;

    float* coordWalker = yGLabelCoord;
    int* numWalker = yGLabelNum;
    
    float ydistance = SCREEN_HEIGHT/14;
    float ygrad = (xmax-xmin)/14;
    for(int i = 0; i < 15; i++, shapeWalker++, coordWalker++, numWalker++){
        //Makes tick marks on the y-axis
        *shapeWalker = sf::RectangleShape(sf::Vector2f(30, 0));
        shapeWalker->setOutlineColor(sf::Color::Red);
        shapeWalker->setOutlineThickness(2);
        shapeWalker->setPosition((-1*xmin) * xgraduation - 15, i * ydistance);

        //startng from top, finds window coordinates of where label of tick should go
        *coordWalker = i * ydistance - 10;

        //starting from top, declares label for each tick, only accepts integer otherwise goes away
        if( fabs(((ymax - i*ygrad)) - (int)((ymax - i*ygrad))) <= 0.1)
            *numWalker = (int)((ymax - i*ygrad));
        else{
            *numWalker = 0;
            *coordWalker = -100;
        }
        

        //Doesn't label the intersect
        if(fabs(*coordWalker - (ymax * ygraduation - 10)) <= 10){
            *coordWalker = -100;
        }    
    }
}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Zoom(int command){
    switch(command){
        case 12: //zoom *= 2;
                 xmin /= 2;
                 xmax /= 2;
                 ymin /= 2;
                 ymax /= 2;
                break;
        case 14: //zoom /= 2;
                 xmin *= 2;
                 xmax *= 2;
                 ymin *= 2;
                 ymax *= 2;
                break;        
    }
    calc_xgraduation(xgraduation);
    calc_ygraduation(ygraduation);
    
    switch(command){
        case 12: 
        case 14: 
                calc_points();
                break;        
    }
}

void System::Pan(int command){
    // sf::RectangleShape* xGWalker = xAxisGraduation;
    // sf::RectangleShape* yGWalker = yAxisGraduation;

    switch(command){
        case 4: xmin--;
                xmax--;
                yAxis.setPosition((-1*xmin) * xgraduation, 0);
                calc_points();
                // for(int i = 0; i < 15; i++, yGWalker++){
                //     yGWalker->move(sf::Vector2f(xgraduation, 0));
                // }
                break;
        case 6: xmin++;
                xmax++;
                yAxis.setPosition((-1*xmin) * xgraduation, 0);
                calc_points();
                // for(int i = 0; i < 15; i++, yGWalker++){
                //     yGWalker->move(sf::Vector2f(-1 * xgraduation, 0));
                // }
                break;
        case 8: ymin++;
                ymax++;
                xAxis.setPosition(0, ymax * ygraduation);
                calc_points();
                // for(int i = 0; i < 15; i++, xGWalker++){
                //     xGWalker->move(sf::Vector2f(0, ygraduation));
                // }
                break;
        case 10: ymin--;
                ymax--;
                xAxis.setPosition(0, ymax * ygraduation);
                calc_points();
                // for(int i = 0; i < 15; i++, xGWalker++){
                //     xGWalker->move(sf::Vector2f(0, -1 * ygraduation));
                // }
                break;
    }
}

//void System::Step(int command){

    //     //all this is the responsibility of the
    //     // individual object:
    // sf::CircleShape* shapeWalker = shapePtr;
    // sf::Vector2f* velWalker = velPtr;
    // for(int i = 0; i < 15; i++, velWalker++, shapeWalker++){
    //     shapeWalker->move(*velWalker);
    //     sf::Vector2f pos = shapeWalker->getPosition();
    //     if ((pos.x)>=WORK_PANEL-20)
    //         *velWalker = sf::Vector2f(-1*velWalker->x,1*velWalker->y);
    //     if (pos.x<=0)
    //         *velWalker = sf::Vector2f(-1*velWalker->x,1*velWalker->y);
    //     if ((pos.y)>=SCREEN_HEIGHT-20)
    //         *velWalker = sf::Vector2f(1*velWalker->x,-1*velWalker->y);
    //     if (pos.y<=0)
    //         *velWalker = sf::Vector2f(1*velWalker->x,-1*velWalker->y);
    // }

//}


void System::Draw(sf::RenderWindow& window){
    xGraduationMark();
    yGraduationMark();

    window.clear(sf::Color{ 211, 211, 211, 255 });
    // sf::CircleShape* shapeWalker = shapePtr;
    // for(int i = 0; i < 15; i++, shapeWalker++)
    //     window.draw(*shapeWalker);
    window.draw(yAxis);
    window.draw(xAxis);
    
    sf::RectangleShape* xGWalker = xAxisGraduation;
    sf::RectangleShape* yGWalker = yAxisGraduation;

    //sf::Text* labelWalker = xGLabel;
    
    for(int i = 0; i < 15; i++, xGWalker++, yGWalker++){
        window.draw(*xGWalker);

        xGLabel = sf::Text(to_string(xGLabelNum[i]), font);
        xGLabel.setCharacterSize(20);
        xGLabel.setStyle(sf::Text::Bold);
        xGLabel.setFillColor(sf::Color::Black);
        xGLabel.setPosition(sf::Vector2f(xGLabelCoord[i], ymax*ygraduation + 25));
        window.draw(xGLabel);

        window.draw(*yGWalker);

        yGLabel = sf::Text(to_string(yGLabelNum[i]), font);
        yGLabel.setCharacterSize(20);
        yGLabel.setStyle(sf::Text::Bold);
        yGLabel.setFillColor(sf::Color::Black);
        yGLabel.setPosition(sf::Vector2f((-1*xmin) * xgraduation + 25, yGLabelCoord[i]));
        window.draw(yGLabel);

    }

    sf::CircleShape* velWalker = Points;

    for(int i = 0; i < WORK_PANEL; i++, velWalker++){
        window.draw(*velWalker);
    }



        //int label = xmin + 20;

        
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

}
