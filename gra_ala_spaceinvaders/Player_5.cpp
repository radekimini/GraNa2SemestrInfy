#include "Player_5.h"
Texture Player_5::BodyTexture;
Texture Player_5::ExhaustTexture;
Player_5::Player_5(RenderWindow& window, bool playable) {
    ship.setTexture(BodyTexture);
    ship.setScale(1.f, 1.f);
    Exhaust.setTexture(ExhaustTexture);
    Exhaust.setScale(2.f, 2.f);
    Exhaust.setTextureRect(IntRect(0, 0, 64, 64));
    if (playable) {
        ship.setPosition(Vector2f(Exhaust.getGlobalBounds().width, window.getSize().y / 2));
        Exhaust.setPosition(Vector2f(Exhaust.getGlobalBounds().width - 100.f, window.getSize().y / 2 - 18));
    }
    else {
        ship.setPosition(ExhaustTexture.getSize().x/4*3, (window.getSize().y / 2) - (ship.getGlobalBounds().height / 2));
        Exhaust.setPosition(ExhaustTexture.getSize().x / 4 * 3 - 100.f, (window.getSize().y / 2) - (ship.getGlobalBounds().height / 2) - 18);
    }
}
void Player_5::setTexture() {
}
void Player_5::Schoot(std::vector<Bullet*>& projectiles) {
    projectiles.push_back( new Bullet_5(Vector2f(ship.getPosition().x + (ship.getGlobalBounds().width / 2), ship.getPosition().y + (ship.getGlobalBounds().height / 2 + 10) ) ) );
}
void Player_5::UseSkill(std::vector<Bullet*>& projectiles, RenderWindow& window) {
    // 24 px wysokosc bulleta
    if (SkillUsageLeft > 0) {
        int BulletsFitsInWindow = window.getSize().y / 24;
        for (int i = 0; i < BulletsFitsInWindow; i++) {
            projectiles.push_back( new Bullet_5(Vector2f(0.f, 24 * i)));
        }
        SkillUsageLeft--;
    }
}
void Player_5::ShowSkill(float i, RenderWindow& window, int PlayerNumer) {
    if (SkillUsageLeft > 0) {
            Sprite prodjectile;
            prodjectile.setTexture(Bullet_5::BodyTexture);
            prodjectile.setTextureRect(IntRect(116, 0, 58, 12));
            prodjectile.setScale(1.5f, 1.5f);
            prodjectile.rotate(-15);
        if (PlayerNumer == 1) {
            prodjectile.setPosition(i * 45 - 25 + (window.getSize().x / 2), window.getSize().y - 25);
        }
        else {
            prodjectile.setPosition(i * 45 - 25, window.getSize().y - 25);
        }
            window.draw(prodjectile);
    }
}
int Player_5::GetWich() { return 5; }
