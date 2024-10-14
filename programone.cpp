#include <iostream>
#include <vector>
#include <algorithm>

void displaySet(std::vector<int>& set){
	for(int i = 0; i < set.size(); i++){
		std::cout << set[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int> unionSet(std::vector<int>& a, std::vector<int>& b){
	std::vector<int> result = a;	
	for (int i = 0; i < b.size(); i++) {
        	if (std::find(result.begin(), result.end(), b[i]) == result.end()) {
            		result.push_back(b[i]);
        }
    }
	return result;
} 

std::vector<int> intersectSet(std::vector<int>& a, std::vector<int>& b){
	std::vector<int> result;
	for (int i = 0; i < a.size(); i++) {
		if (std::find(b.begin(), b.end(), a[i]) != b.end()) {
			if (std::find(result.begin(), result.end(), a[i]) == result.end()) {
				result.push_back(a[i]);
			}
		}
	}
	return result;
}

std::vector<int> differenceSet(std::vector<int>& a, std::vector<int>& b) {
	std::vector<int> result;
	for (int i = 0; i < a.size(); i++) {
		if (std::find(b.begin(), b.end(), a[i]) == b.end()) {
            		result.push_back(a[i]);
       		}
	}
	return result;
}

int main() {

	std::vector<int> a = {1, 3, 5, 6, 8};
	std::vector<int> b = {2, 3, 4, 7, 9};

	std::vector<int> unionResult = unionSet(a, b);
	std::cout << "Union Set: ";
	displaySet(unionResult);

	std::vector<int> intersectResult = intersectSet(a, b);
	std::cout << "Intersection Set: "; 
	displaySet(intersectResult);

	std::vector<int> differenceResult = differenceSet(a, b);
	std::cout << "Difference Set: ";
	displaySet(differenceResult);

	return 0;
}
