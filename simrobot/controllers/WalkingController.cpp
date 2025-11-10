#include "Controller.h"
#include "SimRobot/Actuators/Motor.h"
#include "SimRobot/Sensors/JointAngleSensor.h"
#include <iostream>
#include <cmath>

// REUSE YOUR EXISTING CODE!
#include "../../include/WalkingGait.h"

class WalkingController : public Controller {
private:
    Motor* legMotors[4];
    JointAngleSensor* jointSensors[4];
    WalkingGait* gait;
    double time;

public:
    WalkingController() : time(0) {}
    
    void init() override {
        std::cout << "🤖 Initializing SimRobot Walking Controller..." << std::endl;
        
        // Initialize your existing gait algorithm
        gait = new WalkingGait(0.1, 0.05, 0.7);
        
        // Get motors (names would match your SimRobot model)
        for(int i = 0; i < 4; i++) {
            legMotors[i] = getMotor("leg_motor_" + std::to_string(i));
            jointSensors[i] = getSensor<JointAngleSensor>("joint_sensor_" + std::to_string(i));
        }
        
        std::cout << "✅ Controller initialized with 4 leg motors" << std::endl;
    }
    
    void step() override {
        time += 0.01; // Simulated time step
        
        // USE YOUR EXISTING WALKING ALGORITHM!
        for(int leg = 0; leg < 4; leg++) {
            double phase = (leg * 0.25) + (time * 0.1);
            double x, z;
            // Calculate trajectory using your existing method
            // For SimRobot, we convert to joint angles
            double targetAngle = gait->calculateLegTrajectory(leg, phase).first * 10.0; // Scale for simulation
            
            // Apply to motor
            if(legMotors[leg]) {
                legMotors[leg]->setPosition(targetAngle);
            }
        }
        
        // Check balance using your existing method
        if(gait->checkBalance()) {
            // Stable - continue walking
        } else {
            // Unstable - adjust gait
            std::cout << "⚠️  Balance unstable - adjusting..." << std::endl;
        }
        
        // Output every 100 steps
        if(static_cast<int>(time * 100) % 100 == 0) {
            std::cout << "🚶 Walking... Time: " << time << "s" << std::endl;
        }
    }
    
    ~WalkingController() {
        delete gait;
    }
};

// SimRobot controller registration
extern "C" {
    Controller* createController() {
        return new WalkingController();
    }
}
