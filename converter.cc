#include <iostream>
#include <vector>


class SingletonConverter
{
   public:
       static SingletonConverter* getInstance( ) {
            static SingletonConverter* instance;
            return instance;
       
       };
       ~SingletonConverter( );
        float fromFtoC(float temp) {
            return ((temp-32)/1.8);
        };
   private:
       SingletonConverter( );
       
};

int main()
{

  std::vector<float> allTemps;

  while(1) {

      std::string temp;
      std::cout << "Please enter a temperature or x to stop entering temperatures.\n";
      std::cin >> temp;
      
      if (temp == "x") {
          break;
      }
      
      std::cout << "Stored " << temp << "!\n";

      allTemps.push_back(std::stof(temp));
      
  }

  std::cout << allTemps.size() << " temperatures stored!\n";

  float averageTemp = 0;
  for (int i=0; i<allTemps.size(); i++) {
    averageTemp += allTemps[i];
  }

  averageTemp /= allTemps.size();

  std::cout << "The average temperature is: " << averageTemp << "\n";

  std::cout << "Converted to Celsius, this temperature is " << SingletonConverter::getInstance()->fromFtoC(averageTemp) << "!\n";
  
}


