#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

void step(set<string> &sources, vector<pair<string,string>> &replacements)
{
	set<string> results;
	for (string source : sources)
	{
		for (pair<string,string> rep : replacements)
		{
			int p=-1;
			do
			{
				p = source.find(rep.first, p+1);
				string tSrc = source;
				if(p>-1 && p<source.length())
					results.insert(tSrc.replace(p,rep.first.length(),rep.second));
			}while (p < source.size() && p != -1);
		}
	}
	sources = results;
	cout << results.size() << " sources" << endl;
}

int main()
{
	fstream input {"input.txt",ios::in};
	string line;

	string dest = "CRnCaCaCaSiRnBPTiMgArSiRnSiRnMgArSiRnCaFArTiTiBSiThFYCaFArCaCaSiThCaPBSiThSiThCaCaPTiRnPBSiThRnFArArCaCaSiThCaSiThSiRnMgArCaPTiBPRnFArSiThCaSiRnFArBCaSiRnCaPRnFArPMgYCaFArCaPTiTiTiBPBSiThCaPTiBPBSiRnFArBPBSiRnCaFArBPRnSiRnFArRnSiRnBFArCaFArCaCaCaSiThSiThCaCaPBPTiTiRnFArCaPTiBSiAlArPBCaCaCaCaCaSiRnMgArCaSiThFArThCaSiThCaSiRnCaFYCaSiRnFYFArFArCaSiRnFYFArCaSiRnBPMgArSiThPRnFArCaSiRnFArTiRnSiRnFYFArCaSiRnBFArCaSiRnTiMgArSiThCaSiThCaFArPRnFArSiRnFArTiTiTiTiBCaCaSiRnCaCaFYFArSiThCaPTiBPTiBCaSiThSiRnMgArCaF";
	//string dest = "HOH";
	set<string> sources {"e"};
	vector<pair<string,string>> replacements;
	//set<string> results;
	while (getline(input, line))
	{
		string s1 = line.substr(0,line.find_first_of(' '));
		string s2 = line.substr(line.find_last_of(' ')+1,line.length()-line.find_last_of(' '));
		replacements.push_back(pair<string,string>(s1,s2));
	}
	input.close();

	int iterations=0;
	while (sources.find(dest) == sources.end())
	{
		step(sources, replacements);
		iterations++;
	}

	cout << iterations << endl;
	//cout << results.size() << endl;
	char c; cin >> c;
}