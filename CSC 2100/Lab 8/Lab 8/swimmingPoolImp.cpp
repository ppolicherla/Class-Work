#include "SwimmingPool.h"
using namespace std;

void swimmingPool::fillTime()
{
	double amount;
	amount = (length*width*depth) / 7.48;
	cout << "The amount of water to fill the pool is: " << amount << endl;
}

swimmingPool::swimmingPool(int longs, int wide, int deep, int speed)
{
	length = longs;
	width = wide;
	depth = deep;
	rate = speed;

}
