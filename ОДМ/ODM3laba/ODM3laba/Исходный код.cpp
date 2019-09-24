#include<iostream>
#include<clocale>
using namespace std;

int** PereChislenie(int key);
void  Watch(int **M, int mM);
void  KonZap();
void  menu();
int** InOne(int **A, int **B, int mA, int mB);		// ����������� ��������
int** Peresek(int **A, int **B, int mA, int mB);	// ����������� ��������
int** Pa3HocTb(int **U, int **W, int mU, int mW);	// �������� 
int** SimRas(int **A, int **B, int mA, int mB);		// ������������ �������� A u B
int** Inversion(int **M, int mM);					// ��������
int** Exposition(int **A, int **B, int mA, int mB);	// ���������� ��������

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� �������� ������� �:\t";
	int mA;
	cin >> mA;
	int **A = PereChislenie(mA);
	cout << "������� �������� ������� B:\t";
	int mB;
	cin >> mB;
	int **B = PereChislenie(mB);
	KonZap();
	while (true)
	{
		system("cls");
		cout << "A =  ";	Watch(A, mA);
		cout << "B =  ";	Watch(B, mB);
		menu();
		int Operaziya;
		cin >> Operaziya;
		system("cls");
		switch (Operaziya)
		{
		case 1: // ����������� ��������
		{
			cout << "����������� �������� :" << endl;
			int mD = mA + mB + 1;
			int **D = new int*[mD];
			for (int i = 0; i <= mD; i++)
				D[i] = new int[3];
			D = Peresek(A, B, mA, mB);
			mD = D[0][0];
			Watch(D, mD);
			system("pause");
		}
		break;
		case 2: // ����������� ��������
		{
			cout << "����������� �������� :" << endl;
			int mC = mA + mB + 1;
			int **C = new int*[mC];
			for (int i = 0; i <= mC; i++)
				C[i] = new int[3];
			C = InOne(A, B, mA, mB);
			mC = C[0][0];
			Watch(C, mC);
			system("pause");
		}
		break;
		case 3: // �������� A � � 
		{
			cout << "�������� A � � :" << endl;
			int mR = mA + 1;
			int **R = new int*[mR];
			for (int i = 0; i <= mR; i++)
				R[i] = new int[3];
			R = Pa3HocTb(A, B, mA, mB);
			mR = R[0][0];
			Watch(R, mR);
			system("pause");
		}
		break;
		case 4:// ������������ �������� A u B
		{
			cout << "������������ �������� A u B :" << endl;
			int mS = mB + mA + 1;
			int **S = new int*[mS];
			for (int i = 0; i <= mS; i++)
				S[i] = new int[3];
			S = SimRas(B, A, mB, mA);
			mS = S[0][0];
			Watch(S, mS);
			system("pause");
		}
		break;
		case 5:// �������� � 
		{
			cout << "�������� � :" << endl;
			int mI = mA;
			int **I = new int*[mI];
			for (int i = 0; i <= mI; i++)
				I[i] = new int[3];
			I = Inversion(A, mA);
			mI = I[0][0];
			Watch(I, mI);
			system("pause");
		}
		break;
		case 6:// �������� �
		{
			cout << "�������� B :" << endl;
			int mI = mB;
			int **I = new int*[mI];
			for (int i = 0; i <= mI; i++)
				I[i] = new int[3];
			I = Inversion(B, mB);
			mI = I[0][0];
			Watch(I, mI);
			system("pause");
		}
		break;
		case 7:// ���������� �������� A � B
		{
			cout << "���������� �������� A � B :" << endl;
			int mK = mB*mA + 1;
			int **K = new int*[mK];
			for (int i = 0; i <= mK; i++)
				K[i] = new int[3];
			K = Exposition(A, B, mA, mB);
			mK = K[0][0];
			Watch(K, mK);
			system("pause");
		}
		break;
		case 0:// �����
			return 0;
		}
	}
}

int** PereChislenie(int mM)
{
	int **M;
	M = new int *[mM];
	for (int i = 1; i <= mM; i++)
		M[i] = new int[3];
	if (mM < 1)
	{
		cout << "������ ������!" << endl;
		return M;
	}
	cout << "������� ���� �������:\n";
	for (int i = 1; i <= mM; i++)
	{
		cout << "���� �" << i << endl;
		for (int j = 1; j < 3; j++)
		{
			cin >> M[i][j];
		}
	}
	cout << endl;
	return M;
}
void  Watch(int **M, int mM)
{
	cout << "{";
	for (int i = 1; i <= mM; i++)
	{
		cout << "<";
		for (int j = 1; j < 3; j++)
		{
			cout << M[i][j];
			if (j == 1)
				cout << ", ";
		}
		cout << ">";
		if (i < mM)
			cout << ", ";
	}
	cout << "}" << endl;
}
void  KonZap()
{
	cout << "������� ���������." << endl;
	system("pause");
	system("cla");
}
void  menu()
{
	cout << endl << "�������� ��������:" << endl;
	cout << "	1. ����������� ��������\n	2. ����������� ��������\n	3. �������� A � �\n	4. ������������ �������� A u B\n	5. �������� �\n	6. �������� �\n	7. ���������� �������� A � B\n	0. �����\n";
	cout << "-->";
}
int** InOne(int **A, int **B, int mA, int mB)
{
	int mC = mA + mB + 1;
	int i, j;
	int **C = new int*[mC];
	for (int i = 0; i <= mC; i++)
		C[i] = new int[3];
	if (mB == 0 && mA == 0)
	{
		cout << "������ ������!  -  ";
		return C;
	}
	if (mA == 0)
	{
		for (i = 1; i <= mB; i++)
		{
			for (j = 1; j < 3; j++)
			{
				C[i][j] = B[i][j];
			}
		}
		C[0][0] = mB;
		return C;
	}
	if (mB == 0)
	{
		for (i = 1; i <= mA; i++)
		{
			for (j = 1; j < 3; j++)
			{
				C[i][j] = A[i][j];
			}
		}
		C[0][0] = mA;
		return C;
	}
	for (i = 1; i <= mA; i++)
	{
		for (j = 1; j < 3; j++)
		{
			C[i][j] = A[i][j];
		}
	}
	for (int b = 1; b <= mB; b++)
	{
		for (int a = 1; a <= mA; a++)
		{
			if (B[b][1] == A[a][1] && B[b][2] == A[a][2])
				break;
			if (B[b][1] != A[a][1] || B[b][2] != A[a][2])
			{
				if (a == (mA))
				{
					C[i][1] = B[b][1];
					C[i][2] = B[b][2];
					i++;
				}
				else continue;
			}
		}

	}
	C[0][0] = i - 1;
	return C;
}
int** Peresek(int **A, int **B, int mA, int mB)
{
	int mD = mA + mB + 1;
	int **D = new int*[mD];
	for (int i = 0; i <= mD; i++)
		D[i] = new int[3];
	int i = 0;
	if (mA == 0 || mB == 0)
	{
		cout << "������ ������!  -  ";
		return D;
	}
	for (int b = 1; b <= mB; b++)
	{
		for (int a = 1; a <= mA; a++)
		{
			if (B[b][1] == A[a][1] && B[b][2] == A[a][2])
			{
				i++;
				D[i][1] = B[b][1];
				D[i][2] = B[b][2];
			}
		}
	}
	if (i == 0)
		cout << "������ ������!  -  ";
	D[0][0] = i;
	return D;
}
int** Pa3HocTb(int **U, int **W, int mU, int mW)
{
	int mR = mU + 1;
	int **R = new int*[mR];
	for (int i = 0; i <= mR; i++)
		R[i] = new int[3];
	int r = 0;
	if (mU == 0)
	{
		cout << "������ ������!  -  ";
		return R;
	}
	if (mW == 0)
	{
		for (int i = 1; i <= mU; i++)
		{
			R[i][1] = U[i][1];
			R[i][2] = U[i][2];
		}
		R[0][0] = mU;
		return R;
	}

	for (int i = 1; i <= mU; i++)
	{
		for (int j = 1; j <= mW; j++)
		{
			if (U[i][1] == W[j][1] && U[i][2] == W[j][2])
				break;
			if (j == (mW))
			{
				r++;
				R[r][1] = U[i][1];
				R[r][2] = U[i][2];
			}
		}
	}
	if (r == 0)
		cout << "������ ������!  -  ";
	R[0][0] = r;
	return R;
}
int** SimRas(int **A, int **B, int mA, int mB)
{
	int mS = mA * mB + 2;
	int **S = new int*[mS];
	for (int i = 0; i <= mS; i++)
		S[i] = new int[3];
	int s = 0, o = 0;
	if (mA == 0 && mB == 0)
	{
		cout << "������ ������!";
		return  S;
	}
	if (mA == 0)
	{
		for (int i = 1; i <= mB; i++)
		{
			S[i][1] = B[i][1];
			S[i][2] = B[i][2];

		}
		S[0][0] = mB;
		return S;
	}
	if (mB == 0)
	{
		for (int i = 1; i <= mA; i++)
		{
			S[i][1] = A[i][1];
			S[i][2] = A[i][2];

		}
		S[0][0] = mA;
		return S;
	}
	for (int i = 1; i <= mA; i++)
	{
		for (int j = 1; j <= mB; j++)
		{
			o = 0;
			if (A[i][1] == B[j][1] && A[i][2] == B[j][2])
				continue;
			for (int l = 1; l <= s; l++)
			{
				if (S[l][1] == A[i][1] && S[l][2] == A[i][2])
				{
					o = 1;
					break;
				}
			}
			for (int v = 1; v <= mB; v++)
			{
				if (A[i][1] == B[v][1] && A[i][2] == B[v][2])
				{
					o = 1;
					break;
				}
			}
			if (o == 1)
				continue;
			s++;
			S[s][1] = A[i][1];
			S[s][2] = A[i][2];
		}
	}
	for (int i = 1; i <= mB; i++)
	{
		for (int j = 1; j <= mA; j++)
		{
			o = 0;
			if (B[i][1] == A[j][1] && B[i][2] == A[j][2])
				continue;
			for (int l = 1; l <= s; l++)
			{
				if (S[l][1] == B[i][1] && S[l][2] == B[i][2])
				{
					o = 1;
					break;
				}
			}
			for (int v = 1; v <= mA; v++)
			{
				if (B[i][1] == A[v][1] && B[i][2] == A[v][2])
				{
					o = 1;
					break;
				}
			}
			if (o == 1)
				continue;
			s++;
			S[s][1] = B[i][1];
			S[s][2] = B[i][2];
		}
	}
	if (s == 0)
		cout << "������ ������!  -  ";
	S[0][0] = s;
	return S;
}
int** Inversion(int **M, int mM)
{
	int **I = new int*[mM];
	int i = 0;
	for (int l = 0; l <= mM; l++)
		I[l] = new int[3];
	if (mM == 0)
	{
		cout << "������ ������!  -  ";
		return I;
	}
	for (i = 1; i <= mM; i++)
	{
		I[i][1] = M[i][2];
		I[i][2] = M[i][1];
	}
	I[0][0] = mM;
	return I;
}
int** Exposition(int **A, int **B, int mA, int mB)
{
	int mO = mA * mB + 1;
	int **K = new int*[mO];
	int k = 0;
	for (int p = 0; p <= mO; p++)
		K[p] = new int[3];
	if (mA == 0 || mB == 0)
	{
		cout << "������ ������!  -  ";
		return K;
	}
	for (int i = 1; i <= mA; i++)
	{
		for (int j = 1; j <= mB; j++)
		{
			int o = 0;
			if (A[i][2] != B[j][1])
				continue;
			for (int l = 1; l <= k; l++)
				if (A[i][1] == K[l][1] && B[j][2] == K[l][2])
				{
					o = 1;
					break;
				}
			if (o == 1)
				continue;
			k++;
			K[k][1] = A[i][1];
			K[k][2] = B[j][2];
			o = 0;
		}
	}
	if (k == 0)
		cout << "������ ������!  -  ";
	K[0][0] = k;
	return K;
}


