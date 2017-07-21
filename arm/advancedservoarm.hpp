#include "servoarm.hpp"
/// \file
/// \class advancedservoarm
/// \brief 
/// a servo arm with more functionality
/// \details
/// A servoarm with the possibility to add offset for the servo motor's.
class advancedservoarm : public servoarm{
private:
    int servo1_offset;
    int servo2_offset;
public:
    /// \brief
    /// constructor for an advanced servoarm
    /// \param[in] int len1, the lenght of the first arm
    /// \param[in] int len2, the lenght of the second arm
    /// \param[in] Servo servo1, the servo that is joint1
    /// \param[in] Servo servo2, the servo that is joint2
    /// \param[in] int servo1_offset, the amount of degrees the first servo is off from the x or y axis.
    /// \param[in] int servo1_offset, the amount of degrees the first servo is off from the x or y axis.
    advancedservoarm(int &len1, int &len2, Servo &servo1, Servo &servo2, int servo1_offset, int servo2_offset);
    /// \brief
    /// set the angle of the first joint
    /// \details 
    /// This function will set the angle of the first joint, it will add the offset to degrees
    /// \param[in] uint16_t degrees, the angle the first joint should be set to
    void set_joint1(const uint16_t &degrees);
    /// \brief
    /// set the angle of the second joint
    /// \details 
    /// This function will set the angle of the second joint, it will add the offset to degrees
    /// \param[in] uint16_t degrees, the angle the second joint should be set to
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