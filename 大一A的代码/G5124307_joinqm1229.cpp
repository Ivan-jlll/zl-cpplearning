#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define N 5
#define M 5

void fill(int num[5][5], char ch[5][5], int m) {
    int value = 1;
    int layer = 0;
    while (layer < (m + 1) / 2) {
        // Top row, left to right
        for (int i = layer; i < m - layer; ++i) {
            num[layer][i] = value++;
        }
        // Right column, top to bottom
        for (int i = layer + 1; i < m - layer; ++i) {
            num[i][m - layer - 1] = value++;
        }
        // Bottom row, right to left
        for (int i = m - layer - 2; i >= layer; --i) {
            num[m - layer - 1][i] = value++;
        }
        // Left column, bottom to top
        for (int i = m - layer - 2; i > layer; --i) {
            num[i][layer] = value++;
        }
        ++layer;
    }

    char c = 'a';
    layer = 0;
    while (layer < (m + 1) / 2) {
        // Top row, left to right
        for (int i = layer; i < m - layer; ++i) {
            ch[layer][i] = c++;
            if (c > 'z') c = 'a';
        }
        // Right column, top to bottom
        for (int i = layer + 1; i < m - layer; ++i) {
            ch[i][m - layer - 1] = c++;
            if (c > 'z') c = 'a';
        }
        // Bottom row, right to left
        for (int i = m - layer - 2; i >= layer; --i) {
            ch[m - layer - 1][i] = c++;
            if (c > 'z') c = 'a';
        }
        // Left column, bottom to top
        for (int i = m - layer - 2; i > layer; --i) {
            ch[i][layer] = c++;
            if (c > 'z') c = 'a';
        }
        ++layer;
    }
}

void print(int num[5][5], char ch[5][5], int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << num[i][j] << "\t";
        }
        cout << endl;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ch[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
	int m;
	cin >> m;
	int num[N][M] = {};
	char ch[N][M] = {};
	fill(num, ch, m);
	print(num, ch, m);
	return 0;
}
