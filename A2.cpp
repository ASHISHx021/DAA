#include <iostream>

using namespace std;


struct Object {

int profit;
int weight;
double ratio;
};
int M;int n;

void getdata()
{ 

   cout<<"Enter the No of Objects:-";
   cin>>n;
   
  object  = new Object[n];
   
  for(int i = 0; i<n; i++)
    {
      cout<<"Enter the profits: ";
      cin>>object[i].profit;
 
     cout<<"Enter the Weights: ";
     cin>>object[i].weight;

     }
  cout<<"Enter the capacity of Knapsack: ";
  cin>>M;
}

// Function to calculate the ratio of profit to weight for each object

void calculateRatio(Object object[], int n) 
{
  for(int i = 0; i < n; i++){
    object[i].ratio = object[i].profit / object[i].weight;
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

void quickSort(Object object[], int low, int high) 
{
    if (low < high) {
        int pivot = partition(object, low, high);

        quickSort(object, low, pivot - 1);
        quickSort(object, pivot + 1, high);
    }
}

double fractionalKnapsack(Object object[], int n, int M) 
{
    
    calculateRatio(object, n);
    quickSort(object, 0, n - 1);

    double totalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (M >= object[i].weight) {
        
            M -= object[i].weight;
            totalProfit += object[i].profit;
        } 
        else {
            double fraction = M / object[i].weight;
            totalProfit += object[i].profit * fraction;
            break;
        }
    }

    return totalProfit;
}

int main()
{
 getdata();
 
 double maxValue = fractionalKnapsack(object, n, M);

    cout << "Maximum value that can be put in the knapsack: " << maxValue << endl;

    delete[] Object;

    return 0;
}


/*
#include <iostream>

using namespace std;

struct Object {
    int profit;
    int weight;
    double ratio;
};

// Change 1: Passed object, n, and M by reference to the getdata function
// This is because we want to modify these variables inside the function and have the changes reflected outside
void getdata(Object*& object, int& n, int& M) {
    cout << "Enter the No of Objects: ";
    cin >> n;

    // Change 2: Declared object as a pointer to Object and initialized it with new Object[n]
    // This is because we want to dynamically allocate memory for the object array
    object = new Object[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the profits: ";
        cin >> object[i].profit;

        cout << "Enter the Weights: ";
        cin >> object[i].weight;
    }

    cout << "Enter the capacity of Knapsack: ";
    cin >> M;
}

void calculateRatio(Object object[], int n) {
    for (int i = 0; i < n; i++) {
        // Change 3: Casted one of the operands to double to perform floating-point division
        // This is because we want to get a decimal result for the ratio
        object[i].ratio = (double)object[i].profit / object[i].weight;
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
            // Change 4: Casted one of the operands to double to perform floating-point division
            // This is because we want to get a decimal result for the fraction
            double fraction = (double)M / object[i].weight;
            totalProfit += object[i].profit * fraction;
            break;
        }
    }

    return totalProfit;
}

int main() {
    // Change 5: Declared object as a pointer to Object
    // This is because we want to dynamically allocate memory for the object array
    Object* object;
    int n, M;

    getdata(object, n, M);

    double maxValue = fractionalKnapsack(object, n, M);

    cout << "Maximum value that can be put in the knapsack: " << maxValue << endl;

    // Change 6: Deleted the object array to free up memory
    // This is because we want to prevent memory leaks
    delete[] object;

    return 0;
}
*/






