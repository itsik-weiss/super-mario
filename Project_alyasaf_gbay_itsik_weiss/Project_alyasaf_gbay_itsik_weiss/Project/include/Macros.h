#pragma once
#include "Resources.h"
#include <string>


using std::vector;
using std::string;
using std::to_string;

const unsigned int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width;
const unsigned int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;

const float PLAYER_SPEED = 300.f;
const float PLAYER_JUMP_SPEED = -600.f;
const float PLAYER_SHOT_SPEED = 1000.f;

const float MENU_BG_WIDTH = 640;
const float MENU_BG_HEIGHT = 480;

const float GRAVITY= 1000.f;
const float CUBE_SIZE = 25.f;
const float CUBE_SIZE_MARIO_X = 38.f;
const float CUBE_SIZE_MARIO_Y = 53.f;
const int NUMBER_OF_MARIO = 3;
//const sf::IntRect RECT_MARIO = sf::Vector2f{17, 33 )};
//sf::Vector2f POSITION_RECT_MARIO = { 0,10 };

const string LEVEL_FILE_NAME = "Board";
const string EMPTY_STRING = "";
const string TXT_SUFFIX = ".txt";
const string SCORE_MSG = "YOUR SCORE IS: ";
const string MARIO_MSG = "Mario Game";
const float PROTECTED_TIME = 1;
const float PLAYER_TIME = 30;


const char SPACE = ' ';
const char PLAYER = '/';
const char MONSTER = '!';
const char FOOD = 'D';
//const char STONE = '@';
const char WALL = '#';
const char GIFT = '+';
const char THORN = '@';
const char WIN_POINT = 'w';
const char PLAYER_SHOT = 'o';

const int NEW_BTN_POS_HEIGH = WINDOW_HEIGHT / 2.100;
const int EXIT_BTN_POS_HEIGH = WINDOW_HEIGHT / 1.411;
const unsigned int MENU_MSG_CHAR_SIZE = int(WINDOW_HEIGHT / 5.4);
const int MENU_MSG_ORIGIN_HEIGHT = int(WINDOW_HEIGHT / 2.7);
const int MENU_MSG_DEFAULT_ORIGIN_HEIGHT = int(WINDOW_HEIGHT / 2.16);
const int SCORE_TEXT_CHAR_SIZE = int(WINDOW_HEIGHT / 13.5);

const int SCORE_MSG_ORIGIN_HEIGHT = int(WINDOW_HEIGHT / 1.6);
const unsigned int INITIAL_SCORE = 0;
const unsigned int INITIAL_LIVES = 3;

//const enum class DIRECTION { NO_MOVE=0, LEFT = 71, RIGHT, UP, DOWN };
const enum { LEFT = -1, RIGHT=1};

const sf::Vector2f BUTTON_SCALE = sf::Vector2f(WINDOW_WIDTH / (379 * 3.377), WINDOW_HEIGHT / (122 * 5.9016));
const sf::Vector2f BUTTON_ORIGIN = sf::Vector2f(379 / 2, 122 / 2);

const sf::Color GREEN = sf::Color(51, 204, 0, 255);
const sf::Color RED = sf::Color(255, 77, 77, 255);