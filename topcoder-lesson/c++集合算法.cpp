#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<char> vectorObject1, vectorObject2, v_res(26), vectorObject3;
  vector<char>::iterator p, pres_end;
  int i;

  for(i = 0; i <20; i++) 
      vectorObject1.push_back('A'+i);
  for(i=10; i <26; i++) 
      vectorObject2.push_back('A'+i);

  cout << "Contents of vectorObject1:\n";
  for(i = 0; i <vectorObject1.size(); i++)
    cout << vectorObject1[ i ];
  cout << endl;

  cout << "Contents of vectorObject2:\n";
  for(i = 0; i <vectorObject2.size(); i++)
    cout << vectorObject2[ i ];
  cout << endl;

  pres_end = set_union(vectorObject1.begin(), vectorObject1.end(), vectorObject2.begin(), vectorObject2.end(), v_res.begin());

  cout << "Set union: ";
  for(p=v_res.begin(); p!=pres_end; p++)
    cout << *p;
  cout << endl;

  pres_end = set_difference(vectorObject1.begin(), vectorObject1.end(), vectorObject2.begin(), vectorObject2.end(), v_res.begin());

  cout << "Set difference: ";
  for(p=v_res.begin(); p!=pres_end; p++)
    cout << *p;
  cout << endl;

  pres_end = set_symmetric_difference(vectorObject1.begin(), vectorObject1.end(), vectorObject2.begin(), vectorObject2.end(), v_res.begin());

  cout << "Set symmetric difference: ";
  for(p=v_res.begin(); p!=pres_end; p++)
    cout << *p;
  cout << endl;

  pres_end = set_intersection(vectorObject1.begin(), vectorObject1.end(), vectorObject2.begin(), vectorObject2.end(), v_res.begin());

  cout << "Set intersection: ";
  for(p=v_res.begin(); p!=pres_end; p++)
    cout << *p;
  cout << endl;

  // includes 
  vectorObject3.push_back('A');
  vectorObject3.push_back('C');
  vectorObject3.push_back('D');

  if(includes(vectorObject1.begin(), vectorObject1.end(), vectorObject3.begin(), vectorObject3.end()))
      cout << "vectorObject1 includes all of vectorObject3.";
  else
      cout << "vectorObject3 contains elements not found in vectorObject1.";

  return 0;
}
