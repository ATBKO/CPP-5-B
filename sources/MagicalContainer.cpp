#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <list>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <set>
#include "MagicalContainer.hpp"
namespace ariel{
    MagicalContainer::MagicalContainer(){}

    MagicalContainer::MagicalContainer(const MagicalContainer& other){}

    MagicalContainer::~MagicalContainer(){
        this->original_order.clear();
        this->sorted.clear();
        this->prime.clear();
        this->cross.clear();
    }

    void MagicalContainer::addElement(int element){
        this->original_order.push_back(element);
        this->sorted.insert(element);
        if (isPrime(element)){
            this->prime.push_back(element);
        }

        std::list<int>::iterator it = this->original_order.begin();
        std::list<int>::reverse_iterator rit = this->original_order.rbegin();
        this->cross.clear();
        for(size_t i = 0; i < this->original_order.size()/2; ++i){
            this->cross.push_back(*it++);
            this->cross.push_back(*rit++);
        }

        if(this->original_order.size() % 2 == 1) {
            this->cross.push_back(*it);
        }
    }


    void MagicalContainer::removeElement(int element){
        int tmp = this->sorted.count(element);
        if(tmp == 0){
            throw std::runtime_error("Element does not exist");
        }
        this->original_order.remove(element);
        this->sorted.erase(element);
        this->prime.remove(element);
        this->cross.remove(element);
    }

    int MagicalContainer::size() const{
        return this->original_order.size();
    }

    bool MagicalContainer::contains(int element){
        return this->sorted.contains(element);
    }


    bool MagicalContainer::isPrime(int num){
        if (num <= 1 || (num != 2 && num % 2 == 0)){
            return false;
        }
        int sqr = std::sqrt(num);
        for (int i = 2; i <= sqr; i++){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }

    /**
     * PrimeIterator Section:
     * Constructor with the begin pointer.
     * Copy Constructor with the pointer.
     * All the operators, ++, *, ==, =, <, >, !=.
     */

    MagicalContainer::PrimeIterator::PrimeIterator(){
        this->iter = this->prime_ptr->begin();
    }

    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other){
        this->iter = other.iter;
        this->prime_ptr = other.prime_ptr;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container){
        this->iter = container.prime.begin();
        this->prime_ptr = &container.prime;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        if(this->iter == this->prime_ptr->end()){
            throw std::runtime_error("Iterator is at the end");
        }
        this->iter++;
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        if(this->prime_ptr != other.prime_ptr){
            throw std::invalid_argument("Not the same container");
        }
        if(this->prime_ptr->size() == 0){
            return true;
        }
        return std::distance(this->prime_ptr->begin(), this->iter) == std::distance(other.prime_ptr->begin(), other.iter);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        return std::distance(this->prime_ptr->begin(), this->iter) > std::distance(other.prime_ptr->begin(), other.iter);;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        return std::distance(this->prime_ptr->begin(), this->iter) < std::distance(other.prime_ptr->begin(), other.iter);
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
        return std::distance(this->prime_ptr->begin(), this->iter) != std::distance(other.prime_ptr->begin(), other.iter);
    }

    int MagicalContainer::PrimeIterator::operator*() const{
        return *(this->iter);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        MagicalContainer::PrimeIterator ans(*this);
        ans.iter = this->prime_ptr->begin();
        return ans;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
        MagicalContainer::PrimeIterator ans(*this);
        ans.iter = this->prime_ptr->end();
        return ans;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        if(this->prime_ptr != other.prime_ptr){
            throw std::runtime_error("different container");
        }
        return *this;
    }

    /**
     * AscendingIterator Section:
     * Constructor with the begin pointer.
     * Copy Constructor with the pointer.
     * All the operators, ++, *, ==, =, <, >, !=.
     */

    MagicalContainer::AscendingIterator::AscendingIterator(){
        this->iter = this->sorted_ptr->begin();
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container){
        this->iter = container.sorted.begin();
        this->sorted_ptr = &container.sorted;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other){ // copy
        this->iter = other.iter;
        this->sorted_ptr = other.sorted_ptr;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        if(this->iter == this->sorted_ptr->end()){
            throw std::runtime_error("Iterator is at the end");
        }
        this->iter++;
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return std::distance(this->sorted_ptr->begin(), this->iter) == std::distance(other.sorted_ptr->begin(), other.iter);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        return std::distance(this->sorted_ptr->begin(), this->iter) > std::distance(other.sorted_ptr->begin(), other.iter);;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        return std::distance(this->sorted_ptr->begin(), this->iter) < std::distance(other.sorted_ptr->begin(), other.iter);
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
        return std::distance(this->sorted_ptr->begin(), this->iter) != std::distance(other.sorted_ptr->begin(), other.iter);
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return *(this->iter);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        MagicalContainer::AscendingIterator ans(*this);
        ans.iter = this->sorted_ptr->begin();
        return ans;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        MagicalContainer::AscendingIterator ans(*this);
        ans.iter = this->sorted_ptr->end();
        return ans;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        if(this->sorted_ptr != other.sorted_ptr){
            throw std::runtime_error("different containers");
        }
        return *this;
    }

    /**
     * SideCrossIterator Section:
     * Constructor with the begin pointer.
     * Copy Constructor with the pointer.
     * All the operators, ++, *, ==, =, <, >, !=.
     */

    MagicalContainer::SideCrossIterator::SideCrossIterator(){
        this->iter = this->cross_ptr->begin();
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container){
        this->iter = container.cross.begin();
        this->cross_ptr = &container.cross;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other){
        this->iter = other.iter;
        this->cross_ptr = other.cross_ptr;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        if(this->iter == this->cross_ptr->end()){
            throw std::runtime_error("Iterator is at the end");
        }
        this->iter++;
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return std::distance(this->cross_ptr->begin(), this->iter) == std::distance(other.cross_ptr->begin(), other.iter);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        return std::distance(this->cross_ptr->begin(), this->iter) > std::distance(other.cross_ptr->begin(), other.iter);
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return std::distance(this->cross_ptr->begin(), this->iter) < std::distance(other.cross_ptr->begin(), other.iter);
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return std::distance(this->cross_ptr->begin(), this->iter) != std::distance(other.cross_ptr->begin(), other.iter);
    }

    int MagicalContainer::SideCrossIterator::operator*() const{
        return *(this->iter);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
        MagicalContainer::SideCrossIterator ans(*this);
        ans.iter = this->cross_ptr->begin();
        return ans;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
        MagicalContainer::SideCrossIterator ans(*this);
        ans.iter = this->cross_ptr->end();
        return ans;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        if(this->cross_ptr != other.cross_ptr){
            throw std::runtime_error("different containers");
        }
        return *this;
    }
}