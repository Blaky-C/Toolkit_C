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

// ��¼���������棬����������������ű�ʾ
struct Facet {
	int a, b, c;
	Facet() {}
	Facet(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
};

// ��¼���������棬�������ߵ������ű�ʾ
struct FacetByEdge {
	int a, b, c;
	FacetByEdge() {}
	FacetByEdge(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
};

// ��¼�⣬���������������ű�ʾ
struct Edge {
	int a, b;
	Edge() {}
	Edge(int _a, int _b) {
		a = _a;
		b = _b;
	}
};

#endif // DATA_GEOMETRY_H
