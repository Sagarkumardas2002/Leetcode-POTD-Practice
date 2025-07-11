class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by their start time
        sort(meetings.begin(), meetings.end());

        // Count of meetings held in each room
        vector<int> roomCount(n, 0);

        // Min-heap for available room indices (sorted by room index)
        priority_queue<int, vector<int>, greater<>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        // Min-heap of {endTime, room} for ongoing meetings
        using pii = pair<long long, int>;
        priority_queue<pii, vector<pii>, greater<>> ongoing;

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];

            // Free up rooms that have finished before current meeting's start
            while (!ongoing.empty() && ongoing.top().first <= start) {
                freeRooms.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!freeRooms.empty()) {
                // Assign meeting to the lowest-numbered free room
                int room = freeRooms.top(); freeRooms.pop();
                ongoing.push({end, room});
                roomCount[room]++;
            } else {
                // All rooms busy — wait for the earliest to be free
                auto [nextFreeTime, room] = ongoing.top(); ongoing.pop();
                long long newEnd = nextFreeTime + (end - start);
                ongoing.push({newEnd, room});
                roomCount[room]++;
            }
        }

        // Return the room with the highest count (lowest index in case of tie)
        return max_element(roomCount.begin(), roomCount.end()) - roomCount.begin();
    }
};