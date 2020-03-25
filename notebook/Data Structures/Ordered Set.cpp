// change the value of int to use this for other types

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// for set
typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> OrderedSet;

// to use this as a multiset, use a pair instead of an int, use the 
// second value of the pair to differentiate between the elements
typedef tree<PII, null_type, less<PII>, rb_tree_tag,
	tree_order_statistics_node_update> OrderedSet;
int id = 0;

// Finding the SECOND largest element
*o_set.find_by_order(1)

// Finding the number of elements strictly < 4
o_set.order_of_key(4)