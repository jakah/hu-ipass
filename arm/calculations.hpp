#include "stdint.h"
#include "coordinate.hpp"
/// \file
/// \brief
/// calculate the joint angles
/// \details
/// given the lenght and coordinates the arm should move to, this function calculates the angle of the joints
/// calculations arm based on this document http:://www.hessmer.org/uploads/RobotArm/Inverse%2520Kinematics%2520for%2520Robot%2520Arm.pdf
/// \param[in] int len1, the length of the first arm
/// \param[in] int len2, the lenght of the second arm
/// \param[in] coordinate position, the position the end of the arm should move to
/// \param[out] uint16_t servo1, the angle joint1 should be set to
/// \param[out] uint16_t servo2, the angle joint2 should be set to
/// \result int error, 0 on success 1 on error.
int calc_positions(int &len1,int &len2,coordinate &position,uint16_t &servo1, uint16_t &servo2);