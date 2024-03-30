#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class activity
{
public:
    int start;
    int finish;
    int duration;

    activity(int start, int finish)
    {
        this->start = start;
        this->finish = finish;
        this->duration = finish - start;
    }
};

vector<activity> generateRandomActivities(int numActivities)
{
    vector<activity> activities;

    for (int i = 0; i < numActivities; ++i)
    {
        int start = rand() % 10;
        int duration = rand() % (10 - start) + 1; 
        activities.push_back(activity(start, start + duration));
    }

    return activities;
}

bool cmpDuration(activity a, activity b)
{
    return b.duration > a.duration;
}

bool cmpStart(activity a, activity b)
{
    return b.start > a.start;
}

bool cmpEnd(activity a, activity b)
{
    return b.finish > a.finish;
}

vector<int> greedyActivitySelector(vector<activity> &activities)
{
    vector<int> solution;
    solution.push_back(0);
    int k = 0;

    for (int i = 1; i < activities.size(); i++)
    {
        if (activities[k].finish <= activities[i].start)
        {
            solution.push_back(i);
            k = i;
        }
    }

    return solution;
}

int sortFinish(vector<activity> &activities)
{
    sort(activities.begin(), activities.end(), cmpEnd);
    vector<int> finish = greedyActivitySelector(activities);
    return finish.size();
}

int sortDuration(vector<activity> &activities)
{
    sort(activities.begin(), activities.end(), cmpDuration);
    vector<int> duration = greedyActivitySelector(activities);
    return duration.size();
}

int sortStart(vector<activity> &activities)
{
    sort(activities.begin(), activities.end(), cmpStart);
    vector<int> start = greedyActivitySelector(activities);
    return start.size();
}

int main()
{
    int numActivities = 10; 
    vector<activity> activities = generateRandomActivities(numActivities);

    cout << "Activities:" << endl;
    for (int i = 0; i < numActivities; ++i)
    {
        cout << "Activity " << i + 1 << ": Start=" << activities[i].start << ", Finish=" << activities[i].finish << endl;
    }

    cout << endl;

    int maxActivitiesFinish = sortFinish(activities);
    cout << "Maximum non-overlapping activities (sorted by finish time): " << maxActivitiesFinish << endl;

    int maxActivitiesDuration = sortDuration(activities);
    cout << "Maximum non-overlapping activities (sorted by duration): " << maxActivitiesDuration << endl;

    int maxActivitiesStart = sortStart(activities);
    cout << "Maximum non-overlapping activities (sorted by start time): " << maxActivitiesStart << endl;

    return 0;
}
