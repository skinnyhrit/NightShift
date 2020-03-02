#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class pixel
{
	protected:
		int x1,x2,y1,y2;
		void getdata(int nx1, int ny1, int nx2, int ny2)
		{
			
			x1 = nx1;
			x2 = nx2;
			y1 = ny1;
			y2 = ny2;
			
		}

};
class Line:public pixel
{
	private:
		int dx,dy,x,y,e,m;
	public:
		Line(int nx1, int ny1, int nx2, int ny2)
		{
			getdata(nx1,ny1,nx2,ny2);
			dx = abs(x2-x1);
			dy = abs(y2-y1);
			e = (2*dy)-dx;
			

		}
		void draw()
		{
			for(int x = x1,y = y1;y<=y2;x++)
			{
				cout<<"here";
				putpixel(round(x),round(y),RED);
				if(e < 0)
				{
					e = e + (2*dy);
				}
				else if(e >= 0)
				{
					e = e + (2*dy) - (2*dx);
					y = y + 1;
				}
				
			}		
		}

};

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	Line l1(50,50,100,50);
	
	l1.draw();
	getch();
	return 0;
}


