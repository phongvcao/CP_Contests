//
// Created by Phong Cao on 2019-03-25.
//

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <iostream>
#include <iomanip>
#include <ios>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----<iostream>------------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----<iomanip>-------------//
using std::setprecision;
using std::setw;

//----<ios>-----------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----<sstream>-------------//
using std::ostringstream;
using std::istringstream;

//----<fstream>-------------//
using std::ofstream;
using std::ifstream;

//----<string>--------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----<cmath>---------------//
using std::sqrt;
using std::pow;

//----<cstdlib>-------------//
using std::rand;
using std::srand;

//----<ctime>---------------//
using std::time;

//----<functional>----------//
using std::hash;
using std::greater;         // lhs > rhs. Used for MinPQ
using std::less;            // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----<vector>--------------//
using std::vector;          // Unordered Array

//----<map>-----------------//
using std::map;             // Ordered Map (Red-Black Tree)

//----<unordered_map>-------//
using std::unordered_map;   // HashMap (SeparateChainingHashST)

//----<set>-----------------//
using std::set;             // Ordered Set (Red-Black Tree)

//----<unordered_set>-------//
using std::unordered_set;   // HashSet (SeparateChainingHashST)

//----<list>----------------//
using std::list;            // Doubly-Linked List with size() ( O( 1 ) )

//----<forward_list>--------//
using std::forward_list;    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----<deque>---------------//
using std::deque;           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----<queue>---------------//
using std::queue;           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;  // MaxPQ (MaxHeap) & Non-Iterable.
//                          // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----<stack>---------------//
using std::stack;           // Non-Iterable & Use std::deque as underlying data structure

//----<iterator>------------//
using std::next;            // Return an advanced iter without changing original iter
using std::prev;            // Return an decremented iter without changin original iter
using std::distance;        // Calculate distance between 2 iterators

//----<utility>-------------//
using std::pair;

//----<algorithm>-----------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;

//----<memory>--------------//
using std::make_shared;
using std::shared_ptr;

//----<cctype>--------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----<stdexcept>-----------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----<limits>--------------//
using std::numeric_limits;

//----<numeric>-------------//
using std::iota;
using std::gcd;
using std::lcm;

//--------------------------//

class WordsLookup {
public:

    WordsLookup() {
        // not implemented
    }

    virtual ~WordsLookup() {
        // not implemented
    }

    static void test() {
        unordered_map< string, unordered_map< int, unordered_set< int > > > dict;

        int lineCount = -1;
        string line = "";
        if ( getline( cin, line ) ) {
            lineCount = stoi( line );
        }

        for ( int i = 0; i < lineCount; ++i ) {
            if ( getline( cin, line ) ) {
                string word = "";
                istringstream iss( line );
                for ( int j = 0; iss >> word; ++j ) {
                    // If we can find word in dict
                    if ( dict.find( word ) != dict.end() ) {
                        // If we can find the sentence index in the 2nd unordered_map
                        if ( dict[ word ].find( i ) != dict[ word ].end() ) {
                            // If we can find the word index in the unordered_set
                            if ( dict[ word ][ i ].find( j ) != dict[ word ][ i ].end() ) {
                                // This should be flagged as an error. We do nothing for now.
                            } else {
                                // Push j into the unordered set
                                dict[ word ][ i ].insert( j );
                            }
                        } else {
                            // Create a new unordered_set
                            unordered_set< int > wordIdxSet;
                            wordIdxSet.insert( j );
                            dict[ word ].insert( pair< int, unordered_set< int > >( i, wordIdxSet ) );
                        }
                    } else {
                        // ElseIf we cannot find word in dict
                        // Create a new unordered_map AND unordered_set in dict
                        unordered_set< int > wordIdxSet;
                        wordIdxSet.insert( j );
                        unordered_map< int, unordered_set< int > > wordMap;
                        wordMap.insert( pair< int, unordered_set< int > >( i, wordIdxSet ) );
                        dict.insert( pair< string, unordered_map< int, unordered_set< int > > >( word, wordMap ) );
                    }
                }
            }
        }

        if ( getline( cin, line ) ) {
            lineCount = stoi( line );
        }

        string output = "";

        for ( int i = 0; i < lineCount; ++i ) {
            if ( getline( cin, line ) ) {
                string word = "";
                istringstream iss( line );
                // In this intersectMap we store the intersection of information of all queried words
                //
                // What we do here is:
                // - Loop through each word in the query sentence
                //     - If this is the first word
                //         - Create the intersectMap with:
                //             - key == all sentence indices of first word in dict
                //               value == all word indices of first word in dict
                //     - If this is not the first word
                //         - Loop through intersectMap
                //         - If we cannot find the sentenceIdx that's already in intersectMap in the
                //           current word's unordered_map< int, unordered_set< int > >, we remove that
                //           sentenceIdx from intersectMap. If intersectMap is empty, break and print out
                //           -1 and return. Otherwise, keep going to next words
                //
                // - Print out the final result using intersectMap
                unordered_map< int, const unordered_set< int > * > intersectMap;

                // Loop through each word in the query sentence
                for ( int i = 0; iss >> word; ++i ) {
                    // If we can't find this word in dict, let's print -1 and move to the next query line
                    if ( dict.find( word ) == dict.end() ) {
                        output += "-1";
                        // cout << line << " : " << -1 << endl;
                        break;
                    }

                    // If intersectMap is already empty() and we still have word left, let's print -1 and move to the
                    // next query line
                    if ( i != 0 && intersectMap.empty() ) {
                        output += "-1";
                        // cout << line << " : " << -1 << endl;
                        break;
                    }

                    // If this is the first word
                    if ( i == 0 ) {
                        for ( unordered_map< int, unordered_set< int > >::iterator iter = dict[ word ].begin();
                              iter != dict[ word ].end(); ++iter ) {
                            intersectMap.insert( pair< int, const unordered_set< int > * >( iter->first, &( iter->second ) ) );
                        }
                    } else {
                        // If we are here, this means this is not the first word and also intersectMap is not empty,
                        // and also this non-first-word can be found in dict.
                        for ( unordered_map< int, const unordered_set< int > * >::iterator iter = intersectMap.begin();
                              iter != intersectMap.end(); ++iter ) {
                            if ( dict[ word ].find( iter->first ) == dict[ word ].end() ) {
                                // We cannot find this sentenceIdx from the intersectMap in the dict[ word ].
                                // We have to remove this sentenceIdx from the intersectMap
                                intersectMap.erase( iter->first );
                            } else {
                                // If we can find this sentenceIdx from the intersectMap in the dict[ word ].
                                // We keep this sentenceIdx
                            }
                        }

                    }
                }

                // If intersectMap is not empty(), we print out its keys
                // Otherwise, we print out -1
                if ( ! intersectMap.empty() ) {
                    for ( unordered_map< int, const unordered_set< int > * >::iterator iter = intersectMap.begin();
                          iter != intersectMap.end(); ++iter ) {
                        if ( iter != intersectMap.begin() ) {
                            output += " ";
                        }
                        output += to_string( iter->first );
                    }
                } else {
                    output += "-1";
                    // cout << line << " : " << -1 << endl;
                }
                output += "\n";
            }
        }

        cout << output;
    }

};

int main( int argc, char ** argv ) {

    WordsLookup::test();

    return 0;
}
