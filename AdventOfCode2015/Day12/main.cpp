#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

enum ObjType {ARRAY,HASH,STRING,NUM};
struct obj
{
	vector<obj*> array;
	map<obj*,obj*> hash;
	string str;
	int num;

	ObjType mytype;

	obj(fstream &input)
		: num(0)
	{
		char c;
		input >> c;
		switch (c)
		{
			case '[':
				mytype = ARRAY;
				if(input.peek() != ']') // Empty Array
				{
					do 
					{
						array.push_back(new obj(input));
						input >> c;	// ',' or ']'
					} while (c != ']');
				}
				break;
			case '{':
				mytype = HASH;
				if (input.peek() != '}') // Empty hash
				{
					do 
					{
						obj *first = new obj(input);
						input >> c; // ':'
						obj *second = new obj(input);
						hash[first] = second;
						input >> c; // ',' or '}'
					} while (c != '}');
				}
				break;
			case '"':
				mytype = STRING;
				input >> c;
				while(c != '"')
				{
					str += c;
					input >> c;
				}
				break;
			default:	// Integer
				mytype = NUM;
				str+=c;
				c = input.peek();
				while (c == '-' || (c >= '0' && c <= '9'))
				{
					str += c;
					input.ignore();
					c = input.peek();
				}
				num = stoi(str);
				break;
		}
	}

	int value()
	{
		switch (mytype)
		{
			case ARRAY:
				for(int i=0; i<array.size(); ++i)
					num += array[i]->value();
				return num;
			case HASH:
				for (pair<obj*,obj*> p : hash)
				{
					if(p.second->mytype == STRING && p.second->str == "red")
						return 0;
					//num += p.first->value(); // Unnecessary
					num += p.second->value();
				}
				return num;
			case STRING:
				return 0;
			case NUM:
				return num;
		}
		// Shouldn't be hit
		return 0;
	}
};

void main()
{
	fstream input {"input.txt", ios::in};
	obj *head = new obj(input);
	input.close();

	cout << head->value() << endl;
	
	char c;
	cin >> c;
}

/*	Star 1, which required far less than Star 2. I knew it was coming...
void main()
{
	fstream input {"input.txt", ios::in};
	char c;
	string tnum;
	int total = 0;
	while (input >> c)
	{
		while (c == '-' || (c >= '0' && c <= '9'))
		{
			tnum += c;
			input >> c;
		}

		if(!tnum.empty())
		{
			total += stoi(tnum);
			tnum.clear();
		}
	}

	cout << total << endl;

	cin >> c;
}*/