#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

typedef pair<double, double> coords;

double distance(coords p1, coords p2) {
    return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}

double find_min(const vector<coords>& points, int n) {
    double min_dist = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double a = distance(points[i], points[j]);
            if (a < min_dist) min_dist = a;
        }
    }

    return min_dist;
}

double strip_closest(vector<coords>& strip, int n, double d) { 
    double min_dist = d; 
 
    // sort with the 'y', second element in the pair
    sort(strip.begin(), strip.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && (strip[j].second - strip[i].second) < min_dist; ++j) {
            double a = distance(strip[i], strip[j]);
            if (a < min_dist) 
                min_dist = a;
        }
    }
 
    return min_dist; 
} 

double div_and_conq(vector<coords>& points, int n) {
    
    if (n <= 3) 
        return find_min(points, n);
  
    double mid = n / 2;
    coords point_mid = points[mid];

    vector<coords> dl(points.begin(), points.begin() + mid);
    vector<coords> dr(points.begin() + mid, points.end());

    double left = div_and_conq(dl, dl.size());
    double right = div_and_conq(dr, dr.size());

    double d = min(left, right);

    vector<coords> strip;

    for (int i = 0; i < n; i++) 
        if (abs(points[i].first - point_mid.first) < d) 
            strip.push_back(points[i]);

    return min(d, strip_closest(strip, strip.size(), d));
}

int main() {
    int n;
    cin >> n;

    vector<coords> points;

    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end()); 

    double res = div_and_conq(points, points.size());

    printf("%.2lf", res);

    return 0;
}
