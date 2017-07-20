#include "arm.hpp"
/// \file
/// \class servoarm
/// \brief
/// \a arm with servomotors
class servoarm : public arm{
protected:
    Servo &servo1;
    Servo &servo2;
    int servo1_degrees;
    int servo2_degrees;
public:   
    /// \brief
    /// a robotarm with servomotors as joints
    /// \param[in] int len1, the lenght of the first arm
    /// \param[in] int len2, the lenght of the second arm
    /// \param[in] Servo servo1, the servo that is joint1
    /// \param[in] Servo servo2, the servo that is joint2
    servoarm(int &len1, int &len2, Servo &servo1, Servo &servo2);
    /// \brief
    /// set the angle of the first joint
    /// \param[in] uint16_t degrees, the angle the first joint should be set to
    void set_joint1(const uint16_t &degrees);
    /// \brief
    /// set the angle of the second joint
    /// \param[in] uint16_t degrees, the angle the second joint should be set to
    void set_joint2(const uint16_t &degrees);
};