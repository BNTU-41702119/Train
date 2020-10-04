#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

class RailwayCarriage
{
    string type;

public:
    RailwayCarriage(string type)
    {
        this->type = type;
    }

public:
    string getType()
    {
        return type;
    }
};

void handleHandInput(stack <RailwayCarriage>* railwayCarriages, int count)
{
    for (int index = 0; index < count; index++)
    {
        string type;
        cout << "Enter Railway Carriage type: ";
        cin >> type;

        RailwayCarriage railwayCarriage = RailwayCarriage(type);
        railwayCarriages->push(railwayCarriage);
    }
}

void handleFileInput(stack <RailwayCarriage>* railwayCarriages, string filePath)
{
    ifstream inFile;
    inFile.open(filePath);

    if (inFile) {
        cout << "Reading from the file" << endl;

        string type;
        int index = 0;
        while (inFile >> type) {
            RailwayCarriage railwayCarriage = RailwayCarriage(type);
            railwayCarriages->push(railwayCarriage);
        }
    }
    else
    {
        cout << "No such group" << endl;
        system("pause");
    }

    inFile.close();
}

void generateRailwayCarriages(stack <RailwayCarriage>* railwayCarriages)
{
    handleFileInput(railwayCarriages, "railwayCarriages.txt");
    handleHandInput(railwayCarriages, 4);
}

void divideRailwayCarriagesByType(
    stack <RailwayCarriage>* railwayCarriages,
    stack <RailwayCarriage>* typeOneRailwayCarriages,
    stack <RailwayCarriage>* otherRailwayCarriages)
{
    while (!railwayCarriages->empty())
    {
        RailwayCarriage railwayCarriage = railwayCarriages->top();
        if (railwayCarriage.getType() == "type1")
        {
            typeOneRailwayCarriages->push(railwayCarriage);
        } 
        else
        {
            otherRailwayCarriages->push(railwayCarriage);
        }
        railwayCarriages->pop();
    }
}

int main()
{
    stack <RailwayCarriage> railwayCarriages;
    generateRailwayCarriages(&railwayCarriages);

    cout << railwayCarriages.size() << endl;

    stack <RailwayCarriage> typeOneRailwayCarriages;
    stack <RailwayCarriage> otherRailwayCarriages;
    divideRailwayCarriagesByType(&railwayCarriages, &typeOneRailwayCarriages, &otherRailwayCarriages);

    cout << railwayCarriages.size() << endl;
    cout << typeOneRailwayCarriages.size() << endl;
    cout << otherRailwayCarriages.size() << endl;
}
