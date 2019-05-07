struct task {
    int name;
    int num;
    task(int _name, int _num): name(_name), num(_num) {}
    bool operator < (const task& t) const {
        if (num == t.num) {
            return name < t.name;
        } else {
            return num > t.num;
        }
    }
};

class Solution {
    
public:
    int leastInterval(vector<char>& tasks, int n) {
        int nt = tasks.size();
        if (nt == 0)  return 0;
        vector<int> task_count(26);
        // 每一个任务的index和当前剩余数
        set<task> task_set;
        // 每一个任务剩余cooling interval
        vector<int> cooling(26);
        for (int i = 0; i < nt; ++i) {
            task_count[tasks[i]-'A']++;
        }
        for (int i = 0; i < 26; ++i) {
            if (task_count[i] > 0) {
                task_set.insert(task(i, task_count[i]));
            }
        }
        // 已经安排的task数
        int arranged_task = 0;
        // 已经过去的interval
        int interval = 0;
        while (arranged_task < nt) {
            // 找到num最大且不需要cooling的task
            auto it = task_set.begin();
            for (; it != task_set.end(); it++) {
                if (cooling[it->name] <= 0)  break;
            }
            // 找到这样的task，该task的数量减1，且重置cooling；由于之后每一个任务的cooling interval都会减1，重置时多设置1
            if (it != task_set.end()) {
                //cout << "arrange task " << (char)(it->name+'A') << endl;
                task tmp(it->name, it->num-1);
                cooling[it->name] = n + 1;
                task_set.erase(it);
                if (tmp.num > 0)
                    task_set.insert(tmp);
                arranged_task++;
            } else {
                //cout << "cooling ...... " << endl;
            }
            // 每一个任务都减少一个cooling
            for (int i = 0; i < 26; ++i) {
                if (cooling[i] > 0)  cooling[i]--;
            }
            interval++;
        }
        return interval;
    }
};