#ifndef HIKARI_CORE_GAME_GAMEPROGRESS
#define HIKARI_CORE_GAME_GAMEPROGRESS

#include "hikari/core/Platform.hpp"
#include "hikari/core/util/Service.hpp"
#include <memory>

namespace hikari {

    class EventBus;

    class HIKARI_API GameProgress : public Service {
    private:
        static const unsigned char NumBosses = 8;
        static const unsigned char NumWeapons = NumBosses + 3; // Need to determine this.
        static const unsigned char DEFAULT_PLAYER_ENERGY;
        static const int DEFAULT_NUM_LIVES;

        int lives;
        unsigned char eTanks;
        unsigned char mTanks;
        unsigned char playerEnergy;
        unsigned char weaponEnergies[NumWeapons];
        unsigned char currentBoss;
        unsigned char currentWeapon;

        bool bossesDefeated[NumBosses];
        bool weaponsEnabled[NumWeapons];

        std::weak_ptr<EventBus> eventBus;
    public:
        GameProgress();
        virtual ~GameProgress();

        void setEventBus(const std::weak_ptr<EventBus> & eventBus);
        const std::weak_ptr<EventBus> & getEventBus() const;

        //
        // Getters
        //
        const unsigned char getBossCount() const;
        const unsigned char getDefeatedBossCount() const;
        int getLives() const;
        unsigned char getETanks() const;
        unsigned char getMTanks() const;
        int getPlayerEnergy() const;
        unsigned char getCurrentBoss() const;
        unsigned char getCurrentWeapon() const;
        unsigned char getWeaponCount() const;
        unsigned char getWeaponEnergy(unsigned char weapon) const;
        unsigned char getWeakestWeapon() const;
        bool bossIsDefeated(unsigned char boss) const;
        bool weaponIsEnabled(unsigned char weapon) const;

        //
        // Setters
        //
        void setBossDefeated(unsigned char boss, bool defeated);
        void setLives(int value);
        void setETanks(unsigned char value);
        void setMTanks(unsigned char value);
        void setPlayerEnergy(int value);
        void setCurrentBoss(unsigned char boss);
        void setCurrentWeapon(unsigned char weapon);
        void setWeaponEnergy(unsigned char weapon, unsigned char value);
        void enableWeapon(unsigned char weapon, bool enable);

        //
        // Methods
        //
        void resetLivesToDefault();
        void resetPlayerEnergyToDefault();
        void resetWeaponEnergyToDefault();
    };

} // hikari

#endif // HIKARI_CORE_GAME_GAMEPROGRESS
