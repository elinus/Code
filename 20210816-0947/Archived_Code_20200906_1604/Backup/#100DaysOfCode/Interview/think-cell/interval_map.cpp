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
void assign(K const & keyBegin, K const & keyEnd, V const & val) {
        if (!(keyBegin < keyEnd)) return;

		using iterator_t = typename std::map<K, V>::iterator;

		iterator_t lower_bound_begin = m_map.lower_bound(keyBegin); 
		iterator_t upper_bound_begin = m_map.upper_bound(keyBegin);
		iterator_t lower_bound_end = m_map.lower_bound(keyEnd);
		iterator_t upper_bound_end = m_map.upper_bound(keyEnd);
		iterator_t it_delete_begin, it_delete_end;
		K key_begin_search, key_end_search;
		
        it_delete_begin = lower_bound_begin; 
        key_begin_search = lower_bound_begin->first; 
		
        if (--lower_bound_begin != m_map.end()) {
			key_begin_search = lower_bound_begin->first;
		}
		if (lower_bound_end == upper_bound_end) 
			--lower_bound_end;
		it_delete_end = lower_bound_end;
		
        V tail = it_delete_end->second; 
		key_end_search = lower_bound_end->first;

		m_map.erase(it_delete_begin, ++it_delete_end);

		m_map.insert(std::begin(m_map), std::make_pair(keyBegin, val));
		m_map.insert(std::begin(m_map), std::make_pair(keyEnd, tail));

		iterator_t it = m_map.find(key_begin_search); 
		V prev = it->second;
		it++;
		iterator_t it_end = m_map.find(key_end_search);
		it_end++;
		while (it != it_end) {
			if (it->second == prev) {
				iterator_t it_del = it;
				it++;
				m_map.erase(it_del);
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

