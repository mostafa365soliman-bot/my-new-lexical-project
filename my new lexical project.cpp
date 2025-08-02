#include <iostream>        // إدخال/إخراج البيانات
#include <string>          // التعامل مع نوع البيانات string
#include <cctype>          // يحتوي على دوال مثل isdigit()، isalpha() لفحص الحروف
#include <vector>
#include <unordered_set>   // لتخزين الكلمات المحجوزة بكفاءة

using namespace std;

// الكلمات المحجوزة في اللغة
unordered_set<string> keywords = {
    "int", "float", "if", "else", "while", "for", "return", "void", "main"
};

// دالة تفحص إن كانت الكلمة من الكلمات المحجوزة
bool isKeyword(const string& word) {
    return keywords.find(word) != keywords.end();
}

// الدالة الرئيسية لتحليل الكود
void lexicalAnalyzer(const string& code) {
    int i = 0;                    // عداد لمكان الحرف الحالي
    int n = code.length();       // عدد الأحرف الكلي

    while (i < n) {              // حلقة تمشي على الكود حرف حرف
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // تحليل الأرقام
        if (isdigit(code[i])) {
            string num;
            while (i < n && isdigit(code[i])) {
                num += code[i++];
            }
            cout << "NUMBER: " << num << endl;
        }

        // تحليل الكلمات المحجوزة أو المعرفات
        else if (isalpha(code[i]) || code[i] == '_') {
            string word;
            while (i < n && (isalnum(code[i]) || code[i] == '_')) {
                word += code[i++];
            }
            if (isKeyword(word))
                cout << "KEYWORD: " << word << endl;
            else
                cout << "IDENTIFIER: " << word << endl;
        }

        // تحليل العوامل والفواصل
        else {
            switch (code[i]) {
                case '+': case '-': case '*': case '/': case '=':
                case '<': case '>': case '!':
                    cout << "OPERATOR: " << code[i] << endl;
                    break;
                case ';': case '(': case ')': case '{': case '}':
                    cout << "DELIMITER: " << code[i] << endl;
                    break;
                default:
                    cout << "UNKNOWN: " << code[i] << endl;
            }
            i++;
        }
    }
}

// الدالة الرئيسية
int main() {
    string inputCode;
    cout << "Enter your code: ";
    getline(cin, inputCode);   // قراءة سطر واحد من الكود

    cout << "\n--- Tokens ---\n";
    lexicalAnalyzer(inputCode);   // تحليل الكود
    return 0;