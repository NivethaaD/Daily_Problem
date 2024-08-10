#include <vector>
#include <string>
#include <numeric> // for iota

class Solution {
public:
    int find(int x, std::vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y, std::vector<int>& parent, std::vector<int>& rank) {
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        int size = 4 * n * n;
        std::vector<int> parent(size);
        std::vector<int> rank(size, 0);
        std::iota(parent.begin(), parent.end(), 0); // Initialize DSU

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = 4 * (i * n + j);
                char c = grid[i][j];
                // Connect triangles within the cell
                if (c == '/') {
                    unite(base + 0, base + 3, parent, rank);
                    unite(base + 1, base + 2, parent, rank);
                } else if (c == '\\') {
                    unite(base + 0, base + 1, parent, rank);
                    unite(base + 2, base + 3, parent, rank);
                } else {
                    unite(base + 0, base + 1, parent, rank);
                    unite(base + 1, base + 2, parent, rank);
                    unite(base + 2, base + 3, parent, rank);
                }
                // Connect triangles to neighboring cells
                if (i > 0) {
                    unite(base + 0, base - 4 * n + 2, parent, rank); // Top
                }
                if (j > 0) {
                    unite(base + 3, base - 4 + 1, parent, rank); // Left
                }
            }
        }

        int regions = 0;
        for (int i = 0; i < size; ++i) {
            if (find(i, parent) == i) {
                regions++;
            }
        }
        return regions;
    }
};
