#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char Ma[10];
	char HoTen[40];
}SinhVien;
void ReadFile(char *FileName);
void WriteFile(char *FileName);
void Search(char *FileName);
int main()
{
	int c;
	for(;;)
	{
		system("cls");
		printf("\n \t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
		printf("\t 1. Nhap DSSV\n");
		printf("\t 2. In DSSV\n");
		printf("\t 3. Tim Kiem\n");
		printf("\t 4. Thoat\n");
		printf("\t Bam Chon 1, 2, 3, 4: ");
		scanf("%d",&c);
		fflush(stdin);
		if(c==1)
		{
			WriteFile("SinhVien.txt");
		}
		else if (c==2)
		{
			ReadFile("SinhVien.txt");
		}
		else if (c==3)
		{
			Search("SinhVien.txt");
		}
		else break;
	}
}
void WriteFile(char *FileName)
{
	FILE *f;
	int n,i;
	SinhVien sv;
	f=fopen(FileName,"ab");
	printf("Nhap vao so luong sinh vien ");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		printf("Sinh vien thu %i\n",i);
		fflush(stdin);
		printf(" - MSSV: ");
		gets(sv.Ma);
		printf(" - Ho ten: ");
		gets(sv.HoTen);
		fwrite(&sv,sizeof(sv),1,f);	
	}
	fclose(f);
	printf("Bam phim bat ki de tiep tuc ");
	getch();
}
void ReadFile(char *FileName)
{
	FILE *f;
	SinhVien sv;
	f=fopen(FileName,"rb");
	printf(" MSSV | Ho va ten\n");
	fread(&sv,sizeof(sv),1,f);
	while (!feof(f))
	{
		printf(" %s | %s\n",sv.Ma,sv.HoTen);
		fread(&sv,sizeof(sv),1,f);
	}
	fclose(f);
	printf("Bam phim bat ki de tiep tuc ");
	getch();
}
void Search(char *FileName)
{
	char MSSV[10];
	FILE *f;
	int Found=0;
	SinhVien sv;
	fflush(stdin);
	printf("Ma so sinh vien can tim ");
	gets(MSSV);
	f=fopen(FileName,"rb");
	while (!feof(f)&& Found==0)
	{
		fread(&sv,sizeof(sv),1,f);
		if(strcmp(sv.Ma,MSSV)==0)
		Found=1;	
	}
	fclose(f);
	if (Found ==1)
	{
		printf("Tim thay sinh vien co ma %s. Ho ten la: %s ",sv.Ma,sv.HoTen);
	}
	else
	{
		printf("Tim khong thay sinh vien co ma %s ",MSSV);
	}
	printf("\n Bam phim bat ki de tiep tuc ");
	getch();
}

