#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

class ShapeTwoD
{
    protected :
        string name;
        bool containsWarpSpace;
    
    public :
        ShapeTwoD()
        {
            this->name = "john";
            this->containsWarpSpace = true;
        }
    
        ShapeTwoD(string name, bool containsWarpSpace)
        {
            this -> name = name;
            this -> containsWarpSpace = containsWarpSpace;
        }
 
        string getName()
        {
            return name;
        }
    
        bool getContainsWarpSpace()
        {
            return containsWarpSpace;
        }
        
        virtual string toString()
        {
            return "\n";
        }
    
        virtual double computeArea()
        {
            return 0.1;
        }
    
        virtual bool isPointInShape(int x, int y)
        {
            return true;
        }
    
        virtual bool isPointOnShape(int x, int y)
        {
            return false;
        }
    
        void setContainsWarpSpace(bool containsWarpSpace)
        {
            this->containsWarpSpace = containsWarpSpace;
        }
};
    
class Square : public ShapeTwoD
{
    private :
        int x1, x2, x3, x4;
        int y1, y2, y3, y4;
        int num;
        int xArray[4];
        int yArray[4];
    
    public :
        Square(string name, bool containsWarpSpace, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int num) : ShapeTwoD(name, containsWarpSpace)
        {
            this -> x1 = x1;
            this -> y1 = y1;
            this -> x2 = x2;
            this -> y2 = y2;
            this -> x3 = x3;
            this -> y3 = y3;
            this -> x4 = x4;
            this -> y4 = y4;
            this -> num = num;
            xArray[0] = x1;
            xArray[1] = x2;
            xArray[2] = x3;
            xArray[3] = x4;
            yArray[0] = y1;
            yArray[1] = y2;
            yArray[2] = y3;
            yArray[3] = y4;
        }
        
        string getName()
        {
            return name;
        }

        bool getContainsWarpSpace()
        {
            return containsWarpSpace;
        }

        string toString()
        {
            ostringstream sout;
            string a;
            if(containsWarpSpace == false)
                a = "NS\n";
            else
                a = "WS\n";
            
            sout << "Shape [" << num << "]\n" << "Name : " << name << "\nSpecial Type : " << a ;
            sout << "Area : " << computeArea() << " units square" << endl;;
            sout << "Vertices :\n";
            
            for(int i = 0; i < 4; i++)
            {
                sout << "Point [" << i << "] : (" << xArray[i] << ", " << yArray[i] << ")\n";
            }
            sout << endl << "Points on perimeter : ";
            
            bool none = true;
            
            for(int i = min(xArray); i <= max(yArray); i++)
            {
                for(int j = min(yArray); j <= max(yArray); j++)
                {
                    if(isPointOnShape(i,j))
                    {
                        sout << "(" << i <<  "," << j << ")";
                        none = false;
                    }
                }
            }
            
            if(none == true)
            {
                sout << "None!";
            }
            sout << endl;
            none = true;
        sout << endl;
            
            sout << "Points within shape : ";
            
            for(int i = min(xArray) + 1; i < max(xArray); i++)
            {
                for(int j = min(yArray) + 1; j < max(yArray); j++)
                {
                    if(isPointInShape(i,j))
                    {
                        sout << "(" << i <<  "," << j << ")";
                        none = false;
                    }
                }
            }
            if(none == true)
            {
                sout << "None!";
            }
        sout << endl;
    sout << endl;
        
            return sout.str();
        }
    
        int max(int array[])
        {
            int largest = array[0];
            for(int i = 1;i < 4; i++)
            {
                if(largest < array[i])
                {
                    largest = array[i];
                }
            }
            return largest;
        }
    
        int min(int array[])
        {
            int smallest = array[0];
            for(int i = 1; i < 4; i++)
            {
                if(smallest > array[i])
                {
                    smallest = array[i];
                }
            }
            
            return smallest;
        }
    
        double computeArea()
        {
            unsigned int length = max(yArray) - min(yArray);
            unsigned int  width = max(xArray) - min(xArray);
            double area = 0.0;
            
            area = length * width * 1.0;
            
            return area;
        }
    
        bool isPointInShape(int x, int y)
        {
            return true;
        }
    
        bool isPointOnShape(int x, int y)
        {
            int min_x = min(xArray);
            int max_x = max(xArray);
            int min_y = min(yArray);
            int max_y = max(yArray);
            
            if(x == min_x && (y> min_y && y< max_y))
            {
                return true;
            }
            else if(x == max_x && (y> min_y && y< max_y))
            {
                return true;
            }
            else if(y == max_y && (x> min_x && x< max_x))
            {
                return true;
            }
            else if(y == min_y && (x> min_x && x< max_x))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        void setName(string name)
        {
            this->name = name;
        }
    
        void setContainsWarpSpace(bool containsWarpSpace)
        {
            this->containsWarpSpace = containsWarpSpace;
        }
};

class Rectangle : public ShapeTwoD
{
    private :
        int x1, x2, x3, x4;
        int y1, y2, y3, y4;
        int num;
        int xArray[4];
        int yArray[4];
    
    public :
        Rectangle(string name, bool containsWarpSpace, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int num) : ShapeTwoD(name, containsWarpSpace)
        {
            this -> x1 = x1;
            this -> y1 = y1;
            this -> x2 = x2;
            this -> y2 = y2;
            this -> x3 = x3;
            this -> y3 = y3;
            this -> x4 = x4;
            this -> y4 = y4;
            this -> num = num;
            xArray[0] = x1;
            xArray[1] = x2;
            xArray[2] = x3;
            xArray[3] = x4;
            yArray[0] = y1;
            yArray[1] = y2;
            yArray[2] = y3;
            yArray[3] = y4;
        }
        
        string getName()
        {
            return name;
        }

        bool getContainsWarpSpace()
        {
            return containsWarpSpace;
        }

        string toString()
        {
            ostringstream sout;
            string a;
            if(containsWarpSpace == false)
                a = "NS\n";
            else
                a = "WS\n";
                
            sout << "Shape [" << num << "]\n" << "Name : " << name << "\nSpecial Type : " << a ;
            sout << "Area : " << computeArea() << " units square" << endl;;
            sout << "Vertices :\n";
                
            for(int i = 0; i < 4; i++)
            {
                sout << "Point [" << i << "] : (" << xArray[i] << ", " << yArray[i] << ")\n";
            }
            sout << endl << "Points on perimeter : ";
                            
            bool none = true;
            
            for(int i = min(xArray); i <= max(xArray); i++)
            {
                for(int j = min(yArray); j <= max(yArray); j++)
                {
                    if(isPointOnShape(i,j))
                    {
                        sout << "(" << i <<  "," << j << ")";
                        none = false;
                    }
                }
            }
            
            if(none == true)
            {
                sout << "None!";
            }
            sout << endl;
            none = true;
        sout << endl;
            
            sout << "Points within shape : ";
            
            for(int i = min(xArray) + 1; i < max(xArray); i++)
            {
                for(int j = min(yArray) + 1; j < max(yArray); j++)
                {
                    if(isPointInShape(i,j))
                    {
                        sout << "(" << i <<  "," << j << ")";
                        none = false;
                    }
                }
            }
            if(none == true)
            {
                sout << "None!";
            }
            sout << endl;
        sout << endl;
            return sout.str();
        }
    
        int max(int array[])
        {
            int largest = array[0];
            for(int i = 1;i < 4; i++)
            {
                if(largest < array[i])
                {
                    largest = array[i];
                }
            }
            return largest;
        }
    
        int min(int array[])
        {
            int smallest = array[0];
            for(int i = 1; i < 4; i++)
            {
                if(smallest > array[i])
                {
                    smallest = array[i];
                }
            }
            return smallest;
        }
    
        double computeArea()
        {
            unsigned int length = max(yArray) - min(yArray);
            unsigned int width = max(xArray) - min(xArray);
            double area = 0.0;
            
            area = length * width * 1.0;
            return area;
        }
    
        bool isPointInShape(int x, int y)
        {
            return true;
        }
    
        bool isPointOnShape(int x, int y)
        {
            int min_x = min(xArray);
            int max_x = max(xArray);
            int min_y = min(yArray);
            int max_y = max(yArray);
            
            if(x == min_x && (y> min_y && y< max_y))
            {
                return true;
            }
            else if(x == max_x && (y> min_y && y< max_y))
            {
                return true;
            }
            else if(y == max_y && (x> min_x && x< max_x))
            {
                return true;
            }
            else if(y == min_y && (x> min_x && x< max_x))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        void setName(string name)
        {
            this->name = name;
        }
    
        void setContainsWarpSpace(bool containsWarpSpace)
        {
            this->containsWarpSpace = containsWarpSpace;
        }
};

class Circle : public ShapeTwoD
{
    private :
        int x, y, radius;
        int num;
    int xCenter = x;
    int yCenter = y;

    public :
        Circle(string name, bool containsWarpSpace, int x, int y, int radius, int num) : ShapeTwoD(name, containsWarpSpace)
        {
            this -> x = x;
            this -> y = y;
            this -> radius = radius;
            this -> num = num;
        }
    
        string getName()
        {
            return name;
        }
        
        bool getContainsWarpSpace()
        {
            return containsWarpSpace;
        }
        
        string toString()
        {
            ostringstream sout;
            string a;
            if(containsWarpSpace == false)
                a = "NS\n";
            else
                a = "WS\n";
            
            sout << "Shape [" << num << "]\n" << "Name : " << name << "\nSpecial Type : " << a ;
            sout << "Area : " << fixed << setprecision(2) << computeArea() << endl;;
            sout << "Center : (" << x << ","<< y << ")\n";
        sout << endl;

            sout << "Points on perimeter : ";
            bool none = true;

            sout << "(" << x - radius <<  "," << y << ")";
        sout << "(" << x <<  "," << y + radius << ")";
        sout << "(" << x + radius <<  "," << y << ")";
        sout << "(" << x <<  "," << y - radius << ")";

            none = false;

            if(none == true)
            {
                sout << "None!";
            }
            sout << endl;
        sout << endl;
            
            sout << "Points within shape : ";
            none = true;
            
            for(int i = ((x - radius) + 1); i < (x + radius); i++)
            {
                for(int j = ((y - radius) + 1); j < (y + radius); j++)
                {
                    if(isPointInShape(i,j))
                    {
                        sout << "(" << i <<  "," << j << ")";
                        none = false;
                    }
                }
            }

            if(none == true)
            {
                sout << "None!";
            }
            sout << endl;
        sout << endl;
            return sout.str();
        }
        
        double computeArea()
        {
            double a = (M_PI * radius * radius);
            return a;
        }
        
        bool isPointInShape(int x1, int y1)
        {
            int distance = sqrt(pow((x1 - x), 2) + pow((y1 - y), 2) * 1.0);

            if(distance < radius)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        bool isPointOnShape(int x, int y)
        {
            if(xCenter == x && yCenter + radius == y)
            {
                return true;
            }
            else if(xCenter == x && yCenter - radius == y)
            {
                return true;
            }
            else if(xCenter + radius == x && yCenter == y)
            {
                return true;
            }
            else if(xCenter - radius == x && yCenter == y)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        void setName(string name)
        {
            this->name = name;
        }
        
        void setContainsWarpSpace(bool containsWarpSpace)
        {
            this->containsWarpSpace = containsWarpSpace;
        }
};

class Cross : public ShapeTwoD
{
    private :
        int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;
        int y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12;
        int num;
        int xArray[12];
        int yArray[12];
	static const int numOfVertices = 12;
    
    public :
        Cross(string name, bool containsWarpSpace, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8, int x9, int y9, int x10, int y10, int x11, int y11, int x12, int y12, int num) : ShapeTwoD(name, containsWarpSpace)
        {
            this -> x1 = x1;
            this -> y1 = y1;
            this -> x2 = x2;
            this -> y2 = y2;
            this -> x3 = x3;
            this -> y3 = y3;
            this -> x4 = x4;
            this -> y4 = y4;
            this -> x5 = x5;
            this -> y5 = y5;
            this -> x6 = x6;
            this -> y6 = y6;
            this -> x7 = x7;
            this -> y7 = y7;
            this -> x8 = x8;
            this -> y8 = y8;
            this -> x9 = x9;
            this -> y9 = y9;
            this -> x10 = x10;
            this -> y10 = y10;
            this -> x11 = x11;
            this -> x11 = y11;
            this -> x12 = x12;
            this -> y12 = y12;
            this -> num = num;
            xArray[0] = x1;
            xArray[1] = x2;
            xArray[2] = x3;
            xArray[3] = x4;
            xArray[4] = x5;
            xArray[5] = x6;
            xArray[6] = x7;
            xArray[7] = x8;
            xArray[8] = x9;
            xArray[9] = x10;
            xArray[10] = x11;
            xArray[11] = x12;
            yArray[0] = y1;
            yArray[1] = y2;
            yArray[2] = y3;
            yArray[3] = y4;
            yArray[4] = y5;
            yArray[5] = y6;
            yArray[6] = y7;
            yArray[7] = y8;
            yArray[8] = y9;
            yArray[9] = y10;
            yArray[10] = y11;
            yArray[11] = y12;
        }
    
        string getName()
        {
            return name;
        }

        bool getContainsWarpSpace()
        {
            return containsWarpSpace;
        }

        string toString()
        {
            ostringstream sout;
            string a;
            if(containsWarpSpace == false)
                a = "NS\n";
            else
                a = "WS\n";
            
            sout << "Shape [" << num << "]\n" << "Name : " << name << "\nSpecial Type : " << a ;
            sout << "Area : " << computeArea() << " units square" << endl;;
            sout << "Vertices :\n";
            
            for(int i = 0; i < numOfVertices; i++)
            {
                sout << "Point [" << i << "] : (" << xArray[i] << ", " << yArray[i] << ")\n";
            }
            
            sout << "\nPoints on perimeter : ";
            
            bool none = true;
            
            for(int i = min(xArray); i <= max(xArray); i++)
            {
                for(int j = min(yArray); j <= max(yArray); j++)
                {
                    if((isPointOnShape(i,j) == true) && (isCoordinate(i, j) == false))
                    {
                        sout << "(" << i <<  "," << j << ")";
                        none = false;
                    }
                }
            }
            
            if(none == true)
            {
                sout << "None!";
            }
            none = true;
            sout << endl;
               
            sout << "Points within shape : ";
            for(int i = min(xArray); i <= max(yArray); i++)
            {
                for(int j = min(yArray); j <= max(yArray); j++)
                {
                    if((isPointInShape(i,j) == true) && (isCoordinate(i, j) == false))
                    {
                        sout << "(" << i <<  "," << j << ")";
                        none = false;
                    }
                }
            }
            if(none == true)
            {
                sout << "None!";
            }
        sout << endl;
        sout << endl;

        return sout.str();
        }

        int max(int array[])
        {
            int largest = array[0];
            for(int i = 1; i < numOfVertices; i++)
            {
                if(largest < array[i])
                {
                    largest = array[i];
                }
            }
            return largest;
        }
    
        int min(int array[])
        {
            int smallest = array[0];
            for(int i = 1; i < numOfVertices; i++)
            {
                if(smallest > array[i])
                {
                    smallest = array[i];
                }
            }
            return smallest;
        }
    
        double computeArea()
        {
            double area = 0.0;
            int numOfVertices = 12;
            int j = numOfVertices - 1;
            for(int i = 0; i < numOfVertices; i++)
            {
                area += (xArray[j] + xArray[i]) * (yArray[j]-yArray[i]);
                j=i;
            }

            area /=2;
            return area;
        }
    
        bool isPointInShape(int x, int y)
        {
            int min_x = min(xArray);
	    int minX_minY = 0;

	    int max_x = max(xArray);
	    int maxX_maxY = 0;

	    int min_y = min(yArray);
	    int minY_minX = 0;

	    int max_y = max(yArray);
	    int maxY_maxX = 0;

               	for(int i = 0; i < numOfVertices; i++)
   		{
	   		if(min_x == xArray[i] && minX_minY == 0)
	   		{
	   			minX_minY = yArray[i];
	   			maxX_maxY = yArray[i];
	   		}
	   		if(min_y == yArray[i] && minY_minX == 0)
	   		{
	   			minY_minX = xArray[i];
	   			maxY_maxX = xArray[i];
	   		}
	   		if(min_x == xArray[i] && minX_minY > yArray[i])
	   		{
	   			minX_minY = yArray[i];
	   		}
	   		else if(max_x == xArray[i] && minX_minY < yArray[i])
	   		{
	   			maxX_maxY = yArray[i];
	   		}

	   		if(min_y == yArray[i] && minY_minX > xArray[i])
	   		{
	   			minY_minX = xArray[i];
	   		}
	   		else if(max_y == yArray[i] && minY_minX < xArray[i])
	   		{
	   			maxY_maxX = xArray[i];
	   		}
   		}

	    if(
	    	((x > min_x && x < max_x ) && (y> minX_minY && y< maxX_maxY))
	  		||
	    	((y > minX_minY && y < maxX_maxY) && (x> min_x && x< max_x))
	    	||
	    	((y > min_y && y < max_y) && (x> minY_minX && x< maxY_maxX))
	    	||
	    	((x > minY_minX && x < maxY_maxX) && (y> min_y && y< max_y))

	    	)
	    {
		return true;
	    }
	    else
	    {
		return false;
	    }
        }
    
        bool isPointOnShape(int x, int y)
        {
            int min_x = min(xArray);
            int minX_minY = 0;

            int max_x = max(xArray);
            int maxX_maxY = 0;

            int min_y = min(yArray);
            int minY_minX = 0;

            int max_y = max(yArray);
            int maxY_maxX = 0;
            
            for(int i = 0; i < numOfVertices; i++)
            {
                if(min_x == xArray[i] && minX_minY == 0)
                {
                    minX_minY = yArray[i];
                    maxX_maxY = yArray[i];
                }

                if(min_y == yArray[i] && minY_minX == 0)
                {
                    minY_minX = xArray[i];
                    maxY_maxX = xArray[i];
                }

                if(min_x == xArray[i] && minX_minY > yArray[i])
                {
                    minX_minY = yArray[i];
                }
                else if(max_x == xArray[i] && minX_minY < yArray[i])
                {
                    maxX_maxY = yArray[i];
                }

                if(min_y == yArray[i] && minY_minX > xArray[i])
                {
                    minY_minX = xArray[i];
                }
                else if(max_y == yArray[i] && minY_minX < xArray[i])
                {
                    maxY_maxX = xArray[i];
                }
            }

            if(((y > minX_minY && y < maxX_maxY) && (x> min_x && x< max_x)) ||
                ((x > minY_minX && x < maxY_maxX) && (y> min_y && y< max_y)))
            {
                return false;
            }

            if(((x == min_x || x == max_x) && (y> minX_minY && y< maxX_maxY)) ||
                ((y == minX_minY || y == maxX_maxY) && (x> min_x && x< max_x)) ||
                ((y == min_y || y == max_y) && (x> minY_minX && x< maxY_maxX)) ||
                ((x == minY_minX || x == maxY_maxX) && (y> min_y && y< max_y)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    
        bool isCoordinate(int x, int y)
        {
            for(int i = 0; i < numOfVertices; i++)
            {
                if(x == xArray[i] && y == yArray[i])
                {
                    return true;
                }
            }
            return false;
        }
    
        void setName(string name)
        {
            this->name = name;
        }
    
        void setContainsWarpSpace(bool containsWarpSpace)
        {
            this->containsWarpSpace = containsWarpSpace;
        }
};

void inputSensorData(ShapeTwoD ** sd, int i)
{
    string shape, type;
    bool isWS = true;
        
    cout << "[ Input sensor data ]" << endl;
    cout << "Please enter your name of shape : ";
    cin >> shape;
    cout << "Please enter special type : ";
    cin >> type;
    cout << endl;
    
    if(type == "NS" || type == "ns")
    {
        isWS = false;
    }
    
    if(shape == "Circle" || shape == "circle")
    {
        int x, y, radius;
        
        cout << "Please enter x-ordinate of center : ";
        cin >> x;
        cout << "Please enter x-ordinate of center : ";
        cin >> y;
        cout << "Please enter radius (units) : ";
        cin >> radius;
        
        sd[i] = new Circle (shape, isWS, x, y ,radius, i);
    }
    
    else if(shape == "Square" || shape == "square")
    {
        int x1, x2, x3, x4, y1, y2, y3, y4;
        
        cout << "Please enter x_ordinate of pt.1 : ";
        cin >> x1;
        cout << "Please enter y_ordinate of pt.1 : ";
        cin >> y1;
        cout << "Please enter x_ordinate of pt.2 : ";
        cin >> x2;
        cout << "Please enter y_ordinate of pt.2 : ";
        cin >> y2;
        cout << "Please enter x_ordinate of pt.3 : ";
        cin >> x3;
        cout << "Please enter y_ordinate of pt.3 : ";
        cin >> y3;
        cout << "Please enter x_ordinate of pt.4 : ";
        cin >> x4;
        cout << "Please enter y_ordinate of pt.4 : ";
        cin >> y4;
        
        sd[i] = new Square(shape, isWS, x1, y1, x2, y2, x3, y3, x4, y4, i);
    }
    
    else if(shape == "Rectangle" || shape == "rectangle")
    {
        int x1, x2, x3, x4, y1, y2, y3, y4;
        
        cout << "Please enter x_ordinate of pt.1 : ";
        cin >> x1;
        cout << "Please enter y_ordinate of pt.1 : ";
        cin >> y1;
        cout << "Please enter x_ordinate of pt.2 : ";
        cin >> x2;
        cout << "Please enter y_ordinate of pt.2 : ";
        cin >> y2;
        cout << "Please enter x_ordinate of pt.3 : ";
        cin >> x3;
        cout << "Please enter y_ordinate of pt.3 : ";
        cin >> y3;
        cout << "Please enter x_ordinate of pt.4 : ";
        cin >> x4;
        cout << "Please enter y_ordinate of pt.4 : ";
        cin >> y4;
        
        sd[i] = new Rectangle(shape, isWS, x1, y1, x2, y2, x3, y3, x4, y4, i);
    }
    
    else if(shape == "Cross" || shape == "cross")
    {
        int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12;
        int y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12;
        
        cout << "Please enter x_ordinate of pt.1 : ";
        cin >> x1;
        cout << "Please enter y_ordinate of pt.1 : ";
        cin >> y1;
        cout << "Please enter x_ordinate of pt.2 : ";
        cin >> x2;
        cout << "Please enter y_ordinate of pt.2 : ";
        cin >> y2;
        cout << "Please enter x_ordinate of pt.3 : ";
        cin >> x3;
        cout << "Please enter y_ordinate of pt.3 : ";
        cin >> y3;
        cout << "Please enter x_ordinate of pt.4 : ";
        cin >> x4;
        cout << "Please enter y_ordinate of pt.4 : ";
        cin >> y4;
        cout << "Please enter x_ordinate of pt.5 : ";
        cin >> x5;
        cout << "Please enter y_ordinate of pt.5 : ";
        cin >> y5;
        cout << "Please enter x_ordinate of pt.6 : ";
        cin >> x6;
        cout << "Please enter y_ordinate of pt.6 : ";
        cin >> y6;
        cout << "Please enter x_ordinate of pt.7 : ";
        cin >> x7;
        cout << "Please enter y_ordinate of pt.7 : ";
        cin >> y7;
        cout << "Please enter x_ordinate of pt.8 : ";
        cin >> x8;
        cout << "Please enter y_ordinate of pt.8 : ";
        cin >> y8;
        cout << "Please enter x_ordinate of pt.9 : ";
        cin >> x9;
        cout << "Please enter y_ordinate of pt.9 : ";
        cin >> y9;
        cout << "Please enter x_ordinate of pt.10 : ";
        cin >> x10;
        cout << "Please enter y_ordinate of pt.10 : ";
        cin >> y10;
        cout << "Please enter x_ordinate of pt.11 : ";
        cin >> x11;
        cout << "Please enter y_ordinate of pt.11 : ";
        cin >> y11;
        cout << "Please enter x_ordinate of pt.12 : ";
        cin >> x12;
        cout << "Please enter y_ordinate of pt.12 : ";
        cin >> y12;
        
        sd[i] = new Cross(shape, isWS, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10, x11, y11, x12, y12, i);
    }

    cout << endl;
    cout << "Record successfully stored. Going back to main menu..." << endl;
    cout << endl;
}

void computeArea(int i, ShapeTwoD** array)
{
    for(int j = 0; j < i; j++)
    {
        if(array[j]->computeArea() != 0)
        {
            cout << "Compute completed! ( " << i << " records were updated )" << endl;
        }
        
    }
    cout << endl;
}

void printShapeReport(int i, ShapeTwoD** array)
{
    cout << "Total no. of records available = " << i << endl;
    
    for(int j = 0; j < i; j++)
    {
        cout << array[j]->toString();
    }
}

int mainpage()
{
    int a;
    cout << "Student ID     : 6573678" << endl;
    cout << "Student Name   : Gyu Hyun Lim" << endl;
    cout << "-----------------------------" << endl;
    cout << "Welcome to Assn2 program!" << endl;
    cout << endl;
    cout << "1)\t Input sensor data" << endl;
    cout << "2)\t Compute area (for all records)" << endl;
    cout << "3)\t Print shapes report" << endl;
    cout << "4)\t Sort shape data" << endl;
    cout << endl;
    cout << "Please enter your choice : ";
    cin >> a;
    cout << endl;
    
    return a;
}

void sortShapesData(int num, ShapeTwoD** array)
{
    string ki;
    cout << "a)\t Sort by area (ascending)" << endl;
    cout << "b)\t Sort by area (descending)" << endl;
    cout << "c)\t Sort by special type and area" << endl;
    cout << endl;
    
    cout << "Please select sort option ('q' to go main menu): ";
    cin >> ki;
    cout << endl;
    
    if(ki == "a")
    {
        cout << "Sort by area (smallest to largest)..." << endl;
        cout << endl;
	
	for(int j = 0; j < num; j++)
	{
	   for(int k = j+1; k < num; k++)
	   {
		if((array[j]->computeArea()) > (array[k]->computeArea()))
		{
		     ShapeTwoD* temp = array[j];
		     array[j] = array[k];
		     array[k] = temp;
		}
	    }
	}
            
        printShapeReport(num, array);
    }
    
    else if(ki == "b")
    {
        cout << "Sort by area (largest to smallest)..." << endl;
        cout << endl;

        for(int j=0; j<num-1; j++)
        {
            for(int k=j+1; k<num; k++)
            {
                if(array[j]->computeArea() < array[k]->computeArea()  )
                {
                    ShapeTwoD* temptr = array[j];
                    array[j] = array[k];
                    array[k] = temptr;
                }
            }
        }
        printShapeReport(num, array);
    }
    
    else if (ki == "c")
    {
	for(int j = 0; j < num; j++)
	{
	   for(int k = j+1; k < num; k++)
	   {
		if((array[j]->computeArea()) > (array[k]->computeArea()))
		{
		     ShapeTwoD* temp = array[j];
		     array[j] = array[k];
		     array[k] = temp;
		}
	    }
	}
	
        for(int i = 0; i < num; i ++)
        {
            if(array[i]->getContainsWarpSpace() == true)
            {
                cout << array[i]->toString() << endl;
                cout << endl;
            }
        }

        for(int i = 0; i < num; i ++)
        {
            if(array[i]->getContainsWarpSpace() == false)
            {
                cout << array[i]->toString() << endl;
                cout << endl;
            }
        }
    }
    
    else if (ki == "q")
    {
        mainpage();
    }
}

int main()
{
    int option;
    ShapeTwoD** array = new ShapeTwoD*[100];
    int i = 0;
    do
    {
        option = mainpage();
        
        if(option == 1)
        {
            inputSensorData(array, i);
            i++;
        }
        
        if(option == 2)
        {
            computeArea(i, array);
        }
        
        else if(option == 3)
        {
            printShapeReport(i, array);
        }
        
        else if(option == 4)
        {
            sortShapesData(i, array);
        }
    }while(option < 5);
    
    return 0;
}



