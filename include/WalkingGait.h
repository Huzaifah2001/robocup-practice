#ifndef WALKINGGAIT_H
#define WALKINGGAIT_H

class WalkingGait {
private:
    double stepLength;
    double stepHeight;
    double balanceFactor;
    
public:
    WalkingGait(double length, double height, double balance);
    void calculateLegTrajectory(int legId, double phase);
    void setStepParameters(double length, double height);
    bool checkBalance();
};

#endif
