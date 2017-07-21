#ifndef COORDINATE_HPP
#define COORDINATE_HPP

/// @file

/// \brief
/// coordinate ADT
/// \details
/// This is an ADT that implement coordinates.
/// The x and y value are stored as two integers.
/// The appropriate constructors are provide.
///
/// The following operators are implemented: +, +=, *, *= and <<
class coordinate{
private:
    int x;
    int y;
public:
    /// \brief
    /// constructor from explicit values
    /// \details
    /// This constructor initializes coordinate from a x and y value
    /// The default values for x and y are 0 and 0
    coordinate(int x , int y):
        x(x), y(y)
    {}
    coordinate():
        x( 0 ), y( 0 )
    {}
    /// \brief
    /// the x value of the coordinate
    /// \result int x
    int get_x (){
        return x;
    }
    /// \brief
    /// the y value of the coordinate
    /// \result int y
    int get_y(){
        return y;
    }
    /// \brief
    /// add a coordinate to another coordinate
    /// \details
    /// This operator+ adds a coordinate to another coordinate.
    coordinate operator+( const coordinate& rhs ) const {
        return coordinate( x + rhs.x, y + rhs.y );
    }

    /// \brief
    /// monodic plus operator
    /// \details
    /// This operator returns a coordinate with x and y.
    coordinate operator+() const {
        return coordinate( x, y );
    }

    /// \brief
    /// add a coordinate to itself
    /// \details
    /// This operator+= adds a coordinate to itself.
    coordinate &operator+=( const coordinate & rhs ){
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    /// \brief
    /// add a coordinate to another coordinate
    /// \details
    /// This operator- subtracts a coordinate to another coordinate.
    coordinate operator-( const coordinate& rhs ) const {
        return coordinate( rhs.x - x, rhs.y -y );
    }

    /// \brief
    /// add a coordinate to itself
    /// \details
    /// This operator+= adds a coordinate to itself.
    coordinate &operator-=( const coordinate & rhs ){
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    /// \brief
    /// multiply a coordinate with another coordinate
    /// \details
    /// This operator*  multiplies a coordinate by a coordinate.
    coordinate operator*(const coordinate & rhs) const {
        return coordinate(
            x * rhs.x,
            y * rhs.y
        );
    }

    /// \brief
    /// multiply a coordinate by an integer
    /// \details
    /// This operator multiplies a coordinate with an integer and will return a
    /// coordinate
    coordinate operator*(const int & rhs) const {
        return coordinate(
            x * rhs,
            y * rhs
        );
    }

    /// \brief
    /// multiply integer by a coordinate
    /// \details
    /// This operator multiplies an integer with a coordinate and returns a coordinate
    friend coordinate operator*(const int lhs, const  coordinate & rhs){
        return coordinate(lhs * rhs.x, lhs * rhs.y);
    }

    /// \brief
    /// multiply a coordinate by itself
    /// \details
    /// This operator*= multiplies a coordinate into a coordinate and stores it in
    /// itself.
    coordinate &operator*=( const coordinate & rhs ){
        x = x * rhs.x;
        y = y * rhs.y;
        return *this;
    }

    /// \brief
    /// multiply integer into coordinate
    /// \details
    /// This operator multiplies a integer into a coordinate.
    coordinate &operator*=( const int & rhs ){
        x = x * rhs;
        y = y * rhs;
        return *this;
    }
    /// \brief
    /// output operator for a coordinate
    /// \details
    /// This operator<< prints a constructor in the format (x,y) where both
    /// values are printed as integers.
    // friend hwlib::window_ostream & operator<<( hwlib::window_ostream & lhs, coordinate pos ){
    //     lhs << "(" << pos.x << "," << pos.y << ")";
    //     return lhs;
    // }
};

#endif