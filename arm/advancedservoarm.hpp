#include "servoarm.hpp"

class advancedservoarm : public servoarm{
private:
    int servo1_offset;
    int servo2_offset;
public:
   advancedservoarm(int &len1, int &len2, Servo &servo1, Servo &servo2, int servo1_offset, int servo2_offset);
    void set_joint1(const uint16_t &degrees);
    void set_joint2(const uint16_t &degrees);
    /// \brief
    /// set the position of y in 
    /// \details
    /// Give the amount of degrees that need to be added to position the servo to the Y-axis
    void set_offset_servo1(uint16_t &degrees);
    /// \brief
    /// set the offset for servo 2
    /// \details 
    /// Give the amount of degrees that need to be added to the second servo so it is 
    void set_offset_servo2(uint16_t &degrees);
};