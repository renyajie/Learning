#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1;
    
    double sum = 0;
    while(cin >> x1 >> y1 >> x2 >> y2)
    {
        double dx = x1 - x2, dy = y1 - y2;
        sum += sqrt(dx * dx + dy * dy) * 2;
    }
    
    int minutes = round(sum / 1000 / 20 * 60);
    int hours = minutes / 60;
    minutes %= 60;
    
    printf("%d:%02d\n", hours, minutes);
    
    return 0;
}
