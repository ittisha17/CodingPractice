struct myCmp
{
    bool operator()(const pair<pair<int,int>, int>& p1,
                    const pair<pair<int,int>, int>& p2)
    {
        // Higher frequency first
        if (p1.first.second != p2.first.second)
            return p1.first.second < p2.first.second;

        // If frequency is same, more recent occurrence first
        return p1.second < p2.second;
    }
};

class FreqStack {
public:
    // val -> timestamps of all its currently present occurrences
    unordered_map<int, vector<int>> positions;

    // {{value, frequency-at-that-push}, timestamp}
    priority_queue<
        pair<pair<int,int>, int>,
        vector<pair<pair<int,int>, int>>,
        myCmp
    > pq;

    int timestamp = 0;

    FreqStack() {}

    void push(int val)
    {
        timestamp++;

        positions[val].push_back(timestamp);

        int freq = positions[val].size();

        pq.push({{val, freq}, timestamp});
    }

    int pop()
    {
        // Remove stale entries
        while (true)
        {
            auto top = pq.top();

            int val = top.first.first;
            int freq = top.first.second;
            int time = top.second;

            // Check whether this is the current/latest
            // occurrence of val.
            if (positions.find(val) != positions.end() &&
                positions[val].size() == freq &&
                positions[val].back() == time)
            {
                break;
            }

            pq.pop();
        }

        auto top = pq.top();
        pq.pop();

        int val = top.first.first;

        // Remove the actual latest occurrence of val
        positions[val].pop_back();

        if (positions[val].empty())
            positions.erase(val);

        return val;
    }
};