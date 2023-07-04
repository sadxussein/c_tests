#include <iostream>

using namespace std;

class Box{
    private:
        int l, b, h;
    public:
        Box(int l = 0, int b = 0, int h = 0){
            this->l = l;
            this->b = b;
            this->h = h;
        }
        Box(Box &box){
            l = box.l;
            b = box.b;
            h = box.h;
        }
        int getLength(){ return l; }
        int getBreadth(){ return b; }
        int getHeight(){ return h; }

        long CalculateVolume(){ return (long)b*l*h; };

        friend bool operator<(Box &b1, Box &b2);

        friend ostream& operator<<(ostream &out, Box &box);
};

bool operator<(Box &A, Box &B){
    if(A.l < B.l || (A.l == B.l && A.b < B.b) || (A.l == B.l && A.b == B.b && A.h < B.h))
        return true;
    return false;
}

ostream& operator<<(ostream &out, Box &box){
    out << box.l << " " << box.b << " " << box.h;
    return out;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}