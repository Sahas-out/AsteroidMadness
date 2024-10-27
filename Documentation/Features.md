# Shooter
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
    -reduces cooldown period for all or some shooter.

Launcher(Abstract base class)
    Data
        -positon
    Methods
        contructor()
        -virtual launch(targetMissileType)

normal launcher(derived base class :Launcher) overides launch
RapidLauncher(derived base class: Launcher) overrides launch
SpreadLauncher(derive base class: launcher) overrides launch


Shooter(Abstract base class)
    Data
        -positon
        -cooldown period
        -clock to record time elapsed before last fired 
        -cooldown_enabled
        -missile_attached (object of missile class)
        -launcher attached  (Object of launcher class)
        -type 
    Methods
        -COnstructor intialises 
            -position 
            -cooldown period 
            -missile attached
            -launcher attached 
        -launching missile (creates a instance of missle and add it to items to be displayed on screen)
        -getter and setter methods for position,cooldown period,type 
        -canShoot() returns boolean value if missile can shoot or not
        -Destructor (to delete missile attached objects and launcher attached after code is finished running)
NormalShoooter
    Methods
        -constuctor (calls basec class constructor with apt missle attached and normal launcher )
RapidShooter(base class: Shooter)
    Data
        -Missile count(how many missiles to shoot)
        -image
    Methods
        -constructor (calls base class constructor with apt missile attached and rapid launcher)

SpreadShooter
    Data
        -parameters which define spread
        -Missile count 
        -image
    Method
        -constructor(call base class constructor with apt missile attached and spread launcher )

Asteriod(Abstract base class) 
    Data 
        -type   
        -life(useful for boss and big ones) 
        -speed 
        -size 
        -trajectory(current pos+angle )
        -soundOnBlast 
        -pointsOnDestruction
    Methods 
        -spawn (constructor which spawns the asteroid on screen)
        -move #defines the behaviour when the frame changes 
        -getter and setter methods 
        -destruction(destructor which defines what happens when gets blasted) 
        -setTrajectory 

NormalAsteroid

BigAsteroid(derived from base class: Asteroid ) 
    Data
        -image 
    Methods 
        Constructor
            - change life(takes 2 missile) 
            - changeSpeed

BossAsteroid (derived from base class: Asteroid )
    Data
        -image 
    Methods 
        Constructor
            - change life 
        - subasteroids 
        - subasteroid movements

SplitAsteroid (derived from base class: Asteroid)
    Methods 
        -overrides destruction 
        -movementOfNewParticles

FastAsteroid 
    Methods 
    Constructor
        -changeSpeed


class Missile {
    private:
    image;
    string type;
    double speed;
    int size;
    int impact_perimeter;obj_files
obj_files
obj_files
    double trajectory[3]={angle,current_position};
    string special_feature="";

    public:
    Missile (string type){
        this->type=type;
        this->set_trajectory();
    }

    void set_impact_perimeter(int);
    void set_special_feature(string);
    void set_trajectory(double,double);
    
};

PowerUp:
    Data
    - duration: int (duration of the power-up effect in seconds)
    - active: bool (indicates if the power-up is currently active)
    
    Methods
    - activate(): Activates the power-up effect.
    - deactivate(): Deactivates the power-up effect.
    - update_status(): Checks if the power-up duration has ended.


NoCooldownPowerUp(PowerUp):
    Data
    - target_satellite: Shooter (reference to the satellite getting the powerup)
    
    Methods
    - activate_nocooldown(): Removes cooldown for the target satellite.
    - deactivate_nocooldown(): Restores the original cooldown for the target satellite.


CooldownReductionPowerUp(PowerUp):
    Data
    - target_shooter: List[Shooter] (list of shooter affected by cooldown reduction)
    - reduction_factor: float (factor by which cooldown is reduced)
    
    Methods
    - activate_redcooldown(): Reduces cooldown for target shooter.
    - deactivate_redcooldown(): Restores the original cooldown for the target shooter.

