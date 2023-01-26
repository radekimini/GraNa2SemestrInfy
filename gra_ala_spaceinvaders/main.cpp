// lini kodu 1170
//iloœæ klass 21
// 
// nie dzia³a poruszanie playerem nr 2 
// nie dzia³¹ pokazywanie siê ekranu wyników gry jest 2 playerów
//
//Ship 5 to player[0]
// 
//


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
void CurrentPointsFontSet();
void EnemySpawner();

void UpdateCharacterPicker();
void DrawCharacterPicker();

bool CharacterPicked = false;
int NumberOfPlayers = 2;
bool secondPlayerGotKilled = false;
//RenderWindow window(VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Super Gra!!!", Style::Fullscreen);
RenderWindow window(VideoMode(1000,600), "Super Gra!!!", Style::Default);

std::vector<Player*>PlayablePlayers;
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
std::vector<Text> CurrentPoints;
Text LastScore;
Text ChoicePlayer;;
Text pressEsc;
Text PlayedTime;

int main() {
    srand(time(NULL));
    window.setFramerateLimit(60);
    SetStartingVariablesAndOptions();
    while (window.isOpen()) {
        if (NumberOfPlayers == 0) {
            //okno wyboru iloœci graczy
        }

        while (!CharacterPicked && NumberOfPlayers == 1) {
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
                    PlayablePlayers.push_back(new Player_5(window, true));
                }
                if ((Keyboard::isKeyPressed(Keyboard::Right)) || (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && event.mouseButton.x > window.getSize().x / 2)) {
                    CharacterPicked = true;
                    PlayablePlayers.push_back(new Player_6(window, true));
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
                return 0;
            }
            if (CharacterPicked) {
                CurrentPoints.push_back(Text());
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
                CurrentPointsFontSet();
            }
        }
        if (NumberOfPlayers == 2 && PlayablePlayers.size() < 2) {
            PlayablePlayers.push_back(new Player_5(window, true));
            CurrentPoints.push_back(Text());
            PlayablePlayers.push_back(new Player_6(window, true));
            CurrentPoints.push_back(Text());
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
            CurrentPointsFontSet();
            secondPlayerGotKilled = false;
        }
        Event event;

        while (window.pollEvent(event)) {
        //Game close
            if (event.type == Event::Closed) {
                window.close();
            }
            if (PlayablePlayers[0]->Gethp() > 0) {
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                    PlayablePlayers[0]->Schoot(projectiles);
                }
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::E) {
                    PlayablePlayers[0]->UseSkill(projectiles,window);
                }
            }
            if (NumberOfPlayers == 2 && PlayablePlayers[1]->Gethp() > 0) {
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::RControl) {
                    PlayablePlayers[1]->Schoot(projectiles);
                }
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::RShift) {
                    PlayablePlayers[1]->UseSkill(projectiles, window);
                }
            }
        }
        //game close
        if ((Keyboard::isKeyPressed(Keyboard::Enter) && PlayablePlayers[0]->Gethp() > 1 && NumberOfPlayers == 1) || (Keyboard::isKeyPressed(Keyboard::Enter) && PlayablePlayers[0]->Gethp() < 1 && PlayablePlayers[1]->Gethp() < 1 && NumberOfPlayers == 2)) { // nie dzia³¹ dla 2 graczy
            PlayedTime.setString("");
            LastScore.setPosition((window.getSize().x - LastScore.getGlobalBounds().width) / 2, (window.getSize().y - LastScore.getGlobalBounds().height) / 5);
            CharacterPicked = false;
            explosions.clear();
            enemies.clear();
            projectiles.clear();
            enemiesParts.clear();
            boosts.clear();
            PlayablePlayers.clear();
            CurrentPoints.clear();
            NumberOfPlayers == 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        if ((PlayablePlayers[0]->Gethp() > 0 && NumberOfPlayers == 1)) {
            EnemySpawner();
            GameFactor();
            Update();
            Draw();
        }
        else if ((PlayablePlayers[0]->Gethp() > 0 || PlayablePlayers[1]->Gethp() > 0) && NumberOfPlayers == 2) {   // Poprawiæ warunek by wywala³ sie jak jeden straci Hp tylko oba
            EnemySpawner();
            GameFactor();
            Update();
            Draw();
        }
        else{
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
    for (int j = 0; j < PlayablePlayers.size(); j++) {
        if (PlayablePlayers[j]->Gethp() > 0) {
            for (int i = 0; i < PlayablePlayers[j]->Gethp(); i++) {
                PlayablePlayers[j]->ShowHp(i,window,j);
            }
            for (int i = 0; i < PlayablePlayers[j]->GetSkillUsageLeft(); i++) {
                PlayablePlayers[j]->ShowSkill(i,window,j);
            }
        }
    }
    //rysowanie punktow
    if (NumberOfPlayers == 2) {
        for (int i = 0; i < CurrentPoints.size(); i++) {
            CurrentPoints[i].setPosition((window.getSize().x / 2) + (window.getSize().x / 2 * i) - CurrentPoints[i].getGlobalBounds().width, 5.f);
            CurrentPoints[i].setString("Points: " + std::to_string(PlayablePlayers[i]->GetPoints()));
            window.draw(CurrentPoints[i]);
        }
    }
    else if (NumberOfPlayers == 1) {
        CurrentPoints[0].setString("Points: " + std::to_string(PlayablePlayers[0]->GetPoints()));
        CurrentPoints[0].setPosition((window.getSize().x) - 10 - CurrentPoints[0].getGlobalBounds().width, 5.f);
        window.draw(CurrentPoints[0]);
    }
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
    //rysowanie Playerów
    for (int i = 0; i < PlayablePlayers.size(); i++) {
        if (PlayablePlayers[i]->Gethp() > 0) {
            window.draw(PlayablePlayers[i]->GetShip());
            window.draw(PlayablePlayers[i]->GetExhaust());
        }
    }
    window.display();
}
void Update() {
    //update ruchu playerów
    for (int i = 0; i < PlayablePlayers.size(); i++) {
        if (PlayablePlayers[i]->Gethp() > 0) {
        PlayablePlayers[i]->PlayerMovement(window, i);
        PlayablePlayers[i]->ExhaustAnimation(ExhaustCounter);
        PlayablePlayers[i]->InvincibilityEndCheck(TimeFactor);
        }
        else if (NumberOfPlayers == 2){
            for (int i = 0; i < enemies.size(); i++) {
                if (enemies[i]->GetClassName() == "SEEKER") {
                    if (PlayablePlayers[0]->Gethp() == 0) {
                        enemies[i]->SetSeekingWhom(1);
                    }
                    else {
                        enemies[i]->SetSeekingWhom(0);
                    }
                }
            }
            PlayablePlayers[i]->PlayerLostHp();
            secondPlayerGotKilled = true;
        }
    }
    // ruch i dotarcie do konca bulletow
    for (int i = 0; i < projectiles.size(); i++) {
        if (projectiles[i]->BulletDestroy(window)) {
            if (NumberOfPlayers == 1) {
                PlayablePlayers[0]->TakePoints(2);
            }
            else if (NumberOfPlayers == 2) {
                if (projectiles[i]->BulletType() == 5) {
                    PlayablePlayers[0]->TakePoints(2);
                }
                else if (projectiles[i]->BulletType() == 6) {
                    PlayablePlayers[1]->TakePoints(2);
                }
            }
            projectiles.erase(projectiles.begin()+i);
        }
        else {
            projectiles[i]->BulletMove();
        }
    }
    // czy enemy doszed³ do koñca
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i]->EnemyAtEnd(window)) {
            enemies.erase(enemies.begin()+i);
            if (NumberOfPlayers == 1) {
                PlayablePlayers[0]->TakePoints(50);
            }
        }
        enemies[i]->EnemyMovement(DificultyFactor,PlayablePlayers);
    }
    // kolizja buulet z enemies
    for (int i = 0; i < projectiles.size(); i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (projectiles[i]->GetBody().getGlobalBounds().intersects(enemies[j]->GetBody().getGlobalBounds())) {
                if (enemies[j]->GetClassName() == "BOOST") {
                    int spawnCheck = rand() % 101;
                    spawnCheck = 1;
                    if (spawnCheck < 20) {
                        boosts.push_back(new Boost_invincible(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y), TimeFactor));
                    }
                    enemiesParts.push_back(new Parts_boost(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y,TimeFactor));
                }
                else if (enemies[j]->GetClassName() == "SEEKER") {
                    int spawnCheck = rand() % 101;
                    spawnCheck = 1;
                    if (spawnCheck < 10) {
                        boosts.push_back(new Boost_hp(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y), TimeFactor));
                    }
                    enemiesParts.push_back(new Parts_seeker(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y,TimeFactor));
                }
                else if (enemies[j]->GetClassName() == "NORMAL") {
                    int spawnCheck = rand() % 101;
                    spawnCheck = 1;
                    if (spawnCheck < 10) {
                        if (NumberOfPlayers == 1) {
                            boosts.push_back(new Boost_Skill(Vector2f(enemies[j]->GetBody().getPosition().x-55, enemies[j]->GetBody().getPosition().y), TimeFactor,PlayablePlayers[0]->GetWich()));
                        }
                        else if (NumberOfPlayers == 2) {
                            if (projectiles[i]->BulletType() == 5) {
                            boosts.push_back(new Boost_Skill(Vector2f(enemies[j]->GetBody().getPosition().x-55, enemies[j]->GetBody().getPosition().y), TimeFactor,5));
                            }
                            else if (projectiles[i]->BulletType() == 6) {
                            boosts.push_back(new Boost_Skill(Vector2f(enemies[j]->GetBody().getPosition().x-55, enemies[j]->GetBody().getPosition().y), TimeFactor,6));
                            }
                        }
                    }
                    enemiesParts.push_back(new Parts_normal(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y,TimeFactor));
                }
                if (projectiles[i]->BulletType() == 5) {
                explosions.push_back(new Explosion_5(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y)));
                }
                if (projectiles[i]->BulletType() == 6) {
                explosions.push_back(new Explosion_6(Vector2f(enemies[j]->GetBody().getPosition().x, enemies[j]->GetBody().getPosition().y)));
                }
                if (NumberOfPlayers == 1) {
                    PlayablePlayers[0]->GetKill(DificultyFactor);
                }
                else if (NumberOfPlayers == 2) {
                    if (projectiles[i]->BulletType() == 5) {
                        PlayablePlayers[0]->GetKill(DificultyFactor);
                    }
                    else if (projectiles[i]->BulletType() == 6) {
                        PlayablePlayers[1]->GetKill(DificultyFactor);
                    }
                }
                projectiles.erase(projectiles.begin() + i);
                enemies.erase(enemies.begin() + j);
               break;
            }
        }
    }
    // kolizja PlayablePlayera z enemies
    for (int i = 0; i < enemies.size(); i++) {
        for (int j = 0; j < PlayablePlayers.size(); j++) {
            if (PlayablePlayers[j]->GetShip().getGlobalBounds().intersects(enemies[i]->GetBody().getGlobalBounds())) {
                if (PlayablePlayers[j]->GetWich() == 5) {
                    explosions.push_back(new Explosion_5(Vector2f(enemies[i]->GetBody().getPosition().x, enemies[i]->GetBody().getPosition().y)));
                }
                if (PlayablePlayers[j]->GetWich() == 6) {
                    explosions.push_back(new Explosion_6(Vector2f(enemies[i]->GetBody().getPosition().x, enemies[i]->GetBody().getPosition().y)));
                }
                enemies.erase(enemies.begin() + i);
                if (!PlayablePlayers[j]->IsInvincible()) {
                    PlayablePlayers[j]->ReciveDamage();
                }
            }
        }
    }
    // kolizja PlayablePlayersa z boostami
    for (int i = 0; i < boosts.size(); i++) {
        for (int j = 0; j < PlayablePlayers.size(); j++) {
            if (PlayablePlayers[j]->GetShip().getGlobalBounds().intersects(boosts[i]->GetBody().getGlobalBounds())) {
                if (boosts[i]->GetClassName() == "INVINCIBLE") {
                    PlayablePlayers[j]->MakeInvincibleFor(0.03, TimeFactor);
                }
                else if (boosts[i]->GetClassName() == "HP") {
                    PlayablePlayers[j]->addhp();
                }
                else if (boosts[i]->GetClassName() == "SKILL") {
                    PlayablePlayers[j]->AddSkillUsage();
                }
                boosts.erase(boosts.begin() + i);
            }
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

void EnemySpawner() {
    if (Enemy::SpawnTimer > (46 - (TimeFactor * 5))) {
        int SpawnCheck = rand() % 101;
        if (SpawnCheck < 2.0 + ((DificultyFactor - 1.0) * 10.0) + 1.0) {
            int whitchEnemy = rand() % 3;
            whitchEnemy = 2;
            //std::cout << whitch << std::endl;
            int pos = 50 + rand() % (window.getSize().y - 200);
            if (whitchEnemy == 0) {
                enemies.push_back(new Enemy_normal(pos, window));
            }
            if (whitchEnemy == 1) {
                enemies.push_back(new Enemy_boost(pos, window));
            }
            if (whitchEnemy == 2) {
                if (NumberOfPlayers == 1) {
                    enemies.push_back(new Enemy_seeker(pos, window));
                }
                if (NumberOfPlayers == 2) {
                    if (secondPlayerGotKilled) {
                        if (PlayablePlayers[0]->Gethp() < 1) {
                            enemies.push_back(new Enemy_seeker(pos, window, 0));
                        }
                        else {
                            enemies.push_back(new Enemy_seeker(pos, window, 1));
                        }
                    }
                    else {
                        int los = rand() % NumberOfPlayers;
                        enemies.push_back(new Enemy_seeker(pos, window, los));
                    }
                }
            }
        }
    }
    else { Enemy::SpawnTimer++; }
}


void GameFactor() {
    if (DificultyFactor < 2) {
        if (DificultyFactorCounter > 60) {
            DificultyFactor += 0.01;
            DificultyFactorCounter = 0;
            for (int i = 0; i < PlayablePlayers.size(); i++) {
            PlayablePlayers[i]->SetMovementFactor(DificultyFactor);
            }
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
}
void CurrentPointsFontSet() {
    for (int i = 0; i < CurrentPoints.size(); i++) {
        CurrentPoints[i].setFont(font);
        CurrentPoints[i].setCharacterSize(window.getSize().y / 30);
        CurrentPoints[i].setFillColor(Color::White);
    }
}
void GameOver() {
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
void GameOverFontSet() {
    if (NumberOfPlayers == 1) {
    LastScore.setString("FINAL SCORE:" + std::to_string(PlayablePlayers[0]->GetPoints()));
    }
    else if (NumberOfPlayers == 2) {
        if (PlayablePlayers[0]->GetPoints() > PlayablePlayers[1]->GetPoints()) {
            LastScore.setString("PLAYER 1 WINS: " + std::to_string(PlayablePlayers[0]->GetPoints()));
        }
        else {
            LastScore.setString("PLAYER 2 WINS: " + std::to_string(PlayablePlayers[0]->GetPoints()));
        }
    }
    LastScore.setPosition((window.getSize().x - LastScore.getGlobalBounds().width) / 2, (window.getSize().y - LastScore.getGlobalBounds().height) / 5);
    pressEsc.setPosition(((window.getSize().x - pressEsc.getGlobalBounds().width) / 2), ((window.getSize().y - pressEsc.getGlobalBounds().height) / 2) + (window.getSize().y / 5));
    PlayedTime.setString("\nPlLAYED TIME " + std::to_string((int)(TimeFactor * 100)) + " sec");
    PlayedTime.setPosition((window.getSize().x - PlayedTime.getGlobalBounds().width) / 2, ((window.getSize().y - PlayedTime.getGlobalBounds().height) / 2) - (window.getSize().y/10));
    //std::cout << "ustawienia czcionek\n";
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
        enemies[i]->EnemyMovement(DificultyFactor,PlayablePlayers);
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