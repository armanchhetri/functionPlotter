#pragma once
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

namespace algo
{
struct v2
{
	float x;
	float y;
};

}; // namespace algo

//Declaration
namespace algo
{
void DrawLine(v2 p1, v2 p2);
void DrawTriangle(v2 p1, v2 p2, v2 p3);
void Bresenham(int x1, int y1, int x2, int y2);
}; // namespace algo

//Definiton
namespace algo
{
void DrawLine(v2 p1, v2 p2)
{
	const float dx = p2.x - p1.x;
	const float dy = p2.y - p1.y;
	float step;
	if (fabs(dx) > fabs(dy))
	{
		step = fabs(dx);
	}
	else
	{
		step = fabs(dy);
	}

	const float xinc = dx / step;
	const float yinc = dy / step;
	float x = p1.x;
	float y = p1.y;
	glVertex2f(x / 320.0f, y / 240.0f);
	for (int i = 0; i <= step; i++)
	{
		x += xinc;
		y += yinc;
		std::cout << x << "," << y << std::endl;
		glVertex2f(x / 320.0f, y / 240.0f);
	}
}

void Bresenham(int x1, int y1, int x2, int y2)
{
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++)
	{
		glVertex2f(x / 320.0f, y / 240.0f);
		slope_error_new += m_new;
 
		if (slope_error_new >= 0)
		{
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}
void midPointCircleDraw(int x_centre, int y_centre, int r)
{
	int x = r, y = 0;

	glVertex2f( (x + x_centre)/320.0f, (y + y_centre)/240.0f);
	if (r > 0)
	{
		printf("(%d, %d) ", x + x_centre, -y + y_centre);
		printf("(%d, %d) ", y + x_centre, x + y_centre);
		printf("(%d, %d)\n", -y + x_centre, x + y_centre);
		glVertex2f((x + x_centre) / 320.0f, (-y + y_centre) / 240.0f);
		glVertex2f((y + x_centre) / 320.0f, (x + y_centre) / 240.0f);
		glVertex2f((-y + x_centre) / 320.0f, (x + y_centre) / 240.0f);
	}

	int P = 1 - r;
	while (x > y)
	{
		y++;

		//point inside 
		if (P <= 0)
			P = P + 2 * y + 1;

		// point outside 
		else
		{
			x--;
			P = P + 2 * y - 2 * x + 1;
		}

		if (x < y)
			break;

		
		glVertex2f((x + x_centre) / 320.0f, (y + y_centre) / 240.0f);
		glVertex2f((-x + x_centre) / 320.0f, (y + y_centre) / 240.0f);	
		glVertex2f((x + x_centre) / 320.0f, (-y + y_centre) / 240.0f);
		glVertex2f((-x + x_centre) / 320.0f, (-y + y_centre) / 240.0f);
		//  generated point is on the line x = y then  
		// the perimeter points have already been printed 
		if (x != y)
		{
			glVertex2f((y + x_centre) / 320.0f, (x + y_centre) / 240.0f);

			glVertex2f((-y + x_centre) / 320.0f, (x + y_centre) / 240.0f);
			glVertex2f((y + x_centre) / 320.0f, (-x + y_centre) / 240.0f);

			glVertex2f((-y + x_centre) / 320.0f, (-x + y_centre) / 240.0f);

		}
	}
}


void DrawTriangle(v2 p1, v2 p2, v2 p3)
{
	DrawLine(p1, p2);
	DrawLine(p2, p3);
	DrawLine(p1, p3);
}

} // namespace algo