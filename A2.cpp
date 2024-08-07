#include <iostream>
#include <algorithm>  // For std::swap

using namespace std;

struct Object {
    int profit;
    int weight;
    double ratio;
};

Object* object = nullptr; 
int M, n;

void getdata() { 
    cout << "Enter the number of objects: ";
    cin >> n;
    
    // Check if the number of objects is positive
    if (n <= 0) {
        cout << "Number of objects must be positive!" << endl;
        return;
    }
    
    object = new Object[n];
    
    for(int i = 0; i < n; i++) {
        cout << "Enter the profit for object " << i + 1 << ": ";
        cin >> object[i].profit;

        cout << "Enter the weight for object " << i + 1 << ": ";
        cin >> object[i].weight;

        // Ensure weight is positive
        if (object[i].weight <= 0) {
            cout << "Weight must be positive!" << endl;
            return;
        }
    }
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> M;

    // Ensure capacity is positive
    if (M <= 0) {
        cout << "Capacity must be positive!" << endl;
        return;
    }
}

// Function to calculate the ratio of profit to weight for each object
void calculateRatio(Object object[], int n) {
    for(int i = 0; i < n; i++) {
        object[i].ratio = static_cast<double>(object[i].profit) / object[i].weight;
    }
}

int partition(Object object[], int low, int high) {
    double pivot = object[high].ratio;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (object[j].ratio > pivot) {
            i++;
            swap(object[i], object[j]);
        }
    }

    swap(object[i + 1], object[high]);
    return i + 1;
}

void quickSort(Object object[], int low, int high) {
    if (low < high) {
        int pivot = partition(object, low, high);
        quickSort(object, low, pivot - 1);
        quickSort(object, pivot + 1, high);
    }
}

double fractionalKnapsack(Object object[], int n, int M) {
    calculateRatio(object, n);
    quickSort(object, 0, n - 1);

    double totalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (M >= object[i].weight) {
            M -= object[i].weight;
            totalProfit += object[i].profit;
        } else {
            double fraction = static_cast<double>(M) / object[i].weight;
            totalProfit += object[i].profit * fraction;
            break;
        }
    }

    return totalProfit;
}

int main() {
    getdata();
    
    if (object != nullptr) {
        double maxValue = fractionalKnapsack(object, n, M);
        cout << "Maximum value that can be put in the knapsack: " << maxValue << endl;
        delete[] object;
    }

    return 0;
}
