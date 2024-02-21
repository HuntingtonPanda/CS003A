#include "button.h"
#include "random.h"

#define DELETE_KEY 8
#define ENTER_KEY 13

using namespace std;

Button::Button()
{
    traceButton();
}

void Button::traceButton(){
    //Blueprints the textbox
    textBox.setFillColor(sf::Color(255,255,255)); //(192,192,192)); //silver
    textBox.setPosition(sf::Vector2f(WORK_PANEL + 20, 15));
    textBox.setSize(sf::Vector2f(SIDE_BAR - 40, 100));
    textBox.setOutlineThickness(5.0);
    textBox.setOutlineColor(sf::Color::Black);

    //Blueprints the helpbutton icon box
    helpButton.setFillColor(sf::Color(192,192,192)); //(192,192,192)); //silver
    helpButton.setPosition(sf::Vector2f(20, 15));
    helpButton.setSize(sf::Vector2f(40, 40));
    helpButton.setOutlineThickness(5.0);
    helpButton.setOutlineColor(sf::Color::Black);
    //Blueprints the helpbutton icon circle
    helpButtonCircle.setFillColor(sf::Color(192,192,192)); //(192,192,192)); //silver
    helpButtonCircle.setPosition(sf::Vector2f(22, 17));
    helpButtonCircle.setRadius(18);
    helpButtonCircle.setOutlineThickness(2.0);
    helpButtonCircle.setOutlineColor(sf::Color::Black);
    //Blueprints the helpbutton info box
    helpBox.setFillColor(sf::Color(255,255,255)); //(192,192,192)); //silver
    helpBox.setPosition(sf::Vector2f(60, 15));
    helpBox.setSize(sf::Vector2f(WORK_PANEL - 120, 500));
    helpBox.setOutlineThickness(5.0);
    helpBox.setOutlineColor(sf::Color::Black);
    
    //Blueprints all the key buttons
    button = new sf::RectangleShape[25];
    sf::RectangleShape* buttonWalker = button;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++, buttonWalker++){
            *buttonWalker = sf::RectangleShape({SIDE_BAR/4 - 40, 60});
            buttonWalker->setFillColor(sf::Color(242,243,245));
            buttonWalker->setPosition(sf::Vector2f(j*((SIDE_BAR/4)-8) + 30 + WORK_PANEL, i*(500/6.0) + SCREEN_HEIGHT - 500));
            buttonWalker->setOutlineThickness(3.0);
            buttonWalker->setOutlineColor(sf::Color::Black);
        }
    }
}

//Draws out the history
void Button::writeHistory(sf::RenderWindow& window){
    ifstream myFile("history.txt");
    string line;
    Stack<string> equations;
    while (getline(myFile, line))
    {
        equations.push(line);
    }
    myFile.close();

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    string full = ""; 
    while(!equations.empty()){
        full += (equations.pop());
        full += "\n\n";
    }

    history_text = sf::Text(full, font);
    history_text.setCharacterSize(40);
    history_text.setStyle(sf::Text::Bold);
    history_text.setFillColor(sf::Color::White);
    history_text.setPosition(sf::Vector2f(WORK_PANEL + 30, 135));

    window.draw(history_text);

    
}

// bool firstRow(float mouseY){
//     return(mouseY > (SCREEN_HEIGHT - 500) && mouseY < (SCREEN_HEIGHT - 500 + 60));
// }

// bool secondRow(float mouseY){
//     return(mouseY > (SCREEN_HEIGHT - 500 + 500/6.0) && mouseY < (SCREEN_HEIGHT - 500 + 500/6.0 + 60));
// }

// bool firstCol(float mouseX){
//     return (mouseX > (30 + WORK_PANEL) && mouseX < (30 + WORK_PANEL + SIDE_BAR/4 - 40));
// }

//sees if help-button is clicked
bool clickHelpButton(float mouseX, float mouseY){
    return (mouseX > 20 && mouseX < 60 && mouseY > 15 && mouseY < 55);
}

//Sees if text-box is clicked
bool clickTextBox(float mouseX, float mouseY){
    return (mouseX > WORK_PANEL + 20 && mouseX < WORK_PANEL + 20 + SIDE_BAR - 40 && mouseY > 15 && mouseY < 115);
}

//Find what row button is pressed and what history is pressed
int whatRow(float mouseY){
    for (int i = 0; i < 6; i++){
        if (mouseY > (SCREEN_HEIGHT - 500 + i*(500/6.0)) && mouseY < (SCREEN_HEIGHT - 500 + i*(500/6.0) + 60)){
            //cout << "\n[Row]<" << i << ">\n";
            return i;
        }
    }

    for (int i = 0; i < 6; i++){
        if (mouseY > (135 + i*(95)) && mouseY < (135 + i*(95) + 50)){
            //cout << "\n[Row]<" << i << ">\n";
            return 10-i;
        }
    }
    //cout << "\n[Row]<" << -1 << ">\n";
    return -1;
}

//Find what coloumn button is pressed
int whatCol(float mouseX){
    for (int i = 0; i < 6; i++){
        if (mouseX > (30 + WORK_PANEL + i*((SIDE_BAR/4)-8)) && mouseX < (30 + WORK_PANEL + SIDE_BAR/4 - 40 + i*((SIDE_BAR/4)-8))){
            //cout << "\n[Col]<" << i << ">\n";
            return i;
        }
    }
    //cout << "\n[Col]<" << -1 << ">\n";
    return -1;
}

//Updates history.txt and the the history board on screen
void Button::updateHistory(){
    int counter = 0;
    ifstream myFile("history.txt");
    string line;
    Stack<string> equations;
    Stack<string> temp;
    while (getline(myFile, line))
    {
        equations.push(line);
    }
    myFile.close();

    ofstream oFile("history.txt");
    while(!equations.empty() && counter < 4){
        temp.push(equations.pop());
        counter++;
    }
    while(!temp.empty()){
        oFile << temp.pop() << "\n";
    }
    oFile << _input << "\n";
    oFile.close();
}

//Deletes the last character by tracing it all except the last letter and then returning it
void Button::deleteLastChar(){
    string temp = "";
    for(int i = 0; i < _input.length() - 1; i++){
        temp += _input[i];
    }
    _input = temp;
}

//Allows user to type
void Button::typingText(sf::Event input){
    if (isSelected){
        int charTyped = input.text.unicode; //SFML is weird and only uses ASCII
        if(charTyped < 128) {
            if(charTyped == DELETE_KEY && _input.length() > 0){//Defined at the top
                deleteLastChar();                              //If you press backspace it'll delete one character
            }else if(charTyped == ENTER_KEY && _input.length() > 0){ //Defined at the top
                updateHistory();                                     //If you press enter it'll update history
            }else{
                _input += static_cast<char>(charTyped);    //You can type
            }
        }
    }
    
}

bool Button::processButton(sf::RenderWindow& window){
    sf::Event event;
    float mouseX, mouseY;

    //Find where the mouse is
    mouseX = sf::Mouse::getPosition(window).x-5;
    mouseY = sf::Mouse::getPosition(window).y-5;

    //Sees if you clicked help-button if so inverse needHelp
    if(clickHelpButton(mouseX, mouseY)){
        needHelp = !needHelp;
    }

    //Sees if you clicked text-box
    if(clickTextBox(mouseX, mouseY)){
        isSelected = true;
        //cout << "\nGAME ON\n";
    }else{
        isSelected = false;
        //cout << "\nGAME OFF\n";
    }

    //Brings up the equation which is clicked from the history
    if((whatCol(mouseX) == 0 || whatCol(mouseX) == 1) && whatRow(mouseY) > 5){
        int which =  whatRow(mouseY) - 6;
        int counter = 0;
        ifstream myFile("history.txt");
        string line;
        Stack<string> equations;
        while (getline(myFile, line)){
            if(counter == which)
                break;
            counter++;
        }
        myFile.close();
        _input = line;
    }

    //Reacts to which button is being pressed
    switch(whatRow(mouseY)){
        case 0: 
            switch(whatCol(mouseX)){
                case 0:
                    _input += "sin";
                    break;
                case 1:
                    _input += "cos";
                    break;
                case 2:
                    _input += "tan";
                    break;
                case 3:
                    _input += "^";
                    break;
                default:
                    break;
            }
            break;
        
        case 1:
            switch(whatCol(mouseX)){
                case 0:
                    _input += "X";
                    break;
                case 1:
                    _input += "(";
                    break;
                case 2:
                    _input += ")";
                    break;
                case 3:
                    _input += "/";
                    break;
                default:
                    break;
            }
            break;

        case 2:
            switch(whatCol(mouseX)){
                case 0:
                    _input += "7";
                    break;
                case 1:
                    _input += "8";
                    break;
                case 2:
                    _input += "9";
                    break;
                case 3:
                    _input += "*";
                    break;
                default:
                    break;
            }
            break;    
        
        case 3:
            switch(whatCol(mouseX)){
                case 0:
                    _input += "4";
                    break;
                case 1:
                    _input += "5";
                    break;
                case 2:
                    _input += "6";
                    break;
                case 3:
                    _input += "-";
                    break;
                default:
                    break;
            }
            break;

        case 4:
            switch(whatCol(mouseX)){
                case 0:
                    _input += "1";
                    break;
                case 1:
                    _input += "2";
                    break;
                case 2:
                    _input += "3";
                    break;
                case 3:
                    _input += "+";
                    break;
                default:
                    break;
            }
            break;

        case 5:
            switch(whatCol(mouseX)){
                case 0:
                    _input += "0";
                    break;
                case 1:
                    _input += ".";
                    break;
                case 2:
                    return true;
                    break;
                case 3:
                    _input = "";
                    break;
                default:
                    break;
            }
            break;

        default:
            break;
    }
    return false;
    // if(firstCol(mouseX)){ 
    //     if(firstRow(mouseY)){
    //   \n";
    //     }else if(secondRow(mouseY)){
    //   ;
    //     }else{
    //   --\n";
    //     }
    // }else{
    // }

}


void Button::Draw(sf::RenderWindow& window){
    window.draw(textBox);
    window.draw(helpButton);
    window.draw(helpButtonCircle);

    sf::RectangleShape* buttonWalker = button;
    for(int i = 0; i < 25; i++, buttonWalker++){
        window.draw(*buttonWalker);
    }


    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    help_text = sf::Text(
        "Shift: Zoom-in\nEnter: Zoom-out\nArrows: Panning\n\nYou can use buttons for easy input but can also click on the\nfunction box to type\nIf you press enter key it'll save to history but if you press \nEnter button it will evaluate"
        , font);
    help_text.setCharacterSize(40);
    help_text.setStyle(sf::Text::Bold);
    help_text.setFillColor(sf::Color::Black);
    help_text.setPosition(sf::Vector2f(65, 20));

    if(needHelp){
        window.draw(helpBox);
        window.draw(help_text);
    }
    button_text = sf::Text("?", font);
    button_text.setCharacterSize(40);
    button_text.setStyle(sf::Text::Bold);
    button_text.setFillColor(sf::Color::Yellow);
    button_text.setPosition(sf::Vector2f(31, 10));

    window.draw(button_text);
    int counter = 0;
    button_text.setFillColor(sf::Color::Black);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++, counter++){
            button_text.setString(colour[counter]);  
            button_text.setPosition(sf::Vector2f(j*((SIDE_BAR/4)-8) + 35 + WORK_PANEL, i*(500/6) + SCREEN_HEIGHT - 500));

            window.draw(button_text);
        }
    }

    if(isSelected)
        button_text.setString("f(x): " + _input +"|");
    else  
        button_text.setString("f(x): " + _input);  
    button_text.setPosition(sf::Vector2f(35 + WORK_PANEL, 20));

    window.draw(button_text);
}