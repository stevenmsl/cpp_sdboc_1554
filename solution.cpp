#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
using namespace sol1554;
using namespace std;

/*takeaways
  - given two entries in the dictionary, they must be different in one or
    more chars as they are unique per the question
  - let's use "abcd" and "aacd" as an example
    - remove the fist char 'a' from both, we got "bcd" and "acd"
      - as "bcd" != "acd"  we will ignore this one as we can't
        draw any conclusion from it
    - remove the second char 'b' from entry 1 and 'a' from entry 2 ,
      we got "acd" and "acd"
      - we can conclude that these two entries only differ in one char
        - since each entry is unique, they must differ in some chars
        - we removed one char from each entry, but the remaining chars
          in both entry form the same string - this only means one thing
          the char we removed in entry 1 is different from the one in
          entry 2
  - for those entries that differ in more than one char, no matter
    which single char you removed, the remaining chars from both
    entries will not form the same string
*/
bool Solution::diff(vector<string> &dict)
{
  const int n = dict.size(), m = dict[0].size();
  /*for each char position*/
  for (auto i = 0; i < m; i++)
  {
    auto s = unordered_set<string>();

    for (auto j = 0; j < n; j++)
    {
      /*remove the ith char from the dictionary entry */
      const auto oneLess = dict[j].substr(0, i) + dict[j].substr(i + 1);
      /* if the remaining chars form the same string as the
         previous entry, we are done
      */
      if (s.count(oneLess))
        return true;
      s.insert(oneLess);
    }
  }

  return false;
}