vector<int> repair_machine(vector<vector<int>> network, vector<int> initial_machines) {
    int num = network.size();
    sort(initial_machines.begin(), initial_machines.end());
    vector<int> res = {initial_machines[0], 0};
    vector<int> root(num, 0);
    for(int i = 0; i < num; i++)
        root[i] = i;
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            if(j != i && network[i][j]) {
                root[j] = root[i];
            }
        }
    }
    vector<int> cnt(num, 0);
    for(int i = 0; i < num; i++)
        cnt[root[i]]++;
    vector<int> ini_cnt(num, 0);
    int num2 = initial_machines.size();
    for(int i = 0; i < num2; i++)
        ini_cnt[root[initial_machines[i]]]++;
    for(int i = 0; i < num2; i++) {
        if(ini_cnt[root[initial_machines[i]]] == 1
           && cnt[root[initial_machines[i]]] > res[1]) {
            res[0] = initial_machines[i];
            res[1] = cnt[root[initial_machines[i]]];
        }
    }
    return res;
}