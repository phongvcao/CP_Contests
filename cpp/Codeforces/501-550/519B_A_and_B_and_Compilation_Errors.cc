#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stdint.h>
#include <cmath>
#include <algorithm>
#include <map>


using namespace std;
typedef int64_t Int;
typedef uint64_t UInt;


int main(int argc, char **argv) {
    UInt n = 0;
    map< UInt, UInt > aMap;
    map< UInt, UInt > bMap;
    map< UInt, UInt > cMap;

    string line;
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> n;
    }

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        for ( UInt i = 0; i < n; ++i ) {
            UInt num = 0;
            ss >> num;

            map< UInt, UInt >::iterator it = aMap.find( num );
            if ( it == aMap.end() ) {
                aMap.insert( make_pair( num, 1 ) );
            } else {
                aMap[ num ] += 1;
            }
        }
    }

    // for ( map< UInt, UInt >::iterator iter = aMap.begin(); iter != aMap.end(); ++iter ) {
    //     cout << "DEBUG: first: " << iter->first << endl;
    //     cout << "DEBUG: second: " << iter->second << endl;
    // }

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        for ( UInt i = 0; i < n - 1; ++i ) {
            UInt num = 0;
            ss >> num;

            map< UInt, UInt >::iterator it = bMap.find( num );
            if ( it == bMap.end() ) {
                bMap.insert( make_pair( num, 1 ) );
            } else {
                bMap[ num ] += 1;
            }

            it = aMap.find( num );
            if ( it != aMap.end() ) {
                aMap[ num ] -= 1;
                if ( aMap[ num ] == 0 ) {
                    aMap.erase( it );
                }
            }
            // aMap.erase( num );
        }
    }

    // cout << endl;
    //
    // for ( map< UInt, UInt >::iterator iter = aMap.begin(); iter != aMap.end(); ++iter ) {
    //     cout << "DEBUG: first: " << iter->first << endl;
    //     cout << "DEBUG: second: " << iter->second << endl;
    // }

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        for ( UInt i = 0; i < n - 2; ++i ) {
            UInt num = 0;
            ss >> num;

            map< UInt, UInt >::iterator it = cMap.find( num );
            if ( it == cMap.end() ) {
                cMap.insert( make_pair( num, 1 ) );
            } else {
                cMap[ num ] += 1;
            }

            it = bMap.find( num );
            if ( it != bMap.end() ) {
                bMap[ num ] -= 1;
                if ( bMap[ num ] == 0 ) {
                    bMap.erase( it );
                }
            }
            // bMap.erase( num );
        }
    }

    // cout << endl;
    //
    // for ( map< UInt, UInt >::iterator iter = bMap.begin(); iter != bMap.end(); ++iter ) {
    //     cout << "DEBUG: first: " << iter->first << endl;
    //     cout << "DEBUG: second: " << iter->second << endl;
    // }
    //
    // cout << endl;

    cout << aMap.begin()->first << endl;
    cout << bMap.begin()->first;


    return 0;
}
