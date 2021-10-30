#include<bits/stdc++.h>
using namespace std;
void ppppp(int a){
    a += 1;
    cout << a << endl;
    a = 100; // no change to value of a while coming back in recursion stack
}
void pppp(int a){
    a+=1 ;
   cout << a << endl;
    ppppp(a); 
    cout << a << endl;
}
void ppp(int a){
    a += 1;
   cout << a << endl;
    pppp(a); 
}
void pp(int a){
    a += 1;
    cout << a << endl;
    ppp(a);
}
void p(int a){
    cout << a << endl;
    pp(a);
    cout << a << endl;
}

void pI(int a){ // 1 to 4
    if(a == 5)return;
    cout << a << endl;
    pI(a + 1);
}

void pD(int a){ // 1 to 4
    if(a == -1)return;
    cout << a << endl;
    pD(a - 1);
}

void pID(int a){ // 1 to 4 to 1
    if(a > 4)return;
    cout << a << " ";
    pID(a + 1);
    cout << a << endl;
}

void printOE(int a, int b){
    if(a  > b)
    return;
    if(a % 2 == 0)
    cout << a << " ";
    printOE(a + 1, b);
    if(a % 2 != 0)
    cout << a << endl;
}

void display(vector<int>&arr, int idx){
    if(idx == arr.size())
    return;
    cout << arr[idx] << " ";
    display(arr, idx + 1);
} 

void dRev(vector<int>&arr, int idx){
    if(idx == arr.size())
    return;
    display(arr, idx + 1);
    cout << arr[idx] << " ";
}

int maximum(vector<int>&arr, int idx){
    if(idx == arr.size())return -(int)1e9;
    int a = maximum(arr, idx + 1);
    return  (a < arr[idx]) ? arr[idx] : a;
}
int minimum(vector<int>&arr, int idx){
    if(idx == arr.size())return (int)1e9;
    int a = maximum(arr, idx + 1);
    return  (a > arr[idx]) ? arr[idx] : a;
}

bool find(vector<int>&arr, int idx, int tar){
    if(idx == arr.size())return false;
    return arr[idx] == tar || find(arr, idx + 1, tar);
}

int fI(vector<int>&arr, int idx, int tar){
    if(idx == arr.size())return -1;
    if(arr[idx] == tar)return idx;
    return fI(arr, idx + 1, tar);
}

int lI(vector<int>&arr, int idx, int tar){
    if(idx == arr.size())
    return -1;
    int idxt = lI(arr, idx + 1, tar);
    return idxt == -1 and arr[idx] == tar ? idx : idxt;
}

vector<int>AllIn(vector<int>&arr, int idx, int tar){
    if(idx == arr.size())return {};
    // if(arr[idx] == tar)
    // cnt++;
    vector<int>smallAns = AllIn(arr, idx + 1, tar);
    if(arr[idx] == tar)
    smallAns.push_back(idx);

    return smallAns;
}
vector<string>subseq1(string s){
    if(s.length() == 0)
        return {""};
    vector<string>smallAns = subseq1(s.substr(1));
    vector<string>ans;
    for(int i = 0; i < smallAns.size(); i++){
        ans.push_back(s[0] + smallAns[i]);
    }
    for(int i = 0; i < smallAns.size(); i++){
        ans.push_back(smallAns[i]);
    }

    return  ans;
}
int subseq(string s, int idx, string ans){
    if(idx == s.length()){
        cout <<ans <<endl;
        return 1;
    }
    int cnt = 0;
    cnt += subseq(s, idx + 1, ans + s[idx]);
    cnt += subseq(s, idx + 1, ans);

    return cnt;
}

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr > dr || sc > dc)
    return {};
    if(sr == dr and sc == dc){
        return {""};
    }
    vector<string>hor = getMazePaths(sr, sc + 1, dr, dc);
      vector<string>ver = getMazePaths(sr + 1, sc, dr, dc);
    // vector<string>diag = getMazePaths(sr + 1, sc + 1, dr, dc);
    vector<string>ans;
    for(int i = 0; i < hor.size(); i++){
        ans.push_back("h" + hor[i]);
    }
    for(int i = 0; i < ver.size(); i++){
        ans.push_back("v" + ver[i]);
    }
    // for(int i = 0; i < diag.size(); i++){
    //     ans.push_back("D" + diag[i]);
    // }

    return ans;
}

int getMazePaths1(int sr, int sc, int dr, int dc, string psf){
    if(sr == dr and sc == dc){
        cout << psf << " " ;
        return 1;
    }
    int cnt = 0;
    if(sr < dr + 1)
    cnt += getMazePaths1(sr + 1, sc, dr, dc, psf + "V");
    if(sc < dc + 1)
    cnt += getMazePaths1(sr, sc + 1, dr, dc, psf + "H");
    if(sr < dr + 1 and sc < dc + 1)
    cnt += getMazePaths1(sr + 1, sc + 1, dr, dc, psf + "D");
    return cnt;
}

vector<string>MazePathMulti(int sr, int sc, int dr, int dc){ // can do without forming the three extra vectors
    if(sr == dr and sc == dc)
        return {""};
    vector<string>row;
    vector<string>col;
    vector<string>diag;
    for(int i = 1; i <= dc - sc; i++){
        vector<string>sA = MazePathMulti(sr, sc + i, dr, dc);
        for(int t = 0; t < sA.size(); t++){
            col.push_back("H" + to_string(i) + sA[i]);
        }
    }
    for(int i = 1; i <= dr - sr; i++){
        vector<string>sA = MazePathMulti(sr + i, sc, dr, dc);
        for(int t = 0; t < sA.size(); t++){
            row.push_back("V" + to_string(i) + sA[i]);
        }
    }
    for(int i = 1; i <= dr - sr and i <= dc - sc; i++){
        vector<string>sA = MazePathMulti(sr + i, sc + i, dr, dc);
        for(int t = 0; t < sA.size(); t++){
            diag.push_back("D" + to_string(i) + sA[i]);
        }
    }
    vector<string>f_ans;
    for(auto ele : row){
        f_ans.push_back(ele);
    }
    for(auto ele : col){
        f_ans.push_back(ele);
    }
    for(auto ele : diag){
        f_ans.push_back(ele);
    }

    return f_ans;
}

int MazePath_Multi(int sr, int sc, int dr, int dc, vector<string>&ans, string psf){
    if(sr == dr and sc == dc){
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    for(int i = 1; i <= dr - sr; i++)
    cnt += MazePath_Multi(sr + i, sc, dr, dc, ans, psf + "V" + to_string(i));
    for(int i = 1; i <= dc - sc; i++)
    cnt += MazePath_Multi(sr, sc + i, dr, dc, ans, psf + "H" + to_string(i));
    for(int i = 1; i <= dr - sr and i <= dc - sc; i++)
    cnt += MazePath_Multi(sr + i, sc + i, dr, dc, ans, psf + "D" + to_string(i));
    return cnt;
}

int MazePath_Multi(int sr, int sc, int dr, int dc, vector<string>&ans, string psf, vector<vector<int>>&dir, vector<string>&dirName){
    if(sr > dr and sc > dc){
        return 0;
    }
    if(sr == dr and sc == dc){
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < dir.size(); i++){
        int p = dr - sr, q = dc - sc;
        for(int rad = 1; rad <= max(p , q); i++){
            int x = sc + rad*dir[i][0]; // in dir[i][0] i will keep i cap vector
            int y = sr + rad*dir[i][1];
            cnt += MazePath_Multi(y, x , dr ,dc ,ans, psf + dirName[i] + to_string(rad), dir , dirName);
        }
    }
    return cnt;
}
int MazePath_Multi(int sr, int sc, int dr, int dc, vector<string>&ans, string psf, vector<vector<int>>&dir, vector<string>&dirName){
    if(sr > dr and sc > dc){
        return 0;
    }
    if(sr == dr and sc == dc){
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < dir.size(); i++){
            int x = sc + dir[i][0]; // in dir[i][0] i will keep i cap vector
            int y = sr + dir[i][1];
            if(x >= 0 and y >= 0 and x <= dc and y <= dr)
            cnt += MazePath_Multi(y, x , dr ,dc ,ans, psf + dirName[i], dir , dirName);
    }
    return cnt;
}
vector<vector<bool>>vis;
vector<string>ans;
int FloodFill(int sr, int sc, int dr, int dc, vector<vector<int>>maze, vector<vector<int>>dir, vector<string>dirName, string psf){
    if(sr == dr and sc == dc){
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    vis[sr][sc] = true;
    for(int i = 0; i < dir.size(); i++){
        int x =  sr + dir[i][0];
        int y = sc + dir[i][1];
        if(x >= 0 and y >= 0 and x <= dr and y <= dc and maze[x][y] == 0 and !vis[x][y])
        cnt += FloodFill(x, y, dr, dc, maze, dir, dirName, psf + dirName[i]);
    }
    vis[sr][sc] = false;
    return cnt;
}

vector<vector<bool>>vis;
vector<string>ans;
int FloodFill(int sr, int sc, int dr, int dc, vector<vector<int>>maze, vector<vector<int>>dir, vector<string>dirName, string psf){
    if(sr == dr and sc == dc){
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    vis[sr][sc] = true;
    for(int i = 0; i < dir.size(); i++){
        for(int rad = 1; rad <= dir.size(); rad++){
        int x =  sr + rad * dir[i][0];
        int y = sc + rad * dir[i][1];
        if(x >= 0 and y >= 0 and x <= dr and y <= dc and maze[x][y] == 0 and !vis[x][y])
        cnt += FloodFill(x, y, dr, dc, maze, dir, dirName, psf + dirName[i] + to_string(rad));
        else
        break;
        }
    }
    vis[sr][sc] = false;
    return cnt;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>maze(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)cin >> maze[i][j];
    }
    vis.resize(n, vector<bool>(m, false));
    vector<vector<int>>dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<string>dirName = {"t", "l", "d", "r"};
    FloodFill(0, 0, n - 1, m - 1, maze, dir, dirName, "");
    for(int i = 0; i < ans.size(); i++)cout << ans[i] <<endl;
}
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
 vector<vector<bool>>vis;
vector<string>ans;
int FloodFill(int sr, int sc, int dr, int dc, vector<vector<int>>maze, vector<vector<int>>dir, vector<string>dirName, string psf){
    if(sr == dr and sc == dc){
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    vis[sr][sc] = true;
    for(int i = 0; i < dir.size(); i++){
        int x =  sr + dir[i][0];
        int y = sc + dir[i][1];
        if(x >= 0 and y >= 0 and x <= dr and y <= dc and maze[x][y] == 1 and !vis[x][y])
        cnt += FloodFill(x, y, dr, dc, maze, dir, dirName, psf + dirName[i]);
    }
    vis[sr][sc] = false;
    return cnt;
}

    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0)
        {
            return ans;
        }
    vis.resize(n, vector<bool>(n, false));
    vector<vector<int>>dir = {{1,0}, {0, -1},  {0, 1}, {-1,0}};
    vector<string>dirName = {"D",  "L", "R", "U"};
    FloodFill(0, 0, n - 1, n - 1, m, dir, dirName, "");
    return ans;
    }
// https://practice.geeksforgeeks.org/problems/special-matrix4201/1
vector<vector<bool>>vis;
    int mazePath(int sr, int sc, int dr, int dc, vector<vector<int>>dir){
        if(sr == dr and sc == dc)
            return 1;
        int cnt = 0;
        vis[sr][sc] = true;
            for(int i = 0; i < dir.size(); i++){
                int x = sr + dir[i][0];
                int y = sc + dir[i][1];
                if(x >= 0 and y >= 0 and x <= dr and y <= dc and !vis[x][y])
                cnt += mazePath(x, y, dr, dc , dir);
            }
        vis[sr][sc] = false;
        return cnt;
    }
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    if(blocked_cells[0][0]-1 == 0 and blocked_cells[0][1]-1 == 0)
	    return 0;
	    vis.resize(n, vector<bool>(m, false));
	    for(int i = 0;  i < blocked_cells.size(); i++){
	        vis[blocked_cells[i][0] - 1][blocked_cells[i][1] - 1] = true;
	    }
	    vector<vector<int>>dir = {{1,0}, {0,1}};
	    return mazePath(0, 0, n - 1, m - 1, dir);
	}

    // https://www.geeksforgeeks.org/rat-in-a-maze-with-multiple-steps-jump-allowed/?ref=rp
vector<vector<bool>>vis;
int mazePath(vector<vector<int>>ans, vector<vector<int>>maze, int sr, int sc, int dr, int dc,
 vector<vector<int>>dir){
    if(sr == dr and sc == dc){
        ans[sr][sc] = 1;
        for(int i = 0; i < ans.size(); i++){
            for(int j = 0; j < ans[i].size(); j++)cout <<ans[i][j] << " ";
            cout << endl;
        }
        ans[sr][sc] = 0;
            cout << endl;
        return 1;
    }
    int cnt = 0;
    int jump = maze[sr][sc];
    vis[sr][sc] = true;
    ans[sr][sc] = 1;
    for(int i = 0; i < dir.size(); i++){
        for(int rad = 1; rad <= jump; rad++){
            int x = sr + rad * dir[i][0];
            int y = sc + rad * dir[i][1];
            if(x >= 0 and y >= 0 and x <= dr and y <= dc and !vis[x][y] and maze[x][y] != 0){
                ans[x][y] = 1;
                cnt += mazePath(ans, maze, x, y, dr,dc,dir);
                ans[x][y] = 0;
            }
        }
    }
    ans[sr][sc] = 0;
    vis[sr][sc] = false;

    return cnt;
}

class Pair{
    public:
    int len;
    string psf;
    Pair(){
        len = 0;
        psf = "";
    }
    Pair(string x, int a){
        len = a;
        psf = x;
    }
};

vector<vector<bool>>vis;
Pair LongestPath(int sr ,int sc, int dr, int dc, vector<vector<int>>dir, vector<string>dirName){
    if(sr == dr and sc == dc){
        Pair base;
        return base;
    }
    Pair myAns("", -1);

    vis[sr][sc] = true;
    for(int i = 0; i < dir.size(); i++){
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(x >= 0 and y >= 0 and x <= dr and y <= dc and !vis[x][y]){
            Pair sA = LongestPath(x , y , dr , dc, dir, dirName);
            if(sA.len != -1 and sA.len + 1 > myAns.len){
                myAns.len = sA.len + 1;
                myAns.psf = dirName[i] + sA.psf;
            }
        }
    }
    vis[sr][sc] = false;
    return myAns;
}

vector<vector<bool>>vis;
Pair ShortestPath(int sr ,int sc, int dr, int dc, vector<vector<int>>dir, vector<string>dirName){
    if(sr == dr and sc == dc){
        Pair base;
        return base;
    }
    Pair myAns("", (int)1e9); // here shortest so keep (int)1e9 otherwise -1 + 1  = 0 which is min

    vis[sr][sc] = true;
    for(int i = 0; i < dir.size(); i++){
        int x = sr + dir[i][0];
        int y = sc + dir[i][1];
        if(x >= 0 and y >= 0 and x <= dr and y <= dc and !vis[x][y]){
            Pair sA = ShortestPath(x , y , dr , dc, dir, dirName);
            if(sA.len != (int)1e9 and sA.len + 1 < myAns.len){
                myAns.len = sA.len + 1;
                myAns.psf = dirName[i] + sA.psf;
            }
        }
    }
    vis[sr][sc] = false;
    return myAns;
}

int equalSetPartition(vector<int>&arr, vector<int>&set1, vector<int>&set2, int idx, int sum1, int sum2){
    if(idx == arr.size()){
        if(sum1 == sum2){
            for(int i = 0; i < set1.size(); i++)cout << set1[i] << " ";
            cout << "&";
            for(int i = 0; i < set2.size(); i++)cout << set2[i] << " ";

            cout << endl;
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    set1.push_back(arr[idx]);
    cnt += equalSetPartition(arr, set1, set2, idx + 1, sum1 + arr[idx], sum2);
    set1.pop_back();
    set2.push_back(arr[idx]);
    cnt += equalSetPartition(arr, set1, set2, idx + 1, sum1, sum2 + arr[idx]);
    set2.pop_back();
}
// with repeated groups not allowed
int equalSetPartition(vector<int>&arr, vector<int>&set1, vector<int>&set2, int idx, int sum1, int sum2){
    if(idx == arr.size()){
        if(sum1 == sum2){
            for(int i = 0; i < set1.size(); i++)cout << set1[i] << " ";
            cout << "& ";
            for(int i = 0; i < set2.size(); i++)cout << set2[i] << " ";

            cout << endl;
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    set1.push_back(arr[idx]);
    cnt += equalSetPartition(arr, set1, set2, idx + 1, sum1 + arr[idx], sum2);
    set1.pop_back();
    set2.push_back(arr[idx]);
    cnt += equalSetPartition(arr, set1, set2, idx + 1, sum1, sum2 + arr[idx]);
    set2.pop_back();
}
int perm(string s, string psf, vector<bool>&visited, int calls, int prev_calls){
        if(s.length() == 0){
            cout << psf << endl;
            return 1;
        }
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(prev_calls != calls || !visited[s[i] - 'a']){
                visited[s[i] - 'a'] = true;
                string rem = s.substr(0,i) + s.substr(i + 1);
                prev_calls = calls;
                cnt += perm(rem , psf + s[i], visited, calls + 1, prev_calls);
                visited[s[i] - 'a'] = false;
            }
        }
        return cnt;
    }


int PermutInfi(vector<int>&arr, int tar, string asf){
    if(tar < 0)return 0;
    if(tar == 0){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        cnt += PermutInfi(arr, tar - arr[i], asf + to_string(arr[i]) + ", ");
    }
    return cnt;
}

int combInf(int idx, vector<int>&arr, string asf, int tar){
    if(tar < 0)
    return 0;
    if(tar == 0){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = idx; i < arr.size(); i++){
        // cout << 1 << endl;
        cnt += combInf(i, arr, asf + to_string(arr[i]) + ", ", tar - arr[i]);
    }
    return cnt;
}

int combSingleCoin(int idx, vector<int>&arr, string asf, int tar){
    if(tar < 0)
    return 0;
    if(tar == 0){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = idx; i < arr.size(); i++){
        // cout << 1 << endl;
        cnt += combSingleCoin(i + 1, arr, asf + to_string(arr[i]) + ", ", tar - arr[i]);
    }
    return cnt;
}

vector<bool> vis;
int PermSingleCoin(vector<int>&arr, int tar, string asf){
    if(tar < 0)return 0;
    if(tar == 0){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        if(!vis[i]){
            vis[i] = true;
            cnt += PermSingleCoin(arr, tar - arr[i], asf + to_string(arr[i]) + ", ");
            vis[i] = false;
        }
    }
    return cnt;
}

int combS_subsSingle(vector<int>&arr, int tar, int idx, string asf){
     if (tar == 0 || idx == arr.size()) {
            if (tar == 0) {
                cout << asf;
                cout << endl;
                return 1;
            }
            return 0;
        }

        int count = 0;

        if (tar - arr[idx] >= 0)
            count += combS_subs(arr, tar - arr[idx], idx + 1, asf + to_string(arr[idx]) + ", ");
        count += combS_subs(arr, tar, idx + 1, asf);

        return count;
}

int combS_subs_Infi(vector<int>&arr, int tar, int idx, string asf){
     if (tar == 0 || idx == arr.size()) {
            if (tar == 0) {
                cout << asf;
                cout << endl;
                return 1;
            }
            return 0;
        }

        int count = 0;

        if (tar - arr[idx] >= 0)
            count += combS_subs_Infi(arr, tar - arr[idx], idx, asf + to_string(arr[idx]) + ", ");
        count += combS_subs_Infi(arr, tar, idx + 1, asf);

        return count;
}

int PermInfiCoin_subs(vector<int>&arr, int tar, int idx, string asf){
     if (tar == 0 || idx == arr.size()) {
            if (tar == 0) {
                cout << asf;
                cout << endl;
                return 1;
            }
            return 0;
        }

        int count = 0;

        if (tar - arr[idx] >= 0)
            count += PermInfiCoin_subs(arr, tar - arr[idx], 0, asf + to_string(arr[idx]) + ", ");
        count += PermInfiCoin_subs(arr, tar, idx + 1, asf);

        return count;
}


int PermSingle_subs(vector<int>&arr, int tar, int idx, string asf){
     if (tar == 0 || idx == arr.size()) {
            if (tar == 0) {
                cout << asf;
                cout << endl;
                return 1;
            }
            return 0;
        }

        int count = 0;

        if (tar - arr[idx] >= 0){
            if(arr[idx] > 0){
                int val = arr[idx];
                arr[idx] = -val;
                count += PermSingle_subs(arr, tar - val, 0, asf + to_string(val) + ", ");
                arr[idx] = val;
            }
        }
        count += PermSingle_subs(arr, tar, idx + 1, asf);

        return count;
}
int nqueen1D_combination(int nq, int nb, int tnb, int tnq, string asf){
    if(nq == tnq){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = nb; i < tnb; i++){
        cnt += nqueen1D(nq + 1,  i + 1, tnb, tnq, asf + "q" + to_string(nq) + "b" + to_string(i));
    }   
    return cnt;
}
int nqueen1D_Permutation(int nq, int nb, int tnb, int tnq, string asf){
    if(nq == tnq){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < tnb; i++){
        if(!boxes[i]){
            boxes[i] = true;
            cnt += nqueen1D_Permutation(nq + 1,  i + 1, tnb, tnq, asf + "q" + to_string(nq) + "b" + to_string(i));
            boxes[i] = false;
        }
    }   
    return cnt;
}

int nqueen2D_comb(int n, int m, int tnq,  int qn, int bn, string asf){
    if(qn == tnq){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = bn; i < n*m; i++){
        int row = i / m;
        int col = i % m;
        cnt += nqueen2D_comb(n, m, tnq, qn + 1, i + 1, asf + "(" + to_string(row) + "," + to_string(col) + ") ");
    }
    return cnt;
}

int nqueen2D_perm(int n, int m, int tnq,  int qn, int bn, string asf){
    if(qn == tnq){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = bn; i < n*m; i++){
        int row = i / m;
        int col = i % m;
        if(!vis[row][col]){
            vis[row][col] = true;
            cnt += nqueen2D_perm(n, m, tnq, qn + 1, 0, asf + "(" + to_string(row) + "," + to_string(col) + ") ");
            vis[row][col] = false;
        }
    }
    return cnt;
}

vector<vector<bool>>board;
bool isSafeToPlace(int row, int col){
    vector<vector<int>>dir = {{-1, 0}, {-1, -1}, {-1, 1}, {0, -1}};
    for(int i = 0; i < dir.size(); i++){
        for(int rad = 1; rad < board.size(); rad++){
            int  r = row + rad * dir[i][0];
            int  c = col + rad * dir[i][1];
            if(r >= 0 and c >= 0 and r < board.size() and c < board[0].size()){
                if(board[r][c])
                return false;
            }
            else
            break;
        }
    }

    return true;
}
int nqueen2D_comb(int n, int m, int tnq,  int qn, int bn, string asf){
    if(qn == tnq){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = bn; i < n*m; i++){
        int row = i / m;
        int col = i % m;
        if(isSafeToPlace(row, col)){
            board[row][col] = true;
            cnt += nqueen2D_comb(n, m, tnq, qn + 1, i + 1, asf + "(" + to_string(row) + "," + to_string(col) + ") ");
            board[row][col] = false;
        }
    }
    return cnt;
}

int nqueen2D_perm(int n, int m, int tnq,  int qn, int bn, string asf){
    if(qn == tnq){
        cout << asf << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = bn; i < n*m; i++){
        int row = i / m;
        int col = i % m;
        if(isSafeToPlace(row,col) and !vis[row][col]){
            vis[row][col] = true;
            cnt += nqueen2D_perm(n, m, tnq, qn + 1, 0, asf + "(" + to_string(row) + "," + to_string(col) + ") ");
            vis[row][col] = false;
        }
    }
    return cnt;
}

vector<vector<bool>>vis;
bool IS(vector<vector<bool>>vis, int row, int col){
    int n = vis.size(), m = vis[0].size();
    vector<vector<int>>dir = {{-1, 0}, {0, -1}, {-1, -1}, {-1, 1}};
    for(int i = 0; i < dir.size(); i++){
        for(int rad = 1; rad < n; rad++){
            int x = row + rad * dir[i][0];
            int y = col + rad * dir[i][1];
            if(x >= 0 and y >= 0 and x < n and y < m){
                if(vis[x][y] == true){
                    return false;
                }
            }
            else
            break;
        }
    }
    return true;
}
int NqueenComb2D(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf){
    if(nq == tnq){
        cout << asf << endl;
         return 1;
    }
    int cnt = 0;
    int n = vis.size(), m = vis[0].size();
    for(int i = nb; i < n*m; i++){
        int r = i / m;
        int c = i % m;
        if(IS(vis, r, c)){
            vis[r][c] = true;
            cnt += NqueenComb2D(vis, i + 1, tnb, nq + 1,tnq, asf + "(" + to_string(r) + ", " + to_string(c) + ") ");
            vis[r][c] = false;
        }
    }
    return cnt;
}
int NqueenComb2D_subs(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf){
    if(nq == tnq || nb == tnb){
        if(nq == tnq){
            cout << asf << endl;
             return 1;
        }
        return 0;
    }
    int cnt = 0;
    int n = vis.size(), m = vis[0].size();
    int r = nb / m;
    int c = nb % m;
    if(IS(vis, r, c)){
        vis[r][c] = true;
        cnt += NqueenComb2D_subs(vis, nb + 1, tnb, nq + 1, tnq, asf + "(" + to_string(r) + ", " + to_string(c) + ") ");
        vis[r][c] = false;
    }
    cnt += NqueenComb2D_subs(vis, nb + 1, tnb, nq, tnq, asf);
    
    return cnt;
}

// for this write is safe function to check in all 8 directions
int NqueenPerm(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf){
    if(nq == tnq){
        cout << asf << endl;
        return 1;
    }
    int n = vis.size(), m = vis[0].size();
    int cnt = 0;
    for(int i = nb; i < n * m; i++){
        int r = i / m;
        int c = i % m;
        if(IS(vis, r, c)){
            vis[r][c] = true;
            cnt += NqueenPerm(vis,0, tnb, nq + 1, tnq, asf + "(" + to_string(r) + "," + to_string(c) + ") ");
            vis[r][c] = false;
        }
    }
    
    return cnt;
}

vector<vector<bool>>vis;
vector<bool>row;
vector<bool>col;
vector<bool>diag;
vector<bool>aDiag;

int NqueenPerm(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf){
    if(nq == tnq){
        cout << asf << endl;
        return 1;
    }
    int n = vis.size(), m = vis[0].size();
    int cnt = 0;
    for(int i = nb; i < n * m; i++){
        int r = i / m;
        int c = i % m;
        if(!row[r] and !col[c] and !diag[r + c] and !aDiag[r - c + m - 1]){
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = true;
            cnt += NqueenPerm(vis,0, tnb, nq + 1, tnq, asf + "(" + to_string(r) + "," + to_string(c) + ") ");
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = false;
        }
    }
    
    return cnt;
}


int NqueenComb(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf){
    if(nq == tnq){
        cout << asf << endl;
        return 1;
    }
    int n = vis.size(), m = vis[0].size();
    int cnt = 0;
    for(int i = nb; i < n * m; i++){
        int r = i / m;
        int c = i % m;
        if(!row[r] and !col[c] and !diag[r + c] and !aDiag[r - c + m - 1]){
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = true;
            cnt += NqueenComb(vis,i + 1, tnb, nq + 1, tnq, asf + "(" + to_string(r) + "," + to_string(c) + ") ");
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = false;
        }
    }
    
    return cnt;
}

vector<vector<bool>>vis;
vector<bool>row;
vector<bool>col;
vector<bool>diag;
vector<bool>aDiag;

int NCombQueen(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf, int floor){ // most optimized without using bits
    if(nq == tnq){
        cout << asf << endl;
        return 1;
    }
    int n = vis.size(), m = vis[0].size();
    int cnt = 0;
    for(int room = 0 ;room < m;room++){
        int r = floor;
        int c = room;
        if(!row[r] and !col[c] and !diag[r + c] and !aDiag[r - c + m - 1]){
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = true;
            cnt += NCombQueen(vis,0, tnb, nq + 1, tnq, asf + "(" + to_string(r) + "," + to_string(c) + ") ", floor + 1);
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = false;
        }
    }
    
    return cnt;
}


using namespace std;
vector<vector<bool>>vis;
vector<bool>row;
vector<bool>col;
vector<bool>diag;
vector<bool>aDiag;

int NCombPerm(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf, int floor){
    if(nq == tnq || floor == vis.size()){
        if(floor == vis.size())return 0;
        cout << asf << endl;
        return 1;
    }
    int n = vis.size(), m = vis[0].size();
    int cnt = 0;
    cnt += NCombPerm(vis, 0, tnb, nq , tnq, asf, floor + 1);
    for(int room = 0 ;room < m;room++){
        int r = floor;
        int c = room;
        if(!row[r] and !col[c] and !diag[r + c] and !aDiag[r - c + m - 1]){
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = true;
            cnt += NCombPerm(vis,0, tnb, nq + 1, tnq, asf + "(" + to_string(r) + "," + to_string(c) + ") ",0);
            row[r] = col[c] = diag[r + c] = aDiag[r - c + m - 1] = false;
        }
    }
    
    return cnt;
}

vector<vector<bool>>vis;
int row = 0;
int col = 0;
int diag = 0;
int aDiag = 0;

int NCombQueen(vector<vector<bool>>vis, int nb, int tnb, int nq, int tnq, string asf, int floor){
    if(nq == tnq){
        if(nq == tnq)return 0;
        cout << asf << endl;
        return 1;
    }
    int n = vis.size(), m = vis[0].size();
    int cnt = 0;
    // cnt += NCombQueen(vis, 0, tnb, nq , tnq, asf, floor + 1);
    for(int room = 0 ;room < m;room++){
        int r = floor;
        int c = room;
        if(!(col & (1 << c)) and !(diag &(1 << (r + c))) and !(aDiag &(1 << (r - c+m - 1)))){
            // row ^= (1 << r);
                col ^= (1 << c); 
                diag ^= (1 << (r + c)); 
                aDiag ^= (1 << (r - c+ m - 1));
            cnt += NCombQueen(vis,0, tnb, nq + 1, tnq, asf + "(" + to_string(r) + "," + to_string(c) + ") ",floor + 1);
            // row ^= (1 << r);
                col ^= (1 << c); 
                diag ^= (1 << (r + c)); 
                aDiag ^= (1 << (r - c+ m - 1)); 
        }
    }
    
    return cnt;
}

bool IS(int row, int col, int num){
    // if(maze[row][col] != 0)return false;
    int n = maze.size(), m = maze[0].size();
    // cout<<"me0 "<< num<<endl;
    for(int i = 0; i < 9; i++){
        // if(i == col)continue;
        if(maze[row][i] == num)return false;
    }
    // cout<<"me1";
    for(int i = 0; i < 9; i++){
        // if(i == row)continue;
        if(maze[i][col] == num)return false;
    }
    // cout<<"me2";
    row = (row / 3) * 3;
    col = (col / 3) * 3;
    for(int i = row; i < row + 3; i++){
        for(int j = col; j < col + 3; j++){
            if(maze[i][j] == num)return false;
        }
    }
    // cout<<"me3";
    return true;
}

bool SudokuSolver(int idx, vector<int>EmptyIndex){
    int n = maze.size(), m = maze[0].size();
    if(idx == EmptyIndex.size()){
        return true;
    }
    
    // int cnt = 0;
    int code = EmptyIndex[idx];

    // decoding the code
    int row = code / m;
    int col = code % m;
    
    // cout<< row<<" and "<<col<<endl;
    // if(maze[row][col] == 0){
    for(int num = 1; num <= 9; num++){
        // cout<<"yes"<<endl;
        int mask = (1 << num);
        if(IS(row, col , num)){
            maze[row][col] = num;
            if(SudokuSolver(idx + 1,EmptyIndex))
            return true;
           maze[row][col] = 0;
        }
    }
    // }
    return false;
}

vector<vector<int>>mat;
vector<int>row_;
vector<int>col_;
bool SudokuSolver(int idx, vector<int>EmptyIndex){
    int n = maze.size(), m = maze[0].size();
    if(idx == EmptyIndex.size()){
        return true;
    }
    
    // int cnt = 0;
    int code = EmptyIndex[idx];

    // decoding the code
    int row = code / m;
    int col = code % m;
    
    // cout<< row<<" and "<<col<<endl;
    // if(maze[row][col] == 0){
    for(int num = 1; num <= 9; num++){
        // cout<<"yes"<<endl;
        int mask = (1 << num);
        if((row_[row] & mask) == 0 and (col_[col] & mask) == 0 and (mat[row/3][col/3] & 1) == 0){
            row_[row] ^= mask;
                col_[col] ^= mask;
                mat[row/3][col/3] ^= mask;
            maze[row][col] = num;
            if(SudokuSolver(idx + 1,EmptyIndex))
            return true;
            maze[row][col] = 0;
            row_[row] ^= mask;
                col_[col] ^= mask;
                mat[row/3][col/3] ^= mask;
        }
    }
    // }
    return false;
}

 vector<vector<int>>mat;
vector<int>row_;
vector<int>col_;
    bool isValidSudoku(vector<vector<char>>& maze) {
        mat.resize(3, vector<int>(3, 0));
    (row_).resize(9,0);
    (col_).resize(9,0);
            for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(maze[i][j] != '.'){
                int mask = (1 << (maze[i][j] - '0'));
                 if((row_[i] & mask) == 0 and (col_[j] & mask) == 0 and (mat[i/3][j/3] & mask) == 0){
            row_[i] ^= mask;
                col_[j] ^= mask;
                mat[i/3][j/3] ^= mask;
           }
                else
                    return false;
            }
        }
    }
return true;
    }

unordered_map<char,int>A;
bool isUsed[10] = {false};
int StringToInt(string s){
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        ans = ans * 10 + A[s[i]];
    }
    return ans;
}
int Solve(string s1, string s2, string s3, string t, int idx){
    if(idx == t.length()){
        int a = StringToInt(s1);
        int b = StringToInt(s2);
        int c = StringToInt(s3);

        if(a + b == c){
            cout << a << endl;
            cout << "+" << b << endl;
            cout << "---------" << endl;
            cout << c << endl;
            cout << endl;
            return 1;
        }

        return 0;
    }
    int cnt = 0;
    char ch = t[idx];
    for(int num = 0; num <= 9; num++){
        if((ch == s1[0] || ch == s2[0] || ch == s3[0]) and num == 0)
        continue;
        if(!isUsed[num]){
            isUsed[num] = true;
            A[ch] = num;
            cnt += Solve(s1, s2, s3, t, idx + 1);
            A[ch] = -1;
            isUsed[num] = false;
        }
    }
    return cnt;
}

using namespace std;
unordered_map<string,int>A;

int WordBreak(string s, string ans){
    if(s.length() == 0){
        cout << ans << endl;
        return 1;
    }
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        string t = s.substr(0, i + 1);
        if(A.find(t) != A.end()){
            cnt += WordBreak(s.substr(i+1), ans + t + " ");
        }
    }
    return cnt;
}


int main(){
     int n, m;
    cin >> n >> m;
    vector<vector<int>>maze(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)cin >> maze[i][j];
    }
    vis.resize(n, vector<bool>(m, false));
    vector<vector<int>>dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<string>dirName = {"t", "l", "d", "r"};
    FloodFill(0, 0, n - 1, m - 1, maze, dir, dirName, "");
    for(int i = 0; i < ans.size(); i++)cout << ans[i] << " ";
     int n, m;
    cin >> n >> m;
    vector<vector<int>>maze(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)cin >> maze[i][j];
    }
    vis.resize(n, vector<bool>(m, false));
    vector<vector<int>>dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    vector<string>dirName = {"t", "l", "d", "r"};
    FloodFill(0, 0, n - 1, m - 1, maze, dir, dirName, "");
    for(int i = 0; i < ans.size(); i++)cout << ans[i] <<endl;
}