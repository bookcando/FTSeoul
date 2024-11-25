#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
#include "PmergeMe.hpp"


static unsigned int power(unsigned int base, unsigned int exp) {
    unsigned int result = 1;
    for (unsigned int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

static std::list<unsigned int> genJacobsthalPermutation(unsigned int n) {
    std::list<unsigned int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    for (int i = 2; jacobsthal.back() < n; ++i) {
        jacobsthal.push_back(listAt(jacobsthal, i - 1) + 2 * listAt(jacobsthal, i - 2));
    }

    std::list<unsigned int> jacobsthalPermutation;
    if (n < jacobsthal.back()) {
        jacobsthal.back() = n;
    }
    int previousJacobsthal = 0;
    for (unsigned int i = 0; i < jacobsthal.size(); ++i) {
        for (int j = listAt(jacobsthal, i); j > previousJacobsthal; --j) {
            jacobsthalPermutation.push_back(j - 1);
        }
        previousJacobsthal = listAt(jacobsthal, i);
    }
    return jacobsthalPermutation;
}

static int binaryInsertLocation(const std::list< std::list<int> > &arr, int value, int right) {
    if (arr.size() == 0) {
        return 0;
    }
    int left = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (listAt(arr, mid).front() == value) {
            return mid;
        }
        else if (listAt(arr, mid).front() < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

static void makeGroup(std::list<int> &data, std::list<int> &temp, std::list<int> &residue, int group) {
    for (unsigned int i = 0; i < data.size(); i += 2 * group) {
        unsigned int left = i;
        unsigned int right = i + group;
        unsigned int leftEnd = right;
        unsigned int rightEnd = i + 2 * group;

        if (rightEnd > data.size()) {
            while (left < data.size()) {
                residue.push_back(listAt(data, left));
                left++;
            }
            break;
        }
        else if (listAt(data, left) > listAt(data, right)) {
            while (left < leftEnd) {
                temp.push_back(listAt(data, left));
                left++;
            }
            while (right < rightEnd) {
                temp.push_back(listAt(data, right));
                right++;
            }
        } 
        else {
            while (right < rightEnd) {
                temp.push_back(listAt(data, right));
                right++;
            }
            while (left < leftEnd) {
                temp.push_back(listAt(data, left));
                left++;
            }
        }
    }
}

static void splitBeforeInsert(std::list<int> &data, \
std::list< std::list<int> > &tempListA, \
std::list< std::list<int> > &tempListB, \
std::list<int> &residue, int group) {
    for (unsigned int i = 0; i < data.size(); i += 2 * group) {
        std::list<int> chunk;
        for (unsigned int j = i; j < i + group; j++) {
            if (j < data.size()) {
                chunk.push_back(listAt(data, j));
            }
        }
        tempListA.push_back(chunk);
        chunk.clear();
        for (unsigned int j = i + group; j < i + 2 * group; j++) {
            if (j < data.size()) {
                chunk.push_back(listAt(data, j));
            }
        }
        tempListB.push_back(chunk);
    }
    if (residue.size() > 0) {
        tempListB.push_back(residue);
    }
}

static void insertSort(std::list< std::list<int> > &tempList, \
std::list< std::list<int> > &tempListA, \
std::list< std::list<int> > &tempListB) {

    if (tempListA.size() == 0 || tempListB.size() == 0) {
        throw std::invalid_argument("Error: List: invalid input (empty list)");
    }

    std::list<unsigned int> jacobsthal = genJacobsthalPermutation(tempListB.size());

    tempList.push_back(listAt(tempListB, 0));
    tempList.push_back(listAt(tempListA, 0));
    unsigned int indexB = 2;
    unsigned int fixedRight;

    std::list<bool> insertedA(tempListB.size(), false);
    listAt(insertedA, 0) = true;
    for (unsigned int i = 1; i < jacobsthal.size(); ++i) {
        unsigned int index = listAt(jacobsthal, i);
        if (listAt(jacobsthal, i - 1) < listAt(jacobsthal, i)) {
            indexB *= 2;
            fixedRight = indexB - 1;
        }

        if (listAt(insertedA, index) == false) {
            for (unsigned int j = 0; j <= index; ++j) {
                if (j < tempListA.size() && listAt(insertedA, j) == false) {
                    tempList.push_back(listAt(tempListA, j));
                    listAt(insertedA, j) = true;
                }
            }
        }
        if (fixedRight >= tempList.size()) {
            fixedRight = tempList.size() - 1;
        }
        int insertLocation = binaryInsertLocation(tempList, listAt(listAt(tempListB, index), 0), fixedRight);
        std::list< std::list<int> >::iterator it = tempList.begin();
        std::advance(it, insertLocation);
        tempList.insert(it, listAt(tempListB, index));

        if (index < insertedA.size() && listAt(insertedA, index) == false && index < tempListA.size()) {
            tempList.push_back(listAt(tempListA, index));
            listAt(insertedA, index) = true;
        }
    }
}

void PmergeMe::listMergeInsertSort(std::list<int> &data, int depth) {
    unsigned int group = power(2, depth);
    unsigned int bunch = group * 2;
    if (bunch > data.size()) {
        return;
    }

    std::list<int> temp;
    std::list<int> residue;
    makeGroup(data, temp, residue, group);
    data = temp;

    listMergeInsertSort(data, depth + 1);

    std::list< std::list<int> > tempList;
    std::list< std::list<int> > tempListA;
    std::list< std::list<int> > tempListB;
    splitBeforeInsert(data, tempListA, tempListB, residue, group);
    insertSort(tempList, tempListA, tempListB);

    std::list<int> resolve;
    for (std::list< std::list<int> >::iterator it = tempList.begin(); it != tempList.end(); ++it) {
        for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            resolve.push_back(*it2);
        }
    }
    data = resolve;
}
