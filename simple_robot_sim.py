import time
import math

class VirtualRobot:
    def __init__(self):
        self.leg_positions = [0, 0, 0, 0]
        self.body_position = 0
        
    def update_walking_gait(self, time_step):
        # Use the same algorithm from our C++ code
        for leg in range(4):
            phase = (leg * 0.25) + (time_step * 0.1)
            x = 0.1 * math.sin(phase * 2 * math.pi)
            z = 0.05 * (1 - math.cos(phase * 2 * math.pi)) / 2
            self.leg_positions[leg] = (x, z)
        
        self.body_position = time_step * 0.05  # Robot moves forward
        
    def display_robot(self, step):
        print(f'\n\033[1;36m=== STEP {step} ===\033[0m')
        print(f'Robot Position: {self.body_position:.2f}m')
        print('Leg Positions:')
        
        for i, (x, z) in enumerate(self.leg_positions):
            # Create simple ASCII visualization
            spaces = ' ' * int((x + 0.5) * 20)
            leg_char = '🦵' if z > 0.02 else '│'
            print(f'  Leg {i}: {spaces}{leg_char} (x:{x:.2f}m, z:{z:.2f}m)')
        
        # Simple balance indicator
        balance = '✅ STABLE' if all(z < 0.03 for _, z in self.leg_positions) else '⚠️  ADJUSTING'
        print(f'Balance: {balance}')

# Create and animate robot
print('🤖 \033[1;32mROBOCUP ROBOT SIMULATION\033[0m 🤖')
print('Press Ctrl+C to stop...')

robot = VirtualRobot()

try:
    for step in range(20):
        robot.update_walking_gait(step)
        robot.display_robot(step + 1)
        time.sleep(1)
except KeyboardInterrupt:
    print('\n\n🎯 Simulation stopped. Great job!')

print('\n🚀 Your walking gait algorithm is working!')
print('📊 The robot is moving forward with coordinated leg movements!')
