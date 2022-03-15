 
#include <iostream>
#include <string>
#include "map.hpp"

int main ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it, it2, it3, it5, it6, it7;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

    /*
    **      c 1
    **a 1       d 0
    **     (b 1)     e 1
    **                  f 0
    */
  it = mymap.find('b');

  std::cout << "found b\n";

  it2 =  mymap.find('a');
  it3 = mymap.find('c');
  it5 = mymap.find('d');
  it6 = mymap.find('e');
  it7 = mymap.find('f');

 /* std::cout << it.getNode()->_c << "-" << it->first << " " << it2.getNode()->_c << "-" << it2->first << " " << it3.getNode()->_c << "-" <<  it3->first << " " <<  it5.getNode()->_c
        << "-" <<  it5->first << " " << it6.getNode()->_c << "-" <<  it6->first << " " <<  it7.getNode()->_c << "-" <<  it7->first << std::endl; 
  */
  mymap.erase (it);                   // erasing by iterator
  std::cout << "erase iterator to b\n";
  mymap.erase ('c');                  // erasing by key
  std::cout << "erase by key 'c'\n";
  it=mymap.find ('e');
  std::cout << "erase by range 'e' to end\n";
  mymap.erase ( it, mymap.end() );    // erasing by range

  std::cout << " display :\n";
  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}