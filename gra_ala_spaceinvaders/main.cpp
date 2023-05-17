// Code lines: 1700
// Classes number: 21
//
// Game writen By Rados³aw Olejniczak
// Copping and Sharing without permission ist verbotten
// For Education or Fun purpoces only
//
// Have Fun ~Creator
//
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Game.h"
using namespace sf;


RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Super Gra!!!", Style::Fullscreen);
//RenderWindow window(VideoMode(1000,600), "Super Gra!!!", Style::Default);


int main() {
    Game game(window);
    srand(time(NULL));
    window.setFramerateLimit(60);
    while (window.isOpen()) {

        game.Play(window);

    }
    return 0;
}

