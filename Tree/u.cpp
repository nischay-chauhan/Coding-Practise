#include <iostream>
#include <string>
#include <map>
#include <vector>

/* 
1. Suffix Tree
A suffix tree is a compressed trie containing all suffixes of a string. It enables efficient solutions to complex string problems.

Properties:

Space: O(n) for a string of length n

Construction time: O(n) with Ukkonen's algorithm

Supports operations in O(m) time (pattern length m)
*/
struct SuffixTreeNode {
    std::map<char, SuffixTreeNode*> children;
    SuffixTreeNode* suffix_link;
    int start;
    int* end;

    SuffixTreeNode(int start, int* end) : start(start), end(end), suffix_link(nullptr) {}

    int edgeLength() {
        return *end - start + 1;
    }
};

class SuffixTree {
public:
    SuffixTree(const std::string& text) : text(text) {
        build();
    }

    ~SuffixTree() {
        deleteTree(root);
    }

    bool hasSubstring(const std::string& pattern) {
        SuffixTreeNode* current_node = root;
        int i = 0;
        while (i < pattern.length()) {
            if (current_node->children.find(pattern[i]) == current_node->children.end()) {
                return false;
            }

            SuffixTreeNode* next_node = current_node->children[pattern[i]];
            int edge_len = next_node->edgeLength();
            
            for (int j = 0; j < edge_len && i < pattern.length(); ++j) {
                if (text[next_node->start + j] != pattern[i]) {
                    return false; // Mismatch on the edge
                }
                i++;
            }
            current_node = next_node;
        }
        return true;
    }

    void printTree() {
        std::cout << "Suffix Tree Structure (Edges point to nodes with [start, end] indices):" << std::endl;
        printNode(root, "");
    }

private:
    std::string text;
    SuffixTreeNode* root = nullptr;
    
    SuffixTreeNode* active_node = nullptr;
    int active_edge = -1;
    int active_length = 0;
    int remaining_suffixes = 0;
    int leaf_end = -1; // Global end for all leaves, updated each phase

    void build() {
        root = new SuffixTreeNode(-1, new int(-1));
        active_node = root;

        for (int i = 0; i < text.length(); ++i) {
            extend(i);
        }
    }

    void extend(int phase) {
        leaf_end = phase; // Rule 1: All leaves extend implicitly
        remaining_suffixes++;
        SuffixTreeNode* last_new_node = nullptr;

        while (remaining_suffixes > 0) {
            if (active_length == 0) {
                active_edge = phase; // Start from the current character
            }

            if (active_node->children.find(text[active_edge]) == active_node->children.end()) {
                active_node->children[text[active_edge]] = new SuffixTreeNode(phase, &leaf_end);
                if (last_new_node != nullptr) {
                    last_new_node->suffix_link = active_node;   
                    last_new_node = nullptr;
                }
            } else {
                SuffixTreeNode* next_node = active_node->children[text[active_edge]];
                if (active_length >= next_node->edgeLength()) {
                    active_node = next_node;
                    active_length -= next_node->edgeLength();
                    active_edge += next_node->edgeLength();
                    continue;
                }

                if (text[next_node->start + active_length] == text[phase]) {
                    if (last_new_node != nullptr && active_node != root) {
                        last_new_node->suffix_link = active_node;
                    }
                    active_length++;
                    break;
                }

                // Rule 2 (Case 2): Split the edge.
                int* split_end = new int(next_node->start + active_length - 1);
                SuffixTreeNode* split_node = new SuffixTreeNode(next_node->start, split_end);
                active_node->children[text[active_edge]] = split_node;

                split_node->children[text[phase]] = new SuffixTreeNode(phase, &leaf_end);
                next_node->start += active_length;
                split_node->children[text[next_node->start]] = next_node;

                if (last_new_node != nullptr) {
                    last_new_node->suffix_link = split_node;
                }
                last_new_node = split_node;
            }

            remaining_suffixes--;
            if (active_node == root && active_length > 0) {
                active_length--;
                active_edge = phase - remaining_suffixes + 1;
            } else if (active_node != root) {
                active_node = active_node->suffix_link;
            }
        }
    }

    void printNode(SuffixTreeNode* node, const std::string& indent) {
        if (node == nullptr) return;
        for (auto const& [key, val] : node->children) {
            std::cout << indent << "-> Edge(" << key << ")[" << val->start << ", " << *val->end << "]: " 
                      << text.substr(val->start, val->edgeLength()) << std::endl;
            printNode(val, indent + "  ");
        }
    }

    void deleteTree(SuffixTreeNode* node) {
        if (node == nullptr) return;
        for (auto const& [key, val] : node->children) {
            deleteTree(val);
        }
        // Internal nodes and the root have their own allocated 'end' pointers.
        if (!node->children.empty()) {
            delete node->end;
        }
        delete node;
    }
};

int main() {
    // A unique character ($) at the end is crucial for ensuring every suffix ends at a leaf.
    std::string s = "banana$";
    std::cout << "Building Suffix Tree for: " << s << std::endl;
    SuffixTree st(s);

    st.printTree();

    std::cout << "\nSearching for substrings:" << std::endl;
    std::vector<std::string> patterns = {"nana", "bana", "ana", "apple", "bananas", "$"};
    for (const auto& p : patterns) {
        std::cout << " - '" << p << "': " << (st.hasSubstring(p) ? "Found" : "Not Found") << std::endl;
    }

    return 0;
}