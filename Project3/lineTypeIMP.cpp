#include <iostream>
#include <iomanip>
#include "lineType.h"

using namespace std;

ostream& operator<<(ostream& osObject, const lineType& lineOut)
{
	if (lineOut.xCoeff == 0)
	{
		if(lineOut.yCoeff < 0)
		{
			osObject << '-' << setw(2) << -lineOut.yCoeff << 'y';
			osObject << setw(2) << '=' << setw(2) << lineOut.constTerm;
		}
		else if(lineOut.yCoeff > 0)
		{
			osObject << setw(2) << '+' << setw(2) << lineOut.yCoeff << 'y';
			osObject << setw(2) << '=' << setw(2) << lineOut.constTerm;
		}
		else
			cout << "There is no line " << endl;
	}
	
	else if(lineOut.yCoeff == 0)
	{
		if(lineOut.xCoeff < 0)
		{
			osObject << '-' << setw(2) << -lineOut.xCoeff << 'x';
			osObject << setw(2) << '=' << setw(2) << lineOut.constTerm;
		}
		else if(lineOut.xCoeff > 0)
		{
			osObject << '+' << setw(2) << lineOut.xCoeff << 'x';
			osObject << setw(2)  << '=' << setw(2) << lineOut.constTerm;
		}
		else
			cout << "There is no line " << endl;
	}
	else
	{
		if(lineOut.xCoeff < 0)
		{
			osObject  << '-' << -lineOut.xCoeff << 'x';
			if(lineOut.yCoeff < 0)
			{
				osObject << '-' << -lineOut.yCoeff << 'y';
				osObject << '=' << lineOut.constTerm;
			}
			else
			{
				osObject << '+' << lineOut.yCoeff << 'y';
				osObject << '=' << lineOut.constTerm;
			}
		}
		if(lineOut.xCoeff > 0)
		{
			osObject << lineOut.xCoeff << 'x' << setw(2);
			if(lineOut.yCoeff < 0)
			{
				osObject << '-' << setw(2) << -lineOut.yCoeff << 'y';
				osObject << setw(2) << '=' << setw(2) << lineOut.constTerm;
			}
			else
			{
				osObject << '+' << setw(2) << lineOut.yCoeff << 'y';
				osObject << setw(2) << '=' << setw(3) << lineOut.constTerm;
			}
		}
	}

	return osObject;  //return the ostream object
}

istream& operator>>(istream& is, lineType& lineIn)
{
	char ch;

	is >> lineIn.xCoeff;

	is.get(ch);

	is >> lineIn.yCoeff;

	is.get(ch);

	is >> lineIn.constTerm;

	return is;

}

const lineType& lineType::operator=(const lineType& line)
{
	this->xCoeff = line.xCoeff;
	this->yCoeff = line.yCoeff;
	this->constTerm = line.constTerm;

	return *this;
}

void lineType::setLine(double a, double b, double c)
{
	xCoeff = a;
	yCoeff = b;
	constTerm = c;
}

double lineType::getXCoefficient() const
{
	return xCoeff;
}

double lineType::getYCoefficient() const
{
	return yCoeff;
}

double lineType::getCOnstantTerm() const
{
	return constTerm;
}

void lineType::setXCoefficient(double coeff)
{
	xCoeff = coeff;
}

void lineType::setYCoefficient(double coeff)
{
	yCoeff = coeff;
}

void lineType::setConstantTerm(double c)
{
	constTerm = c;
}

bool lineType::operator+() const
{
	return (this->yCoeff == 0);
}
 
bool lineType::operator-() const
{
	return (this->xCoeff == 0);
}

bool lineType::operator==(const lineType& otherLine) const
{
	return ( ((this->constTerm / this->xCoeff) == (otherLine.constTerm / otherLine.xCoeff)) && ((this->constTerm / this->yCoeff) == (otherLine.constTerm / otherLine.yCoeff)) );
}
bool lineType::operator||(const lineType& otherLine) const
{
	if (yCoeff == 0 && otherLine.yCoeff == 0)
        return true;
    else if ((yCoeff != 0 && otherLine.yCoeff == 0)
              || (yCoeff == 0 && otherLine.yCoeff != 0))
        return false;
    else if ((xCoeff / yCoeff) == (otherLine.xCoeff / otherLine.yCoeff))
        return true;
    else
        return false;
}

bool lineType::operator&&(const lineType& otherLine) const
{
	return ( (this->slope() * otherLine.slope() == -1) );
}

double lineType::slope() const
{
	double slope;

	slope = - xCoeff / yCoeff;

	return slope;
}

void lineType::pointOfIntersection(lineType otherLine)
{
	if(*this == otherLine)
	{
		cout << "Both lines are equal. They have infinite points of intersections." << endl;
	}
	else if(*this || otherLine)
	{
		cout << "There is no point of intersection" << endl;
	}
	else
	{
		float a;
		float b;
		a = (this->constTerm * otherLine.yCoeff - this->yCoeff * otherLine.constTerm) / (this->xCoeff * otherLine.yCoeff - this->yCoeff * otherLine.xCoeff);
		b = (this->constTerm * otherLine.xCoeff - this->xCoeff * otherLine.constTerm) / (this->yCoeff * otherLine.xCoeff - this->xCoeff * otherLine.yCoeff);
		cout << "Point of intersection is: (" << a << "," << b << ")" << endl;
	}
		
}

lineType::lineType(double a,double b,double c)
{
	lineType::setLine(a,b,c);
}