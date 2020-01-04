// GameLoad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afx.h>
#include <tchar.h>
int Decrypt_KEY(int a1, int a2, BYTE *a3);
int Encrypt_KEY(int a1, int a2, BYTE *a3);
void Encrypt()
{
	unsigned int v1; // esi@2
	void *v2; // edi@2
	BYTE *v3; // ebp@2
	int v7; // [sp+4Ch] [bp-4h]@1

	v7 = 0;
	CFile v5;
	CFile v6;
	if (v5.Open(L"GameLoadInfo.ini", 0, 0))
	{
		v1 = v5.GetLength();
		v2 = operator new[](v1 + 2);
		v3 = (BYTE*)operator new[](v1 + 2);
		v5.Read(v2, v1);
		v5.Close();
		Encrypt_KEY((int)v2, v1, v3);
		if (v6.Open(L"GameLoadInfo.dat", 0x1001, 0))
		{
			v6.Write(v3, v1);
			v6.Close();
			printf("File encrypted sucessfully to GameLoadInfo.dat");
			int none;
			scanf_s("%d", &none);
		}
	}
}
void Decrypt()
{
	unsigned int v1; // esi@2
	void *v2; // edi@2
	BYTE *v3; // ebp@2
	int v7; // [sp+4Ch] [bp-4h]@1

	v7 = 0;
	CFile v5;
	CFile v6;
	if (v5.Open(L"GameLoadInfo.dat", 0, 0))
	{
		v1 = v5.GetLength();
		v2 = operator new[](v1 + 2);
		v3 = (BYTE*)operator new[](v1 + 2);
		v5.Read(v2, v1);
		v5.Close();
		Decrypt_KEY((int)v2, v1, v3);
		if (v6.Open(L"GameLoadInfo.ini", 0x1001, 0))
		{
			v6.Write(v3, v1);
			v6.Close();
			printf("File decrypted sucessfully to GameLoadInfo.ini");
			int none;
			scanf_s("%d",&none);
		}
	}
}

int main(int argc, char* argv[])
{
	printf("Created by SuperNova [Muhammad Ibrahim]\nGameLoad Decryptor/Encryptor\n");
	printf("Choose what do you want?\n1.Decrypt\n2.Encrypt\n");
	int choice;
	scanf_s("%d", &choice);
	switch (choice) {
	default:
	case 1:
		Decrypt();
		break;
	case 2:
		Encrypt();
	}
	return 0;
}
int Decrypt_KEY(int a1, int a2, BYTE *a3)
{
	int result; // eax@1
	BYTE *v4; // ecx@2
	int v5; // edi@2
	int v6; // edx@2
	char v7; // bl@5
	char v8; // [sp+4h] [bp-Ch]@1
	char v9; // [sp+5h] [bp-Bh]@1
	char v10; // [sp+6h] [bp-Ah]@1
	char v11; // [sp+7h] [bp-9h]@1
	char v12; // [sp+8h] [bp-8h]@1
	char v13; // [sp+9h] [bp-7h]@1
	char v14; // [sp+Ah] [bp-6h]@1

	v11 = 1;
	v13 = 1;
	result = 0;
	v8 = 7;
	v9 = 3;
	v10 = 4;
	v12 = 5;
	v14 = 2;
	if (a2 <= 0)
	{
		a3[a2] = 0;
	}
	else
	{
		v4 = a3;
		v5 = a1 - (unsigned long)a3;
		v6 = a2;
		do
		{
			if (result == 5)
				result = 0;
			switch (result) {
			case 0:
				v7 = v8 ^ v4[v5];
				break;

			case 1:
				v7 = v9 ^ v4[v5];
				break;

			case 2:
				v7 = v10 ^ v4[v5];
				break;

			case 3:
				v7 = v11 ^ v4[v5];
				break;

			case 4:
				v7 = v12 ^ v4[v5];
				break;
			}
			result++;
			*v4++ = v7;
			--v6;
		} while (v6);
		a3[a2] = 0;
	}
	return result;
}
int Encrypt_KEY(int data, int length, BYTE *a3) // The reverse of Decrypt
{
	int result; // eax@1
	BYTE *v4; // ecx@2
	int v5; // edi@2
	int v6; // edx@2
	char v7; // bl@5
	char v8; // [sp+4h] [bp-Ch]@1
	char v9; // [sp+5h] [bp-Bh]@1
	char v10; // [sp+6h] [bp-Ah]@1
	char v11; // [sp+7h] [bp-9h]@1
	char v12; // [sp+8h] [bp-8h]@1
	char v13; // [sp+9h] [bp-7h]@1
	char v14; // [sp+Ah] [bp-6h]@1

	v11 = 1;
	v13 = 1;
	result = 0;
	v8 = 7;
	v9 = 3;
	v10 = 4;
	v12 = 5;
	v14 = 2;
	if (length <= 0)
	{
		a3[length] = 0;
	}
	else
	{
		v4 = a3;
		v5 = data - (unsigned long)a3;
		v6 = length;
		do
		{
			if (result == 5)
				result = 0;
			switch (result) {
			case 0:
				v7 = v4[v5] ^ v8;
				break;

			case 1:
				v7 = v4[v5] ^ v9;
				break;

			case 2:
				v7 = v4[v5] ^ v10;
				break;

			case 3:
				v7 = v4[v5] ^ v11;
				break;

			case 4:
				v7 =  v4[v5] ^ v12;
				break;
			}
			result++;
			*v4++ = v7;
			--v6;
		} while (v6);
		a3[length] = 0;
	}
	return result;
}

