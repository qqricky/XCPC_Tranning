#include<iostream>
using namespace std;
enum CPU_Rank {P1=1,P2,P3,P4,P5,P6,P7};
class CPU
{
    private:
    CPU_Rank Rank;
        int frequency;
        float voltage;
    public:
        CPU(CPU_Rank newrank,int newfrequency,float newvoltage);
        void run()
        {
            cout<<"CPU run"<<endl;
        }
        void stop()
        {
            cout<<"CPU stop"<<endl;
        }
        ~CPU(){cout<<"Destruct CPU"<<endl;}
};
CPU::CPU(CPU_Rank newrank,int newfrequency,float newvoltage)
{
    Rank=(CPU_Rank)newrank;
    frequency=newfrequency;
    voltage=newvoltage;
    cout<<"Construct CPU"<<endl;
}
int main()
{
    CPU a(P6,300,2.8);
    a.run();
    a.stop();
    system("pause");
    return 0;
}