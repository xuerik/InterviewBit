bool myCmp(Interval a, Interval b) {
    return a.start < b.start;
}

vector<Interval> Solution::merge(vector<Interval> &intervals) {
    if(intervals.size() < 2) {
        return intervals;
    }
    sort(intervals.begin(), intervals.end(), myCmp);
    int first = 0;
    for(int second = 1; second < intervals.size(); second++) {
        if(intervals[second].start <= intervals[first].end) {
            intervals[first].end = max(intervals[second].end, intervals[first].end);
        }
        else {
            ++first;
            intervals[first].start = intervals[second].start;
            intervals[first].end = intervals[second].end;
        }
    }
    intervals.erase(intervals.begin() + first + 1, intervals.end());
    return intervals;
}
