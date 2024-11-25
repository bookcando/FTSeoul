#include <iostream>
#include <string>
#include <vector>
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

static std::vector<unsigned int> genJacobsthalPermutation(unsigned int n) {
    std::vector<unsigned int> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    for (int i = 2; jacobsthal.back() < n; ++i) {
        jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
    }

    std::vector<unsigned int> jacobsthalPermutation;
    if (n < jacobsthal.back()) {
        jacobsthal.back() = n;
    }
    int previousJacobsthal = 0;
    for (unsigned int i = 0; i < jacobsthal.size(); ++i) {
        for (int j = jacobsthal[i]; j > previousJacobsthal; --j) {
            jacobsthalPermutation.push_back(j - 1);
        }
        previousJacobsthal = jacobsthal[i];
    }
    return jacobsthalPermutation;
}

static int binaryInsertLocation(const std::vector< std::vector<int> > &arr, int value, int right) {
    if (arr.size() == 0) {
        return 0;
    }
    int left = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid][0] == value) {
            return mid;
        } else if (arr[mid][0] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

static void makeGroup(std::vector<int> &data, std::vector<int> &temp, std::vector<int> &residue, int group) {
    for (unsigned int i = 0; i < data.size(); i += 2 * group) {
        unsigned int left = i;
        unsigned int right = i + group;
        unsigned int leftEnd = right;
        unsigned int rightEnd = i + 2 * group;

        if (rightEnd > data.size()) {
            while (left < data.size()) {
                residue.push_back(data[left]);
                left++;
            }
            break;
        }
        else if (data[left] > data[right]) {
            while (left < leftEnd) {
                temp.push_back(data[left]);
                left++;
            }
            while (right < rightEnd) {
                temp.push_back(data[right]);
                right++;
            }
        } 
        else {
            while (right < rightEnd) {
                temp.push_back(data[right]);
                right++;
            }
            while (left < leftEnd) {
                temp.push_back(data[left]);
                left++;
            }
        }
    }
}

static void splitBeforeInsert(std::vector<int> &data, \
std::vector< std::vector<int> > &tempVectorA, \
std::vector< std::vector<int> > &tempVectorB, \
std::vector<int> &residue, int group) {
    for (unsigned int i = 0; i < data.size(); i += 2 * group) {
        std::vector<int> chunk;
        for (unsigned int j = i; j < i + group; j++) {
            if (j < data.size()) {
                chunk.push_back(data[j]);
            }
        }
        tempVectorA.push_back(chunk);
        chunk.clear();
        for (unsigned int j = i + group; j < i + 2 * group; j++) {
            if (j < data.size()) {
                chunk.push_back(data[j]);
            }
        }
        tempVectorB.push_back(chunk);
    }
    if (residue.size() > 0) {
        tempVectorB.push_back(residue);
    }
}

static void insertSort(std::vector< std::vector<int> > &tempVector, \
std::vector< std::vector<int> > &tempVectorA, \
std::vector< std::vector<int> > &tempVectorB) {

    if (tempVectorA.size() == 0 || tempVectorB.size() == 0) {
        throw std::invalid_argument("Error: Vector: invalid input (empty vector)");
    }

    std::vector<unsigned int> jacobsthal = genJacobsthalPermutation(tempVectorB.size());

    tempVector.push_back(tempVectorB[0]);
    tempVector.push_back(tempVectorA[0]);
    unsigned int indexB = 2;
    unsigned int fixedRight;

    std::vector<bool> insertedA(tempVectorB.size(), false);
    insertedA[0] = true;
    for (unsigned int i = 1; i < jacobsthal.size(); ++i) {
        unsigned int index = jacobsthal[i];
        if (jacobsthal[i - 1] < jacobsthal[i]) {
            indexB *= 2;
            fixedRight = indexB - 1;
        }

        if (insertedA[index] == false) {
            for (unsigned int j = 0; j <= index; ++j) {
                if (j < tempVectorA.size() && insertedA[j] == false) {
                    tempVector.push_back(tempVectorA[j]);
                    insertedA[j] = true;
                }
            }
        }
        if (fixedRight >= tempVector.size()) {
            fixedRight = tempVector.size() - 1;
        }
        int insertLocation = binaryInsertLocation(tempVector, tempVectorB[index][0], fixedRight);
        tempVector.insert(tempVector.begin() + insertLocation, tempVectorB[index]);
        if (index < insertedA.size() && insertedA[index] == false && index < tempVectorA.size()) {
            tempVector.push_back(tempVectorA[index]);
            insertedA[index] = true;
        }
    }
}

void PmergeMe::vectorMergeInsertSort(std::vector<int> &data, int depth) {
    unsigned int group = power(2, depth);
    unsigned int bunch = group * 2;
    if (bunch > data.size()) {
        return;
    }

    std::vector<int> temp;
    std::vector<int> residue;
    makeGroup(data, temp, residue, group);

    data = temp;
    vectorMergeInsertSort(data, depth + 1);

    std::vector< std::vector<int> > tempVector;
    std::vector< std::vector<int> > tempVectorA;
    std::vector< std::vector<int> > tempVectorB;
    splitBeforeInsert(data, tempVectorA, tempVectorB, residue, group);
    insertSort(tempVector, tempVectorA, tempVectorB);
    std::vector<int> resolve;
    for (std::vector< std::vector<int> >::iterator it = tempVector.begin(); it != tempVector.end(); ++it) {
        for (std::vector<int>::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            resolve.push_back(*it2);
        }
    }
    data = resolve;
}
