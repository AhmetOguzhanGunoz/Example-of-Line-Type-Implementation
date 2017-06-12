#include <iostream>
#include <iomanip>
#include "lineType.h"

using namespace std;

int main()
{
	lineType line1(2,3,4),line2(3,5,7),line3(2,3,-2),line4(3,-2,1),line5(2,0,3),line6(0,-1,2),line7(4,6,8),line8;

	cout << "line1: " << line1 << endl;
	cout << "The slope of line1: " << line1.slope() << endl;

	cout << "line2: " << line2 << endl;
	cout << "line3: " << line3 << endl; 
	cout << "line4: " << line4 << endl;
	cout << "line5: " << line5 << endl;
	cout << "line6: " << line6 << endl;
	cout << "line7: " << line7 << endl;

	if(line1 || line2)
		cout << "line1 and line2 are parallel" << endl;
	else
		cout << "line1 and line2 are not parallel" << endl;
	line1.pointOfIntersection(line2);

	if(line1 || line3)
		cout << "line1 and line3 are parallel" << endl;
	else
		cout <<"line 1 and line3 are not parallel" << endl;

	if(line1 && line4)
		cout << "line1 and line4 are perpendicular" << endl;
	else
		cout << "line1 and line4 are not perpendicular" << endl;

	if(+(line5))
		cout << "line5 is a vertical line" << endl;
	if(-(line6))
		cout << "line6 is a horizontal line" << endl;

	line5.pointOfIntersection(line6);

	if(line1 == line7)
		cout << "line1 and line7 are equal" << endl;

	line1.pointOfIntersection(line7);

	cout << "Input line8 in the form(a,b,c: (";
	cin >> line8;

	cout << line8 << endl;

	if(line1 || line8)
		cout << "line1 and line8 are parallel" << endl;
	else
		cout << "line1 and line8 are not parallel" << endl;


	system("pause");

	return 0;
}