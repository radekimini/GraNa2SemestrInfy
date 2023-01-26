// lini kodu 1170
//iloœæ klass 21

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "Bullet.h"
#include "Bullet_5.h"
#include "Bullet_6.h"
#include "Enemy.h"
#include "Player.h"
#include "Player_5.h"
#include "Player_6.h"
#include "Enemy_boost.h"
#include "Enemy_normal.h"
#include "Enemy_seeker.h"
#include "Boost.h"
#include "Boost_invincible.h"
#include "Boost_hp.h"
#include "Boost_Skill.h"
#include "Explosion.h"
#include "Explosion_5.h"
#include "Explosion_6.h"
#include "Parts.h"
#include "Parts_seeker.h"
#include "Parts_boost.h"
#include "Parts_normal.h"
using namespace sf;

void Draw();
void Update();
void GameFactor();
void SetStartingVariablesAndOptions();
void GameOver();
void GameOverFontSet();
void ExhaustCount();

void UpdateCharacterPicker();
void DrawCharacterPicker();

bool CharacterPicked = false;
int which=5;
//RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Super Gra!!!", Style::Fullscreen);
RenderWindow window(VideoMode(1000,600), "Super Gra!!!", Style::Default);
Player *player;

Player *CharacterPickerPlayers[2];

float TimeFactor = 0;
unsigned int TimeFactorCounter = 0;
float DificultyFactor = 1;
unsigned int DificultyFactorCounter = 0;
unsigned int textEscCounter = 0;
int ExhaustCounter = 0;
unsigned long long FramesCounter = 1;

std::vector<Parts*> enemiesParts;
std::vector<Bullet*> projectiles;
std::vector<Explosion*> explosions;
std::vector<Enemy*> enemies;
std::vector<Boost*> boosts;

Font font;
Text LastScore;
Text ChoicePlayer;;
Text CurrentPoints;
Text pressEsc;
Text PlayedTime;

//Texture BoostTexture;
//Sprite kosmolud;

int main() {
    srand(time(NULL));
    window.setFramerateLimit(60);
    SetStartingVariablesAndOptions();
    while (window.isOpen()) {
        

        while (!CharacterPicked) {
            UpdateCharacterPicker();
            DrawCharacterPicker();
            Event event;
            while (window.pollEvent(event)) {
                //Game close
                if (event.type == Event::Closed) {
                    window.close();
                    return 0;
                }
                if ((Keyboard::isKeyPressed(Keyboard::Left)) || (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && event.mouseButton.x <= window.getSize().x / 2)) {
                    CharacterPicked = true;
                    player = new Player_5(window,true);
                    which = 5;
                }
                if ((Keyboard::isKeyPressed(Keyboard::Right)) || (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && event.mouseButton.x > window.getSize().x / 2)) {
                    CharacterPicked = true;
                    player = new Player_6(window,true);
                    which = 6;
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
                return 0;
            }
            if (CharacterPicked) {
                CharacterPickerPlayers[0];
                CharacterPickerPlayers[1];
                TimeFactor = 0;
                TimeFactorCounter = 0;
                DificultyFactor = 1;
                DificultyFactorCounter = 0;
                explosions.clear();
                enemies.clear();
                projectiles.clear();
                enemiesParts.clear();
            }
        }
        Event event;

        while (window.pollEvent(event)) {
        //Game close
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                player->Schoot(projectiles);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::E) {
                player->UseSkill(projectiles,window);
            }
        }
        //game close
        if (Keyboard::isKeyPressed(Keyboard::Enter) && player->Gethp() == 0) {
            PlayedTime.setString("");
            LastScore.setPosition((window.getSize().x - LastScore.getGlobalBounds().width) / 2, (window.getSize().y - LastScore.getGlobalBounds().height) / 5);
            CharacterPicked = false;
            explosions.clear();
            enemies.clear();
            projectiles.clear();
            enemiesParts.clear();
            boosts.clear();
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        if (player->Gethp() > 0) {
            if (Enemy::SpawnTimer > (46 - (TimeFactor*5))) {
                int SpawnCheck = rand() % 101;
                if (SpawnCheck < 2.0 + ((DificultyFactor - 1.0) * 10.0) + 1.0) {
                    int whitchEnemy = rand() % 3;
                    //whitch = 1;
                    //std::cout << whitch << std::endl;
                    int pos = 50 + rand() % (window.getSize().y - 200);
                    if (whitchEnemy == 0) {
                        enemies.push_back(new Enemy_normal(pos,window));
                    }
                    if (whitchEnemy == 1) {
                        enemies.push_back(new Enemy_boost(pos,window));
                    }
                    if (whitchEnemy == 2) {
                        enemies.push_back(new Enemy_seeker(pos,window));
                    }
                }
            }
            else { Enemy::SpawnTimer++; }

            GameFactor();
            Update();
            Draw();
        }
        else {
            GameOver();
        }
    }
    return 0;
}

void Draw() {
    window.clear(Color::Black);
    for (int i = 0; i < enemiesParts.size(); i++) {
        enemiesParts[i]->PartsDraw(window);
    }
    for (int i = 0; i < player->Gethp(); i++) {
    player->ShowHp(i,window);
    }
    for (int i = 0; i < player->GetSkillUsageLeft(); i++) {
    player->ShowSkill(i,window);
    }
    //rusowanie punktow
    CurrentPoints.setPosition(window.getSize().x - 10 - CurrentPoints.getGlobalBounds().width, 5.f);
    CurrentPoints.setString("Points: " + std::to_string(player->GetPoints()));
    window.draw(CurrentPoints);
    //rysowanie eksplozji 
    for (int i = 0; i < explosions.size(); i++) {
        window.draw(explosions[i]->GetBody());
    }
    //rysowanie enemies
    for (int i = 0; i < enemies.size(); i++) {
        window.draw(enemies[i]->GetBody());
        window.draw(enemies[i]->GetExhaust());
    }
    //rysowanie booletow
    for (int i = 0; i < projectiles.size(); i++) {
        window.draw(projectiles[i]->GetBody());
    }
    //rywowanie boostow
    for (int i = 0; i < boosts.size(); i++) {
        window.draw(boosts[i]->GetBody());
    }
    window.draw(player->GetShip());
    window.draw(player->GetExhaust());

    window.display();
}
void Update() {
    player->PlayerMovement(window);
    player->ExhaustAnimation(ExhaustCounter);
    player->InvincibilityEndCheck(TimeFactor);
    // ruch i dotarcie do konca bulletow
    for (int i = 0; i < projectiles.size(); i++) {
        if (projectiles[i]->BulletDestroy(window)) {
            projectiles.erase(projectiles.begin()+i);
            player->TakePoints(2);
        }
        projectiles[i]->BulletMove();
    }
    // czy enemy doszed³ do koñca
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->EnemyAtEnd(window)) {
            enemies.erase(enemies.begin()+i);
            player->TakePoints(50);
        }
        enemies[i]->EnemyMovement(DificultyFactor,*player);
    }
    // kolizja buulet z enemies
    for (int i = 0; i < projectiles.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (projectiles[i]->GetBody().getGlobalBounds().intersects(enemies[j]->GetBody().getGlobalBounds())) {
                if (enemies[j]->GetClassName() == "BOOST") {
                    int spawnCheck = rand() % 101;
                    //spawnCheck = 1;
                    if (spawnCheck < 20) {
                        boosts.push_back(new Boost_invincible(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y), TimeFactor));
                    }
                    enemiesParts.push_back(new Parts_boost(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y,TimeFactor));
                }
                else if (enemies[j]->GetClassName() == "SEEKER") {
                    int spawnCheck = rand() % 101;
                    //spawnCheck = 1;
                    if (spawnCheck < 10) {
                        boosts.push_back(new Boost_hp(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y), TimeFactor));
                    }
                    enemiesParts.push_back(new Parts_seeker(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y,TimeFactor));
                }
                else if (enemies[j]->GetClassName() == "NORMAL") {
                    int spawnCheck = rand() % 101;
                    //spawnCheck = 1;
                    if (spawnCheck < 10) {
                        boosts.push_back(new Boost_Skill(Vector2f(enemies[j]->GetBody().getPosition().x-55, enemies[j]->GetBody().getPosition().y), TimeFactor,which));
                    }
                    enemiesParts.push_back(new Parts_normal(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y,TimeFactor));
                }
                if (projectiles[i]->BulletType() == 5) {
                explosions.push_back(new Explosion_5(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y)));
                }
                if (projectiles[i]->BulletType() == 6) {
                explosions.push_back(new Explosion_6(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y)));
                }
                player->GetKill(DificultyFactor);
                projectiles.erase(projectiles.begin() + i);
                enemies.erase(enemies.begin() + j);
               break;
            }
        }
    }
    // kolizja playera z enemies
    for (int i = 0; i < enemies.size(); i++) {
        if (player->GetShip().getGlobalBounds().intersects(enemies[i]->GetBody().getGlobalBounds())) {
            if (which == 5) {
                explosions.push_back(new Explosion_5(Vector2f(enemies[i]->GetBody().getPosition().x, enemies[i]->GetBody().getPosition().y)));
            }
            if (which == 6) {
                explosions.push_back(new Explosion_6(Vector2f(enemies[i]->GetBody().getPosition().x, enemies[i]->GetBody().getPosition().y)));
            }
            enemies.erase(enemies.begin() + i);
            if (!player->IsInvincible()) {
                player->ReciveDamage();
            }
        }
    }
    // kolizja playera z boostami
    for (int i = 0; i < boosts.size(); i++) {
        if (player->GetShip().getGlobalBounds().intersects(boosts[i]->GetBody().getGlobalBounds())) {
            if (boosts[i]->GetClassName() == "INVINCIBLE") {
                player->MakeInvincibleFor(0.03, TimeFactor);
            }
            else if (boosts[i]->GetClassName() == "HP") {
                player->addhp();
            }
            else if (boosts[i]->GetClassName() == "SKILL") {
                player->AddSkillUsage();
            }
                boosts.erase(boosts.begin() + i);
        }
    }
    // usuwanie boostow po x sekundach
    for (int i = 0; i < boosts.size(); i++) {
        if (TimeFactor - boosts[i]->GetSpawnDificultyFactor() > 0.04) {
            boosts.erase(boosts.begin() + i);
        }
    }
    // animacja boostow
    for (int i = 0; i < boosts.size(); i++) {
        boosts[i]->AnimateBoost();
        boosts[i]->AnimationCounterer();
    }
    //animacja pociskow
    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i]->AnimateBoolet();
    }
    //animacja eksplozji
    for (int i = 0; i < explosions.size(); i++) {
        explosions[i]->Display();
        if (explosions[i]->GetFrameCounter() >= 66) {
            explosions.erase(explosions.begin() + i);
        }
    }
    //animacja exhaustów
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->ExhaustAnimate(ExhaustCounter);
    }
    //ruch partsow i usuwanie
    for (int i = 0; i < enemiesParts.size(); i++) {
        if (enemiesParts[i]->PartsDissaper(TimeFactor)) {
            enemiesParts.erase(enemiesParts.begin() + i);
        }
        else {
        float los = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        enemiesParts[i]->PartsMove(los);
        }
    }
    ExhaustCount();
}
void GameFactor() {
    if (DificultyFactor < 2) {
        if (DificultyFactorCounter > 60) {
            DificultyFactor += 0.01;
            DificultyFactorCounter = 0;
            player->SetMovementFactor(DificultyFactor);
        }
        else {
            DificultyFactorCounter++;
        }
    }
    if (TimeFactorCounter == 60) {
        TimeFactorCounter = 0;
        TimeFactor+=0.01;
    }
    else {
        TimeFactorCounter++;
    }
    FramesCounter++;
    //std::cout << "Dificulty: " << DificultyFactor << " Time: " << TimeFactor << std::endl;
    //std::cout << FramesCounter << std::endl;
}
void SetStartingVariablesAndOptions() {
    font.loadFromFile("./Resourses/Fonts/game_font.otf");
    LastScore.setFont(font);
    LastScore.setCharacterSize(window.getSize().y / 9);
    LastScore.setFillColor(Color::White);
    ChoicePlayer.setFont(font);
    ChoicePlayer.setCharacterSize(window.getSize().y / 9);
    ChoicePlayer.setFillColor(Color::White);
    CurrentPoints.setFont(font);
    CurrentPoints.setCharacterSize(window.getSize().y / 30);
    CurrentPoints.setFillColor(Color::White);
    pressEsc.setFont(font);
    pressEsc.setFillColor(Color::White);
    pressEsc.setCharacterSize(window.getSize().y / 15);
    pressEsc.setString("   PRESS ESCAPE TO QUIT\nENTER TO START NEW GAME");
    PlayedTime.setFont(font);
    PlayedTime.setCharacterSize(window.getSize().y / 12);
    PlayedTime.setFillColor(Color::White);
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
    ChoicePlayer.setString("Choose Your Player!");
    ChoicePlayer.setPosition((window.getSize().x - ChoicePlayer.getGlobalBounds().width) / 2, (window.getSize().y - ChoicePlayer.getGlobalBounds().height) / 5);
    CharacterPickerPlayers[0] = new Player_5(window, false);
    CharacterPickerPlayers[1] = new Player_6(window, false);
    player = new Player_6(window,true);
    which = 6;
}
void GameOver() {
    if (CharacterPicked) {
        window.clear(Color::Black);
        if (PlayedTime.getString() == "") {
            GameOverFontSet();
        }
        window.draw(LastScore);
        window.draw(PlayedTime);
        if (textEscCounter <= 60) {
            window.draw(pressEsc);
            textEscCounter++;
        }
        if (textEscCounter > 60 && textEscCounter < 120) {
            textEscCounter++;
        }
        if (textEscCounter == 120) {
            textEscCounter = 0;
        }
        window.display();
    }
}
void GameOverFontSet() {
    std::cout << "ustawienia czcionek\n";
    LastScore.setString("FINAL SCORE:" + std::to_string(player->GetPoints()));
    LastScore.setPosition((window.getSize().x - LastScore.getGlobalBounds().width) / 2, (window.getSize().y - LastScore.getGlobalBounds().height) / 5);
    pressEsc.setPosition(((window.getSize().x - pressEsc.getGlobalBounds().width) / 2), ((window.getSize().y - pressEsc.getGlobalBounds().height) / 2) + (window.getSize().y / 5));
    PlayedTime.setString("\nPlLAYED TIME " + std::to_string((int)(TimeFactor * 100)) + " sec");
    PlayedTime.setPosition((window.getSize().x - PlayedTime.getGlobalBounds().width) / 2, ((window.getSize().y - PlayedTime.getGlobalBounds().height) / 2) - (window.getSize().y/10));
}
void ExhaustCount() {
    if (ExhaustCounter == 40) {
        ExhaustCounter = 0;
    }
    else {
        ExhaustCounter++;
    }
}
void UpdateCharacterPicker() {
    CharacterPickerPlayers[0]->ExhaustAnimation(ExhaustCounter);
    CharacterPickerPlayers[1]->ExhaustAnimation(ExhaustCounter);

    //animacja pociskow
    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i]->AnimateBoolet();
    }
    //animacja eksplozji
    for (int i = 0; i < explosions.size(); i++) {
        explosions[i]->Display();
        if (explosions[i]->GetFrameCounter() >= 66) {
            explosions.erase(explosions.begin() + i);
        }
    }
    //animacja exhaustów
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->ExhaustAnimate(ExhaustCounter);
    }
    for (int i = 0; i < projectiles.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (projectiles[i]->GetBody().getGlobalBounds().intersects(enemies[j]->GetBody().getGlobalBounds())) {
                if (projectiles[i]->BulletType() == 5) {
                    explosions.push_back(new Explosion_5(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y)));
                }
                if (projectiles[i]->BulletType() == 6) {
                    explosions.push_back(new Explosion_6(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y)));
                }
                projectiles.erase(projectiles.begin() + i);
                enemies.erase(enemies.begin() + j);
                break;
            }
        }
    }
    for (int i = 0; i < projectiles.size(); i++) {
        projectiles[i]->BulletMove();
    }
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->EnemyMovement(DificultyFactor,*CharacterPickerPlayers[0]);
    }
    if (TimeFactorCounter == 15) {
        CharacterPickerPlayers[0]->Schoot(projectiles);
        CharacterPickerPlayers[1]->Schoot(projectiles);
    }
    if (TimeFactorCounter == 30) {
        enemies.push_back(new Enemy_normal(window.getSize().y/2, window));
        enemies.push_back(new Enemy_normal(window.getSize().y / 2, window, window.getSize().x / 2));
    }
    if (FramesCounter % 360 == 0) {
        CharacterPickerPlayers[0]->MakeInvincibleFor(0.03, TimeFactor);
        CharacterPickerPlayers[1]->MakeInvincibleFor(0.03, TimeFactor);
    }
    CharacterPickerPlayers[0]->InvincibilityEndCheck(TimeFactor);
    CharacterPickerPlayers[1]->InvincibilityEndCheck(TimeFactor);
    ExhaustCount();
    GameFactor();

}
void DrawCharacterPicker() {
    window.clear(Color::Black);
    for (int i = 0; i < explosions.size(); i++) {
        window.draw(explosions[i]->GetBody());
    }
    for (int i = 0; i < enemies.size(); i++) {
        window.draw(enemies[i]->GetBody());
        window.draw(enemies[i]->GetExhaust());
    }
    for (int i = 0; i < projectiles.size(); i++) {
        window.draw(projectiles[i]->GetBody());
    }
    if (TimeFactorCounter<30) {
        window.draw(ChoicePlayer);
    }
    window.draw(CharacterPickerPlayers[0]->GetShip());
    window.draw(CharacterPickerPlayers[0]->GetExhaust());
    window.draw(CharacterPickerPlayers[1]->GetShip());
    window.draw(CharacterPickerPlayers[1]->GetExhaust());

    window.display();
}