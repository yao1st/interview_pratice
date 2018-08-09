//
// Created by senseadmin on 18-8-9.
//

#include <iostream>
#include <vector>

bool containAllType(const std::string &pw)
{
    bool C = false;

    for (int i = 0; i < pw.length(); ++i) {
        if (pw[i] <= 'Z' && pw[i] >= 'A')
        {
            C = true;
            break;
        }
    }

    bool c = false;
    for (int j = 0; j < pw.length(); ++j) {
        if (pw[j] <= 'z' && pw[j] >= 'a')
        {
            c = true;
            break;
        }
    }

    bool n = false;
    for (int k = 0; k < pw.length(); ++k) {
        if (pw[k] <= '9' && pw[k] >= '0')
        {
            n = true;
            break;
        }
    }

    bool special = false;
    for (int l = 0; l < pw.length(); ++l) {
        if (pw[l] == '!' ||
                (pw[l] >=35 && pw[l] <=38) ||
                    (pw[l] >=40 && pw[l] <=47) ||
        (pw[l] >=60 && pw[l] <=64) ||
        (pw[l] >=93 && pw[l] <=95) ||
        pw[l] == '{'||
        pw[l] == '}')
        {
            special = true;
            break;
        }
    }
    return (C&&c&&n&&special);
}

bool increasing(const std::string &pw, char c1, char c2) {
    int first = 0;
    int first_ind, second_ind;
    int second = 0;
    for (int i = 0; i < pw.length()-1; ++i) {
        if (pw[i] >= c1 && pw[i] <= c2)
        {
            if (first == 0)
            {
                first = pw[i];
                first_ind = i;
                continue;
            } else
            {
                second = pw[i];
                second_ind = i;
                if (second - first == 1 && second_ind - first_ind == 1)
                {
                    if (pw[i+1] - second == 1)
                        return true;
                    else
                    {
                        first = 0;
                    }
                }
            }
        }
    }
    return false;

}

bool equal(const std::string &pw, char c1, char c2) {
    int first = 0;
    int first_ind, second_ind;
    int second = 0;
    for (int i = 0; i < pw.length()-1; ++i) {
        if (pw[i] >= c1 && pw[i] <= c2)
        {
            if (first == 0)
            {
                first = pw[i];
                first_ind = i;
                continue;
            } else
            {
                second = pw[i];
                second_ind = i;
                if (second - first == 0 && second_ind - first_ind == 0)
                {
                    if (pw[i+1] - second == 0)
                        return true;
                    else
                    {
                        first = 0;
                    }
                }
            }
        }
    }
    return false;
}

bool decrease(const std::string &pw, char c1, char c2) {
    int first = 0;
    int first_ind, second_ind;
    int second = 0;
    for (int i = 0; i < pw.length()-1; ++i) {
        if (pw[i] >= c1 && pw[i] <= c2)
        {
            if (first == 0)
            {
                first = pw[i];
                first_ind = i;
                continue;
            } else
            {
                second = pw[i];
                second_ind = i;
                if (second - first == -1 && second_ind - first_ind == -1)
                {
                    if (pw[i+1] - second == 0)
                        return true;
                    else
                    {
                        first = 0;
                    }
                }
            }
        }
    }
    return false;
}


bool ordinary_word(const std::string &pw)
{
    if (pw.find("password") != pw.npos || pw.find("admin") != pw.npos || pw.find("hello") != pw.npos || pw.find("iloveyou") != pw.npos || pw.find("112233") != pw.npos || pw.find("qwerty") != pw.npos)
        return true;
    return false;
}

void check(const std::string &pw)
{
    if (pw.length() < 8 ||
        !containAllType(pw) ||
        increasing(pw, '0', '9') ||
        increasing(pw, 'a', 'z') ||
        increasing(pw, 'A', 'Z') ||
        equal(pw, '0', '9') ||
        equal(pw, 'a', 'z') ||
        equal(pw, 'A', 'Z') ||
        decrease(pw, '0', '9') ||
        decrease(pw, 'a', 'z') ||
        decrease(pw, 'A', 'Z') ||
        ordinary_word(pw)
            )
    {
        std::cout << "no" << std::endl;
        return;
    }

    std::cout << "yes" << std::endl;
}


int main(int argc, char **argv)
{
    int t;
    std::cin >> t;

    if (t <= 0 || t > 1000)
        return -1;

    std::vector<std::string> pw_vec;
    for (int i = 0; i < t; ++i) {
        std::string pw;
        std::cin >> pw;
        if (pw.length() > 16)
            return -1;
        pw_vec.push_back(pw);
    }

    for (int j = 0; j < t; ++j) {
        check(pw_vec[j]);
    }

}