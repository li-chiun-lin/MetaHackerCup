/*

*/

#define _USE_MATH_DEFINES

#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const long long MODULO = 998244353LL;
const int BLOCK_POWER = 9;
const int BLOCK_SIZE = (1 << BLOCK_POWER);
const int BLOCK_MASK = BLOCK_SIZE - 1;

void dfs(int node, int parentNode, int depth, vector<vector<int>>& adj, vector<int>& parent, vector<int>& maxDepth) {
    parent[node] = parentNode;
    maxDepth[node] = depth;
    for (int neighbor : adj[node]) {
        if (neighbor == parentNode) continue;
        dfs(neighbor, node, depth + 1, adj, parent, maxDepth);
        maxDepth[node] = max(maxDepth[node], maxDepth[neighbor]);
    }
}

struct SqrtDecomposition {
    vector<deque<long long>> blocks;
    vector<long long> blockAdditions;
    long long totalSum;
	int M;

	SqrtDecomposition(int m) : M(m), totalSum(0) {};

    inline int size() const {
        return blocks.empty() ? 0 : ((blocks.size() - 1) << BLOCK_POWER) + blocks.back().size();
    }

    void addSuffix(int position, long long value) {
        long long span = max(0, min(M, size() - 1) - position + 1);
        totalSum += span * value;
        int blockIndex = (position >> BLOCK_POWER);
        position -= (blockIndex << BLOCK_POWER);
        if (!position) {
            blockAdditions[blockIndex] += value;
        } else {
            vector<long long> buffer;
            while (blocks[blockIndex].size() > position) {
                buffer.push_back(blocks[blockIndex].back());
                blocks[blockIndex].pop_back();
            }
            while (!buffer.empty()) {
                blocks[blockIndex].push_back(buffer.back() + value);
                buffer.pop_back();
            }
        }
        ++blockIndex;
        while (blockIndex < blockAdditions.size()) {
            blockAdditions[blockIndex++] += value;
        }
    }

    void insert(int position, long long value) {
        if (position <= M) {
            if (size() > M) totalSum -= get(M);
            totalSum += value;
        }
        int blockIndex = (position >> BLOCK_POWER);
        if (blockIndex == blocks.size()) {
            blocks.push_back(deque<long long>(1, value));
            blockAdditions.push_back(0LL);
            return;
        }
        position -= (blockIndex << BLOCK_POWER);
        vector<long long> buffer;
        buffer.reserve(position);
        deque<long long>& block = blocks[blockIndex];
        while (position--) {
            buffer.push_back(block.front());
            block.pop_front();
        }
        block.push_front(value - blockAdditions[blockIndex]);
        while (!buffer.empty()) {
            block.push_front(buffer.back());
            buffer.pop_back();
        }
        if (block.size() > BLOCK_SIZE) {
            long long overflowValue = block.back() + blockAdditions[blockIndex];
            block.pop_back();
            ++blockIndex;
            for (;;) {
                if (blockIndex == blocks.size()) {
                    blocks.push_back(deque<long long>(1, overflowValue));
                    blockAdditions.push_back(0LL);
                    break;
                }
                blocks[blockIndex].push_front(overflowValue - blockAdditions[blockIndex]);
                if (blocks[blockIndex].size() <= BLOCK_SIZE) break;
                overflowValue = blocks[blockIndex].back() + blockAdditions[blockIndex];
                blocks[blockIndex].pop_back();
                ++blockIndex;
            }
        }
    }

    pair<long long, long long> getTwo(int index) {
        deque<long long>& block = blocks[index];
        if (block.size() == 1) {
            return make_pair(block.front() + blockAdditions[index], -1LL);
        }
        pair<long long, long long> result;
        result.first = block.front();
        block.pop_front();
        result.second = block.front();
        block.push_front(result.first);
        result.first += blockAdditions[index];
        result.second += blockAdditions[index];
        return result;
    }

    long long get(int position) {
        const int blockIndex = (position >> BLOCK_POWER);
        deque<long long>& block = blocks[blockIndex];
        if (!(position & BLOCK_MASK)) return block.front() + blockAdditions[blockIndex];
        position -= (blockIndex << BLOCK_POWER);
        vector<long long> buffer;
        buffer.reserve(position);
        while (position--) {
            buffer.push_back(block.front());
            block.pop_front();
        }
        const long long result = block.front() + blockAdditions[blockIndex];
        while (!buffer.empty()) {
            block.push_front(buffer.back());
            buffer.pop_back();
        }
        return result;
    }

    long long getResult() {
        long long result = totalSum;
        if (size() <= M) {
            result += static_cast<long long>(M - size() + 1) * get(size() - 1);
        }
        return result % MODULO;
    }
};

void merge(SqrtDecomposition& mainDecomp, SqrtDecomposition& secondaryDecomp) {
    int sizeSecondary = secondaryDecomp.size();
    int index = 0;
    vector<long long> buffer;
    long long lastMain = mainDecomp.blocks.back().back() + mainDecomp.blockAdditions.back();
    long long lastSecondary = secondaryDecomp.blocks.back().back() + secondaryDecomp.blockAdditions.back();

    while ((index << BLOCK_POWER) < sizeSecondary) {
        int position = 0;
        if (index == size(mainDecomp.blocks)) {
            mainDecomp.blocks.push_back(deque<long long>());
            mainDecomp.blockAdditions.push_back(0LL);
        }
        while (!secondaryDecomp.blocks[index].empty()) {
            long long currentValue = lastMain;
            if (!mainDecomp.blocks[index].empty()) {
                currentValue = mainDecomp.blocks[index].front() + mainDecomp.blockAdditions[index];
                mainDecomp.blocks[index].pop_front();
                if (((index << BLOCK_POWER) | position) <= mainDecomp.M) {
                    mainDecomp.totalSum -= currentValue;
                }
            }
            currentValue = min(currentValue, secondaryDecomp.blocks[index].front() + secondaryDecomp.blockAdditions[index]);
            secondaryDecomp.blocks[index].pop_front();
            buffer.push_back(currentValue);
            ++position;
        }
        --position;
        while (!buffer.empty()) {
            if (((index << BLOCK_POWER) | position) <= mainDecomp.M) {
                mainDecomp.totalSum += buffer.back();
            }
            mainDecomp.blocks[index].push_front(buffer.back() - mainDecomp.blockAdditions[index]);
            buffer.pop_back();
            --position;
        }
        ++index;
    }
    int hasPopped = 0;
    while (!mainDecomp.blocks.back().empty() && mainDecomp.blocks.back().back() + mainDecomp.blockAdditions.back() > lastSecondary) {
        hasPopped = 1;
        int blockPosition = mainDecomp.size() - 1;
        long long value = mainDecomp.blocks.back().back() + mainDecomp.blockAdditions.back();
        if (blockPosition <= mainDecomp.M) mainDecomp.totalSum -= value;
        mainDecomp.blocks.back().pop_back();
    }
    if (hasPopped && mainDecomp.blocks.back().back() != lastSecondary) {
        mainDecomp.insert(mainDecomp.size(), lastSecondary);
    }
}

long long recursiveFast(int node, SqrtDecomposition& sqrtDecomp, vector<int>& A, vector<vector<int>>& adj, vector<int>& parent, vector<int>& maxDepth) {
    int heavyChild = -1;
    for (int neighbor : adj[node]) {
        if (neighbor == parent[node]) continue;
        if (heavyChild == -1 || maxDepth[heavyChild] < maxDepth[neighbor]) {
            heavyChild = neighbor;
        }
    }

    long long result = 0;
    if (heavyChild == -1) {
        result = A[node];
        sqrtDecomp.blocks.resize(1);
        sqrtDecomp.blockAdditions.assign(1, 0LL);
        sqrtDecomp.blocks[0].push_front(result);
        sqrtDecomp.blocks[0].push_front(0LL);
        sqrtDecomp.totalSum = result;
        return sqrtDecomp.getResult();
    }

    result = recursiveFast(heavyChild, sqrtDecomp, A, adj, parent, maxDepth);
    for (int neighbor : adj[node]) {
        if (neighbor == heavyChild || neighbor == parent[node]) continue;
        SqrtDecomposition subDecomp(sqrtDecomp.M);
        result += recursiveFast(neighbor, subDecomp, A, adj, parent, maxDepth);
        if (result >= MODULO) result -= MODULO;
        merge(sqrtDecomp, subDecomp);
    }

    int position = sqrtDecomp.size() - 1;
    long long value = sqrtDecomp.blocks.back().back() + sqrtDecomp.blockAdditions.back();
    for (int i = 0; i < size(sqrtDecomp.blocks); ++i) {
        auto [first, second] = sqrtDecomp.getTwo(i);
        if (i + 1 == size(sqrtDecomp.blocks) || first + A[node] > second) {
            value = first;
            position = (i << BLOCK_POWER);
            break;
        }
    }
    sqrtDecomp.insert(position + 1, value);
    sqrtDecomp.addSuffix(position + 1, A[node]);

    result += sqrtDecomp.getResult();
    if (result >= MODULO) result -= MODULO;
    return result;
}



long long minflow_maxcut(int N, int M, vector<int>& A, vector<int>& U, vector<int>& V)
{
	vector<vector<int>> adj(N);
	vector<int> parent(N), maxDepth(N);

	for (int i = 0; i < N - 1; ++i)
	{
		adj[U[i] - 1].push_back(V[i] - 1);
		adj[V[i] - 1].push_back(U[i] - 1);
	}

	dfs(0, 0, 0, adj, parent, maxDepth);
	
	SqrtDecomposition s(M);
    return recursiveFast(0, s, A, adj, parent, maxDepth);
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N, M;

		cin >> N >> M;

		vector<int> A(N);
		//A.resize(N);
		vector<int> U(N - 1), V(N - 1);

		for (auto& a : A)
			cin >> a;

		for (int i = 0; i < N - 1; ++i)
			cin >> U[i] >> V[i];

		cout << "Case #" << t << ": ";
		cout << minflow_maxcut(N, M, A, U, V) << "\n";
	}

	return 0;
}

