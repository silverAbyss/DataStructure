#include<iostream>
#include<vector>
#include<string.h>
#include<cstdio>
#include<ctype.h>
using namespace std;
int p[127];
//�趨��Ϊ�෴�������
int pd(char a,char b){
    return p[a]==-p[b];
}
//���
void print(char a){
    cout<<"NO"<<endl;
    //�������û�ҵ�
    if(p[a]>0){
        cout<<"?-";
    }

    //�����ַ����
    if(a=='a'){
        cout<<"/*";
    }
    else if(a=='b'){
        cout<<"*/";
    }
    else
        cout<<a;

    //�����ұ�û�ҵ�
    if(p[a]<0){
        cout<<"-?";
    }
}
int main()
{
    p['a']=-1;
    p['b']=1;
    p['(']=-2;
    p[')']=2;
    p['[']=-3;
    p[']']=3;
    p['{']=-4;
    p['}']=4;
    char *s=new char[100];
    vector<char> vcs;
    //�洢
    while(gets(s)&&s[0]!='.'){
        for(int i=0;i<strlen(s);i++){
            if(s[i]=='/'&&s[i+1]=='*'){
                vcs.push_back('a');
                i++;
            }
            else if(s[i]=='*'&&s[i+1]=='/'){
                vcs.push_back('b');
                i++;
            }
            else if(s[i]=='('||s[i]==')'||s[i]=='['||s[i]==']'||s[i]=='{'||s[i]=='}'){
                vcs.push_back(s[i]);
            }
        }
    }
//    for(int i=0;i<vcs.size();i++)
//        cout<<vcs[i]<<" ";
//    cout<<endl;
    //ִ��
    int f=1;
    for(int i=0;i<vcs.size();i++){
            //cout<<vcs[i]<<"ii"<<endl;
        if(p[vcs[i]]>0){
            if(i==0){
                    f=0;
                print(vcs[i]);
                break;
            }
            if(!pd(vcs[i],vcs[i-1])){
                f=0;
                print(vcs[i-1]);
                break;
            }
            else{
                //cout<<vcs[i-1]<<"dlt"<<endl;
                vcs.erase(vcs.begin()+i-1);
                //cout<<vcs[i-1]<<"dlt"<<endl;
                vcs.erase(vcs.begin()+i-1);
                i-=2;
            }
        }
    }
    if(vcs.empty()){
        cout<<"YES";
    }
    else if(f){
        print(vcs[0]);
    }
    return 0;
}
