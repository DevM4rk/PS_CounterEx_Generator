#include <bits/stdc++.h>

using namespace std;

extern random_device rd;

//Return Random Number - min 이상, max 이하의 난수 반환 (실수일 때는 max 미만)
template <typename T>
string randNum(T min, T max, bool duplication=true, unordered_set<string> *dup=NULL){   // 최솟값 / 최댓값 / 0중복없음, 1중복있음 / 중복있다면 중복체크 할 set 주소
    //난수 생성 엔진 초기화
    mt19937 gen(rd());  

    // min 부터 max 까지 균등하게 생성하기 위해 균등 분포 정의
    uniform_int_distribution<T> dis(min, max);      //정수 타입, min이상 ~ max이하
    //uniform_real_distribution<T> dis(min, max);   //실수 타입, min이상 ~ max미만

    while(true){
        string ret = to_string(dis(gen));

        if(duplication){
            return ret;
        }
        else{
            if(!dup->count(ret)){   // 중복없음이고 이미 나온 문자가 아닌 경우 return
                dup->insert(ret);
                return ret;
            }
        }
    }
    return "";
}

string randAlpha(int len, int letterCase=0, bool duplication=true, unordered_set<string> *dup=NULL);