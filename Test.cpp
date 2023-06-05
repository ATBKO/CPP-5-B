#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("Initialization MagicalContainer container") {
    MagicalContainer container;

    SUBCASE("One elements") {
        container.addElement(7);
        CHECK(container.size() == 1);
    }

    SUBCASE("Two elements") {
        container.addElement(5);
        container.addElement(15);
        CHECK(container.size() == 2);
    }

    SUBCASE("Removing an existing element") {
        container.addElement(10);
        container.addElement(20);
        CHECK_NOTHROW(container.removeElement(10));
        CHECK(container.size() == 1);
    }

    SUBCASE("Removing a non-existing element") {
        container.addElement(10);
        container.addElement(20);
        CHECK_THROWS_AS(container.removeElement(30), runtime_error);
        CHECK(container.size() == 2);
    }

}

TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(10);
    container.addElement(25);


    SUBCASE("Iterating over elements") {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 10);
        ++it;
        ++it;
        ++it;
        CHECK(*it == 25);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::AscendingIterator it(emptyContainer);
        CHECK(it == it.end());
    }
}

TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(30);
    container.addElement(40);

    SUBCASE("Iterating over elements") {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 40);
        ++it;
        CHECK(*it == 30);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::SideCrossIterator it(emptyContainer);
        CHECK(it == it.end());
    }
}

TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(5);
    container.addElement(6);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 5);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("Iterating over an empty container") {
        MagicalContainer emptyContainer;
        MagicalContainer::PrimeIterator it(emptyContainer);
        CHECK(it == it.end());
    }
}


TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(5);
    container.addElement(14);

    SUBCASE("Iterating in side-cross order from start to end") {
        MagicalContainer::SideCrossIterator it(container);

        CHECK(*it == 1);
        ++it;
        CHECK(*it == 14);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == it.end());
    }
}


TEST_CASE("Comparing PrimeIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);

        CHECK((it1 == it2));
        CHECK_FALSE((it1 != it2));
        CHECK_FALSE((it1 > it2));
        CHECK_FALSE((it1 < it2));

        ++it1;
        CHECK_FALSE((it1 == it2));
        CHECK((it1 != it2));
        CHECK_FALSE((it1 < it2));
        CHECK((it1 > it2));

        CHECK(it1 == it1.end());
        CHECK(it2 == it2.end());
    }
}


TEST_CASE("Comparing SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);

    SUBCASE("Comparing iterators after increments") {
        MagicalContainer::SideCrossIterator itStart1(container);
        MagicalContainer::SideCrossIterator itStart2(container);

        CHECK((itStart1 == itStart2));
        CHECK_FALSE((itStart1 != itStart2));
        CHECK_FALSE((itStart1 > itStart2));
        CHECK_FALSE((itStart1 < itStart2));

        ++itStart1;
        CHECK_FALSE((itStart1 == itStart2));
        CHECK((itStart1 != itStart2));
        CHECK_FALSE((itStart1 < itStart2));
        CHECK((itStart1 > itStart2));
    }
}
TEST_CASE("AscendingIterator with Negative and Positive Numbers") {
    MagicalContainer container;
    container.addElement(-3);
    container.addElement(5);
    container.addElement(-2);
    container.addElement(0);

    SUBCASE("Iterating over elements") {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == -3);
        ++it;
        CHECK(*it == -2);
        ++it;
        CHECK(*it == 0);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == it.end());
    }
}

TEST_CASE("PrimeIterator with No Prime Numbers") {
    MagicalContainer container;
    container.addElement(6);
    container.addElement(8);
    container.addElement(10);

    SUBCASE("Iterating over elements") {
        MagicalContainer::PrimeIterator it(container);

        CHECK(it == it.end());
        CHECK_THROWS_AS(++it, runtime_error);
    }
}

TEST_CASE("SideCrossIterator with Single Element") {
    MagicalContainer container;
    container.addElement(22);

    SUBCASE("Iterating over elements") {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 22);
        ++it;
        CHECK(it == it.end());
    }
}


