#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <sstream>

#include <sys/time.h>
typedef struct timeval timeval;
class PmergeMe {
    private:
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

        std::list<int> _dataList;
        std::vector<int> _dataVector;
        long long _listStartTime;
        long long _listEndTime;
        long long _vectorStartTime;
        long long _vectorEndTime;

        void vectorMergeInsertSort(std::vector<int> &data, int depth = 0);
        void listMergeInsertSort(std::list<int> &data, int depth = 0);

        long long getTime(void);

    public:
        PmergeMe();
        ~PmergeMe();
        void parseInput(const char *argv[]);
        void printVectorData(const std::string &string);
        void printListData(const std::string &string);
        void sortData();
        void printResults();

        bool checkSorted();
};

template <typename T>
static T &listAt(std::list<T> &lst, unsigned int index) {
    if (lst.size() <= index) {
        throw std::out_of_range("Error: listAt: index out of range");
    }
    typename std::list<T>::iterator it = lst.begin();
    std::advance(it, index);
    if (it == lst.end()) {
        throw std::out_of_range("Error: listAt: index out of range");
    }
    return *it;
}

template <typename T>
static const T &listAt(const std::list<T> &lst, unsigned int index) {
    if (lst.size() <= index) {
        throw std::out_of_range("Error: listAt: index out of range");
    }
    typename std::list<T>::const_iterator it = lst.begin();
    std::advance(it, index);
    if (it == lst.end()) {
        throw std::out_of_range("Error: listAt: index out of range");
    }
    return *it;
}

#endif