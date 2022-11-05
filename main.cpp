#include <bits/stdc++.h>

using namespace std;

//randomSet.h

//시드값
random_device rd;

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

//Return Random Alphabet - 문자 종류(소,대,모두)내에서 설정한 길이만큼 랜덤한 알파벳 반환
string randAlpha(int len, int letterCase=0, bool duplication=true, unordered_set<string> *dup=NULL){    // 반환받을 길이 / 0소문자, 1대문자, 2구분없음 / 0중복없음, 1중복있음 / 중복있다면 중복체크 할 set 주소
    
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

//userSetInput.h

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
    
    /*
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
    */

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

void Init(){
    // 두 코드 컴파일
    int ret;
    ret = system("g++ ./code/correct.cpp -o ./code/correct -O2 -lm -static");
    if(ret == -1 ){
        cout << "Correct compile Error\n";
        exit(1);
    }
    ret = system("g++ ./code/incorrect.cpp -o ./code/incorrect -O2 -lm -static");
    if(ret == -1 ){
        cout << "Incorrect compile Error\n";
        exit(1);
    }
}

int main(){

    Init();

    // Timer On, 걸린 시간 체크
    time_t start, finish;
    start = time(NULL); 
 
    while(true){
        // 랜덤 입력 값 받아오고 파일에 저장
        string seed = SetInput();

        ofstream inputFile;
        inputFile.open("input.txt");    //파일 열기(없으면 생성)

        inputFile << seed << "\n";

        inputFile.close();


        // 입력값을 넣고, 출력값을 파일로 저장
        // 속도 제일 많이 잡아먹는 구간, 0.03초걸림
        int ret;
        ret = system("cmd /c \".\\code\\correct < input.txt > .\\code\\correctOutput.txt\"");
        if(ret == -1 ){
            cout << "CorrectOutput create Error\n";
            exit(1);
        }
        ret = system("cmd /c \".\\code\\incorrect < input.txt > .\\code\\incorrectOutput.txt\"");
        if(ret == -1 ){
            cout << "CorrectOutput create Error\n";
            exit(1);
        }
        

        // 두 출력값 파일을 받아와 비교
        ifstream outputFile1, outputFile2;
        outputFile1.open("./code/correctOutput.txt");  
        outputFile2.open("./code/incorrectOutput.txt");

        bool diff = false;
        vector<string> answer, wrong;
        if (outputFile1.is_open() && outputFile2.is_open())
        {
            string line;
            while(!outputFile1.eof()){
                getline(outputFile1, line);
                answer.push_back(line);
            }
            while(!outputFile2.eof()){
                getline(outputFile2, line);
                wrong.push_back(line);
            }
            outputFile1.close();    
            outputFile2.close();
            
            if(answer.size() != wrong.size()){          // 출력값 라인 길이가 다를 경우
                diff = true;
            }
            else{
                for(int i=0; i<answer.size(); ++i){
                    if(answer[i] == wrong[i]) continue; // 라인 내의 출력값이 다를 경우
                    diff = true;
                    break;
                }
            }
        }


        // 두 출력값이 다른 경우
        if(diff){
            // Timer Off
            finish  = time(NULL);     
            auto duration = finish - start;
            struct tm* t = localtime(&finish);
            string nowtime;
            nowtime = '[' + to_string(t->tm_year + 1900) + '.' + to_string(t->tm_mon + 1) + '.' + to_string(t->tm_mday) + '/'
                    + to_string(t->tm_hour) + ':' + to_string(t->tm_min) + ':' + to_string(t->tm_sec) + ']';

            // logStr 세팅
            // 백준문제 번호, 날짜 및 시간, 걸린 시간
            string logStr = "------------------------------\n";   
            logStr += "boj - " + to_string(boj) + '\n';
            logStr += nowtime + '\t';
            logStr += to_string(duration) + "sec\n";

            logStr += "\n[input]\n" + seed;
            logStr += "\n\n[answer]\n";
            for(auto a : answer) logStr += a + "\n";
            logStr += "\n[wrong]\n";
            for(auto w : wrong) logStr += w + "\n";

            // 커맨드 출력
            cout << logStr;

            // 로그 남기기
            ofstream logFile;
            logFile.open("log.txt", ios::app);  // 이어쓰기

            logFile << logStr;

            logFile.close();
            break;
        }
    }
}