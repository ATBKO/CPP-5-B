#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <list>
#include <iterator>
#include <algorithm>
#include <set>
namespace ariel{
    class MagicalContainer{
        private:
            std::list<int> lst_original;
            std::set<int> set_sorted;
            std::list<int> lst_prime;
            std::list<int> lst_cross;
            bool isfront;
            void updatePrimeContainer();
            bool isPrime(int number);

        public:
            MagicalContainer();
            ~MagicalContainer();
            void addElement(int element);
            void removeElement(int element);
            int size() const;
            bool contains(int element);
    

    class PrimeIterator{
    private:
        std::list<int>::iterator iter;
        std::list<int>* prime_ptr;
    public:
        PrimeIterator(MagicalContainer &container);
        PrimeIterator& operator++();
        bool operator>(const PrimeIterator& other) const;
        bool operator<(const PrimeIterator& other) const;
        bool operator==(const PrimeIterator& other) const;
        bool operator!=(const PrimeIterator& other) const;
        int operator*() const;
        PrimeIterator begin() const;
        PrimeIterator end() const;
        PrimeIterator& operator=(const PrimeIterator& other);
    };

    class AscendingIterator{
        private:
            std::set<int>::iterator iter;
            std::set<int>* sorted_ptr; 
        public:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator& operator++();
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator begin() const;
            AscendingIterator end() const;
            AscendingIterator& operator=(const AscendingIterator& other);
    };

    class SideCrossIterator{
        private:
            std::list<int>::iterator iter;
            std::list<int>* cross_ptr;
        public:
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator& operator++();
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
            SideCrossIterator& operator=(const SideCrossIterator& other);
    };
    };
}
