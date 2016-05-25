#include <iostream>

using namespace std;


struct Node
{
  int Size;
  int Count;

    Node ():Size (0), Count (0)
  {
  }

  Node (int size):Size (size), Count (1)
  {
  }
};

void
map_insert (map < int, Node > &map, int key, int size)
{
  std::map < int, Node >::iterator itr = map.find (key);

  if (itr != map.end ())
    {
      itr->second.Count++;
      itr->second.Size += size;
    }
  else
    {
      map[key] = Node (size);
    }
}

bool
compare (const std::pair < int, Node > &a1, const std::pair < int, Node > &a2)
{
  return a1.second.Size < a2.second.Size;
}

int
main (int argc, char* argv[])
{
  std::map < int, Node > _map;

  map_insert (_map, 1, 3);
  map_insert (_map, 3, 27);
  map_insert (_map, 7, 7);
  map_insert (_map, 3, 2);
  map_insert (_map, 1, 1);

  std::vector < std::pair < int, Node >> v (_map.begin (), _map.end ());
  std::sort (v.begin (), v.end (), compare);

  return 0;
}
