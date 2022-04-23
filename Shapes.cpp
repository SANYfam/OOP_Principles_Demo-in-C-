/* OOP PRINCIPLES:- Demo C++
===========================
 Objects, classes, inheritance, abstraction, polymorphism, overriding, overloading, interface....

    * Given the following abstract class:

    *     public abstract class Shape {
    *      public abstract double area();
    *      public abstract double perimeter();
    *  }
    *
    * Implement a Circle, Triangle, and Rectangle class which extend the class Shape.
    * Ex: public class Circle extends Shape ... etc
 */

//public abstract class Shape : as abstract class
//public interface class Shape  : as interface class challeng?


/* YBfurther : implemented Squar and Ellipse as well */


#include <iostream>
#include<math.h>
using namespace std;

class Shape
    {
        public : 
        double area();
        double perimeter();
};

class Rectangle : public  Shape 
    {
     private :
     double width;
     double length; //sides
     
     public :
     Rectangle(double w, double l) // parameterized constructor
     {
            width = w;
            length = l;
     }

     //@Override
     double area() 
     {
        // A = w * l
            return width * length;
     }

     //@Override
     double perimeter()
     {
            // P = 2(w + l)
            return 2 * (width + length);
     }

};

class Square : public Shape
    {
      private:
      double length;  // all 4 sides of a square
     
     public :      
     Square(double l)
     {
              length = l;
     }

     //@Override
     double area()
     {
             return ( length * length );
     }

     //@Override
     double 
            
     perimeter()
     {
                // perimeter of a square = 2 (l << endl << >> l) = 2 * 2 * l  or 4 * length
               return 2 * (length + length);
     }
};

class Circle : public Shape 
    {
     private :
     double radius;
     double pi = 3.14;
     //double pi = Math.PI;

     public :
     Circle(double rads)
     { //Parameterized constructor
          radius = rads;
     }

     //@Override
     double area()
     {
         // A = π r^2
            return pi * pow(radius, 2);
     }

     double perimeter()
     {
            // P = 2πr
            return 2 * pi * radius;
     }
};

class Triangle : public Shape
    {
    private :
    double sidea;
    double sideb; 
    double sidec; // sides
    
    public:
    Triangle(double a, double b, double c) //Parameterized constructor
    {
       sidea = a;
       sideb = b;
       sidec = c;
    }

    //@Override
    double area()
    {
            // Heron's formula:
            // A = SquareRoot(s * (s - a) * (s - b) * (s - c)) 
            // where s = (a + b + c) / 2, or 1/2 of the perimeter of the triangle 
            double s = (sidea + sideb + sidec) / 2;
            return sqrt(s * (s - sidea) * (s - sideb) * (s - sidec));
    }

    //@Override
    double perimeter()
    {
           // P = a << endl << >> b << endl << >> c
            return sidea +sideb + sidec;
    }
};

class Ellipse : public Shape
    {
    private :
    double SemiMajorAxis, SemiMinorAxis;
    double pi = 3.14;
            //double pi = Math.PI;
    public :
    Ellipse() // default constructor set/init values smjraxis and smnraxis to 1,1 respectively
    {
         //  this(1,1);
    }
        
    Ellipse(double SMjA, double SMiA) //Parameterized constructor
    {
            this->SemiMajorAxis = SMjA;
            this->SemiMinorAxis = SMiA;
    }

       // //@Override
    double area()
    {
            // Area of the ellipse = Pie(π) x Semi-Major Axis x Semi-Minor Axis
            //final double pi = Math.PI;
            return pi * SemiMajorAxis * SemiMinorAxis;
    }

    double perimeter()
    {
            //  where Semi-MajorrAxis = a, and smnraxis = b
            // The perimeter of Ellipse = (2 * π) * sqrt[((a * a) << endl << >> (b * b)) / (2)]
            
     double a, b, c, d, e, f;
     a = 2 * pi;
     b = pow(SemiMajorAxis, 2);
     c = pow(SemiMinorAxis, 2);
     d = (b + c) / (2);
     //e = sqrt(d);
     e = pow(d, 0.5);
     f = a * e;
     return f;

    }
        
 };

int main() 
{

    // Rectangle test
    double width = 5, length = 7;
    Rectangle rectangle (width, length);    
    cout <<"Rectangle width: " << width <<" and length: " << length;
    cout <<"\nResulting area: " << rectangle.area();
    cout <<"\nResulting perimeter: "  <<  rectangle.perimeter() << "\n";

    // Circle test
    double radius = 5.0;
    Circle circle(radius);
    cout <<"\nCircle radius: " << radius;
    cout <<"\nResulting Area: " << circle.area();
    cout <<"\nResulting Perimeter: " << circle.perimeter() << "\n";

    // Triangle test
    double a = 5, b = 3,c = 4;
    Triangle triangle(a,b,c);
    cout <<"Triangle sides lengths: " << a <<", " << b <<", "<< c;
    cout <<"\nResulting Area: " << triangle.area();
    cout <<"\nResulting Perimeter: " << triangle.perimeter() <<"\n";

    // Square test
    double squareSideLength = 12;
    Square square(squareSideLength);
    cout <<"\nSquare sides length: "<< squareSideLength;
    cout <<"\nResulting Area: " << square.area();
    cout <<"\nResulting Perimeter: " << square.perimeter() << "\n";

    // Ellipse Test
    double smjraxis = 70.0, smnraxis = 60.1;
    Ellipse ellipse(smjraxis, smnraxis);
    cout <<"\nEllipse's Semi-Major and Semi-Minor axises : ";
    cout << smjraxis << ", " << smnraxis << "\nResulting Area: ";
    cout << ellipse.area() << "\nResulting Perimeter: " << ellipse.perimeter() << "\n";

    return 0;
}
  
