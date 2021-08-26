#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

class priorityQueue
{
	vector <int> pq;
public:

	bool isEmpty(){
		return pq.size() == 0;
	}

	/// Gives size fo Heap
	int getSize(){
		return pq.size();
	}

	int getMin(){
		if( pq.size() == 0){
			return 0;
		}
		return pq[0];
	}


	void insert(int data){

		pq.push_back(data);
		if( this->isEmpty()){
			return;
		}
		int ch = pq.size() - 1;
		while( ch > 0){
			int p = (ch - 1)/2;
			if( pq[p] > pq[ch]){
				int temp = pq[p];
				pq[p] = pq[ch];
				pq[ch] = temp;
			}else{
				break;
			}
			ch = p;
			p = (ch-1)/2;

		}

	}

	int remove(){

		if( pq.size() == 0) return 0;

		int data = pq[0];
		pq[0] = pq[pq.size() -1 ];
		pq.pop_back();

		int pindex = 0;
		int leftChild = 2 * pindex + 1;
		int rightChild = 2 * pindex + 2;

		while( leftChild < pq.size()){

			int minIndex = pindex;

			if( pq[minIndex] > pq[ leftChild]) minIndex = leftChild;

			if(rightChild < pq.size() && pq[minIndex] > pq[ rightChild]) minIndex = rightChild;

			if( minIndex == pindex) break;

				int temp = pq[pindex];
				pq[pindex] = pq[minIndex];
				pq[minIndex] = temp;

			pindex = minIndex;
			leftChild = 2 * pindex + 1;
			rightChild = 2 * pindex + 2;
		}
		return data;
	}
	
};


int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();

int n;
cin>>n;

priorityQueue p;

for( int i = 0; i < n; i++){
	int x;
	cin>>x;
	p.insert(x);
}

cout<<"\n SIZE : "<<p.getSize();

cout<< "\n Min ELement : "<<p.getMin() ;

cout<<"\n Deleted Order : ";
while( p.getSize() != 0){

	cout<< p.remove() <<" ";
}
 

return 0;

}

/*

Input : 
5
12 34 56 10 50

Output:
 SIZE : 5
 Min ELement : 10
 Deleted Order : 10 12 34 50 56 
 */
