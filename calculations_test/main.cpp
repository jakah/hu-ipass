#include "ostream"
#include "../arm/calculations.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE("radianstodegrees, positive"){
    int degrees = radianstodegrees(0.39865);
    REQUIRE(degrees == 22);
}

TEST_CASE("radianstodegrees, negative"){
    int degrees = radianstodegrees(-0.39865);
    REQUIRE(degrees == -22);
}

TEST_CASE( "servo2, all positive" ){
    int len1 = 100;
    int len2 = 100;
    int x = 55;
    int y = 55;
    float servo2 = calc_servo2(len1,len2,x,y);

    REQUIRE(servo2 == Approx(2.3681) );     
}

TEST_CASE( "servo2, negative x" ){
    int len1 = 100;
    int len2 = 100;
    int x = -55;
    int y = 55;
    float servo2 = calc_servo2(len1,len2,x,y);

    REQUIRE(servo2 == Approx(0.7719) );     
}

TEST_CASE( "servo2, negative y" ){
    int len1 = 100;
    int len2 = 100;
    int x = 55;
    int y = -55;
    float servo2 = calc_servo2(len1,len2,x,y);

    REQUIRE(servo2 == Approx(2.3681) );     
}

TEST_CASE( "servo1, all positive" ){
    int len1 = 100;
    int len2 = 100;
    int x = 55;
    int y = 55;
    float servo2 = calc_servo2(len1,len2,x,y);
    float servo1 = calc_servo1(len1,len2,x,y,servo2);

    REQUIRE(servo2 == Approx(2.3681)); 
    REQUIRE(servo1 == Approx(2.74135)); 
}

TEST_CASE( "servo1, negative x" ){
    int len1 = 100;
    int len2 = 100;
    int x = -55;
    int y = 55;
    float servo2 = calc_servo2(len1,len2,x,y);
    float servo1 = calc_servo1(len1,len2,x,y,servo2);

    REQUIRE(servo2 == Approx(0.7719)); 
    REQUIRE(servo1 == Approx(1.16976)); 
}

TEST_CASE( "servo1, negative y" ){
    int len1 = 100;
    int len2 = 100;
    int x = 55;
    int y = -55;

    float servo2 = calc_servo2(len1,len2,x,y);
    float servo1 = calc_servo1(len1,len2,x,y,servo2);

    REQUIRE(servo2 == Approx(2.3681)); 
    REQUIRE(servo1 == Approx(1.17055)); 
}
