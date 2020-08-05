 /////////////////////////????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
#include<iostream>
using namespace std;
#include<cstring>
#include<string>
#include<windows.h>
#include<cstdio>
#include<time.h>
//////////////////////////????????????????????????????????????????????????????????????????????????????????????????????????????????????????????



class money{
public:
    char name[30];
    float pool;

};


class carlist{
    public:
char name[30];
char color[30];
int model;
};





class Address{
protected:
    char shoghl[30];
    char khiaban_mahal_kar[30];
    char kode_posti_mahal_kar[30];
    char telephone_mahal_kar[30];
public:
    Address(char *shoghl1,char *khiaban_mahal_kar1,char *kode_posti_mahal_kar1,char *telephone_mahal_kar1){
    strcpy(this->shoghl,shoghl1);
    strcpy(this->khiaban_mahal_kar,khiaban_mahal_kar1);
    strcpy(this->kode_posti_mahal_kar,kode_posti_mahal_kar1);
    strcpy(this->telephone_mahal_kar,telephone_mahal_kar1);

    }
};

class Human_Customer:Address{
private:
    char name[30];
    char mobile[30];
    char tarikh_tavalod[30];
    char kode_meli[30];
public:
    Human_Customer(char *shoghl1,char *khiaban_mahal_kar1,char *kode_posti_mahal_kar1,char *telephone_mahal_kar1,char *name1,char *mobile1,char *tarikh_tavalod1,char *kode_meli1):
    Address( shoghl1, khiaban_mahal_kar1, kode_posti_mahal_kar1, telephone_mahal_kar1)
    {
    strcpy(this->shoghl,shoghl1);
    strcpy(this->khiaban_mahal_kar,khiaban_mahal_kar1);
    strcpy(this->kode_posti_mahal_kar,kode_posti_mahal_kar1);
    strcpy(this->telephone_mahal_kar,telephone_mahal_kar1);
    strcpy(this->name,name1);
    strcpy(this->mobile,mobile1);
    strcpy(this->tarikh_tavalod,tarikh_tavalod1);
    strcpy(this->kode_meli,kode_meli1);
    }
void print(){
    cout<<"-------------------------------------------------\n";
cout<<"name forooshande :  "<<this->name<<endl;
cout<<"kode meli forooshande :  "<<this->kode_meli<<endl;
cout<<"tarikh tavalod forooshande :  "<<this->tarikh_tavalod<<endl;
cout<<"mobile forooshande :  "<<this->mobile<<endl;
cout<<"telephone forooshande :  "<<this->telephone_mahal_kar<<endl;
cout<<"kode posti forooshande :  "<<this->kode_posti_mahal_kar<<endl;
cout<<"khiaban mahal kar forooshande :  "<<this->khiaban_mahal_kar<<endl;
cout<<"shoghle forooshande :  "<<this->shoghl<<endl;
cout<<"-------------------------------------------------\n";

}
};

operator <<(ostream &cout,class Human_Customer a){

a.print();
}

class Human_Seller:Address{
private:
    char name[30];
    char mobile[30];
    char tarikh_tavalod[30];
    char kode_meli[30];
public:
    Human_Seller(char *shoghl1,char *khiaban_mahal_kar1,char *kode_posti_mahal_kar1,char *telephone_mahal_kar1,char *name1,char *mobile1,char *tarikh_tavalod1,char *kode_meli1):
    Address( shoghl1, khiaban_mahal_kar1, kode_posti_mahal_kar1, telephone_mahal_kar1)
    {
    strcpy(this->shoghl,shoghl1);
    strcpy(this->khiaban_mahal_kar,khiaban_mahal_kar1);
    strcpy(this->kode_posti_mahal_kar,kode_posti_mahal_kar1);
    strcpy(this->telephone_mahal_kar,telephone_mahal_kar1);
    strcpy(this->name,name1);
    strcpy(this->mobile,mobile1);
    strcpy(this->tarikh_tavalod,tarikh_tavalod1);
    strcpy(this->kode_meli,kode_meli1);
    }
    void print(){
    cout<<"-------------------------------------------------\n";
cout<<"name kharidar :  "<<this->name<<endl;
cout<<"kode meli kharidar :  "<<this->kode_meli<<endl;
cout<<"tarikh tavalod kharidar :  "<<this->tarikh_tavalod<<endl;
cout<<"mobile kharidar :  "<<this->mobile<<endl;
cout<<"telephone kharidar :  "<<this->telephone_mahal_kar<<endl;
cout<<"kode posti kharidar :  "<<this->kode_posti_mahal_kar<<endl;
cout<<"khiaban mahal kar kharidar :  "<<this->khiaban_mahal_kar<<endl;
cout<<"shoghle kharidar :  "<<this->shoghl<<endl;
cout<<"-------------------------------------------------\n";

}

};

operator <<(ostream &cout,class Human_Seller a){

a.print();
}



class Car_information{
protected:

char Rangeh_car[30];
char Sale_Tolide_car[30];
char Shomareh_Sanad_car[30];
char Saheb_sanad_car[30];
char Karkard_car[30];
char Moshakhasat_car[1000];
char Rangeh_Dakheleh_car[30];
char Shomare_Pelakeh_car[30];
char Shomareh_Shasi_car[30];
char Gheimateh_Foroosh_car[30];
public:
    Car_information(char *Rangeh_car1,char *Sale_Tolide_car1,char *Shomareh_Sanad_car1,char *Saheb_sanad_car1,char *Karkard_car1,char *Moshakhasat_car1,char *Rangeh_Dakheleh_car1,char *Shomare_Pelakeh_car1,char *Shomareh_Shasi_car1,char *Gheimateh_Foroosh_car1){
    strcpy(this->Rangeh_car,Rangeh_car1);
    strcpy(this->Sale_Tolide_car,Sale_Tolide_car1);
    strcpy(this->Shomareh_Sanad_car,Shomareh_Sanad_car1);
    strcpy(this->Saheb_sanad_car,Saheb_sanad_car1);
    strcpy(this->Karkard_car,Karkard_car1);
    strcpy(this->Moshakhasat_car,Moshakhasat_car1);
    strcpy(this->Rangeh_Dakheleh_car,Rangeh_Dakheleh_car);
    strcpy(this->Shomare_Pelakeh_car,Shomare_Pelakeh_car1);
    strcpy(this->Shomareh_Shasi_car,Shomareh_Shasi_car1);
    strcpy(this->Gheimateh_Foroosh_car,Gheimateh_Foroosh_car1);


    }



};

class Brand{
protected:
    char brand_car[30];

public:
    Brand(char *brand_car1){

    strcpy(this->brand_car,brand_car1);
    }



};
class hyundai: Brand, Car_information{
protected:
    char Name_car[30];
    char hybrid_or_normal[30];
public:

    hyundai(char *Rangeh_car1,char *Sale_Tolide_car1,char *Shomareh_Sanad_car1,char *Saheb_sanad_car1,char *Karkard_car1,char *Moshakhasat_car1,char *Rangeh_Dakheleh_car1,char *Shomare_Pelakeh_car1,char *Shomareh_Shasi_car1,char *Gheimateh_Foroosh_car1,char *brand_car1,char *Name_car1,char *hybrid_or_normal1)
    :Brand(brand_car1)
    ,Car_information(Rangeh_car1,Sale_Tolide_car1,Shomareh_Sanad_car1,Saheb_sanad_car1,Karkard_car1,Moshakhasat_car1,Rangeh_Dakheleh_car1,Shomare_Pelakeh_car1,Shomareh_Shasi_car1,Gheimateh_Foroosh_car1)
    {
    strcpy(this->Rangeh_car,Rangeh_car1);
    strcpy(this->Sale_Tolide_car,Sale_Tolide_car1);
    strcpy(this->Shomareh_Sanad_car,Shomareh_Sanad_car1);
    strcpy(this->Saheb_sanad_car,Saheb_sanad_car1);
    strcpy(this->Karkard_car,Karkard_car1);
    strcpy(this->Moshakhasat_car,Moshakhasat_car1);
    strcpy(this->Rangeh_Dakheleh_car,Rangeh_Dakheleh_car);
    strcpy(this->Shomare_Pelakeh_car,Shomare_Pelakeh_car1);
    strcpy(this->Shomareh_Shasi_car,Shomareh_Shasi_car1);
    strcpy(this->Gheimateh_Foroosh_car,Gheimateh_Foroosh_car1);
    strcpy(this->brand_car,brand_car1);
    strcpy(this->Name_car,Name_car1);
    strcpy(this->hybrid_or_normal,hybrid_or_normal1);
    }


void print(){
    cout<<"----------------------------------------------------\n";
    cout<<"range mashin : "<<this->Rangeh_car<<endl;
    cout<<"sale tolide mashin : "<<this->Sale_Tolide_car<<endl;
    cout<<"shomare sanade mashin : "<<this->Shomareh_Sanad_car<<endl;
    cout<<"saheb sanade mashin : "<<this->Saheb_sanad_car<<endl;
    cout<<"karkard mahin : "<<this->Karkard_car<<endl;
    cout<<this->Moshakhasat_car<<endl;
    cout<<"range dakhele mahin : "<<this->Rangeh_Dakheleh_car<<endl;
    cout<<"shomare pelak :"<<this->Shomare_Pelakeh_car<<endl;
    cout<<"shomare shasi : "<<this->Shomareh_Shasi_car<<endl;
    cout<<"gheymat foroosh : "<<this->Gheimateh_Foroosh_car<<endl;
    cout<<"brand mashin : "<<this->brand_car<<endl;
    cout<<"name mashin : "<<this->Name_car<<endl;
    cout<<"this car is : "<<this->hybrid_or_normal<<endl;
cout<<"----------------------------------------------------\n";
}

};
class kia: Brand, Car_information{
protected:
    char Name_car[30];
    char hybrid_or_normal[30];
public:

    kia(char *Rangeh_car1,char *Sale_Tolide_car1,char *Shomareh_Sanad_car1,char *Saheb_sanad_car1,char *Karkard_car1,char *Moshakhasat_car1,char *Rangeh_Dakheleh_car1,char *Shomare_Pelakeh_car1,char *Shomareh_Shasi_car1,char *Gheimateh_Foroosh_car1,char *brand_car1,char *Name_car1,char *hybrid_or_normal1)
    :Brand(brand_car1)
    ,Car_information(Rangeh_car1,Sale_Tolide_car1,Shomareh_Sanad_car1,Saheb_sanad_car1,Karkard_car1,Moshakhasat_car1,Rangeh_Dakheleh_car1,Shomare_Pelakeh_car1,Shomareh_Shasi_car1,Gheimateh_Foroosh_car1)
    {
    strcpy(this->Rangeh_car,Rangeh_car1);
    strcpy(this->Sale_Tolide_car,Sale_Tolide_car1);
    strcpy(this->Shomareh_Sanad_car,Shomareh_Sanad_car1);
    strcpy(this->Saheb_sanad_car,Saheb_sanad_car1);
    strcpy(this->Karkard_car,Karkard_car1);
    strcpy(this->Moshakhasat_car,Moshakhasat_car1);
    strcpy(this->Rangeh_Dakheleh_car,Rangeh_Dakheleh_car);
    strcpy(this->Shomare_Pelakeh_car,Shomare_Pelakeh_car1);
    strcpy(this->Shomareh_Shasi_car,Shomareh_Shasi_car1);
    strcpy(this->Gheimateh_Foroosh_car,Gheimateh_Foroosh_car1);
    strcpy(this->brand_car,brand_car1);
    strcpy(this->Name_car,Name_car1);
    strcpy(this->hybrid_or_normal,hybrid_or_normal1);
    }
void print(){
    cout<<"----------------------------------------------------\n";
    cout<<"range mashin : "<<this->Rangeh_car<<endl;
    cout<<"sale tolide mashin : "<<this->Sale_Tolide_car<<endl;
    cout<<"shomare sanade mashin : "<<this->Shomareh_Sanad_car<<endl;
    cout<<"saheb sanade mashin : "<<this->Saheb_sanad_car<<endl;
    cout<<"karkard mahin : "<<this->Karkard_car<<endl;
    cout<<this->Moshakhasat_car<<endl;
    cout<<"range dakhele mahin : "<<this->Rangeh_Dakheleh_car<<endl;
    cout<<"shomare pelak :"<<this->Shomare_Pelakeh_car<<endl;
    cout<<"shomare shasi : "<<this->Shomareh_Shasi_car<<endl;
    cout<<"gheymat foroosh : "<<this->Gheimateh_Foroosh_car<<endl;
    cout<<"brand mashin : "<<this->brand_car<<endl;
    cout<<"name mashin : "<<this->Name_car<<endl;
    cout<<"this car is : "<<this->hybrid_or_normal<<endl;
    cout<<"----------------------------------------------------\n";

}




};





class AnotherCar:Brand,Car_information{
protected:
    char Name_car[30];
    char hybrid_or_normal[30];
public:

    AnotherCar(char *Rangeh_car1,char *Sale_Tolide_car1,char *Shomareh_Sanad_car1,char *Saheb_sanad_car1,char *Karkard_car1,char *Moshakhasat_car1,char *Rangeh_Dakheleh_car1,char *Shomare_Pelakeh_car1,char *Shomareh_Shasi_car1,char *Gheimateh_Foroosh_car1,char *brand_car1,char *Name_car1,char *hybrid_or_normal1)
    :Brand(brand_car1)
    ,Car_information(Rangeh_car1,Sale_Tolide_car1,Shomareh_Sanad_car1,Saheb_sanad_car1,Karkard_car1,Moshakhasat_car1,Rangeh_Dakheleh_car1,Shomare_Pelakeh_car1,Shomareh_Shasi_car1,Gheimateh_Foroosh_car1)
    {
    strcpy(this->Rangeh_car,Rangeh_car1);
    strcpy(this->Sale_Tolide_car,Sale_Tolide_car1);
    strcpy(this->Shomareh_Sanad_car,Shomareh_Sanad_car1);
    strcpy(this->Saheb_sanad_car,Saheb_sanad_car1);
    strcpy(this->Karkard_car,Karkard_car1);
    strcpy(this->Moshakhasat_car,Moshakhasat_car1);
    strcpy(this->Rangeh_Dakheleh_car,Rangeh_Dakheleh_car);
    strcpy(this->Shomare_Pelakeh_car,Shomare_Pelakeh_car1);
    strcpy(this->Shomareh_Shasi_car,Shomareh_Shasi_car1);
    strcpy(this->Gheimateh_Foroosh_car,Gheimateh_Foroosh_car1);
    strcpy(this->brand_car,brand_car1);
    strcpy(this->Name_car,Name_car1);
    strcpy(this->hybrid_or_normal,hybrid_or_normal1);
    }


    void print(){
        cout<<"----------------------------------------------------\n";
    cout<<"range mashin : "<<this->Rangeh_car<<endl;
    cout<<"sale tolide mashin : "<<this->Sale_Tolide_car<<endl;
    cout<<"shomare sanade mashin : "<<this->Shomareh_Sanad_car<<endl;
    cout<<"saheb sanade mashin : "<<this->Saheb_sanad_car<<endl;
    cout<<"karkard mahin : "<<this->Karkard_car<<endl;
    cout<<this->Moshakhasat_car<<endl;
    cout<<"range dakhele mahin : "<<this->Rangeh_Dakheleh_car<<endl;
    cout<<"shomare pelak :"<<this->Shomare_Pelakeh_car<<endl;
    cout<<"shomare shasi : "<<this->Shomareh_Shasi_car<<endl;
    cout<<"gheymat foroosh : "<<this->Gheimateh_Foroosh_car<<endl;
    cout<<"brand mashin : "<<this->brand_car<<endl;
    cout<<"name mashin : "<<this->Name_car<<endl;
    cout<<"this car is : "<<this->hybrid_or_normal<<endl;
    cout<<"----------------------------------------------------\n";

}


};



operator <<(ostream&out,hyundai h){
h.print();
}
 operator <<(ostream&out,kia h){
h.print();
}
operator <<(ostream&out,AnotherCar h){
h.print();
}













class usefull{
public:
    int i;
    char name[30];
    char money[30];
    char mobile[30];
};



void nowdate(long long int*d,long long int*m,long long int*y){//a fun for calculate time of now
    time_t second;
    second=time(NULL);
long long int p,q,w,g,f,f1,h;
p=second/(24*3600);
q=p/365;
w=p%365;
f=w/30;
f1=w%30;
g=f1%30;
*y=q+1970;
*m=f+1;
h=q/4;
*d=g+1-h;
if(*d<0){
*m=*m-1;
 *d=30+*d;
}

}//end of fun









class Etelaatt_Chek{
private:
    int tedad_chek;
public:
    Etelaatt_Chek(int a){
    tedad_chek=a;
    }
    void mohasebe_kharid(){
    for(int i=0;i<tedad_chek;i++){
        cout<<"please enter day : ";
        long long int day;
        cin>>day;
        cout<<"please enter month : ";
        long long int month;
        cin>>month;
        cout<<"please enter year : ";
        int year;
        cin>>year;
        cout<<"money : ";
        int money;
        cin>>money;
        FILE*chek;
        chek=fopen("chek.txt","a");
        char command[20];
        sprintf(command,"%lld/%lld/%d",day,month,year);
        long long int tarikh=(365*year)+(30*month)+(day);
        fprintf(chek,"%d %lld %s\n",money,tarikh,command);
        fclose(chek);
    }

    }
     void mohasebe_foroosh(){
    for(int i=0;i<tedad_chek;i++){
        cout<<"please enter day : ";
        long long int day;
        cin>>day;
        cout<<"please enter month : ";
        long long int month;
        cin>>month;
        cout<<"please enter year : ";
        int year;
        cin>>year;
        cout<<"money : ";
        int money;
        cin>>money;
        char command[20];
        sprintf(command,"%lld/%lld/%d",day,month,year);
        FILE*chekf;
        chekf=fopen("chekf.txt","a");
        long long int tarikh=(365*year)+(30*month)+(day);
        fprintf(chekf,"%d %lld %s\n",money,tarikh,command);
        fclose(chekf);
    }


     }




};








void show_near_chek(){

int money;
long long int tarikh;
long long int tarikhf;
int moneyf;
long long int day;
long long int month;
long long int year;
nowdate(&day,&month,&year);
long long int now_tarikh;
now_tarikh=(365*year)+(30*month)+(day);
char command[20];
FILE*chek;
FILE*chekf;
chek=fopen("chek.txt","r");
chekf=fopen("chekf.txt","r");
int sum=0;
int sumf=0;
int i=0;
int i_f=0;
int kk=0;
int kkf=0;
while(!feof(chek)){
        i++;
    fscanf(chek,"%d %lld %s\n",&money,&tarikh,command);
if(i==0){
    kk=money;
}
    if(tarikh-now_tarikh<=30&&tarikh-now_tarikh>=0){
            cout<<"shoma dar kamtar az 30 rooze ayande bayad chek be mablagh "<<money<<"    million toman "<<"pass konid   "<<command<<endl<<endl<<endl;


    }


}




while(!feof(chekf)){

    fscanf(chekf,"%d %lld %s\n",&moneyf,&tarikhf,command);




    if(tarikhf-now_tarikh<=30&&tarikhf-now_tarikh>=0){
         cout<<"shoma dar kamtar az 30 rooze ayande bayad chek be mablagh "<<moneyf<<"    million toman "<<"vosool konid  "<<command<<endl<<endl<<endl;


    }


}


fclose(chek);
fclose(chekf);

}

class por_daram_tarin_mah{
long long int month;
int year;
float poorsant;
public:
    void show(){
        int monthp;
        int monthk;
        int Max=0;
        int Min=1000;
     long long int d;
    long long int m;
     long long int y;
     nowdate(&d,&m,&y);

      float mp[12]={0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00};



    FILE*por_kam;
    por_kam=fopen("daram_poorsant_max_min.txt","r");
    while(!feof(por_kam)){

        fscanf(por_kam,"%f %lld %d",&poorsant,&month,&year);

        if(year==y){

                if(month==1){
                    mp[0]+=poorsant;
                }
                else if(month==2){
                    mp[1]+=poorsant;
                }
                else if(month==3){
                    mp[2]+=poorsant;
                }
                else if(month==4){
                    mp[3]+=poorsant;
                }
                else if(month==5){
                    mp[4]+=poorsant;
                }
                else if(month==6){
                    mp[5]+=poorsant;
                }
                else if(month==7){
                    mp[6]+=poorsant;
                }
                 else if(month==8){
                    mp[7]+=poorsant;
                }
                else if(month==9){
                    mp[8]+=poorsant;
                }
                else if(month==10){
                    mp[9]+=poorsant;
                }
                else if(month==11){
                    mp[10]+=poorsant;
                }
                else if(month==12){
                    mp[11]+=poorsant;
                }

                for(int i=0;i<12;i++){
                    if(mp[i]>Max)
                    {
                        Max=mp[i];
                        monthp=i+1;
                    }
                    if(mp[i]<Min){
                        Min=mp[i];
                        monthk=i+1;
                    }

                }//end of for


        }//end of if(year==y)

    }//end of while
    cout<<"in sal : "<<y<<endl<<endl<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n";
    cout<<"por daram tarin mah az nazar poorsant dar in sal : "<<monthp<<endl<<endl<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n";
    cout<<"kam daramad tarin mah az nazar poorsant dar in sal : "<<monthk<<endl<<endl<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n";

    fclose(por_kam);

    }//end of function


};


















class userinfo{
    public:
char name[30];
char family[30];
char nameofauto[30];
char username[30];
char password[30];
char secondpassword[30];
};

class buy_car_sell{
    public:
char Nameh_Kharidar[30];
char Kodeh_melli_Khridar[30];
char Shomare_Mobile_Kharidar[30];
////////////////////////
char Name_car[30];
char Rangeh_car[30];
 char Sale_Tolide_car[30];////////////////////////////////////////
char Shomareh_Sanad_car[30];/////////////////////////////////////
char Saheb_sanad_car[30];////////////////////////////////////////
char Brand_car[30];//////////////////////////////////////
char Karkard_car[30];/////////////////////////////////
char Moshakhasat_car[1000];//////////////////////////////
char Rangeh_Dakheleh_car[30];
char Shomare_Pelakeh_car[30];
char Shomareh_Shasi_car[30];
char Gheimateh_Foroosh_car[30];
/////////////
char Nameh_Saheb[30];
char Kodeh_melli_Saheb[30];
char Shomare_Mobile_Saheb[30];
}customer;



class Poole_Sarmayeh_Gozary{



public:
    float money;
}users1[100000];




void sarmayeh(){
FILE*mone;
float mm;
mone=fopen("mone.txt","r");
float sum=0;
int i=-1;
while(!feof(mone)){
i++;
    fscanf(mone,"%f",&users1[i].money);
    sum+=users1[i].money;


}
fclose(mone);
cout<<"Poole_Sarmaye_Gozari_Shode_Tavasote_Sarmaye_Gozaran : "<<double(sum)<<" million toman"<<endl<<endl<<endl;


}



class tedad_foroosh{
public:
    int tedad;
    long long int day;
    long long int month;
    int year;
}x;


class tedad_kharid{
public:
    int tedad;
    long long int day;
    long long int month;
    int year;
}y;



void tedad_kharid()
{


    cout<<"please enter two date : \n";
long long int day;
long long int month;
int year;
long long int day1;
long long  int month1;
int year1;
cout<<"first date(day) : ";
cin>>day;
cout<<"first date(month) : ";
cin>>month;
cout<<"first date(year) : ";
cin>>year;


long long int date=(year*10000)+(month*100)+(day);


char command1[20];
sprintf(command1,"%lld/%lld/%d",day,month,year);


cout<<"second date(day) : ";
cin>>day1;
cout<<"second date(month) : ";
cin>>month1;
cout<<"second date(year) : ";
cin>>year1;

long long int date1=(year1*10000)+(month1*100)+(day1);



char command2[20];
sprintf(command2,"%lld/%lld/%d",day1,month1,year1);




    FILE*kharid;
    kharid=fopen("tedad kharid.txt","r");
    int sum=0;
    while(!feof(kharid)){
        fscanf(kharid,"%d %lld %lld %d",&x.tedad,&x.day,&x.month,&x.year);
long long int yourdate=(x.year*10000)+(x.month*100)+(x.day);


        if(yourdate>=date&&yourdate<=date1){


        sum+=x.tedad;

        }

    }
    system("pause");
    system("cls");
    cout<<"tedade khodro kharide shode dar tarikh morede nazar : "<<sum-1<<endl;
    fclose(kharid);
}








void tedad_foroosh()
{


    cout<<"please enter two date : \n";
long long int day;
long long int month;
int year;
long long int day1;
long long  int month1;
int year1;
cout<<"first date(day) : ";
cin>>day;
cout<<"first date(month) : ";
cin>>month;
cout<<"first date(year) : ";
cin>>year;




char command1[20];
sprintf(command1,"%lld/%lld/%d",day,month,year);


cout<<"second date(day) : ";
cin>>day1;
cout<<"second date(month) : ";
cin>>month1;
cout<<"second date(year) : ";
cin>>year1;


char command2[20];
sprintf(command2,"%lld/%lld/%d",day1,month1,year1);



long long int date=(10000*year)+(100*month)+(day);
        long long int date1=(10000*year1)+(100*month1)+(day1);
    FILE*foroosh;
    foroosh=fopen("tedad foroosh.txt","r");
    int sum=0;
    while(!feof(foroosh)){
        fscanf(foroosh,"%d %lld %lld %d",&y.tedad,&y.day,&y.month,&y.year);


        long long int yourdate=(10000*y.year)+(100*y.month)+(y.day);


        if(yourdate>=date&&yourdate<=date1){


        sum+=y.tedad;

        }

    }
    system("pause");
    system("cls");

    cout<<"tedade khodro forooosh shode dar tarikh morede nazar : "<<sum-1<<endl;
fclose(foroosh);
}







class daramd_poorsant{
public:
    long long int day;
    long long int month;
    int year;
    float money;

}pool;

void poorsat_daramad(){
cout<<"please enter two date for calculate poorsat : \n";
long long int day;
long long int month;
int year;
long long int day1;
long long  int month1;
int year1;
cout<<"first date(day) : ";
cin>>day;
cout<<"first date(month) : ";
cin>>month;
cout<<"first date(year) : ";
cin>>year;




char command1[20];
sprintf(command1,"%lld/%lld/%d",day,month,year);


cout<<"second date(day) : ";
cin>>day1;
cout<<"second date(month) : ";
cin>>month1;
cout<<"second date(year) : ";
cin>>year1;


char command2[20];
sprintf(command2,"%lld/%lld/%d",day1,month1,year1);


long long int date=(10000*year)+(100*month)+(day);

long long int date1=(10000*year1)+(100*month1)+(day1);

FILE*p;
p=fopen("poorsant.txt","r");
int sum=0;
while(!feof(p)){
   fscanf(p,"%f %lld %lld %d\n",&pool.money,&pool.day,&pool.month,&pool.year);

   long long int yourdate=(10000*pool.year)+(100*pool.month)+(pool.day);


   if(yourdate>=date&&yourdate<=date1){

    sum+=pool.money;


   }



}


cout<<"Tamame Poorsant Dar Tarikhe morede Nazar Shoma : "<<sum<<"      million toman";
    cout<<"\n\n";


}









int main(){


 userinfo user;
FILE*User;
/*
strcpy(user.secondpassword,"emad borjegani 1273462912");
strcpy(user.name,"emad");
strcpy(user.family,"borjegani");
strcpy(user.nameofauto,"borjegani");
strcpy(user.username,"9818393");
strcpy(user.password,"1273462912");
User=fopen("user.txt","w");
fwrite(&user,sizeof(struct userinfo),1,User);
fclose(User);
*/



long long int day;
long long int month;
long long int year;


nowdate(&day,&month,&year);


cout<<day<<"/"<<month<<"/"<<year<<endl;





cout<<"\n\n\n";

cout<<"************************************************************************************************************************************\n";
cout<<"\n\n\n\n\n";
cout<<"\t\t\t\t{existing car in auto Borjegani}\n\n\n\n\n";


FILE*carlist;
carlist=fopen("carlist.txt","r");
 cout<<"-----------------------\n";
while(!feof(carlist)){


    char c;
    c=fgetc(carlist);
    cout<<c;
    if(c=='\n'){
        cout<<"-----------------------\n";
    }


}
fclose(carlist);

cout<<"************************************************************************************************************************************\n";


cout<<"Auto Gallery {Borjegani}        Manager : Hamid Reza Borjegani\n\n\naddress : Hasht Behesht Street              telephone :(031)32260880       mobile phone : 09131157122\n\n\n";







cout<<"\n\n\nif you manager enter (1) else enter any number that you want : ";
int a;
cin>>a;
if(a!=1){
    return 0;
}

system("cls");

getchar();

nowdate(&day,&month,&year);


cout<<day<<"/"<<month<<"/"<<year<<endl;



User=fopen("user.txt","rb");
fread(&user,sizeof(struct userinfo),1,User);
fclose(User);
start1:
cout<<"\t\t\t\t\t\t\t\t\tHello Mr.Borjegani"<<endl;
cout<<"please enter your user name : ";
char username[30];
char password[30];
char secondpassword[30];
gets(username);

system("cls");
nowdate(&day,&month,&year);


cout<<day<<"/"<<month<<"/"<<year<<endl;
cout<<"\t\t\t\t\t\t\t\t\tHello Mr.Borjegani"<<endl;


cout<<"please enter your password : ";
gets(password);





system("cls");
nowdate(&day,&month,&year);


cout<<day<<"/"<<month<<"/"<<year<<endl;
cout<<"\t\t\t\t\t\t\t\t\tHello Mr.Borjegani"<<endl;


cout<<"please enter your second password : ";
gets(secondpassword);









if(   strcmp(username  ,  (user.username) ) ==0 && strcmp(password ,(user.password) ) ==0&&strcmp(secondpassword ,(user.secondpassword) ) ==0 ){


system("cls");





start:

nowdate(&day,&month,&year);
cout<<day<<"/"<<month<<"/"<<year<<endl;



cout<<"-----------------------------------------------------------------------------------------------------\n\n\n";
sarmayeh();
show_near_chek();
cout<<"-----------------------------------------------------------------------------------------------------\n\n\n";
cout<<"{ for help enter (0) }\n\n\n";
cout<<"please enter number that you want : ";


int number;


cin>>number;
//?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
if(!(number>=0&&number<=16)){

   cout<<"the number that you entered don't exist\n";

   system("pause");
   system("cls");

   goto start;
}
//????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????/
system("cls");






if(number==16){
        getchar();
cout<<"lotfa baraye neveshtan (1) ra vared konid va baraye khandan (2) : ";
int n;
cin>>n;
if(n==1){
system("cls");


    long long int dd;
    long long int mm;
    long long int yy;
    nowdate(&dd,&mm,&yy);
    char command[30];
    sprintf(command,"daftar\\%lld.txt",yy);
    FILE*f;
    f=fopen(command,"a");
    fprintf(f,"%lld/%lld/%lld",dd,mm,yy);
    char c='a';
    while(c!='^'){
             c=getc(stdin);
        if(c!='^'){

            fprintf(f,"%c",c);
        }

    }

    fprintf(f,"\n-------------------------------------------------\n");
fclose(f);
}

else if(n==2){
        system("cls");
    cout<<"sale morde nazar ra vared konid : ";
    long long int yy;
    cin>>yy;
system("cls");
    char command[30];
    sprintf(command,"daftar\\%lld.txt",yy);
    FILE*f;

    if((f=fopen(command,"r"))){
    while(!feof(f)){
        char c;
        c=getc(f);
        cout<<c;
    }

 fclose(f);

}
}



    system("pause");
    system("cls");
    goto start;


}


else if(number==15){
    system("cls");

    por_daram_tarin_mah POR;
    POR.show();
    system("pause");
    system("cls");
    goto start;

}




if(number==0){
    cout<<"\t\t\t\t\t\t\t\t\t{hello Mr.Borjegani}\n\n\n\n\n\n{please enter (1) to change your User Name} \n\n\n{please enter (2) to change your password}\n\n\n{please enter (3) to enter information for buy or sell car for every body without you }\n\n\n";


cout<<"{please enter (4) to get information about Sellers or Customers}\n\n\n{please enter (5) for exit }\n\n\n{please enter (6) to change your second password}\n\n\n";


cout<<"{please enter (7) to enter basic information about existing car in auto \n\n\n{please enter (8) to show existing car in your auto}\n\n\n";


cout<<"{please enter (9) to enter information about buy or sell car for you}\n\n\n";


cout<<"{please enter (10) to  enter/show  name and information about a person that very usefull for your auto}\n\n\n";


cout<<"{please enter (11) to enter/show name and information about a person that give you money for buy and sell car}\n\n\n";


cout<<"{please enter (12) to calculate your poorsant in date that you want }\n\n\n";


cout<<"{please enter (13) to show \ enter you all of auto car that it's for you}\n\n\n";


cout<<"{tedade mashine forookhte shode va kharidari shode dar tarikh morede nazar (14) }\n\n\n";
cout<<"{por daramad / kam daramad tarin mah dar in sal (15)}\n\n\n";
cout<<"{baraye didan va neveshtane yaddasht (16) ra vared konid}\n\n\n";
 system("pause");
 system("cls");
 goto start;

}













else if(number==14){
cout<<"please enter (1) to tedad kharid   enter (2) tedad foroosh : ";
int a;
cin>>a;
if(a==1){

    tedad_kharid();

}

else if(a==2){

    tedad_foroosh();

}

system("pause");
system("cls");
goto start;


}









else if(number==13){
        getchar();
    cout<<"please enter(1) to show  and enter(2) to give information : ";
    int n;
    cin>>n;
    system("cls");
    if(n==2){
getchar();
    FILE*Auto;
    Auto=fopen("Auto.txt","a");
    cout<<"please enter name of auto : ";
    char name[30];
    gets(name);
    cout<<"please enter address : ";
    char address[30];
    gets(address);
    cout<<"please enter name of manager : ";
    char manager[30];
    gets(manager);
    cout<<"please enter telephone : ";
    char telephone[30];
    gets(telephone);

    fprintf(Auto,"\nName of auto gallery : %s\nAddress :  %s\nmanger : %s\ntelephone : %s\n---------------------\n",name,address,manager,telephone);
    fclose(Auto);
    }

    else if(n==1){
      getchar();

        FILE*m;
        m=fopen("Auto.txt","r");
        while(!feof(m)){
            char c;
            c=fgetc(m);

            cout<<c;

        }

        fclose(m);



    }
    system("pause");
        system("cls");
        goto start;


}










else if(number==12){

    poorsat_daramad();
    system("pause");
    system("cls");
    goto start;


}








else if(number==11){
        getchar();
    cout<<"Hello Mr.Borjegani please enter (1)  to show or enter (2) to give information and enter (3) to change information : ";
    int l;
    cin>>l;

    if(l==3){
        getchar();
    class money M[1000];
    FILE*moneybin;

    moneybin=fopen("moneybin.txt","rb");
    cout<<"please enter name of person that you want change his information : ";
    char name[30];
    gets(name);

    int i=0;
    while(!feof(moneybin)){
        fread(&M[i],sizeof(class money),1,moneybin);


        if(strcmp(M[i].name,name)==0){
cout<<"please enter new money : ";
cin>>M[i].pool;

        }

            i++;



    }


    fclose(moneybin);
    FILE*money;
    FILE*mone;
    mone=fopen("mone.txt","w");
    money=fopen("money.txt","w");
    moneybin=fopen("moneybin.txt","w");

    for (int j=0;j<i;j++){
            if(M[j].pool!=0.000){
         fwrite(&M[j],sizeof(class money),1,moneybin);
        fprintf(money,"full name :    %s           money :    %f million toman\n",M[j].name,M[j].pool);
            fprintf(mone,"%f\n",M[j].pool);
            }


    }
    fclose(money);
    fclose(moneybin);
    fclose(mone);
system("pause");




    }


    else if(l==1){

        FILE*money;
        money=fopen("money.txt","r");


        cout<<"\n\n\n\n\n\n\n\n------------------\n";


        while(!feof(money)){

            char c;
            c=fgetc(money);
            cout<<c;
            if(c=='\n'){
                cout<<endl<<"-------------------"<<endl;
            }


        }
        fclose(money);

    }



    else if(l==2){
        getchar();
        system("cls");
        cout<<"please enter a person name : ";
        char name[30];
        gets(name);
        cout<<"please enter money for buy and sell car : ";
        float money;
        cin>>money;
        FILE*m;
        m=fopen("money.txt","a");
        fprintf(m,"full name :    %s           money :    %f million toman\n",name,money);
        fclose(m);
        FILE*m1;
        m1=fopen("mone.txt","a");
        fprintf(m1,"%f\n",money);
        fclose(m1);
        FILE*m2;
        m2=fopen("moneybin.txt","ab");
        class money MON;
        strcpy(MON.name,name);
        MON.pool=money;
        fwrite(&MON,sizeof(class money),1,m2);
    fclose(m2);
    }

    system("pause");
    system("cls");
    goto start;

}








else if(number==10){


    getchar();
    system("cls");
    cout<<"HELLO Mr.Borjegani please enter   for      enter(1)   /  show(2)  /  delete(3)  basic information about that person that you want : ";
    int k;
    cin>>k;
    system("cls");

if(k==3){
         getchar();
    class usefull U[1000];
    FILE*usefullbin;

    usefullbin=fopen("usefullbin.txt","rb");
    cout<<"please enter name of person that you want delete : ";
    char name[30];
    gets(name);

    int i=0;
    while(!feof(usefullbin)){
        fread(&U[i],sizeof(class usefull),1,usefullbin);


        if(strcmp(U[i].name,name)==0){

        }
        else{
            i++;
        }


    }


    fclose(usefullbin);
    FILE*usefull;
    usefull=fopen("usefull person.txt","w");
    usefullbin=fopen("usefullbin.txt","w");

    for (int j=0;j<i;j++){
            if(U[j].i==1){
         fwrite(&U[j],sizeof(class usefull),1,usefullbin);
        fprintf(usefull,"name : %s         money : %s       mobile : %s\n\n",U[j].name,U[j].money,U[j].mobile);
            }


    }
    fclose(usefull);
    fclose(usefullbin);
system("pause");


    }










   else if(k==2){
        FILE*usefull;
        usefull=fopen("usefull person.txt","r");
        while(!feof(usefull)){
            char c;

            c=fgetc(usefull);
            cout<<c;

        }

fclose(usefull);
    }






    else if(k==1){
    cout<<"please enter name of person : ";
    char name[30];
    getchar();
    gets(name);
    cout<<endl<<endl<<endl;
    cout<<"please enter amount of money that this person want buy a car by it : ";
    char money[30];
    gets(money);
    cout<<endl<<endl<<endl;
    cout<<"please enter his mobile number : ";
    char mobile[30];
    getchar();
    gets(mobile);


    FILE*usefull;
    usefull=fopen("usefull person.txt","a");
    fprintf(usefull,"name : %s       mobile phone : %s          money : %s    million toman\n\n\n\n",name,mobile,money);
    fclose(usefull);
    FILE*ff;
    ff=fopen("usefullbin.txt","ab");
    class usefull g;
    strcpy(g.name,name);
    strcpy(g.mobile,mobile);
    strcpy(g.money,money);
    g.i=1;
    fwrite(&g,sizeof(class usefull),1,ff);
    fclose(ff);

    }
    system("pause");
    system("cls");
    goto start;



}









else if(number==9){
getchar();
system("cls");

cout<<"Hello Mr.Borjegani please enter (1) to buy car or enter (2) to sell car : ";
int n;
cin>>n;
cout<<endl<<endl<<endl;
system("cls");

if(!(n>=1&&n<=2)){
system("cls");
   cout<<"please try again\n\n";
   system("pause");
   system("cls");
    goto start;
}




if(n==1){

   getchar();
    //cout<<"name kharidar : ";
    char namekharidar[30];
    //gets(namekharidar);
    strcpy(customer.Nameh_Kharidar,"Hamid Reza Borjegani");
    //cout<<endl<<"kode meli kharidar : ";
    char kodemelikharidar[30];
    //gets(kodemelikharidar);
    strcpy(customer.Kodeh_melli_Khridar,"1273462912");
    //cout<<endl<<"shomare mobile kharidar : ";
    char shomaremobilekharidar[30];
    //gets(shomaremobilekharidar);
    strcpy(customer.Shomare_Mobile_Kharidar,"09131157122");
    cout<<endl<<"name mashin : ";
    char namecar[30];
    gets(namecar);
    strcpy(customer.Name_car,namecar);
    cout<<endl<<"range mashin : ";
    char rangemashin[30];
    gets(rangemashin);
    strcpy(customer.Rangeh_car,rangemashin);
    cout<<endl<<"range dakhel mashin : ";
    char rangedakhelcar[30];
    gets(rangedakhelcar);
    strcpy(customer.Rangeh_Dakheleh_car,rangedakhelcar);
    cout<<endl<<"shomare pelak mashin : ";
    char shomarepelak[30];
    gets(shomarepelak);
    strcpy(customer.Shomare_Pelakeh_car,shomarepelak);
    cout<<endl<<"shomare shasi : ";
    char shomareshasi[30];
    gets(shomareshasi);
    strcpy(customer.Shomareh_Shasi_car,shomareshasi);
    cout<<endl<<"gheimat foroosh : ";
    char gheimatforoosh[30];
    gets(gheimatforoosh);
    strcpy(customer.Gheimateh_Foroosh_car,gheimatforoosh);
    cout<<endl<<"name saheb : ";
    char namesaheb[30];
    gets(namesaheb);
    strcpy(customer.Nameh_Saheb,namesaheb);
    cout<<endl<<"kode meli saheb : ";
    char kodemelisaheb[30];
    gets(kodemelisaheb);
    strcpy(customer.Kodeh_melli_Saheb,kodemelisaheb);
    cout<<endl<<"shomare mobile saheb : ";
    char shomaremobilesaheb[30];
    gets(shomaremobilesaheb);
    strcpy(customer.Shomare_Mobile_Saheb,shomaremobilesaheb);




    cout<<endl<<"tarikh tavalod saheb : ";
char tarikh_tavalod_saheb[30];
gets(tarikh_tavalod_saheb);
    cout<<endl<<"shoghl saheb : ";
    char shoghl_saheb[30];
    gets(shoghl_saheb);
    cout<<endl<<"khiaban mahal kar saheb : ";
    char khiaban_mahal_kar_saheb[30];
    gets(khiaban_mahal_kar_saheb);
    cout<<endl<<"kode posti mahal kar saheb : ";
    char kode_posti_saheb[30];
    gets(kode_posti_saheb);
    cout<<endl<<"telephone mahale kar saheb : ";
    char telephon_mahal_kar_saheb[30];
    gets(telephon_mahal_kar_saheb);



    Human_Customer C(shoghl_saheb,khiaban_mahal_kar_saheb,kode_posti_saheb,telephon_mahal_kar_saheb,namesaheb,shomaremobilesaheb,tarikh_tavalod_saheb,kodemelisaheb);






//char Moshakhasat_car[100];//////////////////////////////
  cout<<endl<<"sale tolide mashin : ";
  char saletolid[30];
  gets(saletolid);
  strcpy(customer.Sale_Tolide_car,saletolid);
   cout<<endl<<"shomareh sanade mashin : ";
   char shomaresanad[30];
   gets(shomaresanad);
   strcpy(customer.Shomareh_Sanad_car,shomaresanad);
    cout<<endl<<"sahebe sanade mashin : ";
    char sahebesanad[30];
    gets(sahebesanad);
    strcpy(customer.Saheb_sanad_car,sahebesanad);
    cout<<endl<<"brande mashin : ";
    char brand[30];
    gets(brand);
    strcpy(customer.Brand_car,brand);
    cout<<endl<<"karkarde mashin : ";
    char karkard[30];
    gets(karkard);
    strcpy(customer.Karkard_car,karkard);
    cout<<endl<<"moshakhasate ezafi in one line : ";
    char moshakhasat[1000];
    gets(moshakhasat);
    strcpy(customer.Moshakhasat_car,moshakhasat);



    cout<<endl<<"this car is hybrid or normal : ";
    char hybrid_normal[30];
    gets(hybrid_normal);

cout<<endl<<"gheymat foroosh : ";
char gheymat[30];
gets(gheymat);



    char KIA[30];
    char HYUNDAI[30];
    strcpy(KIA,"kia");
    strcpy(HYUNDAI,"hyundai");

    if(strcmp(brand,KIA)==0){
       class kia k(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
    system("pause");
    system("cls");

    cout<<C;
    cout<<k;


    }
        else if(strcmp(brand,HYUNDAI)==0){
        hyundai h(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
        system("pause");
    system("cls");

    cout<<C;
    cout<<h;

        }

        else{
AnotherCar a(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
       system("pause");
    system("cls");

    cout<<C;
    cout<<a;

        }













    cout<<"\n\n\nif you give chek to another people enter (1) else enter any number that you want : ";
    int k;
    cin>>k;
    if(k==1){
            cout<<"please enter number of chek : ";
            int k1;
            cin>>k1;
        Etelaatt_Chek etelaatt(k1);
        etelaatt.mohasebe_kharid();

    }



FILE*ff;
ff=fopen("usefullbin.txt","rb");
class usefull g;
while(!feof(ff)){
    fread(&g,sizeof(class usefull),1,ff);
    if(strcmp(g.money,customer.Gheimateh_Foroosh_car)==0){
        cout<<endl<<g.name<<"  needs to this car with phone number : "<<g.mobile<<endl<<endl;
    }


}
fclose(ff);










nowdate(&day,&month,&year);
    char command1[20];
    sprintf(command1,"%lld/%lld/%d",day,month,year);

    FILE*BuyAndSellInfo;
    BuyAndSellInfo=fopen("BuyAndSellInfo.txt","a");
    fprintf(BuyAndSellInfo,"\nname mashin : %s   sale tolide mashin: %s tarikh : %s forooshande : %s kharidar : %s range mashin : %s",customer.Name_car,customer.Sale_Tolide_car,command1,customer.Nameh_Saheb,customer.Nameh_Kharidar,customer.Rangeh_car);
    fclose(BuyAndSellInfo);
    system("pause");
    system("cls");
    FILE*name;
    char command[100];

sprintf(command,"all info\\%s.txt",customer.Nameh_Kharidar);
    name=fopen(command,"a");
    fprintf(name,"\nname : %s \n%s kharide \nrange mashin : %s \nshomare pelak mashin : %s \nrange dakhele mashin : %s",customer.Nameh_Kharidar,customer.Name_car,customer.Rangeh_car,customer.Shomare_Pelakeh_car,customer.Rangeh_car);

    fprintf(name,"\nshomare shasi mashin : %s\ngheymat kharid mashin %s\n",customer.Shomareh_Shasi_car,customer.Gheimateh_Foroosh_car);
  fprintf(name,"kode melli : %s\nshomare mobile : %s\ntarikh: %s\nname forooshande : %s",customer.Kodeh_melli_Khridar,customer.Shomare_Mobile_Kharidar,command1,customer.Nameh_Saheb);
   fprintf(name,"\nmoshakhasate mashin : %s\nsale tolid : %s \nsahebe sanad : %s\n..................................................\n",customer.Moshakhasat_car,customer.Sale_Tolide_car,customer.Saheb_sanad_car);
    fclose(name);


    sprintf(command,"all info\\%s.txt",customer.Nameh_Saheb);
    name=fopen(command,"a");
    fprintf(name,"name : %s \n%s forookhte \nrange mashin : %s \nshomare pelak mashin : %s\nrange dakhele mashin : %s ",customer.Nameh_Saheb,customer.Name_car,customer.Rangeh_car,customer.Shomare_Pelakeh_car,customer.Rangeh_Dakheleh_car);

    fprintf(name,"\nshomare shasi mashin : %s\ngheymat foroosh mashin %s\nmoshakhasat : %s\nsale tolid : %s\nsahebe sanad : %s",customer.Shomareh_Shasi_car,customer.Gheimateh_Foroosh_car,customer.Moshakhasat_car,customer.Sale_Tolide_car,customer.Saheb_sanad_car);
   fprintf(name,"kode melli : %s\nshomare mobile : %s\ntarikh:%s\nname kharidar : %s",customer.Kodeh_melli_Saheb,customer.Shomare_Mobile_Saheb,command1,customer.Nameh_Kharidar);
   fprintf(name,"\n..................................................\n");
    fclose(name);
    system("pause");
system("cls");


FILE*kharid;
kharid=fopen("tedad kharid.txt","a");
fprintf(kharid,"%d %lld %lld %d ",1,day,month,year);
fclose(kharid);



cout<<"do you like take your car in your auto gallery if you want please enter 1 else enter any number : ";
int a;
cin>>a;
if(a==1){
    FILE*carlist;
    carlist=fopen("carlist.txt","a");
    fprintf(carlist,"name : %s         color : %s       model : %s\n\n",namecar,rangemashin,saletolid);
    fclose(carlist);
    system("cls");
    goto start;


}




    system("pause");
    system("cls");
    goto start;

}






else if(n==2){
getchar();
    cout<<"name kharidar : ";
    char namekharidar[30];
    gets(namekharidar);
    strcpy(customer.Nameh_Kharidar,namekharidar);
    cout<<endl<<"kode meli kharidar : ";
    char kodemelikharidar[30];
    gets(kodemelikharidar);
    strcpy(customer.Kodeh_melli_Khridar,kodemelikharidar);
    cout<<endl<<"shomare mobile kharidar : ";
    char shomaremobilekharidar[30];
    gets(shomaremobilekharidar);
    strcpy(customer.Shomare_Mobile_Kharidar,shomaremobilekharidar);
    cout<<endl<<"name mashin : ";
    char namecar[30];
    gets(namecar);
    strcpy(customer.Name_car,namecar);
    cout<<endl<<"range mashin : ";
    char rangemashin[30];
    gets(rangemashin);
    strcpy(customer.Rangeh_car,rangemashin);
    cout<<endl<<"range dakhel mashin : ";
    char rangedakhelcar[30];
    gets(rangedakhelcar);
    strcpy(customer.Rangeh_Dakheleh_car,rangedakhelcar);
    cout<<endl<<"shomare pelak mashin : ";
    char shomarepelak[30];
    gets(shomarepelak);
    strcpy(customer.Shomare_Pelakeh_car,shomarepelak);
    cout<<endl<<"shomare shasi : ";
    char shomareshasi[30];
    gets(shomareshasi);
    strcpy(customer.Shomareh_Shasi_car,shomareshasi);
    cout<<endl<<"gheimat foroosh : ";
    char gheimatforoosh[30];
    gets(gheimatforoosh);
    strcpy(customer.Gheimateh_Foroosh_car,gheimatforoosh);
    //cout<<endl<<"name saheb : ";
    char namesaheb[30];
    //gets(namesaheb);
    strcpy(customer.Nameh_Saheb,"Hamid Reza Borjegani");
    //cout<<endl<<"kode meli saheb : ";
    char kodemelisaheb[30];
    //gets(kodemelisaheb);
    strcpy(customer.Kodeh_melli_Saheb,"1273462912");
    //cout<<endl<<"shomare mobile saheb : ";
    char shomaremobilesaheb[30];
    //gets(shomaremobilesaheb);
    strcpy(customer.Shomare_Mobile_Saheb,"09131157122");




    cout<<endl<<"tarikh tavalod kharidar : ";
char tarikh_tavalod_kharidar[30];
gets(tarikh_tavalod_kharidar);
    cout<<endl<<"shoghl kharidar : ";
    char shoghl_kharidar[30];
    gets(shoghl_kharidar);
    cout<<endl<<"khiaban mahal kar kharidar : ";
    char khiaban_mahal_kar_kharidar[30];
    gets(khiaban_mahal_kar_kharidar);
    cout<<endl<<"kode posti mahal kar kharidar : ";
    char kode_posti_kharidar[30];
    gets(kode_posti_kharidar);
    cout<<endl<<"telephone mahale kar kharidar : ";
    char telephon_mahal_kar_kharidar[30];
    gets(telephon_mahal_kar_kharidar);




     Human_Seller S(shoghl_kharidar,khiaban_mahal_kar_kharidar,kode_posti_kharidar,telephon_mahal_kar_kharidar,namekharidar,shomaremobilekharidar,tarikh_tavalod_kharidar,kodemelikharidar);












//char Moshakhasat_car[100];//////////////////////////////
  cout<<endl<<"sale tolide mashin : ";
  char saletolid[30];
  gets(saletolid);
  strcpy(customer.Sale_Tolide_car,saletolid);
   cout<<endl<<"shomareh sanade mashin : ";
   char shomaresanad[30];
   gets(shomaresanad);
   strcpy(customer.Shomareh_Sanad_car,shomaresanad);
    cout<<endl<<"sahebe sanade mashin : ";
    char sahebesanad[30];
    gets(sahebesanad);
    strcpy(customer.Saheb_sanad_car,sahebesanad);
    cout<<endl<<"brande mashin : ";
    char brand[30];
    gets(brand);
    strcpy(customer.Brand_car,brand);
    cout<<endl<<"karkarde mashin : ";
    char karkard[30];
    gets(karkard);
    strcpy(customer.Karkard_car,karkard);
    cout<<endl<<"moshakhasate ezafi in one line : ";
    char moshakhasat[1000];
    gets(moshakhasat);
    strcpy(customer.Moshakhasat_car,moshakhasat);
cout<<endl<<"this car is hybrid or normal : ";
    char hybrid_normal[30];
    gets(hybrid_normal);

cout<<endl<<"gheymat foroosh : ";
char gheymat[30];
gets(gheymat);

    char KIA[30];
    char HYUNDAI[30];
    strcpy(KIA,"kia");
    strcpy(HYUNDAI,"hyundai");

    if(strcmp(brand,KIA)==0){
       class kia k(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
    system("pause");
    system("cls");

    cout<<S;
    cout<<k;


    }
        else if(strcmp(brand,HYUNDAI)==0){
        hyundai h(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
        system("pause");
    system("cls");

    cout<<S;
    cout<<h;

        }

        else{
AnotherCar a(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
       system("pause");
    system("cls");

    cout<<S;
    cout<<a;

        }

    cout<<"\n\n\nif you get chek from another people enter (1) else enter any number that you want : ";
    int k;
    cin>>k;
    if(k==1){
            cout<<"please enter number of chek : ";
            int k1;
            cin>>k1;
        Etelaatt_Chek etelaatt(k1);
        etelaatt.mohasebe_foroosh();

    }














nowdate(&day,&month,&year);
    char command1[20];
    sprintf(command1,"%lld/%lld/%d",day,month,year);

    FILE*BuyAndSellInfo;
    BuyAndSellInfo=fopen("BuyAndSellInfo.txt","a");
    fprintf(BuyAndSellInfo,"\nname mashin : %s   sale tolide mashin: %s tarikh : %s forooshande : %s kharidar : %s range mashin : %s",customer.Name_car,customer.Sale_Tolide_car,command1,customer.Nameh_Saheb,customer.Nameh_Kharidar,customer.Rangeh_car);
    fclose(BuyAndSellInfo);
    system("pause");
    system("cls");
    FILE*name;
    char command[100];

sprintf(command,"all info\\%s.txt",customer.Nameh_Kharidar);
    name=fopen(command,"a");
    fprintf(name,"\nname : %s \n%s kharide \nrange mashin : %s \nshomare pelak mashin : %s \nrange dakhele mashin : %s",customer.Nameh_Kharidar,customer.Name_car,customer.Rangeh_car,customer.Shomare_Pelakeh_car,customer.Rangeh_car);

    fprintf(name,"\nshomare shasi mashin : %s\ngheymat kharid mashin %s\n",customer.Shomareh_Shasi_car,customer.Gheimateh_Foroosh_car);
  fprintf(name,"kode melli : %s\nshomare mobile : %s\ntarikh: %s\nname forooshande : %s",customer.Kodeh_melli_Khridar,customer.Shomare_Mobile_Kharidar,command1,customer.Nameh_Saheb);
   fprintf(name,"\nmoshakhasate mashin : %s\nsale tolid : %s \nsahebe sanad : %s\n..................................................\n",customer.Moshakhasat_car,customer.Sale_Tolide_car,customer.Saheb_sanad_car);
    fclose(name);


    sprintf(command,"all info\\%s.txt",customer.Nameh_Saheb);
    name=fopen(command,"a");
    fprintf(name,"name : %s \n%s forookhte \nrange mashin : %s \nshomare pelak mashin : %s\nrange dakhele mashin : %s ",customer.Nameh_Saheb,customer.Name_car,customer.Rangeh_car,customer.Shomare_Pelakeh_car,customer.Rangeh_Dakheleh_car);

    fprintf(name,"\nshomare shasi mashin : %s\ngheymat foroosh mashin %s\nmoshakhasat : %s\nsale tolid : %s\nsahebe sanad : %s",customer.Shomareh_Shasi_car,customer.Gheimateh_Foroosh_car,customer.Moshakhasat_car,customer.Sale_Tolide_car,customer.Saheb_sanad_car);
   fprintf(name,"kode melli : %s\nshomare mobile : %s\ntarikh:%s\nname kharidar : %s",customer.Kodeh_melli_Saheb,customer.Shomare_Mobile_Saheb,command1,customer.Nameh_Kharidar);
   fprintf(name,"\n..................................................\n");
    fclose(name);

system("pause");
system("cls");


FILE*foroosh;
foroosh=fopen("tedad foroosh.txt","a");
fprintf(foroosh,"%d %lld %lld %d ",1,day,month,year);
fclose(foroosh);




goto start;



}







system("pause");
system("cls");
goto start;
}











else if(number==8){
getchar();
    system("cls");
    FILE*carlist;
    carlist=fopen("carlist.txt","r");
    while(!feof(carlist)){
        char c;
        c=fgetc(carlist);
        cout<<c;

    }
fclose(carlist);
system("pause");
system("cls");
goto start;




}











else if(number==7){
        getchar();




    system("cls");

    cout<<"please enter 1 to delete car and 2 to add car : ";
    int n;
    cin>>n;



if(n==1){
    getchar();
    class carlist CAR[1000];
    FILE*carlistbin;

    carlistbin=fopen("carlistbin.txt","rb");
    cout<<"please enter name of car that you want delete : ";
    char name[30];
    gets(name);
    cout<<"please enter color of car that you want delete  : ";
    char color[30];
    gets(color);
    cout<<"please enter model of car that you want delete : ";
    int model;
    cin>>model;
    int i=0;
    while(!feof(carlistbin)){
        fread(&CAR[i],sizeof(class carlist),1,carlistbin);

        if(CAR[i].model==model&&strcmp(CAR[i].name,name)==0&&strcmp(CAR[i].color,color)==0){

        }
        else{
            i++;
        }


    }


    fclose(carlistbin);
    //FILE*carlistbin;
    FILE*carlist;
    carlist=fopen("carlist.txt","w");
    carlistbin=fopen("carlistbin.txt","w");

    for (int j=0;j<i;j++){
            if(CAR[j].model!=0){
         fwrite(&CAR[j],sizeof(class carlist),1,carlistbin);
        fprintf(carlist,"name : %s         color : %s       model : %d\n\n",CAR[j].name,CAR[j].color,CAR[j].model);
            }


    }
    fclose(carlist);
    fclose(carlistbin);
system("pause");

}




   else if(n==2){
            getchar();
    cout<<"please enter name of car :"<<endl;
    char nameofcar[30];
    gets(nameofcar);
    cout<<"please enter color of car :"<<endl;
    char colorofcar[30];
    gets(colorofcar);
    cout<<"please enter model of car :"<<endl;
    int modelofcar;
    cin>>modelofcar;

    FILE*carlist;
    carlist=fopen("carlist.txt","a");
    fprintf(carlist,"name : %s         color : %s       model : %d\n\n",nameofcar,colorofcar,modelofcar);

    system("cls");
    fclose(carlist);

    FILE*carlistbin;
    carlistbin=fopen("carlistbin.txt","ab");
    class carlist CAR;
    strcpy(CAR.name,nameofcar);
    strcpy(CAR.color,colorofcar);
    CAR.model=modelofcar;
    fwrite(&CAR,sizeof(class carlist),1,carlistbin);
    fclose(carlistbin);

    }
    system("cls");
    cout<<"sabt shod\n\n";
    system("pause");
    system("cls");
goto start;


}







else if(number==6){
    getchar();
    cout<<"please enter your user name again : ";
    char Username[30];
    gets(Username);
    cout<<"please enter your user name again : ";
    char Password[30];
    gets(Password);
    cout<<"please enter your second password : ";
    char secandpassword[30];
    gets(secandpassword);

    if(strcmp(user.username,Username)==0&&strcmp(user.password,Password)==0&&strcmp(user.secondpassword,secandpassword)==0){

        system("cls");
        cout<<"please enter your new second password : ";
        gets(secandpassword);
        strcpy(user.secondpassword,secandpassword);
        FILE*tt;
        tt=fopen("user.txt","w");
        fwrite(&user,sizeof(struct userinfo),1,tt);
        fclose(tt);
        cout<<"your second password is changed"<<endl;
        system("pause");
        system("cls");
        goto start;


    }
    else {
        cout<<"your user name or your password or your second password is incorrect\n";
        system("pause");
        system("cls");
        goto start;


    }


}



else if(number==4){
getchar();
cout<<"please enter 1 to search by name of person\n\n\nplease enter 2 to search by date of sell or buy car\n\n\nplease enter 3 to search by name of car\n\n\nplease enter 4 to search by color of car\n\n\n";

   int number1;
   cin>>number1;


    if(number1==2){
    getchar();
    system("cls");
    cout<<"please enter date of buy or sell car:\n";
    cout<<"day:";
    long long int day1;
    long long int month1;
    long long int year1;
    cin>>day1;
    cout<<"month:";
    cin>>month1;
    cout<<"year:";
    cin>>year1;
    char comm[100];
   // nowdate(&day1,&month1,&year1);
    //sprintf(comm,"%lld/%lld/%lld",day1,month1,year1);
    char comm124[100];
    sprintf(comm124,"findstr %lld/%lld/%lld BuyAndSellInfo.txt",day1,month1,year1);
    system(comm124);
    cout<<endl<<endl;
    system("pause");
    system("cls");
    goto start;
}






   else if(number1==4){
    getchar();
    system("cls");
    cout<<"please enter color of car:";
    char color[30];
    gets(color);
    char comm[100];
    sprintf(comm,"findstr %s BuyAndSellInfo.txt",color);
    system(comm);
    cout<<endl<<endl;
    system("pause");
    system("cls");
    goto start;
}





else if(number1==3){
    getchar();
    system("cls");
    cout<<"please enter name of car:";
    char nameofcar[30];
    gets(nameofcar);
    char comm[100];
    sprintf(comm,"findstr %s BuyAndSellInfo.txt",nameofcar);
    system(comm);
    cout<<endl<<endl;
    system("pause");
    system("cls");
    goto start;
}

  else if (number1==1){
        system("cls");
    cout<<"name shakhse morede nazar : ";

    char nameshakhs[30];
    getchar();
    gets(nameshakhs);
    system("cls");

    char command2[100];
    cout<<"{all information about "<<nameshakhs<<" :}\n"<<endl;

    sprintf(command2,"all info\\%s.txt",nameshakhs);
    FILE*file;

    file=fopen(command2,"r");
    if(file==NULL){
            system("cls");
      cout<<"{ shoma ba chenin shakhsi moamele nadashtid }"<<endl;
        system("pause");
        system("cls");
    goto start;
    }
    while(!feof(file)){
         char a;
       a=fgetc(file);
       cout<<a;


    }
cout<<endl;
system("pause");
system("cls");
goto start;
   }












}















else if(number==3){
getchar();






cout<<"please enter name of car's brand : ";
char name_of_brand_car[30];

gets(name_of_brand_car);
system("cls");
    cout<<"\t\t\t\t\tthis brand is "<<name_of_brand_car<<"\n\n\n";

    cout<<"name kharidar : ";
    char namekharidar[30];
    gets(namekharidar);
    strcpy(customer.Nameh_Kharidar,namekharidar);
    cout<<endl<<"kode meli kharidar : ";
    char kodemelikharidar[30];
    gets(kodemelikharidar);
    strcpy(customer.Kodeh_melli_Khridar,kodemelikharidar);
cout<<endl<<"tarikh tavalod kharidar : ";
char tarikh_tavalod_kharidar[30];
gets(tarikh_tavalod_kharidar);
    cout<<endl<<"shoghl kharidar : ";
    char shoghl_kharidar[30];
    gets(shoghl_kharidar);
    cout<<endl<<"khiaban mahal kar kharidar : ";
    char khiaban_mahal_kar_kharidar[30];
    gets(khiaban_mahal_kar_kharidar);
    cout<<endl<<"kode posti mahal kar kharidar : ";
    char kode_posti_kharidar[30];
    gets(kode_posti_kharidar);
    cout<<endl<<"telephone mahale kar kharidar : ";
    char telephon_mahal_kar_kharidar[30];
    gets(telephon_mahal_kar_kharidar);




    cout<<endl<<"shomare mobile kharidar : ";
    char shomaremobilekharidar[30];
    gets(shomaremobilekharidar);
    strcpy(customer.Shomare_Mobile_Kharidar,shomaremobilekharidar);
    cout<<endl<<"name mashin : ";
    char namecar[30];
    gets(namecar);
    strcpy(customer.Name_car,namecar);
    cout<<endl<<"range mashin : ";
    char rangemashin[30];
    gets(rangemashin);
    strcpy(customer.Rangeh_car,rangemashin);
    cout<<endl<<"range dakhel mashin : ";
    char rangedakhelcar[30];
    gets(rangedakhelcar);
    strcpy(customer.Rangeh_Dakheleh_car,rangedakhelcar);
    cout<<endl<<"shomare pelak mashin : ";
    char shomarepelak[30];
    gets(shomarepelak);
    strcpy(customer.Shomare_Pelakeh_car,shomarepelak);
    cout<<endl<<"shomare shasi : ";
    char shomareshasi[30];
    gets(shomareshasi);
    strcpy(customer.Shomareh_Shasi_car,shomareshasi);
    cout<<endl<<"gheimat foroosh : ";
    float gheimatforoosh;
    cin>>gheimatforoosh;
    //strcpy(customer.Gheimateh_Foroosh_car,gheimatforoosh);
    getchar();
    cout<<endl<<"name saheb : ";
    char namesaheb[30];
    gets(namesaheb);
    strcpy(customer.Nameh_Saheb,namesaheb);
    cout<<endl<<"kode meli saheb : ";
    char kodemelisaheb[30];
    gets(kodemelisaheb);
    strcpy(customer.Kodeh_melli_Saheb,kodemelisaheb);
    cout<<endl<<"shomare mobile saheb : ";
    char shomaremobilesaheb[30];
    gets(shomaremobilesaheb);
    strcpy(customer.Shomare_Mobile_Saheb,shomaremobilesaheb);



    cout<<endl<<"tarikh tavalod saheb : ";
char tarikh_tavalod_saheb[30];
gets(tarikh_tavalod_saheb);
    cout<<endl<<"shoghl saheb : ";
    char shoghl_saheb[30];
    gets(shoghl_saheb);
    cout<<endl<<"khiaban mahal kar saheb : ";
    char khiaban_mahal_kar_saheb[30];
    gets(khiaban_mahal_kar_saheb);
    cout<<endl<<"kode posti mahal kar saheb : ";
    char kode_posti_saheb[30];
    gets(kode_posti_saheb);
    cout<<endl<<"telephone mahale kar saheb : ";
    char telephon_mahal_kar_saheb[30];
    gets(telephon_mahal_kar_saheb);



    Human_Customer C(shoghl_saheb,khiaban_mahal_kar_saheb,kode_posti_saheb,telephon_mahal_kar_saheb,namesaheb,shomaremobilesaheb,tarikh_tavalod_saheb,kodemelisaheb);

    Human_Seller S(shoghl_kharidar,khiaban_mahal_kar_kharidar,kode_posti_kharidar,telephon_mahal_kar_kharidar,namekharidar,shomaremobilekharidar,tarikh_tavalod_kharidar,kodemelikharidar);







//char Moshakhasat_car[100];//////////////////////////////
  cout<<endl<<"sale tolide mashin : ";
  char saletolid[30];
  gets(saletolid);
  strcpy(customer.Sale_Tolide_car,saletolid);
   cout<<endl<<"shomareh sanade mashin : ";
   char shomaresanad[30];
   gets(shomaresanad);
   strcpy(customer.Shomareh_Sanad_car,shomaresanad);
    cout<<endl<<"sahebe sanade mashin : ";
    char sahebesanad[30];
    gets(sahebesanad);
    strcpy(customer.Saheb_sanad_car,sahebesanad);
    cout<<endl<<"brande mashin : ";
    char brand[30];
    gets(brand);
    strcpy(customer.Brand_car,brand);
    cout<<endl<<"karkarde mashin : ";
    char karkard[30];
    gets(karkard);
    strcpy(customer.Karkard_car,karkard);
    cout<<endl<<"moshakhasate ezafi in one line : ";
    char moshakhasat[1000];
    gets(moshakhasat);
    strcpy(customer.Moshakhasat_car,moshakhasat);
    cout<<endl<<"this car is hybrid or normal : ";
    char hybrid_normal[30];
    gets(hybrid_normal);

cout<<endl<<"gheymat foroosh : ";
char gheymat[30];
gets(gheymat);

    char KIA[30];
    char HYUNDAI[30];
    strcpy(KIA,"kia");
    strcpy(HYUNDAI,"hyundai");

    if(strcmp(brand,KIA)==0){
       class kia k(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
    system("pause");
    system("cls");
    cout<<S;
    cout<<C;
    cout<<k;


    }
        else if(strcmp(brand,HYUNDAI)==0){
        hyundai h(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
        system("pause");
    system("cls");
    cout<<S;
    cout<<C;
    cout<<h;

        }

        else{
AnotherCar a(rangemashin,saletolid,shomaresanad,sahebesanad,karkard,moshakhasat,rangedakhelcar,shomarepelak,shomareshasi,gheymat,brand,namecar,hybrid_normal);
       system("pause");
    system("cls");
    cout<<S;
    cout<<C;
    cout<<a;

        }




nowdate(&day,&month,&year);
    char command1[20];
    sprintf(command1,"%lld/%lld/%d",day,month,year);

    FILE*BuyAndSellInfo;
    BuyAndSellInfo=fopen("BuyAndSellInfo.txt","a");
    fprintf(BuyAndSellInfo,"\nname mashin : %s   sale tolide mashin: %s tarikh : %s forooshande : %s kharidar : %s range mashin : %s",customer.Name_car,customer.Sale_Tolide_car,command1,customer.Nameh_Saheb,customer.Nameh_Kharidar,customer.Rangeh_car);
    fclose(BuyAndSellInfo);
    system("pause");
    system("cls");
    FILE*name;
    char command[100];

sprintf(command,"all info\\%s.txt",customer.Nameh_Kharidar);
    name=fopen(command,"a");
    fprintf(name,"\nname : %s \n%s kharide \nrange mashin : %s \nshomare pelak mashin : %s \nrange dakhele mashin : %s",customer.Nameh_Kharidar,customer.Name_car,customer.Rangeh_car,customer.Shomare_Pelakeh_car,customer.Rangeh_car);

    fprintf(name,"\nshomare shasi mashin : %s\ngheymat kharid mashin %f\n",customer.Shomareh_Shasi_car,gheimatforoosh);
  fprintf(name,"kode melli : %s\nshomare mobile : %s\ntarikh: %s\nname forooshande : %s",customer.Kodeh_melli_Khridar,customer.Shomare_Mobile_Kharidar,command1,customer.Nameh_Saheb);
   fprintf(name,"\nmoshakhasate mashin : %s\nsale tolid : %s \nsahebe sanad : %s \nshoghl : %s \nkhiaban mahal kar : %s \nkode posti mahal kar : %s \ntelephone mahal kar : %s\n..................................................\n",customer.Moshakhasat_car,customer.Sale_Tolide_car,customer.Saheb_sanad_car,shoghl_kharidar,khiaban_mahal_kar_kharidar,kode_posti_kharidar,telephon_mahal_kar_kharidar);
    fclose(name);


    sprintf(command,"all info\\%s.txt",customer.Nameh_Saheb);
    name=fopen(command,"a");
    fprintf(name,"name : %s \n%s forookhte \nrange mashin : %s \nshomare pelak mashin : %s\nrange dakhele mashin : %s ",customer.Nameh_Saheb,customer.Name_car,customer.Rangeh_car,customer.Shomare_Pelakeh_car,customer.Rangeh_Dakheleh_car);

    fprintf(name,"\nshomare shasi mashin : %s\ngheymat foroosh mashin %f\nmoshakhasat : %s\nsale tolid : %s\nsahebe sanad : %s",customer.Shomareh_Shasi_car,gheimatforoosh,customer.Moshakhasat_car,customer.Sale_Tolide_car,customer.Saheb_sanad_car);
   fprintf(name,"kode melli : %s\nshomare mobile : %s\ntarikh:%s\nname kharidar : %s\nshoghl : %s \nkhiaban mahal kar : %s \n kode poste mahal kar : %s\ntelephone mahal kar : %s",customer.Kodeh_melli_Saheb,customer.Shomare_Mobile_Saheb,command1,customer.Nameh_Kharidar,shoghl_saheb,khiaban_mahal_kar_saheb,kode_posti_saheb,telephon_mahal_kar_saheb);
   fprintf(name,"\n..................................................\n");
    fclose(name);



system("pause");
system("cls");
float poorsant=( gheimatforoosh * 0.005*1000000 );
printf("you must get %f toman from %s and must get %f  toman from %s for poorsant \n",poorsant,namesaheb,poorsant,namekharidar);

system("pause");
system("cls");
FILE*Poorsant;
Poorsant=fopen("poorsant.txt","a");
fprintf(Poorsant,"%f %lld %lld %d\n",2*poorsant/1000000,day,month,year);
fclose(Poorsant);


FILE*foroosh;
foroosh=fopen("tedad foroosh.txt","a");
fprintf(foroosh,"%d %lld %lld %d ",1,day,month,year);
fclose(foroosh);



FILE*por_kam;
    por_kam=fopen("daram_poorsant_max_min.txt","a");
    fprintf(por_kam,"%f %lld %d ",2*poorsant/1000000,month,year);

fclose(por_kam);

system("pause");
system("cls");




    goto start;







}












else if(number==1){
        getchar();
        pqrs:
        cout<<"\t\t\t\t\t{Hello Mr.Borjegani}\nplease enter your old User Name:";
        char username1[30];
        gets(username1);
        system("cls");

        if(strcmp(user.username,username1)==0){
   pqrt:
    cout<<"\t\t\t\t\t{Hello Mr.Borjegani}\nplease enter your new User Name : ";
    char username2[30];

     gets(username2);

    cout<<endl<<"please enter your new User Name try again : ";

    gets(username1);
    if(strcmp(username1,username2)==0){
       cout<<"{your User Name changed}\n";
       system("pause");
       strcpy(user.username,username1);\
       User=fopen("user.txt","w");
fwrite(&user,sizeof(struct userinfo),1,User);
fclose(User);
       system("cls");


       goto start;

    }
    cout<<"{please try again your new user name is not correct}\n";
    system("pause");
    system("cls");
    goto pqrt;


}

else{

   cout<<"{your old User Name is incorrect}\n";
   system("pause");
   system("cls");
   goto pqrs;
}

}


else if(number==2){
    getchar();
        pqrs1:
        cout<<"\t\t\t\t\t{Hello Mr.Borjegani}\nplease enter your old Password:";
        char password1[30];
        gets(password1);
        system("cls");

        if(strcmp(user.password,password1)==0){
   pqrt1:
    cout<<"\t\t\t\t\t{Hello Mr.Borjegani}\nplease enter your new Password : ";
    char password2[30];

     gets(password2);

    cout<<endl<<"please enter your new Password try again : ";

    gets(password1);
    if(strcmp(password1,password2)==0){
       cout<<"{your Password changed}\n";
       system("pause");
       system("cls");
       strcpy(user.password,password1);
       User=fopen("user.txt","w");
fwrite(&user,sizeof(struct userinfo),1,User);
fclose(User);
       goto start;

    }
    cout<<"{please try again your new password is not correct}\n";
    system("pause");
    system("cls");
    goto pqrt1;


}

else{

   cout<<"{your old Password is incorrect}\n";
   system("pause");
   system("cls");
   goto pqrs1;
}

}


//////////////////////////////////////////////////////end of change user name and password


else if (number==5){


return 0;

}















}//////////////////////end if for enter your information

else{
    system("cls");
   cout<<"\t\t\t\t\t{Hello Mr.Borjegani}\n{your user name or your passwords is incorrect please try again}\n" ;
   system("pause");
   system("cls");
   goto start1;


}







return 0 ;
}
