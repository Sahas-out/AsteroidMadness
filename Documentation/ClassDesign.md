
# Shooter(Abstract base class)
    Data
        -   positon
        -   cooldown period
        -   clock to record time elapsed before last fired 
        -   cooldown_enabled
        -   attachedMissileType
        -   static size // defines size of image on screen 
    Methods
        -   Shooter(position,cooldown period,missile)
        -   virtual shoot() // returns a instance of missile 
        -   setCooldownPeriod()
        -   virtual getType()
        -   virtual getImage()
        -   canShoot() //returns boolean value if missile can shoot or not
        -   ~Shooter() 
# NormalShoooter(extends Shooter)
    Data
        -   image
        -   type
    Methods
        -   Overides shoot()
# SpreadShoooter(extends Shooter)
    Data
        -   image
        -   type
        -   missileCount // number of missiles to be fired 
    Methods
        -   Overides shoot()
# RapidShoooter(extends Shooter)
    Data
        -   image
        -   type
        -   missileCount // number of missiles to be fired 
        -   interval    // interval between two missiles
    Methods
        -   Overides shoot()

# ShooterManager
    "responsible for maintaining the list of sattelits on screen and doing group actions on them"
    Data
        -   list<Shooters>
        -   enum shooterTypes
        -   Shooter SelectedShooter 
    Method
        -   ShooterManager()
        -   addNewShooter(type) // adds new shooter to the screen
        -   handleTarget(targetPos) // handles the target by shooting missiles  
        -   removeShooter() //removes currentSelectedShooter from the screen
        -   Map(function_ptr) //applies that function to all the shooters  
        -   setSelectedShooter()
        -   drawShooters(window) // dras shooters on the window
# Asteriod(base class) 
    "defines movement,appearance and behaviour on destruction of asteroids"
    Data 
        -   type   
        -   health
        -   speed 
        -   trajectory(current pos+angle of movement )
        -   pointsAwarded
        -   image
        -   size
        -   bool hasChild // is true if on burst produces  new asteroids
    Methods 
        -   Asteroid()
        -   move() //sets new pos for frame change
        -   getImage()
        -   getType()
        -   setTrajectory()
        -   setSpeed()
        -   setHealth() 
        -   ~Asteriod

Instead of creating all these classes lets just have different functions which create such classes 

# AsteroidManager
    "responsible for maintaining the list of asteroids that are currently on screen"
    Data:
        -   list<Asteroids>
        -   enum asteroidTypes
    Methods:
        -   addAsteroid(asteroidType) // creates different type of asteroid by setting different speed,health etc
        -   hitsEarth() // checks if any asteroid hits the earth 
        -   checkCollison() // checks the event when a asteroid collides missile and handles it and then returns the pointScored
        -   private destroyAsteroid(Asteroid asteroid)
        -   moveAsteroids() // moves all the asteroids when frame changes
        -   Map(function) applies that function to all the asteroids 
        -   drawAsteroids(window) // dras shooters on the window

# Missile(Abstract base class)
    Data:
        -   speed
        -   size
        -   trajectory = (currentPos,angleOfMovement) 
        -   impactRadius
        -   bool specialEffectOnBlast
        -   targetCoordinates
        -   image
        -   type
    Method:
        -   Missile()
        -   move()
        -   virtual getImage()
        -   virtual getType()
        -   setTrajectory()
        -   setImapctPerimeter
        -   virtual effectOnBlast()

# NormalMissile(extends Missile)
    Method
        -   NormalMissile()
        -   overides effectOnBlast()

# BigBlaster(extends Missile)
    Method
        -   BigBlaster()
        -   overides effectOnBlast()

#  Missile2(extends Missile)
    Method
        -   Missile2()
        -   overides effectOnBlast()

# MissileManager
"handles the missiles that are present on the screen"
    Data
        -   list (Missiles)
    Method
        -   addMissile(Missile) // 
        -   move() // changes the position of missiles when frame changes
        -   removeMissile()
        -   handleTargetReached() // handles the behaviour of missile when target is reached
        -   Map(function_ptr) // aplies the funciton on all the missiles
        -   drawMissiles(window) // draw missiles on the window

# GameLogic
    Data
        -   GameScore
        -   bool GameOver
        -   file highScoreKeeper
        -   MissileManager 
        -   AsteroidManager
        -   ShooterManager
    Method
        -   GameLogic()
        -   actionOnKeys(key) //defines behaviour of game when keys are used by user
        -   mouseListener()   // defines behaviour of game on mouse clicks by user
        -   handleFrameEvents() //  defines tasks to do between frames
        -   handlegameOver()    // defines tasks to do when game is over

<!-- # PowerUp:
    Data
    - duration: int (duration of the power-up effect in seconds)
    - active: bool (indicates if the power-up is currently active)
    
    Methods
    - activate(): Activates the power-up effect.
    - deactivate(): Deactivates the power-up effect.
    - update_status(): Checks if the power-up duration has ended.


# NoCooldownPowerUp(PowerUp):
    Data
    - target_satellite: Shooter (reference to the satellite getting the powerup)
    
    Methods
    - activate_nocooldown(): Removes cooldown for the target satellite.
    - deactivate_nocooldown(): Restores the original cooldown for the target satellite.


# CooldownReductionPowerUp(PowerUp):
    Data
    - target_shooter: List[Shooter] (list of shooter affected by cooldown reduction)
    - reduction_factor: float (factor by which cooldown is reduced)
    
    Methods
    - activate_redcooldown(): Reduces cooldown for target shooter.
    - deactivate_redcooldown(): Restores the original cooldown for the target shooter. -->

<!-- # BossAsteroid (derived from base class: Asteroid )
    Data
        -image 
    Methods 
        -Constructor
            - base class +
            - set bigger health 
            - set low Speed
            - set points on destruction
            - subasteroids 
            - subasteroid movements

# SplitAsteroid (derived from base class: Asteroid)
    Methods 
        -overrides destruction (creates two new asteroids) -->