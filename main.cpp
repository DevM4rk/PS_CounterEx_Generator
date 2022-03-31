#include <bits/stdc++.h>

using namespace std;

//randomNum.h

//�õ尪
random_device rd;

template <typename T>
string randNum(T min, T max){
    //���� ���� ���� �ʱ�ȭ
    mt19937 gen(rd());  

    // min ���� max ���� �յ��ϰ� �����ϱ� ���� �յ� ���� ����
    uniform_int_distribution<T> dis(min, max);      //���� Ÿ��, min�̻� ~ max����
    //uniform_real_distribution<T> dis(min, max);   //�Ǽ� Ÿ��, min�̻� ~ max�̸�

    return to_string(dis(gen));
}

//userSetInput.h

typedef long long ll;

int boj;
string SetInput(){
    /*
    ����ڰ� �Է� ������ ���Ŀ� ���缭 ���� ���� �ʿ�

    template <typename T>
    string randNum<T>(T min, T max)  -  min �̻�, max ������ ���� ��ȯ (�Ǽ��� ���� max �̸�)

    ����
    boj = 22251;
    string k = randNum<int>(1,6);
    string p = randNum<int>(1,42);
    string n = randNum<int>(1, pow(10,stoi(k))-1);
    string x = randNum<int>(1,stoi(n)); 
    
    return n + ' ' + k + ' ' + p + ' ' + x;
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
                for(int i=0; i<answer.size(); i++){
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