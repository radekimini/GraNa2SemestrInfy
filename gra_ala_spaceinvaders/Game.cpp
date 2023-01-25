#include "Game.h"

//VideoMode(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height), "Super Gra!!!", Style::Fullscreen

Game::Game(RenderWindow &window) {
    if (!font.loadFromFile("game_font.otf")) {
        std::cout << "Font file not found" << std::endl;
    }
    else {
        SetFont(window);
    }
    Event event;
    Player player();
    DificultyFactor = 1;
    DificultyFactorCounter = 0;
    textEscCounter = 0;
}

void Game::Play(RenderWindow &window) {

        Event event;
        while (window.pollEvent(event)) {
            //Game close
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                projectiles.push_back(player.Schoot());
            }
        }
        //game close

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        if (player.Gethp() > 0) {
            if (Enemy::SpawnTimer > 46) {
                int SpawnCheck = rand() % 101;
                if (SpawnCheck < 2.0 + ((DificultyFactor - 1.0) * 10.0) + 1.0) {
                    int pos = 25 + rand() % (window.getSize().y - 200);
                    enemies.push_back(Enemy(pos, window));
                }
            }
            else { Enemy::SpawnTimer++; }

            GameFactor();
            Update(window);
            Draw(window);
        }
        else {
            GameOver(window);
        }

}

void Game::Draw(RenderWindow& window) {
    window.clear(Color::Black);
    for (size_t i = 0; i < enemies.size(); i++) {
        window.draw(enemies[i].GetBody());
    }
    for (size_t i = 0; i < projectiles.size(); i++) {
        window.draw(projectiles[i].GetBody());
    }
    window.draw(player.GetShip());
    for (int i = 0; i < player.Gethp(); i++) {
        player.ShowHp(i, window);
    }
    CurrentPoints.setPosition(window.getSize().x - 10 - CurrentPoints.getGlobalBounds().width, 5.f);
    CurrentPoints.setString("Points: " + std::to_string(player.GetPoints()));
    window.draw(CurrentPoints);

    window.display();
}
void Game::Update(RenderWindow& window){
    player.PlayerMovement(window);
    for (size_t i = 0; i < projectiles.size(); i++) {
        if (projectiles[i].BulletDestroy(window)) {
            projectiles.erase(projectiles.begin() + i);
            player.TakePoints(2);
        }
        projectiles[i].BulletMove();
    }
    for (size_t i = 0; i < enemies.size(); i++) {
        if (enemies[i].EnemyAtEnd(window)) {
            enemies.erase(enemies.begin() + i);
            player.TakePoints(50);
        }
        enemies[i].EnemyMovement(DificultyFactor);
    }

    for (size_t i = 0; i < projectiles.size(); i++) {
        for (size_t j = 0; j < enemies.size(); j++) {
            if (projectiles[i].GetBody().getGlobalBounds().intersects(enemies[j].GetBody().getGlobalBounds())) {
                player.GetKill(DificultyFactor);
                projectiles.erase(projectiles.begin() + i);
                enemies.erase(enemies.begin() + j);
                break;
            }
        }
    }
    for (size_t i = 0; i < enemies.size(); i++) {
        if (player.GetShip().getGlobalBounds().intersects(enemies[i].GetBody().getGlobalBounds())) {
            enemies.erase(enemies.begin() + i);
            player.ReciveDamage();
        }
    }
}
void Game::GameFactor() {
    if (DificultyFactorCounter > 60) {
        DificultyFactor += 0.01;
        DificultyFactorCounter = 0;
        player.SetMovementFactor(DificultyFactor);
    }
    else {
        DificultyFactorCounter++;
    }
}
void Game::SetFont(RenderWindow &window) {
    LastScore.setFont(font);
    LastScore.setCharacterSize(window.getSize().y / 7);
    LastScore.setFillColor(Color::White);
    CurrentPoints.setFont(font);
    CurrentPoints.setCharacterSize(window.getSize().y / 30);
    CurrentPoints.setFillColor(Color::White);
    pressEsc.setFont(font);
    pressEsc.setFillColor(Color::White);
    pressEsc.setCharacterSize(window.getSize().y / 15);
    pressEsc.setString("PRESS ESCAPE TO QUIT");
}
void Game::GameOver(RenderWindow& window) {
    window.clear(Color::Black);
    LastScore.setString("FINAL SCORE:" + std::to_string(player.GetPoints()));
    LastScore.setPosition((window.getSize().x - LastScore.getGlobalBounds().width) / 2, (window.getSize().y - LastScore.getGlobalBounds().height) / 2.5);
    window.draw(LastScore);
    if (textEscCounter <= 60) {
        pressEsc.setPosition(((window.getSize().x - pressEsc.getGlobalBounds().width) / 2), ((window.getSize().y - pressEsc.getGlobalBounds().height) / 2) + (window.getSize().y / 5));
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
// gety
//RenderWindow Game::GetWindow() { return window; }
float Game::GetDificultyFactor() { return DificultyFactor; }
unsigned int Game::GetDificultyFactorCounter() { return DificultyFactorCounter; }
unsigned int Game::GetTextEscCounter() { return textEscCounter; }
Text Game::GetLastScore() { return LastScore; }
Text Game::GetCurrentPoints() { return CurrentPoints; }
Text Game::GetPressEsc() { return pressEsc; }
Player Game::GetPlayer() { return player; }
