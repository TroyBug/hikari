#ifndef HIKARI_CLIENT_GAME_OBJECTS_SPAWNER
#define HIKARI_CLIENT_GAME_OBJECTS_SPAWNER

#include "hikari/client/game/objects/GameObject.hpp"
#include "hikari/client/game/GameWorld.hpp"
#include "hikari/core/game/Direction.hpp"
#include "hikari/core/math/Vector2.hpp"
#include "hikari/client/game/events/EventData.hpp"
#include "hikari/client/game/events/EventListenerDelegate.hpp"

#include <memory>

namespace hikari {

    class EventBus;
    
    /**
        A Spawner is responsible for spawning one or more objects in the game
        world. It keeps track of whether its spawn should be alive or not.
    */
    class Spawner : public GameObject {
    private:
        Direction direction;
        Vector2<float> position;
        bool awake;

    protected:
        std::vector<std::pair<EventListenerDelegate, EventType>> eventHandlerDelegates;

    public:
        Spawner();

        virtual ~Spawner() {
            // no-op
        }

        const Direction& getDirection() const;

        void setDirection(const Direction& direction);

        /**
            Gets the position where this Spawner's offspring will spawn.

            @return offspring's spawn position in world coordinates.
        */
        const Vector2<float>& getPosition() const;

        /**
            Sets the position where this Spawner's offspring will spawn.

            @param newPosition the offspring's spawn position in world 
            coordinates.
        */
        void setPosition(const Vector2<float>& newPosition);

        virtual void performAction(GameWorld & world);

        virtual void attachEventListeners(EventBus & EventBus);
        virtual void detachEventListeners(EventBus & EventBus);

        virtual void attachToInstance(const std::shared_ptr<GameObject> & instance);

        bool isAwake() const;
        void setAwake(bool awake);

        virtual bool canSpawn() const;

        virtual void onWake();
        virtual void onSleep();

        //
        // GameObject overrides
        //
        virtual void onActivated();
        virtual void onDeactivated();
    };

} // hikari

#endif // HIKARI_CLIENT_GAME_OBJECTS_SPAWNER