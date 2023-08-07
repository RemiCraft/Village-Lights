#include <Arduino.h>

class Building {
  private:
    String name;
    int position;
    int pattern;

  public:

    Building()
    {
      name = "newName";
      position = 0;
      pattern = 0;
    }

    Building(String newName, int newPosition, int newPattern)
    {
      name = newName;
      position = newPosition;
      pattern = newPattern;
    }

    void SetName(String newName)
    {
      name = newName;
    }

    String GetName()
    {
      return name;
    }

    void SetPosition(int newPosition)
    {
      position = newPosition;
    }

    int GetPosition()
    {
      return position;
    }

    void SetPattern(int newPattern)
    {
      pattern = newPattern;
    }

    int GetPattern()
    {
      return pattern;
    }

};