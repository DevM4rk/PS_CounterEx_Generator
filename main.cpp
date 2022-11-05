#include <bits/stdc++.h>

using namespace std;

//randomSet.h

//�õ尪
random_device rd;

//Return Random Number - min �̻�, max ������ ���� ��ȯ (�Ǽ��� ���� max �̸�)
template <typename T>
string randNum(T min, T max, bool duplication=true, unordered_set<string> *dup=NULL){   // �ּڰ� / �ִ� / 0�ߺ�����, 1�ߺ����� / �ߺ��ִٸ� �ߺ�üũ �� set �ּ�
    //���� ���� ���� �ʱ�ȭ
    mt19937 gen(rd());  

    // min ���� max ���� �յ��ϰ� �����ϱ� ���� �յ� ���� ����
    uniform_int_distribution<T> dis(min, max);      //���� Ÿ��, min�̻� ~ max����
    //uniform_real_distribution<T> dis(min, max);   //�Ǽ� Ÿ��, min�̻� ~ max�̸�

    while(true){
        string ret = to_string(dis(gen));

        if(duplication){
            return ret;
        }
        else{
            if(!dup->count(ret)){   // �ߺ������̰� �̹� ���� ���ڰ� �ƴ� ��� return
                dup->insert(ret);
                return ret;
            }
        }
    }
    return "";
}

//Return Random Alphabet - ���� ����(��,��,���)������ ������ ���̸�ŭ ������ ���ĺ� ��ȯ
string randAlpha(int len, int letterCase=0, bool duplication=true, unordered_set<string> *dup=NULL){    // ��ȯ���� ���� / 0�ҹ���, 1�빮��, 2���о��� / 0�ߺ�����, 1�ߺ����� / �ߺ��ִٸ� �ߺ�üũ �� set �ּ�
    
    mt19937 gen(rd());  
    uniform_int_distribution<int> dis(0, 51);   //���ĺ� ���� = 26

    while(true){
        string ret;
        for(int i=0; i<len; ++i){
            if(letterCase == 0)
                ret += 'a' + dis(gen)%26;    //�ҹ���
            else if(letterCase == 1)
                ret += 'A' + dis(gen)%26;    //�빮��
            else   //letterCase == 2
                ret += 'a' + dis(gen);       //���� ����
        }

        if(duplication){
            return ret;
        }
        else{
            if(!dup->count(ret)){   // �ߺ������̰� �̹� ���� ���ڰ� �ƴ� ��� return
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
    ����ڰ� �Է� ������ ���Ŀ� ���缭 ���� ���� �ʿ�

    string randNum<T>(T min, T max, bool duplication=true, unordered_set<string> *dup=NULL)
    - (��ȯ���� ���� / 0�ҹ���, 1�빮��, 2���о��� / 0�ߺ�����, 1�ߺ����� / �ߺ��ִٸ� �ߺ�üũ �� set �ּ�)
    
    string randAlpha(int len, int letterCase=0, bool duplication=true, unordered_set<string> *dup=NULL) 
    - (��ȯ���� ���� / 0�ҹ���, 1�빮��, 2���о��� / 0�ߺ�����, 1�ߺ����� / �ߺ��ִٸ� �ߺ�üũ �� set �ּ�)
    */
    
    /*
    //����1
    boj = 22251;
    string ret;
    string k,p,n,x;

    k = randNum<int>(1,6);
    p = randNum<int>(1,42);
    n = randNum<int>(1, pow(10,stoi(k))-1);
    x = randNum<int>(1,stoi(n)); 
    
    ret = n + ' ' + k + ' ' + p + ' ' + x;          // ���� ǥ���� ' ' �� �ƴ� " "�� �ϰ� �� ��� ���� �߻� ����
    
    return ret;
    */

    /*
    //����2
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
        //n�� ���� ��, �������� �г����� ���̰� 16���� �ȴٰ� ������ �÷��̾��� ���� �ִ� 300���̰� 
        //���ĺ� �ҹ��� �ΰ��� ������ ����� ���� 26*26 = 676���̹Ƿ� �ΰ��� �����Ͽ� ����.

        ret += l + ' ' + n + '\n';
    }

    return ret;
    */
}

void Init(){
    // �� �ڵ� ������
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

    // Timer On, �ɸ� �ð� üũ
    time_t start, finish;
    start = time(NULL); 
 
    while(true){
        // ���� �Է� �� �޾ƿ��� ���Ͽ� ����
        string seed = SetInput();

        ofstream inputFile;
        inputFile.open("input.txt");    //���� ����(������ ����)

        inputFile << seed << "\n";

        inputFile.close();


        // �Է°��� �ְ�, ��°��� ���Ϸ� ����
        // �ӵ� ���� ���� ��ƸԴ� ����, 0.03�ʰɸ�
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
        

        // �� ��°� ������ �޾ƿ� ��
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
            
            if(answer.size() != wrong.size()){          // ��°� ���� ���̰� �ٸ� ���
                diff = true;
            }
            else{
                for(int i=0; i<answer.size(); ++i){
                    if(answer[i] == wrong[i]) continue; // ���� ���� ��°��� �ٸ� ���
                    diff = true;
                    break;
                }
            }
        }


        // �� ��°��� �ٸ� ���
        if(diff){
            // Timer Off
            finish  = time(NULL);     
            auto duration = finish - start;
            struct tm* t = localtime(&finish);
            string nowtime;
            nowtime = '[' + to_string(t->tm_year + 1900) + '.' + to_string(t->tm_mon + 1) + '.' + to_string(t->tm_mday) + '/'
                    + to_string(t->tm_hour) + ':' + to_string(t->tm_min) + ':' + to_string(t->tm_sec) + ']';

            // logStr ����
            // ���ع��� ��ȣ, ��¥ �� �ð�, �ɸ� �ð�
            string logStr = "------------------------------\n";   
            logStr += "boj - " + to_string(boj) + '\n';
            logStr += nowtime + '\t';
            logStr += to_string(duration) + "sec\n";

            logStr += "\n[input]\n" + seed;
            logStr += "\n\n[answer]\n";
            for(auto a : answer) logStr += a + "\n";
            logStr += "\n[wrong]\n";
            for(auto w : wrong) logStr += w + "\n";

            // Ŀ�ǵ� ���
            cout << logStr;

            // �α� �����
            ofstream logFile;
            logFile.open("log.txt", ios::app);  // �̾��

            logFile << logStr;

            logFile.close();
            break;
        }
    }
}