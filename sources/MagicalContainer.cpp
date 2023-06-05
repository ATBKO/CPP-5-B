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
    MagicalContainer::MagicalContainer(){
        this->isfront = true;
    }

    MagicalContainer::~MagicalContainer(){
        this->lst_original.clear();
        this->set_sorted.clear();
        this->lst_prime.clear();
        this->lst_cross.clear();
    }

    void MagicalContainer::addElement(int element){
    }

    void MagicalContainer::removeElement(int element){
    }

    int MagicalContainer::size() const{
        return this->lst_original.size();
    }

    bool MagicalContainer::contains(int element){
        return this->set_sorted.contains(element);
    }

    void MagicalContainer::updatePrimeContainer(){
    }

    bool MagicalContainer::isPrime(int num){
        return true;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container){
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const{
        return this->iter == other.iter;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const{
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const{
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const{
        return false;
    }

    int MagicalContainer::PrimeIterator::operator*() const{
        return 0;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const{
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const{
        MagicalContainer container;
        MagicalContainer::PrimeIterator ans(container);
        return ans;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other){
        return *this;
    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container){
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const{
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const{
        return false;
    }

    int MagicalContainer::AscendingIterator::operator*() const{
        return 0;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const{
        MagicalContainer container;
        AscendingIterator ans(container);
        return ans;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other){
        return *this;
    }

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container){
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return false;
    }

    int MagicalContainer::SideCrossIterator::operator*() const{
        return 0;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const{
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const{
        MagicalContainer container;
        MagicalContainer::SideCrossIterator ans(container);
        return ans;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other){
        return *this;
    }
}