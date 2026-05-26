#include "PmergeMe.hpp"

bool	ListSorted(std::list<int> list) {
    if (list.size() <= 1)
        return true;

    std::list<int>::iterator it = list.begin();
    int prev = *it;
    ++it;

    while (it != list.end()) {

        if (*it <= prev)
            return false;
        prev = *it;
        ++it;
    }
    return true;
}

bool	VectorSorted(std::vector<int> vector) {
    if (vector.size() <= 1)
        return true;

    std::vector<int>::iterator it = vector.begin();
    int prev = *it;
    ++it;

    while (it != vector.end()) {

        if (*it <= prev)
            return false;
        prev = *it;
        ++it;
    }
    return true;
}

int getJacob(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (getJacob(n - 1) + 2 * getJacob(n - 2));
}

void	sortList( std::list<int> &list ) {

	if (list.size() < 2)
		return;
	
	std::list<int>::iterator	itlst = list.begin();
	std::list< std::pair<int, int> > pairs;
	bool	is_odd = false;
	int		odd;

	while ( itlst != list.end() ) {

		int	first = *itlst;
		if (++itlst == list.end()) {
			is_odd = true;
			odd = first;
		}
		else {
			if (*itlst > first)
				pairs.push_back(std::make_pair(first, *itlst));
			else
				pairs.push_back(std::make_pair(*itlst, first));
			itlst++;
		}
	}

	std::list<int>	main;

	for (std::list< std::pair<int, int> >::iterator	it = pairs.begin(); it != pairs.end(); it++)
		main.push_back(it->second);

	sortList(main);

	std::list<std::pair<int, int> > sorted_pairs;
    for (std::list<int>::iterator main_it = main.begin(); main_it != main.end(); ++main_it) {
        for (std::list<std::pair<int, int> >::iterator pend_it = pairs.begin(); pend_it != pairs.end(); ++pend_it) {
            if (pend_it->second == *main_it) {
                sorted_pairs.push_back(*pend_it);
                break;
            }
        }
    }
    pairs = sorted_pairs;

	int	main_size = static_cast<int>(main.size());
	int	fmain = main.front();
	for (std::list< std::pair<int, int> >::iterator	it = pairs.begin(); it != pairs.end(); it++) {

		if (fmain == it->second)
			main.push_front(it->first);
	}

	int	n = 3;
	int	jacob = 3;
	int	prev_jacob = 1;

	while (jacob <= main_size) {

		std::list< std::pair<int, int> >::iterator	itp = pairs.begin();
		std::advance(itp, jacob - 1);
		for (int i = 0; i < (jacob - prev_jacob); i++) {

			std::list<int>::iterator	itm = std::lower_bound(main.begin(), main.end(), itp->first);
			main.insert(itm, itp->first);
			itp--;
		}
		prev_jacob = jacob;
		jacob = getJacob(++n);
	}

	if (prev_jacob < main_size) {

		std::list< std::pair<int, int> >::iterator	itp = pairs.begin();
		std::advance(itp, main_size - 1);
		for (int i = 0; i < (main_size - prev_jacob); i++) {

			std::list<int>::iterator	itm = std::lower_bound(main.begin(), main.end(), itp->first);
			main.insert(itm, itp->first);
			itp--;
		}
	}

	if (is_odd) {

		std::list<int>::iterator	itm = std::lower_bound(main.begin(), main.end(), odd);
		main.insert(itm, odd);
	}

	list = main;
}

void	sortVector( std::vector<int> &vector ) {

	if (vector.size() < 2)
		return;
	
	std::vector<int>::iterator	itvct = vector.begin();
	std::vector< std::pair<int, int> > pairs;
	bool	is_odd = false;
	int		odd;

	while ( itvct != vector.end() ) {

		int	first = *itvct;
		if (++itvct == vector.end()) {
			is_odd = true;
			odd = first;
		}
		else {
			if (*itvct > first)
				pairs.push_back(std::make_pair(first, *itvct));
			else
				pairs.push_back(std::make_pair(*itvct, first));
			itvct++;
		}
	}

	std::vector<int>	main;

	for (std::vector< std::pair<int, int> >::iterator	it = pairs.begin(); it != pairs.end(); it++)
		main.push_back(it->second);

	sortVector(main);

	std::vector<std::pair<int, int> > sorted_pairs;
    for (std::vector<int>::iterator main_it = main.begin(); main_it != main.end(); ++main_it) {
        for (std::vector<std::pair<int, int> >::iterator pend_it = pairs.begin(); pend_it != pairs.end(); ++pend_it) {
            if (pend_it->second == *main_it) {
                sorted_pairs.push_back(*pend_it);
                break;
            }
        }
    }
    pairs = sorted_pairs;

	int	main_size = static_cast<int>(main.size());
	int	fmain = main.front();
	for (std::vector< std::pair<int, int> >::iterator	it = pairs.begin(); it != pairs.end(); it++) {

		if (fmain == it->second)
			main.insert(main.begin(), it->first);
	}

	int	n = 3;
	int	jacob = 3;
	int	prev_jacob = 1;

	while (jacob <= main_size) {

		std::vector< std::pair<int, int> >::iterator	itp = pairs.begin();
		std::advance(itp, jacob - 1);
		for (int i = 0; i < (jacob - prev_jacob); i++) {

			std::vector<int>::iterator	itm = std::lower_bound(main.begin(), main.end(), itp->first);
			main.insert(itm, itp->first);
			itp--;
		}
		prev_jacob = jacob;
		jacob = getJacob(++n);
	}

	if (prev_jacob < main_size) {

		std::vector< std::pair<int, int> >::iterator	itp = pairs.begin();
		std::advance(itp, main_size - 1);
		for (int i = 0; i < (main_size - prev_jacob); i++) {

			std::vector<int>::iterator	itm = std::lower_bound(main.begin(), main.end(), itp->first);
			main.insert(itm, itp->first);
			itp--;
		}
	}

	if (is_odd) {

		std::vector<int>::iterator	itm = std::lower_bound(main.begin(), main.end(), odd);
		main.insert(itm, odd);
	}

	vector = main;
}

int main(int argc, char const *argv[]) {

	try {

		PmergeMe	pmm;
		pmm.Parsing(argc, argv);

		timeval tim;
    	
		{
			std::list<int>	lst;

			std::cout << "Before:";
			pmm.PrintList();
			// std::cout << ListSorted(pmm.getList()) << std::endl;
			gettimeofday(&tim,NULL);
			double t1 = tim.tv_usec;
			lst = pmm.getList();
			sortList(lst);
			pmm.setList(lst);
			gettimeofday(&tim,NULL);
    		double t2 = tim.tv_usec;
			std::cout << "After:";
			pmm.PrintList();
			std::cout << "Time to process a range of " << pmm.getList().size() << " elements with std::list: " << t2-t1 << " microseconds" << std::endl;
			// std::cout << ListSorted(pmm.getList()) << std::endl;
		}
	
		{
			std::vector<int>	vct;

			// pmm.PrintVector();
			// std::cout << VectorSorted(pmm.getVector()) << std::endl;
			gettimeofday(&tim,NULL);
    		double t1 = tim.tv_usec;
			vct = pmm.getVector();
			sortVector(vct);
			pmm.setVector(vct);
			gettimeofday(&tim,NULL);
    		double t2 = tim.tv_usec;
			std::cout << "Time to process a range of " << pmm.getList().size() << " elements with std::vector: " << t2-t1 << " microseconds" << std::endl;
			// pmm.PrintVector();
			// std::cout << VectorSorted(pmm.getVector()) << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
