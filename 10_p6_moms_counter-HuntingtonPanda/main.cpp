#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1200;
const int GRID_WIDTH = 200;
const int GRID_HEIGHT = 110;
const int CELL_SIZE = 5;

using namespace std;



int main(int argc, char *argv[])
{
    //----------S E T U P ------------------------------:

    //declare a window object:
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "JAVA SUCKS!");
    //
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    //
    //or...
    // you could do this:
    //sf::RenderWindow window;
    //window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    //

    window.setFramerateLimit(3); //3 times per second

    //this is where we keep all the shapes.
//    sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];


    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    //Application runs at the same freq as monitor

    //. . . . . . . SHAPES ............
    //this is how you would declare and manipulate shapes:
    sf::CircleShape circle(250.f);
    circle.setFillColor(sf::Color::Green);
    // set a 10-pixel wide orange outline
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color(250, 150, 100));


    // define a 120x50 rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.move(sf::Vector2f(100,100));
    rectangle.setFillColor(sf::Color::Blue);
    // change the size to 100x100
    //rectangle.setSize(sf::Vector2f(10, 10));
    //. . . . . . . . . . . . . . . . . . . . . . . . . . .



    // run the program as long as the window is open
    while (window.isOpen()){
        cout<<"looooping..."<<endl;
        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;

        //go through all the pending events: keyboard, mouse, close, resize, etc.
        //pollEvent and waitEvent are the only two functions that can fill event
        while (window.pollEvent(event))//or waitEvent
        {
            // check the type of the event...
            switch (event.type)
            {
            // window closed
            // "close requested" event: we close the window
            case sf::Event::Closed:
                cout<<"close event was encountered!"<<endl;
                //window.close();
                break;

                // key pressed
            case sf::Event::KeyPressed:
                cout<<"a key was pressed..."<<endl;
                //...
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                else
                    std::cout<<"left button?"<<std::endl;
                break;
            default:
                break;
            }
        }

        window.clear();
        window.draw(circle); //draw the circle on the window
        window.draw(rectangle);
        window.display();
    }
    return 0;
}

