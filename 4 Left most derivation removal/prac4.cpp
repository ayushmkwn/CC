#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of productions: ";
    cin >> n;
    map<char, vector<string>> m1, m2;
    vector<string> v;
    set<char> se;
    vector<string> ans;
    cout << "\nEnter the productions one by one:\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
        se.insert(s[0]);
        string s1 = "";
        for (int i = 3; i < s.length(); i++)
        {
            if (s[i] == '|')
            {
                if (s1[0] >= 'A' && s1[0] <= 'Z' && s1[0] == s[0])
                {
                    m1[s[0]].push_back(s1);
                    s1 = "";
                }
                else
                {
                    m2[s[0]].push_back(s1);
                    s1 = "";
                }
            }
            else
            {
                s1 += s[i];
            }
        }
        if (s1[0] >= 'A' && s1[0] <= 'Z' && s1[0] == s[0])
        {
            m1[s[0]].push_back(s1);
            s1 = "";
        }
        else
        {
            m2[s[0]].push_back(s1);
            s1 = "";
        }
    }
    for (auto it = se.begin(); it != se.end(); it++)
    {
        if (m1[*it].size() == 0)
        {
            string ans1 = "";
            ans1 += (*it);
            ans1 += "-";
            ans1 += ">";
            vector<string> temp = m2[*it];
            for (int i = 0; i < temp.size(); i++)
            {
                if (i != (temp.size() - 1))
                {
                    ans1 += temp[i];
                    ans1 += "|";
                }
                else
                {
                    ans1 += temp[i];
                }
            }
            ans.push_back(ans1);
        }
        else
        {
            string temp = "";
            temp += *it;
            temp += '\'';
            vector<string> temp1 = m1[*it];
            vector<string> temp2 = m2[*it];
            string prod1 = "";
            prod1 += *it;
            prod1 += "->";
            for (int i = 0; i < temp2.size(); i++)
            {
                if (i != (temp2.size() - 1))
                {
                    string tt = temp2[i];
                    tt += temp;
                    prod1 += tt;
                    prod1 += "|";
                }
                else
                {
                    string tt = temp2[i];
                    tt += temp;
                    prod1 += tt;
                }
            }
            string prod2 = "";
            prod2 += temp;
            prod2 += "->";
            for (int i = 0; i < temp1.size(); i++)
            {
                string tt = temp1[i].substr(1);
                tt += temp;
                prod2 += tt;
                prod2 += "|";
            }
            prod2 += "~";
            ans.push_back(prod1);
            ans.push_back(prod2);
        }
    }
    cout << "\nGrammar after eliminating left recursion is:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
