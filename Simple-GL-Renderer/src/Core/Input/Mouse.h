#pragma once

class Mouse
{
public:

	static bool ButtonPressed(int button, bool repeat = true);

	static void GetPosition(double &x, double &y);

};