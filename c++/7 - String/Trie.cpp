(Prefix tree) Estructura de datos para almacenar un diccionario de strings. Debe ejecutarse el método init_trie. El método dfs hace un recorrido en orden del trie.

const int MAXL = 26; //cantidad de letras del lenguaje
char L = 'a'; //primera letra del lenguaje

struct node {
    int next[MAXL];
    bool fin = false;
    node() {
        memset(next, -1, sizeof(next));
    }
};

vector<node> trie;

void init_trie() {
    trie.assign(1, node());
}

void add_str(string &s) {
    int cur = 0;
    for (auto c : s) {
        if (trie[cur].next[c-L] == -1) {
            trie[cur].next[c-L] = trie.size();
            trie.push_back(node());
        }
        cur = trie[cur].next[c-L];
    }
    trie[cur].fin = 1;
}

bool contain(string &s) {
    int cur = 0;
    for (auto c : s) {
        if (trie[cur].next[c-L] == -1) return 0;
        cur = trie[cur].next[c-L];
    }
    return trie[cur].fin;
}

void dfs(int cur) {
    for (int i = 0; i < MAXL; ++i) {
        if (trie[cur].next[i] != -1) {
            dfs(trie[cur].next[i]);
        }
    }
}
