#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
 
public:
    int kSimilarity(string A, string B) {
      unordered_map<char, int> uniq;
      size_t numchars = 0;
      int swapcount = 0;
      int cycles = 0;

      // Build graph
      for (size_t i = 0; i < A.size(); i++) {
        if (uniq.find(A[i]) == uniq.end()) {
          uniq[A[i]] = numchars;
          numchars++;
        }
      }
      
      vector< vector<int> > graph(numchars, vector<int>(0));
      for (size_t i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) // no need to swap same chars
          graph[uniq[A[i]]].push_back(uniq[B[i]]);
      }
      
      // Process Graph for cycles and update swapcount
      for (size_t len = 2; len < numchars; len++) {
        // for each starting point - find all 'len' lengthed
        for (size_t st = 0; st < numchars; st++) {
          //find len lengthed path starting from st
          int currlen = 0;
          size_t paths_size = 0;
          vector< vector<int> > paths;
          vector< vector<int> > newpaths;
          paths.push_back({(int)st});
          paths_size = paths.size();
          
          while (paths_size > 0 && (size_t)currlen < len) {
            for (size_t i = 0; i < paths_size; i++) {
              int pivo = paths[i].back();
              vector<int> next = graph[pivo];
              unique(next.begin(), next.end(), [](auto &a, auto&b) {return (a == b);});
              for (size_t j = 0; j < next.size(); j++) {
                vector<int> paths_i = paths[i];// IMP: make a copy
                paths_i.push_back(next[j]);    // Update
                newpaths.push_back(paths_i);   // Pushback
              }
            }
            paths.clear();
            paths = newpaths;
            newpaths.clear();
            paths_size = paths.size();
            currlen = (int)((paths_size > 0)?(paths[0].size())-1:len+1);
          }

          // remove the cycles formed therefrom from the graph.
          // rinse and repeat.
          cycles = 0;
          for (size_t i = 0; i < paths_size;  i++) {
            if (paths[i].front() == paths[i].back()) {  // Cycle !!
              for (size_t k = 0; k < (size_t)currlen; k++)
                graph[paths[i][k]].erase(find(graph[paths[i][k]].begin(), graph[paths[i][k]].end(), paths[i][k+1]));
              cycles++;
            }
          }
          swapcount += (cycles * (currlen - 1));
        }
      }
      return swapcount;  
    }
};

int main()
{
  Solution sol;
//  string A = "aabbccddee";
//  string B = "cdacbeebad";
  string A = "abcc";
  string B = "cacb";



  int ans = sol.kSimilarity(A, B);
  cout << "k-similar number : " << ans << endl; 
}
