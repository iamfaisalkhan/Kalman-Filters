# Extended Kalman Filter
---

An implementation of kalman filter for predicting and tracking the position and velocity of a moving object in a 2D world. The tracking is done using the input from two sensors:

* Laser (LIDAR)
* RADAR

The LIDAR sensor measures only the position of the object. The RADAR sensor provides measurement for the range (radial distance $$\rho$$ from the origin), bearing (angle between x-axis and the range vector and also the radial velocity (change of $$\rho$$). 

In this project, we use the Kalman Filter (KF) to combine the measurements from these two sensor to predict a 4D state of the moving object that includes its position and its velocity.  

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make` 
   * On windows, you may need to run: `cmake .. -G "Unix Makefiles" && make`
4. Run it: `./ExtendedKF path/to/input.txt path/to/output.txt`. You can find
   some sample inputs in 'data/'.
    - eg. `./ExtendedKF ../data/obj_pose-laser-radar-synthetic-input.txt`

