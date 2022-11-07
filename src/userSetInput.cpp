#include "userSetInput.hpp"

typedef long long ll;

int boj;

string SetInput(){
    /*
    사용자가 입력 범위와 형식에 맞춰서 로직 구현 필요

    string randNum<T>(T min, T max, bool duplication=true, unordered_set<string> *dup=NULL)
    - (반환받을 길이 / 0소문자, 1대문자, 2구분없음 / 0중복없음, 1중복있음 / 중복있다면 중복체크 할 set 주소)
    
    string randAlpha(int len, int letterCase=0, bool duplication=true, unordered_set<string> *dup=NULL) 
    - (반환받을 길이 / 0소문자, 1대문자, 2구분없음 / 0중복없음, 1중복있음 / 중복있다면 중복체크 할 set 주소)
    */
    
    
    //참고1
    boj = 22251;
    string ret;
    string k,p,n,x;

    k = randNum<int>(1,6);
    p = randNum<int>(1,42);
    n = randNum<int>(1, pow(10,stoi(k))-1);
    x = randNum<int>(1,stoi(n)); 
    
    ret = n + ' ' + k + ' ' + p + ' ' + x;          // 공백 표현을 ' ' 이 아닌 " "로 하게 될 경우 에러 발생 주의
    
    return ret;
    

    /*
    //참고2
    boj = 20006;
    string ret;
    string p,m,l,n;
    unordered_set<string> name;

    p = randNum<int>(1,300);
    m = randNum<int>(1,300);

    ret = p + ' ' + m + '\n';

    for(int i=0; i<stoi(p); ++i){
        l = randNum<int>(1,500);
        n = randAlpha(2,0,false,&name);
        //n을 구할 때, 문제에서 닉네임의 길이가 16까지 된다고 했지만 플레이어의 수는 최대 300명이고 
        //알파벳 소문자 두개로 가능한 경우의 수는 26*26 = 676개이므로 두개를 조합하여 구함.

        ret += l + ' ' + n + '\n';
    }

    return ret;
    */
}
