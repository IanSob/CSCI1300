#include <iostream>
#include <vector>
using namespace std;

vector<string> subscribe(vector<string> subscriptions, string newsletter);
vector<string> unsubscribe(vector<string> subscriptions, string newsletter);

int main()
{
    vector<string> subscriptions = {"Daily News", "Tech Insights"};
subscriptions = unsubscribe(subscriptions, "Sports News");

    int subscription_size = subscriptions.size();
    cout << "Current subscriptions:" << endl;
    for (int i = 0; i < subscription_size; ++i)
    {
        cout << subscriptions[i] << endl;
    }
}

vector<string> subscribe(vector<string> subscriptions, string newsletter)
{
    for (int i = 0; i < static_cast<int>(subscriptions.size()); i++)
    {
        //Do not add anythin
        if(subscriptions.at(i) == newsletter)
        {
            return subscriptions;
        }
    }
    
    subscriptions.push_back(newsletter);

    return subscriptions;
}

vector<string> unsubscribe(vector<string> subscriptions, string newsletter)
{
    vector <string> newSubs;
    for (int i = 0; i < static_cast<int>(subscriptions.size()); i++)
    {
        if(subscriptions.at(i) != newsletter)
        {
            newSubs.push_back(subscriptions.at(i));
        }
    }
    
    return newSubs;
}