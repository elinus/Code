#include <iostream>
#include <map>
#include <limits>

using namespace std;

template<typename K, typename V>
class interval_map {
    std::map<K,V> m_map;

    public:
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val) {
        m_map.insert(m_map.end(),std::make_pair(std::numeric_limits<K>::lowest(),val));
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if (!(keyBegin < keyEnd)) return; 

        auto begin_lb = m_map.lower_bound(keyBegin); 
        auto begin_ub = m_map.upper_bound(keyBegin);
        auto end_lb = m_map.lower_bound(keyEnd);
        auto end_ub = m_map.upper_bound(keyEnd);
        K begin_search, end_search;
        auto begin_delete = begin_lb;
        auto end_delete = end_lb;

        begin_search = begin_lb->first;
        if (--begin_lb != m_map.end()) begin_search = begin_lb->first;

        if (end_lb == end_ub) --end_lb;
        end_delete = end_lb;

        V tail = end_delete->second;
        end_search = end_lb->first;

        m_map.erase(begin_delete, ++end_delete); 

        m_map.insert(std::begin(m_map), std::make_pair(begin_search, val));
        m_map.insert(std::begin(m_map), std::make_pair(end_search, tail));

        auto it = m_map.find(begin_search);
        V prev = it->second;
        it++;
        auto eit = m_map.find(end_search);
        eit++;
        while (it != eit) {
            if (it->second == prev) {
                auto dit = it;
                it++;
                m_map.erase(dit);
            } else {
                prev = it->second;
                it++;
            }
        }
    }



    // look-up of the value associated with key
    V const& operator[]( K const& key ) const {
        return ( --m_map.upper_bound(key) )->second;
    }

    void print() {
        for (auto it = m_map.begin(); it != m_map.end(); ++it) {
            std::cout << it->first << " " << it->second << "\n";
        }
    }
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.

int main (int argc, char *argv[]) {
    int value1 = 14;
    interval_map<int, int> imap_(value1);
    imap_.print();
    cout << "\n";
    imap_.assign(7, 10, 40);
    imap_.print();
    cout << "\n";
    imap_.assign(7, 10, 25);
    imap_.print();
    cout << "\n"; 
    imap_.assign(3, 5, 30);
    imap_.print();
    //cout << "\n";
    return 0;
}

