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

void SetStartingVariablesAndOptions();

RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Super Gra!!!", Style::Fullscreen);
//RenderWindow window(VideoMode(1000,600), "Super Gra!!!", Style::Default);

Game game(window);

int main() {
    srand(time(NULL));
    window.setFramerateLimit(60);
    SetStartingVariablesAndOptions();

    while (window.isOpen()) {

        game.Play(window);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); return 0; }

    }
    return 0;
}


void SetStartingVariablesAndOptions() {
    Boost_invincible::BodyTexture.loadFromFile("./Resourses/sprites/black_hole_background.png");
    Boost_hp::BodyTexture.loadFromFile("./Resourses/sprites/Heart.png");
    Enemy_normal::BodyTexture.loadFromFile("./Resourses/sprites/Ship1.png");
    Enemy_normal::ExhaustTexture.loadFromFile("./Resourses/sprites/ExhaustEnemyNormal.png");
    Enemy_boost::BodyTexture.loadFromFile("./Resourses/sprites/Ship2.png");
    Enemy_boost::ExhaustTexture.loadFromFile("./Resourses/sprites/ExhaustEnemyBoost.png");
    Enemy_seeker::BodyTexture.loadFromFile("./Resourses/sprites/Ship3animated.png");
    Player::HeartTexture.loadFromFile("./Resourses/sprites/Heart.png");
    Player_5::BodyTexture.loadFromFile("./Resourses/sprites/Ship5.png");
    Player_5::ExhaustTexture.loadFromFile("./Resourses/sprites/Exhaust_player_5.png");
    Player_6::BodyTexture.loadFromFile("./Resourses/sprites/Ship6.png");
    Player_6::ExhaustTexture.loadFromFile("./Resourses/sprites/Exhaust_player_6.png");
    Bullet_5::BodyTexture.loadFromFile("./Resourses/sprites/Shoot_5.png");
    Bullet_6::BodyTexture.loadFromFile("./Resourses/sprites/Shoot_6.png");
    Explosion_5::ExplosionTexture.loadFromFile("./Resourses/sprites/Explosion_5.png"); 
    Explosion_6::ExplosionTexture.loadFromFile("./Resourses/sprites/Explosion_6.png"); 
    Parts_normal::BodyTexture.loadFromFile("./Resourses/sprites/Parts_ship1.png"); 
    Parts_boost::BodyTexture.loadFromFile("./Resourses/sprites/Parts_ship2.png"); 
    Parts_seeker::BodyTexture.loadFromFile("./Resourses/sprites/Parts_ship3.png"); 

}