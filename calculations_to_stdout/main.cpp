#include <iostream>
#include "../arm/calculations.hpp"
int main( void ){
    int len1 = 170;
    int len2 = 100;
    int x = 100;
    int y = 150;
    int error = 0;
    float s2 = calc_servo2(len1,len2 ,x ,y,0,error);
    float s1 = calc_servo1(len1,len2 ,x ,y,s2,error);
    if (s1 > 0){
                    std::cout << " s2: " << s2  << " degrees: " << radianstodegrees(s2) << "\n";
                std::cout << "s1: " << s1 << " degrees: " << radianstodegrees(s1) << "\n"; 
                std::cout << "=========================================================="<<"\n";
    }
    else {
        float s2 = calc_servo2(len1,len2 ,x ,y,-1,error);
        float s1 = calc_servo1(len1,len2 ,x ,y,s2,error);
                            std::cout << " s2: " << s2  << " degrees: " << radianstodegrees(s2) << "\n";
                std::cout << "s1: " << s1 << " degrees: " << radianstodegrees(s1) << "\n"; 
                std::cout << "=========================================================="<<"\n";
    }
    // for (int x = 100; x <150; x++){
    //     for (int y =100; y <150; y++){
    //         float s2 = calc_servo2(len1,len2 ,x ,y,error);
    //         float s1 = calc_servo1(len1,len2 ,x ,y,s2,error);
    //         if ((s1 != s1 || s2 !=s2 || s1 < 0 || s2 < 0)){
    //             // std::cout << " x: " << x << " y: " << y << "\n";
    //             // std::cout << " s2: " << s2  << " degrees: " << radianstodegrees(s2) << "\n";
    //             // std::cout << "s1: " << s1 << " degrees: " << radianstodegrees(s1) << "\n"; 
    //         }

    //     }
    // } 
}
