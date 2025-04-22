#include <bits/stdc++.h>
using namespace std;

class Point 
{ 
	public:
	int x, y; 
}; 

int compareX(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 


int compareY(const void* a, const void* b) 
{ 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 


float dist(Point p1, Point p2) 
{ 
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			); 
} 


float bruteForce(Point P[], int n, Point &p1, Point &p2) 
{ 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) {
				min = dist(P[i], P[j]); 
				p1 = P[i];
				p2 = P[j];
			}
	return min; 
} 


float min(float x, float y) 
{ 
	return (x < y)? x : y; 
} 


float stripClosest(Point strip[], int size, float d, Point &p1, Point &p2) 
{ 
	float min = d; 

	qsort(strip, size, sizeof(Point), compareY); 

	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) {
				min = dist(strip[i], strip[j]); 
				p1 = strip[i];
				p2 = strip[j];
			}

	return min; 
} 


float closestUtil(Point P[], int n, Point &p1, Point &p2) 
{ 
	
	if (n <= 3) 
		return bruteForce(P, n, p1, p2); 

	
	int mid = n/2; 
	Point midPoint = P[mid]; 


	Point pl1, pl2, pr1, pr2;
	float dl = closestUtil(P, mid, pl1, pl2); 
	float dr = closestUtil(P + mid, n - mid, pr1, pr2); 

	float d = min(dl, dr); 
	if (dl < dr) {
		p1 = pl1;
		p2 = pl2;
	} else {
		p1 = pr1;
		p2 = pr2;
	}

	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(P[i].x - midPoint.x) < d) 
			strip[j] = P[i], j++; 

	Point ps1, ps2;
	float strip_d = stripClosest(strip, j, d, ps1, ps2);
	if (strip_d < d) {
		p1 = ps1;
		p2 = ps2;
	}
	
	return min(d, strip_d); 
} 


float closest(Point P[], int n, Point &p1, Point &p2) 
{ 
	qsort(P, n, sizeof(Point), compareX); 

	
	return closestUtil(P, n, p1, p2); 
} 

// Driver code 
int main() 
{ 
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P) / sizeof(P[0]); 
	
	Point p1, p2;
	float min_dist = closest(P, n, p1, p2);
	cout << "The smallest distance is " << min_dist << endl;
	cout << "The closest points are: (" << p1.x << ", " << p1.y << ") and (" << p2.x << ", " << p2.y << ")" << endl;
	return 0; 
} 
