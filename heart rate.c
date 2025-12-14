#include <iostream>
class Device;
class DeviceFriend 
{
public:
static void func(const Device& device);
};
class Device {
friend class DeviceFriend;
private:
int age;
int RHR;
public:
Device(int _age, int _RHR) : age(_age), RHR(_RHR) {} };
void DeviceFriend::func(const Device& device) 
{
  int MHR = 220 - device.age; 
  int RHR_sleep = 0.9 * device.RHR; 
  std::cout << "MHR: " << MHR << " bpm\n"; 
  std::cout << "RHR_sleep: " << RHR_sleep << " bpm\n"; 
}
int main() 
{ 
  int age, RHR; 
  std::cin >> age >> RHR;
  if (age < 15 || age > 80 || RHR < 60 || RHR > 300) 
  { 
    std::cerr << "Invalid input!\n"; 
    return 1;
    } 
  Device device(age, RHR); 
  DeviceFriend::func(device); 
  return 0; 
}
