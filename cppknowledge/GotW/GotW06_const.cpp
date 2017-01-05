/*
 * GotW06_const.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: songjiguo
 */

/*Guideline: Remember the “M&M rule”: For a member variable, mutable
 * and mutex (or atomic) go together.*/

/*Guideline: Prefer declaring variables using auto. */

/*Guideline: Prefer range-based for loops to naked iterator-incrementing for
  loops when visiting the elements of the range in order.*/

/*
Guideline: Prefer passing a read-only parameter by const& if you are only
going to read from it (not make a copy of it).
*/

/*
Guideline: Prefer passing a read-only parameter by value if you’re going to
make a copy of the parameter anyway, because it enables move from rvalue arguments.
*/

/*Guideline: Prefer to make variables, including locals, const if they should not change. */


/*With C++98, we taught a generation of C++ developers that “const
 * means logically const, not physically/bitwise const.” That is, in
 * C++98 we taught that const meant only that the observable state of
 * the object (say, via its non-private member functions) should not
 * change as far as the caller could tell, but its internal bits might
 * change in order to update counters and instrumentation and other
 * data not accessible via the type’s public or protected interface.*/

/*
#include <iostream>
#include <vector>

using namespace std;

struct point {
	int x;
	int y;
};


class polygon {
public:
    polygon() : area{-1} {}

    // Note that because of the atomic member, which is not copyable, we now provide polygon‘s copy and move operations explicitly.
    polygon( const polygon& other ) : points{other.points}, area{-1} { }


    void add_point( const point pt ) { area = -1;
                                       points.push_back(pt); }

    point get_point( const int i ) { return points[i]; }

    int get_num_points() { return points.size(); }

    double get_area() {
        if( area < 0 )   // if not yet calculated and cached
            calc_area();     // calculate now
        return area;
    }

private:
    void calc_area() {
        area = 0;
        vector<point>::iterator i;
        for( i = begin(points); i != end(points); ++i )
            area += 2;
    }

    vector<point> points;
    double        area;
};

polygon operator+( polygon& lhs, polygon& rhs ) {
    auto ret = lhs;
    auto last = rhs.get_num_points();
    for( auto i = 0; i < last; ++i ) // concatenate
        ret.add_point( rhs.get_point(i) );
    return ret;
}

void f( const polygon& poly ) {
    const_cast<polygon&>(poly).add_point( {0,0} );
}

//void g( polygon& const poly ) { poly.add_point( {1,1} ); }

void h( polygon* const poly ) { poly->add_point( {2,2} ); }

int main() {
    polygon poly;
    const polygon cpoly;

    f(poly);
    f(cpoly);
//    g(poly);
    h(&poly);
}
*/
int main() {

}
