#include"main.cpp"

int main()
{
        String obj1("My name ABC"),obj2(obj1),obj3;

        cout<<obj1 <<endl<< obj2<<endl<< obj3<<endl;

        obj3="vector India";

        obj2=obj3;

        cout<<"operator overloading: "<<obj2<<endl<< obj3<<endl;

        obj3=obj1+obj2;

        cout<<"Concatenation: "<<obj3<<endl;

        cout<<"[] overloading: "<<obj2[2]<<endl;

        String temp;
        cin>>temp;
        cout<<temp<<endl;

        cout<<"Length of obj1: "<<strlen(obj1)<<endl;

        cout<<"Cmp: "<<strcmp(obj2,temp);
        cout<<"Cmp: "<<strcmp(obj1,obj2);

        cout<<"strncat: "<<strncat(obj1,obj2,7)<<endl;

        cout<<"strrev: "<<strrev(obj1)<<endl;

        cout<<"strupr: "<<strupr(obj2)<<endl;

        cout<<"Strlwr: "<<strlwr(obj1)<<endl;

        char *s;
        s=strchr(obj3,'r');
        cout<<"strchr: "<<*s<<endl;

        char val[5]="ABC";
        s=strstr(obj3,val);
        cout<<"strstr: "<<s<<endl;
}