// prefix_func(pat + "#" + txt, pi);
// count(pi.begin(), pi.end(), pat.size()-1)
void prefix_func(const string &pat, VI &pi) {
  pi.resize(pat.size());
  int now = -1; pi[0] = -1;

  for (int i = 1; i < pat.size(); i++) {
    while (now != -1 and pat[now+1] != pat[i]) now = pi[now];
    if (pat[now+1] == pat[i]) pi[i] = ++now;
    else pi[i] = now = -1;
  }
}