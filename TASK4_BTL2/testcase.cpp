#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "eniesLobby.h"
#include <sstream>
#include <fstream>

#include <sstream>

string str(BattleContext &context)
{
    stringstream ss;

    ss << "resultCode=" << context.resultCode << " "
       << "turnCount=" << context.turnCount << " "
       << "morale=" << context.morale << " "
       << "alarmLevel=" << context.alarmLevel << " "
       << "rescueProgress=" << context.rescueProgress << " "
       << "escapeProgress=" << context.escapeProgress << " "
       << "busterCallTimer=" << context.busterCallTimer;

    return ss.str();
}

void printBeforeAfter(Character *actor, Character *target, string action, BattleContext &context)
{
    cout << "- " << actor->getName() << " " << action << " -> " << target->getName() << endl;
    cout << "actor(before):  " << actor->str() << " | alive=" << (actor->isAlive() ? "true" : "false") << endl;
    cout << "target(before): " << target->str() << " | alive=" << (target->isAlive() ? "true" : "false") << endl;
    int damage = 0;
    if (action == "special")
    {
        damage = actor->specialSkill(target, context);
    }
    else
    {
        damage = actor->attack(target, context);
    }
    cout << "damage: " << damage << endl;
    cout << "actor(after):   " << actor->str() << " | alive=" << (actor->isAlive() ? "true" : "false") << endl;
    cout << "target(after):  " << target->str() << " | alive=" << (target->isAlive() ? "true" : "false") << endl;
}

TEST_CASE("test_005")
{
    Character *strawHats[7];
    strawHats[0] = new Luffy("Luffy", 120, 35, 20, 25, 50, 1500000000LL);
    strawHats[1] = new Zoro("Zoro", 110, 38, 25, 20, 45, 1111000000LL);
    strawHats[2] = new Sanji("Sanji", 100, 34, 18, 30, 45, 1032000000LL);
    strawHats[3] = new Nami("Nami", 80, 22, 12, 35, 60, 366000000LL);
    strawHats[4] = new Chopper("Chopper", 90, 20, 15, 22, 55, 1000LL);
    strawHats[5] = new Usopp("Usopp", 85, 24, 14, 28, 50, 500000000LL);
    strawHats[6] = new Franky("Franky", 130, 32, 28, 18, 50, 394000000LL);

    ostringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());
    for (int i = 0; i < 7; i++)
    {
        cout << "- " << strawHats[i]->str()
             << " | isStrawHat=" << (strawHats[i]->isStrawHat() ? "true" : "false")
             << " | isCP9=" << (strawHats[i]->isCP9() ? "true" : "false")
             << endl;
    }
    cout.rdbuf(old);
    CHECK(buffer.str() == "- StrawHat[name=Luffy, hp=120, atk=35, def=20, speed=25, energy=50, bounty=1500000000] | isStrawHat=true | isCP9=false\n"
                          "- StrawHat[name=Zoro, hp=110, atk=38, def=25, speed=20, energy=45, bounty=1111000000] | isStrawHat=true | isCP9=false\n"
                          "- StrawHat[name=Sanji, hp=100, atk=34, def=18, speed=30, energy=45, bounty=1032000000] | isStrawHat=true | isCP9=false\n"
                          "- StrawHat[name=Nami, hp=80, atk=22, def=12, speed=35, energy=60, bounty=366000000] | isStrawHat=true | isCP9=false\n"
                          "- StrawHat[name=Chopper, hp=90, atk=20, def=15, speed=22, energy=55, bounty=1000] | isStrawHat=true | isCP9=false\n"
                          "- StrawHat[name=Usopp, hp=85, atk=24, def=14, speed=28, energy=50, bounty=500000000] | isStrawHat=true | isCP9=false\n"
                          "- StrawHat[name=Franky, hp=130, atk=32, def=28, speed=18, energy=50, bounty=394000000] | isStrawHat=true | isCP9=false\n");
    for (int i = 0; i < 7; i++)
        delete strawHats[i];
}

TEST_CASE("test_006")
{
    Character *cp9[7];
    cp9[0] = new Lucci("Lucci", 150, 40, 25, 30, 60, 4000);
    cp9[1] = new Kaku("Kaku", 130, 35, 22, 28, 55, 2200);
    cp9[2] = new Jabra("Jabra", 125, 33, 30, 24, 50, 2180);
    cp9[3] = new Blueno("Blueno", 110, 28, 24, 26, 45, 820);
    cp9[4] = new Kalifa("Kalifa", 95, 26, 18, 32, 50, 630);
    cp9[5] = new Kumadori("Kumadori", 115, 30, 20, 20, 45, 810);
    cp9[6] = new Fukurou("Fukurou", 100, 27, 16, 25, 40, 800);

    ostringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());
    for (int i = 0; i < 7; i++)
    {
        cout << "- " << cp9[i]->str()
             << " | isStrawHat=" << (cp9[i]->isStrawHat() ? "true" : "false")
             << " | isCP9=" << (cp9[i]->isCP9() ? "true" : "false")
             << endl;
    }
    cout.rdbuf(old);
    CHECK(buffer.str() == "- CP9[name=Lucci, hp=150, atk=40, def=25, speed=30, energy=60, doriki=4000] | isStrawHat=false | isCP9=true\n"
                          "- CP9[name=Kaku, hp=130, atk=35, def=22, speed=28, energy=55, doriki=2200] | isStrawHat=false | isCP9=true\n"
                          "- CP9[name=Jabra, hp=125, atk=33, def=30, speed=24, energy=50, doriki=2180] | isStrawHat=false | isCP9=true\n"
                          "- CP9[name=Blueno, hp=110, atk=28, def=24, speed=26, energy=45, doriki=820] | isStrawHat=false | isCP9=true\n"
                          "- CP9[name=Kalifa, hp=95, atk=26, def=18, speed=32, energy=50, doriki=630] | isStrawHat=false | isCP9=true\n"
                          "- CP9[name=Kumadori, hp=115, atk=30, def=20, speed=20, energy=45, doriki=810] | isStrawHat=false | isCP9=true\n"
                          "- CP9[name=Fukurou, hp=100, atk=27, def=16, speed=25, energy=40, doriki=800] | isStrawHat=false | isCP9=true\n");
    for (int i = 0; i < 7; i++)
        delete cp9[i];
}

TEST_CASE("test_007")
{
    Character *strawHats[3];
    strawHats[0] = new Luffy("Luffy", 120, 35, 20, 25, 50, 1500000000LL);
    strawHats[1] = new Nami("Nami", 80, 22, 12, 35, 60, 366000000LL);
    strawHats[2] = new Franky("Franky", 130, 32, 28, 18, 50, 394000000LL);

    Character *cp9[3];
    cp9[0] = new Lucci("Lucci", 150, 40, 25, 30, 60, 4000);
    cp9[1] = new Kaku("Kaku", 130, 35, 22, 28, 55, 2200);
    cp9[2] = new Kalifa("Kalifa", 95, 26, 18, 32, 50, 630);

    BattleContext context;

    ostringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());
    cout << "\n[Round 1] StrawHat attacks" << endl;
    printBeforeAfter(strawHats[0], cp9[0], "special", context);
    printBeforeAfter(strawHats[1], cp9[1], "attack", context);
    printBeforeAfter(strawHats[2], cp9[2], "special", context);

    cout << "\n[Round 2] CP9 attacks" << endl;
    printBeforeAfter(cp9[0], strawHats[0], "attack", context);
    printBeforeAfter(cp9[1], strawHats[1], "special", context);
    printBeforeAfter(cp9[2], strawHats[2], "special", context);
    cout.rdbuf(old);
    CHECK(buffer.str() == "\n"
                          "[Round 1] StrawHat attacks\n"
                          "- Luffy special -> Lucci\n"
                          "actor(before):  StrawHat[name=Luffy, hp=120, atk=35, def=20, speed=25, energy=50, bounty=1500000000] | alive=true\n"
                          "target(before): CP9[name=Lucci, hp=150, atk=40, def=25, speed=30, energy=60, doriki=4000] | alive=true\n"
                          "damage: 45\n"
                          "actor(after):   StrawHat[name=Luffy, hp=110, atk=50, def=20, speed=40, energy=30, bounty=1500000000] | alive=true\n"
                          "target(after):  CP9[name=Lucci, hp=105, atk=40, def=25, speed=30, energy=60, doriki=4000] | alive=true\n"
                          "- Nami attack -> Kaku\n"
                          "actor(before):  StrawHat[name=Nami, hp=80, atk=22, def=12, speed=35, energy=60, bounty=366000000] | alive=true\n"
                          "target(before): CP9[name=Kaku, hp=130, atk=35, def=22, speed=28, energy=55, doriki=2200] | alive=true\n"
                          "damage: 6\n"
                          "actor(after):   StrawHat[name=Nami, hp=80, atk=22, def=12, speed=35, energy=60, bounty=366000000] | alive=true\n"
                          "target(after):  CP9[name=Kaku, hp=124, atk=35, def=22, speed=28, energy=55, doriki=2200] | alive=true\n"
                          "- Franky special -> Kalifa\n"
                          "actor(before):  StrawHat[name=Franky, hp=130, atk=32, def=28, speed=18, energy=50, bounty=394000000] | alive=true\n"
                          "target(before): CP9[name=Kalifa, hp=95, atk=26, def=18, speed=32, energy=50, doriki=630] | alive=true\n"
                          "damage: 21\n"
                          "actor(after):   StrawHat[name=Franky, hp=130, atk=32, def=28, speed=18, energy=20, bounty=394000000] | alive=true\n"
                          "target(after):  CP9[name=Kalifa, hp=74, atk=26, def=18, speed=32, energy=50, doriki=630] | alive=true\n"
                          "\n"
                          "[Round 2] CP9 attacks\n"
                          "- Lucci attack -> Luffy\n"
                          "actor(before):  CP9[name=Lucci, hp=105, atk=40, def=25, speed=30, energy=60, doriki=4000] | alive=true\n"
                          "target(before): StrawHat[name=Luffy, hp=110, atk=50, def=20, speed=40, energy=30, bounty=1500000000] | alive=true\n"
                          "damage: 220\n"
                          "actor(after):   CP9[name=Lucci, hp=105, atk=40, def=25, speed=30, energy=60, doriki=4000] | alive=true\n"
                          "target(after):  StrawHat[name=Luffy, hp=0, atk=50, def=20, speed=40, energy=30, bounty=1500000000] | alive=false\n"
                          "- Kaku special -> Nami\n"
                          "actor(before):  CP9[name=Kaku, hp=124, atk=35, def=22, speed=28, energy=55, doriki=2200] | alive=true\n"
                          "target(before): StrawHat[name=Nami, hp=80, atk=22, def=12, speed=35, energy=60, bounty=366000000] | alive=true\n"
                          "damage: 69\n"
                          "actor(after):   CP9[name=Kaku, hp=124, atk=35, def=22, speed=28, energy=35, doriki=2200] | alive=true\n"
                          "target(after):  StrawHat[name=Nami, hp=11, atk=22, def=12, speed=35, energy=60, bounty=366000000] | alive=true\n"
                          "- Kalifa special -> Franky\n"
                          "actor(before):  CP9[name=Kalifa, hp=74, atk=26, def=18, speed=32, energy=50, doriki=630] | alive=true\n"
                          "target(before): StrawHat[name=Franky, hp=130, atk=32, def=28, speed=18, energy=20, bounty=394000000] | alive=true\n"
                          "damage: 9\n"
                          "actor(after):   CP9[name=Kalifa, hp=74, atk=26, def=18, speed=32, energy=32, doriki=630] | alive=true\n"
                          "target(after):  StrawHat[name=Franky, hp=121, atk=32, def=28, speed=12, energy=20, bounty=394000000] | alive=true\n");
    for (int i = 0; i < 3; i++)
        delete strawHats[i];
    for (int i = 0; i < 3; i++)
        delete cp9[i];
}

TEST_CASE("test_008")
{
    Character *strawHats[4];
    strawHats[0] = new Zoro("Zoro", 110, 38, 25, 20, 45, 1111000000LL);
    strawHats[1] = new Sanji("Sanji", 100, 34, 18, 30, 45, 1032000000LL);
    strawHats[2] = new Chopper("Chopper", 90, 20, 15, 22, 55, 1000LL);
    strawHats[3] = new Usopp("Usopp", 85, 24, 14, 28, 50, 500000000LL);

    Character *cp9[4];
    cp9[0] = new Jabra("Jabra", 125, 33, 30, 24, 50, 2180);
    cp9[1] = new Blueno("Blueno", 110, 28, 24, 26, 45, 820);
    cp9[2] = new Kumadori("Kumadori", 115, 30, 20, 20, 45, 810);
    cp9[3] = new Fukurou("Fukurou", 100, 27, 16, 25, 40, 800);

    BattleContext context;

    ostringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());
    cout << "\n[Round 1] StrawHat attacks" << endl;
    printBeforeAfter(strawHats[0], cp9[0], "special", context); // Zoro -> Jabra
    printBeforeAfter(strawHats[1], cp9[1], "special", context); // Sanji -> Blueno
    printBeforeAfter(strawHats[2], cp9[2], "attack", context);  // Chopper -> Kumadori
    printBeforeAfter(strawHats[3], cp9[3], "special", context); // Usopp -> Fukurou

    cout << "\n[Round 2] CP9 attacks" << endl;
    printBeforeAfter(cp9[0], strawHats[0], "special", context); // Jabra -> Zoro
    printBeforeAfter(cp9[1], strawHats[1], "special", context); // Blueno -> Sanji
    printBeforeAfter(cp9[2], strawHats[2], "special", context); // Kumadori -> Chopper
    printBeforeAfter(cp9[3], strawHats[3], "special", context); // Fukurou -> Usopp
    cout.rdbuf(old);
    CHECK(buffer.str() == "\n"
                          "[Round 1] StrawHat attacks\n"
                          "- Zoro special -> Jabra\n"
                          "actor(before):  StrawHat[name=Zoro, hp=110, atk=38, def=25, speed=20, energy=45, bounty=1111000000] | alive=true\n"
                          "target(before): CP9[name=Jabra, hp=125, atk=33, def=30, speed=24, energy=50, doriki=2180] | alive=true\n"
                          "damage: 54\n"
                          "actor(after):   StrawHat[name=Zoro, hp=110, atk=38, def=25, speed=20, energy=30, bounty=1111000000] | alive=true\n"
                          "target(after):  CP9[name=Jabra, hp=71, atk=33, def=30, speed=24, energy=50, doriki=2180] | alive=true\n"
                          "- Sanji special -> Blueno\n"
                          "actor(before):  StrawHat[name=Sanji, hp=100, atk=34, def=18, speed=30, energy=45, bounty=1032000000] | alive=true\n"
                          "target(before): CP9[name=Blueno, hp=110, atk=28, def=24, speed=26, energy=45, doriki=820] | alive=true\n"
                          "damage: 48\n"
                          "actor(after):   StrawHat[name=Sanji, hp=100, atk=34, def=18, speed=30, energy=27, bounty=1032000000] | alive=true\n"
                          "target(after):  CP9[name=Blueno, hp=62, atk=28, def=16, speed=26, energy=45, doriki=820] | alive=true\n"
                          "- Chopper attack -> Kumadori\n"
                          "actor(before):  StrawHat[name=Chopper, hp=90, atk=20, def=15, speed=22, energy=55, bounty=1000] | alive=true\n"
                          "target(before): CP9[name=Kumadori, hp=115, atk=30, def=20, speed=20, energy=45, doriki=810] | alive=true\n"
                          "damage: 0\n"
                          "actor(after):   StrawHat[name=Chopper, hp=90, atk=20, def=15, speed=22, energy=55, bounty=1000] | alive=true\n"
                          "target(after):  CP9[name=Kumadori, hp=115, atk=30, def=20, speed=20, energy=45, doriki=810] | alive=true\n"
                          "- Usopp special -> Fukurou\n"
                          "actor(before):  StrawHat[name=Usopp, hp=85, atk=24, def=14, speed=28, energy=50, bounty=500000000] | alive=true\n"
                          "target(before): CP9[name=Fukurou, hp=100, atk=27, def=16, speed=25, energy=40, doriki=800] | alive=true\n"
                          "damage: 4\n"
                          "actor(after):   StrawHat[name=Usopp, hp=85, atk=24, def=14, speed=28, energy=34, bounty=500000000] | alive=true\n"
                          "target(after):  CP9[name=Fukurou, hp=96, atk=27, def=16, speed=13, energy=40, doriki=800] | alive=true\n"
                          "\n"
                          "[Round 2] CP9 attacks\n"
                          "- Jabra special -> Zoro\n"
                          "actor(before):  CP9[name=Jabra, hp=71, atk=33, def=30, speed=24, energy=50, doriki=2180] | alive=true\n"
                          "target(before): StrawHat[name=Zoro, hp=110, atk=38, def=25, speed=20, energy=30, bounty=1111000000] | alive=true\n"
                          "damage: 25\n"
                          "actor(after):   CP9[name=Jabra, hp=71, atk=33, def=30, speed=24, energy=32, doriki=2180] | alive=true\n"
                          "target(after):  StrawHat[name=Zoro, hp=85, atk=38, def=25, speed=20, energy=30, bounty=1111000000] | alive=true\n"
                          "- Blueno special -> Sanji\n"
                          "actor(before):  CP9[name=Blueno, hp=62, atk=28, def=16, speed=26, energy=45, doriki=820] | alive=true\n"
                          "target(before): StrawHat[name=Sanji, hp=100, atk=34, def=18, speed=30, energy=27, bounty=1032000000] | alive=true\n"
                          "damage: 39\n"
                          "actor(after):   CP9[name=Blueno, hp=62, atk=28, def=16, speed=26, energy=30, doriki=820] | alive=true\n"
                          "target(after):  StrawHat[name=Sanji, hp=61, atk=34, def=18, speed=30, energy=27, bounty=1032000000] | alive=true\n"
                          "- Kumadori special -> Chopper\n"
                          "actor(before):  CP9[name=Kumadori, hp=115, atk=30, def=20, speed=20, energy=45, doriki=810] | alive=true\n"
                          "target(before): StrawHat[name=Chopper, hp=90, atk=20, def=15, speed=22, energy=55, bounty=1000] | alive=true\n"
                          "damage: 96\n"
                          "actor(after):   CP9[name=Kumadori, hp=115, atk=30, def=20, speed=20, energy=29, doriki=810] | alive=true\n"
                          "target(after):  StrawHat[name=Chopper, hp=0, atk=20, def=15, speed=22, energy=55, bounty=1000] | alive=false\n"
                          "- Fukurou special -> Usopp\n"
                          "actor(before):  CP9[name=Fukurou, hp=96, atk=27, def=16, speed=13, energy=40, doriki=800] | alive=true\n"
                          "target(before): StrawHat[name=Usopp, hp=85, atk=24, def=14, speed=28, energy=34, bounty=500000000] | alive=true\n"
                          "damage: 22\n"
                          "actor(after):   CP9[name=Fukurou, hp=96, atk=27, def=16, speed=13, energy=26, doriki=800] | alive=true\n"
                          "target(after):  StrawHat[name=Usopp, hp=63, atk=24, def=14, speed=28, energy=34, bounty=500000000] | alive=true\n");
    for (int i = 0; i < 4; i++)
        delete strawHats[i];
    for (int i = 0; i < 4; i++)
        delete cp9[i];
}

TEST_CASE("test_101")
{
    Character *luffy = new Luffy("Luffy", 120, 20, 20, 25, 40, 1500000000LL);

    Building *buildings[5] = {
        new MainGate("MainGate", 35),
        new Courthouse("Courthouse", 120),
        new TowerOfJustice("TowerOfJustice", 150),
        new BridgeOfHesitation("BridgeOfHesitation", 100),
        new BusterCallShip("BusterCallShip", 180)};

    BattleContext context;
    context.busterCallTimer = 99;

    luffy->specialSkill(buildings[0], context);

    for (int turn = 0; turn < 6; turn++)
    {
        for (int i = 0; i < 5; i++)
        {
            buildings[i]->applyEffect(context);
        }
    }
    CHECK(buildings[0]->str() == "Building[name=MainGate, hp=0, maxHP=35, destroyed=true]");
    CHECK(buildings[1]->str() == "Building[name=Courthouse, hp=120, maxHP=120, destroyed=false]");
    CHECK(str(context) == "resultCode= turnCount=0 morale=5 alarmLevel=40 rescueProgress=50 escapeProgress=0 busterCallTimer=93");

    delete luffy;
    for (int i = 0; i < 5; i++)
        delete buildings[i];
}

TEST_CASE("test_102")
{
    Character *strawHats[3] = {
        new Luffy("Luffy", 120, 20, 20, 25, 40, 1500000000LL),
        new Nami("Nami", 80, 25, 12, 35, 10, 366000000LL),
        new Usopp("Usopp", 85, 25, 14, 28, 10, 500000000LL)};

    Character *cp9[1] = {
        new Lucci("Lucci", 80, 10, 20, 30, 0, 0)};

    Building *buildings[5] = {
        new MainGate("MainGate", 35),
        new Courthouse("Courthouse", 120),
        new TowerOfJustice("TowerOfJustice", 150),
        new BridgeOfHesitation("BridgeOfHesitation", 100),
        new BusterCallShip("BusterCallShip", 180)};

    BattleContext context;
    context.busterCallTimer = 99;

    // turnCount 1
    strawHats[0]->specialSkill(buildings[0], context);
    strawHats[0]->endTurn(context);
    for (int i = 0; i < 5; i++)
    {
        buildings[i]->applyEffect(context);
    }

    // turnCount 2
    strawHats[1]->attack(cp9[0], context);
    strawHats[1]->endTurn(context);
    for (int i = 0; i < 5; i++)
    {
        buildings[i]->applyEffect(context);
    }

    // turnCount 3
    strawHats[2]->attack(cp9[0], context);
    strawHats[2]->endTurn(context);
    for (int i = 0; i < 5; i++)
    {
        buildings[i]->applyEffect(context);
    }

    // turnCount 4
    cp9[0]->attack(strawHats[0], context);
    cp9[0]->endTurn(context);
    for (int i = 0; i < 5; i++)
    {
        buildings[i]->applyEffect(context);
    }

    // turnCount 5
    strawHats[0]->specialSkill(cp9[0], context);
    strawHats[0]->endTurn(context);
    for (int i = 0; i < 5; i++)
    {
        buildings[i]->applyEffect(context);
    }

    // turnCount 6
    strawHats[1]->attack(cp9[0], context);
    strawHats[1]->endTurn(context);
    for (int i = 0; i < 5; i++)
    {
        buildings[i]->applyEffect(context);
    }

    CHECK(cp9[0]->str() == "CP9[name=Lucci, hp=0, atk=10, def=20, speed=30, energy=0, doriki=0]");
    CHECK(str(context) == "resultCode= turnCount=0 morale=20 alarmLevel=50 rescueProgress=50 escapeProgress=0 busterCallTimer=93");

    for (int i = 0; i < 3; i++)
        delete strawHats[i];
    for (int i = 0; i < 1; i++)
        delete cp9[i];
    for (int i = 0; i < 5; i++)
        delete buildings[i];
}

TEST_CASE("test_200")
{
    ofstream fout("test_200.txt");
    fout << "CONTEXT 0 0 0 0 99 20\n";
    fout << "STRAW_HAT Luffy 120 20 20 25 40 1500000000\n";
    fout << "STRAW_HAT Nami 80 25 12 35 10 366000000\n";
    fout << "STRAW_HAT Usopp 85 25 14 28 10 500000000\n";
    fout << "CP9 Lucci 80 10 20 30 0 0\n";
    fout << "BUILDING MainGate 35\n";
    fout << "BUILDING Courthouse 120\n";
    fout << "BUILDING TowerOfJustice 150\n";
    fout << "BUILDING BridgeOfHesitation 100\n";
    fout << "BUILDING BusterCallShip 180\n";
    fout.close();

    EniesLobbyBattle battle("test_200.txt");
    battle.runBattle();
    CHECK(battle.getResult() == "STRAW_HAT_WIN_BY_DEFEAT_CP9 6 20 50 50 0 93");
    remove("test_200.txt");
}
