#include <Arduino.h>

class Building {
  private:
    String name;
    int position;
    int pattern;
    int fireValue;
    int targetValue;

  public:
    Building()
    {
      name = "newName";
      position = -1;
      pattern = 0;
      int fireValue = random(50, 256);
      int targetValue = random(50, 256);
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

    void SetRandomTarget()
    {
      targetValue = random(50, 256);
    }

    void SetTarget(int target)
    {
      targetValue = target;
    }

    int GetTargetValue()
    {
      return targetValue;
    }

    void SetFireValue(int value)
    {
      fireValue = value;
    }
    
    int GetFireValue()
    {
      return fireValue;
    }

};