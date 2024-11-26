#pragma once

// #include"GameUtils.hpp"
#include"Missile.hpp"
class MissileManager
{
    private:
        std::vector<Missile*>  missileList;
        sf::RenderWindow* window ;
    public:
        MissileManager(sf::RenderWindow* inWindow);
        void addMissile(std::vector<Missile*> newMissileList);
        std::pair<std::vector<settings::Circle>,std::vector<Missile*>> getAllBounds();
        void executeMissileBehaviour();
        void updateStatus();
        ~MissileManager();
        void update();
        void render();
};