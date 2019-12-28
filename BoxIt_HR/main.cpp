#include "Box.hpp"

using namespace std;




void check2()
{
	int n;
	std::cout <<" Enter number of inputs\n";
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
  		std::cout << " Enter type \n";
		int type;

		cin>>type;
		if(type ==1)
		{
			std::cout << "Creating default box\n";
			cout<<temp<<endl;
		}
		if(type == 2)
		{
 			std::cout << "Input l, b, h\n";
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			std::cout << "creating customized box\n";
			cout<<temp<<endl;
		}
		if(type==3)
		{
			std::cout << "Input l, b, h\n";
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			std::cout << "Comparison result is \n";
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
			std::cout << "Calculating volume \n";
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			std::cout << "Creating new box out of old one \n";
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}

