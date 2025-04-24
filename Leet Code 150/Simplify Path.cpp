class Solution {
public:
    string simplifyPath(string path) {
    vector<string> dirs;
    stringstream ss(path);
    string token;


    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue; 
        } else if (token == "..") {
            if (!dirs.empty()) dirs.pop_back(); 
        } else {
            dirs.push_back(token); 
        }
    }

    
    string result = "/";
    for (int i = 0; i < dirs.size(); ++i) {
        result += dirs[i];
        if (i != dirs.size() - 1) {
            result += "/";
        }
    }

    return result;
}
};
