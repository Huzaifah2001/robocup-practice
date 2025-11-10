#include "WalkingGait.h"
#include <iostream>
#include <cmath>

WalkingGait::WalkingGait(double length, double height, double balance) 
    : stepLength(length), stepHeight(height), balanceFactor(balance) {}

void WalkingGait::calculateLegTrajectory(int legId, double phase) {
    // Sine wave for smooth leg movement
    double x = stepLength * sin(phase * 2 * M_PI);
    double z = stepHeight * (1 - cos(phase * 2 * M_PI)) / 2;
    
    std::cout << "Leg " << legId << " - Phase: " << phase 
              << " -> X: " << x << " Z: " << z << std::endl;
}

void WalkingGait::setStepParameters(double length, double height) {
    stepLength = length;
    stepHeight = height;
    std::cout << "Step parameters updated - Length: " << length 
              << " Height: " << height << std::endl;
}

bool WalkingGait::checkBalance() {
    return balanceFactor > 0.5; // Simple balance check
}
