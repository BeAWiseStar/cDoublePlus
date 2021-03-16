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
using namespace std;

struct City
{
    vector <string> a;
    bool printed;
};

struct Cloud
{
    vector<string> b;
};

struct Pressure
{
    vector<string> c;
};

struct rawData
{
    int gridX_Idx_Range;
    int gridY_Idx_Range;
    
    City *city_location;
    int numberOfCities;

    Cloud *cloud_data;
    int numberOfCloud;

    Pressure *pressure_data;
    int numberOfPressure;
};

int getValue(int num)
{
    if(num >= 0 && num < 10)
    {
        return 0;
    }
    else if(num >= 10 && num < 20)
    {
        return 1;
    }
    else if(num >= 20 && num < 30)
    {
        return 2;
    }
    else if(num >= 30 && num < 40)
    {
        return 3;
    }
    else if(num >= 40 && num < 50)
    {
        return 4;
    }
    else if(num >= 50 && num < 60)
    {
        return 5;
    }
    else if(num >= 60 && num < 70)
    {
        return 6;
    }
    else if(num >= 70 && num < 80)
    {
        return 7;
    }
    else if(num >= 80 && num < 90)
    {
        return 8;
    }
    else
    {
        return 9;
    }
}

char getLMH (int num)
{
    if(num >= 0 && num < 35)
    {
        return 'L';
    }
    else if(num >= 35 && num < 65 )
    {
        return 'M';
    }
    else
    {
        return 'H';
    }
}

int getProbability(char avg1, char avg2)
{
    if(avg1 == 'L' && avg2 == 'H')
    {
        return 90;
    }
    else if(avg1 == 'L' && avg2 == 'M')
    {
        return 80;
    }
    else if(avg1 == 'L' && avg2 == 'L')
    {
        return 70;
    }
    else if(avg1 == 'M' && avg2 == 'H')
    {
        return 60;
    }
    else if(avg1 == 'M' && avg2 == 'M')
    {
        return 50;
    }
    else if(avg1 == 'M' && avg2 == 'L')
    {
        return 40;
    }
    else if(avg1 == 'H' && avg2 == 'H')
    {
        return 30;
    }
    else if(avg1 == 'H' && avg2 == 'M')
    {
        return 20;
    }
    else
    {
        return 10;
    }
}

void getCoordinates(string str, int& x, int& y)
{
    istringstream iss(str);
    char c;
    
    iss >> c >> x >> c >> y >> c;
}

float getAverageCloud(string city_name, rawData d)
{
    int counter = 0;
    int sum = 0;
    float result = 0;
    int min_x = 1, min_y = 1;
    int max_x = 0, max_y = 0;
    bool found = false;
    
    int x_coordinates = 0, y_coordinates = 0;
    
    for(int i = 0; i < d.numberOfCities + 1; i++)
    {
        getCoordinates(d.city_location[i].a[0], x_coordinates, y_coordinates);

        if(find(d.city_location[i].a.begin(), d.city_location[i].a.end(), city_name) != d.city_location[i].a.end())
        {
            if(found == false)
            {
                max_x = x_coordinates;
                min_x = x_coordinates;
                min_y = y_coordinates;
                max_y = y_coordinates;
                found = true;
            }
          
            else
            {
                if(max_x <= x_coordinates)
                {
                    max_x = x_coordinates;
                }
              
                if(min_x >= x_coordinates)
                {
                    min_x = x_coordinates;
                }
              
                if(min_y >= y_coordinates)
                {
                    min_y = y_coordinates;
                }
              
                if(max_y <= y_coordinates)
                {
                    max_y = y_coordinates;
                }
            }
        }
    }

    int new_min_x = min_x - 1;
    int new_min_y = min_y - 1;
    int new_max_x = max_x + 1;
    int new_max_y = max_y + 1;
    
    for(int j = 0; j < d.numberOfCloud; j++)
    {
        getCoordinates(d.cloud_data[j].b[0], x_coordinates, y_coordinates);

        if((x_coordinates >= new_min_x && x_coordinates <= new_max_x)
            &&(y_coordinates>= new_min_y && y_coordinates <= new_max_y))
        {
            sum+= stoi(d.cloud_data[j].b[1]);
            counter++;
        }
    }
    
    if(sum != 0 || counter != 0)
        result = double(sum) / double(counter);

    return result;
}

float getAveragePressure(string city_name, rawData d)
{
    int counter = 0;
    int sum = 0;
    float result = 0;
    int min_x = 1, min_y = 1, max_x = 0, max_y = 0;
    bool found = false;
    int x_coordinates = 0, y_coordinates = 0;

    for(int i = 0; i < d.numberOfCities + 1; i++)
    {
        if(find(d.city_location[i].a.begin(), d.city_location[i].a.end(), city_name) != d.city_location[i].a.end())
        {
            getCoordinates(d.city_location[i].a[0], x_coordinates, y_coordinates);

            if(found == false)
            {
                max_x = x_coordinates;
                min_x = x_coordinates;
                min_y = y_coordinates;
                max_y = y_coordinates;
                found = true;
            }
            else
            {
                if(max_x <= x_coordinates)
                {
                    max_x = x_coordinates;
                }
                
                if(min_x >= x_coordinates)
                {
                    min_x = x_coordinates;
                }
                
                if(min_y >= y_coordinates)
                {
                    min_y = y_coordinates;
                }
            
                if(max_y <= y_coordinates)
                {
                    max_y = y_coordinates;
                }
            }
        }
    }
    
    int new_min_x = min_x - 1;
    int new_min_y = min_y - 1;
    int new_max_x = max_x + 1;
    int new_max_y = max_y + 1;

    for(int j = 0; j < d.numberOfPressure; j++)
    {
        getCoordinates(d.pressure_data[j].c[0], x_coordinates, y_coordinates);
        if((x_coordinates >= new_min_x && x_coordinates <= new_max_x)
           &&(y_coordinates >= new_min_y && y_coordinates <= new_max_y))
        {
            sum += stoi(d.pressure_data[j].c[1]);
            counter++;
        }
    }

    if(sum != 0 || counter != 0)
    	result = double(sum) / double(counter);
    
    return result;
}

void showGraphics(float prob)
{
    int value = int(prob) / 10;
	
    if(value < 4)
    {
        for(int i = 1; i <= value; i ++)
        {
            cout << "~";
        }
        cout << endl;

        for(int i = 1; i <= value + 1; i++)
        {
            cout << "~";
        }
        cout << endl;
    }
    else
    {
        for(int i = 1; i <= 4; i ++)
        {
            cout << "~";
        }
        cout << endl;

        for(int i = 1; i <= 5; i ++)
        {
            cout << "~";
        }
        cout << endl;

        for(int i = 1; i <= value - 4; i++)
        {
            for(int j = 1; j <= 5 - (value - 4); j++)
            {
                cout << " ";
            }
            cout << "\\";
        }
        cout << endl;
    }
}

void toString(string city_name, int id, rawData d)
{
    float cloudAvg = getAverageCloud(city_name, d);
    float pressureAvg = getAveragePressure(city_name, d);
    float prob = getProbability(getLMH(pressureAvg), getLMH(cloudAvg));

    cout << "City Name    : " << city_name << endl;
    cout << "City ID      : " << id << endl;
    cout << "Ave. Cloud cover (ACC)     : " << fixed << setprecision(2) << cloudAvg << " (" <<  getLMH(cloudAvg) << ") " << endl;
    cout << "Ave. Pressure    (AP)      : " << fixed << setprecision(2) << pressureAvg << " (" <<  getLMH(pressureAvg) << ") " << endl;
    cout << "Probability of Rain (%)    : " << fixed << setprecision(2) << int(prob) << endl;

    showGraphics(prob);
}

vector <string> tokenizeString (string input, string delimiter)
{
    size_t pos = 0;
    string token;
    
    vector <string> result;
    
    while ((pos = input.find(delimiter)) != string::npos)
    {
        token = input.substr(0, pos);
        result.push_back (token);
        input.erase(0, pos + delimiter.length());
    }
    
    result.push_back (input);
    
    return (result);
}

void readAFile (string filename, rawData& d)
{
    fstream inputFile (filename.c_str(), fstream::in);
    string aLine;
    int counter = 0;
    
    if((filename.compare("citylocation.txt")) == 0)
    {
        d.city_location = new City[(d.gridX_Idx_Range + 1) * (d.gridY_Idx_Range + 1)];
        
        while(getline (inputFile, aLine))
        {
            d.city_location[counter].a = tokenizeString(aLine, "-");
            d.city_location[counter].printed = false;

            counter++;
        }
        d.numberOfCities = --counter;
    }
    
    else if((filename.compare("cloudcover.txt")) == 0)
    {
        d.cloud_data = new Cloud[(d.gridX_Idx_Range + 1) * (d.gridY_Idx_Range+1)];
        
        while(getline (inputFile, aLine))
        {
            d.cloud_data[counter].b = tokenizeString(aLine, "-");
            counter++;
        }
        d.numberOfCloud = --counter;
    }
    
    else if((filename.compare("pressure.txt")) == 0)
    {
        d.pressure_data = new Pressure[(d.gridX_Idx_Range + 1) * (d.gridY_Idx_Range + 1)];
        
        while(getline (inputFile, aLine))
        {
            d.pressure_data[counter].c = tokenizeString(aLine, "-");
            counter++;
        }
        d.numberOfPressure = --counter;
    }
    cout << filename << " ... done!" << endl;
}

int mainPage()
{
    int option = 0;
    cout << "Student ID\t: 6573678" << endl;
    cout << "Student Name\t: Gyu Hyun Lim" << endl;
    cout << "------------------------------" << endl;
    cout << "Welcome to Weather Information Processing System!" << endl;
    cout << endl;
    
    cout << "1) Read in and process a configuration file " << endl;
    cout << "2) Display city map " << endl;
    cout << "3) Display cloud coverage map (cloudliness index)" << endl;
    cout << "4) Display cloud coverage map (LMH symbols) " << endl;
    cout << "5) Display atmospheric pressure map (pressure index) " << endl;
    cout << "6) Display atmospheric pressure map (LMH symbols) " << endl;
    cout << "7) Show weather forecast summary report " << endl;
    cout << "8) Quit" << endl;
    cout << endl;
    
    do
    {
        try
        {
            cout << "Please enter your choice: ";
            cin >> option;
            
            if(!cin)
            {
                throw exception();
            }
        }
        catch (exception e)
        {
            cout << "Option entered is invalid. " << endl;
            cin.clear();
            cin.ignore();
        }
    }while(option <= 0 && option > 8);
    cout << endl;
    
    return option;
}

void fileReading (rawData& d)
{
    string fileName;
    bool error = true;
    ifstream infile;
    
    cout << "[ Read in and process a configuration file ]" << endl;
    
    do
    {
        try
        {
            cout << "Please enter config filename: ";
            cin >> fileName;
            cout << endl;
          
            infile.open (fileName);
            if(!infile)
            {
                cout << "File opening is unsuccessfull. Please enter again." << endl;
                throw exception();
            }
        }
        catch (char e)
        {
            cout << "Option entered is invalid." << endl;
            error = false;
        }
    }while(error == false);
    
        string aLine;
        bool found = false;
    
        while(getline(infile, aLine))
        {
            vector<string> tokens;
            size_t pos = aLine.find("X_IdxRange");
        
            if(pos!=string::npos)
            {
                tokens = tokenizeString(aLine, "-");
                d.gridX_Idx_Range = stoi(tokens[1]);

                tokens = tokenizeString(aLine, "=");
            
                cout << "Reading in " << tokens[0] << " : " << "0-" << d.gridX_Idx_Range << " ... done!" << endl;
            }
        
            pos = aLine.find("Y_IdxRange");
        
            if(pos!=string::npos)
            {
                tokens = tokenizeString(aLine, "-");
                d.gridY_Idx_Range = stoi(tokens[1]);

                tokens = tokenizeString(aLine, "=");

            	cout << "Reading in " << tokens[0] << " : " << "0-" << d.gridY_Idx_Range << " ... done!" << endl;
            	cout << endl;
            }

            pos = aLine.find(".txt");
        
            if(pos!=string::npos)
            {
                if(found == false)
                {
                    cout << "Storing data from input file: " << endl;
                    found = true;
                }

                readAFile(aLine, d);
            }
        }
    
    infile.close();
    cout << endl;
    cout << "All records successfully stored. Going back to the main menu..." << endl;
    cout << endl;
}

void displayMap(rawData& d, int option)
{
    int x = d.gridX_Idx_Range;
    int y = d.gridY_Idx_Range;
    int map_x = x+3;
    int map_y = y+3;
    int temp_y = y;
    int x_coordinates = 0, y_coordinates = 0;
  
    for(int i = 0; i <= map_y; i++)
    {
        if(i == 0 || i == y+2)
        {
            cout << "   ";
            for(int j = 1; j <= x + 2; j++)
            {
                cout << " # ";
            }
            cout << " #"<< endl;
        }
        
        else if(i == y+3)
        {
            cout << "      ";
            for(int j = 0; j <= x; j++)
            {
                cout << " " << j << " ";
            }
            cout << endl;
        }
        
        else
        {
            for(int k = 0; k <=map_x; k++)
            {
                bool check = false;
                  
                if(k==0)
                {
                    cout << " " << temp_y-- << " ";
                }
                else if(k==1 || k==x+3)
                {
                    cout << " # ";
                }
                
                else
                {
                    switch(option)
                    {
                        case 2:
                                for(int loop = 0; loop <= d.numberOfCities; loop++)
                                {
                                    getCoordinates(d.city_location[loop].a[0], x_coordinates, y_coordinates);
                                    if(i == (map_y-2-y_coordinates) && k == (x_coordinates+2))
                                    {
                                        cout << " " << d.city_location[loop].a[1] << " ";
                                        check = true;
                                    }
                                }
                                break;

                        case 3:
                                for(int loop = 0; loop <= d.numberOfCloud; loop++)
                                {
                                    getCoordinates(d.cloud_data[loop].b[0], x_coordinates, y_coordinates);
                                    if( i == (map_y-2-( y_coordinates)) && k == ((x_coordinates)+2) )
                                    {
                                        cout << " " <<  getValue(stoi(d.cloud_data[loop].b[1]))<< " ";
                                        check = true;
                                    }
                                }
                                break;

                        case 4:
                                for(int loop = 0; loop <= d.numberOfCloud; loop++)
                                {
                                    getCoordinates(d.cloud_data[loop].b[0], x_coordinates, y_coordinates);
                                    if( i == (map_y-2-(y_coordinates)) && k == ((x_coordinates)+2) )
                                    {
                                        cout << " " <<  getLMH(stoi(d.cloud_data[loop].b[1]))<< " ";
                                        check = true;
                                    }
                                }
                                break;

                        case 5:
                                for(int loop = 0; loop <= d.numberOfPressure; loop++)
                                {
                                    getCoordinates(d.pressure_data[loop].c[0], x_coordinates, y_coordinates);
                                    if( i == (map_y-2-(y_coordinates)) && k == ((x_coordinates)+2) )
                                    {
                                        cout << " " <<  getValue(stoi(d.pressure_data[loop].c[1]))<< " ";
                                        check = true;
                                    }
                                }
                                break;

                        case 6:
                                for(int loop = 0; loop <= d.numberOfPressure; loop++)
                                {
                                    getCoordinates(d.pressure_data[loop].c[0], x_coordinates, y_coordinates);
                                    if( i == (map_y-2-(y_coordinates)) && k == ((x_coordinates)+2) )
                                    {
                                        cout << " " <<  getLMH(stoi(d.pressure_data[loop].c[1]))<< " ";
                                        check = true;
                                    }
                                }
                                break;
                                    
                        default:
                                break;
                    }
                            
                    if(check == false)
                    {
                        cout << "   ";
                    }
                }
            }
            cout << endl;
        }
    }
}

void safelyDeallocateMemory (rawData& d)
{
    delete [] d.city_location;
    d.city_location = nullptr;

    delete [] d.cloud_data;
    d.cloud_data = nullptr;

    delete [] d.pressure_data;
    d.pressure_data = nullptr;
}

void printAll(rawData& d)
{
    cout << "Weather Forecast Summary Report" << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    
    int size = d.numberOfCities + 1;
    string curCity = "";

    for(int i = 0; i < size; i ++)
    {
        curCity = d.city_location[i].a[2];
	
        if(d.city_location[i].printed == false)
        {
            toString(curCity, stoi(d.city_location[i].a[1]), d);
        }

        for(int j = i; j < size; j++)
        {
            if(find(d.city_location[j].a.begin(), d.city_location[j].a.end(), curCity) != d.city_location[j].a.end())
            {
                d.city_location[j].printed = true;
            }
	}
	    
        d.city_location[i].printed = false;
    }
}

int main()
{
    rawData d;
    int option;
    
    do
    {
        option = mainPage();

        switch(option)
        {
            case 1: fileReading(d);
                break;
            case 2: displayMap(d, option);
                break;
            case 3: displayMap(d, option);
                break;
            case 4: displayMap(d, option);
                break;
            case 5: displayMap(d, option);
                break;
            case 6: displayMap(d, option);
                break;
            case 7: printAll(d);
                break;
            case 8: cout << "Please press <ENTER> to exit the program" << endl;
                    cin.ignore();
                    cin.get();
                break;
            default:
                    cout << "Please enter a valid option. " << endl;
                break;
        }
       
        if(option !=8)
        {
            cout << "Press <enter> to go back to main menu..." << endl;
                cin.clear();
                cin.ignore();
                cin.get();
        }
        cout << endl;
    }while(option != 8);

    safelyDeallocateMemory(d);
    
    return 0;
}

