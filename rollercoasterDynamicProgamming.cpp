// [Fong] [Alec] [8100554843]
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <algorithm>
// put other includes here
using namespace std;

// Please fill in your USC username
const string fileName = "rollerCoasterResult";

int max(int s, vector < pair <int, int> > &RCs, int *mem);

bool pairComp(pair <int, int> a,pair <int, int> b){return a.first < b.first;}

int maxRollercoasters(vector < pair <int, int> > &RCs)
{
		// sort based on time
	// longets substring
	sort(RCs.begin(),RCs.end(),pairComp);

	int *memoized = new int[RCs.size()+1];
	memoized[RCs.size()] = 0;

	for (int i = RCs.size()-1; i >=0 ; --i)
	{
		memoized[i] = 1 + max(i,RCs,memoized);
	}
	int answer = 0;
	for (int i = 0; i < RCs.size(); ++i)
	{
		if (memoized[i] > answer)
		{
			answer = memoized[i];
		}
	}

	return answer;
}

int max(int s, vector < pair <int, int> > &RCs, int mem[]){
	int currentVal = RCs[s].second;
	int max = 0;
	for (int i = s+1; i < RCs.size(); ++i)
	{
		if (RCs[i].second > currentVal && mem[i] > max)
		{
			max = mem[i];
		}
	}
	return max;
}

// DO NOT EDIT BELOW THIS LINE

int main(int argc, char *argv[])
{
	vector<pair<int, int> > RCs;

	for (int i = 1; i < (argc + 1) / 2; i++)
	{
		int ti = atoi(argv[2 * i - 1]);
		int fi = atoi(argv[2 * i]);
		RCs.push_back(make_pair(ti, fi));
	}
	int answer = maxRollercoasters(RCs);
	std::ofstream out;
	out.open(fileName + ".txt", std::ios::app);
	out << answer << endl;
	return 0;
}