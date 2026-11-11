#include <iostream>
#include <iomanip>

int main{
    int choice;

    std::cout<<"Выберите задачу для решения(1/2/3/4): "<<std::endl;
    std::cout<<choice;

    switch(choice){
        case 1:
            int n{};
            int m{};
            int sum{};

            std::cout<<"Введите m и n: (m<n)";
            std::cin>>n>>m;

            for (int i=5; i<=n; i+=5){
                if((i%m)!=0){
                    sum+=i;
                }
            }
            std::cout<<"Сумма: "<<sum<<std::endl;
            break;
        }
        case 2:{
            double a;
            double s{1};

            std::cout<<"Введите а: ";
            std::cin>>a;

            if (a>=0){
                for(int i=2;i<=8;i+=2){
                    S *= (i*i);
                }
                S = S-a;
            }

            if (a<0){
                for(int i=3; i<=9; i+=3){
                    S *= (i-a);
                }
            }
            std::cout<<"S = "<<S<<std::endl;
            break;
        }
        case 3:{
            std::cout<<std::fixed<<std::setprecision(6);



            for(double x=0; x<=1.0001; x+=0.2){
                double y;
                if(x==1.0){
                    y=0
                } else {
                    y=std::log((1+x)/(1-x))
                }
                double sum=0.0;
                int n = 0;

                if (x!= 0.0){
                    double a=x;
                    sum=a;
                    n=1;
                    double term;

                }
            }

        }
