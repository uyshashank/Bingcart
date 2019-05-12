#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

int type,count,pr=9,adp,ad,ac,ae,var,position;
char uid[30],upass[30];
char name[20],lname[20],email[20],goback;
int c,d,sh,e;
int p[100],mode,num,kart=0,det=0,l=0,back,k;
int grand_total=0,pass,pay,crnum[25],key;
int sec,hno,pin,co,g,cvv;
char loc[20],city[20],adminemail[]="admin@gmail.com",adminpass[]="linux";		
int acc=0,choice,a,b,discount=0;
char hi[]="Hi",nice[]="Nice to see you here";
char txt[]=".txt",location[]="BINGCART/DATA/";
//UDF's//
char sub[30],dub[20];

int write_acc_data(char filename[40],char fname[40],char lname[30],char email[40],char pass[40])
{
	FILE *f;	
	f=fopen(filename,"w");
	
	if(f == NULL) 
   {
      printf("Error Creating Account!\nPlease try again!");
      return(-1);
   }
	
	fprintf(f,"%s",fname);
	fprintf(f,"%c",' ');
	fprintf(f,"%s",lname);
	fprintf(f,"%c",' ');
	fprintf(f,"%s",email);
	fprintf(f,"%c",' ');
	fprintf(f,"%s",pass);
	
	fclose(f);
}

int fetch(char filename[30])
{
	FILE *d;
	char fetched[100];
	int i,j;
	
	d=fopen(filename,"r");
	while(fscanf(d,"%s",fetched)!=EOF)
	{
	}	
	fclose(d);
	j=0;
	for(i=0;fetched[i]!='\0';i++)
	{
		if(fetched[i]==';')
		{
			for(i=i+1;fetched[i]!='\0';i++)
			{
			if(fetched[i]==';')
			{
				break;
			}
	
			dub[j]=fetched[i];
			j++;
			}
		}	
	
		sub[i]=fetched[i];
	}
dub[j]='\0';
sub[i]='\0';
	
}
int color(int c)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,c);
	return 0;
}
int stringcolor(char str[200],int c)
{
	HANDLE hConsole;
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,c);
	printf("%s",str);
	SetConsoleTextAttribute(hConsole,15);
}
int charcolor(int ch,int col)
{
	HANDLE hConsole;
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,col);
	printf("%c",ch);
	SetConsoleTextAttribute(hConsole,15);
}
//product detail structures//
	struct
		{
		char name[100];
		}pro[20]={"Samsung Galaxy On7 (Gold, 8 GB)",
				  "Samsung Galaxy On Nxt (Black, 64 GB)",
				  "Moto M (Silver, 64 GB)",
				  "Moto C Plus (Starry Black, 16 GB)",
				  "Lenovo K6 Power (Silver, 32 GB)",
				  "Lenovo K6 Power (Gold, 32 GB)",
				  "Redmi Note 4 (Gold, 32 GB)",
				  "Redmi Note 4 (Black, 32 GB)",
				  "Apple iPhone 6s (Rose Gold, 16 GB)",
				  "Apple iPhone 6s (Space Grey, 16 GB)"
				};
	struct
		{
			int price[20];
		}product = {
					 8490,
					15900,
					15999,
					 6999,
					 9999,
					 9999,
					10999,
					10999,
					38000,
					38000
	      	        };
	struct
	{
		int quantity[20];
	}q = {4,5,3,4,1,6,5,6,5,3};

	struct
	{
		char firstname[20],lastname[30],email[30],password[30];
	}user[100]={
				"Hari",
				"Mohan",
				"harimohan@gmail.com",
				"bingo",
			  };
	struct
	{
		float ram;
		int rom;
		int expupto;
		float screensize;
		int rc,fc,mah;
		char processor[100];
	}features[100]={1.5,8,128,5.5,13,5,3000,"Qualcomm Snapdragon 410 Processor",
					3,64,128,5.5,13,8,3300,"Exynos 7870 Processor",
					4,64,128,5.5,16,8,3050,"MediaTek Helio P15 64-bit Processor",
					2,16,32,5,8,2,4000,"Mediatek MTK6737 Quad Core 1.3Ghz Processor",
					3,32,128,5,13,8,4000,"Qualcomm Snapdragon 430 Processor",
					3,32,128,5.5,13,8,4000,"Qualcomm Snapdragon 410 Processor",
					3,32,128,5.5,13,5,4100,"Qualcomm Snapdragon 625 64-bit Processor",
					3,32,128,5.5,13,5,4100,"Qualcomm Snapdragon 625 64-bit Processor",
					2,16,64,4.7,12,5,1715,"A9 Chip with 64-bit Architecture and M9 Motion Co-processor Processor",
					2,16,64,4.7,12,5,1715,"A9 Chip with 64-bit Architecture and M9 Motion Co-processor Processor",						
               };
//product details structures end here
	
int cart1()//right corner cart 
{
	color(8);
	printf("\n%110c_____%c%c\n",' ',159,196);
	printf("%110c\\___/\n",' ');
	printf("%110c%2c%2c",' ',248,248);
	color(11);
	return 0;
}
int cart2()//middle cart 
{
	color(8);
	printf("\n%55c_____%c%c\n",' ',159,196);
	printf("%55c\\___/\n",' ');
	printf("%55c%2c%2c",' ',248,248);
	color(11);
	return 0;
}
int minus()//continuous minus long used in displaying product list 
{
	int i;
	color(8);
	for(i=1;i<=120;i++)
		printf("%c",196);
	puts("");
	color(11);
	return 0;
}
int minus1()//continuos minus short used in displaying features block//
{
	int i;
	color(8);
	for(i=1;i<=40;i++)
		printf("%c",196);
	puts("");
	color(11);
	return 0;
}
int minus2()//breaked minus or dash used to display payment methods table//
{
	int i;
	color(8);
	for(i=0;i<=70;i++)
		printf("-");
	color(11);
}
int minus3()//used in head second line//
{
	int v;
	color(8);
	for(v=0;v<=30;v++)
	printf("%c",196);
	color(11);
	return 0;
}
int equal1()//continuous equal used in head "welcome to bingkart"//
{
	int i;
	color(8);
	for(i=1;i<=120;i++)
		printf("%c",205);
	puts("");
	color(11);
	return 0;
}
int equal2()//continuous equal used in displaying features//
{
	int i;
	color(8);
	for(i=1;i<=11;i++)
		printf("%c",205);
	puts("");
	color(11);
	return 0;
}
int head()
{
	printf("\n%45c",' ');
	color(8);
	minus3();
	color(8);
	printf("\n%46c",'|');
	color(11);
	printf(" %25s","This is our product list");
	color(8);
	printf(" %3c\n",'|');
	printf("%45c",' ');
	minus3();
	color(8);
	printf("\n%46c%30c\n",'/','\\');
	return 0;
}
int body1()//sr,product name, price, quantity display module
{
	int i;			
	puts("");
	color(8);
	minus();
	color(11);
	printf("%s %26s %30s %25s\n","Pr.No.","Product Name","Price(Rs)","Quantity Available");
	color(8);
	minus();
	color(11);	
		for(i=0;i<=pr;i++)
			printf("%2d %39s %20d %18d\n\n",i+1,pro[i].name,product.price[i],q.quantity[i]);
	return 0;
}
int book1()//it will be executed first or when the cart is empty//
{	
	charcolor(222,8);
	printf("%s"," Enter Pr.No. to add that product to cart ");
	charcolor(222,8);
	puts("\n");
	charcolor(222,8);
	printf("%s"," Enter 21 to view product details         ");
	charcolor(222,8);
	if(kart==0)
		{
			color(8);
			printf("%78s","*Your Cart is Empty!\n->");	
			color(15);
		}		
	scanf("%d",&num);
	if(!(num>=1&&num<=pr+1||num==21||num==22))
	{
		minus();
		printf("%52c",' ');
		stringcolor("Invalid Input\n",207);
		printf("\nPress any key to continue:");
		getch();
		system("cls");
		headn6();
		color(15);
		bing();
	}
	minus();
	return 0;
}
int book2()//when cart is not empty//
{	
	charcolor(222,8);
	printf("%s"," Enter Pr.No. to add that product to cart ");
	charcolor(222,8);
	puts("\n");
	charcolor(222,8);
	printf("%s"," Enter 21 to view product details         ");
	charcolor(222,8);
	if(kart==0)
			{
				color(8);
				printf("%78s","*Your Cart is Empty!\n->");	
				color(15);
			}
	else
	{
			color(8);
			printf("\n\n%c",222);
			color(11);
			printf("%s"," Enter 22 to buy now                      ");
			color(8);
			printf("%c",222);
			if(kart==1)
			{
				color(8);
				printf("%56d %5s",kart,"Item in Your Cart!\n->");	
				color(15);
			}
			
			else
			{
				color(8);
				printf("%56d %5s",kart,"Items in Your Cart!\n->");	
				color(15);
			}
			
	}
	scanf("%d",&num);
	if(!(num>=1&&num<=pr+1||num==21||num==22))
	{
		minus();
		printf("%52c",' ');
		stringcolor("Invalid Input!\n\n",207);	
		printf("%47c",' ');
		stringcolor("Press any key to continue",207);
		getch();
		puts("");
		minus();
		system("cls");
		headn6();
		color(15);
		head();		
		body1();
		minus();
		bing();
	}
	if(!(num==22))
	minus();
	return 0;
}
int func()// redirecting back to main menu from features//
{
	printf("\n||Enter 13 to get back to main menu:||\n->");	
	scanf("%d",&back);
	if(back==13)
		{
			minus();
			bing();
		}	
	else
	{
		printf("Invalid input! Try again!\n");
		func();
	}
		return 0;
}
int add()//storing address//
{
		puts("");
		equal1();
		printf("%70s\n","Delivery Address");
		equal1();
		printf("||Enter Address where product is to be delivered:||\n");
		printf("Sector  :");
		scanf("%d",&sec);
		printf("House no:");
		scanf("%d",&hno);
		fflush(stdin);
		printf("Locality:");
		gets(loc);
		printf("City    :");
		gets(city);
		printf("Pin Code:");
		scanf("%d",&pin);
		equal1();
		printf("%70s\n","Address Confirmation");
		equal1();
		printf("||Enter 1 to continue , 2 to re-enter address:||\n->");
		scanf("%d",&co);			
		if(co==2)
		add();
		else if(co>2)
		{
				minus();
				printf("\n%90s","****************** Address confirmation failed! ******************");
				printf("\n\n%85s\n","************ Your order has been cancelled! ************");				
				printf("Press any key to exit:");
				getch();
				exit(0);
		}
		else
		{
			minus();
			puts("");
			printf("\t\t\t\t%s","************** Address Successfully Confirmed! **************");
			puts("");
		}		
		return 0;			
}
int payment()//payment gateway//
{
		puts("");
		equal1();	
		printf("%70s\n","Payment Gateway");
		equal1();
		printf("\n%s%18s%30s\n","Mt.No","Methods","Offers");
		minus2();
		for(g=1;g<=4;g++)
			{
				switch(g)
				{
					case 1:
						printf("\n%4d%20s%30s\n",g,"Credit Card","5% off");
						break;
					case 2:
						printf("%4d%20s%30s\n",g,"Debit Card","10% off");
						break;
					case 3:
						printf("%4d%20s%30s\n",g,"Net Banking","No Offers");
						break;
					case 4:
						printf("%4d%20s%30s\n",g,"Cash on Delivery","No Offers");
						break;
				}
			}
		minus2();
	return 0;
}
int rec()
{
	if(kart==0)
	{
		head();
		body1();
		color(8);
		minus();
		color(11);
		book1();
	}
	else
		book2();
	if(num<=20)
	{
		p[l]=num;
		l++;
	}	
}
int bing()
{
		rec();
		switch(num)//switch 1.00 
	{
	case 1:
		stringcolor("*Product 1 added to cart!",8);		
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 2:
		stringcolor("*Product 2 added to cart!",8);
		cart1();
		puts("");		
		kart++;
		minus();
		bing();
		break;
	case 3:
		stringcolor("*Product 3 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 4:
		stringcolor("*Product 4 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 5:
		stringcolor("*Product 5 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 6:
		stringcolor("*Product 6 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 7:
		stringcolor("*Product 7 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 8:
		stringcolor("*Product 8 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 9:
		stringcolor("*Product 9 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();
		break;
	case 10:
		stringcolor("*Product 10 added to cart!",8);
		cart1();
		puts("");
		kart++;
		minus();
		bing();	
		break;
	case 21:
		charcolor(222,8);
		printf(" Enter Pr.No. to see product details ");
		charcolor(222,8);
		printf("\n->");
		scanf("%d",&det);
		minus();
	
			if(det>=1&&det<=pr+1)
			{
				minus1();
				printf("%s\n",pro[det-1].name);
				minus1();
				printf("%c Features:\n",254);
				equal2();
				printf("%c Price : Rs.%d/- Only\n",254,product.price[det-1]);
				printf("%c %g GB RAM | %d GB ROM | Expandable Upto %d GB\n"
					   "%c %g inch Full HD Display\n"
					   "%c %dMP Rear Camera | %dMP Front Camera\n"
					   "%c %d mAh Li-Ion Battery\n"
					   "%c %s Processor\n",254,features[det-1].ram,features[det-1].rom,features[det-1].expupto,254,features[det-1].screensize,254,features[det-1].rc,features[det-1].fc,254,features[det-1].mah,254,features[det-1].processor);
				minus1();
				func();
			}
			else
			{
				printf("Invalid input!\n");
				printf("Press any key to continue:");
				getch();
				puts("");
				minus();
				puts("");
				system("cls");
				bing();
				exit(0);	
			}		
	case 22:
		minus();
		puts("\n");
		equal1();
		printf("%70s","Order Summary\n");
		equal1();
		printf("Your Order is:\n");			
		for(k=0;k<kart;k++)
			{
				printf("%d.%40s %20s%d\n",k+1,pro[p[k]-1].name,"Rs.",product.price[p[k]-1]);		
				grand_total+=product.price[p[k]-1];
			}
		minus2();			
		discount=(grand_total/100)*5;
		printf("\n%42s %20s%d\n","Grand Total:","Rs.",grand_total);
		minus2();
		puts("");
		printf("Press any key to continue:");
		getch();
		puts("");
		add();		
		payment();
		printf("\n||Enter Mt.No. to select Payment Method||\n->");
		scanf("%d",&mode);
		switch(mode)//switch 1.2
		{
			case 1:
				puts("");
				equal1();
				printf("%70s\n","Credit Card");
				equal1();
				puts("");
				minus2();
				printf("\n%c %4s %5s%d\n",222,"Discount(5%)   :","Rs.",discount);
				printf("\n%c %4s %5s%d\n",222,"Payble Amount  :","Rs.",grand_total-discount);
				minus2();
				
				printf("\n|Enter Credit Card Number|\n->");
				scanf("%d",&crnum);
				printf("|Enter CVV number|\n->");
				scanf("%d",&cvv);
				
				printf("|Enter 1 to proceed to pay Rs.%d|\n->",grand_total-discount);
				scanf("%d",&pay);
				if(pay!=1)
				{
					minus();
					printf("\n%90s","******************** Transaction Failed! **********************");
					printf("\n\n%85s\n","************ Your order has been cancelled! ************");				
					printf("Press any key to exit:");
					getch();
					exit(0);
				}
				equal1();
				puts("");				
				printf("\n%90s","************ Your order has been Successfully Placed ************");
				cart2();
				printf("\n%85s\n","************ Thanks for shopping at BingKart ************");
				stringcolor("\nDeveloped By Shashank Yenurkar(COPYRIGHT PROTECTED)\n",185);			
				returnn();
				exit(0);
				break;
				
				case 2:
				puts("");
				equal1();
				printf("%70s\n","Debit Card");
				equal1();
				
				minus2();
				printf("\n%c %4s %5s%d\n",222,"Discount(5%)   :","Rs.",discount);
				printf("\n%c %4s %5s%d\n",222,"Payble Amount  :","Rs.",grand_total-discount);
				minus2();
				
				printf("\n|Enter Debit Card Number|\n->");
				scanf("%d",&crnum);
				printf("|Enter CVV number|\n->");
				scanf("%d",&cvv);
				printf("|Enter 1 to proceed to pay Rs.%d|\n->",grand_total-(grand_total/10));				
				scanf("%d",&pay);
				if(pay!=1)
				{
					minus();
					printf("\n%90s","******************** Transaction Failed! **********************");
					printf("\n\n%85s\n","************ Your order has been cancelled! ************");				
					printf("Press any key to exit:");
					getch();
					exit(0);
				}
				equal1();
				printf("\n%90s","************ Your order has been Successfully Placed ************");
				cart2();
				printf("\n%85s\n","************ Thanks for shopping at BingKart ************");	
				stringcolor("\nDeveloped By Shashank Yenurkar(COPYRIGHT PROTECTED)\n",185);			
				returnn();
				exit(0);
				break;
	
			case 3:
				puts("");
				equal1();
				printf("%70s\n","Net Banking");
				equal1();
				printf("|Enter username|\n->");
				scanf("%d",&crnum);
				printf("|Enter password|\n->");
				scanf("%d",&pass);
				printf("|Enter 1 to proceed to pay Rs.%d|\n->",grand_total);				
				scanf("%d",&pay);
				if(pay!=1)
				{
					minus();
					printf("\n%90s","******************** Transaction Failed! **********************");
					printf("\n\n%85s\n","************ Your order has been cancelled! ************");				
					printf("Press any key to exit:");
					getch();
					break;
				}
				equal1();
				printf("\n%90s","************ Your order has been Successfully Placed ************");
				cart2();
				printf("\n%85s\n","************ Thanks for shopping at BingKart ************");					
				stringcolor("\nDeveloped By Shashank Yenurkar(COPYRIGHT PROTECTED)\n",185);			
				returnn();
				exit(0);
				break;
			case 4:
				puts("");
				equal1();
				printf("%70s\n","Cash on Delivery");
				equal1();
				printf("|Enter 1 to confirm order|\n->");				
				scanf("%d",&pay);
				if(pay!=1)
				{
					minus();
					printf("\n%93s","******************* Order Confirmation Failed! **********************");
					printf("\n\n%85s\n","************ Your order has been cancelled! ************");				;
					printf("Press any key to exit:");
					getch();
					exit(0);
				}
				equal1();
				printf("\n%90s","************ Your order has been Successfully Placed ************");
				cart2();
				printf("\n%85s\n","************ Thanks for shopping at BingKart ************");			
				stringcolor("\nDeveloped By Shashank Yenurkar(COPYRIGHT PROTECTED)\n",185);					
				returnn();
				exit(0);
				
				
			default:
				printf("Invalid Input\n");
				printf("Transaction Failed\n");
				printf("Press any key to exit:");
				getch();
				exit(0);
				
		}//sabse andar wala switch // end of switch 1.2//
		
	
break;//end of case 12//
	
		default://switch 1.0 default
		if(num>10&&num<=20)
		{
			color(8);
			printf("*Product %d added to cart!",num);
			cart1();
			puts("");
			kart++;
			minus();
			bing();
			break;			
		}
		else
		{
			equal1();
			printf("\n%78s","************ Invalid Input ************");
			cart2();
			printf("\n%80s\n","************ Process Terminated ************");					
			printf("Press any key to exit:");
			getch();
			
			puts("");
			minus();
			puts("");
			bing();
			
			exit(0);
			}
						
}//end of1.0 
return 0;
}
int returnn()
{
	stringcolor("Press any key to exit!",207);
	getch();
}
int minus4()//used in head second line//
{
	int v;
	color(8);
	for(v=0;v<=25;v++)
	printf("%c",196);
	color(11);
	return 0;
}
int minus5()
{
	int i;
	color(8);
	for(i=1;i<=120;i++)
	printf("%c",196);
	color(11);

	return 0;	
}
int bingcart()
{
	color(8);
	equal1();
	printf("%45c",' ');
	color(11);
	printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c\n",201,205,187,205,203,205,203,' ',203,201,205,187,201,205,187,201,205,187,201,205,187,205,203,205);
	printf("%45c",' ');
	printf("%c%c%c %c%c%c %c%c%c %c%c%c %c   %c%c%c %c %c  %c\n",204,205,185,' ',186,' ',186,'\\',186,186,205,187,186,204,205,185,186,185,186);
	printf("%45c",' ');
	printf("%c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c %c%c%c",200,205,188,205,202,205,202,' ',202,200,205,188,200,205,188,202,' ',202,202,' ',202,' ',202,' ');
	return 0;
}

int headn1()
{	
	bingcart();
	color(8);
	puts("");
	equal1();
	color(15);
	printf("%50c",' ');
	printf("Welcome To %cingCart\n",225);
	color(8);
	equal1();
	
	printf("\n\n%47c",' ');
	minus4();
	color(8);
	printf("\n%48c ",'|');
	color(11);						  //white//
	printf("%17s","Login Portal");
	color(8);
	printf(" %6c\n",'|');
	printf("%47c",' ');
	minus4();
	color(8);
	printf("\n%48c%25c\n",'/','\\');
	puts("");
	minus5();
	return 0;
}
int headn2()
{	
	bingcart();
	color(8);
	puts("");
	equal1();
	color(15);
	printf("%50c",' ');
	printf("Welcome To %cingCart\n",225);
	color(8);
	equal1();
	
	printf("\n\n%47c",' ');
	minus4();
	color(8);
	printf("\n%48c ",'|');
	color(15);						  //white//
	printf("%17s","Consumer Login");
	color(8);
	printf(" %6c\n",'|');
	printf("%47c",' ');
	minus4();
	color(8);
	printf("\n%48c%25c\n",'/','\\');
	puts("");
	minus5();
	return 0;
}
int headn3()
{	
	bingcart();
	color(8);
	puts("");
	equal1();
	color(15);
	printf("%50c",' ');
	printf("Welcome To %cingCart\n",225);
	color(8);
	equal1();
	return 0;
}
int headn4()
{	
	bingcart();
	color(8);
	puts("");
	equal1();
	color(15);
	printf("%50c",' ');
	printf("Welcome To %cingCart\n",225);
	color(8);
	equal1();
	
	printf("\n\n%47c",' ');
	minus4();
	color(8);
	printf("\n%48c ",'|');
	color(11);						  //white//
	printf("%16s","Admin Login");
	color(8);
	printf(" %7c\n",'|');
	printf("%47c",' ');
	minus4();
	color(8);
	printf("\n%48c%25c\n",'/','\\');
	puts("");
	minus5();
	color(15);
	return 0;
}
int headn5()
{	
	bingcart();
	color(8);
	puts("");
	equal1();
	color(15);
	printf("%50c",' ');
	printf("Welcome To %cingCart\n",225);
	color(8);
	equal1();
	
	printf("\n\n%47c",' ');
	minus4();
	color(8);
	printf("\n%48c ",'|');
	color(15);						  //white//
	printf("%13s","Admin");
	color(8);
	printf(" %10c\n",'|');
	printf("%47c",' ');
	minus4();
	color(8);
	printf("\n%48c%25c\n",'/','\\');
	puts("");
	minus5();
	return 0;
}
int headn6()
{
	bingcart();
	puts("");
	equal1();
	printf("%50c",' ');
	printf("Welcome To %cingCart\n",225);
	equal1();
}
int dash()
{
	color(8);
	printf("%c ",222);
	color(15);
}
int square()
{
	int i,x;
	puts("\n");
	color(8);
	printf("%40c",201);
	for(i=1;i<=40;i++)
	printf("%c",205);
	printf("%c\n",187);
	

	for(i=1;i<=15;i++)
	{
		printf("%39c",' ');
		printf("%c",186);
		if(i==1||i==5||i==7||i==12||i==13)
		{	
			
			if(i==1)
			{
			color(59);
			printf("       %s%4c","Select Type of Your Account  ",' ');
			color(8);
			printf("%c\n",186);	
			
			}
			if(i==5)
			{
				printf("%10c ",222);
				color(15);
				printf("%s","Admin Account");
				color(8);
				printf("%16c%c\n",' ',186);	
			}
			if(i==7)
			{
				printf("%10c ",222);
				color(15);
				printf("%s","Consumer Account");
				color(8);
				printf("%13c%c\n",' ',186);	
			}
			if(i==12)
			{
				printf("%3c ",254);
				color(15);
				printf("%s","Press 1 for Admin Account");
				color(8);
				printf("%11c%c\n",' ',186);	
			}
			if(i==13)
			{
				printf("%3c ",254);
				color(15);
				printf("%s","Press 2 for Consumer Account");
				color(8);
				printf("%8c%c\n",' ',186);	
			}
		}
		else 		
		printf("%40c%c\n",' ',186);
		
	}
	printf("%39c",' ');
	printf("%c",200);
	for(i=1;i<=40;i++)
	printf("%c",205);
	printf("%c",188);
	
	return 0;
}
int inv()
{
	puts("");
	dash();
	printf("Press 1 to try again or Press 2 for main menu:\n->");
	scanf("%d",&e);
	if(e==2)
		{
			system("cls");
			main();
			exit(0);
		}
	else if(e==1)
		entry();
	else
	{
		printf("Invalid Input!\n");
		inv();
		exit(0);			
	}
				
}
int pa,en;
char fetched1[200],ch;
char genfile[100];
char fetid[30],fetpas[30],fetfname[30],fetlname[30];
int entry()
{
	FILE *file;
	char temp_pass[30];
		switch(type)
	{
		case 1:
			system("cls");						
			
			headn2();
			puts("");
			dash();
			printf("Enter your email id : ",222);
			scanf("%s",&uid);
			fflush(stdin);
			dash();		
			printf("Enter your password : ");
			for(pa=0;pa<8;pa++)
			{
				ch=getch();
				upass[pa]=ch;
				ch='*';
				printf("%c",ch);				
			}
			upass[pa]='\0';
			getch();
							
			strcpy(genfile,location);
			strcat(genfile,uid);
			strcat(genfile,txt);
			file=fopen(genfile,"r");		
			if(fgets(fetched1,200,file)!= NULL)
			{
					
			}
			fclose(file);
			sscanf(fetched1,"%s %s %s %s",fetfname,fetlname,fetid,fetpas);
					
			if(strcmp(uid,fetid)==0)
			{			
					if(strcmp(upass,fetpas)==0)
					{
						minus5();
						hellouser();			
					}
					else
					{
						puts("\n");
						minus();
						printf("\n%50c",' ');
						stringcolor("Invalid Email or Password!\n\n",207);
						minus();
						inv();
						fflush(stdin);										
					}	
		    }//end of parent if
			else
			{
				puts("\n");
						minus();
						printf("\n%50c",' ');
						stringcolor("Invalid Email or Password!\n\n",207);
						minus();
						inv();
			}
		break;
		case 2:
			system("cls");
			headn2();
			puts("");
			color(8);
			printf("%50c ",222);	
			color(15);
			printf("%s","Create New Account");
			color(8);
			printf("%c\n",222);	
			printf("%45c",' ');
			minus3();
			color(8);
			acc++;
			printf("\n%45c %s :",222,"First Name");
			color(15);
			scanf("%s",&user[acc].firstname);
			color(8);
			printf("\n%45c %s  :",222,"Last Name");
			color(15);
			scanf("%s",&user[acc].lastname);
			color(8);
			printf("\n%45c %s      :",222,"Email");
			color(15);
			scanf("%s",&user[acc].email);
			//password
			color(8);
			printf("%45c",' ');
			minus3();
			puts("");
			color(8);
			printf("%49c ",222);	
			color(15);
			printf("%s","8 Characters Only");
			color(8);
			printf("%c\n",222);				
			printf("\n%45c %s   :",222,"Password");
			color(15);
			scanf("%s",&user[acc].password);
			printf("\n%45c",' ');
			minus3();
			puts("");
			printf("%49c",' ');
			charcolor(222,8);			
			color(15);			
			printf("%s"," Confirm Password ");
			charcolor(222,8);			
			color(8);
			printf("\n\n%45c %s   :",222,"Password");
			color(15);
			scanf("%s",&temp_pass);
					
			if(strcmp(user[acc].password,temp_pass)==0)
			{
			color(8);
			printf("%45c",' ');
			minus3();
			printf("\n%45c",' ');
			color(207);
			printf("%s","Account Successfully Created!\n");
			color(15);
			minus();
			
			//file handling//			
				strcpy(genfile,location);
				strcat(genfile,user[acc].email);
				strcat(genfile,txt);
				write_acc_data(genfile,user[acc].firstname,user[acc].lastname,user[acc].email,user[acc].password);
			//file handling//
								
			printf("\nPress any key to go back to main menu:");
			getch();
			fflush(stdin);
			system("cls");
			main();
			exit(0);
		}
		else
		{
			printf("\n%45c",' ');
			minus3();
			printf("\n%46c",' ');
			stringcolor("Password Confirmation Failed!\n",207);
			color(12);
			printf("\n%c Press any key to continue:",222);
			getch();
			system("cls");
			main();
			exit(0);
		}
		
		
		
		break;	
		default:
			minus();
			printf("%52c",' ');
			stringcolor("Invalid Input!\n",207);
			printf("\n%47c",' ');
			stringcolor("Press any key to try again",207);
			getch();
			system("cls");
			main();
			exit(0);
		break;
								
	}
}
int consumer()
{
	system("cls");
	headn2();
	color(8);
	printf("\n%c",222);
	color(15);
	printf(" Press 1 if you are an existing customer!\n");
	color(8);
	printf("\n%c",222);
	color(15);
	printf(" Press 2 if you are new to %cingCart!\n->",225);
	scanf("%d",&type);
	entry();
}
int delay()
{
	int i,k;
	for(i=1;i<=10;i++)
	{
		for(k=1;k<100000000;k++)
		{
			
		}
	}
	return 0;
	
}
int delay1()
{
	int i,k;
	for(i=1;i<=10;i++)
	{
		for(k=1;k<15000000;k++)
		{
			
		}
	}
	return 0;
	
}
int delay2()
{
	int i,k;
	for(i=1;i<=10;i++)
	{
		for(k=1;k<10000000;k++)
		{
			
		}
	}
	return 0;
}
int loading()
{	
	int i,b;
	color(8);
	printf("\n%99c",222);
	color(15);
	printf(" %s","Loading");
	for(i=1;i<=7;i++)
	{
		printf(".");
		for(b=1;b<100000000;b++)
		{
			
		}
	}
	return 0;
}
int hii()
{
	int t,r;
	printf("%55c",' ');
	for(r=0;hi[r]!='\0';r++)
	{
		printf("%c",hi[r]);
		delay2();
	}
	printf(" ");
	for(t=0;fetfname[t]!='\0';t++)
	{
		printf("%c",fetfname[t]);
		delay2();
	}
	puts("");
	printf("%50c",' ');
}

int hellouser()
{
	system("cls");
	headn3();
	puts("");
	puts("");
	hii();	
	puts("");
	puts("");
	system("cls");
	headn3();
	color(15);
	bing();
}
int addproduct()
{		
		pr++;
		puts("");
		charcolor(222,8);
		printf(" Enter Product Name: ");
		fflush(stdin);
		gets(pro[pr].name);		
		
		puts("");
		charcolor(222,8);
		printf(" Enter Product Price: ");
		scanf("%d",&product.price[pr]);
		fflush(stdin);
		
		puts("");
		charcolor(222,8);
		printf(" Enter Quantity available: ");
		fflush(stdin);
		scanf("%d",&q.quantity[pr]);
		
		puts("");
		charcolor(222,8);
		printf(" Enter RAM size(GB): ");
		fflush(stdin);
		scanf("%d",&features[pr].ram);
		
		puts("");
		charcolor(222,8);
		printf(" Enter ROM size(GB): ");
		fflush(stdin);
		scanf("%d",&features[pr].rom);
		
		puts("");
		charcolor(222,8);
		printf(" Enter ROM Size Expandable upto(GB): ");
		fflush(stdin);
		scanf("%d",&features[pr].expupto);
		
		puts("");
		charcolor(222,8);
		printf(" Enter Screen size(Inch): ");
		fflush(stdin);
		scanf("%d",&features[pr].screensize);
		
		puts("");
		charcolor(222,8);
		printf(" Enter Rear Camera Pixels(MP): ");
		fflush(stdin);
		scanf("%d",&features[pr].rc);
		
		puts("");
		charcolor(222,8);
		printf(" Enter Front Camera Pixels(MP): ");
		fflush(stdin);
		scanf("%d",&features[pr].fc);	
		
		puts("");
		charcolor(222,8);
		printf(" Enter Battery Capacity(MAH): ");
		fflush(stdin);
		scanf("%d",&features[pr].mah);
		
		puts("");
		charcolor(222,8);
		printf(" Enter Processor Name: ");
		fflush(stdin);
		scanf("%s",&features[pr].processor);
		fflush(stdin);
		color(8);
		minus();
		puts("");
		charcolor(222,8);
		printf(" Enter 1 to add more products     ");
		charcolor(222,8);
		puts("\n");
		charcolor(222,8);
		printf(" Enter 2 to see the product list  ");
		charcolor(222,8);
		puts("");
		printf("->");
		fflush(stdin);
		scanf("%d",&ad);
		if(ad==1)
				{
					system("cls");
					addproduct();
					
						
				}
				else if(ad==2)
				{
					system("cls");
					body1();
					minus();
					charcolor(222,8);
					printf("%s"," Press 1 to go back    ");
					charcolor(222,8);
					puts("\n");
					charcolor(222,8);
					printf(" Press 2 for main menu ");
					charcolor(222,8);
					puts("");
					printf("->");
					scanf("%d",&ac);
					if(ac==1)
					{						
						manipulate();
									
					}
					else if(ac==2)
					{
						system("cls");
						main();
						
					}
					else
					{
						
						minus();
						printf("%53c",' ');
						stringcolor("Invalid Input!",207);						
						printf("\n\n%47c",' ');
						stringcolor("Press any key to continue",207);
						getch();
						system("cls");
						main();
					}
					
				}
				else 
				{
					printf("Wrong input!");
					printf("\nPress any key to try again: ");
					getch();
					manipulate();	
				}	
	
}
int del()
{
	pr--;
				for(var=position-1;var<=pr-1;var++)
					{
						strcpy(pro[var].name,pro[var+1].name);
						product.price[var] = product.price[var+1];
						q.quantity[var] = q.quantity[var+1];
						features[var].expupto=features[var+1].expupto;
						features[var].fc=features[var+1].fc;
						features[var].mah=features[var+1].mah;
						strcpy(features[var].processor,features[var+1].processor);
						features[var].ram=features[var+1].ram;
						features[var].rc=features[var+1].rc;
						features[var].rom=features[var+1].rom;
						features[var].screensize=features[var+1].screensize;
					}
			puts("");
			color(8);
			minus();
			charcolor(222,8);
			printf(" Enter 1 to view the Product list ");				
			charcolor(222,8);
			puts("\n");
			charcolor(222,8);
			printf(" Enter 2 to delete more Products  ");				
			charcolor(222,8);
			puts("");
			scanf("%d",&ae);
			if(ae==1)
			{
				puts("");
				body1();
				color(8);
				minus();
				charcolor(222,8);	
				printf(" Press any key to get back to main menu:");
				getch();
				system("cls");
				main();
				exit(0);
			}
			else if(ae==2)
			{
				system("cls");
				deleteproduct();
			}
			else
			{
				stringcolor("Invalid Input!",207);
				main();
				exit(0);
			}
}
int deleteproduct()
{
				headn5();
				puts("");
				charcolor(222,8);
				printf(" Enter Pr.No. of the Product You want to Delete: ");
				scanf("%d",&position);
				
				if(position>=1&&position<=pr+1)
					del();
				else
					{
						minus();
						printf("%52c",' ');
						stringcolor("Invalid Input!\n",207);
						printf("\n%47c",' ');
						stringcolor("Press any key to try again",207);
						getch();
						system("cls");
						manipulate();
						exit(0);
										
					}	
}
int manipulate()//showing admin options to manipulate product list//
{
		system("cls");
		headn5();
		puts("");
		charcolor(222,8);
		printf(" Enter 1 to see Product list ");
		charcolor(222,8);
		puts("\n");
		charcolor(222,8);
		printf(" Enter 2 to add Products     ");
		charcolor(222,8);
		puts("\n");
		charcolor(222,8);
		printf(" Enter 3 to delete Products  ");
		charcolor(222,8);
		puts("\n");
		charcolor(222,8);
		printf(" Enter 4 for main menu       ");
		charcolor(222,8);
		printf("\n->");
		scanf("%d",&choice);
		
		switch(choice)//switch for admin choices//
		{
			case 1:
				system("cls");
				headn5();
				color(15);
				body1();
				minus();
				printf("Press any key to go back:");
				getch();
				manipulate();
				exit(0);	
			break;
			
			case 2:
				system("cls");
				headn5();
				addproduct();
			break;
			
			case 3:
				system("cls");
				deleteproduct();
			case 4:
				system("cls");
				main();
				exit(0);
			break;		
			default:
			minus();
			printf("%52c",' ');
			stringcolor("Invalid Input!\n",207);
			printf("\n%47c",' ');
			stringcolor("Press any key to try again",207);
			getch();
			system("cls");
			manipulate();
			exit(0);
		
		}
	
}
int admin()//this is login for admin
{
	int ab;
	system("cls");
	headn4();
	color(8);
	printf("\n%45c ",222);
	color(15);
	printf("Enter email    : ");
	scanf("%s",&uid);
	color(8);
	printf("\n%45c ",222);
	color(15);
	printf("Enter password : ");
	for(pa=0;pa<5;pa++)
	{
		ch=getch();
		fflush(stdin);
		upass[pa]=ch;
		ch='*';
		printf("%c",ch);
	}	
	upass[pa]='\0';	
	getch();
	
	a=strcmp(uid,adminemail);
	b=strcmp(upass,adminpass);
	if(a==0&&b==0)
	{
		system("cls");
		headn4();
		logging();
		manipulate();
		
	}
	else
	{
		puts("");
		color(8);
		minus();
		printf("\n%47c",' ');
		stringcolor("Invalid Email or Password!\n",207);
		charcolor(222,8);
		printf("%s"," Press 1 to try again  ");
		charcolor(222,8);
		puts("\n");
		charcolor(222,8);
		printf(" Press 2 for main menu ");
		charcolor(222,8);
		puts("");
		printf("->");
		scanf("%d",&ab);
		if(ab==1)
			admin();
		else if(ab==2)
		{
			system("cls");
			main();	
		}
		else
		{
			minus();
			printf("%52c",' ');
			stringcolor("Invalid Input!\n",207);
			printf("\n%47c",' ');
			stringcolor("Press any key to continue",207);
			getch();
			system("cls");
			main();
		}
	}
		
}
int login()
{
	int log;
	puts("");
	printf("%39c%c ",' ',222);
	color(15);
	scanf("%d",&log);
	switch (log)
	{
		case 1:
		admin();	
			break;
		case 2:
			consumer();
			break;
		default:
			printf("%51c",' ');
			stringcolor("Invalid Input!\n\n",207);
			printf("%45c",' ');
			stringcolor("Press any key to try again\n",207);
			getch();
			system("cls");
			main();
			exit(0);
	}
}
int logging()
{	
	int i,b;
	color(8);
	printf("\n%99c",222);
	color(15);
	printf(" %s","Logging in");
	for(i=1;i<=7;i++)
	{
		printf(".");
		for(b=1;b<100000000;b++)
		{
			
		}
	}
	return 0;
}
int main()
{
	headn1();
	square();
	login();	
	return 0;
}
