#include <cstdio>
#include <math.h>
#include <string>
using namespace std;

int n, k, p, x;
int arr[10][10] = { 0 };
string str;

int func(int dep, int cnt) {
	if (dep >= str.length()) {
		if (stoi(str) == x)return 0;
		if (stoi(str) <= n && stoi(str) >= 1) return 1;
		return 0;
	}

	int sum = 0;
	int cur = str[dep] - '0';
	for (int i = 0; i < 10; i++) {
		if ((cur != i) && (arr[cur][i] <= cnt)) {
			str[dep] = i + '0';
			sum += func(dep + 1, cnt - arr[cur][i]);
			str[dep] = cur + '0';
		}
		if (cur == i)sum += func(dep + 1, cnt);
	}
	return sum;
}

int main() {
	int num[] = { 0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011 };
	scanf("%d%d%d%d", &n, &k, &p, &x);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int k = num[i] ^ num[j];
			while (k != 0) {
				if (k & 1)arr[i][j]++;
				k >>= 1;
			}
		}
	}

	str = to_string(x);
	while (str.length() < k)str.insert(str.begin(), '0');
	printf("%d", func(0, p));

}