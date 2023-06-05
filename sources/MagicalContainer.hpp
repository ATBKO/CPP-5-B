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
            std::list<int> original_order;
            std::set<int> sorted;
            std::list<int> prime;
            std::list<int> cross;
            bool isPrime(int num);

        public:
            MagicalContainer();
            MagicalContainer(const MagicalContainer& other);
            MagicalContainer& operator=(MagicalContainer&&) = delete;
            MagicalContainer(MagicalContainer&&) = delete;
            MagicalContainer& operator=(const MagicalContainer&) = delete;
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
        PrimeIterator();
        PrimeIterator(MagicalContainer &container);
        PrimeIterator(const PrimeIterator& other);
        PrimeIterator& operator=(PrimeIterator&&) = delete;
        ~PrimeIterator() = default;
        PrimeIterator(PrimeIterator&&) = default;
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
            AscendingIterator();
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator& other);
            AscendingIterator& operator=(AscendingIterator&&) = delete;
            ~AscendingIterator() = default;
            AscendingIterator(AscendingIterator&&) = default;
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
            SideCrossIterator();
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator& other);
            SideCrossIterator& operator=(SideCrossIterator&&) = delete;
            ~SideCrossIterator() = default;
            SideCrossIterator(SideCrossIterator&&) = default;
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