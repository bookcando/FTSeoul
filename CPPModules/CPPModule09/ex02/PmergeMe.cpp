#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _dataList(std::list<int>()), \
_dataVector(std::vector<int>()), \
_listStartTime(0), _listEndTime(0), \
_vectorStartTime(0), _vectorEndTime(0) {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    _listStartTime = 0;
    _listEndTime = 0;
    _vectorStartTime = 0;
    _vectorEndTime = 0;
    (void)copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    _listStartTime = 0;
    _listEndTime = 0;
    _vectorStartTime = 0;
    _vectorEndTime = 0;
    (void)copy;
    return *this;
}

long long PmergeMe::getTime(void)
{
	timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void PmergeMe::parseInput(const char *argv[]) {
    int n = 0;
    int index = 1;
    while (argv[index] != NULL) {
        std::stringstream ss(argv[index]);
        ss >> n;
        if (ss.fail()) {
            throw std::invalid_argument("Error: invalid input (non-integer or integer overflow)");
        }
        if (n <= 0) {
            throw std::invalid_argument("Error: invalid input (none positive int)");
        }
        if (ss.eof() == false) {
            throw std::invalid_argument("Error: invalid input (none int)");
        }
        _dataList.push_back(n);
        _dataVector.push_back(n);
        index++;
    }
    if (_dataList.size() == 0 || _dataVector.size() == 0) {
        throw std::invalid_argument("Error: input required");
    }
}

void PmergeMe::printVectorData(const std::string &string) {
    if (string.size() > 0) {
        std::cout << string;
    }
    for (std::vector<int>::iterator it = _dataVector.begin(); it != _dataVector.end(); ++it) {
        std::cout << *it;
        if (it + 1 != _dataVector.end()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void PmergeMe::printListData(const std::string &string) {
    if (string.size() > 0) {
        std::cout << string;
    }
    for (std::list<int>::iterator it = _dataList.begin(); it != _dataList.end(); ++it) {
        std::cout << *it;
        if (it != --_dataList.end()) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void PmergeMe::sortData() {
    _listStartTime = getTime();
    listMergeInsertSort(_dataList);
    _listEndTime = getTime();
    _vectorStartTime = getTime();
    vectorMergeInsertSort(_dataVector);
    _vectorEndTime = getTime();
}

bool PmergeMe::checkSorted() {
    std::vector<int>::iterator it1 = _dataVector.begin();
    std::list<int>::iterator it2 = _dataList.begin();

    while (it1 != _dataVector.end() && it2 != _dataList.end()) {
        if (*it1 != *it2) {
            return false;
        }
        ++it1;
        ++it2;
    }
    if (it1 != _dataVector.end() || it2 != _dataList.end()) {
        return false;
    }
    return true;
}

void PmergeMe::printResults() {
    std::cout << "Time to process a range of " << _dataList.size() << " elements with std::list   : " << _listEndTime - _listStartTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _dataVector.size() << " elements with std::vector : " << _vectorEndTime - _vectorStartTime << " us" << std::endl;
}
