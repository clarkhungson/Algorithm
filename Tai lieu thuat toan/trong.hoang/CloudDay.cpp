#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <utility>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumPeople' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY p
 *  2. LONG_INTEGER_ARRAY x
 *  3. LONG_INTEGER_ARRAY y
 *  4. LONG_INTEGER_ARRAY r
 */
 
struct town {
    long pos;
    long val;
    town (long p, long v) {
        this->pos = p; this->val = v;
    }
};

struct cloud {
    long pos;
    int idx;
    bool isEnd;
    cloud (long p, int i, bool isEnd) {
        this->pos = p; this->idx = i; this->isEnd = isEnd;
    }
};

bool com1 (town t1, town t2) {
    return t1.pos <= t2.pos;
}

bool com2 (cloud c1, cloud c2) {
    return c1.pos <= c2.pos;
}

long maximumPeople(vector<long>& p, vector<long>& x, vector<long>& y, vector<long>& r) {
    // Return the maximum number of people that will be in a sunny town after removing exactly one cloud.
    int n = p.size();
    int m = y.size();
    vector<town> t;
    vector<cloud> c;
    
    for (int i = 0; i < n; ++i) {
        t.push_back(town(x[i],p[i]));
    }
    
    for (int i = 0; i < m; ++i) {
        c.push_back(cloud(y[i]-r[i], i, false));
        c.push_back(cloud(y[i]+r[i], i, true));        
    }
    
    std::sort(t.begin(),t.end(),com1);
    std::sort(c.begin(),c.end(),com2);
    
    int num_cloud = 0;
    long total = 0;    
    long cur = 0;
    long max_rm = 0;
    
    int csize = 2*m;
    int j = 0;
    unordered_set<int> index;
    int count_index = 0;
    for (int i = 0; i < csize; ++i) {
        if (!c[i].isEnd) {
            num_cloud++;
            index.insert(c[i].idx);
            if (num_cloud == 1) {
                count_index = c[i].idx;
                while(j < n && t[j].pos < c[i].pos) {
                    total += t[j].val;
                    j++;
                }
            }
            else if (num_cloud == 2) {
                while(j < n && t[j].pos < c[i].pos) {
                    cur += t[j].val;
                    j++;
                }
            }
            else {//num_cloud > 1
                while(j < n && t[j].pos < c[i].pos) {
                    j++;
                }
            }
        }
        else {
            if (num_cloud == 1) {
                while(j < n && t[j].pos <= c[i].pos) {
                    cur += t[j].val;
                    j++;
                }
                max_rm = max(max_rm,cur);
                cur = 0;
            }
            else {//num_cloud > 1
                while(j < n && t[j].pos <= c[i].pos) {
                    j++;
                }
                
                if (c[i].idx == count_index) {
                    max_rm = max(max_rm,cur);
                    cur = 0;
                }
            }
            num_cloud--;
            index.erase(c[i].idx);
            if (num_cloud == 1) {
                count_index = *index.begin();
            }
        }
    }
    
    while (j < n) {
        total += t[j].val;
        j++;
    }
    
    return total + max_rm;
}

int main()
{
    ofstream fout(getenv("./outputCloudDay"));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream finput;
    finput.open("./tcCloudDay.txt");
    string n_temp;
    getline(finput, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string p_temp_temp;
    getline(finput, p_temp_temp);

    vector<string> p_temp = split(rtrim(p_temp_temp));

    vector<long> p(n);

    for (int i = 0; i < n; i++) {
        long p_item = stol(p_temp[i]);

        p[i] = p_item;
    }

    string x_temp_temp;
    getline(finput, x_temp_temp);

    vector<string> x_temp = split(rtrim(x_temp_temp));

    vector<long> x(n);

    for (int i = 0; i < n; i++) {
        long x_item = stol(x_temp[i]);

        x[i] = x_item;
    }

    string m_temp;
    getline(finput, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string y_temp_temp;
    getline(finput, y_temp_temp);

    vector<string> y_temp = split(rtrim(y_temp_temp));

    vector<long> y(m);

    for (int i = 0; i < m; i++) {
        long y_item = stol(y_temp[i]);

        y[i] = y_item;
    }

    string r_temp_temp;
    getline(finput, r_temp_temp);

    vector<string> r_temp = split(rtrim(r_temp_temp));

    vector<long> r(m);

    for (int i = 0; i < m; i++) {
        long r_item = stol(r_temp[i]);

        r[i] = r_item;
    }

    long result = maximumPeople(p, x, y, r);

    fout << result << "\n";

    finput.close();
    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
