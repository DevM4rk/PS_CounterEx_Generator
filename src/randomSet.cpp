#include "randomSet.hpp"

//시드값
random_device rd;

//Return Random Alphabet - 문자 종류(소,대,모두)내에서 설정한 길이만큼 랜덤한 알파벳 반환
string randAlpha(int len, int letterCase, bool duplication, unordered_set<string> *dup){    // 반환받을 길이 / 0소문자, 1대문자, 2구분없음 / 0중복없음, 1중복있음 / 중복있다면 중복체크 할 set 주소
    
    mt19937 gen(rd());  
    uniform_int_distribution<int> dis(0, 51);   //알파벳 개수 = 26

    while(true){
        string ret;
        for(int i=0; i<len; ++i){
            if(letterCase == 0)
                ret += 'a' + dis(gen)%26;    //소문자
            else if(letterCase == 1)
                ret += 'A' + dis(gen)%26;    //대문자
            else   //letterCase == 2
                ret += 'a' + dis(gen);       //구분 없음
        }

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
