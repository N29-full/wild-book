struct pref_max_tree {
    ll t[N << 2];
    ll mx[N << 2];
    ll u[N << 2];
    ll tsl[N << 2];
    ll tsr[N << 2];
 
    ll get(int v, int tl, int tr, ll x) {
        if (mx[v] <= x)
            return x * (tr - tl + 1);
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) >> 1;
        ll res = 0;
        x -= u[v];
        if (mx[v << 1] <= x) {
            res += x * (tm - tl + 1);
            res += get(v << 1 | 1, tm + 1, tr, x);
        } else {
            res += get(v << 1, tl, tm, x);
            res += tsr[v];
        }
        res += (tr - tl + 1) * u[v];
        return res;
    }
 
    void pull(int v, int tl, int tm, int tr) {
        tsl[v] = get(v << 1, tl, tm, 0);
        tsr[v] = get(v << 1 | 1, tm + 1, tr, mx[v << 1]);
        t[v] = tsl[v] + tsr[v];
        t[v] += u[v] * (tr - tl + 1);
        mx[v] = max(mx[v << 1], mx[v << 1 | 1]) + u[v];
    }
 
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        pull(v, tl, tm, tr);
    }
 
    void upd(int l, int r, int x, int v, int tl, int tr) {
        if (r < tl || tr < l || l > r)
            return;
        int tm = (tl + tr) >> 1;
        if (l <= tl && tr <= r) {
            u[v] += x;
            mx[v] += x;
            t[v] += 1ll * x * (tr - tl + 1);
            return;
        }
        upd(l, r, x, v << 1, tl, tm);
        upd(l, r, x, v << 1 | 1, tm + 1, tr);
        pull(v, tl, tm, tr);
    }
 
} tr0, tr1;