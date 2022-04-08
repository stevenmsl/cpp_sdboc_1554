#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1554;

/*
 Example 1:
 Input: dict = ["abcd","acbd", "aacd"]
 Output: true
 Output: Strings "abcd" and "aacd" differ only by one character in the index 1.
*/

tuple<vector<string>, bool> testFixture1()
{
  return make_tuple(vector<string>{"abcd", "acbd", "aacd"}, true);
}

/*
 Example 2:
 Input: dict = ["ab","cd","yz"]
 Output: false
*/

tuple<vector<string>, bool> testFixture2()
{
  return make_tuple(vector<string>{"ab", "cd", "yz"}, false);
}

/*
 Example 3:
 Input: dict = ["abcd","cccc","abyd","abab"]
 Output: true
*/

tuple<vector<string>, bool> testFixture3()
{
  return make_tuple(vector<string>{"abcd", "cccc", "abyd", "abab"}, 3);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << to_string(sol.diff(get<0>(f))) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << to_string(sol.diff(get<0>(f))) << endl;
}
void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << "result: " << to_string(sol.diff(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}