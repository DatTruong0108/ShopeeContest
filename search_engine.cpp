#include<iostream>
#include<sstream>
#include<vector>
#include<cstring>
#include<map>

using namespace std;

vector<string> tokenizeByNumberOfSpace(string toTokenizeString, int noSpaces) {
  vector<string> result;

  // tokenize with 1 space only
  vector<string> tokenizedStringsByOneSpace;
  
  stringstream checkLine(toTokenizeString);

  string intermediate;
  
  while(getline(checkLine, intermediate, ' ')) {
    tokenizedStringsByOneSpace.push_back(intermediate);
  }
  
  // concatinate by number of spaces
  for(int i = 0; i < tokenizedStringsByOneSpace.size() - noSpaces; i++) {
    string temp = tokenizedStringsByOneSpace[i];
    for(int j = i + 1; j < i + noSpaces + 1; j++) {
      temp += " " + tokenizedStringsByOneSpace[j];
    }
    result.push_back(temp);
  }
  
  return result;
}
int countSpaceInString(string s) {
    int count = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            count++;
        }
    }

    return count;
}
int countInMap(map<string, int> map, string query) {
    if(map.find(query) != map.end()) {
        return map[query];
    }

    return 0;
}
void addtoMap(map<string,int> &mapp , string item) {
      if(mapp.find(item)!=mapp.end())           
            mapp[item]++;
      else
            mapp[item]=1;
}

int main() {
    vector<string> dataSet;
      dataSet.push_back("apple lettuce limes avocado");
      dataSet.push_back("onion cranberries apple limes");
      dataSet.push_back("escarole corn28corn apple lettuce limes avocado");
    
      vector<string> queries;
      queries.push_back("limes avocado");
      queries.push_back("apple lettuce");
      queries.push_back("limes");
      queries.push_back("apple");
      queries.push_back("app");
      queries.push_back("apple limes");
    
      map<string, int> resultMap;
    
      // parse input
      for(int i = 0; i < dataSet.size(); i++) {
        int noOfSpaces = countSpaceInString(dataSet[i]);
        for(int j = 0; j <= noOfSpaces; j++) {
          vector<string> spaceSeparatedData = tokenizeByNumberOfSpace(dataSet[i], j);
          for(int k = 0; k < spaceSeparatedData.size(); k++) {
            addtoMap(resultMap, spaceSeparatedData[k]);
          }
        }
      }
    
      // output
      vector<int> result;
      for(int i = 0; i < queries.size(); i++) {
        result.push_back(countInMap(resultMap, queries[i]));
      }
    
      // print result
      for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
      }
    
      return 0;
}