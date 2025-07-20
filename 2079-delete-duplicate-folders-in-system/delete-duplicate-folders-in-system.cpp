class Solution {
    struct TrieNode {
        string name;
        unordered_map<string, TrieNode*> children;
        string serial;  // For serialization of subtree
        bool toDelete = false;
    };
    
    TrieNode* root = new TrieNode();

    // Step 1: Build the Trie from paths
    void insert(const vector<string>& path) {
        TrieNode* curr = root;
        for (const string& folder : path) {
            if (!curr->children.count(folder)) {
                curr->children[folder] = new TrieNode();
                curr->children[folder]->name = folder;
            }
            curr = curr->children[folder];
        }
    }

    // Step 2: Serialize each subtree
    string serialize(TrieNode* node, unordered_map<string, vector<TrieNode*>>& seen) {
        if (node->children.empty()) return "";

        vector<pair<string, string>> subs;
        for (auto& [name, child] : node->children) {
            subs.push_back({name, serialize(child, seen)});
        }

        // Sort to ensure same structure gets same serialization regardless of insertion order
        sort(subs.begin(), subs.end());

        string serial;
        for (auto& [name, subSerial] : subs) {
            serial += "(" + name + subSerial + ")";
        }

        node->serial = serial;
        seen[serial].push_back(node);
        return serial;
    }

    // Step 3: Mark duplicate subtrees
    void markDuplicates(unordered_map<string, vector<TrieNode*>>& seen) {
        for (auto& [serial, nodes] : seen) {
            if (nodes.size() > 1) {
                for (TrieNode* node : nodes) {
                    node->toDelete = true;
                }
            }
        }
    }

    // Step 4: DFS to collect remaining paths
    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (child->toDelete) continue;
            path.push_back(name);
            result.push_back(path);
            collect(child, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths) {
            insert(path);
        }

        unordered_map<string, vector<TrieNode*>> seen;
        serialize(root, seen);
        markDuplicates(seen);

        vector<vector<string>> result;
        vector<string> current;
        collect(root, current, result);
        return result;
    }
};
