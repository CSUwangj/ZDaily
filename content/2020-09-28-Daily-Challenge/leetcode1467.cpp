#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mk(a,b) make_pari(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
LL c[50][50];
int left_color;
int right_color;
int min_color;
int max_color;
int balls_used;
int balls_left;
int number_of_balls;
int number_of_colors;
vector<int> balls;
LL answer;

void dfs(LL cur, int idx) {
//	cout << "cur" << cur << ' ' << idx << ' ' << answer << endl;
//	cout << "color" << left_color << ' ' << right_color << endl;
//	cout << "used" << balls_used << endl;
    if (idx == number_of_colors) {
        if (left_color == right_color){
            answer += cur;
        }
        return;
    }
    int minballs = max(number_of_balls/2 - (balls_used + balls_left - balls[idx]), 0);
    int maxballs = min(number_of_balls/2 - balls_used, balls[idx]);
//    cout << "minmax" << minballs << ' ' << maxballs << endl;
	for(int i = minballs; i <= maxballs; i++){
//		cout << "WTF" << i << ' ' << balls[idx] << ' ' << left_color + (i != 0) << endl;
		balls_left -= balls[idx];
        balls_used += i;
		if (i == 0 && left_color <= max_color) {
			dfs(cur, idx + 1);
		}
        if (i && i < balls[idx] && left_color < max_color) {
            left_color += 1;
            const int new_cur = cur * c[balls[idx]][i];
            dfs(new_cur, idx + 1);
            left_color -= 1;
        } else if (i == balls[idx] && left_color < max_color && right_color > min_color) {
            left_color += 1;
            right_color -= 1;
            dfs(cur, idx + 1);
            right_color += 1;
            left_color -= 1;
        }
		balls_left += balls[idx];
        balls_used -= i;
    }
//    cout << "return" << endl;
}

void init() {
    for (int i = 1; i < 50; i ++) {
        c[i][i] = 1;
        c[i][0] = 1;
//        cout << i << ':';
        for (int j = 1; j < i; ++ j) {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
//            cout << c[i][j] << ' ';
        }
//        cout << endl;
    }
}

void round_init() {
    number_of_colors = balls.size();
    number_of_balls = 0;
    int one = 0;
    for (int i = 0; i < number_of_colors; ++i) {
        if (balls[i] == 1) {
            one += 1;
        }
        number_of_balls += balls[i];
    }
    balls_left = number_of_balls;
    min_color = (number_of_colors + 1) / 2;
    max_color = number_of_colors - (one + 1) / 2;
    right_color = number_of_colors;
    left_color = 0;
    balls_used = 0;
    answer = 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    init();
    while(t--) {
    	int n;
        balls.clear();
        cin >> n;
        cout << n << endl;
        for ( int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            balls.push_back(tmp);
        }
        round_init();
//        cout << "min:" << min_color << " max:" << max_color << endl;
        dfs(1, 0);
        cout << answer << '/' << c[number_of_balls][number_of_balls/2] << endl;;
        double ans = 1.0 * answer / c[number_of_balls][number_of_balls/2];
        cout << fixed << showpoint;
        cout << setprecision(6);
		cout << ans << endl;
    }
    return 0;
}

 