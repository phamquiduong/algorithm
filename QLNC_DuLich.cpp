//Bai toan du lich.. Tim chi phi nho nhat

#include <iostream>
using namespace std;

const int n = 4;

int save[n+1], cost[n+1][n+1], minCost=9999, minV[n+1];
bool b[n+1];

void proc(int currentCost) {
	if (currentCost < minCost) {
		minCost=currentCost;			// Save minimum cost
		for (int i=1; i<=n; i++) minV[i] = save[i];		// Save minimum city visited
	}
}

void TRY (int i, int currentCost) {
	for (int j=1; j<=n; j++) {
			//Return TRUE if city j not visited && have line from city j and before visited && current cost less than minimum cost.
		if (b[j] && (cost[save[i-1]][j]!=0) && currentCost+cost[save[i-1]][j] < minCost) {
			b[j] = false;
			save[i] = j;
			if (i == n) proc(currentCost+cost[save[i-1]][j]);
			else TRY(i+1, currentCost+cost[save[i-1]][j]);
			b[j] = true;
		}
	}
}

int main() {
		//Init Value
	for (int i=1; i<=n; i++) b[i] = true;
	save[0] = 0;
	cost[0][1] = cost[0][2] = cost[0][3] = cost[0][4] = 1;
	cost[1][2] = 3;
	cost[1][3] = 2;
	cost[1][4] = 1;
	cost[2][3] = 1;
	cost[2][4] = 2;
	cost[3][4] = 4;
	for (int i=1; i<=n; i++)
		for (int j=1; j<i; j++)
			cost[i][j] = cost[j][i];

//	for (int i=0; i<=n; i++){				// Print maps
//		for (int j=0; j<=n; j++) cout<<cost[i][j]<<" ";
//		cout<<endl;
//	}

	TRY(1,0);
	
	cout<<"Min Cost: "<<minCost-1<<endl<<"-> ";
	for (int i=1; i<=n; i++) cout<<minV[i]<<" ";
}
