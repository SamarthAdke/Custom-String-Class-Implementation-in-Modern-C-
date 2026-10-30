#include<iostream>
using namespace std;

class String
{
        char *p;
        const char *dup;
        int size=0,i=0;
        public:
        static String temp;
        String()
        {
                //cout<<"Def"<<endl;
                p=nullptr;
        }
        String(const char *temp)
        {
                //cout<<"Param"<<endl;
                dup=temp;
                for(size=1;*dup;dup++,size++);
                p= new char[size];
                p[size-1]='\0';
                for(i=0;i<size-1;i++)
                        p[i]=temp[i];
        }
        String(const String &source)
        {
                //cout<<"Param1"<<endl;
                size=source.size;
                p= new char[size];
                p[size-1]='\0';
                for(i=0;i<size-1;i++)
                        p[i]=source.p[i];
        }
        ~String()
        {
                //cout<<"dest"<<endl;
                if(p!=nullptr)
                {
                        delete []p;
                        //cout<<"flag"<<endl;
                        p=nullptr;
                }
        }

        String& operator =(String &source)
        {
                if(this->p!=nullptr)
                {
                        delete [] p;
                        p=nullptr;
                }
                this->size=source.size;
                this->p= new char[source.size];

                this->p[size-1]='\0';
                for(i=0;i<size-1;i++)
                {
                        this->p[i]=source.p[i];
                }
                return source;

        }

        String& operator =(const char * str)
        {
                if(this->p!=nullptr)
                {
                        delete [] p;
                        p=nullptr;
                }
                dup=str;
                for(this->size=1;*str;str++,this->size++);
                this->p=new char[this->size];
                this->p[size-1]='\0';
                for(i=0;i<this->size-1;i++)
                        this->p[i]=dup[i];

                return *this;
        }
        char& operator =(char& ch)
        {
                if(this->p!=nullptr)
                {
                        delete [] p;
                        this->p=nullptr;
                }
                this->p=new char;
                this->size=1;
                this->p[0]=ch;

                return ch;
        }

        String& operator +(String &source)
        {
                temp.size=this->size+source.size-1;
                if(temp.p!=nullptr)
                {
                        delete [] temp.p;
                        temp.p=nullptr;
                }
                temp.p= new char[temp.size];
                temp.p[temp.size-1]='\0';
                for(i=0;i<this->size-1;i++)
                {
                        temp.p[i]=this->p[i];
                }
                for(int j=0;j<source.size-1;j++,i++)
                {
                        temp.p[i]=source.p[j];
                }
                return temp;

        }
        String&  operator +(const char *str)
        {
                if(temp.p!=nullptr)
                {
                        delete [] temp.p;
                        temp.p=nullptr;
                }
                dup=str;
                int k=0;
                for(i=1;*str;i++,str++);
                temp.size=this->size+i-1;

                temp.p= new char[temp.size];
                temp.p[temp.size-1]='\0';
                for(k=0;k<this->size-1;k++)
                {
                        temp.p[k]=this->p[k];
                }
                for(int j=0;j<i-1;j++,k++)
                {
                        temp.p[k]=dup[j];
                }
                return temp;
        }
        char& operator[](int i)
        {
                return p[i];
        }
        /*operator > (String &source)
        {

        }*/
        friend ostream& operator << (ostream&, const String &);
        friend istream& operator >> (istream&,  String &);
        friend String& strcpy(String&,String&);
        friend String& strncpy(String&,String&,int);
        friend int strlen(String&);
        friend int strcmp(String &, String &);
        friend int strncmp(String &, String &,int);
        friend String& strcat(String &, String &);
        friend String& strncat(String &, String &,int);
        friend String& strrev(String &);
        friend String& strupr(String &);
        friend String& strlwr(String &);
        friend char* strchr(String &,char ch);
        friend char* strrchr(String &,char ch);
        friend char* strstr(String &,const char*);
        void pri()
        {
                for(int i=0;i<size;i++)
                {
                        cout<<p[i]<<endl;
                }
                cout<<size<<endl;
        }

};
String String::temp;
ostream& operator << (ostream& out, const String &source)
{
        if(source.p!=nullptr)
                out<<source.p;
        return out;
}
istream& operator >> (istream& in, String &source)
{
        if(source.p!=nullptr)
        {
                delete[] source.p;
                source.p=nullptr;
        }

        char ch;
        FILE *fp = fopen("temp.txt","w+");
        while((ch=getchar())!='\n'){
                fputc(ch,fp);
        }
        source.size=ftell(fp);
        source.p= new char[source.size+1];
        source.p[source.size]='\0';
        rewind(fp);
        int i=0;
        for(i<0;i<source.size;i++)
        {
                source.p[i]=fgetc(fp);
        }

        fclose(fp);
        remove("temp.txt");
        return in;
}
String& strcpy(String &sour1, String &sour2)
{
        sour1=sour2;
        return sour1;
}

String& strncpy(String &sour1, String &sour2, int n)
{
        if(n>sour2.size)
        {
                cout<<n<<" exceeds object size\n"<<endl;
                return sour1;
        }
        if(sour1.p!=nullptr)
        {
                delete[] sour1.p;
                sour1.p=nullptr;
        }
        sour1.size=n+1;
        sour1.p=new char[sour1.size];
        sour1.p[n]='\0';
        for(int i=0;i<n;i++)
        {
                sour1.p[i]=sour2.p[i];
        }
        return sour1;
}
int strlen(String& s1)
{
        return s1.size;
}
int strcmp(String &s1, String &s2)
{
        int i=0;
        for(i=0;i<(s1.size-1<=s2.size-1?s1.size-1:s2.size-1);i++)
        {
                if(s1.p[i]==s2.p[i])
                        continue;
                else
                        return s1.p[i]-s2.p[i];
        }
        if(s1.size-1<s2.size-1)
                return -s2.p[i];
        else
                return s1.p[i];
}
int strncmp(String &s1, String &s2,int n)
{
        if(n>s1.size-1||n>s2.size-1)
        {
                cout<<"Limit exceeds"<<endl;
                return 0;
        }
        for(int i=0;i<n;i++)
        {
                if(s1.p[i]==s2.p[i])
                        continue;
                else
                        return s1.p[i]-s2.p[i];
        }
        return 0;
}
String& strcat(String &s1, String &s2)
{
        String::temp=s1;
        s1.size=String::temp.size+s2.size-1;
        if(s1.p!=nullptr)
        {
                delete[] s1.p;
                s1.p=nullptr;
        }
        s1.p=new char[s1.size];
        s1.p[s1.size-1]='\0';
        int i=0;
        for(i=0;i<String::temp.size-1;i++)
                s1.p[i]=String::temp.p[i];
        for(int j=0;i<s1.size-1;i++,j++)
                s1.p[i]=s2.p[j];

        return s1;
}
String& strncat(String &s1, String &s2,int n)
{
        String::temp=s1;
        s1.size=String::temp.size+n;
        if(s1.p!=nullptr)
        {
                delete[] s1.p;
                s1.p=nullptr;
        }
        s1.p=new char[s1.size];
        s1.p[s1.size-1]='\0';
        int i=0;
        for(i=0;i<String::temp.size-1;i++)
                s1.p[i]=String::temp.p[i];
        for(int j=0;i<s1.size-1;i++,j++)
                s1.p[i]=s2.p[j];

        return s1;
}
String& strrev(String &s)
{
        if(String::temp.p!=nullptr)
        {
                delete[] String::temp.p;
                String::temp.p=nullptr;
        }

        String::temp=s;
        for(;*(String::temp.p);String::temp.p++);
        String::temp.p--;
        for(int i=0;i<String::temp.size-1;String::temp.p--,i++)
        {
                s.p[i]=*(String::temp.p);
        }
        String::temp.p++;
        return s;
}

String& strupr(String &source)
{
        for(int i=0;i<source.size;i++)
        {
                if(source.p[i]>96 && source.p[i]<123)
                {
                        source.p[i]=source.p[i]-32;
                }
        }
        return source;
}

String& strlwr(String &source)
{
        for(int i=0;i<source.size;i++)
        {
                if(source.p[i]>64 && source.p[i]<96)
                {
                        source.p[i]=source.p[i]+32;
                }
        }
        return source;
}

char* strchr(String &source,char ch)
{
        for(int i=0;i<source.size;i++)
        {
                if(source.p[i]==ch)
                        return source.p+i;
        }
}


char* strrchr(String &source,char ch)
{
        for(int i=source.size-1;i>-1;i--)
        {
                if(source.p[i]==ch)
                        return source.p+i;
        }
}

char* strstr(String &source,const char* s)
{
        for(int i=0;i<source.size;i++)
        {
                if(*s==source.p[i])
                {
                        int k=i;
                        for(int j=0;s[j];j++)
                        {
                                if(source.p[k]==s[j])
                                {
                                        if(s[j+1]=='\0')
                                                return source.p+i;
                                        k++;
                                        continue;
                                }
                                else
                                        break;
                        }
                }
        }
        return 0;
}