#include "eniesLobby.h"

/*
 * BattleContext
 */
BattleContext::BattleContext() {
    turnCount = 0;
    morale = 0;
    alarmLevel = 0;
    rescueProgress = 0;
    escapeProgress = 0;
    busterCallTimer = 0;
    mainGateDestroyed = false;
    robinRescued = false;
    bridgeOpened = false;
    battleEnded = false;
    resultCode = "";
}

void BattleContext::nextTurn() {
    turnCount++;
}

/*
 * Character
 */
Character::Character() {
    name = "";
    hp = 0;
    maxHp = 0;
    atk = 0;
    def = 0;
    speed = 0;
    energy = 0;
    alive = false;
}

Character::Character(string name, int hp, int atk, int def, int speed, int energy) {
    this->name = name;
    this->hp = hp;
    maxHp = hp;
    this->atk =atk;
    this->def =def;
    this->speed=speed;
    this->energy= energy;
    alive = (hp>0);
}

Character::~Character() {
    // TODO: implement if needed
}

int Character::attack(Building* target, BattleContext& context) {
    return 0;
}

int Character::specialSkill(Building* target, BattleContext& context) {
    return 0;
}

void Character::endTurn(BattleContext& context) {
    return ;
}

void Character::receiveDamage(int damage) {
    int realDamage = damage - def;
    if (realDamage > 0){
        hp -=realDamage;
        if(hp<=0) {
            hp = 0;
            alive = false;
        }
    }
}

bool Character::isAlive() const {
    // TODO: implement
    return alive;
}

string Character::getName() const {
    // TODO: implement
    return name;
}

int Character::getHP() const {
    // TODO: implement
    return hp;
}

int Character::getEnergy() const {
    // TODO: implement
    return energy;
}

bool Character::isStrawHat() const {
    return false;
}

bool Character::isCP9() const {
    return false;
}

/*
 * StrawHat
 */
StrawHat::StrawHat() : Character() {
    bounty = 0;
}

StrawHat::StrawHat(string name, int hp, int atk, int def,
                   int speed, int energy, long long bounty)
                    :Character( name,  hp,  atk,  def, speed,  energy)
{
    defeatedEnemy = false; 
    this->bounty = bounty;
    this->maxHp = hp;
}

bool StrawHat::isStrawHat() const {
    return true;
}
string StrawHat::str() const {
    return "StrawHat[name=" + name + ", hp=" + to_string(hp) + ", atk=" + to_string(atk) + ", def=" + to_string(def) + ", speed=" + to_string(speed)+ ", energy=" + to_string(energy) + ", bounty=" +to_string(bounty) + "]";
}

/*
 * Luffy
 */
Luffy::Luffy(string name, int hp, int atk, int def,
             int speed, int energy, long long bounty):StrawHat(name,hp,atk,def,speed,energy,bounty) 
             { 
    this->maxHp = hp;
}
int Luffy::attack(Character* target, BattleContext& context) {
    int damage = 0;
    if (hp > maxHp*0.5) damage = atk;
    else if ( (hp > maxHp*0.3) && (hp<=maxHp*0.5))  damage = ceil(atk*1.15);
    else if ( (hp <= maxHp*0.3)) damage = ceil(atk*1.3);
    bool wasAlive = target->isAlive();
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive){
        context.morale+=5;
        if(context.morale>100) context.morale = 100;
        defeatedEnemy =true;    
    }
    return realDam;
}

int Luffy::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 20 && hp >=ceil(maxHp*0.15)){
        int damage = ceil(atk*2);
        energy-= 20;
        if ( energy < 0) energy = 0;
        speed+=15;
        atk+=15;
        context.alarmLevel+=10;
        if ( context.alarmLevel > 100) context.alarmLevel = 100;
        hp-=ceil(maxHp*0.08);
        if (hp<=0) {hp = 0; alive = false;}
        bool wasAlive = target->isAlive();
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        target->receiveDamage(damage);
        if ( target->isAlive()!= 1 && wasAlive){
        defeatedEnemy =true;    
        }
    return realDam;
    }
return 0;
}
int Luffy::attack(Building* target, BattleContext& context) {
    int damage = 0;
    if (hp > maxHp*0.5) damage = atk;
    else if ( (hp > maxHp*0.3) && (hp<=maxHp*0.5))  damage = ceil(atk*1.15);
    else if ( (hp <= maxHp*0.3)) damage = ceil(atk*1.3);
    target->receiveDamage(damage);
    if(target->isDestroyed()){
        target->onDestroyed(context);
    }
    return damage;
}

int Luffy::specialSkill(Building* target, BattleContext& context){
    if(energy >= 20 && hp >=ceil(maxHp*0.15)){
        int damage = ceil(atk*2);
        energy-= 20;
        if ( energy < 0) energy = 0;
        speed+=15;
        atk+=15;
        context.alarmLevel+=10;
        if ( context.alarmLevel > 100) context.alarmLevel = 100;
        hp-=ceil(maxHp*0.08);
        if (hp<=0) {hp = 0; alive = false;}
        target->receiveDamage(damage);
        if(target->isDestroyed()){
        target->onDestroyed(context);
    }
    return damage;
    }
return 0;
}

void Luffy::endTurn(BattleContext& context) {
    if ( hp<=ceil(maxHp*0.3)) {
        context.morale+=3; 
        if (context.morale > 100) context.morale = 100;
    }
    if (defeatedEnemy){
        energy+=5;
        if ( energy >100) energy = 100;
        defeatedEnemy = false;
    }   
    }

/*
 * Zoro
 */
Zoro::Zoro(string name, int hp, int atk, int def,
           int speed, int energy, long long bounty) 
           :StrawHat(name,hp,atk,def,speed,energy,bounty)
{
}

int Zoro::attack(Character* target, BattleContext& context) {
    int damage = atk + ceil(def*0.2);
    if ( target->getHP() < target->getmaxHp()*0.4) damage= ceil(damage*1.15);
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive) {
        defeatedEnemy =true;
    }
    return realDam;
}

int Zoro::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 15){
        int damage = ceil(atk*2.2);
        if ( target->getHP() < target->getmaxHp()*0.5) damage = ceil(damage*1.5);
        energy-= 15;    
        if ( energy < 0) energy = 0;
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if ( target->isAlive()!= 1 && wasAlive) {
            context.morale+=4;
            if(context.morale>100) context.morale = 100;
            energy+=8;
            if (energy > 100) energy = 100;
            defeatedEnemy =true;
        }   
    return realDam;
    }
    return 0;
}

int Zoro::attack(Building* target, BattleContext& context) {
    int damage = atk + ceil(def*0.2);
    if ( target->getHP() < target->getmaxHP()*0.4) damage= ceil(damage*1.15);
    target->receiveDamage(damage);
    if(target->isDestroyed()){
    target->onDestroyed(context);
    }
    return damage;
}

int Zoro::specialSkill(Building* target, BattleContext& context) {
    if(energy >= 15){
        int damage = ceil(atk*2.2);
        if ( target->getHP() < target->getmaxHP()*0.5) damage = ceil(damage*1.5);
        energy-= 15;    
        if ( energy < 0) energy = 0;
        target->receiveDamage(damage);
    if(target->isDestroyed()){
    target->onDestroyed(context);
    }
    return damage;
    }
    return 0;
}
void Zoro::endTurn(BattleContext& context) {
    if(defeatedEnemy){
        context.morale +=6;
        if (context.morale>100) context.morale = 100;
        atk = ceil(atk*1.05);
        defeatedEnemy = false;
    }
}

/*
 * Sanji
 */
Sanji::Sanji(string name, int hp, int atk, int def,
             int speed, int energy, long long bounty) 
             :StrawHat(name,hp,atk,def,speed,energy,bounty)
    {
}

int Sanji::attack(Character* target, BattleContext& context) {
    int damage = atk + ceil(0.5*speed);
    if ( target->getDEF() < def) damage = ceil(damage*1.1);
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive) {
        defeatedEnemy =true;
    }
    return realDam;
}

int Sanji::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 18){
        int damage = ceil(atk*2.1);
        energy-= 18;    
        if ( energy < 0) energy = 0;
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if ( target->isAlive()!= 1 && wasAlive){
            defeatedEnemy =true;
        }
        if ( target->getName() == "Jabra"){
            target->cutDEF(12);
        }
        else{
            target->cutDEF(8);
        }

    return realDam;
    }
    return 0;
}

int Sanji::attack(Building* target, BattleContext& context) {
    int damage = atk + ceil(0.5*speed);
    target->receiveDamage(damage);
    if(target->isDestroyed()){
    target->onDestroyed(context);
    }
    return damage;
}

int Sanji::specialSkill(Building* target, BattleContext& context) {
    if(energy >= 18){
        int damage = ceil(atk*2.1);
        energy-= 18;    
        if ( energy < 0) energy = 0;
        target->receiveDamage(damage);
    if(target->isDestroyed()){
    target->onDestroyed(context);
    }
    return damage;
    }
    return 0;
}

void Sanji::endTurn(BattleContext& context) {
    if ( defeatedEnemy){
        context.morale +=8;
        if(context.morale>100) context.morale = 100;
        atk =ceil(atk*1.1);
        defeatedEnemy =false;
    }
}

/*
 * Nami
 */
Nami::Nami(string name, int hp, int atk, int def,
           int speed, int energy, long long bounty)
           :StrawHat(name,hp,atk,def,speed,energy,bounty) {
}

int Nami::attack(Character* target, BattleContext& context) {
    int damage = atk + ceil(0.3*target->getDEF());
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive) {
        defeatedEnemy =true;
    }
    return realDam;
}

int Nami::specialSkill(Character* target, BattleContext& context) {
   if(energy >= 20){
        int damage = atk + 40;
        energy-= 20;    
        if ( energy < 0) energy = 0;
        target->cutSpeed(10);
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if ( target->isAlive()!= 1 && wasAlive){
            defeatedEnemy =true;
        }
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        context.busterCallTimer++;
        context.alarmLevel-=5;
    return realDam;
    }
return 0;
}

int Nami::attack(Building* target, BattleContext& context) {
    int damage = ceil(0.5*atk);
    target->receiveDamage(damage);
    if(target->isDestroyed()){
        target->onDestroyed(context);
    }
    return damage;
}

int Nami::specialSkill(Building* target, BattleContext& context) {
     if(energy >= 20){
        int damage = ceil( atk * 1.5);
        energy-= 20;    
        if ( energy < 0) energy = 0;
        target->receiveDamage(damage);
        if(target->isDestroyed()){
            target->onDestroyed(context);
        }
        context.busterCallTimer++;
        context.alarmLevel-=5;
    return damage;
    }
return 0;
}
void Nami::endTurn(BattleContext& context) {
    if (defeatedEnemy){
        energy+=6;
        if (energy>100) energy = 100;
        context.morale+=5;
        if (context.morale>100) context.morale = 100;
        defeatedEnemy = false;
    }
}
/*
 * Chopper
 */
Chopper::Chopper(string name, int hp, int atk, int def,
                 int speed, int energy, long long bounty) 
             :StrawHat(name,hp,atk,def,speed,energy,bounty)
{
}

int Chopper::attack(Character* target, BattleContext& context) {
    int damage = atk;
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive) {
        defeatedEnemy =true;
    }
    return realDam;
}

int Chopper::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 15){   
    int restoreHP = 35 + ceil(atk * 0.5);
    energy-= 15;    
    if ( energy < 0) energy = 0;
    if( target->getName() == "Luffy"){
        context.morale +=5;
        if (context.morale>100) context.morale = 100;
    }
    target->restoreHp(restoreHP);
}
 return 0;
}
int Chopper::attack(Building* target, BattleContext& context) {
    return 0;
}

void Chopper::endTurn(BattleContext& context) {
    if (defeatedEnemy){
        defeatedEnemy = false;
    }
}

/*
 * Usopp
 */
Usopp::Usopp(string name, int hp, int atk, int def,
             int speed, int energy, long long bounty):StrawHat(name,hp,atk,def,speed,energy,bounty)
             {
            flagAttack = false;
}

int Usopp::attack(Character* target, BattleContext& context) {
    int damage = atk;
    flagAttack = 1;
    if (target->getSpeed() < 50) damage = ceil(damage*1.2);
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive) {
        defeatedEnemy =true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Usopp::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 16){
        int damage = ceil(0.8*atk);
        energy-= 16;    
        if ( energy < 0) energy = 0;
        target->cutSpeed(12);
        context.escapeProgress+=8;
        if (context.escapeProgress>100) context.escapeProgress = 100;
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if ( target->isAlive()!= 1 && wasAlive){
            defeatedEnemy =true;
        }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
    }
return 0;
}

int Usopp::attack(Building* target, BattleContext& context) {
    int damage = ceil(0.5*atk);
    target->receiveDamage(damage);
    if(target->isDestroyed()){
        target->onDestroyed(context);
    }
    return damage;
}

int Usopp::specialSkill(Building* target, BattleContext& context) {
    if(energy >= 16){
        int damage = ceil(0.8*atk);
        energy-= 16;    
        if ( energy < 0) energy = 0;
        context.escapeProgress+=8;
        if (context.escapeProgress>100) context.escapeProgress = 100;
        target->receiveDamage(damage);
        if(target->isDestroyed()){
        target->onDestroyed(context);
        }
    return damage;
    }
return 0;
}

void Usopp::endTurn(BattleContext& context) {
     if(flagAttack){
        context.morale +=10;
        if ( context.morale > 100) context.morale = 100;
        flagAttack = false;
    }
    if(defeatedEnemy) defeatedEnemy = false;
}

/*
 * Franky
 */
Franky::Franky(string name, int hp, int atk, int def,
               int speed, int energy, long long bounty) 
            :StrawHat(name,hp,atk,def,speed,energy,bounty)
{
}

int Franky::attack(Character* target, BattleContext& context) {
    int damage = ceil(atk+0.3*def);
    if ( target->isCP9()) damage =ceil(damage*1.1);
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive) {
        defeatedEnemy =true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Franky::specialSkill(Character* target, BattleContext& context) {
    int damage = 0;
    if ( energy >= 30){
        energy-=30;
        if ( energy < 0) energy = 0;
        damage = ceil(1.2);
    }
    else if ( energy >= 20){
        energy-=20;
        if ( energy < 0) energy = 0;
        damage = ceil(1.8*atk);
        if(target->isCP9()) target->cutSpeed(8);
        if(target->getName() == "Lucci") damage = ceil(damage*1.2);
    }
    if ( damage != 0){
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if ( target->isAlive()!= 1 && wasAlive) {
        defeatedEnemy =true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
    }
    return 0;
}

int Franky::attack(Building* target, BattleContext& context) {
    int damage = ceil(atk+0.3*def);
    target->receiveDamage(damage);
    if(target->isDestroyed()){
        target->onDestroyed(context);
    }
    return damage;
}

int Franky::specialSkill(Building* target, BattleContext& context) {
    int damage = 0;
    if ( energy >= 30){
        energy-=30;
        if ( energy < 0) energy = 0;
        target->isDestroyed();
        target->onDestroyed(context);
        return 0;
    }
    else if ( energy >= 20){
        energy-=20;
        if ( energy < 0) energy = 0;
        damage = ceil(1.8*atk);
    }
    if ( damage != 0){
        target->receiveDamage(damage);
        if(target->isDestroyed()){
        target->onDestroyed(context);
    }
    return damage;
    }
    return 0;
}

void Franky::endTurn(BattleContext& context) {
    if (hp>0.7*maxHp) def +=5;
    if ( hp < 0.3*maxHp) atk = ceil(atk*1.1);
    if ( defeatedEnemy){
        context.morale+=5;
        if (context.morale>100) context.morale = 100;
        defeatedEnemy = false;
    }
}

/*
 * CP9Agent
 */
CP9Agent::CP9Agent() : Character() {
    doriki = 0;
}

CP9Agent::CP9Agent(string name, int hp, int atk, int def,
                   int speed, int energy, int doriki) 
                :Character( name,  hp,  atk,  def, speed,  energy)
{
    this->doriki=doriki;
    defeatedEnemy = false; 
}

bool CP9Agent::isCP9() const {
    return true;
}

string CP9Agent::str() const {
    return "CP9[name=" + name + ",hp=" + to_string(hp) + ",atk=" + to_string(atk) + ",def=" + to_string(def) + ",speed=" + to_string(speed)+ ",energy=" + to_string(energy) + ",doriki=" +to_string(doriki) + "]";
}

/*
 * Lucci
 */
Lucci::Lucci(string name, int hp, int atk, int def,
             int speed, int energy, int doriki)
             :CP9Agent(name,  hp,  atk,  def, speed,  energy, doriki)
 {
}

int Lucci::attack(Character* target, BattleContext& context) {
    int damage = atk + ceil(doriki/20.0);
    if ( target->getHP() < ceil(0.5*target->getmaxHp())) damage = ceil(damage*1.2);
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if ( target->isAlive()!= 1 && wasAlive) {
        context.morale-=5;
        if (context.morale<=0) context.morale = 0;
        defeatedEnemy =true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Lucci::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 25){
        int damage = ceil(2.8*atk) + ceil(0.5*target->getDEF());
        energy-= 25;    
        if ( energy < 0) energy = 0;
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if ( target->isAlive()!= 1 && wasAlive){
            context.morale-=10;
            if (context.morale>100) context.morale = 100;
            defeatedEnemy =true;
        }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
    }
    return 0;
}

void Lucci::endTurn(BattleContext& context) {
    if ( hp < 0.4*maxHp) atk = ceil(atk*1.05); 
    if (defeatedEnemy) defeatedEnemy = false;
}

/*
 * Kaku
 */
Kaku::Kaku(string name, int hp, int atk, int def,
           int speed, int energy, int doriki) 
    :CP9Agent(name,  hp,  atk,  def, speed,  energy, doriki)
{
}

int Kaku::attack(Character* target, BattleContext& context) {
    int damage = atk;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if(!target->isAlive() && wasAlive) {
        defeatedEnemy =true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Kaku::specialSkill(Character* target, BattleContext& context) {
    if ( energy>=20){
        energy-=20;     
        //Đòn 1
        int totalDamage = 0;
        int damage1 = ceil(1.2*atk);
        totalDamage+=damage1;
        bool wasAlive = target->isAlive();
        target->receiveDamage(totalDamage);
        if(!target->isAlive() && wasAlive) {
            defeatedEnemy =true;
            return (totalDamage -target -> getDEF());
        }
        int damage2 = atk;
        totalDamage+=damage2;
        target->receiveDamage(totalDamage);
        if(!target->isAlive() && wasAlive) {
            defeatedEnemy =true;
            return totalDamage - target->getDEF();
        }
        int damage3 = ceil(0.8*atk);
        totalDamage+=damage3;
        target->receiveDamage(totalDamage);
        if(!target->isAlive() && wasAlive) {
            context.morale -= 5;
            if(context.morale < 0) context.morale = 0;
            defeatedEnemy =true;
            return totalDamage - target->getDEF();
        }
        else return totalDamage - target->getDEF();
    }
    return 0;
}

void Kaku::endTurn(BattleContext& context) {
    if ( defeatedEnemy){ 
        defeatedEnemy = false;
        context.morale -= 5;
        if(context.morale < 0) context.morale = 0;
    }
}

/*
 * Jabra
 */
Jabra::Jabra(string name, int hp, int atk, int def,
             int speed, int energy, int doriki)
             :CP9Agent(name,  hp,  atk,  def, speed,  energy, doriki)
{
}
int Jabra::attack(Character* target, BattleContext& context) {
    int damage = atk;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if(!target->isAlive() && wasAlive) {
        context.morale -= 5;
        if(context.morale < 0) context.morale = 0;
        defeatedEnemy = true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Jabra::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 18) {
        int damage =ceil(atk*1.5);
        if(hp < maxHp*0.3) damage= ceil(damage*1.25);
        energy -= 18;
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if(!target->isAlive() && wasAlive) {
            context.morale -= 5;
            if(context.morale < 0) context.morale = 0;
            defeatedEnemy = true;
        }
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        return realDam;
    }
    return 0;
}

void Jabra::endTurn(BattleContext& context) {
   if ( defeatedEnemy) defeatedEnemy = false;
}

/*
 * Blueno
 */
Blueno::Blueno(string name, int hp, int atk, int def,
               int speed, int energy, int doriki)
        :CP9Agent(name,  hp,  atk,  def, speed,  energy, doriki)
{
}

int Blueno::attack(Character* target, BattleContext& context) {
    int damage = atk;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if(!target->isAlive() && wasAlive) {
        defeatedEnemy = true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Blueno::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 15) {
        int damage = ceil(atk * 1.3);
        if(hp > maxHp * 0.5) damage += 20;
        else damage += 40;
        energy -= 15;
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if(!target->isAlive() && wasAlive) {
            defeatedEnemy = true;
        }
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        return realDam;
    }
    return 0;
}

void Blueno::endTurn(BattleContext& context) {
    if(defeatedEnemy) {
        defeatedEnemy = false;
        context.morale -= 5;
        if(context.morale < 0) context.morale = 0;
    }
}

/*
 * Kalifa
 */
Kalifa::Kalifa(string name, int hp, int atk, int def,
               int speed, int energy, int doriki) 
            :CP9Agent(name,  hp,  atk,  def, speed,  energy, doriki)
{
}

int Kalifa::attack(Character* target, BattleContext& context) {
    int damage = atk;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if(!target->isAlive() && wasAlive) {
        defeatedEnemy = true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Kalifa::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 18) {
        int damage = ceil(atk * 1.4);
        energy -= 18;
        if ( target->getName() =="Nami") context.morale-=8;
        else context.morale-=12;
        if(context.morale < 0) context.morale = 0;
        target->cutSpeed(6);
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if(!target->isAlive() && wasAlive) {
            defeatedEnemy = true;
        }
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        return realDam;
    }
    return 0;
}

void Kalifa::endTurn(BattleContext& context) {
    if(defeatedEnemy) defeatedEnemy = false;
}

/*
 * Kumadori
 */
Kumadori::Kumadori(string name, int hp, int atk, int def,
                   int speed, int energy, int doriki)
            :CP9Agent(name,  hp,  atk,  def, speed,  energy, doriki)
{
    // TODO: implement
}

int Kumadori::attack(Character* target, BattleContext& context) {
    int damage = atk;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if(!target->isAlive() && wasAlive) {
        defeatedEnemy = true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Kumadori::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 16) {
        int damage = 30 + ceil(doriki/10.0);
        energy -= 16;
        if ( hp <  0.4*maxHp) damage+=25;
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if(!target->isAlive() && wasAlive) {
            defeatedEnemy = true;
        }
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        return realDam;
    }
    return 0;
}

void Kumadori::endTurn(BattleContext& context) {
    if(defeatedEnemy) {
        defeatedEnemy = false;
         context.morale -= 5;
        if(context.morale < 0) context.morale = 0;
    }
}

/*
 * Fukurou
 */
Fukurou::Fukurou(string name, int hp, int atk, int def,
                 int speed, int energy, int doriki)
                 :CP9Agent(name,  hp,  atk,  def, speed,  energy, doriki)
{
    // TODO: implement
}

int Fukurou::attack(Character* target, BattleContext& context) {
    int damage = atk;
    bool wasAlive = target->isAlive();
    target->receiveDamage(damage);
    if(!target->isAlive() && wasAlive) {
        defeatedEnemy = true;
    }
    int realDam = damage - target->getDEF();
    if (realDam<0) realDam = 0;
    return realDam;
}

int Fukurou::specialSkill(Character* target, BattleContext& context) {
    if(energy >= 14) {
        int damage = ceil(1.3*atk);
        energy-=14;
        if (target->getHP() == context.minStrawHatHP){
            damage +=20;
        }
        bool wasAlive = target->isAlive();
        target->receiveDamage(damage);
        if(!target->isAlive() && wasAlive){
            context.morale -= 6;
            if(context.morale < 0) context.morale = 0;
            defeatedEnemy = true;
        }
        int realDam = damage - target->getDEF();
        if (realDam<0) realDam = 0;
        return realDam;
        }
return 0;
}

void Fukurou::endTurn(BattleContext& context) {
    if(defeatedEnemy) defeatedEnemy = false;
}

/*
 * Building
 */
Building::Building(string name, int hp) {
    this->name = name;
    this->hp = hp;
}

Building::~Building() {
}
void Building::receiveDamage(int damage) {
    hp -=damage;
    if ( hp<=0){
        hp = 0;
        destroyed = true;
    }
}

bool Building::isDestroyed() const {
    return destroyed;
}

void Building::onDestroyed(BattleContext& context) {
    return ;
}

string Building::str () const {
    return "Building[name=" + name + ", hp=" + to_string(hp) + ", maxHP=" + to_string(maxHP) + ", destroyed" + to_string(destroyed) + "]";
}
/*
 * MainGate
 */
MainGate::MainGate(string name, int hp) : Building(name, hp) {}

void MainGate::applyEffect(BattleContext& context) {
    if(!context.mainGateDestroyed){
        return;
    }
}

void MainGate::onDestroyed(BattleContext& context) {
    if(context.mainGateDestroyed){
        context.mainGateDestroyed = true;
        
    }
}

/*
 * Courthouse
 */
Courthouse::Courthouse(string name, int hp) : Building(name, hp) {}

void Courthouse::applyEffect(BattleContext& context) {
    // TODO: implement
}

void Courthouse::onDestroyed(BattleContext& context) {
    // TODO: implement
}

/*
 * TowerOfJustice
 */
TowerOfJustice::TowerOfJustice(string name, int hp) : Building(name, hp) {}

void TowerOfJustice::applyEffect(BattleContext& context) {
    // TODO: implement
}

/*
 * BridgeOfHesitation
 */
BridgeOfHesitation::BridgeOfHesitation(string name, int hp) : Building(name, hp) {}

void BridgeOfHesitation::applyEffect(BattleContext& context) {
    // TODO: implement
}

/*
 * BusterCallShip
 */
BusterCallShip::BusterCallShip(string name, int hp) : Building(name, hp) {}

void BusterCallShip::applyEffect(BattleContext& context) {
    // TODO: implement
}

void BusterCallShip::onDestroyed(BattleContext& context) {
    // TODO: implement
}

/*
 * EniesLobbyBattle
 */
EniesLobbyBattle::EniesLobbyBattle(const string& filename) {
    strawHats = new Character*[7];
    strawHatCount = 0;
    cp9Agents = new Character*[7];
    cp9Count = 0;
    buildings = new Building*[5];
    buildingCount = 0;
    turnOrder = nullptr;
    maxTurns = 0;
    loadFromFile(filename);
}

EniesLobbyBattle::~EniesLobbyBattle() {
    for (int i = 0; i < strawHatCount; i++) {
        delete strawHats[i];
    }
    delete[] strawHats;
    strawHats = nullptr;

    for (int i = 0; i < cp9Count; i++) {
        delete cp9Agents[i];
    }
    delete[] cp9Agents;
    cp9Agents = nullptr;

    for (int i = 0; i < buildingCount; i++) {
        delete buildings[i];
    }
    delete[] buildings;
    buildings = nullptr;

    TurnNode* head = turnOrder;
    while (head) {
        TurnNode* temp = head->next;
        delete head;
        head = temp;
    }
    turnOrder = nullptr;
}

Character* createCP9(string name, int hp, int atk, int def, int speed, int energy, int doriki){
    CharacterType temp;
    bool flag = 1;
    if ( name == "Lucci") temp = LUCCI;
    else if ( name == "Kaku") temp = KAKU;
    else if ( name == "Jabra") temp = JABRA;
    else if ( name == "Blueno") temp = BLUENO;
    else if ( name == "Kalifa") temp = KALIFA;
    else if ( name == "Kumadori") temp = KUMADORI;
    else if ( name == "Fukurou") temp = FUKUROU;
    else flag = 0;
    if ( flag) return new Character(name,temp,hp,atk,def,speed,energy);
    else return nullptr;
}
Character* createStrawHat(string name, int hp, int atk, int def, int speed, int energy, long long bounty){
    bool flag = 1;
    CharacterType temp;
    if ( name == "Luffy") temp = LUFFY;
    else if ( name == "Zoro") temp = ZORO;
    else if ( name == "Sanji") temp = SANJI;
    else if ( name == "Nami") temp = NAMI;
    else if ( name == "Chopper") temp = CHOPPER;
    else if ( name == "Usopp") temp = USOPP;
    else if ( name == "Franky") temp = FRANKY;
    else flag = 0;
    if ( flag) return new Character(name,temp,hp,atk,def,speed,energy);
    else return nullptr;
}
    Building* createBuilding(string name, int hp){
    BuildingType temp;
    bool flag = 1;
    if ( name == "MainGate") temp = MAIN_GATE;
    else if ( name == "Courthouse") temp = COURTHOUSE;
    else if ( name == "TowerOfJustice") temp = TOWER_OF_JUSTICE;
    else if ( name == "BridgeOfHesitation") temp = BRIDGE_OF_HESITATION;
    else if ( name == "BusterCallShip") temp = BUSTER_CALL_SHIP;
    else flag = 0;
    if (flag ) return new Building(name,temp,hp);
    else return nullptr;
}

void EniesLobbyBattle::loadFromFile(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
        return;
        string line;
            while ( getline(file,line)){
                if (line.empty()) continue;
                stringstream f(line);
                string text;
                f >> text;
                if ( text == "CONTEXT"){
                    int mor,ala,res,esc,bus;
                    f>>mor>>ala>>res>>esc>>bus>>maxTurns;
                    context.morale = mor;
                    context.alarmLevel = ala;
                    context.rescueProgress = res;
                    context.escapeProgress = esc;
                    context.busterCallTimer = bus;
                }
                else if ( text == "STRAW_HAT"){
                    string name;
                    int hp, atk, def, speed, energy;
                    long long bounty;
                    f>>name>>hp>>atk>>def>>speed>>energy>>bounty;
                    Character *newChar = createStrawHat ( name, hp, atk, def,speed, energy,bounty);
                    if( newChar) addStrawHat(newChar);
                }
                else if ( text == "CP9"){
                    string name;
                    int hp, atk, def, speed, energy;
                    int doriki;
                    f>>name>>hp>>atk>>def>>speed>>energy>>doriki;
                    Character *newChar = createCP9 ( name, hp, atk, def,speed, energy,doriki);
                    if( newChar) addCP9Agent(newChar);
                }
                else if ( text == "BUILDING"){
                    string name;
                    int hp;
                    f>>name>>hp;
                    Building *newChar = createBuilding ( name, hp);
                    if( newChar) addBuilding(newChar);
                }

            }
    buildTurnOrder();
    file.close();
}
void EniesLobbyBattle::addStrawHat(Character* character) {
    if (strawHatCount < 7)
        {strawHats[strawHatCount] = character;
    strawHatCount++;}
}

void EniesLobbyBattle::addCP9Agent(Character* character) {
    if (cp9Count < 7)
        {cp9Agents[cp9Count] = character;
            cp9Count++;
        }
}

void EniesLobbyBattle::addBuilding(Building* building) {
    if (buildingCount < 5)
     {buildings[buildingCount] = building;
        buildingCount++;
     }
}

void EniesLobbyBattle::buildTurnOrder() {
    TurnNode* tail = nullptr;
    turnOrder = nullptr;
    for ( int i = 0;i<strawHatCount;i++){
        TurnNode* temp = new TurnNode(strawHats[i]);
        if (turnOrder == nullptr) {
            turnOrder = temp;
            tail = temp;
        }
        else {
            tail -> next = temp;
            tail = temp;
        }
    }
    for ( int i =0 ; i<cp9Count;i++){
        TurnNode* temp = new TurnNode(cp9Agents[i]);
        if (turnOrder == nullptr){
            turnOrder = temp;
            tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
        
    }
}

void EniesLobbyBattle::runBattle() {
    if ( turnOrder == nullptr) return;
    TurnNode* head = turnOrder;
    turnOrder = turnOrder->next;
    TurnNode* findTail = turnOrder;
    while ( turnOrder->next != nullptr){
        findTail = turnOrder->next;
    }
    findTail->next = head;
    head->next =nullptr;
}

void EniesLobbyBattle::processTurn(Character* character) {
    Character* minHpmember = nullptr;
    int minHp = INT_MAX;
        for ( int i = 0; i< strawHatCount;i++){
            if ( strawHats[i] != nullptr){
                 if (strawHats[i]->isAlive() && strawHats[i]->getHP() < minHp){
                    minHpmember = strawHats[i];
                    minHp = strawHats[i]->getHP();
                }
            }
        }
        context.minStrawHatHP = minHp;
        if ( character->getName() == "Chopper" && character->getEnergy()>=15){
        character->specialSkill(minHpmember,context);
        }
    else{};
}

void EniesLobbyBattle::processBuildings() {
    // TODO: implement
}

void EniesLobbyBattle::checkEndCondition() {
    // TODO: implement
}

string EniesLobbyBattle::getResult() const {
    // TODO: implement
    return "";
}