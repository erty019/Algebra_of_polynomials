#pragma once
struct TMonom
{
	double coef; // коэффициент монома
	int index; // индекс (свертка степеней)


	TMonom() {
		coef = 0;
		index = 0;
	}

	TMonom(double cval, int degX, int degY, int degZ) {
		coef = cval;
		index = degX + degY * 10 + degZ * 100;
	}

	void SetCoef(int cval) { coef = cval; }
	int GetCoef(void) { return coef; }

	void SetIndex(int ival) { index = ival; }
	int GetIndex(void) { return index; }


	bool operator==(const TMonom& other) { return (index == other.index); }
	
	bool operator>(const TMonom& other) { return (index > other.index); }

	bool operator<(const TMonom& other) { return (index < other.index); }


};