#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool func_aux(vector<int> &pages, int n, int m, int max_pages) {
    int students = 1;
    long current = 0;

    for (int i = 0; i < n; i++){

        if(pages[i] > max_pages) 
            return false;
        
        if(current + pages[i] > max_pages){
            students++;
            current = pages[i];

            if(students > m)
                return false;
            
        }else{
            current += pages[i];
        }
    }

    return true;
}

int find_min(vector<int>& pages, int n, int m) {

    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int result = high;

    while (low <= high){
        int mid = (high + low) / 2;

        if(func_aux(pages, n, m, mid)){
            result = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> pages(n);

    for(int i = 0; i < n; i++)
        cin >> pages[i];

    cout << find_min(pages, n, m) << endl;

    return 0;
}
