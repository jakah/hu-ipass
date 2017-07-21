#include "ostream"
#include "stdint.h"
#include "../arm/testarm.hpp"
#include "../arm/coordinate.hpp"
// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE( "all positive" ){
    int len1 = 100;
    int len2 = 100;
    coordinate position (50,50);
    int servo1;
    int servo2;

    testarm arm (len1,len2,servo1,servo2);
    int result = arm.set_position(position);
    REQUIRE(result == 0);
    REQUIRE(arm.get_joint1_degrees() == 68);  
    REQUIRE(arm.get_joint2_degrees() == 46 );     
}

TEST_CASE( "x zero" ){
    int len1 = 100;
    int len2 = 100;
    coordinate position (0,50);
    int servo1;
    int servo2;

    testarm arm (len1,len2,servo1,servo2);
    int result = arm.set_position(position);
    REQUIRE(result == 1);  
}

TEST_CASE( "y zero" ){
    int len1 = 100;
    int len2 = 100;
    coordinate position (50,0);
    int servo1;
    int servo2;

    testarm arm (len1,len2,servo1,servo2);
    int result = arm.set_position(position);
    REQUIRE (result == 1);     
}

TEST_CASE( "both zero" ){
    int len1 = 100;
    int len2 = 100;
    coordinate position (0,0);
    int servo1;
    int servo2;

    testarm arm (len1,len2,servo1,servo2);
    int result = arm.set_position(position);
    REQUIRE (result == 1);     
}

TEST_CASE( "both negative position" ){
    int len1 = 100;
    int len2 = 100;
    coordinate position (-100,-10);
    int servo1;
    int servo2;

    testarm arm (len1,len2,servo1,servo2);
    int result = arm.set_position(position);
    REQUIRE (result == 1);      
}

TEST_CASE( "x negative position" ){
    int len1 = 100;
    int len2 = 100;
    coordinate position (-100,100);
    int servo1;
    int servo2;

    testarm arm (len1,len2,servo1,servo2);
    int result = arm.set_position(position);
    REQUIRE (result == 1);      
}
TEST_CASE( "y negative position" ){
    int len1 = 100;
    int len2 = 100;
    coordinate position (100,-100);
    int servo1;
    int servo2;

    testarm arm (len1,len2,servo1,servo2);
    int result = arm.set_position(position);
    REQUIRE (result == 1);      
}