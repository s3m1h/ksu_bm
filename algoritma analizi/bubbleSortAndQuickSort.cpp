#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

const int BIN = 1000;
const int IKIBIN = 2000;
const int UCBIN =3000;

int karsilastirmaQ=0; // global de�isken -- quick sort algoritmas� karsilastirma sayisi icin

void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

// Bubble sort algoritmas�
int bubbleSort(int n, int dizi[]){
	
	int karsilastirmaB = 0;
	int s, x, y, t; 
	s = n;
	
	
	for (x = 0 ; x < ( s - 1 ); x++) { 
		for (y = 0 ; y < s - x - 1; y++) { 
			if (dizi[y] > dizi[y+1])
			{ 
				karsilastirmaB +=1;
				swap(&dizi[y],&dizi[y+1]); 
			} 
		} 
	}
	 for ( x = 0 ; x < s ; x++ ){
	 	printf("%d  ", dizi[x]); 
	 }

	return karsilastirmaB; 	
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low - 1);  

    for (int j = low; j <= high- 1; j++)
    {
        
        if (arr[j] <= pivot)
        {
			karsilastirmaQ +=1;
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
 
    return (i + 1);
}

// Quick sort algoritmas�
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// fonksiyon imzalar�
//

// uygulamam�z�n men�s�
void printMenu();

// bir diziyi ba�ka bir diziye kopyalamak i�in bir foksiyon
// ilk diziyi ikinci diziyi ve dizi boyutunu parametre olarak al�r.
void *diziKopyala(int ilkDizi[],int ikinciDizi[], int boyut);

// herhangi bir diziyi ekrana yazd�rmak i�in bir fonksiyon
// dizi ve dizi boyutunu parametre olarak al�r.
void diziPrint(int dizi[], int boyut);

// random sayi �reten bir fonksiyon
// mininum ve maksimum sayi arali�i al�r.
int randNum(int min, int max);

// random sayilardan olu�an dizi �retme
// dizi, dizi boyutu, min max -- random sayi arali�i
int *randomDiziUret(int dizi[], int boyut,int min, int max);

// random sayi �retme -- algoritma calistirma -- konsol ciktilari gibi islemleri icermektedir...
// dizi boyutu , random sayi i�in minimum de�er, random sayi i�in maximum de�er
void algoritmaIslem(int boyut, int min, int max);

// metinleri renklendirmek i�in kullan�lacak ba�lang�� kodlar� 
//-------------------------------------------------
HANDLE hConsole(){
	return GetStdHandle(STD_OUTPUT_HANDLE);
}
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD saved_attributes;

WORD savedAttrHandleFonk(){
	GetConsoleScreenBufferInfo(hConsole(), &consoleInfo);
	return consoleInfo.wAttributes;
}
//-------------------------------------------------

// Main foksiyonumuz
int main(){
	saved_attributes = savedAttrHandleFonk();
	
	char secim;
	printMenu();
	printf("seciminiz: \n> ");
	while(true){
		srand(time(NULL));

		scanf("%c",&secim);
		if(secim == 'q'){
			break;
		}
		else if(secim == '1'){
			algoritmaIslem(BIN,1,BIN);
		}
		else if(secim == '2'){
			algoritmaIslem(IKIBIN,1,IKIBIN);
		}
		else if(secim == '3'){
			algoritmaIslem(UCBIN,1,UCBIN);
		}
		else if(secim == '4'){
			int diziBoyutu,min,max;
			
			SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN);
			printf("Dizi boyutu belirtmek i�in bir sayi giriniz: \n>");
			SetConsoleTextAttribute(hConsole(), saved_attributes);
			scanf("%d",&diziBoyutu);
			SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN);
			printf("Uretilecek dizi icin rastgele sayilarin arali�ini sirayla belirtin..\n>");
			SetConsoleTextAttribute(hConsole(), saved_attributes);
			printf("(min) \n>");
			scanf("%d",&min);
			printf("(max) \n>");
			scanf("%d",&max);
			algoritmaIslem(diziBoyutu,min,max);
		}
	}
	
}

void printMenu(){
	
	printf("##############################\n");
	printf(" BUBBLE SORT & QUICK SORT \n");
	printf("##############################\n");
	printf("1) 1000 elemanli dizi\n");
	printf("2) 2000 elemanli dizi\n");
	printf("3) 3000 elemanli dizi\n");
	printf("4) Elle belirle\n");
	printf("q) cikis\n");
	printf("##############################\n");

}

void *diziKopyala(int ilkDizi[],int ikinciDizi[], int boyut){
	for(int i =0;i<boyut;i++) 
		ikinciDizi[i] = ilkDizi[i];
	return ikinciDizi;
}

void diziPrint(int dizi[], int boyut){
	for(int i =0;i<boyut;i++) 
		printf("%d  ",dizi[i]);
}

int randNum(int min, int max){	
	return (rand() % (int)(((max) + 1) - (min))) + (min);
}

int *randomDiziUret(int dizi[], int boyut,int min, int max){
    for(int i = 0 ; i < boyut ; i++)
    {
        dizi[i] = randNum(min,max);
    }
    return dizi;
}
	

void algoritmaIslem(int boyut,int min, int max){
	clock_t basla, bit, basla2, bit2;

	saved_attributes = consoleInfo.wAttributes;
    
	
	int dizi[boyut];
	int diziK[boyut];
	char a;
	SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN);
	printf("%d boyutlu dizi ile calisilacaktir...\n\n",boyut);
	printf("Bekleme durumunda bir tusa basarak devam edebilirsiniz...\n");
	SetConsoleTextAttribute(hConsole(), saved_attributes);
	getch();
		
	randomDiziUret(dizi,boyut,min,max);
	diziPrint(dizi,boyut);
			
			
	SetConsoleTextAttribute(hConsole(),BACKGROUND_RED);
	printf("Rastgele uretilen diziyi 2 algoritma icin kullanilacagindan yeni bir diziye kopyaliyoruz.\n");
	SetConsoleTextAttribute(hConsole(), saved_attributes);
	getch();
	// ilk dizi - kopyalanacak dizi, ikinci dizi - yeni dizi
	diziKopyala(dizi,diziK,boyut);
	diziPrint(diziK,boyut);
	
	
	// satirin arka plan rengini de�i�tirme 
	SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN);
	printf("\n%d adet %d ile %d arasinda rastgele sayilar uretildi ve ekrana basildi...\n",boyut,min,max);
	// satirin arka plan rengini eski halilne getirme 
	SetConsoleTextAttribute(hConsole(), saved_attributes);
	getch();
	
	SetConsoleTextAttribute(hConsole(),BACKGROUND_RED);
	printf("Uretilen dizi Bubble sort siralama algoritmasi ile calistiriliyor..\n");
	SetConsoleTextAttribute(hConsole(), saved_attributes);
	
	getch();
	
	// BUBBLE SORT
	basla = clock();
	int karsilastirmaBubble = bubbleSort(boyut,dizi);
	bit = clock();
	
	SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN);
	printf("Siralama islemi tamamlandi..\n");
	SetConsoleTextAttribute(hConsole(), saved_attributes);
	
	float fark = (float)(bit-basla) / CLOCKS_PER_SEC;
	
	SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	printf("Siralama islemi %f saniye de bitti...\n",fark);
	SetConsoleTextAttribute(hConsole(), saved_attributes);
			
			
	SetConsoleTextAttribute(hConsole(),BACKGROUND_RED);
	printf("Uretilen dizi Quick sort siralama algoritmasi ile calistiriliyor..\n");
	SetConsoleTextAttribute(hConsole(), saved_attributes);
	
	getch();
	int N = sizeof(diziK) / sizeof(diziK[0]);

	basla2 = clock();
	quickSort(diziK,0,N-1);
	bit2 = clock();
	diziPrint(diziK,boyut);

	SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN);
	printf("Siralama islemi tamamlandi..\n");
	SetConsoleTextAttribute(hConsole(), saved_attributes);

	float fark2 = (float)(bit2-basla2) / CLOCKS_PER_SEC;
			
			
	SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
	printf("Siralama islemi %f saniye de bitti...\n\n",fark2);
	SetConsoleTextAttribute(hConsole(), saved_attributes);
	getch();
	SetConsoleTextAttribute(hConsole(),BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
	printf("\n######### ISTATISTIKLER #######################################\n");
	printf("\n%d Elemanli %d minimum %d maximum sayi araligindaki random sayilardan olusan bir dizi ile islemler yapildi..\n\n",boyut,min,max);
	printf("Bubble sort algoritmasi islemi %f saniye de bitirdi...Karsilastirma sayisi: %d\n",fark,karsilastirmaBubble);
	printf("Quick sort algoritmasi islemi %f saniye de bitirdi...Karsilastirma sayisi: %d\n",fark2,karsilastirmaQ);
	printf("");
	printf("###############################################################\n");
	SetConsoleTextAttribute(hConsole(), saved_attributes);
}
