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
void Player::PlayerMovement(RenderWindow &window) {
    if (Keyboard::isKeyPressed(Keyboard::W) && ship.getPosition().y >= 0) {
        movementY = -1 * MovementFactor;
    }
    if (Keyboard::isKeyPressed(Keyboard::W) && ship.getPosition().y < 0) {
        movementY = 0;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && ship.getPosition().y + ship.getGlobalBounds().height <= window.getSize().y) {
        movementY = MovementFactor;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && ship.getPosition().y + ship.getGlobalBounds().height  > window.getSize().y) {
        movementY = 0;
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && ship.getPosition().x <= window.getSize().x) {
        movementX = MovementFactor;
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && ship.getPosition().x > window.getSize().x) {
        movementX = 0;
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && ship.getPosition().x >= 5) {
        movementX = -1 * MovementFactor;
    }
    if (Keyboard::isKeyPressed(Keyboard::A) && ship.getPosition().x < 5) {
        movementX = 0;
    }
    if (!Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::S)) {
        movementY = 0;
    }
    if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::D)) {
        movementX = 0;
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
void Player::ShowHp(float i,RenderWindow &window) {
    if (hp>0) {
        Sprite hart;
        hart.setTexture(HeartTexture);
        hart.setScale(0.2f,0.2f);
        hart.setPosition(i * 30.0, 5.f);
        window.draw(hart);
        //std::cout << hp << std::endl;
    }
}
void Player::ShowSkill(float i, RenderWindow& window) {
    //if (SkillUsageLeft > 0) {
    //    Sprite prodjectile;
    //    prodjectile.setTexture(Bullet::BodyTexture);
    //    prodjectile.setTextureRect(IntRect(116, 0, 58, 12));
    //    prodjectile.setScale(1.5f, 1.5f);
    //    prodjectile.rotate(-15);
    //    prodjectile.setPosition(i * 45 - 25, window.getSize().y-25);
    //    window.draw(prodjectile);
    //}
}
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
