#include "Player.h"

Texture Player::HeartTexture;

Player::Player() {
	hp = 3;
    SkillUsageLeft = 2;
    Points = 0;
    movementX = 0;
    movementY = 0;
    MovementFactor = 7;
    Invincible = false;
    DificultyFactorWhenInvinciblility = 0;
    InvincibilityTime = 0;
}
void Player::PlayerMovement(RenderWindow &window, int WitchMovement) {
    if (WitchMovement == 0) {
        if (Keyboard::isKeyPressed(Keyboard::W) && ship.getGlobalBounds().top >= 0) {
            movementY = -1 * MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::W) && ship.getGlobalBounds().top < 0) {
            movementY = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && ship.getGlobalBounds().top + ship.getGlobalBounds().height <= window.getSize().y) {
            movementY = MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::S) && ship.getGlobalBounds().top + ship.getGlobalBounds().height  > window.getSize().y) {
            movementY = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && ship.getGlobalBounds().left + ship.getGlobalBounds().width <= window.getSize().x) {
            movementX = MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::D) && ship.getGlobalBounds().left + ship.getGlobalBounds().width  > window.getSize().x) {
            movementX = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && ship.getGlobalBounds().left >= 0) {
            movementX = -1 * MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::A) && ship.getGlobalBounds().left < 0) {
            movementX = 0;
        }
        if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S)) {
            movementY = 0;
        }
        if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
            movementX = 0;
        }
    }
    if (WitchMovement == 1) {
        if (Keyboard::isKeyPressed(Keyboard::Up) && ship.getGlobalBounds().top >= 0) {
            movementY = -1 * MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && ship.getGlobalBounds().top < 0) {
            movementY = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && ship.getGlobalBounds().top + ship.getGlobalBounds().height <= window.getSize().y) {
            movementY = MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && ship.getGlobalBounds().top + ship.getGlobalBounds().height  > window.getSize().y) {
            movementY = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && ship.getGlobalBounds().left + ship.getGlobalBounds().width <= window.getSize().x) {
            movementX = MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && ship.getGlobalBounds().left + ship.getGlobalBounds().width > window.getSize().x) {
            movementX = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && ship.getGlobalBounds().left >= 0) {
            movementX = -1 * MovementFactor;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && ship.getGlobalBounds().left < 0) {
            movementX = 0;
        }
        if (!Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Down)) {
            movementY = 0;
        }
        if (!Keyboard::isKeyPressed(Keyboard::Left) && !Keyboard::isKeyPressed(Keyboard::Right)) {
            movementX = 0;
        }
    }
    ship.move(movementX, movementY);
    Exhaust.move(movementX, movementY);
}
void Player::Schoot(std::vector<Bullet*>& projectiles) {}
void Player::GetKill(float factor) {
    Points += 100*factor;
}
void Player::ReciveDamage() {
    hp --;
    if (Points <= 500) {
        Points = 0;
    }
    else {
        Points -= 500;
    }
}
void Player::ShowHp(float i,RenderWindow &window, int PlayerNumer) {
        Sprite hart;
        hart.setTexture(HeartTexture);
        hart.setScale(0.2f,0.2f);
    if (PlayerNumer == 1) {
        hart.setPosition(i * 30.0 + (window.getSize().x / 2), 5.f);
    }
    else {
        hart.setPosition(i * 30.0, 5.f);
    }
        window.draw(hart);
}
void Player::ShowSkill(float i, RenderWindow& window, int PlayerNumer) {}
void Player::TakePoints(unsigned int ptk) {
    if (Points < ptk) {
        Points = 0;
    }
    else {
    Points -= ptk;
    }
}
void Player::SetMovementFactor(float factor) {
    MovementFactor = ((factor - 1) * 10) + 8;
}
void Player::MakeInvincibleFor(float sec, float factor) {
    DificultyFactorWhenInvinciblility = factor;
    InvincibilityTime = sec;
    Invincible = true;
}
void Player::InvincibilityEndCheck(float factor) {
    if (factor - DificultyFactorWhenInvinciblility >= InvincibilityTime && DificultyFactorWhenInvinciblility != 0) {
        Invincible = false;
        DificultyFactorWhenInvinciblility = 0;
        InvincibilityTime = 0;
    }
}
void Player::addhp() {
    hp++;
}
void Player::AddSkillUsage() {
    SkillUsageLeft++;
}

void Player::UseSkill(std::vector<Bullet*>& projectiles, RenderWindow& window) {
}
void Player::ExhaustAnimation(int ExhaustCounter) {
    if (Invincible) {
        if (ExhaustCounter == 10) {
            Exhaust.setTextureRect(IntRect(64, 64, 64, 64));
        }
        if (ExhaustCounter == 20) {
            Exhaust.setTextureRect(IntRect(128, 64, 64, 64));
        }
        if (ExhaustCounter == 30) {
            Exhaust.setTextureRect(IntRect(192, 64, 64, 64));
        }
        if (ExhaustCounter == 40) {
            Exhaust.setTextureRect(IntRect(0, 64, 64, 64));
        }
    }
    else {
        if (ExhaustCounter == 10) {
            Exhaust.setTextureRect(IntRect(64, 0, 64, 64));
        }
        if (ExhaustCounter == 20) {
            Exhaust.setTextureRect(IntRect(128, 0, 64, 64));
        }
        if (ExhaustCounter == 30) {
            Exhaust.setTextureRect(IntRect(192, 0, 64, 64));
        }
        if (ExhaustCounter == 40) {
            Exhaust.setTextureRect(IntRect(0, 0, 64, 64));
        }
    }
}
Sprite Player::GetExhaust() { return Exhaust; }
int Player::Gethp() { return hp; }
int Player::GetSkillUsageLeft() { return SkillUsageLeft; }
Sprite Player::GetShip() {return ship;}
bool Player::IsInvincible() { return Invincible; }
unsigned int Player::GetPoints() { return Points; }
int Player::GetWich() { return 0; }
void Player::PlayerLostHp() {
    if (hp == 0) {
        ship.setPosition(-100.f, -100.f);
        hp--;
    }
}
