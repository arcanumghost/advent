#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

void reduce(set<string> &sources)
{
	vector<string> sortedsources(sources.begin(),sources.end());
	sort(sortedsources.begin(),sortedsources.end());
	sources.clear();
	for(int i=0; i<50000 && i<sortedsources.size(); ++i)
		sources.insert(sortedsources[i]);
}

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
				p = source.find(rep.second, p+1);
				string tSrc = source;
				if(p>-1 && p<source.length())
					results.insert(tSrc.replace(p,rep.second.length(),rep.first));
			}while (p < source.size() && p != -1);
		}
	}
	sources = results;
	cout << results.size() << " sources ";
	reduce(sources);
	cout << "reduced to " << sources.size() << endl;
	if(!sources.size())
		cout << "damn" << endl;
}


// between 207 and 215...
int main()
{
	fstream input {"test.txt",ios::in};
	string line;

	//string dest = "CRnCaCaCaSiRnBPTiMgArSiRnSiRnMgArSiRnCaFArTiTiBSiThFYCaFArCaCaSiThCaPBSiThSiThCaCaPTiRnPBSiThRnFArArCaCaSiThCaSiThSiRnMgArCaPTiBPRnFArSiThCaSiRnFArBCaSiRnCaPRnFArPMgYCaFArCaPTiTiTiBPBSiThCaPTiBPBSiRnFArBPBSiRnCaFArBPRnSiRnFArRnSiRnBFArCaFArCaCaCaSiThSiThCaCaPBPTiTiRnFArCaPTiBSiAlArPBCaCaCaCaCaSiRnMgArCaSiThFArThCaSiThCaSiRnCaFYCaSiRnFYFArFArCaSiRnFYFArCaSiRnBPMgArSiThPRnFArCaSiRnFArTiRnSiRnFYFArCaSiRnBFArCaSiRnTiMgArSiThCaSiThCaFArPRnFArSiRnFArTiTiTiTiBCaCaSiRnCaCaFYFArSiThCaPTiBPTiBCaSiThSiRnMgArCaF";
	//string dest = "HOH";
	//set<string> sources {"e"};

	// Go backwards
	//set<string> sources = {"CRnCaCaCaSiRnBPTiMgArSiRnSiRnMgArSiRnCaFArTiTiBSiThFYCaFArCaCaSiThCaPBSiThSiThCaCaPTiRnPBSiThRnFArArCaCaSiThCaSiThSiRnMgArCaPTiBPRnFArSiThCaSiRnFArBCaSiRnCaPRnFArPMgYCaFArCaPTiTiTiBPBSiThCaPTiBPBSiRnFArBPBSiRnCaFArBPRnSiRnFArRnSiRnBFArCaFArCaCaCaSiThSiThCaCaPBPTiTiRnFArCaPTiBSiAlArPBCaCaCaCaCaSiRnMgArCaSiThFArThCaSiThCaSiRnCaFYCaSiRnFYFArFArCaSiRnFYFArCaSiRnBPMgArSiThPRnFArCaSiRnFArTiRnSiRnFYFArCaSiRnBFArCaSiRnTiMgArSiThCaSiThCaFArPRnFArSiRnFArTiTiTiTiBCaCaSiRnCaCaFYFArSiThCaPTiBPTiBCaSiThSiRnMgArCaF"};
	set<string> sources {"HOHOHOHOHOHOHO"};
	string dest = "e";

	vector<pair<string,string>> replacements;
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