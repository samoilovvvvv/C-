#include<iostream> 
#include<fstream> 
#include<vector> 
using namespace std;
const int MAX = 10;
int front_arr; int sum;
int end_arr; int countss = 0;
struct maximum {
	int MAXx;
	int MAXy;
	int MAXz;
	void getmax(int a, int b, int c) {
		MAXx = a;
		MAXy = b;
		MAXz = c;

	}
	int retmaxx() {
		return MAXx;
	}
	int retmaxy() {
		return MAXy;
	}
	int retmaxz() {
		return MAXz;
	}
};
class point {
private:
	static int these;
	int x;
	int y;
	int z;
	int what_connect[MAX];
	int schet;
public:
	point() {
		x = 0;
		y = 0;   // конструктор ниже тоже
		z = 0;
		schet = 0;
	}
	point(int a, int b, int c, int d) {
		x = a;
		y = b;
		z = c;
		schet = d;
		for (int i = 0; i < MAX; i++) {
			what_connect[i] = -1;
		}
	}
	int go(point a, point* arr, int is_last) {                 // из точки в точку переход
		ofstream file("output.txt", ios_base::app);
		int temp_these = is_exsist(x, y, z, arr);
		if (!(check_connect(these, arr))) {
			if (is_last != -1 && these != -1) {
				arr[temp_these].what_connect[arr[temp_these].schet++] = these;
			}
		}
		if (is_finish(a)) {
			return -2;
		}
		int temp;
		int is_go = 0;
		int tempx = x;
		int tempy = y;
		int tempz = z;
		if (a.retx() > x) {
			tempx++;
			is_go = 1;
		}
		if (a.retx() < x) {
			tempx--;
			is_go = 1;
		}
		if (a.rety() > y && is_go == 0) {
			tempy++;
			is_go = 1;
		}
		if (a.rety() < y && is_go == 0) {
			tempy--;
			is_go = 1;
		}
		if (a.retz() > z && is_go == 0) {
			tempz++;
			is_go = 1;
		}
		if (a.retz() < z && is_go == 0) {
			tempz--;
			is_go = 1;
		}
		these = temp_these;
		if (is_go = 1) {
			if ((is_exsist(tempx, tempy, tempz, arr) != -1)) {
				temp = is_exsist(tempx, tempy, tempz, arr);
				if (!(check_connect(these, arr))) {
					if (arr[temp].check(these, arr, -1)) {
						file <<  x << " " <<  y << " " <<  z << " " <<  tempx << " " <<  tempy << " " << tempz << endl;
						these = -1;
					}
					else {
						arr[temp_these].what_connect[arr[temp_these].schet++] = temp;
					}
				}
				return temp;
			}
			else {
				point b(tempx, tempy, tempz, 0);
				arr[countss] = b;
				arr[temp_these].what_connect[arr[temp_these].schet++] = countss;
				if (b.check(these, arr, -1)) {
					cout << x << y << z << endl << tempx << tempy << tempz << endl;
					schet--;
				}
				return countss++;
			}
		}
		file.close();
	}
	bool check(int a, point * arr, int last) {
		for (int i = 0; i < schet; i++) {
			if (what_connect[i] == last) {
				continue;                                  // проверяет образуются пересечения или нет(проверяет задание)
			}
			int temp = is_exsist(x, y, z, arr);
			if (what_connect[i] == a) {
				return true;
			}
			if (arr[what_connect[i]].check(a, arr, temp)){
				return true;
			}
		}
		return false;
	}
	bool check_connect(int a, point * arr) {
		for (int i = 0; i < schet; i++) {              // проверяет в массиве что-то
			if (what_connect[i] == a) {
				return true;
			}
		}
		return false;
	}
	bool is_finish(point a) {
		int temp = 0;
		if (x == a.retx()) {
			temp++;
		}
		if (y == a.rety()) {
			temp++;
		}
		if (z == a.retz()) {
			temp++;                            // конец или нет проверяет 
		}
		if (temp == 3) {
			return true;
		}
		else {
			return false;
		}
	}
	int retx() {
		return x;
	}                             // возвращает координаты
	int rety() {
		return y;
	}
	int retz() {
		return z;
	}
	int is_exsist(int x, int y, int z, point* arr) {
		int temp = 0;
		for (int i = 0; i <sum; i++) {
			if ((i + 1) == sum) {
				return -1;
			}
			if (arr[i].retx() == x) {               // существует ли точка. создает точку и в нее переходит
				temp++;
			}
			else {
				temp = 0;
				continue;
			}
			if (arr[i].rety() == y) {
				temp++;
			}
			else {
				temp = 0;
				continue;
			}
			if (arr[i].retz() == z) {
				temp++;
			}
			else {
				temp = 0;
				continue;
			}
			if (temp == 3) {
				return i;
			}
		}
	}
	void set_connect(int a) {
		what_connect[schet] = a;
		schet += 1;                       // соединяет с точкой из которой пришло и в которую идет
	}
};
int point::these = -1;          // стат аргумент
int find(int a, int b, int c, point* arr) {
	for (int i = 0; i < sum; i++) {
		int temp3 = 0;
		if ((i + 1) == sum) {
			return -1;
		}
		if (arr[i].retx() == a) {
			temp3++;
		}                                      // создана ли точка в которую ты переходишь 
		else {
			continue;
		}
		if (arr[i].rety() == b) {
			temp3++;
		}
		else {
			continue;
		}
		if (arr[i].retz() == c) {
			temp3++;
		}
		else {
			continue;
		}
		if (temp3 == 3) {
			return i;
		}
	}
}
void do_go(point * arr, point a, point b) {
	int is_end; int j = 0;
	do {
		if (j == 0) {
			is_end = a.go(b, arr, -1);
		}
		else {
			is_end = a.go(b, arr, 0);
		}                                                // переход в точку 
		if (is_end != -2) {
			a = arr[is_end];
		}
		j++;
	} while (is_end != -2);
}
bool check_max(int x, int y, int z, maximum new_max) {
	if (x > new_max.MAXx || x < 0) {
		return true;
	}
	if (y > new_max.MAXy || y < 0) {
		return true;
	}
	if (z > new_max.MAXz || z < 0) {                       // проверяет не выходит ли точка за пределы
		return true;
	}
	return false;
}
int to_end(point* arr, maximum new_max, vector<int>vec, int &ftp) {
	int a, b, c, x, y, z;
	a = vec[ftp++]; b = vec[ftp++]; c = vec[ftp++];
	x = vec[ftp++]; y = vec[ftp++]; z = vec[ftp++];
	//cin » a » b » c » x » y » z; 
	if (check_max(a, b, c, new_max)) {
		return 1;                                         // функция которая запускает гоу и остальные функции 
	}
	if (find(a, b, c, arr) == -1) {
		point fr(a, b, c, 0);
		arr[countss++] = fr;
		if (find(x, y, z, arr) == -1) {
			point er(x, y, z, 0);
			arr[countss++] = er;
			do_go(arr, fr, er);
		}
		else {
			end_arr = find(x, y, z, arr);
			do_go(arr, fr, arr[end_arr]);
		}
	}
	else {
		front_arr = find(a, b, c, arr);
		if (find(x, y, z, arr) == -1) {
			point er(x, y, z, 0);
			arr[countss++] = er;
			do_go(arr, arr[front_arr], er);
		}
		else {
			end_arr = find(x, y, z, arr);
			do_go(arr, arr[front_arr], arr[end_arr]);
		}
	}
	return 0;
}
int main(int argc, char* argv[]) {
	ofstream fil("output.txt");
	fil.clear();
	fil.close();
	ifstream file_in; int a, b, c, q; int ftp;
	file_in.open("input.txt");
	vector<int> vec;
	while (!(file_in.eof())) {
		file_in >> ftp;
		vec.push_back(ftp);
	}
	ftp = 0;
	//cin » a » b » c » q; 
	a = vec[ftp++]; b = vec[ftp++]; c = vec[ftp++]; q = vec[ftp++];
	sum = a * b * c;
	maximum new_max;
	new_max.getmax(a, b, c);
	point * arr = new point[sum];
	for (int i = 0; i < q; i++) {
		to_end(arr, new_max, vec, ftp);
	}
	system("pause");
	return 0;
}