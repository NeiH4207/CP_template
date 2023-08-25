
long long node[N * 4];
 
void build(int v, int l, int r){
    if(l == r){
        //node[v]++;
        return;
    }
    int mid = (l + r) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    //node[v] = node[v * 2] + node[v * 2 + 1];
}
 
 
long long get(int v, int l, int r, int left, int right){
    if(l > right || r < left) return 0;
    if(l >= left && r <= right) return node[v];
    int mid = (l + r) / 2;
    //return get(v * 2, l, mid, left, right) + get(v * 2 + 1, mid + 1, r, left, right);
}