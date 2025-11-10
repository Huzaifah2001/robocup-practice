#include <iostream>
#include "WalkingGait.h"
#include "PIDController.h"

int main() {
    std::cout << "=== RoboCup Robot Motion Control ===" << std::endl;
    
    // Create walking gait controller
    WalkingGait gait(0.1, 0.05, 0.7); // step length, height, balance
    
    std::cout << "\n=== Testing Walking Gait ===" << std::endl;
    
    // Simulate walking sequence
    for(int step = 0; step < 3; step++) {
        std::cout << "\n--- Step " << step + 1 << " ---" << std::endl;
        
        for(int leg = 0; leg < 4; leg++) {
            double phase = (leg * 0.25) + (step * 0.1);
            gait.calculateLegTrajectory(leg, phase);
        }
        
        // Check balance
        if(gait.checkBalance()) {
            std::cout << "Balance: STABLE" << std::endl;
        } else {
            std::cout << "Balance: UNSTABLE - Adjusting..." << std::endl;
        }
    }
    
    std::cout << "\n=== Walking Sequence Complete ===" << std::endl;
    return 0;
}
