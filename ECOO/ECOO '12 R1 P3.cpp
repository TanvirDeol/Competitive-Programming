#include <bits/stdc++.h>
using namespace std;
#define DtoR(angleDegrees) ((angleDegrees) * 3.141592653589793238463 / 180.0)
#define RtoD(angleRadians) ((angleRadians) * 180.0 / 3.141592653589793238463)

int main()
{
    for (int i = 0; i < 5; i++) {
        double x = 0, y = 0;
        cin >> x >> y;
        pair<double, double> giveC = make_pair(x, y);
        double len = 0; double theta = 0;

        len = sqrt(pow(abs(giveC.first), 2.0) + pow(abs(giveC.second), 2.0));
        theta = atan(giveC.second / giveC.first) * (180.0 / 3.141592653589793238463);

        if (giveC.first < 0) {
            theta += 180;
        }

        theta -= 60;
        double secX = 0, secY = 0;
        secY = sin(DtoR(theta));
        secY *= len;
        secX = cos(DtoR(theta));
        secX *= len;
        pair<double, double> secC = make_pair(secX, secY);

        double thrX = 0, thrY = 0;
        thrX = secX * (-1.0);
        thrY = secY * (-1.0);

        double finX = 0, finY = 0;
        theta += 90;
        double finLen = sqrt(pow(len * 2, 2.0) - pow(len, 2.0));
        finY = sin(DtoR(theta)) * finLen;
        finX = cos(DtoR(theta)) * finLen;

        printf("%s%.1lf%s%.1lf%s", "(", thrX, ",", thrY, ") ");
        printf("%s%.1lf%s%.1lf%s", "(", secX, ",", secY, ") ");
        printf("%s%.1lf%s%.1lf%s", "(", finX, ",", finY, ")");
        cout << endl;


    }
    return 0;
}