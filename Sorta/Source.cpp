#include<iostream>
#include<ctime>
#include<algorithm>
#include<cmath>

#define voila(b) for(auto&y:b){std::cout<<y<<' ';}

void QS(int* mass, int pr, int dr) {
	int i = pr, j = dr, m = mass[(pr + dr) / 2];
	do {
		while (mass[i] < m)++i;
		while (mass[j] > m)--j;
		if (i <= j) {
			if (mass[i] > mass[j])std::swap(mass[i], mass[j]); ++i; --j;
		}
	} while (i <= j);
	if (i < dr)QS(mass, i, dr);
	if (pr < j)QS(mass, pr, j);
}
void binarka(int* mass, int l, int r, int k) {
	int mid; bool fla = false;
	while ((l <= r) && (fla != true)) {
		mid = (l + r) / 2;
		if (mass[mid] == k)fla = true;
		if (mass[mid] > k)r = mid - 1;
		else l = mid + 1;
	}
	if (fla)std::cout << "Значение " << k << " позиция " << mid << '\n';
	else { std::cout << "\n нет значения \n"; }
}
void Shell(int* mass, int n) {
	int d = n/2;
	while (d > 0) {
		for (int i = 0; i < n - d; ++i) {
			int j = i;
			while (j >= 0 && mass[j] > mass[j + d]) {
				int cou = mass[j];
				mass[j] = mass[j + d];
				mass[j + d] = cou;
				--j;
			}
		}d /= 2;
	}

}

void Gnomesort(int n, int* mass) {
	int i = 1, j = 2;
	while (i < n) {
		if (i==0||mass[i - 1] <= mass[i]) { i = j; ++j; }
		else {
			std::swap(mass[i - 1], mass[i]);
			--i;
		}
	}
}

void heapify(int* mass, int n,int i) {
	int larg = i;
	int g = 2 * i + 1;
	int d = 2 * i + 2;
	if (g<n && mass[g]>mass[larg]) { larg = g; }
	if (d<n && mass[d]>mass[larg]) { larg = d; }
	if (larg != i) {
		std::swap(mass[i], mass[larg]);
		heapify(mass, n, larg);
	}
}

void heapSort(int* mass, int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(mass, n, i);
	}
	for (int i = n - 1; i >= 0; --i) {
		std::swap(mass[0], mass[i]);
		heapify(mass, i, 0);
	}
}
int main() {
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	const int CST = 10;
	int mass[CST];
	for (int i = 0; i < CST; ++i) {
		mass[i] = 10 + rand() % 100;
	}
	voila(mass); std::cout << '\n';
	//СОРТИРОВКИ!!

	// ПУЗЫРЬКОВАЯ СОРТИРОВКА 

	/*for (int i = 0; i < CST; ++i) {
		for (int j = 0; j < CST - 1; ++j) {
			if (mass[j] > mass[j + 1]) {
				int b = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = b;
			}
		}
	}
	std::cout << "ОТСОРТИРОВАНО\n";
	voila(mass); std::cout << '\n';*/

	// ШЕЙКЕР

	/*for (int i = 0; i < CST; ++ i) {
		bool fl = true;
		for (int j = 0; j < CST - (i + 1); ++j) {
			if (mass[j] > mass[j + 1]) {
				fl = false;
				std::swap(mass[j], mass[j + 1]);
			}
		}
		if (fl) { break; }
	}*/

	/*int l = 0, r = CST - 1, i;
	while (l <= r) {
		for (i = r; i >= l; --i) {
			if (mass[i - 1] > mass[i]) { std::swap(mass[i - 1], mass[i]); }
		}
		++l;
		for (i = l; i <= r; ++i) {
			if (mass[i - 1] > mass[i]) { std::swap(mass[i - 1], mass[i]); }
		}
		--r;
	}*/

	// СОРТИРОВКА ВСТАВКАМИ

	/*int j, i;
	for (i = 1; i < CST; ++i) {
		int s = mass[i];
		for (j = i - 1; j >= 0 && mass[j] > s; --j) {
			mass[j + 1] = mass[j];
		}
		mass[j + 1] = s;
	}*/

	// СОРТИРОВКА ВЫБОРОМ

	/*int min;
	for (int i = 0; i < CST; ++i) {
		min = i;
		for (int j = i + 1; j < CST; ++j) {
			min = (mass[j] < mass[min]) ? j : min;
		}
		if (i != min) { std::swap(mass[i], mass[min]); }
	}*/

	// БЫСТРАЯ СОРТИРОВКА

	//QS(mass, 0, 9);


	// СОРТИРОВКА ШЕЛЛА

	//Shell(mass, 10);

	// ГНОМЬЯ СОРТИРОВКА

	//Gnomesort(10, mass);

	// ПИРАМИДАЛЬНАЯ СОРТИРОВКА

	heapSort(mass, 10);

	std::cout << "ОТСОРТИРОВАНО\n";
	voila(mass);

	// БИНАРНЫЙ ПОИСК

	std::cout << "\n Что ищем : ";
	int kl; std::cin >> kl;
	binarka(mass, 0, 9, kl);
	



	return 0;
}