class Solution {
public:
    double dfs(string src, string dst,
               unordered_map<string, vector<pair<string, double>>>& graph,
               unordered_set<string>& visited) {

        if (src == dst) return 1.0;

        visited.insert(src);

        for (auto& [next, value] : graph[src]) {
            if (visited.count(next)) continue;

            double result = dfs(next, dst, graph, visited);

            if (result != -1.0)
                return value * result;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string, double>>> graph;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        for (auto& q : queries) {
            string src = q[0];
            string dst = q[1];

            if (!graph.count(src) || !graph.count(dst)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            ans.push_back(dfs(src, dst, graph, visited));
        }

        return ans;
    }
};
