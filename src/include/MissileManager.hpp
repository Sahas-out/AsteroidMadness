#include"GameUtils.hpp"
#include"Missile.hpp"
class MissileManager
{
    private:
        std::vector<Missile*>  missileList;
        sf::RenderWindow& window ;
    public:
        MissileManager(sf::RenderWindow& inWindow);
        void addMissile(std::vector<Missile*>& newMissileList);
        void draw();
        std::vector<settings::Circle> getAllBounds();
        void executeMissileBehaviour();
        void updateStatus();
        ~MissileManager();
};