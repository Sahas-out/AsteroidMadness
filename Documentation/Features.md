# Satellites
    -Different cooldowns
    -coordiantes
    -image 
    -Attached missile 
    -Launcher
        -continous burst
        -splash burst missiles will burst at same height 
    Sattelites with different cooldowns and different launchers that are contionus burst abd spalsh burst
# Missiles 
    -image
    -size
    -missile which doesnt get destoryed on colliding with any aasteroid it just gets reflected 
    -missile with a very large impact parameter
    -missile on blast decreases the speed of all other asteroids on screen
# asteroids 
    -image 
    -a large asteroid which takes a 2 missiles to destroy
    -fast moving velocity 
    -a special type of asteroid , which gets split into 2 asteroids when hits a missile.
    - boss asteroid

# Powerups
    -no cooldown on any one satellite for let's say 10sec, you can fire continuosly for 10 sec.
    -reduces cooldown period for all or some satellites.

Satellite(base class)
    Data
        -positon
        -cooldown period
    Methods
        -launching missile (defines the tracjectory of missile)
        -cooldown controller
        -

Asteriods(base class)
    Data
        -name
        -image
        -life(useful for boss and big ones)
        -speed
        -size
    Methods
        - destruction(defines what happens when gets blasted)
        - getter and setter methods
        - soundOnBlast
        -setTrajectory
        -render(draws asteroid)


Asteroid 1(big one ) (derived from base)
    Methods
        - change life(takes 2 missile)
        - changeSpeed

asteroid 2(boss)
    Methods
        - change life
        - subasteroids
        - subasteroid movements

Asteroid 3(split one)
    Methods
        -splitOnDestruction
        -movementOfNewParticles

Asteroid 4 (fast and slow)
    Methods
        -changeSpeed    