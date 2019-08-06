#ifndef DATA_GEOMETRY_H
#define DATA_GEOMETRY_H

struct Point {
	double x, y, z;
	Point() {}
	Point(double _x, double _y, double _z) {
		x = _x;
		y = _y;
		z = _z;

		//        printf("%lf, %lf, %lf", x, y, z);
	}
};

// 记录三角网格面，由三个顶点的索引号表示
struct Facet {
	int a, b, c;
	Facet() {}
	Facet(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
};

// 记录三角网格面，由三条边的索引号表示
struct FacetByEdge {
	int a, b, c;
	FacetByEdge() {}
	FacetByEdge(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
};

// 记录棱，由棱的两点的索引号表示
struct Edge {
	int a, b;
	Edge() {}
	Edge(int _a, int _b) {
		a = _a;
		b = _b;
	}
};

#endif // DATA_GEOMETRY_H
